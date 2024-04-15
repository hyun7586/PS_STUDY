#include <bits/stdc++.h>
using namespace std;

// S[][] : 팀원간의 능력치 저장하는 배열
// team[i] : i번 직원이 어느 팀인지 저장하는 배열, 0팀 - 1팀으로 구분했음
int n;
int S[21][21];
int team[21];

int solve(int k);
void Input();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    cout << solve(0);

    return 0;
}

int solve(int k)
{
    // 현재 n명의 직원 중 k번 직원까지 팀 배분이 끝난 상태일 때
    // 다음 직원의 팀을 배정하거나, 팀 능력치를 계산해서 차이값을 return하는 함수

    /***
     예외처리 : 한 팀으로 모든 인원이 몰리는 경우
     한 팀의 인원이 n명이므로 해당 팀의 팀능력치는 S[][] 배열의 모든 값의 합임
     다른 팀의 팀 능력치는 당연히 0
     결국 return되는 팀능력치 차이는 모든 경우의 수에서 나올 수 있는 차이값 중 가장 최댓값임
     -> 항상 두 개의 후보지 중에 최솟값을 return하도록 함수를 구현했기 때문에 딱히 예외처리 안 했음.
     -> 한 팀의 인원이 n명으로 몰리는 경우까지 계산하는 함수긴 함.
    */

    // 모든 팀원의 팀 배정이 끝난 경우
    if (k == n)
    {
        // sum_of_team : 0팀과 1팀의 팀 능력치를 저장하는 배열
        int sum_of_team[2] = {0, 0};

        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (team[i] == team[j])
                    sum_of_team[team[i]] += S[i][j] + S[j][i];

        // 차이값을 양수로 return
        return max(sum_of_team[1], sum_of_team[0]) - min(sum_of_team[1], sum_of_team[0]);
    }

    // 아직 팀 배정이 덜 된 직원이 있는 경우
    // 다음 직원을 먼저 0팀이라고 고려하고 팀능력치 최솟값 계산
    team[k + 1] = 0;
    int candidate1 = solve(k + 1);

    // 다음 직원을 1팀이라고 가정하고 팀능력치 최솟값 계산
    team[k + 1] = 1;
    int candidate2 = solve(k + 1);

    // 두 후보 candidate1, 2 중에 최솟값을 return
    return min(candidate1, candidate2);
}

void Input()
{
    // 직원 수 n과 팀원 간의 조합능력치 값을 입력받음
    // S[][] 배열의 index는 1부터 집어넣었음
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> S[i][j];
}
