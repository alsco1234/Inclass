#include <iostream>
//#include <fstream>
using namespace std;

int main(){
    for (int i=0, sum=0; i<10; i++){
        sum += i;
    }
    cout << "the sum is " + sum << endl;
    /*ifstream inFile; //이름주기
    inFile.open("test2.txt"); //1.1 입력파일 열기
    int student[3][5];
    inFile >> student[0][0] >> student[0][1] >> student[0][2] >>student[0][3] >> student[0][4];
    cout << student[0][0] << student[0][1] << student[0][2] << student[0][3] << student[0][4];*/
    return 0;
}

    /*int ** student = new int*[count]; // 1.3 각 학생 레코드 배열 선언
    for(int i=0; i<count; i++){
        student[i] = new int [5];
    }*/