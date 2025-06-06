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

< 2343 - 기타 레슨 >

강토는 자신의 기타 강의 동영상을 블루레이로 만들어 판매하려고 한다. 블루레이에는 총 N개의 강의가 들어가는데, 블루레이를 녹화할 때, 

강의의 순서가 바뀌면 안 된다. 순서가 뒤바뀌는 경우에는 강의의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 

즉, i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.

강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 가급적 줄이려고 한다. 

오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 강의 동영상을 녹화하기로 했다. 이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 

단, M개의 블루레이는 모두 같은 크기이어야 한다.

강토의 각 강의의 길이가 분 단위(자연수)로 주어진다. 이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 강의의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 다음 줄에는 강토의 기타 강의의 길이가 강의 순서대로 분 단위로(자연수)로 주어진다. 

각 강의의 길이는 10,000분을 넘지 않는다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 가능한 블루레이 크기중 최소를 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

다른 이분 탐색 문제들과 비슷한 유형의 문제이다.

*/


int N, M;
vector<int> lessonTime;

bool canPutAllLessonsInBluerays(int max_t) {
    int cnt = 1, sum = 0;

    for (int i = 0; i < lessonTime.size(); i++) {
        if (sum + lessonTime[i] <= max_t) 
            sum += lessonTime[i];
        else {
            cnt++;
            sum = lessonTime[i];
        }
    }

    return cnt <= M;
}

int binarySearch(int low, int high) {
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPutAllLessonsInBluerays(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int main() {
    PRESET;

    cin >> N >> M;
    lessonTime.resize(N);

    int max_t = 0;
    for (int i = 0; i < N; i++) {
        cin >> lessonTime[i];
        max_t += lessonTime[i];
    }

    int min_t = *max_element(lessonTime.begin(), lessonTime.end());
    cout << binarySearch(min_t, max_t);

    return 0;
}
