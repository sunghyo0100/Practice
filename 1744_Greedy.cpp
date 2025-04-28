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

int N;
int A[MAX];
int result = 0;

int main() {
	PRESET;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

    sort(A, A + N);

    int i = 0;
    
    while (i < N && A[i] <= 0) { 
        if (i + 1 < N && A[i + 1] <= 0) {
            result += A[i] * A[i + 1];
            i += 2;
        }
        else {
            result += A[i];
            i++;
        }
    }

    while (i < N && A[i] == 1) {
        result += 1;
        i++;
    }

    sort(A + i, A + N, greater<>());

    while (i < N) {
        if (i + 1 < N) {
            result += A[i] * A[i + 1];
            i += 2;
        }
        else {
            result += A[i];
            i++;
        }
    }

    cout << result;

	return 0;
}


