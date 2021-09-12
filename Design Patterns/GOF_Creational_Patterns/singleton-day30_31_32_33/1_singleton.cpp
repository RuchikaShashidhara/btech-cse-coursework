#include <iostream>
using namespace std;
// 3. 
class Singleton
{
	public:
	//Singleton() = delete;//NO
	static Singleton* instance()
	{
		if(instance_ == nullptr)
		{
			instance_ = new Singleton;
		}
		return instance_;
	}
	Singleton(const Singleton&) = delete;
	private:
	static Singleton* instance_;
	Singleton() = default;
};
Singleton* Singleton::instance_ = nullptr;
int main()
{
	Singleton *p1 = Singleton::instance();
	Singleton *p2 = Singleton::instance();
	cout << p1 << "\n";
	cout << p2 << "\n";
	//Singleton st1;
	//cout << &st1 << "\n";
	//Singleton st2(*p1);
	//cout << &st2 << "\n";
}
// what about :
//	assignment operator? delete it
// what if the client calls delete on p1?  make dtor private

// should we make p1 and p2 refer to a reference counted object? not normally done
//		- is possible

