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

< 2110 - ������ ��ġ >

�������� �� N���� ������ ���� �ִ�. ������ ���� ��ǥ�� x1, ..., xN�̰�, �� �������� ���� ��ǥ�� ������ ���� ����.

�����̴� ���� ��𼭳� �������̸� ���� ���ؼ� ���� ������ C���� ��ġ�Ϸ��� �Ѵ�. �ִ��� ���� ������ �������̸� ����Ϸ��� �ϱ� ������, 

�� ������ �����⸦ �ϳ��� ��ġ�� �� �ְ�, ���� ������ �� ������ ������ �Ÿ��� ������ ũ�� �Ͽ� ��ġ�Ϸ��� �Ѵ�.

C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� ���� ���� N (2 �� N �� 200,000)�� �������� ���� C (2 �� C �� N)�� �ϳ� �̻��� �� ĭ�� ���̿� �ΰ� �־�����. 

��° �ٺ��� N���� �ٿ��� ���� ��ǥ�� ��Ÿ���� xi (0 �� xi �� 1,000,000,000)�� �� �ٿ� �ϳ��� �־�����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� ���� ������ �� ������ ������ �ִ� �Ÿ��� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

Ǫ�� ����� ������ �̺� Ž�� ������� ����������, �������� ��ġ�� �ƴ϶� ������ ���� �Ÿ��� �Լ� ���ڷ� �����ؾ��Ѵ�.

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
