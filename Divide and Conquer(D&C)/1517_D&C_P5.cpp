#include <iostream>
#include <string>
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

< 1517 - 버블 소트 >

N개의 수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 이 수열에 대해서 버블 소트를 수행할 때, Swap이 총 몇 번 발생하는지 알아내는 프로그램을 작성하시오.

버블 소트는 서로 인접해 있는 두 수를 바꿔가며 정렬하는 방법이다. 예를 들어 수열이 3 2 1 이었다고 하자. 이 경우에는 인접해 있는 3, 2가 바뀌어야 하므로 2 3 1 이 된다. 

다음으로는 3, 1이 바뀌어야 하므로 2 1 3 이 된다. 다음에는 2, 1이 바뀌어야 하므로 1 2 3 이 된다. 그러면 더 이상 바꿔야 할 경우가 없으므로 정렬이 완료된다.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다. 다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다. 각각의 A[i]는 0 ≤ |A[i]| ≤ 1,000,000,000의 범위에 들어있다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 Swap 횟수를 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

병합 정렬(Merge sort)을 이용하는 문제로, 전체 배열을 가운데 인덱스 기준으로 반으로 나누어(left, right) 각각의 배열을 정렬한 후, 

두 배열의 원소들끼리 비교해가며 만약 특정 왼쪽 배열의 원소가 오른쪽 배열 원소보다 작다면 오른쪽 배열의 다음 원소와 계속 비교, 

그렇지 않으면 왼쪽 배열의 이후 모든 수가 오른쪽 배열의 인덱스에 해당하는 수보다 크므로 mid - i + 1 으로 역전수를 한번에 계산하는 알고리즘이 중요

*/

#define MAX 500001

int N;
vector<int> arr;
vector<int> temp;

ll merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    ll inv_cnt = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_cnt += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }

    return inv_cnt;
}

ll merge_sort(int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    ll inv_cnt = 0;

    inv_cnt += merge_sort(left, mid);
    inv_cnt += merge_sort(mid + 1, right);
    inv_cnt += merge(left, mid, right);

    return inv_cnt;
}

int main() {
    PRESET;

    cin >> N;

    arr.resize(N);
    temp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << merge_sort(0, N - 1);

    return 0;
}
