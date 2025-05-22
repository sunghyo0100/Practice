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

< 11650 - ��ǥ �����ϱ� >

2���� ��� ���� �� N���� �־�����. ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����.

(-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >



*/

int N;

struct Point {
    int x, y;

    bool operator<(const Point& p) const {
        if (x != p.x)
            return x < p.x;
        else
            return y < p.y;
    }
};

int main() {
    PRESET;

    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end());

    for (Point p : points) {
        cout << p.x << ' ' << p.y << '\n';
    }

    return 0;
}
