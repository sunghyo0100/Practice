#include <iostream>
#include <cmath>
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

< 2022 - 사다리 >

아래의 그림과 같이 높은 빌딩 사이를 따라 좁은 길이 나있다. 두 개의 사다리가 있는데 길이가 x인 사다리는 오른쪽 빌딩의 아래를 받침대로 하여 

왼쪽 빌딩에 기대져 있고 길이가 y인 사다리는 왼쪽 빌딩의 아래를 받침대로 하여 오른쪽 빌딩에 기대져 있다. 그리고 두 사다리는 땅에서부터 

정확하게 c인 지점에서 서로 교차한다. 그렇다면 두 빌딩은 얼마나 떨어져 있는 걸까?

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 차례대로 x, y, c에 해당하는 양의 실수 세 개가 입력된다. 수는 소수점 여섯째 자리까지 주어질 수 있으며, 3,000,000,000보다 작거나 같다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

두 빌딩사이에 너비가 되는 수치를 출력한다. 절대/상대 오차는 10^-3까지 허용한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

정수를 사용했던 이분 탐색과는 다르게 실수를 사용하는 이분 탐색이다. 특징으로는 허용되는 오차 내에 들어오면 return 한다는 것이다.

피타고라스 정리와 삼각형의 닮음을 이용해 f(d) = c 꼴로 만드는 과정이 중요하고, d가 커지면 f(d)가 작아지고 d가 작아지면 f(d)가 커진다는 점을

생각하여 f(mid)와 c의 부등호 관계를 설정해야 한다.

*/


double x, y, c;

double f(double d) {
    if (d >= x || d >= y) return 0.0;

    double h1 = sqrt(x * x - d * d);
    double h2 = sqrt(y * y - d * d);
    return (h1 * h2) / (h1 + h2);
}

double binarySearch(double left, double right) {
    double mid = (left + right) / 2.0;

    if (right - left < 1e-6)
        return mid;

    if (f(mid) < c)
        return binarySearch(left, mid);
    else
        return binarySearch(mid, right);
}

int main() {
    PRESET;

    cin >> x >> y >> c;
    
    double min_d = 0.0;
    double max_d = min(x, y);
    
    cout.precision(10);
    cout << fixed << binarySearch(min_d, max_d);
     
    return 0;
}
