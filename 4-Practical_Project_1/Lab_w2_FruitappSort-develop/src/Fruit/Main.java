package Fruit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
	public static void main(String args[]) {
		List<Fruit> al = new ArrayList<Fruit>();
		System.out.println("Fruit List (ordered by name)");
		
		al.add(new Fruit(1,"Apple",1600));
		al.add(new Fruit(2,"Banana",5000));
		al.add(new Fruit(3,"Pear",1400));
		al.add(new Fruit(4,"Orange",600));
		al.add(new Fruit(5,"Lemon",1600));
		al.add(new Fruit(6,"Mango",2000));
		al.add(new Fruit(7,"Strawberry",3000));
		al.add(new Fruit(8,"Watermelon",8000));
		al.add(new Fruit(9,"Kiwi",4000));
		al.add(new Fruit(10,"Lime",500));
	
			
		Collections.sort(al);
			
		for(Fruit s : al) {
			System.out.println(s.toString());
		}
		
		System.out.println("\nFruit List (reverse ordered by name)");
		
		Collections.sort(al, Collections.reverseOrder());
			
		for(int i=0; i<al.size(); i++) {
			System.out.println(al.get(i).toString());
		}
	}
}
