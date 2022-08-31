all:
	gcc -o extract_squashfs extract_squashfs.c
	gcc -o update_squashfs update_squashfs.c
	@cp -v extract_squashfs ../../../../tools/pack-bintools/src/extract_squashfs
	@cp -v update_squashfs ../../../../tools/pack-bintools/src/update_squashfs

clean:
	rm -rf extract_squashfs update_squashfs
