#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> timeline;

int n, T;

bool compare(const tuple<int, int, int> &A, const tuple<int, int, int> &B);
void Input();
void solve(int t);
void vector_clear();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        Input();
        solve(t);
        vector_clear();
    }

    return 0;
}

bool compare(const tuple<int, int, int> &A, const tuple<int, int, int> &B)
{
    // sort에 사용되는 함수
    // 날짜 같으면
    if (get<0>(A) == get<0>(B))
    {
        // 종료시각 같은지 확인
        if (get<2>(A) == get<2>(B))
            return get<1>(A) < get<1>(B);

        // 날짜는 동일, 종료시각은 다름.
        else
            return get<2>(A) < get<2>(B);
    }

    return get<0>(A) < get<0>(B);
}

void Input()
{
    // 각 테스트케이스 별로 경기수, 경기정보를 입력받고 tuple로 저장함.
    // 2개 값 : pair, 3개 이상 : tuple
    cin >> n;

    int day, start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> day >> start >> end;
        timeline.push_back(make_tuple(day, start, end));
    }
}

void solve(int t)
// paramete t는 test case number임 -> 이후에 출력할 때 사용함.
{
    // result : 참관할 수 있는 올림픽 수
    // cur_date : 현재 날짜를 기록하는 변수
    // last_end_time : 마지막으로 참관한 경기의 종료시각, 다음 경기는 이 종료시각보다 늦은 시각이어야 함
    int result = 0, cur_date = 1, last_end_time = 0;

    // 날짜 -> 종료시각 -> 시작시각 중요도 순서로 정렬함.
    // 같은 날짜 내에서 종료시각이 이른 경기를 우선적으로 선택하면 됨.
    sort(timeline.begin(), timeline.end(), compare);

    for (auto each : timeline)
    {
        if (get<0>(each) > cur_date)
        {
            // 처음으로 현재 날짜보다 큰 값을 가지는 경기가 나오면 다음 날짜로 넘어감
            cur_date += 1;
            last_end_time = 0;
        }

        if (get<0>(each) == cur_date && last_end_time <= get<1>(each))
        {
            // 지난 경기 종료시각이 이번 경기 시작시각보다 이름 -> 경기 참관 가능
            result += 1;
            last_end_time = get<2>(each);
        }
    }

    // 출력형태 : 마지막에 개행문자 2개 써야 함
    cout << "Scenario #" << t << ":\n"
         << result << "\n\n";
}

void vector_clear()
{
    // timeline.clear();
    vector<tuple<int, int, int>>().swap(timeline);
}