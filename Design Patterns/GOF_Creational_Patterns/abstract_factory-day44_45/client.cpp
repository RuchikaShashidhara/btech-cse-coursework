#include <iostream>
using namespace std;
#include "prestige_factory.h"
#include "pigeon_factory.h"
#include "cooker.h"


int main()
{
	Factory *f = new Prestige_Factory();
	Cooker c(f);
	
	Factory *f1 = new Pigeon_Factory();
	Cooker c1(f1);
}
