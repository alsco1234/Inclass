#include <iostream>
#include <fstream> //파일입출력
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("hello.txt");
    string str;
    if(inFile.is_open()){
        while(!readFile.eof())    //파일 끝까지 읽었는지 확인
        {
        char arr[256];
        readFromFile.getline(arr, 256);    //한줄씩 읽어오기
        }
    }
    cout << str << endl;
    return 0;
}