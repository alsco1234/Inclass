#include <iostream>

using namespace std;

template <typename T>
void print_array (T arr[], int n){
    cout << "==1" << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << endl;
}

template <>
void print_array (char arr[], int n){
    cout << "==2" << endl;
    cout << arr << endl;
}

void print_array (char arr[], int n){
    cout << "==3" << endl;
    cout << arr << endl;
}

int main(){
    const int size1=3, size2=5;
    int arr1[size1] = {1,2,3};
    double arr2[size2] = {1.1, 2.2, 3.3, 4.4, 5.5};

    print_array(arr1, size1);
    print_array(arr2, size2);

    char arr3[] = "Living without you";
    print_array(arr3, 10);
}