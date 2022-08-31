

objects = check.o script.o update_boot0.o


edit:$(objects)
	gcc -o update_boot0 $(objects) -static
	rm -rf $(objects)
	@cp -v update_boot0 ../../../../tools/pack-bintools/src/update_boot0

clean:
	rm -rf update_boot0 $(objects)
