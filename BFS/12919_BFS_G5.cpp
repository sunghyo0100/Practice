
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

< 12919 - A�� B 2 >

�����̴� A�� B�θ� �̷���� ���� �ܾ� �����Ѵٴ� ��ǿ� �����. ��ǥ���� ���� AB (Abdominal�� ����), BAA (���� ���� �Ҹ�), AA (����� ����), ABBA (������ �� �׷�)�� �ִ�.

�̷� ��ǿ� ��� �����̴� ������ ������ ������ �ߴ�. �� ���ڿ� S�� T�� �־����� ��, S�� T�� �ٲٴ� �����̴�. ���ڿ��� �ٲ� ���� ������ ���� �� ���� ���길 �����ϴ�.

- ���ڿ��� �ڿ� A�� �߰��Ѵ�.
- ���ڿ��� �ڿ� B�� �߰��ϰ� ���ڿ��� �����´�.

�־��� ������ �̿��ؼ� S�� T�� ���� �� �ִ��� ������ �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�

------------------------------------------------------------------------------------------------------

�Է� - ù° �ٿ� S�� ��° �ٿ� T�� �־�����. (1 �� S�� ���� �� 49, 2 �� T�� ���� �� 50, S�� ���� < T�� ����)

��� - S�� T�� �ٲ� �� ������ 1�� ������ 0�� ����Ѵ�.

*/

string S, T;

void bfs() {
    queue<string> q;
    q.push(T);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur == S) {
            cout << 1;
            return;
        }

        if (cur.back() == 'A') {
            string next = cur;
            next.pop_back();
            q.push(next);
        }

        if (cur.front() == 'B') {
            string next = cur;
            reverse(next.begin(), next.end());
            next.pop_back();
            q.push(next);
        }
    }

    cout << 0;
}

int main() {
    PRESET;
    
    cin >> S >> T;

    bfs();

    return 0;
}
