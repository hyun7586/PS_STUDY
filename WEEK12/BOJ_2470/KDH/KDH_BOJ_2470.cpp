#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N;
int low_diff = INT_MAX;
int result_val1, result_val2;
vector<int> arr;

void Input() {
  int temp;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
}

int modified_binary_search(int left, int right, int target) {
  // target보다 큰 원소 중 가장 값이 작은 원소의 index를 출력력
  // arr에 target보다 큰 원소가 없다면? right+1을 return
  int result = right + 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] > target) {
      result = mid;
      right = mid - 1;
    } else if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    }
  }

  return result;
}

void Solve() {
  Input();

  sort(arr.begin(), arr.end());

  for (int i = 0; i < N; i++) {
    int index = modified_binary_search(i + 1, N - 1, -arr[i]);

    // index==N라면: target보다 큰 원소값이 없다는 뜻.
    // index: target 값보다 큰 값들 중 가장 작은 원소의 index
    // index-1, index가 target에 가장 가까운 값들임 -> 이 두 개 후보 중 target에 가까운 값을 사용

    if (index != N && abs(arr[i] + arr[index]) < low_diff) {
      result_val1 = arr[i];
      result_val2 = arr[index];
      low_diff = abs(arr[i] + arr[index]);
    }

    if (i != index - 1 && abs(arr[i] + arr[index - 1]) < low_diff) {
      result_val1 = arr[i];
      result_val2 = arr[index - 1];
      low_diff = abs(arr[i] + arr[index - 1]);
    }
  }

  cout << result_val1 << " " << result_val2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}