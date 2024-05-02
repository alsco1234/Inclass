## 구성한 기능(함수)
---
# __CRUD__ (담당자 : 나예원)
## int createClothes(Clothes *c) 
 Create : 카테고리 맞는 새 구조체 생성

## void readClothes(Clothes *c)
 Read : 카테고리 맞는 구조체들 읽어오기

## int updateClothes(Clothes *c) 
 Update : 대상 구조체 수정

## int deleteClothes(Product *p)
 Delete : 대상 구조체 삭제

---
# __DATA FILE__ (담당자 : 김민채)
## void saveData(Clothes *c, string filename);
 데이터 저장

## int loadData(Clothes *c, string filename); 
 데이터 읽어오기

---
# __검색__ (담당자 : 김민채)
## searchName(Clothes *c, int count)
 이름으로 검색

## searchPrice(Clothes *c, int count)
 가격으로 검색

## searchSize(Clothes *c, int count)
 사이즈로 검색

## searchNum_stars(Clothes *c, int count)
 별 개수로 검색
