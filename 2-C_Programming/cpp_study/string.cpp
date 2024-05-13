#include <stdio.h>
#include <string.h)> //문자열 관련된 헤더파일

int main(void) {
    6장 : 문자열 다루기

        char str // 문자열
        printf("문자열을 입력하세요");
    scanf("%s", str) //%s로 입력받는 문자열 &안받
                           // 띄어쓰기 기준으로 나뉨
        fgets(str, 80, stdin) //키보드로부터(stdin) 80개의 문자 받아 str에 저장
                                     //띄어쓰기로 나누어지지 않음


        int length = strlen(str); //문자열 검사 -> 끝의 enter까지 입력받 
                                 //ex) str = Hello ->5+1(엔터) ->6
    printf("%d", strlen(str)); //warning뜸. strlen은 마이너스 안나와서
     //-> (int)strlen(str) 아님 (unsigned int)strlen(str)써야.


    int cmpresult = strcmp(str1, str2); // 전부다 cmp(compare비교) : str2 - str1
                                        // 사전적으로 먼저 나오나? (대소문자 구분)
    int cmpresult = strncmp(str1, str2, 2) //몇글자까지 비교? ->2글자만 비교


        strcpy(str2, str1) //str"copy" -> str1을 str2에 복붙
        strcpy(str2, "Good Luck!")// -> str2에 "Good Luck!" 넣기


        strcat(str2, "Good Luck!") // -> str2(엔터까지입력받) + Good Luck ->뒤에붙이기
        strncat(str2, "Good Luck!", 2)//몇글자까지 붙이기? ->2글자만 붙이기 -> str2(enter입력)+Go
        응용 : 엔터뺴기
        // str의 엔터빼고 str2에붙임


        int strstr(str1, str2) //문자열(str1)에 검사단어(str2)있나?
                               // 0(포함안됨) 1(포함됨)
         // -> 주의 : 검사단어(str2)입력받을때 enter들어가는거 주의
        if (strstr(str1, str2) != 0)printf("검색어가 포함됨");
    전에 str2[strlen(str2) - 1] = '\0' //Hello\n에서 \n를 non문자로 바꿔야

        return 0;
}