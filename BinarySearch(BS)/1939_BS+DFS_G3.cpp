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

< 1939 - 중량제한 >

N(2 ≤ N ≤ 10,000)개의 섬으로 이루어진 나라가 있다. 이들 중 몇 개의 섬 사이에는 다리가 설치되어 있어서 차들이 다닐 수 있다.

영식 중공업에서는 두 개의 섬에 공장을 세워 두고 물품을 생산하는 일을 하고 있다. 물품을 생산하다 보면 공장에서 다른 공장으로 생산 중이던 물품을 

수송해야 할 일이 생기곤 한다. 그런데 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다. 만약 중량제한을 초과하는 양의 물품이 

다리를 지나게 되면 다리가 무너지게 된다. 한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값을 구하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 N, M(1 ≤ M ≤ 100,000)이 주어진다. 다음 M개의 줄에는 다리에 대한 정보를 나타내는 세 정수 A, B(1 ≤ A, B ≤ N), C(1 ≤ C ≤ 1,000,000,000)가 주어진다. 

이는 A번 섬과 B번 섬 사이에 중량제한이 C인 다리가 존재한다는 의미이다. 서로 같은 두 섬 사이에 여러 개의 다리가 있을 수도 있으며, 모든 다리는 양방향이다. 

마지막 줄에는 공장이 위치해 있는 섬의 번호를 나타내는 서로 다른 두 정수가 주어진다. 공장이 있는 두 섬을 연결하는 경로는 항상 존재하는 데이터만 입력으로 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄에 답을 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >

이분 탐색 과 BFS(DFS)가 결합된 문제.

이분 탐색을 통해 무게를 정하고 해당 무게일 때 BFS를 이용해 목적지에 도착할 수 있는지를 확인하고, 도착할 수 있다면 무게 여유가 있다는 뜻이므로

무게를 올려 도착할 수 있는지 확인하고, 도착할 수 없다면 무게 여유가 없다는 뜻이므로 무게를 내려 도착할 수 있는지 확인하여

도착할 수 있는 가장 큰 무게를 찾는다.

*/

int N, M;
int departure, arrival;
vector<vector<pair<int, int>>> graph;

bool canTransportProduct(int weight) {
    queue<int> q;
    bool visited[10001] = { false };
    q.push(departure);
    visited[departure] = true;

    while (!q.empty()) {
        int curFactory = q.front();
        q.pop();
        
        if (curFactory == arrival) {
            return true;
        }

        for (int i = 0; i < graph[curFactory].size(); i++) {
            int nextFactory = graph[curFactory][i].first;
            int nextWeightLimit = graph[curFactory][i].second;
            
            if (!visited[nextFactory] && weight <= nextWeightLimit) {
                q.push(nextFactory);
                visited[nextFactory] = true;
            }
        }
    }

    return false;
}

ll binarySearch(int left, int right) {
    if (left > right)
        return right;

    ll mid = (left + right) / 2;
    
    if (canTransportProduct(mid)) 
        return binarySearch(mid + 1, right);
    else 
        return binarySearch(left, mid - 1);
}

int main() {
    PRESET;

    cin >> N >> M;  
    graph.resize(N + 1);

    int maxWeightLimit = 0;

    for (int i = 0; i < M; i++) {
        int start, end, weightLimit;
        cin >> start >> end >> weightLimit;
        maxWeightLimit = max(maxWeightLimit, weightLimit);
        graph[start].push_back({ end, weightLimit });
        graph[end].push_back({ start, weightLimit });
    }
    
    cin >> departure >> arrival;
    
    cout << binarySearch(1, maxWeightLimit);

    return 0;
}
