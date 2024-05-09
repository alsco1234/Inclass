#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
references
1) ���� slide 2. Intro to C++
2) ���� slide 5. Intro to C++ - part2
3) ���� slide 4. Lists
4) github https://github.com/22000217/OSSL_teamProject.git
5) blog https://blockdmask.tistory.com/322
*/ 

typedef struct t_list_node { //�ϳ��� node�� �� ������
    int id_number;
    string name;
    int age;
    float score;
    struct t_list_node *link; //link
} list_node;

class Plist {
    private:
        list_node *head;//���� node�� ����Ű�� ������
    public:
        Plist(); //constructor
        ~Plist(); //destructor
        void Fir_Create(int newid_number, string newname, int newage, float newscore); //C
        void Create(int newid_number, string newname, int newage, float newscore); //C
        void Print(); //R
        void Delete(int id_number); //D
        void Retrieve(int newid_number); //R
};

Plist::Plist(){ //constructer
    head = NULL;
}
Plist::~Plist(){ //destructer
    list_node *curr=head, *next;
    while(curr){
        next = curr->link;
        delete curr;
        curr = next;
    }
}
void Plist::Fir_Create(int newid_number, string newname, int newage, float newscore){ //Create
    list_node *new_node = new list_node; //�� ��� ����
    new_node -> id_number = newid_number;
    new_node -> name = newname;
    new_node -> age = newage;
    new_node -> score = newscore;
    head = new_node; //�Ǿտ��ɷ� ����
}
void Plist::Create(int newid_number, string newname, int newage, float newscore){ //Create
    list_node *new_node = new list_node; //�� ��� ����
    list_node* ptr = NULL;
    list_node* curr = head; //�ϴ� �Ǿտ������� ã��
    list_node* prev = NULL;
    new_node -> id_number = newid_number;
    new_node -> name = newname;
    new_node -> age = newage;
    new_node -> score = newscore; //��忡 ������ ���� ��������
    //�ڸ�ã�� (1. �Ǿ�  / 2. �߰� / 3.�ǵ�)
    if(newid_number < head->id_number){ //1.�Ǿ�. ��������
        new_node -> link = head; //������ ����
        head = new_node; //�Ǿտ��ɷ� ����
        return;
    }
    while(curr!=NULL){ //ã��
        if(curr->id_number>newid_number) {
            ptr = prev;
            break;
        }
        prev = curr;
        curr = curr->link;
    }
    if(ptr!=NULL){ //2. �߰��� �����ֱ�
        new_node->link = ptr->link; //�� ����� ��ũ�� ���� ��ũ�� ����Ű���� ����Ű��
        ptr->link = new_node; //���� ����� ��ũ�� �̰� ����Ű��
    }
    else { //3. �갡 �� ŭ. �ǵڿ� �־�ߵ�
        curr = head;
        while(curr->link!=NULL){
            curr = curr->link; //������ ��������
        }
        ptr = curr;
        ptr->link = new_node; //���� ����� ��ũ�� �̰� ����Ű��
    }
}
void Plist::Print(){ //Read
    list_node *cur = NULL; //cur�̶�� ��� ����
    std::cout << "id_number\tname\tage\tscore" << endl;
    for(cur = head; cur != NULL; cur = cur->link){ //cur �ڷ� �ϳ��� �����
        std::cout << cur->id_number << "\t";
        std::cout << cur->name << "\t";
        std::cout << cur->age << "\t";
        std::cout << cur->score << endl; //���
    }
}
void Plist::Delete(int newid_number){ //delete
    list_node* prev = NULL; //prev��� ��� ����
    list_node* curr = head; //curr�� �Ǿ� ����Ű��
    while(curr!=NULL && curr->id_number!=newid_number){ //ã�°� �ƴϸ�
        prev = curr;
        curr = curr->link; //�ڷζ���
    }
    if (curr != NULL){ //ã�Ҵٸ�
        if(curr == head) head = curr -> link;
        else {
            prev->link = curr -> link; // ��ũ �ű�
            std::cout << curr->name << "\'s record is deleted." << endl;
            delete curr;
        }
    }
    else std::cout << "No record shown" << endl; //��ã�Ҵٸ�
}
void Plist::Retrieve(int newid_number){ 
    list_node *cur = NULL;
    int count = 1;
    for(cur = head; cur!=NULL; cur = cur->link){ //ã��
        if(cur->id_number == newid_number) break;
        else count++;
    }
    if (cur!=NULL){ //ã�Ҵٸ�
        std::cout << cur->name <<"'s age is " << cur->age << " and score is " << cur->score << endl;
    }
    else { //��ã�Ҵٸ�
        std::cout << "No record shown" << endl;
    }
}

int main(void){
    string filename;
    string fir;
    //1. When the program begins execution, it asks the user the name of the file to be read
    std::cout << "Enter input file name : " << endl;
    cin >> filename;
    //creates linked list out of it in ascending order. (with the key field as id number)
    Plist* list1 = new Plist(); //list �ϳ� �����
    list_node* node;
    ifstream inFile;
    int id_number;
    string name;
    int age;
    float score;
    inFile.open(filename); //���Ͽ���
    if(inFile.is_open()) {
        for(int i=0; i<4; i++) inFile >> fir;
        inFile >> id_number;
        inFile >> name;
        inFile >> age;
        inFile >> score;
        list1->Fir_Create(id_number, name, age, score); //ó���� �Ǿտ� ��
        while(!inFile.eof()){
            inFile >> id_number;
            inFile >> name;
            inFile >> age;
            inFile >> score;
            list1->Create(id_number, name, age, score); //�������� ���������
        }
    }
    inFile.close(); //���ϴݱ�
    char menu;
    while(1){
        cout << "\n*********** MENU ****************" << endl;
        cout << "A : Add new data" << endl;
        cout << "D : Delete Data" << endl;
        cout << "R : Retrieve data" << endl;
        cout << "P : Print list" << endl;
        cout << "Q : Quit" << endl;
        cout << "Choose menu : ";
        cin >> menu;

        if(menu=='Q')break;
        else if(menu=='A'){
            cout << "==> Type student name : " ;
            cin >> name;
            do{
                cout << "==> Type student id : " ;
                cin >> id_number;
                if(id_number<0 || id_number>=100000) //�߸��� �Է�
                    cout << "the id_number is 5 digits, positive integer." << endl;
            }while(id_number<0 || id_number>=100000); //�߸��� �Է½� �ݺ��ؼ� ����
            cout << "==> Type age of student : " ;
            cin >> age;
            do{
                cout << "==> Type score : " ;
                cin >> score;
                if(score<0 || score>100) //�߸��� �Է�
                    cout << "The input score is ranged from 0 to 100." << endl;
            }while(score<0 || score>100); //�߸��� �Է½� �ݺ��ؼ� ����
            list1->Create(id_number, name, age, score);
            cout << name << "\'s record is added" << endl;
        }
        else if(menu=='D'){
            cout << "==> Type student id : " ; //id���� ã�Ƽ� ����
            cin >> id_number;
            if(id_number<0 || id_number>=100000) cout << "Illegal id number" << endl;
            else list1->Delete(id_number);
        }
        else if(menu=='R'){
            cout << "==> Type student id : " ; //id���� ã�Ƽ� �����
            cin >> id_number;
            if(id_number<0 || id_number>=100000) cout << "Illegal id number" << endl;
            else list1->Retrieve(id_number);
        }
        else if(menu=='P'){
            list1->Print();
        }
    }
    delete list1; //���� ����Ʈ ����
    return 0; 
}
