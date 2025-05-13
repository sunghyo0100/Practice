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

< 2263 - 트리의 순회 >

n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 n(1 ≤ n ≤ 100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 프리오더를 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

- unordered_map 을 사용하여 root의 인덱스를 O(1)의 시간복잡도로 찾기

- 재귀 함수의 인자로 벡터 자체를 넘기면 메모리 초과 -> 인덱스만 넘기기 (!중요!)

- 인자로 시작과 끝 인덱스를 넘기기 때문에 종료 조건은 특정 값에 따라 설정하는 것이 아닌 "범위"로 설정해야 함 (!중요!)

*/

int n;
vector<int> in_order, post_order;
unordered_map<int, int> in_index;

void find_Preorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;

    int root = post_order[post_end];
    cout << root << ' ';
    
    int root_idx = in_index[root];
    int left_size = root_idx - in_start;

    find_Preorder(in_start, root_idx - 1, post_start, post_start + left_size - 1);
    find_Preorder(root_idx + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    PRESET;

    cin >> n;
    in_order.resize(n);
    post_order.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> in_order[i];
        in_index[in_order[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> post_order[i];
    }

    find_Preorder(0, n - 1, 0, n - 1);

    return 0;
}
