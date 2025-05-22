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

< 2751 - �� �����ϱ� 2 >

N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. 

�� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

�Ϲ����� ����� std::sort() �Լ��� ����ص� ����ó�� ������, �Ʒ��� ���� ���� ������ �̿��ϸ� ���� ���� ������ ����.

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
