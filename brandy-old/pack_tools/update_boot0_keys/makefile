
objects = check.o update_boot0_keys.o

edit:$(objects)
	gcc -o update_boot0_keys $(objects) -static
	rm -rf $(objects)
	@cp -v update_boot0_keys ../../../../tools/pack-bintools/src/update_boot0_keys

clean:
	rm -rf update_boot0_keys $(objects)
