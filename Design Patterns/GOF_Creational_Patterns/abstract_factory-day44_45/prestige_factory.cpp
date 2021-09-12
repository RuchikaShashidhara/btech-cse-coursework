#include <iostream>
using namespace std;
#include "prestige_factory.h"
#include "prestige_body.h"
#include "prestige_lid.h"

Body* Prestige_Factory::create_body()
{
	cout << "prestige factory creating body\n";
	return new Prestige_Body();
}
Lid* Prestige_Factory::create_lid()
{
	cout << "prestige factory creating lid\n";
	return new Prestige_Lid();
}
