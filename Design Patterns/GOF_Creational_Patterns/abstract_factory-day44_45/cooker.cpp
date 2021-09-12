#include <iostream>
using namespace std;
#include "factory.h"
#include "cooker.h"

Cooker::Cooker(Factory *f)
: ptr_body(f->create_body()), ptr_lid(f->create_lid())
{
	cout << "cooker ready !!\n";
}

