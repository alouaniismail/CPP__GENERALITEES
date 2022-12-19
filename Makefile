all: Programme.cpp Chaine.cpp
	g++ $^ -o $@
	valgrind ./$@
clean:
	rm -f *.o all *.sh~ *.cpp~ *.hpp~
