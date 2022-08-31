	.cpu cortex-a7
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 4
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"asm-offsets.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.arch armv7ve
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
.LFB72:
	.file 1 "lib/asm-offsets.c"
	.loc 1 23 1 view -0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 25 2 view .LVU1
	.syntax divided
@ 25 "lib/asm-offsets.c" 1
	
->GENERATED_GBL_DATA_SIZE #224 (sizeof(struct global_data) + 15) & ~15
@ 0 "" 2
	.loc 1 28 2 view .LVU2
@ 28 "lib/asm-offsets.c" 1
	
->GENERATED_BD_INFO_SIZE #32 (sizeof(struct bd_info) + 15) & ~15
@ 0 "" 2
	.loc 1 31 2 view .LVU3
	.loc 1 32 1 is_stmt 0 view .LVU4
	.arm
	.syntax unified
	mov	r0, #0
	bx	lr
	.cfi_endproc
.LFE72:
	.size	main, .-main
	.text
.Letext0:
	.file 2 "/home/taga/NuttX/brandy/u-boot-2011.09/include/common.h"
	.file 3 "/home/taga/NuttX/brandy/u-boot-2011.09/include/asm/types.h"
	.file 4 "/home/taga/NuttX/brandy/u-boot-2011.09/include/linux/types.h"
	.file 5 "/home/taga/NuttX/brandy/u-boot-2011.09/include/lmb.h"
	.file 6 "/home/taga/NuttX/brandy/u-boot-2011.09/include/spare_head.h"
	.file 7 "/home/taga/NuttX/brandy/u-boot-2011.09/include/private_uboot.h"
	.file 8 "/home/taga/NuttX/brandy/u-boot-2011.09/include/linux/string.h"
	.file 9 "/home/taga/NuttX/brandy/u-boot-2011.09/include/boot_type.h"
	.file 10 "/home/taga/NuttX/brandy/u-boot-2011.09/include/command.h"
	.file 11 "/home/taga/NuttX/brandy/u-boot-2011.09/include/asm/mach-types.h"
	.file 12 "/home/taga/NuttX/brandy/u-boot-2011.09/include/asm/setup.h"
	.file 13 "/home/taga/NuttX/brandy/u-boot-2011.09/include/asm/u-boot-arm.h"
	.file 14 "/home/taga/NuttX/brandy/u-boot-2011.09/include/net.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x812
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF120
	.byte	0xc
	.4byte	.LASF121
	.4byte	.LASF122
	.4byte	.Ldebug_ranges0+0
	.4byte	0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.4byte	.LASF8
	.byte	0x2
	.byte	0x20
	.byte	0x18
	.4byte	0x36
	.uleb128 0x3
	.4byte	0x25
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF0
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.4byte	.LASF1
	.uleb128 0x4
	.byte	0x2
	.byte	0x7
	.4byte	.LASF2
	.uleb128 0x4
	.byte	0x1
	.byte	0x6
	.4byte	.LASF3
	.uleb128 0x4
	.byte	0x2
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x4
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x4
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x2
	.4byte	.LASF9
	.byte	0x3
	.byte	0x30
	.byte	0x17
	.4byte	0x3d
	.uleb128 0x2
	.4byte	.LASF10
	.byte	0x3
	.byte	0x31
	.byte	0x17
	.4byte	0x3d
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.4byte	.LASF11
	.uleb128 0x6
	.byte	0x4
	.4byte	0x9f
	.uleb128 0x7
	.4byte	0x94
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF12
	.uleb128 0x2
	.4byte	.LASF13
	.byte	0x4
	.byte	0x5a
	.byte	0x19
	.4byte	0x44
	.uleb128 0x2
	.4byte	.LASF14
	.byte	0x4
	.byte	0x5b
	.byte	0x17
	.4byte	0x60
	.uleb128 0x2
	.4byte	.LASF15
	.byte	0x4
	.byte	0x5c
	.byte	0x18
	.4byte	0x3d
	.uleb128 0x8
	.4byte	.LASF24
	.byte	0x8
	.byte	0xb
	.byte	0xf
	.4byte	0x94
	.uleb128 0x4
	.byte	0x8
	.byte	0x4
	.4byte	.LASF16
	.uleb128 0x9
	.4byte	.LASF19
	.byte	0x8
	.byte	0x5
	.byte	0x13
	.byte	0x8
	.4byte	0x105
	.uleb128 0xa
	.4byte	.LASF17
	.byte	0x5
	.byte	0x14
	.byte	0xe
	.4byte	0x75
	.byte	0
	.uleb128 0xa
	.4byte	.LASF18
	.byte	0x5
	.byte	0x15
	.byte	0xe
	.4byte	0x81
	.byte	0x4
	.byte	0
	.uleb128 0x9
	.4byte	.LASF20
	.byte	0x50
	.byte	0x5
	.byte	0x18
	.byte	0x8
	.4byte	0x13a
	.uleb128 0xb
	.ascii	"cnt\000"
	.byte	0x5
	.byte	0x19
	.byte	0x10
	.4byte	0x3d
	.byte	0
	.uleb128 0xa
	.4byte	.LASF18
	.byte	0x5
	.byte	0x1a
	.byte	0xe
	.4byte	0x81
	.byte	0x4
	.uleb128 0xa
	.4byte	.LASF21
	.byte	0x5
	.byte	0x1b
	.byte	0x16
	.4byte	0x13a
	.byte	0x8
	.byte	0
	.uleb128 0xc
	.4byte	0xdd
	.4byte	0x14a
	.uleb128 0xd
	.4byte	0x60
	.byte	0x8
	.byte	0
	.uleb128 0xe
	.ascii	"lmb\000"
	.byte	0xa0
	.byte	0x5
	.byte	0x1e
	.byte	0x8
	.4byte	0x172
	.uleb128 0xa
	.4byte	.LASF22
	.byte	0x5
	.byte	0x1f
	.byte	0x14
	.4byte	0x105
	.byte	0
	.uleb128 0xa
	.4byte	.LASF23
	.byte	0x5
	.byte	0x20
	.byte	0x14
	.4byte	0x105
	.byte	0x50
	.byte	0
	.uleb128 0xf
	.ascii	"lmb\000"
	.byte	0x5
	.byte	0x23
	.byte	0x13
	.4byte	0x14a
	.uleb128 0x9
	.4byte	.LASF25
	.byte	0x8
	.byte	0x6
	.byte	0x66
	.byte	0x10
	.4byte	0x1e7
	.uleb128 0xa
	.4byte	.LASF26
	.byte	0x6
	.byte	0x68
	.byte	0xf
	.4byte	0x9f
	.byte	0
	.uleb128 0xa
	.4byte	.LASF27
	.byte	0x6
	.byte	0x69
	.byte	0xf
	.4byte	0x9f
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF28
	.byte	0x6
	.byte	0x6a
	.byte	0xf
	.4byte	0x9f
	.byte	0x2
	.uleb128 0xa
	.4byte	.LASF29
	.byte	0x6
	.byte	0x6b
	.byte	0xf
	.4byte	0x9f
	.byte	0x3
	.uleb128 0xa
	.4byte	.LASF30
	.byte	0x6
	.byte	0x6c
	.byte	0xf
	.4byte	0x9f
	.byte	0x4
	.uleb128 0xa
	.4byte	.LASF31
	.byte	0x6
	.byte	0x6d
	.byte	0xf
	.4byte	0x9f
	.byte	0x5
	.uleb128 0xa
	.4byte	.LASF23
	.byte	0x6
	.byte	0x6e
	.byte	0xf
	.4byte	0x1e7
	.byte	0x6
	.byte	0
	.uleb128 0xc
	.4byte	0x9f
	.4byte	0x1f7
	.uleb128 0xd
	.4byte	0x60
	.byte	0x1
	.byte	0
	.uleb128 0x2
	.4byte	.LASF32
	.byte	0x6
	.byte	0x70
	.byte	0x1
	.4byte	0x17e
	.uleb128 0xc
	.4byte	0x59
	.4byte	0x213
	.uleb128 0xd
	.4byte	0x60
	.byte	0x3
	.byte	0
	.uleb128 0x9
	.4byte	.LASF33
	.byte	0x30
	.byte	0x7
	.byte	0x20
	.byte	0x8
	.4byte	0x296
	.uleb128 0xa
	.4byte	.LASF34
	.byte	0x7
	.byte	0x22
	.byte	0x10
	.4byte	0x60
	.byte	0
	.uleb128 0xa
	.4byte	.LASF35
	.byte	0x7
	.byte	0x23
	.byte	0x10
	.4byte	0x296
	.byte	0x4
	.uleb128 0xa
	.4byte	.LASF36
	.byte	0x7
	.byte	0x24
	.byte	0x10
	.4byte	0x60
	.byte	0xc
	.uleb128 0xa
	.4byte	.LASF37
	.byte	0x7
	.byte	0x25
	.byte	0x10
	.4byte	0x60
	.byte	0x10
	.uleb128 0xa
	.4byte	.LASF38
	.byte	0x7
	.byte	0x26
	.byte	0x10
	.4byte	0x60
	.byte	0x14
	.uleb128 0xa
	.4byte	.LASF39
	.byte	0x7
	.byte	0x27
	.byte	0x10
	.4byte	0x60
	.byte	0x18
	.uleb128 0xa
	.4byte	.LASF40
	.byte	0x7
	.byte	0x28
	.byte	0x10
	.4byte	0x296
	.byte	0x1c
	.uleb128 0xa
	.4byte	.LASF41
	.byte	0x7
	.byte	0x29
	.byte	0x10
	.4byte	0x296
	.byte	0x24
	.uleb128 0xa
	.4byte	.LASF23
	.byte	0x7
	.byte	0x2a
	.byte	0x10
	.4byte	0x2a6
	.byte	0x2c
	.byte	0
	.uleb128 0xc
	.4byte	0x36
	.4byte	0x2a6
	.uleb128 0xd
	.4byte	0x60
	.byte	0x7
	.byte	0
	.uleb128 0xc
	.4byte	0x59
	.4byte	0x2b6
	.uleb128 0xd
	.4byte	0x60
	.byte	0
	.byte	0
	.uleb128 0x10
	.4byte	.LASF42
	.2byte	0x4d0
	.byte	0x7
	.byte	0x30
	.byte	0x8
	.4byte	0x39b
	.uleb128 0xa
	.4byte	.LASF43
	.byte	0x7
	.byte	0x32
	.byte	0x1e
	.4byte	0x39b
	.byte	0
	.uleb128 0xa
	.4byte	.LASF44
	.byte	0x7
	.byte	0x33
	.byte	0xc
	.4byte	0x59
	.byte	0x80
	.uleb128 0xa
	.4byte	.LASF45
	.byte	0x7
	.byte	0x34
	.byte	0xc
	.4byte	0x59
	.byte	0x84
	.uleb128 0xa
	.4byte	.LASF46
	.byte	0x7
	.byte	0x35
	.byte	0xc
	.4byte	0x59
	.byte	0x88
	.uleb128 0xa
	.4byte	.LASF47
	.byte	0x7
	.byte	0x36
	.byte	0x1e
	.4byte	0x3ab
	.byte	0x8c
	.uleb128 0xa
	.4byte	.LASF48
	.byte	0x7
	.byte	0x37
	.byte	0xc
	.4byte	0x59
	.byte	0x9c
	.uleb128 0xa
	.4byte	.LASF49
	.byte	0x7
	.byte	0x38
	.byte	0x1e
	.4byte	0x3ab
	.byte	0xa0
	.uleb128 0xa
	.4byte	.LASF50
	.byte	0x7
	.byte	0x39
	.byte	0x1b
	.4byte	0x59
	.byte	0xb0
	.uleb128 0xa
	.4byte	.LASF51
	.byte	0x7
	.byte	0x3a
	.byte	0x21
	.4byte	0x59
	.byte	0xb4
	.uleb128 0xa
	.4byte	.LASF52
	.byte	0x7
	.byte	0x3b
	.byte	0x21
	.4byte	0x3bb
	.byte	0xb8
	.uleb128 0x11
	.4byte	.LASF53
	.byte	0x7
	.byte	0x3c
	.byte	0xf
	.4byte	0x3cb
	.2byte	0x1b8
	.uleb128 0x11
	.4byte	.LASF54
	.byte	0x7
	.byte	0x3d
	.byte	0x21
	.4byte	0x3bb
	.2byte	0x2b8
	.uleb128 0x11
	.4byte	.LASF55
	.byte	0x7
	.byte	0x3e
	.byte	0x19
	.4byte	0x3cb
	.2byte	0x3b8
	.uleb128 0x11
	.4byte	.LASF56
	.byte	0x7
	.byte	0x3f
	.byte	0x21
	.4byte	0x59
	.2byte	0x4b8
	.uleb128 0x11
	.4byte	.LASF57
	.byte	0x7
	.byte	0x40
	.byte	0x21
	.4byte	0xb2
	.2byte	0x4bc
	.uleb128 0x11
	.4byte	.LASF23
	.byte	0x7
	.byte	0x41
	.byte	0xf
	.4byte	0x203
	.2byte	0x4c0
	.byte	0
	.uleb128 0xc
	.4byte	0x60
	.4byte	0x3ab
	.uleb128 0xd
	.4byte	0x60
	.byte	0x1f
	.byte	0
	.uleb128 0xc
	.4byte	0x1f7
	.4byte	0x3bb
	.uleb128 0xd
	.4byte	0x60
	.byte	0x1
	.byte	0
	.uleb128 0xc
	.4byte	0x1f7
	.4byte	0x3cb
	.uleb128 0xd
	.4byte	0x60
	.byte	0x1f
	.byte	0
	.uleb128 0xc
	.4byte	0x9f
	.4byte	0x3db
	.uleb128 0xd
	.4byte	0x60
	.byte	0xff
	.byte	0
	.uleb128 0x10
	.4byte	.LASF58
	.2byte	0x500
	.byte	0x7
	.byte	0x45
	.byte	0x8
	.4byte	0x404
	.uleb128 0xa
	.4byte	.LASF59
	.byte	0x7
	.byte	0x47
	.byte	0x21
	.4byte	0x213
	.byte	0
	.uleb128 0xa
	.4byte	.LASF60
	.byte	0x7
	.byte	0x48
	.byte	0x21
	.4byte	0x2b6
	.byte	0x30
	.byte	0
	.uleb128 0x8
	.4byte	.LASF61
	.byte	0x9
	.byte	0x1e
	.byte	0x22
	.4byte	0x3db
	.uleb128 0x9
	.4byte	.LASF62
	.byte	0x1c
	.byte	0xa
	.byte	0x2f
	.byte	0x8
	.4byte	0x479
	.uleb128 0xa
	.4byte	.LASF63
	.byte	0xa
	.byte	0x30
	.byte	0x9
	.4byte	0x94
	.byte	0
	.uleb128 0xa
	.4byte	.LASF64
	.byte	0xa
	.byte	0x31
	.byte	0x7
	.4byte	0x59
	.byte	0x4
	.uleb128 0xa
	.4byte	.LASF65
	.byte	0xa
	.byte	0x32
	.byte	0x7
	.4byte	0x59
	.byte	0x8
	.uleb128 0xb
	.ascii	"cmd\000"
	.byte	0xa
	.byte	0x34
	.byte	0x9
	.4byte	0x4a3
	.byte	0xc
	.uleb128 0xa
	.4byte	.LASF66
	.byte	0xa
	.byte	0x35
	.byte	0x9
	.4byte	0x94
	.byte	0x10
	.uleb128 0xa
	.4byte	.LASF67
	.byte	0xa
	.byte	0x37
	.byte	0x9
	.4byte	0x94
	.byte	0x14
	.uleb128 0xa
	.4byte	.LASF68
	.byte	0xa
	.byte	0x3b
	.byte	0x9
	.4byte	0x4d2
	.byte	0x18
	.byte	0
	.uleb128 0x12
	.4byte	0x59
	.4byte	0x497
	.uleb128 0x13
	.4byte	0x497
	.uleb128 0x13
	.4byte	0x59
	.uleb128 0x13
	.4byte	0x59
	.uleb128 0x13
	.4byte	0x49d
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x410
	.uleb128 0x6
	.byte	0x4
	.4byte	0x9a
	.uleb128 0x6
	.byte	0x4
	.4byte	0x479
	.uleb128 0x12
	.4byte	0x59
	.4byte	0x4cc
	.uleb128 0x13
	.4byte	0x59
	.uleb128 0x13
	.4byte	0x49d
	.uleb128 0x13
	.4byte	0x9f
	.uleb128 0x13
	.4byte	0x59
	.uleb128 0x13
	.4byte	0x4cc
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x94
	.uleb128 0x6
	.byte	0x4
	.4byte	0x4a9
	.uleb128 0x2
	.4byte	.LASF69
	.byte	0xa
	.byte	0x3f
	.byte	0x1a
	.4byte	0x410
	.uleb128 0x8
	.4byte	.LASF70
	.byte	0xa
	.byte	0x41
	.byte	0x13
	.4byte	0x4d8
	.uleb128 0x8
	.4byte	.LASF71
	.byte	0xa
	.byte	0x42
	.byte	0x13
	.4byte	0x4d8
	.uleb128 0xc
	.4byte	0x9f
	.4byte	0x50c
	.uleb128 0xd
	.4byte	0x60
	.byte	0x1f
	.byte	0
	.uleb128 0x14
	.4byte	.LASF72
	.byte	0x2
	.2byte	0x114
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x14
	.4byte	.LASF73
	.byte	0x2
	.2byte	0x11d
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF74
	.byte	0xb
	.byte	0xb
	.byte	0x15
	.4byte	0x60
	.uleb128 0x15
	.byte	0xc
	.byte	0xc
	.2byte	0x104
	.byte	0x2
	.4byte	0x567
	.uleb128 0x16
	.4byte	.LASF75
	.byte	0xc
	.2byte	0x105
	.byte	0x11
	.4byte	0x3d
	.byte	0
	.uleb128 0x16
	.4byte	.LASF18
	.byte	0xc
	.2byte	0x106
	.byte	0x11
	.4byte	0x3d
	.byte	0x4
	.uleb128 0x16
	.4byte	.LASF76
	.byte	0xc
	.2byte	0x107
	.byte	0x11
	.4byte	0x59
	.byte	0x8
	.byte	0
	.uleb128 0x17
	.4byte	.LASF77
	.byte	0x68
	.byte	0xc
	.2byte	0x101
	.byte	0x8
	.4byte	0x5a0
	.uleb128 0x16
	.4byte	.LASF78
	.byte	0xc
	.2byte	0x102
	.byte	0x6
	.4byte	0x59
	.byte	0
	.uleb128 0x18
	.ascii	"end\000"
	.byte	0xc
	.2byte	0x103
	.byte	0x10
	.4byte	0x3d
	.byte	0x4
	.uleb128 0x16
	.4byte	.LASF79
	.byte	0xc
	.2byte	0x108
	.byte	0x4
	.4byte	0x5a0
	.byte	0x8
	.byte	0
	.uleb128 0xc
	.4byte	0x532
	.4byte	0x5b0
	.uleb128 0xd
	.4byte	0x60
	.byte	0x7
	.byte	0
	.uleb128 0x14
	.4byte	.LASF77
	.byte	0xc
	.2byte	0x10b
	.byte	0x17
	.4byte	0x567
	.uleb128 0x8
	.4byte	.LASF80
	.byte	0xd
	.byte	0x21
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF81
	.byte	0xd
	.byte	0x22
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF82
	.byte	0xd
	.byte	0x23
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF83
	.byte	0xd
	.byte	0x24
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF84
	.byte	0xd
	.byte	0x25
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF85
	.byte	0xd
	.byte	0x26
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF86
	.byte	0xd
	.byte	0x27
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF87
	.byte	0xd
	.byte	0x28
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF88
	.byte	0xd
	.byte	0x29
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF89
	.byte	0xd
	.byte	0x2a
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x8
	.4byte	.LASF90
	.byte	0xd
	.byte	0x2b
	.byte	0xe
	.4byte	0xbe
	.uleb128 0x2
	.4byte	.LASF91
	.byte	0xe
	.byte	0x48
	.byte	0x10
	.4byte	0xbe
	.uleb128 0xc
	.4byte	0x25
	.4byte	0x65d
	.uleb128 0xd
	.4byte	0x60
	.byte	0x5
	.byte	0
	.uleb128 0x14
	.4byte	.LASF92
	.byte	0xe
	.2byte	0x15b
	.byte	0x12
	.4byte	0x641
	.uleb128 0x14
	.4byte	.LASF93
	.byte	0xe
	.2byte	0x15c
	.byte	0x12
	.4byte	0x641
	.uleb128 0x14
	.4byte	.LASF94
	.byte	0xe
	.2byte	0x15d
	.byte	0x12
	.4byte	0x641
	.uleb128 0x14
	.4byte	.LASF95
	.byte	0xe
	.2byte	0x161
	.byte	0xe
	.4byte	0x4fc
	.uleb128 0x14
	.4byte	.LASF96
	.byte	0xe
	.2byte	0x162
	.byte	0xe
	.4byte	0x4fc
	.uleb128 0xc
	.4byte	0x9f
	.4byte	0x6ae
	.uleb128 0xd
	.4byte	0x60
	.byte	0x3f
	.byte	0
	.uleb128 0x14
	.4byte	.LASF97
	.byte	0xe
	.2byte	0x163
	.byte	0xe
	.4byte	0x69e
	.uleb128 0x14
	.4byte	.LASF98
	.byte	0xe
	.2byte	0x164
	.byte	0x10
	.4byte	0xa6
	.uleb128 0x14
	.4byte	.LASF99
	.byte	0xe
	.2byte	0x166
	.byte	0xf
	.4byte	0xbe
	.uleb128 0x14
	.4byte	.LASF100
	.byte	0xe
	.2byte	0x167
	.byte	0xf
	.4byte	0x64d
	.uleb128 0x14
	.4byte	.LASF101
	.byte	0xe
	.2byte	0x168
	.byte	0xf
	.4byte	0x64d
	.uleb128 0x14
	.4byte	.LASF102
	.byte	0xe
	.2byte	0x169
	.byte	0x12
	.4byte	0x641
	.uleb128 0x14
	.4byte	.LASF103
	.byte	0xe
	.2byte	0x16a
	.byte	0x12
	.4byte	0x641
	.uleb128 0x14
	.4byte	.LASF104
	.byte	0xe
	.2byte	0x16b
	.byte	0x19
	.4byte	0x716
	.uleb128 0x6
	.byte	0x4
	.4byte	0x31
	.uleb128 0xc
	.4byte	0x716
	.4byte	0x72c
	.uleb128 0xd
	.4byte	0x60
	.byte	0x3
	.byte	0
	.uleb128 0x14
	.4byte	.LASF105
	.byte	0xe
	.2byte	0x16c
	.byte	0x19
	.4byte	0x71c
	.uleb128 0x14
	.4byte	.LASF106
	.byte	0xe
	.2byte	0x16d
	.byte	0x19
	.4byte	0x716
	.uleb128 0x14
	.4byte	.LASF107
	.byte	0xe
	.2byte	0x16e
	.byte	0xd
	.4byte	0x59
	.uleb128 0x14
	.4byte	.LASF108
	.byte	0xe
	.2byte	0x16f
	.byte	0x12
	.4byte	0x60
	.uleb128 0x14
	.4byte	.LASF109
	.byte	0xe
	.2byte	0x170
	.byte	0xf
	.4byte	0x64d
	.uleb128 0x14
	.4byte	.LASF110
	.byte	0xe
	.2byte	0x171
	.byte	0xf
	.4byte	0x64d
	.uleb128 0x14
	.4byte	.LASF111
	.byte	0xe
	.2byte	0x175
	.byte	0x10
	.4byte	0xa6
	.uleb128 0x14
	.4byte	.LASF112
	.byte	0xe
	.2byte	0x176
	.byte	0x10
	.4byte	0xa6
	.uleb128 0x14
	.4byte	.LASF113
	.byte	0xe
	.2byte	0x178
	.byte	0xf
	.4byte	0x64d
	.uleb128 0x14
	.4byte	.LASF114
	.byte	0xe
	.2byte	0x179
	.byte	0x10
	.4byte	0xa6
	.uleb128 0x14
	.4byte	.LASF115
	.byte	0xe
	.2byte	0x17a
	.byte	0x10
	.4byte	0xa6
	.uleb128 0x14
	.4byte	.LASF116
	.byte	0xe
	.2byte	0x17c
	.byte	0xd
	.4byte	0x59
	.uleb128 0x14
	.4byte	.LASF117
	.byte	0xe
	.2byte	0x183
	.byte	0xd
	.4byte	0x59
	.uleb128 0xc
	.4byte	0x9f
	.4byte	0x7e5
	.uleb128 0xd
	.4byte	0x60
	.byte	0x7f
	.byte	0
	.uleb128 0x14
	.4byte	.LASF118
	.byte	0xe
	.2byte	0x18a
	.byte	0xd
	.4byte	0x7d5
	.uleb128 0x14
	.4byte	.LASF119
	.byte	0xe
	.2byte	0x192
	.byte	0x11
	.4byte	0x641
	.uleb128 0x19
	.4byte	.LASF123
	.byte	0x1
	.byte	0x16
	.byte	0x5
	.4byte	0x59
	.4byte	.LFB72
	.4byte	.LFE72-.LFB72
	.uleb128 0x1
	.byte	0x9c
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
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
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
	.uleb128 0x5
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
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x9
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
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
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
	.4byte	.LFB72
	.4byte	.LFE72-.LFB72
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB72
	.4byte	.LFE72
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF121:
	.ascii	"lib/asm-offsets.c\000"
.LASF61:
	.ascii	"uboot_spare_head\000"
.LASF105:
	.ascii	"NetRxPackets\000"
.LASF88:
	.ascii	"_datarellocal_start_ofs\000"
.LASF33:
	.ascii	"spare_boot_ctrl_head\000"
.LASF81:
	.ascii	"_bss_end_ofs\000"
.LASF34:
	.ascii	"jump_instruction\000"
.LASF5:
	.ascii	"unsigned int\000"
.LASF92:
	.ascii	"NetOurGatewayIP\000"
.LASF40:
	.ascii	"version\000"
.LASF41:
	.ascii	"platform\000"
.LASF98:
	.ascii	"NetBootFileSize\000"
.LASF78:
	.ascii	"nr_banks\000"
.LASF111:
	.ascii	"NetOurVLAN\000"
.LASF24:
	.ascii	"___strtok\000"
.LASF54:
	.ascii	"sdcard_gpio\000"
.LASF97:
	.ascii	"NetOurRootPath\000"
.LASF89:
	.ascii	"_datarelro_start_ofs\000"
.LASF85:
	.ascii	"_TEXT_BASE\000"
.LASF73:
	.ascii	"load_addr\000"
.LASF3:
	.ascii	"signed char\000"
.LASF106:
	.ascii	"NetRxPacket\000"
.LASF49:
	.ascii	"twi_gpio\000"
.LASF112:
	.ascii	"NetOurNativeVLAN\000"
.LASF110:
	.ascii	"NetEtherNullAddr\000"
.LASF83:
	.ascii	"IRQ_STACK_START\000"
.LASF72:
	.ascii	"monitor_flash_len\000"
.LASF17:
	.ascii	"base\000"
.LASF64:
	.ascii	"maxargs\000"
.LASF103:
	.ascii	"NetServerIP\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF122:
	.ascii	"/home/taga/NuttX/brandy/u-boot-2011.09\000"
.LASF19:
	.ascii	"lmb_property\000"
.LASF95:
	.ascii	"NetOurNISDomain\000"
.LASF10:
	.ascii	"phys_size_t\000"
.LASF96:
	.ascii	"NetOurHostName\000"
.LASF47:
	.ascii	"uart_gpio\000"
.LASF113:
	.ascii	"NetCDPAddr\000"
.LASF50:
	.ascii	"work_mode\000"
.LASF118:
	.ascii	"BootFile\000"
.LASF60:
	.ascii	"boot_data\000"
.LASF108:
	.ascii	"NetIPID\000"
.LASF93:
	.ascii	"NetOurSubnetMask\000"
.LASF68:
	.ascii	"complete\000"
.LASF36:
	.ascii	"check_sum\000"
.LASF100:
	.ascii	"NetOurEther\000"
.LASF12:
	.ascii	"char\000"
.LASF99:
	.ascii	"NetBootFileXferSize\000"
.LASF37:
	.ascii	"align_size\000"
.LASF31:
	.ascii	"data\000"
.LASF25:
	.ascii	"_normal_gpio_cfg\000"
.LASF52:
	.ascii	"nand_gpio\000"
.LASF77:
	.ascii	"meminfo\000"
.LASF80:
	.ascii	"_bss_start_ofs\000"
.LASF84:
	.ascii	"FIQ_STACK_START\000"
.LASF65:
	.ascii	"repeatable\000"
.LASF6:
	.ascii	"long long int\000"
.LASF51:
	.ascii	"storage_type\000"
.LASF90:
	.ascii	"IRQ_STACK_START_IN\000"
.LASF115:
	.ascii	"CDPApplianceVLAN\000"
.LASF44:
	.ascii	"run_clock\000"
.LASF107:
	.ascii	"NetRxPacketLen\000"
.LASF109:
	.ascii	"NetBcastAddr\000"
.LASF87:
	.ascii	"_datarelrolocal_start_ofs\000"
.LASF62:
	.ascii	"cmd_tbl_s\000"
.LASF69:
	.ascii	"cmd_tbl_t\000"
.LASF18:
	.ascii	"size\000"
.LASF116:
	.ascii	"NetState\000"
.LASF57:
	.ascii	"uboot_start_sector_in_mmc\000"
.LASF48:
	.ascii	"twi_port\000"
.LASF30:
	.ascii	"drv_level\000"
.LASF82:
	.ascii	"_end_ofs\000"
.LASF16:
	.ascii	"long double\000"
.LASF94:
	.ascii	"NetOurDNSIP\000"
.LASF74:
	.ascii	"__machine_arch_type\000"
.LASF9:
	.ascii	"phys_addr_t\000"
.LASF28:
	.ascii	"mul_sel\000"
.LASF4:
	.ascii	"short int\000"
.LASF71:
	.ascii	"__u_boot_cmd_end\000"
.LASF91:
	.ascii	"IPaddr_t\000"
.LASF11:
	.ascii	"long int\000"
.LASF117:
	.ascii	"NetRestartWrap\000"
.LASF38:
	.ascii	"length\000"
.LASF39:
	.ascii	"uboot_length\000"
.LASF46:
	.ascii	"uart_port\000"
.LASF76:
	.ascii	"node\000"
.LASF15:
	.ascii	"ulong\000"
.LASF32:
	.ascii	"normal_gpio_cfg\000"
.LASF58:
	.ascii	"spare_boot_head_t\000"
.LASF66:
	.ascii	"usage\000"
.LASF21:
	.ascii	"region\000"
.LASF63:
	.ascii	"name\000"
.LASF75:
	.ascii	"start\000"
.LASF35:
	.ascii	"magic\000"
.LASF27:
	.ascii	"port_num\000"
.LASF119:
	.ascii	"NetPingIP\000"
.LASF123:
	.ascii	"main\000"
.LASF29:
	.ascii	"pull\000"
.LASF43:
	.ascii	"dram_para\000"
.LASF55:
	.ascii	"sdcard_spare_data\000"
.LASF1:
	.ascii	"long unsigned int\000"
.LASF86:
	.ascii	"_datarel_start_ofs\000"
.LASF26:
	.ascii	"port\000"
.LASF22:
	.ascii	"memory\000"
.LASF67:
	.ascii	"help\000"
.LASF53:
	.ascii	"nand_spare_data\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF13:
	.ascii	"ushort\000"
.LASF120:
	.ascii	"GNU C17 8.2.1 20181213 (release) [gcc-8-branch revi"
	.ascii	"sion 267074] -mfloat-abi=soft -mfpu=neon -marm -mab"
	.ascii	"i=aapcs-linux -mno-thumb-interwork -mcpu=cortex-a7 "
	.ascii	"-march=armv7ve -g -Os -fno-common -ffixed-r8 -fno-b"
	.ascii	"uiltin -ffreestanding -fno-stack-protector\000"
.LASF102:
	.ascii	"NetOurIP\000"
.LASF79:
	.ascii	"bank\000"
.LASF8:
	.ascii	"uchar\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF101:
	.ascii	"NetServerEther\000"
.LASF45:
	.ascii	"run_core_vol\000"
.LASF23:
	.ascii	"reserved\000"
.LASF70:
	.ascii	"__u_boot_cmd_start\000"
.LASF14:
	.ascii	"uint\000"
.LASF42:
	.ascii	"spare_boot_data_head\000"
.LASF104:
	.ascii	"NetTxPacket\000"
.LASF114:
	.ascii	"CDPNativeVLAN\000"
.LASF56:
	.ascii	"secureos_exist\000"
.LASF59:
	.ascii	"boot_head\000"
.LASF20:
	.ascii	"lmb_region\000"
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 8-2018-q4-major) 8.2.1 20181213 (release) [gcc-8-branch revision 267074]"
