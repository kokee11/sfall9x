/* these are flags in EDX of CPUID AX=00000001 */
static const uint32_t FLAC__CPUINFO_X86_CPUID_FPU = 0x00000001;
static const uint32_t FLAC__CPUINFO_X86_CPUID_VME = 0x00000002;
static const uint32_t FLAC__CPUINFO_X86_CPUID_DE = 0x00000004;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PSE = 0x00000008;
static const uint32_t FLAC__CPUINFO_X86_CPUID_TSC = 0x00000010;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MSR = 0x00000020;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PAE = 0x00000040;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MCE = 0x00000080;
static const uint32_t FLAC__CPUINFO_X86_CPUID_CX8 = 0x00000100;
static const uint32_t FLAC__CPUINFO_X86_CPUID_APIC = 0x00000200;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SEP = 0x00000800;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MTRR = 0x00001000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PGE = 0x00002000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MCA = 0x00004000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_CMOV = 0x00008000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PAT = 0x00010000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PSE36 = 0x00020000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PSN = 0x00040000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_CLFSH = 0x00080000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_DS = 0x00200000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_ACPI = 0x00400000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MMX = 0x00800000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_FXSR = 0x01000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SSE = 0x02000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SSE2 = 0x04000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SS = 0x08000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_HTT = 0x10000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_TM = 0x20000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PBE = 0x80000000;

/* these are flags in ECX of CPUID AX=00000001 */
static const uint32_t FLAC__CPUINFO_X86_CPUID_SSE3 = 0x00000001;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PCLMULQDQ = 0x00000002;
static const uint32_t FLAC__CPUINFO_X86_CPUID_DTES64 = 0x00000004;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MONITOR = 0x00000008;
static const uint32_t FLAC__CPUINFO_X86_CPUID_DS_CPL = 0x00000010;
static const uint32_t FLAC__CPUINFO_X86_CPUID_VMX = 0x00000020;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SMX = 0x00000040;
static const uint32_t FLAC__CPUINFO_X86_CPUID_EST = 0x00000080;
static const uint32_t FLAC__CPUINFO_X86_CPUID_TM2 = 0x00000100;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SSSE3 = 0x00000200;
static const uint32_t FLAC__CPUINFO_X86_CPUID_CNXT_ID = 0x00000400;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SDBG = 0x00000800;
static const uint32_t FLAC__CPUINFO_X86_CPUID_FMA = 0x00001000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_CMPXCHG16B = 0x00002000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_XTPRUC = 0x00004000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PDCM = 0x00008000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_PCID = 0x00020000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_DCA = 0x00040000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SSE41 = 0x00080000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_SSE42 = 0x00100000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_X2APIC = 0x00200000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_MOVBE = 0x00400000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_POPCNT = 0x00800000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_TSC_D = 0x01000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_AES = 0x02000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_XSAVE = 0x04000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_OSXSAVE = 0x08000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_AVX = 0x10000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_F16C = 0x20000000;
static const uint32_t FLAC__CPUINFO_X86_CPUID_RDRAND = 0x40000000;

uint32_t cpu_have_cpuid(void);
void cpuinfo_x86(uint32_t level, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx);