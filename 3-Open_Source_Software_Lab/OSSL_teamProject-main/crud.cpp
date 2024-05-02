#include "crud.h"

void Clothes::set_data(string n, int p, string s, int r, int ns) {
    name = n;
    price = p;
    size = s;
    review = r;
    numStars = ns;
}

void Clothes::set_name(string n) {
    name = n;
}

void Clothes::set_price(int p) {
    price = p;
}

void Clothes::set_size(string s) {
    size = s;
}

void Clothes::set_review(int r) {
    review = r;
}

void Clothes::set_numStars(int ns) {
    numStars = ns;
}

string Clothes::get_name() {
    return name;
}

int Clothes::get_price() {
    return price;
}

string Clothes::get_size() {
    return size;
}

int Clothes::get_review() {
    return review;
}

int Clothes::get_numStars() {
    return numStars;
}

Clothes* Clothes::get_link() {
    return link;
}

Product:: Product() {
    head = NULL;
    tail = NULL;
}

void Product::add_to_tail(Clothes c) {
    Clothes *tmp;
    tmp = new Clothes;
    (*tmp) = c;
    tmp->link = NULL;
    if (tail!= NULL) {
        tail->link = tmp;
    }
    else {
        head = tmp;
    }
    tail = tmp;
}

bool Product::list_empty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

Clothes* Product::get_product(string p_name) {
    Clothes *c;
    string name;
    double result;
    for (c = head; c!=NULL; c = c->link) {
        if (strstr(c->get_name().c_str(), p_name.c_str())) {
            return c;
        }
    }
}

int Product::remove_product(string p_name) {
    Clothes *ahead, *before, *temp;
    Clothes *c;
    int result=0;
    before = head;
    if (strstr(head->get_name().c_str(),p_name.c_str())) {
        c = head;
        head = head->link;
        delete c;
        result = 1;
    }
    
    else {
        for (ahead = head->link; ahead!=NULL; ahead = ahead->link) {
            if (strstr(ahead->get_name().c_str(),p_name.c_str())) {
                before->link = ahead->link;
                delete ahead;
                result = 1;
            }
        }
    }
    return result;
}

Clothes createClothes() {
    Clothes c;
    string tmp, remainder;
    int price, review, numStars;
    char size;
    printf("\n");
    printf("제품명? ");
    getline(cin, remainder);
    getline(cin, tmp);
    c.set_name(tmp);

    printf("가격? ");
    scanf("%d",&price);
    c.set_price(price);

    printf("사이즈 (S, M, L, F(Free)? ");
    cin >> tmp;
    c.set_size(tmp);

    printf("리뷰개수? ");
    scanf("%d",&review);
    c.set_review(review);

    printf("별점개수? ");
    scanf("%d",&numStars);
    c.set_numStars(numStars);

    return c;
}

void readClothes(Clothes *c) {
    Clothes *tmp;
    int count=0;
    printf("제품명 / 사이즈 / 가격 / 리뷰개수 / 별점개수\n");
    printf("......................\n");
    for (tmp = c; tmp!=NULL; tmp = tmp->link) {
        cout << tmp->get_name() << " / " << tmp->get_size();
        printf(" / %5d", tmp->get_price());
        printf(" / %5d", tmp->get_review());
        printf(" / %5d\n", tmp->get_numStars());
        count++;
    }
    printf("......(총 %d개)........\n", count);
}

int updateClothes(Clothes *c) {
    string tmp, remainder;
    int price, review, numStars;
    printf("\n");
    printf("제품명? ");
    getline(cin, remainder);
    getline(cin, tmp);
    c->set_name(tmp);

    printf("가격? ");
    scanf("%d",&price);
    c->set_price(price);

    printf("사이즈 (S, M, L, F(Free)? ");
    cin >> tmp;
    c->set_size(tmp);

    printf("리뷰개수? ");
    scanf("%d",&review);
    c->set_review(review);

    printf("별점개수? ");
    scanf("%d",&numStars);
    c->set_numStars(numStars);
    return 1;
}

int menu() {
    int m;
    printf("\n[1]목록 [2]추가 [3]수정 [4]삭제 [5]검색 [6]불러오기 [7]저장 [0]종료 >> ");
    scanf("%d", &m);
    return m;
}

int category() {
    int type;
    printf("카테고리 (0:상의, 1:하의, 2:드레스, 3:전체)? ");
    scanf("%d", &type);
    return type;
}

int deleteClothes(Product *p) {
    string temp, remainder;
    readClothes(p->head);
    printf("삭제하고 싶은 제품 이름? ");
    getline(cin, remainder);
    getline(cin, temp);
    return p->remove_product(temp);
}