#include <iostream>
#include <string> //getline으로 띄어쓰기까지 받기 위해
#include <algorithm> //마지막에 rev reverse
#define q_size 20

using namespace std;

typedef char Element; //숫자 하나만 들어가는 요소

class Queue{ //declares a class data type
    private :  //private data members
        int front, rear;
        int max_size;
        Element * queue;
    public :  //public member functions
        Queue(int max_queue_size){ //생성
            front = rear = 0;
            max_size = max_queue_size;
            queue = new Element[q_size];
        }
        ~Queue(){ //삭제 
            delete queue;
        }
        void Enqueue (Element item){ //넣기
            if((rear+1)%q_size == front)
                cout << "The queue is full" << endl; //꽉차면 꽉찼다
            else{
                rear = (rear+1)%q_size; //원처럼 돌게 하기 위해
                queue[rear] = item; //넣기
            }
        }
        Element Dequeue(){ //빼기
            if(front==rear){
                cout << "The queue is empty" << endl; //비면 비었다
                return (Element)0;
            }
            else{
                front = (front+1) % q_size; //원처럼 돌게 하기 위해
                return queue[front]; //빼기
            }
        }
};

int main(){
    Queue* q1 = new Queue(q_size);
    string str;
    int count=0;
    cout << "Enter Expression: ";
    getline(cin, str); //공백포함받기
    char *ch;
    ch = (char*)str.c_str();
    for(int i=0; i<str.length(); i++){
        if(ch[i]>='0'&&ch[i]<='9') {
            q1->Enqueue(ch[i]);//숫자만 큐에 넣기
            count++; //몇개들어감?
        }
    }
    cout << "You entered ";
    string rev; //거꾸로하기위한 문자열
    for(int i=0; i<count; i++){
        rev = rev + ":" + q1->Dequeue(); //뺀걸 문자열에 저장
    }
    reverse(rev.begin(),rev.end()); //거꾸로해서
    cout << rev; //출력
}