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

< 13397 - ���� ������ 2 >

N���� ���� �̷���� 1���� �迭�� �ִ�. �� �迭�� M�� ������ �������� ����� ������ ������ �ִ��� �ּҷ� �Ϸ��� �Ѵ�. ������ ������ ���� ������ �����ؾ� �Ѵ�.

- �ϳ��� ������ �ϳ� �̻��� ���ӵ� ����� �̷���� �ִ�.
- �迭�� �� ���� ��� �ϳ��� ������ ���ԵǾ� �־�� �Ѵ�.
- ������ ������ ������ ���� ���� �ִ񰪰� �ּڰ��� �����̴�.

���� ���, �迭�� [1, 5, 4, 6, 2, 1, 3, 7] �̰�, M = 3�� ��찡 �ִ�.

�̶�, [1, 5], [4, 6, 2], [1, 3, 7]�� ������ ������ �� ������ ������ 4, 4, 6���� �ȴ�. �̶�, �ִ��� 6���̴�.

����, [1, 5, 4], [6, 2, 1], [3, 7]�� ������ �������ٸ�, �� ������ ������ 4, 5, 4���� �ǰ�, �̶� �ִ��� 5���� �ȴ�.

�� ��� �߿��� �ִ��� �ּ��� ���� 5���� ���̰�, 5������ �ִ��� �۰� ����� ����� ����.

�迭�� M�� �־����� ��, ������ ������ �ִ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� �迭�� ũ�� N�� M�� �־�����. (1 �� N �� 5,000, 1 �� M �� N)

��° �ٿ� �迭�� ����ִ� ���� ������� �־�����. �迭�� ����ִ� ���� 1���� ũ�ų� ����, 10,000���� �۰ų� ���� �ڿ����̴�.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� ������ ������ �ִ��� �ּڰ��� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

������ ����(�ִ� - �ּڰ�)�� �ִ��� �ּڰ��� ���ϴ� ������ ����. ���ϰ��� �ϴ� (�ִ� - �ּڰ�)�� �������� �� ���.

�������� ���� (�ִ� - �ּڰ�) ���� ���� ������ ū ���� ���� ���� ������ ���� �����ϴ� ������� Ǯ��� �ϰ�,

�̷��� �ؼ� ���� ������ M���� ���� ��쿡 true�� ����. ������ ������ ���� T���� �����Ͽ� ã��.

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
