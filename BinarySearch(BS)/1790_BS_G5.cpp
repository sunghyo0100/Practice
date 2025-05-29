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

< 1790 - �� �̾� ���� 2 >

1���� N������ ���� �̾ ���� ������ ���� ���ο� �ϳ��� ���� ���� �� �ִ�.

1234567891011121314151617181920212223...

�̷��� ������� ���ο� ������, �տ��� k��° �ڸ� ���ڰ� � �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� N(1 �� N �� 100,000,000)��, k(1 �� k �� 1,000,000,000)�� �־�����. N�� k ���̿��� ������ �ϳ� �̻� �ִ�.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� �տ��� k��° �ڸ� ���ڸ� ����Ѵ�. ���� ���̰� k���� �۾Ƽ� k��° �ڸ� ���ڰ� ���� ���� -1�� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

getLength(x) �Լ��� �����ϰ�, 1���� x���� ���� �̾�ٿ��� ���� ���̸� ��ȯ. 

getLength�� �ڸ����� 1���� �����Ͽ� 10�� ���س����鼭 x�� ���� �ڸ������� ū �ڸ����� ���� ��(x = 15 �ε� ���� �ڸ����� 1) ��� ���� �ڸ����� ���� ū ������

���� ���� ����  ��� �̾���� ���̸� �����ְ�(x = 15��� 1~9 (���� 9) * 1(�ڸ���)), �׷��� �ʴٸ� (x = 15�ε� ���� �ڸ����� 2) ���� �ڸ����� ���� ���� ������ 

x������ ���� �̾���� ���̸� �����ش�.

�̺� Ž������ getLength(mid) >= k �� ���� ã��, ���� ��� 10�� mid���, 9������ ���̸� ���� �� '1'�� '0' �� � ���� k��° ������ �𸣱� ������, 

k - lenBefore - 1 �� �ش� �ε����� �����ش�.

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
