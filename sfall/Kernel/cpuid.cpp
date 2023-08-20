uint32_t cpu_have_cpuid(void)
{
	uint32_t flags1, flags2;
	__asm {
		pushfd
			pushfd
			pop		eax
			mov		flags1, eax
			xor		eax, 0x200000
			push	eax
			popfd
			pushfd
			pop		eax
			mov		flags2, eax
			popfd
	}
	if (((flags1^flags2) & 0x200000) != 0)
		return 1;
	else
		return 0;
}
	
void cpuinfo_x86(uint32_t level, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{
	int cpuinfo[4];
	int ext = level & 0x80000000;
	__cpuid(cpuinfo, ext);
	if ((uint32_t)cpuinfo[0] >= level) {
		__cpuid(cpuinfo, level);
		*eax = cpuinfo[0]; *ebx = cpuinfo[1]; *ecx = cpuinfo[2]; *edx = cpuinfo[3];
		return;
	}
}
