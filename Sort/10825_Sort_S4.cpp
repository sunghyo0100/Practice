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

< 10825 - ������ >

�����̳� �� �л� N���� �̸��� ����, ����, ���� ������ �־�����. �̶�, ������ ���� �������� �л��� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1. ���� ������ �����ϴ� ������
2. ���� ������ ������ ���� ������ �����ϴ� ������
3. ���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
4. ��� ������ ������ �̸��� ���� ������ �����ϴ� ������ (��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� �����̳� ���� �л��� �� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� �� �ٿ� �ϳ��� �� �л��� �̸�, ����, ����, ���� ������ �������� ������ �־�����. 

������ 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�. �̸��� ���ĺ� ��ҹ��ڷ� �̷���� ���ڿ��̰�, ���̴� 10�ڸ��� ���� �ʴ´�.

----------------------------------------------------------------------------------------------------------------

< ��� >

������ �����ִ� ���� �������� ������ �� ù° �ٺ��� N���� �ٿ� ���� �� �л��� �̸��� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >



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
