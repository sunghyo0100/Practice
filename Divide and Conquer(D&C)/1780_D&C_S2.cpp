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

< 1780 - 종이의 개수 >

N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

(1) 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(2) (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.

이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

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
