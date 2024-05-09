#include <iostream>

using namespace std;

class Point {
    private:
        int x,y;
    public:
        Point(int x, int y){
            this->x=x;
            this->y=y; 
        };
        void print() const{
            cout << "(" << x << "," << y << ")" << endl;
        };
        Point operator + (Point rhs) {
                return Point(x + rhs.x, y + rhs.y); 
        };
        Point operator+(int num){ //이렇게 하기위해 필요
            return Point(x+num, y+num);
        };
};

int main() {
    Point p1(1,2), p2(10,20), p3(100,200);

    Point temp1 = p1 + 3; //이렇게는 안됨
    Point temp2 = p1.operator+(p3);
    p1.print();
    p2.print();
    p3.print();
    temp1.print();
    temp2.print();
}

/*
(1,2)
(10,20)
(100,200)
(4,5)
(101,202)
*/