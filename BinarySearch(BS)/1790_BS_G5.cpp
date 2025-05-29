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

< 1790 - 수 이어 쓰기 2 >

1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수에서, 앞에서 k번째 자리 숫자가 어떤 숫자인지 구하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 N(1 ≤ N ≤ 100,000,000)과, k(1 ≤ k ≤ 1,000,000,000)가 주어진다. N과 k 사이에는 공백이 하나 이상 있다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 앞에서 k번째 자리 숫자를 출력한다. 수의 길이가 k보다 작아서 k번째 자리 숫자가 없는 경우는 -1을 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

getLength(x) 함수를 정의하고, 1부터 x까지 수를 이어붙였을 때의 길이를 반환. 

getLength는 자릿수를 1에서 시작하여 10씩 곱해나가면서 x가 현재 자릿수보다 큰 자릿수를 가진 수(x = 15 인데 현재 자릿수가 1) 라면 현재 자릿수의 가장 큰 수에서

가장 작은 수를  모두 이어붙인 길이를 더해주고(x = 15라면 1~9 (개수 9) * 1(자릿수)), 그렇지 않다면 (x = 15인데 현재 자릿수가 2) 현재 자릿수의 가장 작은 수부터 

x까지의 수를 이어붙인 길이를 더해준다.

이분 탐색으로 getLength(mid) >= k 인 수를 찾고, 예를 들어 10이 mid라면, 9까지의 길이를 더한 후 '1'과 '0' 중 어떤 수가 k번째 수인지 모르기 때문에, 

k - lenBefore - 1 로 해당 인덱스를 구해준다.

*/

ll getLength(int x) {
    ll len = 0;
    int digit = 1;
    int start = 1;
    
    while (start <= x) {
        int end = min(x, start * 10 - 1);
        len += (ll)(end - start + 1) * digit;
        start *= 10;
        digit++;
    }
    return len;
}

int main() {
    PRESET;

    int N;
    ll k;
    cin >> N >> k;

    int low = 1, high = N;
    int target = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (getLength(mid) >= k) {
            target = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (target == -1) {
        cout << -1 << '\n';
        return 0;
    }

    ll lenBefore = getLength(target - 1);

    string s = to_string(target);
    cout << s[k - lenBefore - 1] << '\n';

    return 0;
}
