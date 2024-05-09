#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <time.h>
/*
(1) 강의 slide chapter 7.Sorting (sorting)
(2) 강의 slide chapter Introduction to C++ (file I/O)
(3) Blog https://terrorjang.tistory.com/98 (array 동적할당)
(4) Blog https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kks227&logNo=220224305396 (이어쓰기)
(5) Blog https://hijuworld.tistory.com/1 (시간 측정)
*/
using namespace std;

double result[3][5] = {0};

int selectionSort(int num[], int size){ //comparison 리턴
    int count=0;
    clock_t start, end;
    double timeresult;
    //1. 저장할배열 만들기
    int *selectionnum = new int[size];
    for(int i=0; i<size; i++){
        selectionnum[i] = num[i];
    }
    //2. sorting
    int i=0, j=0, min=0, temp=0;
    start = time(NULL); // 시간 측정 시작
    for(i=0; i<size-1; i++){
        min=i;
        for(j=i+1; j<size; j++){
            count++;
            if(selectionnum[j] < selectionnum[min]){
                min = j;
            }
        }
    int numtemp = selectionnum[i];
    selectionnum[i] = selectionnum[min];
    selectionnum[min] = numtemp;
    }
    end = time(NULL); // 시간 측정 끝
    timeresult = (double)(end - start);
    int datasize = size; //10->0, 100->1, 1000->2, 
    int n=0;
    while(datasize>1){
        datasize= datasize/10;
        n++;
    }
    result[0][n-1] = timeresult;
    //3. sorted.txt
    ofstream outFile;
    outFile.open("sorted.txt", ios::app);
    if(outFile.is_open()) { //열려있는동안
        outFile << "selection(" << size << "): " << endl;
        for(int i=0; i<size; i++)
            outFile << selectionnum[i] << " ";
        outFile << endl;
    }
    outFile.close(); //출력파일닫기
    //4. output.txt
    delete[] selectionnum;
    return count;
}

int insertionSort(int num[], int size){
    int count=0;
    clock_t start, end;
    double timeresult;
    //1. 저장할배열 만들기
    int *insertionnum = new int[size];
    for(int i=0; i<size; i++){
        insertionnum[i] = num[i];
    }
    //2. sorting
    int i, j;
    int next;
    start = time(NULL); // 시간 측정 시작
    for(i=1; i<size; i++){
        next = insertionnum[i];
        for(j=i-1; j>=0 && next < insertionnum[j]; j--){
            insertionnum[j+1] = insertionnum[j];
            count++;
        }
        count++; //위에 for에서 맨마지막 비교 +안함
        insertionnum[j+1] = next;
    }
    end = time(NULL); // 시간 측정 끝
    timeresult = (double)(end - start);
    int datasize = size; //10->0, 100->1, 1000->2, 
    int n=0;
    while(datasize>1){
        datasize= datasize/10;
        n++;
    }
    result[1][n-1] = timeresult;
    //3. sorted.txt
    ofstream outFile;
    outFile.open("sorted.txt", ios::app);
    if(outFile.is_open()) { //열려있는동안
        outFile << "insertion(" << size << "): " << endl;
        for(int i=0; i<size; i++)
            outFile << insertionnum[i] << " ";
        outFile << endl;
    }
    outFile.close(); //출력파일닫기
    //4. output.txt
    delete[] insertionnum;
    return count;
}

int QuickSort(int num[], int left, int right, int count){
    int pivot, i, j;
    int tmp;
    if(left<right){
        i=left;
        j=right+1;
        pivot = num[left];
        do{
            do {i++; count++;}
                while(i<=right && num[i]<pivot);
            do {j--; count++;}
                while(j>left && num[j]>pivot);
            if(i<j){
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }while(i<j);
    tmp = num[left];
    num[left] = num[j];
    num[j] = tmp;
    count = QuickSort(num, left, j-1, count);
    count = QuickSort(num, j+1, right, count);
    }
    return count;
}

int quickSort(int num[], int size){
    int count=0;
    clock_t start, end;
    double timeresult;
    //1. 저장할배열 만들기
    int *quicknum = new int[size];
    for(int i=0; i<size; i++){
        quicknum[i] = num[i];
    }
    //2. sorting
    start = time(NULL); // 시간 측정 시작
    count = QuickSort(quicknum, 0, size-1, count);
    end = time(NULL); // 시간 측정 끝
    timeresult = (double)(end - start);
    int datasize = size; //10->0, 100->1, 1000->2, 
    int n=0;
    while(datasize>1){
        datasize= datasize/10;
        n++;
    }
    result[2][n-1] = timeresult;
    //3. sorted.txt
    ofstream outFile;
    outFile.open("sorted.txt", ios::app);
    if(outFile.is_open()) { //열려있는동안
        outFile << "quick(" << size << "): " << endl;
        for(int i=0; i<size; i++)
            outFile << quicknum[i] << " ";
        outFile << endl;
    }
    outFile.close(); //출력파일닫기
    //4. output.txt
    delete[] quicknum;
    return count;
}

int main(void){
    int datasize=10;
    long int comparison[3][5] = {0};
    int size=0;
    ofstream outFile;
    outFile.open("sorted.txt");
    if(outFile.is_open()) { //열려있는동안
        outFile << "sorted data" << endl;
    }
    outFile.close(); //출력파일닫기
    for(datasize=10; datasize<=100000; datasize=datasize*10){
        int *randomnum = new int[datasize];
        srand(518);
        for(int i=0; i<datasize; i++){
            randomnum[i] = rand()%999;
        }
        comparison[0][size] = selectionSort(randomnum, datasize);
        comparison[1][size] = insertionSort(randomnum, datasize);
        comparison[2][size] = quickSort(randomnum, datasize);
        size++;
        delete[] randomnum;
    }
    outFile.open("output.txt");
    if(outFile.is_open()) { //열려있는동안
        outFile << "Sorting Algorithm\tData Size\tNumber of Comparisons\tExecution Time (in seconds)" << endl;
        outFile << "---------------------------------------------------------------------------------" << endl;
        outFile << "Selection Sort\t\t"<< 10 <<"\t" <<  comparison[0][0] <<"\t" << result[0][0] << endl;
        outFile << "Selection Sort\t\t"<< 100 <<"\t" <<  comparison[0][1] <<"\t" << result[0][1] << endl;
        outFile << "Selection Sort\t\t"<< 1000 <<"\t" <<  comparison[0][2] <<"\t" << result[0][2] << endl;
        outFile << "Selection Sort\t\t"<< 10000 <<"\t" <<  comparison[0][3] <<"\t" << result[0][3] << endl;
        outFile << "Selection Sort\t\t"<< 100000 <<"\t" <<  comparison[0][4] <<"\t" << result[0][4] << endl;
        outFile << "---------------------------------------------------------------------------------" << endl;
        outFile << "Insertion Sort\t"<< 10 <<"\t" <<  comparison[1][0] <<"\t" << result[1][0] << endl;
        outFile << "Insertion Sort\t"<< 100 <<"\t" <<  comparison[1][1] <<"\t" << result[1][1] << endl;
        outFile << "Insertion Sort\t"<< 1000 <<"\t" <<  comparison[1][2] <<"\t" << result[1][2] << endl;
        outFile << "Insertion Sort\t"<< 10000 <<"\t" <<  comparison[1][3] <<"\t" << result[1][3] << endl;
        outFile << "Insertion Sort\t"<< 100000 <<"\t" <<  comparison[1][4] <<"\t" << result[1][4] << endl;
        outFile << "---------------------------------------------------------------------------------" << endl;
        outFile << "Quick Sort\t"<< 10 <<"\t" <<  comparison[2][0] <<"\t" << result[2][0] << endl;
        outFile << "Quick Sort\t"<< 100 <<"\t" <<  comparison[2][1] <<"\t" << result[2][1] << endl;
        outFile << "Quick Sort\t"<< 1000 <<"\t" <<  comparison[2][2] <<"\t" << result[2][2] << endl;
        outFile << "Quick Sort\t"<< 10000 <<"\t" <<  comparison[2][3] <<"\t" << result[2][3] << endl;
        outFile << "Quick Sort\t"<< 100000 <<"\t" <<  comparison[2][4] <<"\t" << result[2][4] << endl;
    }
    outFile.close(); //출력파일닫기
    return 0;
}