# PR_practice
## 2200080 김민채 
- - -
### 1. git/github   
* **git** : 지역 저장소를 만들고 파일, 코드 등을 관리하는 작업(**편집기**)   
* **git hub** : 로컬에서 git으로 관리하는 자료를 다른 사람들과 공유하거나 백업해둘 수 있는 웹사이트(**공유 게시판**)   
* **git이 파일을 관리하는 상태**   
> * untracted : init   
> * modified   
> * staged : add   
> * commited : commmit   
- - -
### 2. Alias 설정 / Branch     
* **Alias** : 별명, 단축어   
> * vi 편집기 이용 (vi ~/.gitconfig)   
* **Branch** : 커밋들을 포인팅하는 포인터    
> * Branch 생성 : git branch "새브랜치이름"   
> * Branch 이주 : git checkout "이동할브랜치이름"   
> * Branch 확인 : git branch   
> * Branch 병합 : git merge "병합할브랜치이름" --> 브랜치를 현재의 브랜치로 병합   
> * Branch 기록확인 : git log   
> * 커밋 취소 : git reset      
* **merge conflict**   
<pre>
<code>
void message(){
  puts("branch is good");
 }
 void main(){
 <<<<<<<< HEAD
  puts("branch is good");
========
  message();
 >>>>>>>> testing
}
</code>
</pre>
HEAD에서 변경된 부분은 <<<HEAD에서 ===까지   
testing 브랜치에서 변경된 부분은 ====부터 >>>testing까지
- - -
### 3. markdown / PR
* **markdown** : = md파일, 텍스트로 저장
> * 문법 참고사이트 https://gist.github.com/ihoneymon/652be052a0727ad59601  
* **Pull Request** : 수정후 merge해달라고 요청      
* 순서
> * 1.Fork
> * 2.clone, remote 설정
> * 3.branch 생성
> * 4.수정 작업 후 sdd, commit, push
> * 5.Pull Request 생성
> * 6.코드리뷰, Merge Pull Request
> * 7.Merge 이후 branch 삭제 및 동기화
