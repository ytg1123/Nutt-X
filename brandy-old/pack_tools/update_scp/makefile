objects = update_scp.o 		\
				  libfdt/fdt.o	\
				  libfdt/fdt_ro.o	\
				  libfdt/fdt_wip.o	\
				  libfdt/fdt_sw.o	\
				  libfdt/fdt_rw.o	\
				  libfdt/fdt_strerror.o	\
				  libfdt/fdt_empty_tree.o	\
				  libscript/script.o	\

edit:$(objects)
	gcc $(INCLUDE) -o  update_scp $(objects)
	rm -rf $(objects)
	@cp -v update_scp ../../../../tools/pack-bintools/src/update_scp

clean:
	rm -rf update_scp $(objects)
