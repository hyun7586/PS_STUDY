# PS_STUDY

## Folder structure

`[n주차]/[platform_문제 번호]/[이름]`


## Conventions

### File naming
`{name}_{platform}_{문제번호 || 문제이름}.{확장자}`
모두 대문자로 작성
  > ex) KDH_BOJ_10828.cpp, KDH_LEET_29.cpp, KDH_PROG_전화번호목록.cpp

### Branch naming
`{NAME}/{create || modify || ...}-{platform}-{(문제번호)}`
  > ex) KDH/create-boj-2126

### Commit message
```
{NAME}: {create || modify || ...} {platform} {문제번호} {문제이름}

new file: {directory/file}
new file: {directory/file}
modify: {directory/file}
- 변경사항 명시
```
추가한 파일 목록을 모두 작성한다.
소스코드, 실행파일, readme 파일 모두 commit한다.
modify 작업을 수행했으면 어떤 부분을 수정했는지 commit message에 명시한다.

### PR title naming
`{NAME}: {create || modify || ...} {platform} {(문제번호)} {문제이름}`
  > ex) KDH: create boj 2346 풍선 터뜨리기기

## Commit & Pull request

1. `{NAME}/{create || modify || ...}-{platform}-{(문제번호)}` 형식의 branch 생성
   
2. 생성된 branch 내에서 `[n주차]/[platform_문제 번호]/[이름]` 디렉토리 생성 후 **풀이 코드 및 리뷰 readme 파일** 생성

3. 문제 풀이 완료 시 Pull Request 생성
   - PR 제목: `{NAME}: {create || modify || ...} {platform} {(문제번호)} {문제이름}`


## Code Review

- 개선점, 의문점, 칭찬할 부분 코멘트 통해 자유롭게 제시 (Issue, PR ...)
