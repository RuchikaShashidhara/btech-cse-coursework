class Enum1
{
	public static void main(String[] args)
	{
		System.out.println("hello world");
		System.out.println(Dir.EAST);
		Dir d = Dir.SOUTH;
		System.out.println(Dir.SOUTH);
		for(Dir dd : Dir.values())
		{
			System.out.println(dd);
		}
		
	
	}
}
// create some const number of objects
enum Dir 
{
	NORTH, EAST, SOUTH, WEST;
}
