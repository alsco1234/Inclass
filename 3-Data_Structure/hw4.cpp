#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
references
1) 강의 slide 2. Intro to C++
2) 강의 slide 5. Intro to C++ - part2
3) 강의 slide 4. Lists
4) github https://github.com/22000217/OSSL_teamProject.git
5) blog https://blockdmask.tistory.com/322
*/ 

typedef struct t_list_node { //하나의 node에 들어갈 데이터
    int id_number;
    string name;
    int age;
    float score;
    struct t_list_node *link; //link
} list_node;

class Plist {
    private:
        list_node *head;//다음 node를 가리키는 포인터
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
    list_node *new_node = new list_node; //새 노드 생성
    new_node -> id_number = newid_number;
    new_node -> name = newname;
    new_node -> age = newage;
    new_node -> score = newscore;
    head = new_node; //맨앞에걸로 지정
}
void Plist::Create(int newid_number, string newname, int newage, float newscore){ //Create
    list_node *new_node = new list_node; //새 노드 생성
    list_node* ptr = NULL;
    list_node* curr = head; //일단 맨앞에서부터 찾기
    list_node* prev = NULL;
    new_node -> id_number = newid_number;
    new_node -> name = newname;
    new_node -> age = newage;
    new_node -> score = newscore; //노드에 데이터 먼저 넣은다음
    //자리찾기 (1. 맨앞  / 2. 중간 / 3.맨뒤)
    if(newid_number < head->id_number){ //1.맨앞. 젤작을때
        new_node -> link = head; //데이터 넣음
        head = new_node; //맨앞에걸로 지정
        return;
    }
    while(curr!=NULL){ //찾기
        if(curr->id_number>newid_number) {
            ptr = prev;
            break;
        }
        prev = curr;
        curr = curr->link;
    }
    if(ptr!=NULL){ //2. 중간에 끼워넣기
        new_node->link = ptr->link; //이 노드의 링크가 이전 링크가 가르키던거 가르키게
        ptr->link = new_node; //이전 노드의 링크가 이거 가르키게
    }
    else { //3. 얘가 젤 큼. 맨뒤에 넣어야됨
        curr = head;
        while(curr->link!=NULL){
            curr = curr->link; //끝까지 돌게한후
        }
        ptr = curr;
        ptr->link = new_node; //이전 노드의 링크가 이거 가르키게
    }
}
void Plist::Print(){ //Read
    list_node *cur = NULL; //cur이라는 노드 만듦
    std::cout << "id_number\tname\tage\tscore" << endl;
    for(cur = head; cur != NULL; cur = cur->link){ //cur 뒤로 하나씩 땡기며
        std::cout << cur->id_number << "\t";
        std::cout << cur->name << "\t";
        std::cout << cur->age << "\t";
        std::cout << cur->score << endl; //출력
    }
}
void Plist::Delete(int newid_number){ //delete
    list_node* prev = NULL; //prev라는 노드 만듦
    list_node* curr = head; //curr은 맨앞 가르키게
    while(curr!=NULL && curr->id_number!=newid_number){ //찾는게 아니면
        prev = curr;
        curr = curr->link; //뒤로땡김
    }
    if (curr != NULL){ //찾았다면
        if(curr == head) head = curr -> link;
        else {
            prev->link = curr -> link; // 링크 옮김
            std::cout << curr->name << "\'s record is deleted." << endl;
            delete curr;
        }
    }
    else std::cout << "No record shown" << endl; //못찾았다면
}
void Plist::Retrieve(int newid_number){ 
    list_node *cur = NULL;
    int count = 1;
    for(cur = head; cur!=NULL; cur = cur->link){ //찾기
        if(cur->id_number == newid_number) break;
        else count++;
    }
    if (cur!=NULL){ //찾았다면
        std::cout << cur->name <<"'s age is " << cur->age << " and score is " << cur->score << endl;
    }
    else { //못찾았다면
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
    Plist* list1 = new Plist(); //list 하나 만들기
    list_node* node;
    ifstream inFile;
    int id_number;
    string name;
    int age;
    float score;
    inFile.open(filename); //파일열기
    if(inFile.is_open()) {
        for(int i=0; i<4; i++) inFile >> fir;
        inFile >> id_number;
        inFile >> name;
        inFile >> age;
        inFile >> score;
        list1->Fir_Create(id_number, name, age, score); //처음은 맨앞에 넣
        while(!inFile.eof()){
            inFile >> id_number;
            inFile >> name;
            inFile >> age;
            inFile >> score;
            list1->Create(id_number, name, age, score); //나머지는 순서따라넣
        }
    }
    inFile.close(); //파일닫기
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
                if(id_number<0 || id_number>=100000) //잘못된 입력
                    cout << "the id_number is 5 digits, positive integer." << endl;
            }while(id_number<0 || id_number>=100000); //잘못된 입력시 반복해서 물음
            cout << "==> Type age of student : " ;
            cin >> age;
            do{
                cout << "==> Type score : " ;
                cin >> score;
                if(score<0 || score>100) //잘못된 입력
                    cout << "The input score is ranged from 0 to 100." << endl;
            }while(score<0 || score>100); //잘못된 입력시 반복해서 물음
            list1->Create(id_number, name, age, score);
            cout << name << "\'s record is added" << endl;
        }
        else if(menu=='D'){
            cout << "==> Type student id : " ; //id묻고 찾아서 지움
            cin >> id_number;
            if(id_number<0 || id_number>=100000) cout << "Illegal id number" << endl;
            else list1->Delete(id_number);
        }
        else if(menu=='R'){
            cout << "==> Type student id : " ; //id묻고 찾아서 출력함
            cin >> id_number;
            if(id_number<0 || id_number>=100000) cout << "Illegal id number" << endl;
            else list1->Retrieve(id_number);
        }
        else if(menu=='P'){
            list1->Print();
        }
    }
    delete list1; //만든 리스트 지움
    return 0; 
}
