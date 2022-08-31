cmd_drivers/gpio/built-in.o :=  arm-none-eabi-ld.bfd     -r -o drivers/gpio/built-in.o drivers/gpio/axp_gpio.o drivers/gpio/gpio-uclass.o drivers/gpio/sunxi_gpio.o 
