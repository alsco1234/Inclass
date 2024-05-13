 
//여러 개의  포인터를 배열로 선언

struct man { //구조체 선언
	char name[30];
	int kor;
	int eng;
	int math;
}
struct person plist[10]; //구조체 10개 메모리 미리 확보 ->비효율

///////이렇게 고치자///////////////////////

	struct person* plist[10]; //구조체를 가르키는 포인터 10개 모여잇

	for (int i = 0; i < 5; i++) {
		plist[i] = (struct person*)malloc(sizeof(struct person)); //포인터가 가르키는 실제 구조체
		printf("Name?");
		scanf("%s", plist[i]->name); //*3 //포인터는 .아니라 ->
		printf("%s", plist[i]->name);
	}

////함수버젼.///////
	void add_person(struct person* p) {
		printf("Name?");
		scanf("%s", p->name); //plist가 아니라 파라메터로 받은 p
	}
	//메인에서 
		add_person(plist[i]); //구조체 포인터 넘김

////포인터 함수버젼/////
	struct person * add_person() { //구조체만큼 메모리할당. 채워서 리턴
		struct person* p;
		p = (struct person*)malloc(sizeof(struct person)); //함수 실행할때 메모리 할당
		printf("Name?");
		scanf("%s", p->name); //plist가 아니라 파라메터로 받은 p
		return *p;
	//메인에서
		plist[i] = add_person(); //구조체 포인터 리턴 (malloc부분 x, 안에잇)
