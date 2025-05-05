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

< 12970 - AB >

정수 N과 K가 주어졌을 때, 다음 두 조건을 만족하는 문자열 S를 찾는 프로그램을 작성하시오.

- 문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
- 문자열 S에는 0 ≤ i < j < N 이면서 s[i] == 'A' && s[j] == 'B'를 만족하는 (i, j) 쌍이 K개가 있다.

----------------------------------------------------------------------

첫째 줄에 N과 K가 주어진다. (2 ≤ N ≤ 50, 0 ≤ K ≤ N(N-1)/2)

*/

int N, K;
string S;

int main() {
    PRESET;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        if (i < N / 2)
            S += 'A';
        else 
            S += 'B';
    }
    
    int pair_max = (N % 2 == 0) ? (N / 2) * (N / 2) : (N / 2) * (N - (N / 2)) ;
    
    if (K > pair_max) {
        cout << -1;
        return 0;
    }
    
    int pair = pair_max;
    int A_idx = (N / 2) - 1;
    int dist = (N + 1) / 2;

    while (pair > K) {
        int diff = pair - K;

        if (diff > dist) {
            char temp = S[A_idx];
            S[A_idx] = S[A_idx + dist];
            S[A_idx + dist] = temp;
            pair -= dist;
            A_idx--;
        }
        else {
            char temp = S[A_idx];
            S[A_idx] = S[A_idx + diff];
            S[A_idx + diff] = temp;
            pair -= diff;
        }
    }

    cout << S;

    return 0;
}
