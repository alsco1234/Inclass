#include <iostream>

using namespace std;

class Clock{
    private:
        int hours; int minutes;

    public:
        Clock(): hours(0), minutes(0){}
        Clock(int h, int m){
            hours = h;
            minutes = m;
        }
        void Show();
        Clock operator+(Clock c1){
            return Clock(hours+c1.hours, minutes+c1.minutes);
        }
};

void Clock :: Show(){
    cout << "hour: " << this->hours << " minutes: " << this->minutes << endl;
}

template <typename T>
T Sum(T a, T b){
    return a+b;
}

int main(){
    Clock c1(1,2,3), c2(10,20,30), c3;
    c1.Show();
    c2.Show();
    c3.Show();
    c3 = Sum(c1,c2);

}