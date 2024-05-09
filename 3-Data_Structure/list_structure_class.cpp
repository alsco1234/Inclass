#include <iostream>

using namespace std;

typedef struct t_list_node {
    string data;
    struct t_list_node *link;
} list_node;

class Slist{
    private : 
        list_node *head;
    public :
        Slist();
        ~Slist();
        void Insert(string data);
        void Delete(string data);
        void Print();
        bool Retrieve(string data);
        list_node* Retrieve(int index);
};

Slist::Slist(){ //constructer
    head = NULL;
}

Slist::~Slist(){ //destructer
    list_node *curr=head, *next;
    while(curr){
        next = curr->link;
        delete curr;
        curr = next;
    }
}

void Slist::Insert(string data){ //insert
    list_node *new_node = new list_node;
    new_node -> data = data;
    new_node -> link = head;
    head = new_node;
}

void Slist::Delete(string data){ //delete
    list_node* prev = NULL;
    list_node* curr = head;

    while(curr!=NULL && curr->data!=data){
        prev = curr;
        curr = curr->link;
    }
    if (curr != NULL){
        if(curr == head) head = curr -> link;
        else {
            prev->link = curr -> link; // 링크 옮김
            cout << "delete " <<curr->data << endl;
            delete curr;
        }
    }
    else cout << "target is not found" << endl;
}

void Slist::Print(){ //print
    list_node *cur = NULL;
    for(cur = head; cur != NULL; cur = cur->link)
        std :: cout << cur->data << "\t";
}

bool Slist::Retrieve(string data){ //있으면 true, 없으면 false 리턴
    list_node *cur = NULL;
    int count = 1;
    for(cur = head; cur!=NULL; cur = cur->link){
        if(cur->data == data) break;
        else count++;
    }
    if (cur!=NULL){
        cout << "\nfind data at "<< count << " index.\n" << endl;
        return true;
    }
    else {
        cout << "cannot find num\n" << endl;
        return false;
    }
}

list_node* Slist::Retrieve(int index){
    list_node *cur = NULL;
    int count = 1;
    for(cur = head; cur!=NULL; cur = cur->link){
        if(count==index) break;
        else count++;
    }
    if (cur!=NULL) cout << "\nfind num at "<< count << " index." << endl;
    else cout << "cannot find num\n" << endl;
    return cur;
}

int main(void){
    Slist* list1 = new Slist();
    list_node* node;

    list1->Print();
    list1->Insert("mat");
    list1->Insert("cat");
    list1->Insert("bat");
    list1->Print();
    cout << endl;

    cout << "list1->Retrieve(\"mat\")" << endl;
    if(list1->Retrieve("mat")) cout << "find" << endl;


    cout << "list1->Retrieve(2)" << endl;
    node = list1->Retrieve(2);
    if(node!=NULL) cout << node -> data << endl;
    else cout << "Out of range" << endl;

    list1->Delete("cat");
    list1->Print();
    cout << endl;

    delete list1;
    return 0;
}
