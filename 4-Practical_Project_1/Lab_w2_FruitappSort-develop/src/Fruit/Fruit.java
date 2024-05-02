package Fruit;


public  class Fruit implements Comparable<Fruit>{
	int no;
	String name;
	int price;
	
	public Fruit(int i, String string, int j) {
		this.no = i;
		this.name = string;
		this.price = j;
	}
	
	
	public String toString() {
		return "Fruit [no="+this.no+", name="+this.name+""
				+ ", age="+this.price+"]";
				
	}

	@Override
	public int compareTo(Fruit o) {
		return name.compareTo(o.name);
	}
}
