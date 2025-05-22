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

< 10814 - ���̼� ���� >

�¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. �̶�, ȸ������ ���̰� �����ϴ� ������, 

���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)

��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. ���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, 

�̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, ���̰� 100���� �۰ų� ���� ���ڿ��̴�. �Է��� ������ ������ �־�����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, ���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >



*/


int N;

struct Member {
    int age, idx;
    string name;

    bool operator<(const Member& m) const {
        if (age != m.age) {
            return age < m.age;
        }
        else {
            return idx < m.idx;
        }
    }
};


int main() {
    PRESET;

    cin >> N;
    vector<Member> members(N);

    for (int i = 0; i < N; i++) {
        members[i].idx = i;
        cin >> members[i].age >> members[i].name;
    }

    sort(members.begin(), members.end());
    
    for (Member member : members) {
        cout << member.age << ' '<< member.name << '\n';
    }

    return 0;
}
