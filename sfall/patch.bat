<# :
:: Header to create Batch/PowerShell hybrid
@echo off

setlocal
set "POWERSHELL_BAT_ARGS=%*"
if defined POWERSHELL_BAT_ARGS set "POWERSHELL_BAT_ARGS=%POWERSHELL_BAT_ARGS:"=\"%"
endlocal & powershell -NoLogo -NoProfile -Command "$_ = $input; Invoke-Expression $( '$input = $_; $_ = \"\"; $args = @( &{ $args } %POWERSHELL_BAT_ARGS% );' + [String]::Join( [char]10, $( Get-Content \"%~f0\" ) ) )"

:: Any batch code that gets run after your PowerShell goes here
goto :EOF
#>

#
# Patches an EXE file to run under Windows 2000 (NT 5.0).
# Necessary since Visual Studio's linker doesn't let us set the subsystem version below 5.01 (Windows XP).
#
# Copyright (c) 2021 Colin Finck, ENLYZE GmbH <c.finck@enlyze.com>
# SPDX-License-Identifier: MIT
#

$exepath = Resolve-Path $args[0]
$exe = [System.IO.File]::ReadAllBytes($exepath)

# This offset is fixed for any EXE file whereas the PE header already starts at different offsets
# depending on whether you build with Visual Studio 2017 or 2019.

$e_lfanew = 0x3c

$pe_start = [System.BitConverter]::ToUInt32($exe, $e_lfanew)
$pe_signature = [System.BitConverter]::ToUInt32($exe, $pe_start)

if ($pe_signature -ne 0x4550) {
    "PE Signature should be 0x4550, but it is 0x{0:x}" -f $pe_signature
    exit 1
}

# Set MajorOperatingSystemVersion (WORD) to 4
$exe[$pe_start + 0x40] = 0x04;
$exe[$pe_start + 0x41] = 0x00;

# Set MinorOperatingSystemVersion (WORD) to 0
$exe[$pe_start + 0x42] = 0x00;
$exe[$pe_start + 0x43] = 0x00;

# Set MajorSubsystemVersion (WORD) to 4
$exe[$pe_start + 0x48] = 0x04;
$exe[$pe_start + 0x49] = 0x00;

# Set MinorSubsystemVersion (WORD) to 0
$exe[$pe_start + 0x4a] = 0x00;
$exe[$pe_start + 0x4b] = 0x00;

[System.IO.File]::WriteAllBytes($exepath, $exe)
