 
//���� ����  �����͸� �迭�� ����

struct man { //����ü ����
	char name[30];
	int kor;
	int eng;
	int math;
}
struct person plist[10]; //����ü 10�� �޸� �̸� Ȯ�� ->��ȿ��

///////�̷��� ��ġ��///////////////////////

	struct person* plist[10]; //����ü�� ����Ű�� ������ 10�� ����

	for (int i = 0; i < 5; i++) {
		plist[i] = (struct person*)malloc(sizeof(struct person)); //�����Ͱ� ����Ű�� ���� ����ü
		printf("Name?");
		scanf("%s", plist[i]->name); //*3 //�����ʹ� .�ƴ϶� ->
		printf("%s", plist[i]->name);
	}

////�Լ�����.///////
	void add_person(struct person* p) {
		printf("Name?");
		scanf("%s", p->name); //plist�� �ƴ϶� �Ķ���ͷ� ���� p
	}
	//���ο��� 
		add_person(plist[i]); //����ü ������ �ѱ�

////������ �Լ�����/////
	struct person * add_person() { //����ü��ŭ �޸��Ҵ�. ä���� ����
		struct person* p;
		p = (struct person*)malloc(sizeof(struct person)); //�Լ� �����Ҷ� �޸� �Ҵ�
		printf("Name?");
		scanf("%s", p->name); //plist�� �ƴ϶� �Ķ���ͷ� ���� p
		return *p;
	//���ο���
		plist[i] = add_person(); //����ü ������ ���� (malloc�κ� x, �ȿ���)
