#include <iostream>
#include <cstdlib> //표준 lib
#include <ctime> //시간 lib
using namespace std;

int main(){
    //srand(111); //랜덤seed줌
    srand((unsigned)time(NULL)); //현재타임을 seed로
    int num = rand();
    cout << "Random num is " << num << endl;
    return 0;
}