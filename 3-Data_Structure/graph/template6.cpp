#include <iostream>

using namespace std;

template <typename T>
class Point{
    private:
        T x;
        T y;

    public:
        Point (T x, T y){
            this->x = x
            this->y = y;
        }
        void Show(){
            cout << "x: "<<x<<"y: "<<y<<endl;
        }
};

int main(){
    Point<int> p1(2,3);
    p1.Show();

    Point<double> p2(2.3, 8.4);
    p2.Show();
}