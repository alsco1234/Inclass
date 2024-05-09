#include <iostream>
using namespace std;

int main(){
    int num=100;
    int *prt=&num;
    int **dptr=&prt;
    const int size(7);
    int arr[size] = {0, 1, 2, 3, 4, 5, 6};

    cout <<arr[0]<<arr[1]<<arr[2]<<arr[3]<<endl;

    int &ref=num;
    int *(pref)=prt; //포인터
    int **(&dpref)=dptr; //더블포인터
    const int ref_size=size;
    int (&parr)[size] = arr; //array표현



    return 0;
}