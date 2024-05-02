#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "class.h"

vector<string> split(string str, char delimiter);

void saveData(Product *p, string filename); //데이터 저장
int loadData(Product *p, string filename); //데이터 읽어오기

void searchName(Clothes *c, int count, string filename);
void searchPrice(Clothes *c, int count, int filename);
void searchSize(Clothes *c, int count, string filename);
void searchNum_stars(Clothes *c, int count, int filename);