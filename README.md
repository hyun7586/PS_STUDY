# 🔥 PS_STUDY
- 코딩 테스트 대비를 위한 알고리즘 스터디 저장소
- 각자가 업로드한 BOJ, Programmers, LeetCode 문제를 풀고 풀이과정을 공유하며 함께 성장하는 것을 목표로 한다.
- 1주일에 각자 2문제씩 업로드하며, 총 6문제를 푼다.
- 풀이 소스코드와 풀이를 설명할 readme 파일을 함께 업로드한다.


## 📂 Folder structure

`[n주차]/[platform_문제 번호]/[이름]` 구조를 사용한다.

```
├───WEEK1/          #주차
│   ├───BOJ_11724/    #문제 번호
│   │   ├───KDH/        #이름
│   │   │       11724.cpp    #풀이 소스 코드
│   │   │       11724.exe    #실행 파일(optional)
│   │   │       README.md    #풀이 설명 readme 파일
|   |   | ...
```


## 📌 Conventions

#### File naming
`{name}-{platform}-{문제번호 || 문제이름}.{확장자}`
모두 대문자로 작성
  > ex) KDH-BOJ-10828.cpp, KDH-LEET-29.cpp, KDH-PROG-전화번호목록.cpp

#### Branch naming
`{NAME}/{create || modify || ...}-{platform}-{(문제번호)}`
  > ex) KDH/create-boj-2126

#### Commit message
```
{NAME}: {create || modify || ...} {platform} {문제번호} {문제이름}

new file: {directory/file}
new file: {directory/file}
modify: {directory/file}
- 기타 변경사항 명시
...
```

1. 추가한 파일 목록을 모두 작성한다.
2. 소스코드, 실행파일, readme 파일 모두 commit한다.
3. 수정 작업을 수행했으면 어떤 부분을 수정했는지 commit message에 명시한다.

#### PR title naming
`{NAME}: {create || modify || ...} {platform} {(문제번호)} {문제이름}`
  > ex) KDH/create-boj-2346 풍선 터뜨리기

## 💪 Commit & PR request

1. `{NAME}/{create || modify || ...}-{platform}-{(문제번호)}` 형식의 branch 생성
   
2. 생성된 branch 내에서 `[n주차]/[platform_문제 번호]/[이름]` 디렉토리 생성 후 **풀이 코드 및 리뷰 readme 파일** 생성

3. 문제 풀이 완료 시 Pull Request 생성
   - PR 제목: `{NAME}/{create || modify || ...}-{platform}-{(문제번호)} {문제이름}`


## 📖 Code Review

- 개선점, 의문점, 칭찬할 부분 코멘트 통해 자유롭게 제시 (Issue, PR ...)
