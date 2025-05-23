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

using namespace std;

#define PRESET cin.tie(NULL); ios::sync_with_stdio(false);
#define debug(x) cout << #x << " = " << x << '\n';

/*

< 11729 - 하노이탑 이동 순서 >

세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.

1. 한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
2. 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.

이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 옮긴 횟수 K를 출력한다.

두 번째 줄부터 수행 과정을 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 

이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.


< 재귀 핵심 아이디어 >

1. 위의 n - 1 개 원판을 A -> B 로 옮김 (B는 보조 기둥)

2. A 에 남아있는 가장 큰 원판을 C 로 옮김

3. B 에 있는 n - 1 개 원판을 C 로 옮김

- 최소 이동 횟수는 항상 2 ^ n - 1. ( T(n) = 2 * T(n - 1) + 1   =>   T(n) = 2 ^ n - 1 )

*/

int n;

void hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(n - 1, from, via, to);        // 1 에 해당
    cout << from << ' ' << to << '\n';  // 2 에 해당
    hanoi(n - 1, via, to, from);        // 3 에 해당
}

int main() {
    PRESET;

    cin >> n;

    cout << pow(2, n) - 1;

    hanoi(n, 1, 3, 2);

    return 0;
}
