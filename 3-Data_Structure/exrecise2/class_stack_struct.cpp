#include <iostream>
#include <stdio.h>
#define s_size 3

using namespace std;

typedef struct {
	string name;
	int age;
} Element;

class  Stack  // Declares a class data type
{
  private:           // Private data members
    int top;
    int max_size;
    Element * stack;

  public:               // Public member functions
    Stack(int max_stack_size);
    ~Stack();
    void Push(Element item);
    Element Pop();
    bool IsFullS() const;
    bool IsEmptyS() const;
    void Show();
};

Stack::Stack(int max_stack_size)
{
    top = -1;
    max_size = max_stack_size;
    stack = new Element[max_size]; 
}

Stack::~Stack()
{
    delete(stack);
}

void Stack::Push(Element item)
{
    if(IsFullS())
        cout << "Stack is full"<< endl;
    else
        stack[++top] = item;
}

Element Stack::Pop()
{
    if(IsEmptyS()){
        cout << "Stack is empty"<< endl;
        //return {"",0};
        Element e={"",0};
        return e;
    }
    else
        return stack[top--];
}

bool Stack::IsFullS() const
{ 
	return (top == max_size-1); 
}


bool Stack::IsEmptyS() const
{ 
	return (top == -1); 
}

void Stack::Show(){
	for (int i=top; i>=0; i--)
		//printf("stack[%d]: %s, %d\n", i, stack[i].name, stack[i].age);
		cout << "stack[i]: " << stack[i].name << ": " << stack[i].age << endl;
}

int main()
{
    Stack* s1 = new Stack(s_size);
    Element e1={"Peace", 10}, e2={"Grace", 20};
    Element t1, t2, t3;

    s1->Show();
    s1->Push(e1);
    s1->Push(e2);
    s1->Push({"Love", 30});
    s1->Show();
        
    t1 = s1->Pop();
    t2 = s1->Pop();
    t3 = s1->Pop();
    cout << "Pop: " << t1.name << endl;
    cout << "Pop: " << t1.age << endl;
    cout << "Pop: " << t2.name << endl;
}