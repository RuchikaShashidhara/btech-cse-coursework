// setters and getters
//	designing a class wherein
//		a1 a2 have to be initialized
//		a3 a4 a5 might be initialized
// BEAN pattern

public class Example2
{
	public static void main(String[] args)
	{
		System.out.println("hello world");
		// set a1 a2 a3 a5; take a4 by default
		A x1 = new A(10, 20).set_a3(30).set_a5(50);
		x1.disp();
		A x2 = new A(10, 20);
		x2.disp();
		A x3 = new A(11, 22).set_a4(44);
		x3.disp();
		
		//new A(1, 2, 3, 4, 5).disp();
	}
}

class A
{
	private int a1;
	private int a2;
	private int a3 = 111;
	private int a4 = 222;
	private int a5 = 333;

	A(int a1, int a2)
	{
		this.a1 = a1; this.a2 = a2;
	}
	
	int get_a1() { return a1; }
	int get_a2() { return a2; }
	int get_a3() { return a3; }
	int get_a4() { return a4; }
	int get_a5() { return a5; }
	
	A set_a1(int a1) { this.a1 = a1; return this; }
	A set_a2(int a2) { this.a2 = a2; return this; }
	A set_a3(int a3) { this.a3 = a3; return this; }
	A set_a4(int a4) { this.a4 = a4; return this; }
	A set_a5(int a5) { this.a5 = a5; return this; }
	
	public void disp()
	{
		System.out.println("a1 : " + this.get_a1() + " a2 : " + this.get_a2() +
			" a3 : " + this.get_a3() + 
			" a4 : " + this.get_a4() +
			 " a5 : " + this.get_a5());
	}
} 
// this : implicit parameter when an instance method of the class is called
//			reference in Java
//	use of this :
//	a) call another ctor of the same class
//	b) return the object back



