#include <iostream>
#include <stdio.h>
#define s_size 20

using namespace std;

typedef struct {
	int decimal;
    string hexa;
} Element;

typedef struct {
	Element *stack;
    int max_size;
    int top;
} Stack;

Stack* CreateS(int max_stack_size){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->stack = (Element*)malloc(max_stack_size*sizeof(Element));
    s->max_size = max_stack_size;
    s->top = -1;
    return s;
}

void push(Stack *s, Element item){
    if(s->top==s->max_size-1)
        cout << "Full stack." << endl;
    else
        s->stack[++s->top] = item;
}

Element pop(Stack *s){
    if(s->top<0)
        cout << "Empty stack." << endl;
    else
        return s->stack[s->top--];
}

int main(){
    Stack* stack = new Stack(5);

  


    Element stack[s_size];
    int top = -1;
    int num;
    int i;
    for(i=0; i<s_size; i++){
        cout << "Enter a number: ";
        cin >> num;
        push(stack[i], num);
        stack[i].hexa = "14A";
        cout << "You entered " << stack[i].decimal <<" and its corresponding hexadecimal number is " << stack[i].hexa << endl ;
    }
}