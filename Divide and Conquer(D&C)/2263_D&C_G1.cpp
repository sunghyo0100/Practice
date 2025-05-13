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

< 2263 - Ʈ���� ��ȸ >

n���� ������ ���� ���� Ʈ���� ������ 1���� n������ ��ȣ�� �ߺ� ���� �Ű��� �ִ�. �̿� ���� ���� Ʈ���� �ο����� ����Ʈ������ �־����� ��, ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� n(1 �� n �� 100,000)�� �־�����. ���� �ٿ��� �ο����� ��Ÿ���� n���� �ڿ����� �־�����, �� ���� �ٿ��� ���� ������ ����Ʈ������ �־�����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� ���������� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

- unordered_map �� ����Ͽ� root�� �ε����� O(1)�� �ð����⵵�� ã��

- ��� �Լ��� ���ڷ� ���� ��ü�� �ѱ�� �޸� �ʰ� -> �ε����� �ѱ�� (!�߿�!)

- ���ڷ� ���۰� �� �ε����� �ѱ�� ������ ���� ������ Ư�� ���� ���� �����ϴ� ���� �ƴ� "����"�� �����ؾ� �� (!�߿�!)

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
