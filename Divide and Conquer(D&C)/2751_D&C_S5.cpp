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

< 2751 - 수 정렬하기 2 >

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 

이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

일반적인 방식인 std::sort() 함수를 사용해도 정답처리 되지만, 아래와 같이 병합 정렬을 이용하면 좀더 빠른 동작이 가능.

*/

int N;
vector<int> arr;
vector<int> temp;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(int left, int right) {
    if (left >= right) return;
    
    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    PRESET;

    cin >> N;
    arr.resize(N);
    temp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(0, N - 1);

    for (int n : arr) {
        cout << n << '\n';
    }

    return 0;
}
