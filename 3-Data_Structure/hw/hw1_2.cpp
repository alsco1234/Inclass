#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FinalScore (int student_score[][7], int num_student); //computes final score for each student
void Rank (int student_score[][7], int num_student); //computes rank for each student
void SelectionSort(int student_score[][7], int num_student);
float ClassAverage (int student_score[][7], int num_student); //computes class average

int main(){
    int count(0);
    int avg;

    //1. ���� �б�
      
    if(inFile.is_open()){
        while (count<1){
            inFile >> count; //1.2 �л� �� �б�
            if (!inFile.fail()){ //���ڵ����� �������
                continue; 
            }
            inFile.clear();
            inFile >> trash;
        }
    }
    int student[100][7];//1.3 �л� �迭 ����
    if(inFile.is_open()){
        for(int i=0; i<8; i++) inFile >> trash;
        for(int i=0; i<count*5; i++){
            for(int j=0; j<count; j++){
                for(int h=0; h<5; h++){
                    if (!inFile.fail()){ //���� �������
                        inFile >> student[j][h];//1.4 �б�
                        continue; 
                    }
                    inFile.clear();
                    inFile >> trash;
                }
            }
        }
    }
    inFile.close(); //1.5 �Է� ���� �ݱ�

    //2 ��� ���
    for(int i=0; i<count; i++){
        FinalScore (student, i);// 2.1 FinalScore �̿� -> �� �������� ���
    }
    Rank (student, count);// 2.2 Ramk �̿� -> ��� ���
    avg = ClassAverage (student, count); //2.3 ClassAverage �̿� -> ����� ���

    //3. ��� ���Ͽ� ��� ���
    ofstream fout;
    fout.open("output.txt");// 3.1 ��� ���� ����
    if(fout.is_open()){
        fout << "Student id Final Score Rank" << endl;
        for (int i=0; i<count; i++){
            fout << student[i][0] <<"\t" << student[i][5] << "\t" << student[i][6] << endl;// 3.2 ��� ����ϱ�
        }
        fout << "Class average: " << avg << endl;
    }
    inFile.close();// 3.3 ��� ���� �ݱ�
    return 0;
}

void FinalScore (int student_score[][7], int num_student){
    int sum(0);
    sum += student_score[num_student][1]*20;
    sum += student_score[num_student][2]*20;
    sum += student_score[num_student][3]*50;
    sum += student_score[num_student][4]*10;
    student_score[num_student][5] = sum/100;
}

void Rank (int student_score[][7], int num_student){
    SelectionSort(student_score, num_student);
    for(int i=0; i<num_student; i++){
        student_score[i][6] = i+1;
    }
}

void SelectionSort(int student_score[][7], int num_student){
    int i(0), j(0), min(999), temp[6];
    for(i=0; i<num_student-1; i++){
        min = i;
        for(j=i+1; j< num_student; j++){
            if(student_score[j][5] < student_score[min][5])
                min = j;
            }
    for(int j=0; j<6; j++){
        temp[j] = student_score[i][j];
    }
    for(int j=0; j<6; j++){
        student_score[i][j] = student_score[min][j];
    }
    for(int j=0; j<6; j++){
        student_score[min][j] = temp[j];
    }
  }
}

float ClassAverage (int student_score[][7], int num_student){
    float sum(0);
    for(int i=0; i<num_student; i++){
        sum += student_score[i][5];
    }
    return sum/num_student*1.0;
}