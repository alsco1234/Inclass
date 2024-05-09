#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
/*
(1) 강의 slide chapter 5.Trees (BST)
(2) 강의 slide chapter Introduction to C++ (file I/O)
(3) Blog https://danco.tistory.com/69 (string<>char[])
(4) GitHub https://github.com/JoSangYeon/Algorithm/blob/master/Tree/BST/Improved_BST.cpp
*/
/*
구현한 메뉴
S : (o)
I : (o)
D : (o)
P : (o)
Q : (write x, quit o)
*/
using namespace std;

typedef struct node {
     string name; //key
     string phone;
     struct node *left_child, *right_child;
} tree_node;

class BST{
    private : 
        tree_node *root;
    tree_node* deleteKey(tree_node* t, string name) //지정된 node삭제
	{
		tree_node* rt = t;
		tree_node* temp = rt;

		if (rt != NULL)
		{
			if (name < rt->name) { rt->left_child = deleteKey(rt->left_child, name); }
			else if (name > rt->name) { rt->right_child = deleteKey(rt->right_child, name); }
			//삭제할 Node의 차수가 0일 경우
			else if (rt->left_child == NULL && rt->right_child == NULL)
			{
				rt = NULL;
			}
			//삭제할 Node의 차수가 1일 경우
			else if (rt->left_child == NULL) //case 1: 왼쪽 node가 비어있을 경우
			{
				temp = rt; rt = rt->right_child; temp = NULL;
			}
			else if (rt->right_child == NULL)//case 2: 오른쪽 node가 비어있을 경우
			{
				temp = rt; rt = rt->left_child; temp = NULL;
			}
			//삭제할 Node의 차수가 2일 경우
			else
			{
				string flag = "middle";
				//case 1: 삭제할 노드의 왼쪽 subTree가 더 높을때
				if (this->getHeight(rt->left_child) > this->getHeight(rt->right_child))
				{
					temp = this->findMax(rt->left_child); flag = "left";
				}
				//case 2: 삭제할 노드의 오른쪽 subTree가 더 높을때
				else if (this->getHeight(rt->left_child) < this->getHeight(rt->right_child))
				{
					temp = this->findMin(rt->right_child); flag = "right";
				}
				//case 3: 양쪽의 subTree의 높이가 같을때
				else
				{
					// case 3-1: 왼쪽 subTree의 node 개수가 더 많을때
					if (this->getNumofNode(rt->left_child) >= this->getNumofNode(rt->right_child))
					{
						temp = this->findMax(rt->left_child); flag = "left";
					}
					//case 3-2: 오른쪽 subTree의 node 개수가 더 많을때
					else //(this.getNumofNode(p.left) < this.getNumofNode(p.right))
					{
						temp = this->findMin(rt->right_child); flag = "right";
					}
				}
				rt->name = temp->name; //teamp로 데이터 이동
                rt->phone = temp->phone;
				if (flag == "left") { rt->left_child = this->deleteKey(rt->left_child, rt->name); }
				else { rt->right_child = deleteKey(rt->right_child, rt->name); }
			}
		}
		else { return NULL; }
		return rt;
	}
    public : 
        void insert_node(string name, string phone); //노드추가
        tree_node* search(tree_node *tree, int key); //node가지고 검색
        tree_node* search(string name); //이름가지고 검색
        tree_node* modified_search(string name); //이름의 부모 반환

        tree_node* searchData(string targetname); //검색메뉴
        void inseartData(); //추가메뉴
        void deleteData(string name); //삭제메뉴
        void printData(); //출력메뉴
        void writeData(string filename); //쓰기메뉴

        int getHeight(tree_node* temp) //노드의 높이 반환
	{
		if (temp == NULL) { return -1; }

		int leftSubTreeHeight = getHeight(temp->left_child) + 1; //왼/오 나눠서 recursion
		int rightSubTreeHegiht = getHeight(temp->right_child) + 1;

		return max(leftSubTreeHeight, rightSubTreeHegiht); //max반환
	}
    int getNumofNode(tree_node* temp)
	{
		if (temp == NULL) { return -1; }

		int leftSubTreeHeight = getHeight(temp->left_child) + 1;
		int rightSubTreeHegiht = getHeight(temp->right_child) + 1;

		return leftSubTreeHeight + rightSubTreeHegiht + 1;
	}

	tree_node* findMin(tree_node* temp) //최소노드 반환
	{
		if (temp->left_child == NULL) { return temp; }
		else { return findMin(temp->left_child); }
	}

	tree_node* findMax(tree_node* temp) //최대노드 반환
	{
		if (temp->right_child == NULL) { return temp; }
		else { return findMax(temp->right_child); }
	}

};

int compare(string str1, string str2){ //같은지 비교
    char chstr1[80];
    char chstr2[80];
    strcpy(chstr1,str1.c_str());
    strcpy(chstr2,str2.c_str());
    for(int i=0; i<str1.length(); i++){
        if((int)chstr1[i]<(int)chstr2[i]) return -1;
        else if((int)chstr1[i]>(int)chstr2[i]) return 1;
    }
    return 0;
}
void inorder(tree_node *tree){ //inorder로 한번씩 다 방문해서 출력
	if (tree != NULL){
		inorder(tree->left_child);
		cout << tree->name << "   " << tree->phone << endl;
		inorder(tree->right_child);
	}
}

int main(void){
    BST *tree = new BST();
    char menu;
    string filename;
    cout << "input file name : ";
    cin >> filename;
    ifstream inFile;
    inFile.open(filename); //파일이름받아 열기
    string line;
    char chline[80];
    string ptrname;
    string ptrphone;
    if(inFile.is_open()) {
        getline(inFile,line);
        while(!inFile.eof()){
            ptrname="";
            ptrphone="";
            getline(inFile,line); //일단 line으로 받은 후
            strcpy(chline, line.c_str()); //char로 만들어서
            int i=0;
            for(; i<line.length(); i++){
                ptrname += chline[i]; //name이면 거기 넣고
                if(chline[i]=='\t')break;
            }
            for(; i<line.length(); i++){ //phone이면 거기 넣
                if(chline[i]!=' ' &&  chline[i]!='\t' && chline[i]!='\n') ptrphone += chline[i];
            }
            tree->insert_node(ptrname, ptrphone); //가공된 데이터 tree에 추가
        }
    }
    inFile.close(); //infile닫기
    while(1){
        cout << "\n********* MENU ***********" << endl;
        cout << "S : Search the list with a specified name" << endl;
        cout << "I : Insert a new entry" << endl;
        cout << "D : Delete an existing entry" << endl;
        cout << "P : Print the entire phone list" << endl;
        cout << "Q : Write the data back to the file and Quit" << endl;
        cout << "\nChoose menu : ";
        cin >> menu;
        if(menu=='S') { //search메뉴선택
            string targetname = "\0";
            cout << "==> Type name of the customer : ";
            cin.ignore(); //버퍼지우기
            getline(cin, targetname); //검색할이름 받기
            if(tree->searchData(targetname)!=NULL){ //검색이름 있으면 검색해서 출력
                cout << tree->searchData(targetname)->name <<"'s phone number is "
                << tree->searchData(targetname)->phone << endl;
            }
            else cout << "No record shown" << endl; //검색이름 없으면 없다
        }
        else if(menu=='I') tree->inseartData(); //추가메뉴선택
        else if(menu=='D') { //삭제메뉴선택
            string name;
            cout << "==> Type name of the customer : "; //이름받아
            cin.ignore(); //버퍼지우기
            getline(cin, name);
            if(!tree->searchData(name)) cout << name<<"'s record is not in the list." << endl;
            else { //검색해서 없으면 없다. 있으면 지우고 지움 출력
                tree->deleteData(name);
                cout << name << "'s record is deleted." << endl;
            }
        }
        else if(menu=='P') tree->printData(); //출력메뉴선택
        else if(menu=='Q') {tree->writeData(filename); break;} //저장하고끝메뉴 선택
        else {
            cout << "Wrong menu, quit" << endl; //잘못된메뉴선택시
            break;
        }
    }
    return 0;
}

void BST::insert_node(string name, string phone){ //노드새로만들기
    tree_node *ptr = NULL, *parent = NULL;
    parent = modified_search(name); //집어넣을 부모 반환
    if(parent || !root){ //부모있고 루트아닐때
        ptr = new tree_node;
        if(ptr == NULL){ //메모리 꽉찼을때
            cerr << "The memory is full" << endl;
            exit(1);
        }
        ptr->name = name;
        ptr->phone = phone;
        ptr->left_child = ptr->right_child = NULL; //노드에 데이터 넣

        if(root==NULL) root = ptr; //루트에 넣는건 쉬움
        else { //아니면 비교해서 작으면 왼쪽, 크면 오른쪽으로 넣
            if (compare(name,parent->name)==-1) parent->left_child = ptr;
            else parent->right_child = ptr;
        }
    }
    ptr = new tree_node;
}

tree_node* BST::modified_search(string name){ //parent반환
    tree_node *tree = root;
    while(tree){
        if(compare(name,tree->name)==0) return NULL; //name존재하면
        else if(compare(name,tree->name)==-1) //name이 tree->name보다 작으면
            if(tree->left_child == NULL) return tree;
            else tree = tree->left_child;
        else  //name이 tree->name보다 크면
            if(tree->right_child == NULL) return tree;
            else tree = tree->right_child;
    }
    return NULL;
}

void BST::printData(){ //inorder 이용해 모두 출력
    tree_node *tree = root;
    cout<< "NAME           	   Phone # " << endl;
    inorder(this->root);
}

tree_node* BST::searchData(string name){ //parent반환
    tree_node *tree = root;
    while(tree){
        if(compare(name,tree->name)==0) return tree; //name존재하면
        else if(compare(name,tree->name)==-1) //name이 tree->name보다 작으면
            if(tree->left_child == NULL) return NULL;
            else tree = tree->left_child;
        else  //name이 tree->name보다 크면
            if(tree->right_child == NULL) return NULL;
            else tree = tree->right_child;
    }
    return NULL;
}

void BST::inseartData(){ //데이터추가
    string ptrname;
    string ptrphone;
    cout << "==> Type name of the customer : ";
    cin.ignore(); //입력버퍼지우기
    getline(cin, ptrname);
    cout << "==> Type phone number : ";
    getline(cin, ptrphone); //입력버퍼지우기
    if(searchData(ptrname)!=NULL) cout << "Error : Dupe record" << endl;
    else {
        this->insert_node(ptrname, ptrphone);
        cout << ptrname << "'s record is added" << endl;
    }
}   

void BST::deleteData(string name){ //노드지우기
    root = this->deleteKey(this->root, name);
}

void BST::writeData(string filename){ //파일에출력하기
    ofstream outFile;
    outFile.open(filename);
    tree_node *tree = root;
    if(outFile.is_open()) { //열려있는동안
        outFile << "NAME           	   Phone # " << endl;
        while(tree!=NULL){ //tree가 null이 아닌동안(데이터가 있으면)
            if(tree->left_child!=NULL)tree = tree->left_child; //일단 왼쪽부터 가서
            outFile << tree->name << "   " << tree->phone << endl; //출력
            if(tree->right_child!=NULL) tree = tree->right_child; //왼쪽다갔으면 오른쪽으로
        }
    }
    outFile.close(); //출력파일닫기
}