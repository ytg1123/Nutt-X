OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
 . = (0x40900000);
 . = ALIGN(4);
 .head :
 {
  arch/arm/cpu/armv7/sun8iw5/spare_head.o (.data)
 }
        .hash :
        {
                arch/arm/cpu/armv7/sun8iw5/../uboot_hash.o (.data)
        }
 . = ALIGN(1);
 .text :
 {
  __int_vector_start = .;
  arch/arm/cpu/armv7/start.o (.text*)
  __int_vector_end = .;
  *(.text)
 }
 . = ALIGN(16);
 .rodata :
 {
  *(.rodata*)
 }
 . = ALIGN(16);
 .data :
 {
  *(.data)
 }
 . = ALIGN(4);
 . = .;
 __u_boot_cmd_start = .;
 .u_boot_cmd : { *(.u_boot_cmd) }
 __u_boot_cmd_end = .;
 . = ALIGN(4);
 __image_copy_end = .;
 .rel.dyn : {
  __rel_dyn_start = .;
  *(.rel*)
  __rel_dyn_end = .;
 }
 .dynsym : {
  __dynsym_start = .;
  *(.dynsym)
 }
 _end = .;
 .bss __rel_dyn_start (OVERLAY) : {
  __bss_start = .;
  *(.bss)
   . = ALIGN(4);
  __bss_end__ = .;
 }
 /DISCARD/ : { *(.dynstr*) }
 /DISCARD/ : { *(.dynamic*) }
 /DISCARD/ : { *(.plt*) }
 /DISCARD/ : { *(.interp*) }
 /DISCARD/ : { *(.gnu*) }
}
