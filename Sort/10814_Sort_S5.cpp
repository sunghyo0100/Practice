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

< 10814 - 나이순 정렬 >

온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 

나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 

이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >



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
