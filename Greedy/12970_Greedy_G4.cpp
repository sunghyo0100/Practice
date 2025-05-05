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

���� N�� K�� �־����� ��, ���� �� ������ �����ϴ� ���ڿ� S�� ã�� ���α׷��� �ۼ��Ͻÿ�.

- ���ڿ� S�� ���̴� N�̰�, 'A', 'B'�� �̷���� �ִ�.
- ���ڿ� S���� 0 �� i < j < N �̸鼭 s[i] == 'A' && s[j] == 'B'�� �����ϴ� (i, j) ���� K���� �ִ�.

----------------------------------------------------------------------

ù° �ٿ� N�� K�� �־�����. (2 �� N �� 50, 0 �� K �� N(N-1)/2)

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
