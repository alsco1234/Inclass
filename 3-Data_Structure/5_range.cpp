#include <iostream>
using namespace std;

int main(){
    int arr[10] = {0,1,2,3,4,5};
    for(int item: arr[10]){
        cout << item << "\t";
    }
    /*와 같은의미
    for(int i=0; i<10; i++){
        int item = crr[i];
        printf("%d\t", item);
    }*/
    for(auto item: arr){
        cout << item << "\t";
    }
    return 0;
}