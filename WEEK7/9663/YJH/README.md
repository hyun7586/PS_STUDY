# 9663 : N-Queen

## 코드 설명
1. depth은 퀸을 놓는 갯수, ary는 1차원 배열 체스판으로 설정, record는 이전에 놓았던 퀸들의 좌표를 기록하는 용도
2. 만약 depth가 1인, 첫번째로 놓는 경우라면 record에 좌표 담고 bt(depth+1...) 돌리기
3. depth가 2이상이라면 이전에 놓은것들과,새로 놓은 것들이 대각선으로 만나지 않는지 확인
4. 대각선으로 만나지 않으려면 abs(놓으려는 퀸의 y좌표 - 이전 퀸들의 y좌표) == abs(놓으려는 퀸의 x의 좌표 - 이전 퀸들의 x좌표)
5. 4번 조건이 성립하는 퀸들만 record에 좌표 담고 bt(depth+1...) 돌리기

## etc
1. 저번보다 시간이 2000ms나 더 걸림;