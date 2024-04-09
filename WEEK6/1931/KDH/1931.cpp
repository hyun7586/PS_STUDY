#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &A, const pair<int, int> &B)
{
    /***
     sort에 사용되는 정렬함수
     second를 기준으로 오름차순으로 정렬하되, second값이 같으면 first값을 기준으로 정렬하도록 함.
     A<B로 설정하면 오름차순, A>B로 설정하면 내림차순
    */
    if (A.second == B.second)
        return A.first < B.first;

    return A.second < B.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> arr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        arr.push_back(make_pair(start, end));
    }

    // 회의 시작시각을 기준으로 오름차순으로 정렬하되,
    // 시작시각이 같으면 종료시각을 기준으로 오름차순으로 정렬.
    sort(arr.begin(), arr.end(), compare);

    // 이전 강의의 종료시각을 저장하는 변수, 초기상태는 0
    int LastLecture_EndTime = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (LastLecture_EndTime <= arr[i].first)
        {
            // 이전 강의 종료시각이 다음 강의 시작시각보다 작으면 됨.
            cnt += 1;
            LastLecture_EndTime = arr[i].second;
        }
    }

    cout << cnt;

    return 0;
}