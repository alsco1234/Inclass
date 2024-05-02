#include "crud.h"
#include "manager.h"
#define QUIT 0
#define READ 1
#define CREATE 2
#define UPDATE 3
#define DELETE 4
#define SEARCH 5
#define LOAD 6  //불러오기
#define SAVE 7  //저장

int main() {
    Product top, bot, dress;
    Clothes tmp;
    string CATEGORY[3] = {"상의","하의","드레스"}, temp, remainder;
    int cmd, type, check=1, count=0;
    do {
        cmd = menu();
        switch (cmd) {
            case READ:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("등록된 상품이 없습니다.");
                            break;
                        }
                        else {
                            cout << "\n" << CATEGORY[0] << " 제품 정보입니다." << endl;
                            readClothes(top.head);
                        }
                        break;
                    case 1:
                        if (bot.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            cout << "\n" << CATEGORY[0] << " 제품 정보입니다." << endl;
                            readClothes(bot.head);
                        }
                        break;
                    case 2:
                        if (dress.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            cout << "\n" << CATEGORY[0] << " 제품 정보입니다." << endl;
                            readClothes(dress.head);
                        }
                        break;
                    case 3:
                        if (top.list_empty() && bot.list_empty() && dress.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            printf("\n상의\n");
                            readClothes(top.head);
                            printf("\n\n하의\n");
                            readClothes(bot.head);
                            printf("\n\n드레스\n");
                            readClothes(dress.head);
                        }
                }
                break;
            case CREATE:
                tmp = createClothes();
                switch (category()) {
                    case 0:
                        top.add_to_tail(tmp);
                        break;
                    case 1:
                        bot.add_to_tail(tmp);
                        break;
                    case 2:
                        dress.add_to_tail(tmp);
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> 추가됨\n");
                break;
            case UPDATE:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        readClothes(top.head);
                        printf("수정하고 싶은 제품 이름? ");
                        getline(cin, remainder);
                        getline(cin, temp);
                        check = updateClothes(top.get_product(temp));
                        break;
                    case 1:
                        if (bot.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        readClothes(bot.head);
                        printf("수정하고 싶은 제품 이름? ");
                        getline(cin, remainder);
                        getline(cin, temp);
                        check = updateClothes(bot.get_product(temp));
                        break;
                    case 2:
                        if (dress.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        readClothes(dress.head);
                        printf("수정하고 싶은 제품 이름? ");
                        getline(cin, remainder);
                        getline(cin, temp);
                        check = updateClothes(dress.get_product(temp));
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> 수정됨\n");
                break;
            case DELETE:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        deleteClothes(&top);
                        break;
                    case 1:
                        if (bot.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        deleteClothes(&bot);
                        break;
                    case 2:
                        if (dress.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        deleteClothes(&dress);
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> 삭제됨\n");
                break;
            case SEARCH:
            int searchhow;
                std :: cout << "무엇으로 검색하시겠습니까?" << endl;
                std :: cout << "이름(1) /  가격(2) / 사이즈(3) / 별점수(4) / 취소(0) >> ";
                std :: cin >> searchhow;
                if(searchhow==0){
                    std :: cout << "==> 취소됨! ";
                    break;
                }
                else if(searchhow==1){
                    string target;
                    std :: cout << "\n어떤 이름을 찾으세요? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. 상의에서" << endl;
                    searchName(top.head, count, target);
                    std :: cout << "\ncategory 2. 하의에서" << endl;
                    searchName(bot.head, count, target);
                    std :: cout << "\ncategory 3. 드레스에서" << endl;
                    searchName(dress.head, count, target);
                }
                else if(searchhow==2){
                    int target;
                    std :: cout << "\n어떤 가격을 찾으세요? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. 상의에서" << endl;
                    searchPrice(top.head, count, target);
                    std :: cout << "\ncategory 2. 하의에서" << endl;
                    searchPrice(bot.head, count, target);
                    std :: cout << "\ncategory 3. 드레스에서" << endl;
                    searchPrice(dress.head, count, target);
                }
                else if(searchhow==3){
                    string target;
                    std :: cout << "\n어떤 사이즈를 찾으세요? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. 상의에서" << endl;
                    searchSize(top.head, count, target);
                    std :: cout << "\ncategory 2. 하의에서" << endl;
                    searchSize(bot.head, count, target);
                    std :: cout << "\ncategory 3. 드레스에서" << endl;
                    searchSize(dress.head, count, target);
                }
                else if(searchhow==4){
                    int target;
                    std :: cout << "\n어떤 별점 수를 찾으세요? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. 상의에서" << endl;
                    searchNum_stars(top.head, count, target);
                    std :: cout << "\ncategory 2. 하의에서" << endl;
                    searchNum_stars(bot.head, count, target);
                    std :: cout << "\ncategory 3. 드레스에서" << endl;
                    searchNum_stars(dress.head, count, target);
                }
                break;
            case LOAD:
                switch (category()) {
                    case 0:
                        //loadData();
                        check = loadData(&top, "topInfo.txt");
                        break;
                    case 1:
                        bot.add_to_tail(tmp);
                        break;
                    case 2:
                        dress.add_to_tail(tmp);
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> 로딩완료\n");
                break;
            case SAVE:
                switch (category()) {
                    case 0:
                        saveData(&top, "topInfo.txt");
                        break;
                    case 1:
                        saveData(&bot, "botInfo.txt");
                        break;
                    case 2:
                        saveData(&dress, "dressInfo.txt");
                        break;
                    default:
                        saveData(&top, "topInfo.txt");
                        saveData(&bot, "botInfo.txt");
                        saveData(&dress, "dressInfo.txt");
                        check=0;
                }
                cout << "==> 저장완료" << endl;
                break;
            default:
                break;
        }
    } while(cmd != QUIT);
    printf("종료되었습니다.\n");
    return 0;
}