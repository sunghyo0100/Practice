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

< 2110 - 공유기 설치 >

도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 

한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 

둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

푸는 방법은 이전의 이분 탐색 문제들과 동일하지만, 공유기의 위치가 아니라 공유기 간의 거리를 함수 인자로 설정해야한다.

*/


int N, C;
vector<int> wifi;

bool canPutWifiRouters(ll dist) {
    int idx = 0;
    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (wifi[i] - wifi[idx] >= dist) {
            idx = i;
            cnt++;
        }
    }

    return cnt >= C;
}

int binarySearch(ll left, ll right) {
    if (left > right) 
        return right;

    ll mid = (left + right) / 2;

    if (canPutWifiRouters(mid))
        return binarySearch(mid + 1, right);
    else
        return binarySearch(left, mid - 1);
}

int main() {
    PRESET;

    cin >> N >> C;
    wifi.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> wifi[i];
    }
    sort(wifi.begin(), wifi.end());
    
    ll max_dist = wifi[N - 1] - wifi[0];
    
    cout << binarySearch(1, max_dist);

    return 0;
}
