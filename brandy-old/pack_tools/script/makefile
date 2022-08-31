

objects = script.o


edit:$(objects)
	gcc -o script $(objects) -static
	rm -rf $(objects)
	cp script ../../../../tools/pack-bintools/src/script


clean:
	rm -rf script $(objects)

