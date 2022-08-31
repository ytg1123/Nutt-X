cmd_dts/dt-spl.dtb := ./tools/fdtgrep -b u-boot,dm-pre-reloc -b u-boot,dm-spl -RT arch/arm/dts/sun8i-a33-vividnode.dtb -n /chosen -n /config -O dtb | ./tools/fdtgrep -r -O dtb - -o dts/dt-spl.dtb 
