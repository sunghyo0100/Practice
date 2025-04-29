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

어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 

30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

----------------------------------------------------------------------

N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

*/


string N;   // N은 10^5 자리 이므로 문자열로 입력받음
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


    // 끝자리가 0 : 2의 배수이면서 5의 배수
    // 모든 자리수의 합이 3의 배수 : 3의 배수 이므로 끝자리가 0이면서 모든 자리수의 합이 3의 배수이면 30의 배수

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
