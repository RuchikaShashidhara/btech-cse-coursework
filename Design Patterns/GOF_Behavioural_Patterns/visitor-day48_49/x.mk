a.out : client.o shape.o rect.o circle.o square.o visitor.o disp_visitor.o area_visitor.o
	g++ client.o shape.o rect.o circle.o square.o visitor.o disp_visitor.o area_visitor.o
	
shape.o : shape.h shape.cpp
	g++ -c shape.cpp
	
circle.o : circle.h circle.cpp
	g++ -c circle.cpp

rect.o : rect.h rect.cpp
	g++ -std=c++2a -c rect.cpp

square.o : square.h square.cpp
	g++ -c square.cpp
	
visitor.o : visitor.cpp visitor.h
	g++ -c visitor.cpp
	
disp_visitor.o : disp_visitor.h disp_visitor.cpp
	g++ -c disp_visitor.cpp
	
area_visitor.o : area_visitor.h area_visitor.cpp
	g++ -c area_visitor.cpp
	
