#include <iostream>
using namespace std;

struct Clock{
    int hours;
    int minutes;
    int seconds;
};

void Print(struct Clock *c){
    cout << c->hours << ": " << c->minutes << endl;
}

int main(){
    struct Clock c1={1, 2, 3};
    cout << c1.hours << ": " << c1.minutes << endl;
    Print(&c1);
}