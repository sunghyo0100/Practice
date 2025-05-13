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

�Ѽ��� ũ�Ⱑ 2N �� 2N�� 2���� �迭�� Z������� Ž���Ϸ��� �Ѵ�. ���� ���, 2��2�迭�� ���� ��ĭ, ������ ��ĭ, ���� �Ʒ�ĭ, ������ �Ʒ�ĭ ������� �湮�ϸ� Z����̴�.

N > 1�� ���, �迭�� ũ�Ⱑ 2N-1 �� 2N-1�� 4��� �� �Ŀ� ��������� ������� �湮�Ѵ�.

N�� �־����� ��, r�� c���� �� ��°�� �湮�ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� ���� N, r, c�� �־�����.

----------------------------------------------------------------------------------------------------------------

< ��� >

r�� c���� �� ��°�� �湮�ߴ��� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

������ 4 ��� �Ͽ� ��ǥ ��ġ�� ��� �ִ����� ���� ������� ���� ������ ��踦 �������� ���ϰ�, ��ǥ ��ġ�� �ִ� ��и��� ���������� ��� ũ�⸦ �ٿ�����

���������� ��ǥ ��ġ�� �ش��ϴ� �� ���� �����ϰ� ��ͷ� ����

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
