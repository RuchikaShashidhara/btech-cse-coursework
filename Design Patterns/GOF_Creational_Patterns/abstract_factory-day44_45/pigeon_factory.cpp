#include <iostream>
using namespace std;
#include "pigeon_factory.h"
#include "pigeon_body.h"
#include "pigeon_lid.h"

Body* Pigeon_Factory::create_body()
{
	cout << "Pigeon factory creating body\n";
	return new Pigeon_Body();
}
Lid* Pigeon_Factory::create_lid()
{
	cout << "Pigeon factory creating lid\n";
	return new Pigeon_Lid();
}
