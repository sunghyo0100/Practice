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

< 2343 - ��Ÿ ���� >

����� �ڽ��� ��Ÿ ���� �������� ��緹�̷� ����� �Ǹ��Ϸ��� �Ѵ�. ��緹�̿��� �� N���� ���ǰ� ���µ�, ��緹�̸� ��ȭ�� ��, 

������ ������ �ٲ�� �� �ȴ�. ������ �ڹٲ�� ��쿡�� ������ �帧�� ����, �л����� ��ȥ���� ���� �� �ֱ� �����̴�. 

��, i�� ���ǿ� j�� ���Ǹ� ���� ��緹�̿� ��ȭ�Ϸ��� i�� j ������ ��� ���ǵ� ���� ��緹�̿� ��ȭ�ؾ� �Ѵ�.

����� �� ��緹�̰� �󸶳� �ȸ��� ���� �� �� ���� ������, ��緹���� ������ ������ ���̷��� �Ѵ�. 

���� ��� ���� ����� M���� ��緹�̿� ��� ��Ÿ ���� �������� ��ȭ�ϱ�� �ߴ�. �̶�, ��緹���� ũ��(��ȭ ������ ����)�� �ּҷ� �Ϸ��� �Ѵ�. 

��, M���� ��緹�̴� ��� ���� ũ���̾�� �Ѵ�.

������ �� ������ ���̰� �� ����(�ڿ���)�� �־�����. �̶�, ������ ��緹���� ũ�� �� �ּҸ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� ������ �� N (1 �� N �� 100,000)�� M (1 �� M �� N)�� �־�����. ���� �ٿ��� ������ ��Ÿ ������ ���̰� ���� ������� �� ������(�ڿ���)�� �־�����. 

�� ������ ���̴� 10,000���� ���� �ʴ´�.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� ������ ��緹�� ũ���� �ּҸ� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

�ٸ� �̺� Ž�� ������� ����� ������ �����̴�.

*/


int N, M;
vector<int> lessonTime;

bool canPutAllLessonsInBluerays(int max_t) {
    int cnt = 1, sum = 0;

    for (int i = 0; i < lessonTime.size(); i++) {
        if (sum + lessonTime[i] <= max_t) 
            sum += lessonTime[i];
        else {
            cnt++;
            sum = lessonTime[i];
        }
    }

    return cnt <= M;
}

int binarySearch(int low, int high) {
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPutAllLessonsInBluerays(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int main() {
    PRESET;

    cin >> N >> M;
    lessonTime.resize(N);

    int max_t = 0;
    for (int i = 0; i < N; i++) {
        cin >> lessonTime[i];
        max_t += lessonTime[i];
    }

    int min_t = *max_element(lessonTime.begin(), lessonTime.end());
    cout << binarySearch(min_t, max_t);

    return 0;
}
