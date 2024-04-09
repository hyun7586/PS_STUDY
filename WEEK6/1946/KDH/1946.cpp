#include <bits/stdc++.h>
using namespace std;

int Test_case;

// n명의 신입사원에 대해서 greedy 기법을 수행해서 선발할 수 있는 최대 신입사원의 수를 return
int Greedy(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Test_case;

    for (int t = 0; t < Test_case; t++)
    {
        int n;
        cin >> n;

        cout << Greedy(n) << '\n';
    }

    return 0;
}

int Greedy(int n)
{
    /***
    지원자 i보다 서류등수가 높으면서 면접등수도 높은 지원자가 존재하면 i가 탈락임
    -> i보다 서류등수가 높은 지원자 중 가장 높은 면접등수보다 i의 면접등수가 더 높으면
    -> 적어도 i가 면접등수에서는 우위를 가짐, i는 합격할 수 있음.

    arr에 서류등수, 면접등수 pair 형태로 저장되어있고, 서류등수를 기준으로 오름차순 정렬을 해 놨음.
    temp : 지원자 i보다 서류등수가 높은 지원자 중 가장 높은 면접 등수를 저장

    arr를 순회해 가며 temp보다 면접등수가 높으면 result+=1;
    i값을 늘리며 다음 지원자를 탐색할 때마다 temp는 가장 높은 값으로 갱신해 줘야 함.
    이 알고리즘에서 말하는 '등수가 높다'라는 표현은 '등수값이 낮다'라고 해석해야 함.
    */

    // n명의 신입사원에 대해서 greedy 기법을 수행해서 선발할 수 있는 최대 신입사원의 수(result)를 return
    int result = 0;
    vector<pair<int, int>> arr;

    // 초기 setting : n명의 등수 정보를 pair로 arr에 저장
    for (int i = 0; i < n; i++)
    {
        int A, B;
        // 서류등수, 면접등수 순서로 입력
        cin >> A >> B;

        arr.push_back(make_pair(A, B));
    }

    // 서류등수를 기준으로 오름차순으로 정렬
    sort(arr.begin(), arr.end());

    // temp : i보다 높은 서류 등수를 가진 지원자들 중 가장 높은 면접등수
    int temp = arr[0].second;

    // 서류 1등은 무조건 합격
    result += 1;

    // 서류 2등부터 탐색
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second < temp)
        {
            // temp보다 지원자 i의 면접등수가 더 높으면 -> i는 합격, 다음 지원자는 지원자 i보다 면접등수가 좋아야 하므로 temp 갱신
            result += 1;
            temp = arr[i].second;
        }
    }

    return result;
}