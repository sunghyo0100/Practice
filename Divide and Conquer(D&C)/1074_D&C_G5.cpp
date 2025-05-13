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

< 1074 - Z >

한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

N > 1인 경우, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 정수 N, r, c가 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

r행 c열을 몇 번째로 방문했는지 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

구역을 4 등분 하여 목표 위치가 어디 있는지에 따라 결과값에 현재 넓이의 몇배를 더해줄지 정하고, 목표 위치가 있는 사분면을 선택함으로 계속 크기를 줄여나가

마지막에는 목표 위치에 해당하는 한 점에 도달하게 재귀로 구현

*/

int N, r, c;
int result = 0;

void solve(int y, int x, int size) {
    if (size == 1) return;

    int half = size / 2;
    int area = half * half;

    if (r < y + half && c < x + half) {
        solve(y, x, half);
    }
    else if (r < y + half && c >= x + half) {
        result += area;
        solve(y, x + half, half);
    }
    else if (r >= y + half && c < x + half) {
        result += area * 2;
        solve(y + half, x, half);
    }
    else {
        result += area * 3;
        solve(y + half, x + half, half);
    }
}

int main() {
    PRESET;

    cin >> N >> r >> c;

    solve(0, 0, 1 << N);
    cout << result;

    return 0;
}
