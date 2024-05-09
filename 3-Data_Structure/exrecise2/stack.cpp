#include <iostream>
#include <sstream>
using namespace std;

int main(void){
    char c;
    string str;
    stringstream strm;
    getline(cin, str);
    strm.str(str);
    while (strm >> c){
        cout << c << endl;
    }
    return 0;
}