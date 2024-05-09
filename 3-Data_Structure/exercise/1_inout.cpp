#include <iostream>
using namespace std; //쓰면 std :: cout << "Hello" 안해도됨

int main(){
    char name[20];
    int age;
    cout << "Enter your name, age : ?" << endl; //cout가 출력, endl은 \n
    cin >> name >> age; //cin이 입력
    cout << "Your name is " << name << endl;
    cout << "Your age is " << age << endl;
    return 0;
}

// 컴파일 : g++ inout.cpp
// 만약두개면 -o a.exe
// 실행 : ./a.exe