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

< 1733 - 스카이라인 >

N개의 직사각형 모양의 건물들이 주어졌을 때, 스카이라인을 구해내는 프로그램을 작성하시오. 스카이라인은 건물 전체의 윤곽을 의미한다. 

즉, 각각의 건물을 직사각형으로 표현했을 때, 그러한 직사각형들의 합집합을 구하는 문제이다.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 건물의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 N개의 건물에 대한 정보가 주어진다. 건물에 대한 정보는 세 정수 L, H, R로 나타나는데, 

각각 건물의 왼쪽 x좌표, 높이, 오른쪽 x좌표를 의미한다. (1 ≤ L < R ≤ 1,000,000,000, 1 ≤ H ≤ 1,000,000,000)

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 스카이라인을 출력한다. 출력을 할 때에는 높이가 변하는 지점에 대해서, 그 지점의 x좌표와 그 지점에서의 높이를 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

(시작 x 좌표, 높이) 와 (끝 x 좌표, 높이) 로 나눠 각각을 구조체로 선언하여 관리.

sort에는 operator< 함수가 사용되므로, operator< 함수를 조건에 맞게 재정의(overload) 함.

함수 내 인자가 변동될 가능성이 없는 경우에는 괄호 뒤에 const 키워드를 작성함으로써 변동될 여지가 없다는 것을 확실히 알림.

각 좌표마다 최고 높이를 일일이 기록하려는 방법이 아니라, 새로운 건물이 입력될 때마다 높이를 저장하는 multiset에 추가하고,

해당 건물의 끝 x 좌표 이벤트를 만났을 때 erase와 find 함수를 이용하여 해당 높이를 제거함.

매 사이클마다 multiset의 최댓값을 구하여 스카이라인의 높이를 구하여 출력. (sort로 정렬되어있기 때문에 rbegin()이 최댓값이 됨.)

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
