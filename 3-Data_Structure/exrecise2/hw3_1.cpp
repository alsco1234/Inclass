#include <iostream>
#include <algorithm> //Change에서 reverse
#define s_size 20 //stack size is 20

using namespace std;

typedef struct {
    int deci;
	string hexa;
} Element; //두 개의 요소 구조체로

string Change(int num){ //10진수 받아서 16진수로 리턴
    string str;
    while(1){
        int mod = num%16; //16나눠서
        if(mod<10) str += (int)'0' + mod; //10보다작으면 ASCII이용해서 string으로 변환
        else str+= (int)'A' + (mod - 10); //string으로 10보다크면 알파벳으로 변환
        num = num/16; //나눠주고
        if(num==0)break; //0되면 멈춤
    }
    reverse(str.begin(),str.end()); //나눈거 거꾸로 올라갔으니 다시 거꾸로
    return str;
}

class  Stack {// Declares a class data type
  private:           // Private data members
    int top;
    int max_size;
    Element * stack;

  public:               // Public member functions
    Stack(int max_stack_size);
    ~Stack();
    void Push(int item); //넣기
    Element Pop(); //빼기
    void Show();
};

Stack::Stack(int max_stack_size){ //생성
    top = -1;
    max_size = max_stack_size;
    stack = new Element[max_size]; 
}

Stack::~Stack(){ //삭제
    delete(stack);
}

void Stack::Push(int32_t item){ //pop. deci 아이템넣기
    if(top == max_size-1)
        cout << "Stack is full"<< endl; //꽉차면 찼다고
    else
        stack[++top].deci = item; //아니면 deci 넣고
        stack[top].hexa = Change(item); //hexa도 넣고
}

Element Stack::Pop(){ //pop. hexa 아이템 빼기
    if(top == -1){
        cout << "Stack is empty"<< endl; //비면 비다고
        Element e={0,"NULL"};
        return e;
    }
    else
        return stack[top--]; //아니면 빼기
}

int main(){
    Stack* s1 = new Stack(s_size); //20크기로 만듬
    int num;
    for(int i=0; i<s_size; i++){
        cout << "Enter a number: ";
        cin >> num; //10진수 받아서
        s1->Push(num); //넣고
        Element t1; //받을거로 받음
        t1 = s1->Pop(); //받아서
        cout << "You entered " << t1.deci << " and its corresponding hexadecimal number is " << t1.hexa << "." <<endl; //출력
    }
}