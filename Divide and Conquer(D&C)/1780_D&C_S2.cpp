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

using namespace std;

#define PRESET cin.tie(NULL); ios::sync_with_stdio(false);
#define debug(x) cout << #x << " = " << x << '\n';

/*

< 1780 - ������ ���� >

N��Nũ���� ��ķ� ǥ���Ǵ� ���̰� �ִ�. ������ �� ĭ���� -1, 0, 1 �� �ϳ��� ����Ǿ� �ִ�. �츮�� �� ����� ������ ���� ��Ģ�� ���� ������ ũ��� �ڸ����� �Ѵ�.

(1) ���� ���̰� ��� ���� ���� �Ǿ� �ִٸ� �� ���̸� �״�� ����Ѵ�.
(2) (1)�� �ƴ� ��쿡�� ���̸� ���� ũ���� ���� 9���� �ڸ���, ������ �߸� ���̿� ���ؼ� (1)�� ������ �ݺ��Ѵ�.

�̿� ���� ���̸� �߶��� ��, -1�θ� ä���� ������ ����, 0���θ� ä���� ������ ����, 1�θ� ä���� ������ ������ ���س��� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� N(1 �� N �� 37, N�� 3k ��)�� �־�����. ���� N���� �ٿ��� N���� ������ ����� �־�����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� -1�θ� ä���� ������ ������, ��° �ٿ� 0���θ� ä���� ������ ������, ��° �ٿ� 1�θ� ä���� ������ ������ ����Ѵ�.

*/

#define MAX 2187

int N;
int paper[MAX][MAX];
int minus_one_cnt, zero_cnt, one_cnt;

bool hasSameNumber(int sy, int sx, int size) {
    int temp = paper[sy][sx];
    for (int i = sy; i < sy + size; i++) {
        for (int j = sx; j < sx + size; j++) {
            if (paper[i][j] != temp) {
                return false;
            }
        }
    }
    return true;
}

void solve(int sy, int sx, int size) {
    if (hasSameNumber(sy, sx, size)) {
        if (paper[sy][sx] == -1) 
            minus_one_cnt++;
        else if (paper[sy][sx] == 0) 
            zero_cnt++;
        else 
            one_cnt++;
        
        return;
    }

    for (int i = sy; i < sy + size; i += (size / 3)) {
        for (int j = sx; j < sx + size; j += (size / 3)) {
            solve(i, j, size / 3);
        }
    }
}

int main() {
    PRESET;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << minus_one_cnt << '\n' << zero_cnt << '\n' << one_cnt;

    return 0;
}
