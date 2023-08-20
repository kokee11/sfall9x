# sfall9x

[![License](https://img.shields.io/badge/License-GPL--3.0-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Dev Build](https://github.com/phobos2077/sfall/actions/workflows/build.yml/badge.svg?branch=develop)](https://github.com/phobos2077/sfall/actions/workflows/build.yml)
[![GitHub Pages](https://github.com/phobos2077/sfall/actions/workflows/gh-pages.yml/badge.svg)](https://github.com/phobos2077/sfall/actions/workflows/gh-pages.yml)

Fully-featured backport of sfall to older Windows. Compatible with 98/ME/2000/XP/XPSP3/...

## Installation
The package contains only the proxy `ddraw.dll` and some helper files for Win9x. Assuming you **already have sfall correctly installed** and just want to replace the normal version with the 9x version:

__Windows NT 5/NT 5.1/NT 5.2/NT 6+__:
1. Install DirectX October 2006 Runtime, if your current DirectX is older.
2. Extract the archive with sfall9x into the game directory and overwrite.
3. In your Fallout folder delete files `d3dx9_31.dll` and `d3dx9_43.dll` if they exist. (some TCs have them)
4. You can now play the game.

__Windows 98/ME__:
1. Install DirectX October 2006 Runtime, if your current DirectX is older.
2. Extract the archive with sfall9x into the game directory and overwrite.
3. In your Fallout folder delete files `d3dx9_31.dll` and `d3dx9_43.dll`. (some TCs have them; on Win9x you have to enable see hidden files)
4. Hexedit Fallout's executable and replace all references of `ddraw.dll` to `ggraw.dll`. Alternatively, if you don't want to bother with a hexeditor, you can drag'n'drop Fallout's executable on the `dragndrop.exe` utility that's packaged with sfall9x, which will replace the references for you. The operation is reversible, i.e. you can drag'n'drop to undo the changes.
5. Rename sfall9x's `ddraw.dll` to `ggraw.dll`
6. You can now play the game.  

>NOTE:  sfall should run on a Pentium II CPU and higher. Additionally, DX9 mode requires GPU acceleration.  

## Compiling
The .dll was compiled on Visual Studio 2015 with the v140_xp compiler and linked against October 2006 DirectX SDK. Assuming you have the `Visual Studio`, the `v140_xp compiler` and the `DXSDK` installed:  

1. Make sure the `DXSDK_DIR` environment variable is pointing to the October 2006 SDK and not some other.
2. In the `%DXSDK_DIR%/include` directory delete `rpcsal.h` to make it compatible with Windows 7 SDK (as per the suggestions in https://walbourn.github.io/the-zombie-directx-sdk/)
3. Open the sfall project with Visual Studio 2015.
4. Select the `ReleaseXP` configuration and rebuild the solution.
5. The compiled .dll should be in the `ReleaseXP` folder.
