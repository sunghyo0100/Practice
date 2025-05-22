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

< 10825 - 국영수 >

도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

1. 국어 점수가 감소하는 순서로
2. 국어 점수가 같으면 영어 점수가 증가하는 순서로
3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)

----------------------------------------------------------------------------------------------------------------

< 입력 >

첫째 줄에 도현이네 반의 학생의 수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 한 줄에 하나씩 각 학생의 이름, 국어, 영어, 수학 점수가 공백으로 구분해 주어진다. 

점수는 1보다 크거나 같고, 100보다 작거나 같은 자연수이다. 이름은 알파벳 대소문자로 이루어진 문자열이고, 길이는 10자리를 넘지 않는다.

----------------------------------------------------------------------------------------------------------------

< 출력 >

문제에 나와있는 정렬 기준으로 정렬한 후 첫째 줄부터 N개의 줄에 걸쳐 각 학생의 이름을 출력한다.

----------------------------------------------------------------------------------------------------------------

< 핵심 아이디어 >



*/


int N;

struct Student {
    string name;
    int kor, eng, math;

    bool operator<(const Student& s) const {
        if (kor != s.kor) {
            return kor > s.kor;
        }
        else {
            if (eng != s.eng) 
                return eng < s.eng;
            else {
                if (math != s.math)
                    return math > s.math;
                else
                    return name < s.name;
            }
        }
    }
};

int main() {
    PRESET;

    cin >> N;
    vector<Student> students;

    for (int i = 0; i < N; i++) {
        Student s;
        cin >> s.name >> s.kor >> s.eng >> s.math;
        students.push_back(s);
    }

    sort(students.begin(), students.end());

    for (Student student : students) {
        cout << student.name << '\n';
    }

    return 0;
}
