#include <iostream>
using namespace std;

class Point{
    private : //2개의 member variable
        int x;
        int y;
    public : //5개의 member function
        Point(): x(0), y(0){} //default conatructor : initialize point to (0,0)
        void MoveXY(int x_position,int y_position); //move point to (x,y)
        void showPoint(); //show current position
        int getX(); //show current x-axis position
        int getY(); //show current y-axis position
};

void Point::MoveXY(int x_position,int y_position){ //move point to (x,y)
    this->x = x_position; 
    this->y = y_position; 
}

void Point::showPoint(){ //show current position
    cout << "the position of point is (" << this->x << ", " << this->y << ")" << endl;
}

int Point::getX(){ //show current x-axis position
    return this->x;
}

int Point::getY(){ //show current y-axis position
    return this->y;
}

int main(){
    Point p; //p라고 이름붙임
    int menu(0);
    int x_axis;
    int y_axis;
    while(1){ //반복해서 test
        cout << "\nshow(1)\nmove(2)\nexit(0) : ";
        cin >> menu;
        if(menu==0) return 0; //종료
        else if(menu==1){ //current position show하는 member function
            cout << "the current position of x is " << p.getX() << endl;
            cout << "the current position of y is " << p.getY() << endl;
            p.showPoint();
        }
        else { 
            cout << "x-axis to move? ";
            cin >> x_axis;
            cout << "y-axis to move? ";
            cin >> y_axis;
            p.MoveXY(x_axis, y_axis); //move하는 member function
        }
    }
}