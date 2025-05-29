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

< 1654 - 랜선 자르기 >

집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 

때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 

그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 

이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 

그리고 항상 K <= N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 2^31-1보다 작거나 같은 자연수이다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

문제의 조건이 구간 안에서의 최댓값을 구하는 것이기 때문에 일반적인 이분 탐색 알고리즘과 약간 다른 알고리즘을 사용. numberOfLANs = N 이어도

해당 조건을 만족하는 더 큰 수를 찾아야 하기 때문에 크거나 같아도 계속 탐색하고, left > right 이라면 right 값이 문제의 조건을 만족하는 값이므로 right를 반환.

*/


int K, N;
ll sum = 0;
vector<int> LAN;

int numberOfLANs(int length) {
    int cnt = 0;

    for (int i = 0; i < LAN.size(); i++) {
        cnt += LAN[i] / length;
    }

    return cnt;
}

ll binarySearch(ll left, ll right) {
    if (left > right) 
        return right;
    
    ll mid = left + (right- left) / 2;

    if (numberOfLANs(mid) < N)
        return binarySearch(left, mid - 1);
    else 
        return binarySearch(mid + 1, right);
}

int main() {
    PRESET;

    cin >> K >> N;
    LAN.resize(K);

    for (int i = 0; i < K; i++) {
        cin >> LAN[i];
        sum += LAN[i];
    }

    ll max_LAN = sum / N;

    cout << binarySearch(1, max_LAN);

    return 0;
}
