#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 배열버전, 20명까지 관리
 
typedef struct{
   char name[20];
    int kor;
    int eng;
    int math;
    int sum;
    float avg;
} Score;
   
int addScore(Score *s);
void readScore(Score s);
void listScore(Score *s[], int count);
int selectDataNo(Score *s[], int count);
int updateScore(Score *s);
void saveData(Score *s[], int count);
int loadData(Score *s[]);
void searchName(Score *s[], int count);
   
int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
   
int main(void){
    Score *sp[20]; //포인터 배열 변수 선언
    int index; //데이터번호
    int count = loadData(sp); 
    index = count;
    int menu;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0)
                listScore(sp, index);
            else
                printf("데이터가 없습니다,\n");
        }
        else if (menu == 2){
            sp[index] = (Score *)malloc(sizeof(Score)); //메모리할당
            count += addScore(sp[index++]);
            }
        else if (menu == 3){
            int no = selectDataNo(sp, index);
            if(no ==0){
                printf("==> 취소됨!\n");
                continue;
            }
            updateScore(sp[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(sp, index);
            if(no == 0){
                printf("==> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(sp[no-1]) free(sp[no-1]); //메모리풀기
                sp[no-1] = NULL;
                count --;
                printf("=> 삭제됨!");
            }
        }
        else if (menu ==5){
            saveData(sp, index);
        }
        else if (menu ==6){
            searchName(sp, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
   
int addScore(Score *s){
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    s->sum =0;
    s->sum += s->kor + s->math + s->eng;
    s->avg = s->sum/3.0;
    return 1;
}
   
void readScore(Score s){
    printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",s.name,s.kor,s.eng,s.math,s.sum,s.avg);
}
   
void listScore(Score *s[], int count){
    printf("Name\tKor\tEng\tMath\tSum\tAvg\n");
    printf("============================================\n");
    for(int i=0; i<count; i++){
        if(s[i] == NULL) continue;
        printf("%2d ", i+1);
        readScore(*s[i]);
    }
printf("\n");
}
   
int selectDataNo(Score *s[], int count){
    int no;
    listScore(s, count);
    printf("번호는 (취소:0)? ");
    scanf("%d", &no);
    return no;
}
   
int updateScore(Score *s){
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    s->sum =0;
    s->sum += s->kor + s->math + s->eng;
    s->avg = s->sum/3.0;
    printf("=> 수정됨!\n");
    return 0;
}

void saveData(Score *s[], int count){
	FILE *fp;
    fp = fopen("score.txt", "wt");
    for(int i=0; i<count; i++){
        if(s[i]->kor == -1) continue;
        fprintf(fp, "%s %d %d %d \n", s[i]->name, s[i]->kor, s[i]->eng, s[i]->math);
    }
    fclose(fp);
    printf("==>저장됨! ");
}

int loadData(Score *s[]){
    int count =0;
    FILE *fp;
    if(!fopen("score.txt", "rt"))printf("=> 파일 없음");
    else{
        while (!feof(fp)) { //파일의 끝이 아니면
	    fscanf(fp, "%s %d %d %d \n", s[count]->name, &s[count]->kor, &s[count]->eng, &s[count]->math);
		count++;
        }
    }
}

void searchName(Score *s[], int count){
    int scnt = 0;
    char search[20];
    printf("검색할 이름? ");
    scanf("%s", search);
    printf("\nNo Name Kor Eng Math Sum Avg\n");
    printf("================================\n");
    for(int i =0; i <count ; i++){
        if(s[i]->kor == -1) continue;
        if(strstr(s[i]->name, search)){
            printf("%2d ", i+1);
            readScore(*s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}