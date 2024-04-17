#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
vector<tuple<int, int, int, int>> timeline;

bool compare(const tuple<int, int, int, int> &A, const tuple<int, int, int, int> &B);
void func(int last_end_time, int last_day, int value, int index);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    // 요일, 시작시각, 종료시각을 tuple로 입력받음
    for (int i = 0; i < n; i++)
    {
        int day, start, end;
        cin >> day >> start >> end;

        // 어차피 금공강 만들 거라 금요일 수업은 고려 안 함.
        if (day != 5)
            timeline.push_back(make_tuple(day, start, end, end - start + 1));
    }

    // 요일 -> 시작시각 -> 종료시각 순으로 정렬
    sort(timeline.begin(), timeline.end());

    func(0, 1, 0, 0);

    cout << cnt;

    return 0;
}

bool compare(const tuple<int, int, int> &A, const tuple<int, int, int> &B)
{
    if (get<0>(A) == get<0>(B))
    {
        if (get<1>(A) == get<1>(B))
            return get<2>(A) < get<2>(B);

        return get<1>(A) < get<1>(B);
    }

    return get<0>(A) < get<0>(B);
}

void func(int last_end_time, int last_day, int value, int index)
{
    // timeline의 각 수업 each를 수강하거나, 안 하거나 둘 중에 하나를 결정해야 함.
    // 두 가지로 가지치기하면서 backtracking.
    // value : 지금까지 채운 학점
    // index : timeline에서 수업 고를 때 쓰는 인덱스

    if (value == k)
    {
        // k학점을 다 채운 경우
        cnt += 1;
        return;
    }

    if (index >= timeline.size())
        // timeline의 수업을 끝까지 고려했지만 k학점 못 채운 경우
        return;

    // 아직 k학점 덜 채움 : 다음 수업을 시간표에 추가할 건지 안 할 건지 결정
    tuple<int, int, int, int> next = timeline[index];

    // 다음 수업을 추가하고 싶은 경우
    if (last_day < get<0>(next))
    {
        // 다음 날짜로 넘어가는 경우 : 이전 수업이 언제 끝났는 지 고려 안 해도 됨
        func(get<2>(next), get<0>(next), value + get<3>(next), index + 1);
    }
    else
    {
        // 이전 수업과 다음 수업의 날짜가 같은 경우
        if (last_end_time < get<1>(next))
        {
            // 이전 수업의 종료시각이 다음 수업의 시작시각보다 이전이어야 함
            if (k - value >= get<3>(next))
            {
                func(get<2>(next), get<0>(next), value + get<3>(next), index + 1);
            }
        }
    }

    // 다음 수업을 추가하지 않는 경우
    func(last_end_time, last_day, value, index + 1);
}