#include <stdio.h>
#include <string.h)> //���ڿ� ���õ� �������

int main(void) {
    6�� : ���ڿ� �ٷ��

        char str // ���ڿ�
        printf("���ڿ��� �Է��ϼ���");
    scanf("%s", str) //%s�� �Է¹޴� ���ڿ� &�ȹ�
                           // ���� �������� ����
        fgets(str, 80, stdin) //Ű����κ���(stdin) 80���� ���� �޾� str�� ����
                                     //����� ���������� ����


        int length = strlen(str); //���ڿ� �˻� -> ���� enter���� �Է¹� 
                                 //ex) str = Hello ->5+1(����) ->6
    printf("%d", strlen(str)); //warning��. strlen�� ���̳ʽ� �ȳ��ͼ�
     //-> (int)strlen(str) �ƴ� (unsigned int)strlen(str)���.


    int cmpresult = strcmp(str1, str2); // ���δ� cmp(compare��) : str2 - str1
                                        // ���������� ���� ������? (��ҹ��� ����)
    int cmpresult = strncmp(str1, str2, 2) //����ڱ��� ��? ->2���ڸ� ��


        strcpy(str2, str1) //str"copy" -> str1�� str2�� ����
        strcpy(str2, "Good Luck!")// -> str2�� "Good Luck!" �ֱ�


        strcat(str2, "Good Luck!") // -> str2(���ͱ����Է¹�) + Good Luck ->�ڿ����̱�
        strncat(str2, "Good Luck!", 2)//����ڱ��� ���̱�? ->2���ڸ� ���̱� -> str2(enter�Է�)+Go
        ���� : ���͕���
        // str�� ���ͻ��� str2������


        int strstr(str1, str2) //���ڿ�(str1)�� �˻�ܾ�(str2)�ֳ�?
                               // 0(���Ծȵ�) 1(���Ե�)
         // -> ���� : �˻�ܾ�(str2)�Է¹����� enter���°� ����
        if (strstr(str1, str2) != 0)printf("�˻�� ���Ե�");
    ���� str2[strlen(str2) - 1] = '\0' //Hello\n���� \n�� non���ڷ� �ٲ��

        return 0;
}