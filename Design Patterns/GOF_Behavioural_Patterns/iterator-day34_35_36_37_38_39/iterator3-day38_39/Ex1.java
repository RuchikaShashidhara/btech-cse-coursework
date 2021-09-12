class Ex1
{
	public static void main(String[] args)
	{
		int[] a = new int[]{11, 22, 33, 44, 55};
		// int[] a = {11, 22, 33, 44, 55}; // array ref on stack
		// array on the heap
		
		// iteration thro array : enhanced for
		for(int e : a)
		{
			System.out.print(e + " ");
			e += 100;
		}
		System.out.println();
		for(int e : a)
		{
			System.out.print(e + " ");
		}
		System.out.println();
		// enhanced for loop : allows iterations
		// - cannot walk thro a part of the array
		// - cannot change the element in the array
		
		
	}
}
