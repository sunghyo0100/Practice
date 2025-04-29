#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define PRESET cin.tie(NULL); ios::sync_with_stdio(false);
#define debug(x) cout << #x << " = " << x << '\n';

/*

< 10610 - 30 >

��� ��, �̸��ڴ� �쿬�� ��Ÿ����� ��� N�� ���Ҵ�. �̸��ڴ� 30�̶� ���� �����ϱ� ������, �״� ��Ÿ����� ã�� ���� ���Ե� ���ڵ��� ���� 

30�� ����� �Ǵ� ���� ū ���� ����� �;��Ѵ�.

�̸��ڸ� ���� �װ� ����� �;��ϴ� ���� ����ϴ� ���α׷��� �ۼ��϶�.

----------------------------------------------------------------------

N�� �Է¹޴´�. N�� �ִ� 105���� ���ڷ� �����Ǿ� ������, 0���� �������� �ʴ´�.

*/


string N;   // N�� 10^5 �ڸ� �̹Ƿ� ���ڿ��� �Է¹���
vector<int> digit;

int main() {
    PRESET;

    cin >> N;

    for (char c : N) {
        digit.push_back(c - '0');
    }

    int digit_sum = 0;
    for (int d : digit) {
        digit_sum += d;
    }

    sort(digit.rbegin(), digit.rend());


    // ���ڸ��� 0 : 2�� ����̸鼭 5�� ���
    // ��� �ڸ����� ���� 3�� ��� : 3�� ��� �̹Ƿ� ���ڸ��� 0�̸鼭 ��� �ڸ����� ���� 3�� ����̸� 30�� ���

    string ans = "";
    if (digit[digit.size() - 1] == 0 && digit_sum % 3 == 0) {   
        for (int i = 0; i < digit.size(); i++) {
            ans += (digit[i] + '0');
        }
    }
    else {
        ans = "-1";
    }

    cout << ans;

    return 0;
}
