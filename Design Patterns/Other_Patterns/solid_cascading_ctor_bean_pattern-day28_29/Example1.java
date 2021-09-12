// chaining of constructors
public class Example1
{
	public static void main(String[] args)
	{
		System.out.println("hello world");
		A x1 = new A(10, 20, 30, 40, 50);
		x1.disp();
		A x2 = new A(10, 20, 30, 40);
		x2.disp();
		A x3 = new A(10, 20, 30);
		x3.disp();
		A x4 = new A(10, 20);
		x4.disp();
	}
}

class A
{
	private int a1;
	private int a2;
	private int a3;
	private int a4;
	private int a5;

	// ctor
	A(int a1, int a2, int a3, int a4, int a5)
	{
		this.a1 = a1;
		this.a2 = a2;
		this.a3 = a3;
		this.a4 = a4;
		this.a5 = a5;
	}
	A(int a1, int a2, int a3, int a4)
	{
		this(a1, a2, a3, a4, 500);
	}
	A(int a1, int a2, int a3)
	{
		this(a1, a2, a3, 400);
	}
	A(int a1, int a2)
	{
		this(a1, a2, 300);
	}
	public void disp()
	{
		System.out.println("a1 : " + a1 + " a2 : " + a2 +
			" a3 : " + a3 + " a4 : " + a4 + " a5 : " + a5);
	}
} 
