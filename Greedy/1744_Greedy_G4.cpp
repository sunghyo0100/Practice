#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <unordered_set>
#define PRESET cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
#define MAX 51

using namespace std;

/*

길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다. 

어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 그리고 어떤 수를 묶게 되면, 

수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다. 예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 

하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다. 수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

*/

int N;
int A[MAX];
int result = 0;

int main() {
	PRESET;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

    sort(A, A + N);     // 오름차순 정렬

    int i = 0;
    
    // 음수 처리 (음수 짝이 있으면 곱해서 양수로 만들기)
    while (i < N && A[i] <= 0) { 
        if (i + 1 < N && A[i + 1] <= 0) {
            result += A[i] * A[i + 1];
            i += 2;
        }
        // 짝이 없는 경우 그냥 더하기
        else {
            result += A[i];
            i++;
        }
    }

    // 1은 더함
    while (i < N && A[i] == 1) {
        result += 1;
        i++;
    }

    sort(A + i, A + N, greater<>());    // 양수 부분 내림차순 정렬

    // 양수 처리 (양수 짝이 있으면 곱해서 더하기)
    while (i < N) {
        if (i + 1 < N) {
            result += A[i] * A[i + 1];
            i += 2;
        }
        // 짝이 없는 경우 그냥 더하기
        else {
            result += A[i];
            i++;
        }
    }

    cout << result;

	return 0;
}


