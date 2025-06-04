#include <iostream>
#include <cmath>
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

< 2022 - ��ٸ� >

�Ʒ��� �׸��� ���� ���� ���� ���̸� ���� ���� ���� ���ִ�. �� ���� ��ٸ��� �ִµ� ���̰� x�� ��ٸ��� ������ ������ �Ʒ��� ��ħ��� �Ͽ� 

���� ������ ����� �ְ� ���̰� y�� ��ٸ��� ���� ������ �Ʒ��� ��ħ��� �Ͽ� ������ ������ ����� �ִ�. �׸��� �� ��ٸ��� ���������� 

��Ȯ�ϰ� c�� �������� ���� �����Ѵ�. �׷��ٸ� �� ������ �󸶳� ������ �ִ� �ɱ�?

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù° �ٿ� ���ʴ�� x, y, c�� �ش��ϴ� ���� �Ǽ� �� ���� �Էµȴ�. ���� �Ҽ��� ����° �ڸ����� �־��� �� ������, 3,000,000,000���� �۰ų� ����.

----------------------------------------------------------------------------------------------------------------

< ��� >

�� �������̿� �ʺ� �Ǵ� ��ġ�� ����Ѵ�. ����/��� ������ 10^-3���� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

������ ����ߴ� �̺� Ž������ �ٸ��� �Ǽ��� ����ϴ� �̺� Ž���̴�. Ư¡���δ� ���Ǵ� ���� ���� ������ return �Ѵٴ� ���̴�.

��Ÿ��� ������ �ﰢ���� ������ �̿��� f(d) = c �÷� ����� ������ �߿��ϰ�, d�� Ŀ���� f(d)�� �۾����� d�� �۾����� f(d)�� Ŀ���ٴ� ����

�����Ͽ� f(mid)�� c�� �ε�ȣ ���踦 �����ؾ� �Ѵ�.

*/


double x, y, c;

double f(double d) {
    if (d >= x || d >= y) return 0.0;

    double h1 = sqrt(x * x - d * d);
    double h2 = sqrt(y * y - d * d);
    return (h1 * h2) / (h1 + h2);
}

double binarySearch(double left, double right) {
    double mid = (left + right) / 2.0;

    if (right - left < 1e-6)
        return mid;

    if (f(mid) < c)
        return binarySearch(left, mid);
    else
        return binarySearch(mid, right);
}

int main() {
    PRESET;

    cin >> x >> y >> c;
    
    double min_d = 0.0;
    double max_d = min(x, y);
    
    cout.precision(10);
    cout << fixed << binarySearch(min_d, max_d);
     
    return 0;
}
