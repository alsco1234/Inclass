#include <iostream>
#include <queue>
using namespace std;

#define MAX 12

int graph[MAX][MAX] = { { 0, 15, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //Daegeou
                        { 15, 0, 12, 0, 0, 0, 0, 0, 0, 15, 0, 0 }, //SaSang
                        { 8, 12, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, //Ducchon
                        { 0, 0, 10, 0, 3, 0, 7, 0, 0, 0, 0, 0 }, //MeeNam
                        { 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 0, 0 }, //Dongrae
                        { 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 12 }, //KyuDae
                        { 0, 0, 5, 5, 0, 2, 0, 2, 0, 0, 11, 0 }, //GyeJae
                        { 0, 0, 0, 0, 0, 2, 2, 0, 6, 0, 10, 0 }, //YunSan
                        { 0, 0, 0, 0, 0, 0, 5, 6, 0, 1, 0, 0 }, //BuChon
                        { 0, 15, 0, 0, 0, 0, 0, 0, 1, 0, 20, 0 }, //SuMyan
                        { 0, 0, 0, 0, 0, 0, 11, 0, 0, 20, 0, 6 }, //SuYung
                        { 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 6, 0 } }; //BeckSKo

string name[MAX] = {"Daegeou", "SaSang", "Ducchon", "MeeNam", "Dongrae", 
                    "KyuDae", "GyeJae", "YunSan", "BuChon", "SuMyan",
                    "SuYung", "BeckSKo"};

void dijkstra(int start){
    bool S[MAX] = { 0 }; //already find : true
    int D[MAX];
    queue<int> P[MAX];

    S[start] = true; //if start and end is equal, time is 0
    
    for (int i = 0; i < MAX; ++i) {
        if(graph[start][i] != 0) P[i].push(i);
    }

    for (int i = 0; i < MAX; ++i) {
        D[i] = graph[start][i];
    }

    for (int j = 1; j < MAX; ++j) {
        int w = start;

        for (int i = 0; i < MAX; ++i) {
            if (D[i] != 0 && !S[i]) {
                if (D[w] == 0 || D[w] > D[i]) w = i;
            }
        }

        S[w] = true;

        for (int i = 0; i < MAX; ++i) {
            if (graph[w][i] != 0 && !S[i]) {
                if ((D[i] == 0) || (D[i] > D[w] + graph[w][i])) {
                    if (D[w] != 0) {

                        if (!P[i].empty()) {
                            queue<int> pre_path = P[i];
                            int prev, next;
                            int pre_d = 0, post_d = 0;

                            prev = start;

                            while (!pre_path.empty()) {
                                next = pre_path.front();
                                pre_d += graph[prev][next];
                                prev = next;
                                pre_path.pop();
                            }

                            queue<int> post_path = P[w];

                            prev = start;

                            while (!post_path.empty()) {
                                next = post_path.front();
                                post_d += graph[prev][next];
                                prev = next;
                                post_path.pop();
                            }

                            post_d += graph[w][i];

                            if (pre_d > post_d) {
                                post_path = P[w];
                                post_path.push(i);
                                P[i] = post_path;
                            }
                        }
                        else {
                            P[i] = P[w];
                            P[i].push(i);
                        }
                        D[i] = D[w] + graph[w][i];
                    }
                }
            }
        }
    }

    //print
    cout << "Start\tEnd\t\tTime(min)\t\tPath" << endl;
    cout << "========================================================================" << endl;

    for (int i = 0; i < MAX; ++i) {
        cout << name[start] << "\t" << name[i] << "\t\t" << D[i] << "\t\t\t";
        
        if (!P[i].empty()) {
            queue<int> temp = P[i];
            cout << name[start];

            do {
                cout << " - " << name[temp.front()];
                temp.pop();
            } while (!temp.empty());

            cout << endl;
        }
        else {
            if (i != start) cout << "not existing Path" << endl;
            else cout << name[start] << endl;
        }
    }
}

int main(){
    cout << "FINDING SHORTEST PATH USING MATRO IN BUSAN" << endl;
    cout << "Daegeou = 0, \t SaSang = 1, \t Ducchon = 2, \t MeeNam = 3, \n Dongrae = 4, \t KyuDae = 5, \t GyeJae = 6, \t YunSan = 7, \n BuChon = 8, \t SuMyan = 9, \t SuYung = 10, \t BeckSKo = 11" << endl;
    cout << "Enter your home : ";
    int home;
    cin >> home;
    dijkstra(home);

    return 0;
}
