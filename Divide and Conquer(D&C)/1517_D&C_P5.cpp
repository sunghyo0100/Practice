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

< 1517 - ���� ��Ʈ >

N���� ���� �̷���� ���� A[1], A[2], ��, A[N]�� �ִ�. �� ������ ���ؼ� ���� ��Ʈ�� ������ ��, Swap�� �� �� �� �߻��ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

���� ��Ʈ�� ���� ������ �ִ� �� ���� �ٲ㰡�� �����ϴ� ����̴�. ���� ��� ������ 3 2 1 �̾��ٰ� ����. �� ��쿡�� ������ �ִ� 3, 2�� �ٲ��� �ϹǷ� 2 3 1 �� �ȴ�. 

�������δ� 3, 1�� �ٲ��� �ϹǷ� 2 1 3 �� �ȴ�. �������� 2, 1�� �ٲ��� �ϹǷ� 1 2 3 �� �ȴ�. �׷��� �� �̻� �ٲ�� �� ��찡 �����Ƿ� ������ �Ϸ�ȴ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� N(1 �� N �� 500,000)�� �־�����. ���� �ٿ��� N���� ������ A[1], A[2], ��, A[N]�� �־�����. ������ A[i]�� 0 �� |A[i]| �� 1,000,000,000�� ������ ����ִ�.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� Swap Ƚ���� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

���� ����(Merge sort)�� �̿��ϴ� ������, ��ü �迭�� ��� �ε��� �������� ������ ������(left, right) ������ �迭�� ������ ��, 

�� �迭�� ���ҵ鳢�� ���ذ��� ���� Ư�� ���� �迭�� ���Ұ� ������ �迭 ���Һ��� �۴ٸ� ������ �迭�� ���� ���ҿ� ��� ��, 

�׷��� ������ ���� �迭�� ���� ��� ���� ������ �迭�� �ε����� �ش��ϴ� ������ ũ�Ƿ� mid - i + 1 ���� �������� �ѹ��� ����ϴ� �˰����� �߿�

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
