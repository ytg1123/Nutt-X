

objects = check.o script.o update_fes1.o


edit:$(objects)
	gcc -o update_fes1 $(objects) -static
	rm -rf $(objects)


clean:
	rm -rf update_fes1 $(objects)
