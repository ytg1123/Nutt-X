	.arch armv7-a
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 4
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"asm-offsets.c"
@ GNU C (crosstool-NG linaro-1.13.1-2012.02-20120222 - Linaro GCC 2012.02) version 4.6.3 20120201 (prerelease) (arm-linux-gnueabi)
@	compiled by GNU C version 4.1.3 20080704 (prerelease) (Ubuntu 4.1.2-27ubuntu1), GMP version 5.0.2, MPFR version 3.0.1, MPC version 0.9
@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed:  -nostdinc -I include
@ -I /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include
@ -I /home/taga/NuttX/brandy/u-boot-2014.07/include/openssl -imultilib .
@ -imultiarch arm-linux-gnueabi
@ -iprefix /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/
@ -isysroot /home/taga/NuttX/brandy/gcc-linaro/bin/../arm-linux-gnueabi/libc
@ -D __KERNEL__ -D CONFIG_SYS_TEXT_BASE=0x4A000000 -D CONFIG_ARM -D __ARM__
@ -D DO_DEPS_ONLY -D KBUILD_STR(s)=#s
@ -D KBUILD_BASENAME=KBUILD_STR(asm_offsets)
@ -D KBUILD_MODNAME=KBUILD_STR(asm_offsets)
@ -isystem /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include
@ -MD lib/.asm-offsets.s.d lib/asm-offsets.c -march=armv7-a
@ -mno-unaligned-access -marm -mno-thumb-interwork -mabi=aapcs-linux
@ -mword-relocations -msoft-float -mtune=cortex-a9 -mfpu=vfpv3-d16
@ -auxbase-strip lib/asm-offsets.s -g -Os -Wall -Wstrict-prototypes
@ -Wno-format-security -Wno-format-nonliteral -Werror -fno-builtin
@ -ffreestanding -fno-stack-protector -fstack-usage -ffunction-sections
@ -fdata-sections -fno-common -ffixed-r9 -fverbose-asm
@ options enabled:  -fauto-inc-dec -fbranch-count-reg -fcaller-saves
@ -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
@ -fcrossjumping -fcse-follow-jumps -fdata-sections -fdefer-pop
@ -fdelete-null-pointer-checks -fdevirtualize -fdwarf2-cfi-asm
@ -fearly-inlining -feliminate-unused-debug-types -fexpensive-optimizations
@ -fforward-propagate -ffunction-cse -ffunction-sections -fgcse -fgcse-lm
@ -fguess-branch-probability -fident -fif-conversion -fif-conversion2
@ -findirect-inlining -finline -finline-functions
@ -finline-functions-called-once -finline-small-functions -fipa-cp
@ -fipa-profile -fipa-pure-const -fipa-reference -fipa-sra
@ -fira-share-save-slots -fira-share-spill-slots -fivopts
@ -fkeep-static-consts -fleading-underscore -fmath-errno -fmerge-constants
@ -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
@ -foptimize-register-move -foptimize-sibling-calls -fpartial-inlining
@ -fpeephole -fpeephole2 -fprefetch-loop-arrays -freg-struct-return
@ -fregmove -freorder-blocks -freorder-functions -frerun-cse-after-loop
@ -fsched-critical-path-heuristic -fsched-dep-count-heuristic
@ -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
@ -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
@ -fsched-stalled-insns-dep -fschedule-insns2 -fsection-anchors
@ -fshow-column -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types
@ -fstrict-aliasing -fstrict-overflow -fstrict-volatile-bitfields
@ -fthread-jumps -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
@ -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-copy-prop
@ -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
@ -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
@ -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
@ -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
@ -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slp-vectorize
@ -ftree-sra -ftree-switch-conversion -ftree-ter -ftree-vect-loop-version
@ -ftree-vrp -funit-at-a-time -fvar-tracking -fvar-tracking-assignments
@ -fverbose-asm -fzero-initialized-in-bss -mglibc -mlittle-endian
@ -msched-prolog -mvectorize-with-neon-quad -mword-relocations

	.text
.Ltext0:
@ Compiler executable checksum: 2d9bb3b2e63bd79368eb5f8f2e036e7c

	.cfi_sections	.debug_frame
	.section	.text.startup.main,"ax",%progbits
	.align	2
	.global	main
	.type	main, %function
main:
.LFB155:
	.file 1 "lib/asm-offsets.c"
	.loc 1 20 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 22 0
#APP
@ 22 "lib/asm-offsets.c" 1
	
->GENERATED_GBL_DATA_SIZE #336 (sizeof(struct global_data) + 15) & ~15	@
@ 0 "" 2
	.loc 1 25 0
@ 25 "lib/asm-offsets.c" 1
	
->GENERATED_BD_INFO_SIZE #96 (sizeof(struct bd_info) + 15) & ~15	@
@ 0 "" 2
	.loc 1 28 0
@ 28 "lib/asm-offsets.c" 1
	
->GD_SIZE #328 sizeof(struct global_data)	@
@ 0 "" 2
	.loc 1 30 0
@ 30 "lib/asm-offsets.c" 1
	
->GD_BD #0 offsetof(struct global_data, bd)	@
@ 0 "" 2
	.loc 1 34 0
@ 34 "lib/asm-offsets.c" 1
	
->GD_RELOCADDR #44 offsetof(struct global_data, relocaddr)	@
@ 0 "" 2
	.loc 1 36 0
@ 36 "lib/asm-offsets.c" 1
	
->GD_RELOC_OFF #96 offsetof(struct global_data, reloc_off)	@
@ 0 "" 2
	.loc 1 38 0
@ 38 "lib/asm-offsets.c" 1
	
->GD_START_ADDR_SP #60 offsetof(struct global_data, start_addr_sp)	@
@ 0 "" 2
	.loc 1 43 0
	mov	r0, #0	@,
	bx	lr	@
	.cfi_endproc
.LFE155:
	.size	main, .-main
	.text
.Letext0:
	.file 2 "/home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/types.h"
	.file 3 "include/linux/types.h"
	.file 4 "include/asm-generic/u-boot.h"
	.file 5 "include/net.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x39b
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF56
	.byte	0x1
	.4byte	.LASF57
	.4byte	.LASF58
	.4byte	0
	.4byte	0
	.4byte	.Ldebug_ranges0+0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x4
	.4byte	.LASF10
	.byte	0x2
	.byte	0x35
	.4byte	0x30
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF8
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF9
	.uleb128 0x4
	.4byte	.LASF11
	.byte	0x3
	.byte	0x59
	.4byte	0x30
	.uleb128 0x5
	.byte	0x4
	.uleb128 0x6
	.byte	0x8
	.byte	0x4
	.byte	0x82
	.4byte	0xb3
	.uleb128 0x7
	.4byte	.LASF12
	.byte	0x4
	.byte	0x83
	.4byte	0x81
	.byte	0x2
	.byte	0x23
	.uleb128 0
	.uleb128 0x7
	.4byte	.LASF13
	.byte	0x4
	.byte	0x84
	.4byte	0x81
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0
	.uleb128 0x8
	.4byte	.LASF36
	.byte	0x58
	.byte	0x4
	.byte	0x1b
	.4byte	0x1e6
	.uleb128 0x7
	.4byte	.LASF14
	.byte	0x4
	.byte	0x1c
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0
	.uleb128 0x7
	.4byte	.LASF15
	.byte	0x4
	.byte	0x1d
	.4byte	0x68
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x7
	.4byte	.LASF16
	.byte	0x4
	.byte	0x1e
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x7
	.4byte	.LASF17
	.byte	0x4
	.byte	0x1f
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x7
	.4byte	.LASF18
	.byte	0x4
	.byte	0x20
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x7
	.4byte	.LASF19
	.byte	0x4
	.byte	0x21
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x7
	.4byte	.LASF20
	.byte	0x4
	.byte	0x22
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x7
	.4byte	.LASF21
	.byte	0x4
	.byte	0x24
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x7
	.4byte	.LASF22
	.byte	0x4
	.byte	0x25
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x7
	.4byte	.LASF23
	.byte	0x4
	.byte	0x26
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x7
	.4byte	.LASF24
	.byte	0x4
	.byte	0x29
	.4byte	0x4c
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0x7
	.4byte	.LASF25
	.byte	0x4
	.byte	0x2a
	.4byte	0x4c
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.uleb128 0x7
	.4byte	.LASF26
	.byte	0x4
	.byte	0x36
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.uleb128 0x7
	.4byte	.LASF27
	.byte	0x4
	.byte	0x37
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x34
	.uleb128 0x7
	.4byte	.LASF28
	.byte	0x4
	.byte	0x38
	.4byte	0x1e6
	.byte	0x2
	.byte	0x23
	.uleb128 0x38
	.uleb128 0x7
	.4byte	.LASF29
	.byte	0x4
	.byte	0x39
	.4byte	0x37
	.byte	0x2
	.byte	0x23
	.uleb128 0x3e
	.uleb128 0x7
	.4byte	.LASF30
	.byte	0x4
	.byte	0x3a
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x40
	.uleb128 0x7
	.4byte	.LASF31
	.byte	0x4
	.byte	0x3b
	.4byte	0x30
	.byte	0x2
	.byte	0x23
	.uleb128 0x44
	.uleb128 0x7
	.4byte	.LASF32
	.byte	0x4
	.byte	0x7f
	.4byte	0x81
	.byte	0x2
	.byte	0x23
	.uleb128 0x48
	.uleb128 0x7
	.4byte	.LASF33
	.byte	0x4
	.byte	0x80
	.4byte	0x81
	.byte	0x2
	.byte	0x23
	.uleb128 0x4c
	.uleb128 0x7
	.4byte	.LASF34
	.byte	0x4
	.byte	0x85
	.4byte	0x1f6
	.byte	0x2
	.byte	0x23
	.uleb128 0x50
	.byte	0
	.uleb128 0x9
	.4byte	0x29
	.4byte	0x1f6
	.uleb128 0xa
	.4byte	0x53
	.byte	0x5
	.byte	0
	.uleb128 0x9
	.4byte	0x8e
	.4byte	0x206
	.uleb128 0xa
	.4byte	0x53
	.byte	0
	.byte	0
	.uleb128 0x4
	.4byte	.LASF35
	.byte	0x4
	.byte	0x87
	.4byte	0xb3
	.uleb128 0xb
	.byte	0x4
	.4byte	0x206
	.uleb128 0x8
	.4byte	.LASF37
	.byte	0x40
	.byte	0x5
	.byte	0x51
	.4byte	0x2cc
	.uleb128 0x7
	.4byte	.LASF38
	.byte	0x5
	.byte	0x52
	.4byte	0x2cc
	.byte	0x2
	.byte	0x23
	.uleb128 0
	.uleb128 0x7
	.4byte	.LASF39
	.byte	0x5
	.byte	0x53
	.4byte	0x1e6
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x7
	.4byte	.LASF40
	.byte	0x5
	.byte	0x54
	.4byte	0x4c
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x7
	.4byte	.LASF41
	.byte	0x5
	.byte	0x55
	.4byte	0x4c
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x7
	.4byte	.LASF42
	.byte	0x5
	.byte	0x57
	.4byte	0x2f7
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x7
	.4byte	.LASF43
	.byte	0x5
	.byte	0x58
	.4byte	0x317
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x7
	.4byte	.LASF44
	.byte	0x5
	.byte	0x59
	.4byte	0x32d
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0x7
	.4byte	.LASF45
	.byte	0x5
	.byte	0x5a
	.4byte	0x33f
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.uleb128 0x7
	.4byte	.LASF46
	.byte	0x5
	.byte	0x5e
	.4byte	0x32d
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.uleb128 0x7
	.4byte	.LASF47
	.byte	0x5
	.byte	0x5f
	.4byte	0x2f1
	.byte	0x2
	.byte	0x23
	.uleb128 0x34
	.uleb128 0x7
	.4byte	.LASF48
	.byte	0x5
	.byte	0x60
	.4byte	0x4c
	.byte	0x2
	.byte	0x23
	.uleb128 0x38
	.uleb128 0x7
	.4byte	.LASF49
	.byte	0x5
	.byte	0x61
	.4byte	0x8c
	.byte	0x2
	.byte	0x23
	.uleb128 0x3c
	.byte	0
	.uleb128 0x9
	.4byte	0x7a
	.4byte	0x2dc
	.uleb128 0xa
	.4byte	0x53
	.byte	0xf
	.byte	0
	.uleb128 0xc
	.byte	0x1
	.4byte	0x4c
	.4byte	0x2f1
	.uleb128 0xd
	.4byte	0x2f1
	.uleb128 0xd
	.4byte	0x211
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x217
	.uleb128 0xb
	.byte	0x4
	.4byte	0x2dc
	.uleb128 0xc
	.byte	0x1
	.4byte	0x4c
	.4byte	0x317
	.uleb128 0xd
	.4byte	0x2f1
	.uleb128 0xd
	.4byte	0x8c
	.uleb128 0xd
	.4byte	0x4c
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x2fd
	.uleb128 0xc
	.byte	0x1
	.4byte	0x4c
	.4byte	0x32d
	.uleb128 0xd
	.4byte	0x2f1
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x31d
	.uleb128 0xe
	.byte	0x1
	.4byte	0x33f
	.uleb128 0xd
	.4byte	0x2f1
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x333
	.uleb128 0xf
	.4byte	.LASF59
	.byte	0x4
	.byte	0x5
	.2byte	0x1f2
	.4byte	0x36b
	.uleb128 0x10
	.4byte	.LASF50
	.sleb128 0
	.uleb128 0x10
	.4byte	.LASF51
	.sleb128 1
	.uleb128 0x10
	.4byte	.LASF52
	.sleb128 2
	.uleb128 0x10
	.4byte	.LASF53
	.sleb128 3
	.byte	0
	.uleb128 0x11
	.byte	0x1
	.4byte	.LASF60
	.byte	0x1
	.byte	0x13
	.byte	0x1
	.4byte	0x4c
	.4byte	.LFB155
	.4byte	.LFE155
	.byte	0x2
	.byte	0x7d
	.sleb128 0
	.uleb128 0x12
	.4byte	.LASF54
	.byte	0x5
	.byte	0x6b
	.4byte	0x2f1
	.byte	0x1
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF55
	.byte	0x5
	.2byte	0x1f8
	.4byte	0x345
	.byte	0x1
	.byte	0x1
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB155
	.4byte	.LFE155-.LFB155
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB155
	.4byte	.LFE155
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF54:
	.ascii	"eth_current\000"
.LASF21:
	.ascii	"bi_arm_freq\000"
.LASF33:
	.ascii	"bi_boot_params\000"
.LASF28:
	.ascii	"bi_enetaddr\000"
.LASF45:
	.ascii	"halt\000"
.LASF41:
	.ascii	"state\000"
.LASF49:
	.ascii	"priv\000"
.LASF32:
	.ascii	"bi_arch_number\000"
.LASF18:
	.ascii	"bi_flashoffset\000"
.LASF12:
	.ascii	"start\000"
.LASF42:
	.ascii	"init\000"
.LASF38:
	.ascii	"name\000"
.LASF26:
	.ascii	"bi_bootflags\000"
.LASF30:
	.ascii	"bi_intfreq\000"
.LASF56:
	.ascii	"GNU C 4.6.3 20120201 (prerelease)\000"
.LASF29:
	.ascii	"bi_ethspeed\000"
.LASF27:
	.ascii	"bi_ip_addr\000"
.LASF39:
	.ascii	"enetaddr\000"
.LASF40:
	.ascii	"iobase\000"
.LASF35:
	.ascii	"bd_t\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF16:
	.ascii	"bi_flashstart\000"
.LASF1:
	.ascii	"long unsigned int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF17:
	.ascii	"bi_flashsize\000"
.LASF22:
	.ascii	"bi_dsp_freq\000"
.LASF20:
	.ascii	"bi_sramsize\000"
.LASF14:
	.ascii	"bi_memstart\000"
.LASF24:
	.ascii	"bi_card_num\000"
.LASF60:
	.ascii	"main\000"
.LASF52:
	.ascii	"NETLOOP_SUCCESS\000"
.LASF34:
	.ascii	"bi_dram\000"
.LASF11:
	.ascii	"ulong\000"
.LASF5:
	.ascii	"unsigned int\000"
.LASF43:
	.ascii	"send\000"
.LASF19:
	.ascii	"bi_sramstart\000"
.LASF25:
	.ascii	"res0\000"
.LASF15:
	.ascii	"bi_memsize\000"
.LASF31:
	.ascii	"bi_busfreq\000"
.LASF10:
	.ascii	"phys_size_t\000"
.LASF44:
	.ascii	"recv\000"
.LASF6:
	.ascii	"long long int\000"
.LASF55:
	.ascii	"net_state\000"
.LASF51:
	.ascii	"NETLOOP_RESTART\000"
.LASF48:
	.ascii	"index\000"
.LASF36:
	.ascii	"bd_info\000"
.LASF4:
	.ascii	"short int\000"
.LASF23:
	.ascii	"bi_ddr_freq\000"
.LASF37:
	.ascii	"eth_device\000"
.LASF50:
	.ascii	"NETLOOP_CONTINUE\000"
.LASF8:
	.ascii	"long int\000"
.LASF9:
	.ascii	"char\000"
.LASF59:
	.ascii	"net_loop_state\000"
.LASF3:
	.ascii	"signed char\000"
.LASF46:
	.ascii	"write_hwaddr\000"
.LASF47:
	.ascii	"next\000"
.LASF13:
	.ascii	"size\000"
.LASF58:
	.ascii	"/home/taga/NuttX/brandy/u-boot-2014.07\000"
.LASF53:
	.ascii	"NETLOOP_FAIL\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF57:
	.ascii	"lib/asm-offsets.c\000"
	.ident	"GCC: (crosstool-NG linaro-1.13.1-2012.02-20120222 - Linaro GCC 2012.02) 4.6.3 20120201 (prerelease)"
	.section	.note.GNU-stack,"",%progbits
