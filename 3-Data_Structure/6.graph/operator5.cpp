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
};

ostream& operator<<(ostream& out, Point p){
    p.print();
    return out;
}

int main() {
    Point p1(1,2), p2(10,20), p3(100,200);

    Point temp1 = p1 + p2; //이렇게는 안됨
    temp1.print();
    
    temp1 = p1 + p3;
    cout << "[1] " << temp1 << "[2]" << endl;
}

/*
(11,22)
[1] (101,202)
[2]
*/