

objects = check.o script.o update_uboot.o


edit:$(objects)
	gcc -o update_uboot $(objects) -static
	rm -rf $(objects)
	@cp -v update_uboot ../../../../tools/pack-bintools/src/update_uboot


clean:
	rm -rf update_uboot $(objects)
