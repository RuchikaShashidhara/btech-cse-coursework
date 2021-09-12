a.out : factory.o prestige_factory.o pigeon_factory.o cooker.o client.o body.o  prestige_body.o pigeon_body.o lid.o prestige_lid.o pigeon_lid.o
	g++ factory.o prestige_factory.o pigeon_factory.o cooker.o client.o body.o  prestige_body.o pigeon_body.o lid.o prestige_lid.o pigeon_lid.o
	
factory.o : factory.cpp factory.h
	g++ -c factory.cpp
prestige_factory.o : prestige_factory.cpp prestige_factory.h
	g++ -c prestige_factory.cpp	 
pigeon_factory.o : pigeon_factory.cpp pigeon_factory.h
	g++ -c pigeon_factory.cpp	
cooker.o : cooker.cpp cooker.h
	g++ -c cooker.cpp
client.o : client.cpp prestige_factory.h pigeon_factory.h cooker.h
	g++ -c client.cpp
body.o : body.cpp body.h
	g++ -c body.cpp
prestige_body.o : prestige_body.cpp  prestige_body.h
	g++ -c prestige_body.cpp
pigeon_body.o : pigeon_body.cpp  pigeon_body.h
	g++ -c pigeon_body.cpp
lid.o : lid.cpp lid.h
	g++ -c lid.cpp
prestige_lid.o : prestige_lid.cpp  prestige_lid.h
	g++ -c prestige_lid.cpp
pigeon_lid.o : pigeon_lid.cpp  pigeon_lid.h
	g++ -c pigeon_lid.cpp
	
