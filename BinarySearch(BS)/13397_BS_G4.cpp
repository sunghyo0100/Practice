#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

typedef long long ll;
using namespace std;

#define PRESET cin.tie(NULL); ios::sync_with_stdio(false);
#define debug(x) cout << #x << " = " << x << '\n';

/*

< 13397 - 구간 나누기 2 >

N개의 수로 이루어진 1차원 배열이 있다. 이 배열을 M개 이하의 구간으로 나누어서 구간의 점수의 최댓값을 최소로 하려고 한다. 구간은 다음과 같은 조건을 만족해야 한다.

- 하나의 구간은 하나 이상의 연속된 수들로 이루어져 있다.
- 배열의 각 수는 모두 하나의 구간에 포함되어 있어야 한다.
- 구간의 점수란 구간에 속한 수의 최댓값과 최솟값의 차이이다.

예를 들어, 배열이 [1, 5, 4, 6, 2, 1, 3, 7] 이고, M = 3인 경우가 있다.

이때, [1, 5], [4, 6, 2], [1, 3, 7]로 구간을 나누면 각 구간의 점수는 4, 4, 6점이 된다. 이때, 최댓값은 6점이다.

만약, [1, 5, 4], [6, 2, 1], [3, 7]로 구간을 나누었다면, 각 구간의 점수는 4, 5, 4점이 되고, 이때 최댓값은 5점이 된다.

두 경우 중에서 최댓값이 최소인 것은 5점인 것이고, 5점보다 최댓값을 작게 만드는 방법은 없다.

배열과 M이 주어졌을 때, 구간의 점수의 최댓값의 최솟값을 구하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 배열의 크기 N과 M이 주어진다. (1 ≤ N ≤ 5,000, 1 ≤ M ≤ N)

둘째 줄에 배열에 들어있는 수가 순서대로 주어진다. 배열에 들어있는 수는 1보다 크거나 같고, 10,000보다 작거나 같은 자연수이다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 구간의 점수의 최댓값의 최솟값을 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

구간의 점수(최댓값 - 최솟값)의 최댓값의 최솟값을 구하는 복잡한 문제. 구하고자 하는 (최댓값 - 최솟값)이 움직여야 할 대상.

구간에서 현재 (최댓값 - 최솟값) 으로 정한 값보다 큰 값이 있을 때는 구간을 새로 생성하는 방식으로 풀어야 하고,

이렇게 해서 생긴 구간이 M보다 작은 경우에 true를 리턴. 구간의 범위에 따라 T값을 조절하여 찾음.

*/


int N, M;
vector<int> arr;

bool canDivide(int T) {
    int group_cnt = 1;
    int cur_max = arr[0], cur_min = arr[0];

    for (int i = 1; i < N; i++) {
        cur_max = max(cur_max, arr[i]);
        cur_min = min(cur_min, arr[i]);

        if (cur_max - cur_min > T) {
            group_cnt++;
            cur_max = arr[i];
            cur_min = arr[i];
        }
    }

    return group_cnt <= M;
}

/*
int binarySearch(int left, int right) {
    if (left > right)
        return left;

    int mid = (left + right) / 2;

    if (canDivide(mid))
        return binarySearch(left, mid - 1);
    else
        return binarySearch(mid + 1, right);
}
*/

int main() {
    PRESET;

    cin >> N >> M;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
    int result = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;

        if (canDivide(mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result;

    return 0;
}
