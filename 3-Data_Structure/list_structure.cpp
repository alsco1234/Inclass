#include <iostream>

using namespace std;

typedef struct t_list_node {
    int data;
    struct t_list_node *link;
} list_node;

int main(void){
    list_node *head = NULL, *cur=NULL;

    //base Insert
    head = new list_node;
    head->data = 1;
    head->link = NULL;
    cur = head;

    for(int i=2; i<=10; i++){
        list_node *new_node = new list_node;
        new_node->data = i;
        new_node->link = NULL;
        cur -> link = new_node;
        cur = new_node;
    }

    //print
    cur = head;
    while (cur){
        cout << cur->data << "\t";
        cur = cur -> link;
    }
    cout << endl;

    //find
    /*int num;
    cout << "\nfind num? ";
    cin >> num;
    int count = 1;
    for(cur = head; cur!=NULL; cur = cur->link){
        if(cur->data == num) break;
        else count++;
    }
    if (cur!=NULL) cout << "find num at "<< count << " index.\n" << endl;
    else cout << "cannot find num\n" << endl;

    //delete specific
    list_node* prev = NULL;
    list_node* curr = head;
    int target;
    cout << "\ndelete target? ";
    cin >> target;

    while(curr!=NULL && curr->data!=target){
        prev = curr;
        curr = curr->link;
    }
    if (curr != NULL){
        if(curr == head) head = curr -> link;
        else {
            prev->link = curr -> link; // 링크 옮김
            cout << "delete " <<cur->data << endl;
            delete curr;
        }
    }
    else cout << "target is not found" << endl;*/

    //insert between ==> beginnig / between
    list_node *ptr = new list_node;
    cur = head;
    int whatindex;
    int whatnum;
    cout << "\n insert what ptr index?" << endl;
    cin >> whatindex;
    cout << "insert what num?" << endl;
    cin >> whatnum;

    if(whatindex==1){ //beginnig insertion
        list_node *new_node = new list_node;
        new_node->data = whatnum;
        new_node->link = head;
        head = new_node;
    }
    else { //between insertion
            for(int i=2; i<=10; i++){
            if(i==whatindex){
                list_node *new_node = cur->link;
                new_node->data = whatnum;
                new_node->link = ptr->link;
                cur -> link = new_node;
            }
        }
    }
    
    //print
    cur = head;
    int i=0;
    while (cur){
        if(i==10)break;
        cout << cur->data << "\t";
        cur = cur -> link;
        i++;
    }
    cout << endl;

    return 0;
}
