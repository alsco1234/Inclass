//primpt user to enter integer, n.
//create array of integer of size n.
//prompt user to enter n integers.
//Save numbers in array and display them.

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "enter integer" << endl; //출력
    cin >> n; //입력받기
    int ar[n];
    int *par = &ar[0];
    for(int i=0; i<n; i++){
        *(par+i) = 1+i;
    }
    for(int i=0; i<n; i++){
        cout << ar[i] << endl;
    }  
}
