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

< 1891 - 사분면 >

하나의 좌표평면은 네 개의 사분면으로 나뉜다.

그러면, 각각의 사분면을 다시 사분면으로 나누어 번호를 붙여 보면 어떨까? 예를 들어 1번 사분면의 1번 사분면은 11번 사분면, 

3번 사분면의 2번 사분면은 32번 사분면이라고 하면 좋지 않을까? 물론 한 번 더 나눠 볼 수도 있겠다. 3번 사분면의 4번 사분면의 1번 사분면은 341번 사분면이다.

사분면의 번호 길이가 길어짐에 따라 각각의 사분면의 크기는 급격히 작아지며, 그 개수는 기하급수적으로 증가한다.

사분면에 번호를 붙이는 이러한 규칙을 상정하고서, 어떤 사분면 조각을 이동시켰을 때, 그 조각이 위치하게 되는 사분면의 번호가 궁금하다. 

예를 들어, 341번 사분면을 오른쪽으로 두 번, 위쪽으로 한 번 이동시키면 424번 사분면에 온다.

하나의 사분면 조각을 이동시켰을 때, 그 조각이 도착한 사분면의 번호를 알아내는 프로그램을 작성하라.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫 줄에 이동시키려는 사분면 조각 번호의 자릿수를 나타내는 정수 d와, 그 사분면 조각의 번호가 주어진다. (1 ≤ d ≤ 50) 둘째 줄에는 이동의 내용을 나타내는 

두 정수가 x, y가 주어진다. (|x|, |y| ≤ 250) 오른쪽으로 이동한 경우 x가 양수, 왼쪽으로 이동한 경우 음수이며, 그 절댓값은 오른쪽 왼쪽 방향 이동 횟수를 나타낸다. 

위쪽으로 이동한 경우 y가 양수, 아래쪽으로 이동한 경우 음수이며, 역시 그 절댓값은 아래위 방향 이동 횟수를 나타낸다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫 줄에 도착한 사분면의 번호를 출력한다. 만약, 존재하지 않는 사분면인 경우에는 -1을 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

중앙을 (0, 0)으로 잡아 x, y의 범위를 [-half, half) 로 설정하여 풀었는데, 칸의 왼쪽 아래를 꼭지점을 기준으로 칸의 좌표를 설정하니 마지막 단계에서 1사분면같이 x 또는 y가 + 인 사분면에서 
1사분면을 구하기 위해선 기준상 좌표값을 더하면 안되지만 코드상 더해야 하는 부분이 있어서 헷갈림.

분명 중앙을 (0, 0)으로 잡고 푸는 방법이 있을텐데, 왼쪽 위를 (0, 0)으로 잡는게 풀기 쉬운 것 같다.

*/

int d;
long long x, y;
string num;

pair<long long, long long> get_Coordinate(string& str, int index, long long r, long long c, long long size)
{
    if (size == 1) return make_pair(r, c);
    else
    {
        if (str[index] == '1') {
            return get_Coordinate(str, index + 1, r, c + size / 2, size / 2);
        }
        else if (str[index] == '2') {
            return get_Coordinate(str, index + 1, r, c, size / 2);
        }
        else if (str[index] == '3') {
            return get_Coordinate(str, index + 1, r + size / 2, c, size / 2);
        }
        else if (str[index] == '4') {
            return get_Coordinate(str, index + 1, r + size / 2, c + size / 2, size / 2);
        }
    }
    return make_pair(0, 0);
}

string go(long long r, long long c, long long size, long long x, long long y)
{
    if (size == 1) 
        return "";
    if (x < r + size / 2 && y < c + size / 2) 
        return "2" + go(r, c, size / 2, x, y);
    else if (x < r + size / 2 && y >= c + size / 2) 
        return "1" + go(r, c + size / 2, size / 2, x, y);
    else if (x >= r + size / 2 && y < c + size / 2) 
        return "3" + go(r + size / 2, c, size / 2, x, y);
    else 
        return "4" + go(r + size / 2, c + size / 2, size / 2, x, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> num >> x >> y;

    long long size = (1LL << d);

    auto p = get_Coordinate(num, 0, 0, 0, size);

    p.first -= y;
    p.second += x;

    if (0 <= p.first && p.first < size && 0 <= p.second && p.second < size)
        cout << go(0, 0, size, p.first, p.second);
    else
        cout << "-1" << "\n";

    return 0;
}