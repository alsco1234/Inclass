1) ����ü�� �ڷ����� ���� �ٸ� �ڷ���� ����
2) �ǹ̻��� �������� �ִ� ���� �ڷ� �ϳ��� ����
3) �迭 = �������ڷ�, ����ü = ���� �ڷ��� ���ÿ�

struct man { //����ü ����
	char name[30];
	int kor;
	int eng;
	int math;
	int total;
	float ave;
}

struct man student 1, student 2; //����ü ���� ����

student1.kor = 100; //student1�� �������� 100���� �Ҵ�
student1.total = student1.kor + student1.eng;

#include <stdio.h>

struct person {
	char name[20];
	char adress[80];
	int age;
};

main(){ //���� �Է¹޴� ���
	struct person p1;

	printf("�̸���?");
	scanf("%s", p1.name); // gets(p1.name)�� �Ǵµ� repl.it�� �ΰ� ���� ����
	printf("�ּҴ�?");
	scanf("%s", p1.adress);
	printf("���̴�?");
	scanf("%d", &p1.age);

	printf("%s %s %d\n", p1.name, p1.adress, p1.age);
}

//2�� ��ǥ �޾Ƽ� �Ÿ� ����ϴ� ����
strust point{
	float x;
	float y;
};
float calc_distance(struct point p1, struct point p2) //�Լ�����
main() {
	struct point p1, p2;
	p1, p2 �Է�
	dist = calc_distance(p1, p2);
	dist ���
}
//�迭�̳� ����ü�� �����͸� ����ϴ� ���� ����.
// �ֳ�? �Ʒ� main����
struct person kim; //80+20+4����Ʈ �̸� �Ҵ�
struct person* p_kim; //4����Ʈ �̸� �Ҵ�

#include <stdlib.h>// malloc�Լ�

struct person {
	char name[20];
	char adress[80];
	int age;
};

void printStruct(struct person *p); //����ü ������ ����x �����Ͱ�

main() {
	struct peson kim = { "Kim", "SEoul", 20 }; //����� �ʱ�ȭ
	struct person* p_kim; //�����ͺ���
	 p_kim = (struct person *) malloc(sizeof(struct person)); //���α׷��� ����Ǵ� �� ������ �Ÿ� �Ҵ����
	p_kim = &kim; //kim�����Ķ�
	prinfStruct(p_kim);
	printf("Name : %s\n", p_kim->name);
}

void printStruct(struct person *p) {
	p->age = 25; //����ü �����ͷ� ����� ������ ������ . ��� ->
	printf("Name : %s\n", p->name);
	printf("Adress : %s\n", p->adress);
	printf("Age : %d\n", p->age);
}