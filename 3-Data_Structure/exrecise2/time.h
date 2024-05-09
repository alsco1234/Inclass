#include <iostream>
using namespace std;

class Time{
    private : 
        int hours;
        int mins;
        int secs;
    public : 
        Time () : hours(0), mins(0), secs(0) {}
        Time (int initHrs, int initMins, int initSecs){
            int hours = initHrs;
            int mins = initMins;
            int secs = initSecs
        }
        void show(){
            cout << "hours:" << this->hours << endl;
            cout << "mins:" << this->mins << endl;
            cout << "secs:" << this->secs << endl;
        }
        void Increment(){
            hours++;
        }
};