#include <bits/stdc++.h>
using namespace std;

int dice[7];

// A, B, C, D, E, F면을 각각 1, 2, 3, 4, 5, 6면이라고 했을 때
// 2, 3면을 노출할 수 있는 경우는 아래와 같다.
int case_for_three[8][3] = {{1, 2, 3}, {1, 2, 4}, {1, 3, 5}, {1, 4, 5}, {6, 2, 3}, {6, 2, 4}, {6, 3, 5}, {6, 4, 5}};
int case_for_two[12][2] = {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {2, 3}, {2, 4}, {3, 5}, {4, 5}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a = 999, b = 999, c = 999;
    long long result = 0;
    cin >> n;

    for (int i = 1; i <= 6; i++)
        cin >> dice[i];

    // 예외처리 : n==1, 블럭이 1개면 노출되는 면이 5개임. 최댓값 하나만 빼고 노출시키면 됨.
    if (n == 1)
    {
        int temp = 0;
        sort(dice + 1, dice + 7);
        for (int i = 1; i <= 5; i++)
            temp += dice[i];

        cout << temp;
        exit(0);
    }

    // 3면을 노출하는 경우의 수 중에 노출하는 수가 가장 적은 case를 선택
    for (int i = 0; i < 8; i++)
    {
        int temp = 0;
        temp += dice[case_for_three[i][0]];
        temp += dice[case_for_three[i][1]];
        temp += dice[case_for_three[i][2]];

        a = min(a, temp);
    }

    // 2면을 노출하는 경우의 수 중에 노출하는 수가 가장 적은 case를 선택
    for (int i = 0; i < 12; i++)
    {
        int temp = 0;
        temp += dice[case_for_two[i][0]];
        temp += dice[case_for_two[i][1]];

        b = min(b, temp);
    }

    // 1면을 노출하는 경우의 수 중에 노출하는 수가 가장 적은 case를 선택
    for (int i = 1; i <= 6; i++)
        c = min(c, dice[i]);

    // n*n*n의 정육면체로 이루어져있을 때, 노출되어있는 수의 합을 구하는 관계식
    result = 4 * a + (8 * n - 12) * b;

    // result_temp=5*n*n-16*n+12로 처리할 때랑, 아래와 같이 operation을 하나씩 처리하는 거랑 결과값이 차이남
    // c에서 숫자 리터럴을 저장하는 기본 타입은 double임.
    // 등호 오른쪽 5*n*n을 계산할 때 double type이 리터럴로 사용되어서 overflow나는 듯..
    long long result_temp = 5 * n;
    result_temp *= n;
    result_temp += 12;
    result_temp -= 16 * n;
    result_temp *= c;

    result += result_temp;
    // result += (5 * n * n - 16 * n + 12) * c;

    cout << result;

    return 0;
}