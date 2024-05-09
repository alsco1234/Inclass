#include <template>
#include <iostream>

template <typename T>
T Sum(T a, T b){
    return a+b;
}

template <typename T1, typename T2>
T2 Mult(T1 a, T2 b){
    return a*b;
}

template <typename T>
void exchange(T &a, T &b){
    T temp;
    temp = a;

}

template <class T>
void sort(T arr[], int size){
    //code to implement Quick Sort
}

template <>
void 