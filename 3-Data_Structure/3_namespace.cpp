#include <iostream>
//using namespace std;

namespace Space_A{
    int num =20;
} //Space A에서 통하는 num

namespace Space_B{
    int num =30;
} //Space B에서 통하는 num

namespace stds{
    int numm(5);
}

using namespace std;
//using namespace Space_A; //그냥 num을 Space_A의 num(20)으로 인식
//using namespace Space_B

int num(5);

int main(){
    int num =10; 
    cout << "main: " << num << endl; //기본num
    cout << "A: " << Space_A :: num << endl; //Space_A의 num을 쓰겠다
    cout << "B: " << Space_B :: num << endl; //Space_B의 num을 쓰겠다
    cout << "std: " <<:: num << endl; //
    return 0;
}