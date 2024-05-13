#include <stdio.h>
#include <stdlib.h>  //rand헤더파일
#include <time.h> //time헤더파일
#define	YES 1
#define NO	0

sprintf(문자열병수, 포맷, 변수들...);
sprintf(str, "%d님 당신은 %d살입니다", name, age); //name, age는 이전에 정의
-- > str에 "name님 당신은 age살입니다"가 저장됨
printf("생성된 문자열 : %s", str)//출력

rand();
// <stdlib.h>와 <time.h> 헤더파일
1. void srand(unsunged seed); // 랜덤수를 위해 섞는다
2. int rand(); // 임의의 특정 정수값을 만들어 리턴
num = rand() % 6 + 1; // 개수 + 첫값
num = (double)(rand()%2001-1000)/1000.0 // -1.0000 ~ 1.0000

time_t time( time_t *arg) //시간을 만들어 냄
// <time.h>헤더파일
// ()안에 \n이면 현재시간으로 섞음

ex) int num; //임의로 만들 랜덤 수
srand(time(0)); //현재시간의 값으로 랜덤 수 섞기 (실행할때마다)
srand(timr(NULL)); //(돌아갈때마다)
num = rand();
printf("만들어진 수 :%d\n", num); //->실행할때마다 '현재시간'바뀜, 계속바뀜