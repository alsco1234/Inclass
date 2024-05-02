#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;

void InsertionSort(int num[]);
void QuickSort(int num[], int left, int right);
void HeapSort(int num[]);
void swap(int* a, int* b);
void Build_Max_Heap(int num[]);
void Max_Heapify(int num[], int i, int length);

int count = 0; // count num of statements

int main(){
    // put nums in array
    string filename;
    int num[1000];
    int i(0);

    std::cout << "input file name : " << std::endl;
    std::cin >> filename;
    ifstream input_file(filename);

    if(!input_file.is_open()) {
        std::cout << "file open error" << std::endl;
        return 1;
    }

    while(input_file >> num[i++]){};

    input_file.close();

    //sort
    int sorttype;
    std::cout << "sorttype [0]insertion [1]quick [2]heap : " << std::endl;
    std::cin >> sorttype;

    switch (sorttype){
        case 0 : InsertionSort(num);
            break;
        case 1 : QuickSort(num, 0, 1000-1);
            break;
        case 2 : HeapSort(num);
            break;
        default :
            std::cout << "type error" << std::endl;
            break;
    }

    //print result
    for(int j=0; j<1000; j++)
        std::cout << num[j] << " ";
    std::cout << std::endl;
    std::cout << "count of statement is " << count << std::endl;
	return 0;
}

void InsertionSort(int num[]){
    int i, j;
    int next;
    for(i=1; i<1000; i++){
        next = num[i];
        for(j=i-1; j>=0 && next < num[j]; j--){
            num[j+1] = num[j];
            count++;
        }
        num[j+1] = next;
        count++;
    }
}

void QuickSort(int num[], int left, int right){
    int pivot, i, j;
    if(left < right) {
        i = left;
        j = right+1;
        pivot = num[left];
        do{
            do i++; while(i <= right && num[i] < pivot);
            do j--; while(j > left && num[j] > pivot);
            if(i<j)
                swap(&num[i], &num[j]);
        } while (i<j);
        swap(&num[left], &num[j]);
        QuickSort(num, left, j-1);
        QuickSort(num, j+1, right);
    }
}

void HeapSort(int num[]){
    Build_Max_Heap(num);
    int length = 1000;

    for (int i=1000-1; i>=0; i--){
        swap(&num[0], &num[i]);
        length--;
        Max_Heapify(num, 0, length);
    }
}

void swap(int* a, int* b){
    count++;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Build_Max_Heap(int num[]){
    int i;
    for(int i=499; i>=0; i--)
        Max_Heapify(num, i, 1000);
}

void Max_Heapify(int num[], int i, int length){
    int *tmp;
    int left = 2*i +1;
    int right = 2*i +2;
    int largest;

    if((left<length) && (num[left] > num[i]))
        largest = left;
    else   
        largest = i;
    
    if((right < length) && (num[right] > num[largest]))
        largest = right;

    if(largest != i){
        swap(&num[i], &num[largest]);
        Max_Heapify(num, largest, length);
    }
}