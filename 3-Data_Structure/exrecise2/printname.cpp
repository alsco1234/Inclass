#include <iostream>
#include <string>

using namespace std;

const string FIRST = "Herman";
const string LAST = "Smith";
const char MIDDLE = 'G';

int main(){
    string firstLast;
    string lastFirst;

    firstLast = FIRST + " " + LAST;
    cout << "Name in first-last format is" << endl
        << firstLast << endl;
    
    lastFirst = LAST + ", " + FIRST + ' ';
    cout << "Name in first-initial format is" << endl
        << lastFirst << MIDDLE << '.' <<  endl;

        return 0;
}