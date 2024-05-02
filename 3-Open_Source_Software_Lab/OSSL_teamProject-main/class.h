#include <iostream>
#include <string>
#ifndef CLASS
#define CLASS

using namespace std;

class Clothes {
private:
    string name;        //��ǰ��
    int price;          //����
    string size;          //������(S,M,L,F(free))
    int review;         //���� ����
    int numStars;       //���� ����
public:
    Clothes* link;      //���� node�� ����Ű�� ������
    //setter
    void set_data(string n, int p, string s, int r, int ns);
    void set_name(string n);
    void set_price(int p);
    void set_size(string s);
    void set_review(int r);
    void set_numStars(int ns);
    //getter
    string get_name();
    int get_price();
    string get_size();
    int get_review();
    int get_numStars();
    Clothes* get_link();
};

class Product {
public:
    Clothes *head, *tail;
    Product();
    void add_to_tail(Clothes c);
    bool list_empty();
    Clothes* get_product(string p_name);
    int remove_product(string p_name);
};

#endif
