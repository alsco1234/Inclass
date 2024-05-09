#include <iostream>
using namespace std;

// int &num1 =n 하면 n이라는 같은장소의 이름을 n뿐만아니라 num이라고도 붙인다는 의미
// int &num 하면 실체가 없으므로 안됨
// int &num = 10 하면 실체가 없는거에 값주니까 안됨
// 포인터는 공간 잡고 공간이 공간 가르킴. 얘는 같은 공간을 가르킴.
// 포인터 대신 쓸 수 있지만 완전대체 x

void num_swap(int &, int&);

int main(){
    const int size(3);
    int arr[size] = {0,1,2};
    cout << arr[0] << arr[1] << arr[2] << endl;
    num_swap(arr[0], arr[1]);

    cout << arr[0] << arr[1] << arr[2] << endl;

    return 0;
}

void num_swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << num1 << num2 << endl;
}