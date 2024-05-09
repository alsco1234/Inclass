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
        friend Point operator+(const int&num, const Point& p);
        //friend : 밖에서도 private 변수 acsess할수있게
};

Point operator+(const int& num, const Point& p){
    return Point(num+p.x, num+p.y);
}

int main() {
    Point p1(1,2), p2(10,20), p3(100,200);

    Point temp1 = p1 + p2; //이렇게는 안됨
    temp1.print();
    
    temp1 = 5 + p3;
    temp1.print();
}

/*
(11,22)
(105,205)
*/