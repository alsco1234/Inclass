## 포항사랑상품권 이용정보
#### 누구에게?  
>	포항사랑상품권을 사고 / 가맹점에서 이용하고자 하는 소비자  
#### 왜?  
>	포항사랑상품권 이용 가능한 가맹점 정보를 한눈에 알기 힘들고, 일일히 전화해서 확인해야 하는 불편함이 있다. 포항사랑상품권을 어디서 파는지 알기도 힘들다  
#### 무엇을?   
>	포항사랑상품권을 이용할 수 있는 가맹점을 리스트로 보여주고, 포항사랑상품권을 판매하는 가맹점도 리스트로 보여준다. 
#### 어떻게?   
>	도로명 주소의 키워드를 이용해서, 위치를 검색하면 위치의 이름, 주소, 연락처 등을 보여준다. 
---
#### 구체적인 필드 이름과 타입(숫자, 글자, 날짜)
<pre>
<code>
	STORE{ //판매점
seq (int(11)), auto-increment, KEY //시드
belong (varchar(30)) //금융기관명
name (varchar(30)) //판매 및 환전처명
Address (varchar(100)) //주소
Latitude (varchar(20)) //위도
longitude (varchar(20)) //경도
regdate (timestamp) //기준일자
cnt (int(11))
}
</code>
</pre>

<pre>
<code>
	FRANCHISEE{ //가맹점
seq (int(11)), auto-increment, KEY //시드
name (varchar(30)) //업체명
callnum (varchar(20)) //연락처
category (varchar(20)) //업태
admin (varchar(20)) //행정동
address (varchar(100)) //주소
latitude (varchar(20)) //위도
longitude (varchar(20)) //경도
regdate (timestamp) //기준일자
cnt (int(11))
}
</code>
</pre>

--- 
### Crud 기능별 예상 동작 설명
#### C : 판매점 / 가맹점 등록
#### R : 메인 기능
>	판매점 검색 : 근융기관명, 판매 및 환전처명, 주소 ,위도로 검색 		가능 (일부만 포함해도 검색 가능하게)
>	위도는 가장 가까운 곳 순으로 출력 기능

>	가맹점 검색 : 업체명, 연락처, 업태, 행정동, 주소로 검색 가능 		(일부만 포함해도 검색 가능하게)
#### U : 판매점 / 가맹점 수정
#### D : 핀메잠 / 가맹점 삭제
---
https://www.data.go.kr/data/15063240/fileData.do //판매점
https://www.data.go.kr/data/15030170/fileData.do //가맹점
JSON 이용
