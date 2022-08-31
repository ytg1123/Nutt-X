objects = update_dtb.o


edit:$(objects)
	gcc -o update_dtb $(objects) -static
	rm -rf $(objects)
	cp update_dtb ../../../../tools/pack-bintools/src/update_dtb


clean:
	rm -rf update_dtb $(objects)

