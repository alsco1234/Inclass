#include <iostream>
#define S_size  5;

using namespace std;
typedef int Element;

class Stack{
    private:
        int top;
        int max_size;
        Element * stack;

    public:
        Stack(int max_stack_size);
        ~Stack();
        void Push(Element item);
        Element Pop();
        Element Show();
        bool IsFullS();
        bool IsEmptyS();
};

Stack::Stack(int max_stack_size){
    top = -1;
    max_size = max_stack_size;
    stack = new Element[max_size];
    cout << "In Stack() " << endl;
}

Stack::~Stack(){
    delete(stack);
    cout << "In ~Stack() " << endl;
}

void Stack::Push(Element item) { //IsEmpty()
    if(IsEmptyS()) cout << "FuLL" << endl;
    else stack[++top] = item;
}

Element Stack::Pop(){
    if(IsEmptyS()) cout << "Empty" << endl;
    else return stack[top--];
}

Element Stack::Show(){
    for (int i=0; i<=top; i++)
        cout << "stack[" << i << "]: " << stack[i] << endl;
}

bool Stack::IsFullS(){
    return (top == max_size-1);
}

bool Stack::IsEmptyS(){
    return (top == -1);
}

int main(void){
    Stack* stack = new Stack(5);
    stack->Show();
    stack->Push(1);
    stack->Push(3);
    stack->Show();

    cout << "Pop: " << stack->Pop() << endl;
    stack->Show();
}