1) 구조체는 자료형이 서로 다른 자료들의 집합
2) 의미상을 연관성이 있는 여러 자료 하나로 묶어
3) 배열 = 동일한자료, 구조체 = 여러 자료형 동시에

struct man { //구조체 선언
	char name[30];
	int kor;
	int eng;
	int math;
	int total;
	float ave;
}

struct man student 1, student 2; //구조체 변수 선언

student1.kor = 100; //student1의 국어점수 100으로 할당
student1.total = student1.kor + student1.eng;

#include <stdio.h>

struct person {
	char name[20];
	char adress[80];
	int age;
};

main(){ //직졉 입력받는 경우
	struct person p1;

	printf("이름은?");
	scanf("%s", p1.name); // gets(p1.name)도 되는데 repl.it은 두개 쓰면 오류
	printf("주소는?");
	scanf("%s", p1.adress);
	printf("나이는?");
	scanf("%d", &p1.age);

	printf("%s %s %d\n", p1.name, p1.adress, p1.age);
}

//2개 좌표 받아서 거리 출력하는 문제
strust point{
	float x;
	float y;
};
float calc_distance(struct point p1, struct point p2) //함수선언
main() {
	struct point p1, p2;
	p1, p2 입력
	dist = calc_distance(p1, p2);
	dist 출력
}
//배열이나 구조체는 포인터를 사용하는 것이 좋다.
// 왜냐? 아래 main에서
struct person kim; //80+20+4바이트 미리 할당
struct person* p_kim; //4바이트 미리 할당

#include <stdlib.h>// malloc함수

struct person {
	char name[20];
	char adress[80];
	int age;
};

void printStruct(struct person *p); //구조체 변수가 직접x 포인터가

main() {
	struct peson kim = { "Kim", "SEoul", 20 }; //선언과 초기화
	struct person* p_kim; //포인터변수
	 p_kim = (struct person *) malloc(sizeof(struct person)); //프로그램이 실행되는 그 시점에 매모리 할당받음
	p_kim = &kim; //kim가르쳐라
	prinfStruct(p_kim);
	printf("Name : %s\n", p_kim->name);
}

void printStruct(struct person *p) {
	p->age = 25; //구조체 포인터로 멤버를 접근할 때에는 . 대신 ->
	printf("Name : %s\n", p->name);
	printf("Adress : %s\n", p->adress);
	printf("Age : %d\n", p->age);
}