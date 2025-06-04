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

< 1939 - �߷����� >

N(2 �� N �� 10,000)���� ������ �̷���� ���� �ִ�. �̵� �� �� ���� �� ���̿��� �ٸ��� ��ġ�Ǿ� �־ ������ �ٴ� �� �ִ�.

���� �߰��������� �� ���� ���� ������ ���� �ΰ� ��ǰ�� �����ϴ� ���� �ϰ� �ִ�. ��ǰ�� �����ϴ� ���� ���忡�� �ٸ� �������� ���� ���̴� ��ǰ�� 

�����ؾ� �� ���� ����� �Ѵ�. �׷��� ������ �ٸ����� �߷������� �ֱ� ������ ���δ�� ��ǰ�� �ű� �� ����. ���� �߷������� �ʰ��ϴ� ���� ��ǰ�� 

�ٸ��� ������ �Ǹ� �ٸ��� �������� �ȴ�. �� ���� �̵����� �ű� �� �ִ� ��ǰ���� �߷��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� N, M(1 �� M �� 100,000)�� �־�����. ���� M���� �ٿ��� �ٸ��� ���� ������ ��Ÿ���� �� ���� A, B(1 �� A, B �� N), C(1 �� C �� 1,000,000,000)�� �־�����. 

�̴� A�� ���� B�� �� ���̿� �߷������� C�� �ٸ��� �����Ѵٴ� �ǹ��̴�. ���� ���� �� �� ���̿� ���� ���� �ٸ��� ���� ���� ������, ��� �ٸ��� ������̴�. 

������ �ٿ��� ������ ��ġ�� �ִ� ���� ��ȣ�� ��Ÿ���� ���� �ٸ� �� ������ �־�����. ������ �ִ� �� ���� �����ϴ� ��δ� �׻� �����ϴ� �����͸� �Է����� �־�����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٿ� ���� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

�̺� Ž�� �� BFS(DFS)�� ���յ� ����.

�̺� Ž���� ���� ���Ը� ���ϰ� �ش� ������ �� BFS�� �̿��� �������� ������ �� �ִ����� Ȯ���ϰ�, ������ �� �ִٸ� ���� ������ �ִٴ� ���̹Ƿ�

���Ը� �÷� ������ �� �ִ��� Ȯ���ϰ�, ������ �� ���ٸ� ���� ������ ���ٴ� ���̹Ƿ� ���Ը� ���� ������ �� �ִ��� Ȯ���Ͽ�

������ �� �ִ� ���� ū ���Ը� ã�´�.

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
