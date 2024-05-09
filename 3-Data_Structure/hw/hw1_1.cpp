#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    //prompts user to enter positive integer, say n
    int n(0);
    do {
    cout << "enter positive integer, n : " << endl;
    cin >> n ;
    } while(n<=0);

    //1. dynamically allocate n integers
    int *pn;
    pn = new int;
    *pn = n;

    //2. generate random number with seed as current time, resize range of random numbers between 1 and 10
    srand((unsigned)time (NULL));
    int *arr;
    arr = new int[*pn];
    int count[10]={0};
    for(int i=0; i < *pn; i++){
        int num;
        num = rand() % 10 + 1;
        //3. store them in array
        arr[i] = num;
        count[num-1]++;
        //cout << arr[i] << endl; //test
    }

    //4. write out a tabulation showing the number of times each elements appears.
    for(int i=0; i<10; i++){
        if(count[i]!=0) cout << i+1 << ": "<< count[i] <<" times" << endl;
    }

    delete pn;
    return 0;
}