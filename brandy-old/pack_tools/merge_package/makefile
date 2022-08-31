

objects = script.o merge_package.o


edit:$(objects)
	gcc -o merge_full_img $(objects) -static
	rm -rf $(objects)
	cp merge_full_img ../../../../tools/pack-bintools/src


clean:
	rm -rf merge_full_img $(objects)
