#include <iostream>
using namespace std;

int main(){
    int sum(0);

    //for (int i=0, sum=0; i<=10; i++)
    for (int i=0; i<10; i++)
        sum = sum +i;
        
    cout << sum << endl;

    return 0;
}