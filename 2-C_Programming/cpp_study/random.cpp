#include <stdio.h>
#include <stdlib.h>  //rand�������
#include <time.h> //time�������
#define	YES 1
#define NO	0

sprintf(���ڿ�����, ����, ������...);
sprintf(str, "%d�� ����� %d���Դϴ�", name, age); //name, age�� ������ ����
-- > str�� "name�� ����� age���Դϴ�"�� �����
printf("������ ���ڿ� : %s", str)//���

rand();
// <stdlib.h>�� <time.h> �������
1. void srand(unsunged seed); // �������� ���� ���´�
2. int rand(); // ������ Ư�� �������� ����� ����
num = rand() % 6 + 1; // ���� + ù��
num = (double)(rand()%2001-1000)/1000.0 // -1.0000 ~ 1.0000

time_t time( time_t *arg) //�ð��� ����� ��
// <time.h>�������
// ()�ȿ� \n�̸� ����ð����� ����

ex) int num; //���Ƿ� ���� ���� ��
srand(time(0)); //����ð��� ������ ���� �� ���� (�����Ҷ�����)
srand(timr(NULL)); //(���ư�������)
num = rand();
printf("������� �� :%d\n", num); //->�����Ҷ����� '����ð�'�ٲ�, ��ӹٲ�