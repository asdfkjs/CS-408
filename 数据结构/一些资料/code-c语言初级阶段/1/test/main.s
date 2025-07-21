	.file	"main.cpp"
	.intel_syntax noprefix
 # GNU C++14 (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) version 8.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 8.1.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.18-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -imultilib 32
 # -iprefix C:/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/
 # -D_REENTRANT main.cpp -m32 -masm=intel -mtune=generic -march=i686
 # -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -fexceptions -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
 # -fgnu-runtime -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
 # -fpeephole -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fshrink-wrap-separate
 # -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
 # -m96bit-long-double -maccumulate-outgoing-args -malign-double
 # -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mstv -mvzeroupper

	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.text
	.def	__ZL6printfPKcz;	.scl	3;	.type	32;	.endef
__ZL6printfPKcz:
	push	ebp	 #
	mov	ebp, esp	 #,
	push	ebx	 #
	sub	esp, 36	 #,
 # C:/mingw64/x86_64-w64-mingw32/include/stdio.h:348:   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
	lea	eax, [ebp+12]	 # tmp91,
	mov	DWORD PTR [ebp-16], eax	 # __local_argv, tmp91
 # C:/mingw64/x86_64-w64-mingw32/include/stdio.h:349:   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
	mov	ebx, DWORD PTR [ebp-16]	 # __local_argv.0_1, __local_argv
	mov	DWORD PTR [esp], 1	 #,
	mov	eax, DWORD PTR __imp____acrt_iob_func	 # tmp92,
	call	eax	 # tmp92
	mov	edx, eax	 # _2,
	mov	DWORD PTR [esp+8], ebx	 #, __local_argv.0_1
	mov	eax, DWORD PTR [ebp+8]	 # tmp93, __format
	mov	DWORD PTR [esp+4], eax	 #, tmp93
	mov	DWORD PTR [esp], edx	 #, _2
	call	___mingw_vfprintf	 #
	mov	DWORD PTR [ebp-12], eax	 # __retval, tmp94
 # C:/mingw64/x86_64-w64-mingw32/include/stdio.h:351:   return __retval;
	mov	eax, DWORD PTR [ebp-12]	 # _11, __retval
 # C:/mingw64/x86_64-w64-mingw32/include/stdio.h:352: }
	add	esp, 36	 #,
	pop	ebx	 #
	pop	ebp	 #
	ret	
.lcomm __ZStL8__ioinit,1,1
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp	 #
	mov	ebp, esp	 #,
	and	esp, -16	 #,
	sub	esp, 32	 #,
 # main.cpp:3: int main() {
	call	___main	 #
 # main.cpp:4:     short a=-32768;
	mov	WORD PTR [esp+30], -32768	 # a,
 # main.cpp:5:     printf("%d\n",a);
	movsx	eax, WORD PTR [esp+30]	 # _1, a
	mov	DWORD PTR [esp+4], eax	 #, _1
	mov	DWORD PTR [esp], OFFSET FLAT:LC0	 #,
	call	__ZL6printfPKcz	 #
 # main.cpp:6: }
	mov	eax, 0	 # _5,
	leave	
	ret	
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	push	ebp	 #
	mov	ebp, esp	 #,
	sub	esp, 8	 #,
 # C:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	mov	ecx, OFFSET FLAT:__ZStL8__ioinit	 #,
	call	__ZNSt8ios_base4InitD1Ev	 #
	leave	
	ret	
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	push	ebp	 #
	mov	ebp, esp	 #,
	sub	esp, 24	 #,
 # main.cpp:6: }
	cmp	DWORD PTR [ebp+8], 1	 # __initialize_p,
	jne	L8	 #,
 # main.cpp:6: }
	cmp	DWORD PTR [ebp+12], 65535	 # __priority,
	jne	L8	 #,
 # C:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	mov	ecx, OFFSET FLAT:__ZStL8__ioinit	 #,
	call	__ZNSt8ios_base4InitC1Ev	 #
	mov	DWORD PTR [esp], OFFSET FLAT:___tcf_0	 #,
	call	_atexit	 #
L8:
 # main.cpp:6: }
	nop	
	leave	
	ret	
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
	push	ebp	 #
	mov	ebp, esp	 #,
	sub	esp, 24	 #,
 # main.cpp:6: }
	mov	DWORD PTR [esp+4], 65535	 #,
	mov	DWORD PTR [esp], 1	 #,
	call	__Z41__static_initialization_and_destruction_0ii	 #
	leave	
	ret	
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	___mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
