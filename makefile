CC=g++
libs=-lm
objs=declarations_shapes.o project_main.o

project: $(objs)
	$(CC) $^ -o $@ $(libs)

main.o: project_main.cpp
	$(CC) -c $^ -o $@

declarations_shapes.o: declarations_shapes.cpp
	$(CC) -c $^ -o $@

clean: $(objs)
	rm $^
