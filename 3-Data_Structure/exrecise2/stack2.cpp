#include <iostream>
#include <sstream>
using namespace std;

int main(void){
    string str, name, city;
    int years;
    stringstream strm;
    getline(cin, str);
    strm.str(str);
    strm >> name;
    cout << name << endl;
    strm >> city;
    cout << city << endl;
    strm >> years;
    cout << years << endl;
    return 0;
}