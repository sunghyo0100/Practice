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

< 11650 - 좌표 정렬하기 >

2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.

(-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >



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
