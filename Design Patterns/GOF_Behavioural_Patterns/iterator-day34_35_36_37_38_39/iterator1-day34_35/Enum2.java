class Enum2
{
	public static void main(String[] args)
	{
		System.out.println(NTon.kuvempu);
		NTon x = NTon.bendre;
		System.out.println(x);
		//NTon y = new NTon("aaaa", "bbbb"); // NO
		// enhanced forloop
		for(NTon nton : NTon.values())
		{
			System.out.println(nton);
		}
		
		
	
	}
}
// Java : single rooted hierarchy
enum NTon 
{
	kuvempu("kannada", "sri ramayanadarshanam"),
	bendre("kannada", "naakutanti"),
	narayan("english", "malgudi days"),
	kalidasa("samskrita", "shankuntala");
	
	private String lang;
	private String title;
	
	private NTon(String lang, String title)
	{
		this.lang = lang;
		this.title = title;	
	} 
	public String toString()
	{
		return lang + ":" + title;
	}
}
