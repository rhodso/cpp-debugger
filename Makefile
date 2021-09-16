cpp-debugger : obj/main.o obj/dbg.o
	g++ -o cpp-debugger obj/main.o obj/dbg.o

obj/main.o :
	g++ -c src/main.cpp -I headers -o obj/main.o -fPIC

obj/dbg.o : 
	g++ -c src/dbg.cpp -I headers -o obj/dbg.o -fPIC

clean: 
	rm -rfv obj
	mkdir obj
	rm -f cpp-debugger

run: cpp-debugger
	./cpp-debugger

