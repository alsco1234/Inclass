#include <iostream>
#include <string> //getline���� ������� �ޱ� ����
#include <algorithm> //�������� rev reverse
#define q_size 20

using namespace std;

typedef char Element; //���� �ϳ��� ���� ���

class Queue{ //declares a class data type
    private :  //private data members
        int front, rear;
        int max_size;
        Element * queue;
    public :  //public member functions
        Queue(int max_queue_size){ //����
            front = rear = 0;
            max_size = max_queue_size;
            queue = new Element[q_size];
        }
        ~Queue(){ //���� 
            delete queue;
        }
        void Enqueue (Element item){ //�ֱ�
            if((rear+1)%q_size == front)
                cout << "The queue is full" << endl; //������ ��á��
            else{
                rear = (rear+1)%q_size; //��ó�� ���� �ϱ� ����
                queue[rear] = item; //�ֱ�
            }
        }
        Element Dequeue(){ //����
            if(front==rear){
                cout << "The queue is empty" << endl; //��� �����
                return (Element)0;
            }
            else{
                front = (front+1) % q_size; //��ó�� ���� �ϱ� ����
                return queue[front]; //����
            }
        }
};

int main(){
    Queue* q1 = new Queue(q_size);
    string str;
    int count=0;
    cout << "Enter Expression: ";
    getline(cin, str); //�������Թޱ�
    char *ch;
    ch = (char*)str.c_str();
    for(int i=0; i<str.length(); i++){
        if(ch[i]>='0'&&ch[i]<='9') {
            q1->Enqueue(ch[i]);//���ڸ� ť�� �ֱ�
            count++; //���?
        }
    }
    cout << "You entered ";
    string rev; //�Ųٷ��ϱ����� ���ڿ�
    for(int i=0; i<count; i++){
        rev = rev + ":" + q1->Dequeue(); //���� ���ڿ��� ����
    }
    reverse(rev.begin(),rev.end()); //�Ųٷ��ؼ�
    cout << rev; //���
}