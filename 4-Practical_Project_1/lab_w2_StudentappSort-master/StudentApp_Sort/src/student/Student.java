package student;

public class Student implements Comparable<Student> {
	int no;
	String name;
	int age;
	
	public Student(int i, String string, int j) {
		this.no = i;
		this.name = string;
		this.age = j;
	}
	
	@Override
	public int compareTo(Student o) {
		return name.compareTo(o.name);
	}
	
	public String toString() {
		return "Student [no="+this.no+", name="+this.name+""
				+ ", age="+this.age+"]";
				
	}
}
