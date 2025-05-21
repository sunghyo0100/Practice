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

< 1733 - ��ī�̶��� >

N���� ���簢�� ����� �ǹ����� �־����� ��, ��ī�̶����� ���س��� ���α׷��� �ۼ��Ͻÿ�. ��ī�̶����� �ǹ� ��ü�� ������ �ǹ��Ѵ�. 

��, ������ �ǹ��� ���簢������ ǥ������ ��, �׷��� ���簢������ �������� ���ϴ� �����̴�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� �ǹ��� ���� N(1 �� N �� 100,000)�� �־�����. ���� N���� �ٿ��� N���� �ǹ��� ���� ������ �־�����. �ǹ��� ���� ������ �� ���� L, H, R�� ��Ÿ���µ�, 

���� �ǹ��� ���� x��ǥ, ����, ������ x��ǥ�� �ǹ��Ѵ�. (1 �� L < R �� 1,000,000,000, 1 �� H �� 1,000,000,000)

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� ��ī�̶����� ����Ѵ�. ����� �� ������ ���̰� ���ϴ� ������ ���ؼ�, �� ������ x��ǥ�� �� ���������� ���̸� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

(���� x ��ǥ, ����) �� (�� x ��ǥ, ����) �� ���� ������ ����ü�� �����Ͽ� ����.

sort���� operator< �Լ��� ���ǹǷ�, operator< �Լ��� ���ǿ� �°� ������(overload) ��.

�Լ� �� ���ڰ� ������ ���ɼ��� ���� ��쿡�� ��ȣ �ڿ� const Ű���带 �ۼ������ν� ������ ������ ���ٴ� ���� Ȯ���� �˸�.

�� ��ǥ���� �ְ� ���̸� ������ ����Ϸ��� ����� �ƴ϶�, ���ο� �ǹ��� �Էµ� ������ ���̸� �����ϴ� multiset�� �߰��ϰ�,

�ش� �ǹ��� �� x ��ǥ �̺�Ʈ�� ������ �� erase�� find �Լ��� �̿��Ͽ� �ش� ���̸� ������.

�� ����Ŭ���� multiset�� �ִ��� ���Ͽ� ��ī�̶����� ���̸� ���Ͽ� ���. (sort�� ���ĵǾ��ֱ� ������ rbegin()�� �ִ��� ��.)

*/

int N;

struct Event {
    int x, h;
    bool is_start;

    Event(int _x, int _h, bool _is_start) : x(_x), h(_h), is_start(_is_start) {}

    bool operator<(const Event& e) const {
        if (x != e.x) 
            return x < e.x;

        if (is_start != e.is_start) 
            return is_start;

        if (is_start)
            return h > e.h;
        else
            return h < e.h;
    }
};

int main() {
    PRESET;

    vector<Event> events;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int L, H, R;
        cin >> L >> H >> R;
        events.emplace_back(L, H, true);
        events.emplace_back(R, H, false);
    }

    sort(events.begin(), events.end());

    multiset<int> heights;
    heights.insert(0);

    int prevMax = 0;

    vector<pair<int, int>> result;

    for (auto& e : events) {
        if (e.is_start) {
            heights.insert(e.h);
        }
        else {
            heights.erase(heights.find(e.h));
        }
    
        int currMax = *heights.rbegin();
        if (currMax != prevMax) {
            result.emplace_back(e.x, currMax);
            prevMax = currMax;
        }
    }

    for (pair<int, int> res : result) {
        cout << res.first << " " << res.second << " ";
    }
    cout << '\n';

    return 0;
}
