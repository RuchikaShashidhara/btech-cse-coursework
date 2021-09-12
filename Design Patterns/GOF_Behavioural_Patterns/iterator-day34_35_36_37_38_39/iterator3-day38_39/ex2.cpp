#include <iostream>
using namespace std;

int main()
{
	int a[] = {11, 22, 33, 44, 55};
	// range for
	for(int e : a)
	{
		cout << e << "\t";
	}
	cout << "\n";
	for(int& e : a)
	{
		cout << e << "\t";
		e += 100;
	}
	cout << "\n";
	for(int e : a)
	{
		cout << e << "\t";
	}
	cout << "\n";

}
