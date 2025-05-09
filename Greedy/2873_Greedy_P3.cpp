#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define PRESET cin.tie(NULL); ios::sync_with_stdio(false);
#define debug(x) cout << #x << " = " << x << '\n';

/*

< 2873 - 롤러코스터 >

상근이는 우리나라에서 가장 유명한 놀이 공원을 운영하고 있다. 이 놀이 공원은 야외에 있고, 다양한 롤러코스터가 많이 있다.

어느 날 벤치에 앉아있던 상근이는 커다란 황금을 발견한 기분이 들었다. 자신의 눈 앞에 보이는 이 부지를 구매해서 롤러코스터를 만든다면,

세상에서 가장 재미있는 롤러코스터를 만들 수 있다고 생각했다.

이 부지는 직사각형 모양이고, 상근이는 R행 C열의 표 모양으로 나누었다. 롤러코스터는 가장 왼쪽 위 칸에서 시작할 것이고, 가장 오른쪽 아래 칸에서 도착할 것이다.

롤러코스터는 현재 있는 칸과 위, 아래, 왼쪽, 오른쪽으로 인접한 칸으로 이동할 수 있다. 각 칸은 한 번 방문할 수 있고, 방문하지 않은 칸이 있어도 된다.

각 칸에는 그 칸을 지나갈 때, 탑승자가 얻을 수 있는 기쁨을 나타낸 숫자가 적혀있다. 롤러코스터를 탄 사람이 얻을 수 있는 기쁨은 지나간 칸의 기쁨의 합이다.

가장 큰 기쁨을 주는 롤러코스터는 어떻게 움직여야 하는지를 구하는 프로그램을 작성하시오.

------------------------------------------------------------------------------------------------------

입력 - 첫째 줄에 R과 C가 주어진다. (2 ≤ R, C ≤ 1000) 둘째 줄부터 R개 줄에는 각 칸을 지나갈 때 얻을 수 있는 기쁨이 주어진다. 이 값은 1000보다 작은 양의 정수이다.

출력 - 첫째 줄에 가장 가장 큰 기쁨을 주는 롤러코스터는 가장 왼쪽 위 칸부터 가장 오른쪽 아래 칸으로 어떻게 움직이면 되는지를 출력한다.

위는 U, 오른쪽은 R, 왼쪽은 L, 아래는 D로 출력한다. 정답은 여러 가지 일 수도 있다.

*/

// 핵심 아이디어 : 칸의 개수가 홀수면 모든 칸 방문 가능, 짝수면 한 칸 제외하고 방문 가능. 이 경우 가장 시작점 한칸 오른쪽에서 부터 시작하는 지그재그 모양의 칸들 중 
// 숫자가 가장 작은 칸 제외.

#define MAX 1001

int R, C;
int happiness[MAX][MAX];

int main() {
	PRESET;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> happiness[i][j];
		}
	}

	string move = "";
	int y = 0, x = 0;

	if (R % 2 == 0 && C % 2 == 0) {
		int min_happiness = 1001, min_x = 0, min_y = 0;

		// (i + j) % 2 == 1 인 칸 중 최소 찾기
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if ((i + j) % 2 == 1 && happiness[i][j] < min_happiness) {
					min_happiness = happiness[i][j];
					min_y = i;
					min_x = j;
				}
			}
		}

		int sy = min_y / 2 * 2;
		int ey = sy + 1;
		int sx = min_x / 2 * 2;
		int ex = sx + 1;

		// 제외할 칸을 포함한 2행에 도달하기 전 오른쪽 왼쪽 순으로 지그재그
		for (int i = 0; i < sy; i++) {
			if (i % 2 == 0)
				move += string(C - 1, 'R');
			else
				move += string(C - 1, 'L');

			if (i < R - 1)
				move += 'D';
		}

		// 제외할 칸을 포함한 2행 도달 후 제외할 칸을 포함한 2 * 2 크기의 박스 도달 전
		for (int i = 0; i < sx; i++) {
			if (i % 2 == 0)
				move += "DR";
			else
				move += "UR";
		}

		// 박스가 포함된 열에 도달
		if (min_x % 2 == 0) 
			move += "RD";
		else 
			move += "DR";
	
		// 박스가 포함된 열에 도달 후
		for (int i = ex; i < C - 1; i++) {
			if (i % 2 == 0) {
				move += "RD";
			}
			else {
				move += "RU";
			}
		}

		// 제외할 칸이 포함된 2행이 마지막이 아니라면 계속 진행
		if (ey < R - 1)
			move += 'D';

		// 제외할 칸이 포함된 2행 이후 왼쪽 오른쪽 순으로 지그재그
		for (int i = ey + 1; i < R; i++) {
			if (i % 2 == 0)
				move += string(C - 1, 'L');
			else
				move += string(C - 1, 'R');

			if (i < R - 1)
				move += 'D';
		}
	}
	else {
		if (R % 2 == 1) {
			for (int i = 0; i < R; i++) {
				if (i % 2 == 0)
					move += string(C - 1, 'R');
				else
					move += string(C - 1, 'L');

				if (i < R - 1)
					move += 'D';
			}
		}
		else if (C % 2 == 1) {
			for (int i = 0; i < C; i++) {
				if (i % 2 == 0)
					move += string(R - 1, 'D');
				else
					move += string(R - 1, 'U');

				if (i < C - 1)
					move += 'R';
			}
		}
	}

	cout << move;

	return 0;
}
