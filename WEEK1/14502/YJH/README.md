# [14502] 연구소

### 코드 설명

1. graph는 미로, wall_record는 빈 공간의 좌표를 저장하는 배열, empty는 이미 벽이 놓아진 공간의 좌표를 저장하는 배열, virus_group은 바이러스의 좌표를 저장하는 배열
2. 빈 공간 중 벽 3개를 놓는 경우의 수를 모두 찾아서 벽을 놔보고 바이러스를 퍼트려본 후(bfs), 안전공간 중 가장 큰 값을 찾도록 설계
3. itertools 라이브러리의 combinations(조합) 함수를 사용
4. 벽3개를 놓을때마다 미로를 새로 만들어서 bfs -> 미로 새로 만드는 과정에서 deepcopy가 빠른지 for문으로 graph를 새로 만드는게 빠른지 테스트 해봤는데 새로 만드는게 훨씬 빠르다.
5. Max가 안전구역의 최대값이다.