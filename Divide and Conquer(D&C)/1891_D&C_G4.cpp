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

using namespace std;

#define PRESET cin.tie(NULL); ios::sync_with_stdio(false);
#define debug(x) cout << #x << " = " << x << '\n';

/*

< 1891 - ��и� >

�ϳ��� ��ǥ����� �� ���� ��и����� ������.

�׷���, ������ ��и��� �ٽ� ��и����� ������ ��ȣ�� �ٿ� ���� ���? ���� ��� 1�� ��и��� 1�� ��и��� 11�� ��и�, 

3�� ��и��� 2�� ��и��� 32�� ��и��̶�� �ϸ� ���� ������? ���� �� �� �� ���� �� ���� �ְڴ�. 3�� ��и��� 4�� ��и��� 1�� ��и��� 341�� ��и��̴�.

��и��� ��ȣ ���̰� ������� ���� ������ ��и��� ũ��� �ް��� �۾�����, �� ������ ���ϱ޼������� �����Ѵ�.

��и鿡 ��ȣ�� ���̴� �̷��� ��Ģ�� �����ϰ�, � ��и� ������ �̵������� ��, �� ������ ��ġ�ϰ� �Ǵ� ��и��� ��ȣ�� �ñ��ϴ�. 

���� ���, 341�� ��и��� ���������� �� ��, �������� �� �� �̵���Ű�� 424�� ��и鿡 �´�.

�ϳ��� ��и� ������ �̵������� ��, �� ������ ������ ��и��� ��ȣ�� �˾Ƴ��� ���α׷��� �ۼ��϶�.

----------------------------------------------------------------------------------------------------------------

< �Է� >

ù �ٿ� �̵���Ű���� ��и� ���� ��ȣ�� �ڸ����� ��Ÿ���� ���� d��, �� ��и� ������ ��ȣ�� �־�����. (1 �� d �� 50) ��° �ٿ��� �̵��� ������ ��Ÿ���� 

�� ������ x, y�� �־�����. (|x|, |y| �� 250) ���������� �̵��� ��� x�� ���, �������� �̵��� ��� �����̸�, �� ������ ������ ���� ���� �̵� Ƚ���� ��Ÿ����. 

�������� �̵��� ��� y�� ���, �Ʒ������� �̵��� ��� �����̸�, ���� �� ������ �Ʒ��� ���� �̵� Ƚ���� ��Ÿ����.

----------------------------------------------------------------------------------------------------------------

< ��� >

ù �ٿ� ������ ��и��� ��ȣ�� ����Ѵ�. ����, �������� �ʴ� ��и��� ��쿡�� -1�� ����Ѵ�.

----------------------------------------------------------------------------------------------------------------

< �ٽ� ���̵�� >

�߾��� (0, 0)���� ��� x, y�� ������ [-half, half) �� �����Ͽ� Ǯ���µ�, ĭ�� ���� �Ʒ��� �������� �������� ĭ�� ��ǥ�� �����ϴ� ������ �ܰ迡�� 1��и鰰�� x �Ǵ� y�� + �� ��и鿡�� 
1��и��� ���ϱ� ���ؼ� ���ػ� ��ǥ���� ���ϸ� �ȵ����� �ڵ�� ���ؾ� �ϴ� �κ��� �־ �򰥸�.

�и� �߾��� (0, 0)���� ��� Ǫ�� ����� �����ٵ�, ���� ���� (0, 0)���� ��°� Ǯ�� ���� �� ����.

*/

int d;
long long x, y;
string num;

pair<long long, long long> get_Coordinate(string& str, int index, long long r, long long c, long long size)
{
    if (size == 1) return make_pair(r, c);
    else
    {
        if (str[index] == '1') {
            return get_Coordinate(str, index + 1, r, c + size / 2, size / 2);
        }
        else if (str[index] == '2') {
            return get_Coordinate(str, index + 1, r, c, size / 2);
        }
        else if (str[index] == '3') {
            return get_Coordinate(str, index + 1, r + size / 2, c, size / 2);
        }
        else if (str[index] == '4') {
            return get_Coordinate(str, index + 1, r + size / 2, c + size / 2, size / 2);
        }
    }
    return make_pair(0, 0);
}

string go(long long r, long long c, long long size, long long x, long long y)
{
    if (size == 1) 
        return "";
    if (x < r + size / 2 && y < c + size / 2) 
        return "2" + go(r, c, size / 2, x, y);
    else if (x < r + size / 2 && y >= c + size / 2) 
        return "1" + go(r, c + size / 2, size / 2, x, y);
    else if (x >= r + size / 2 && y < c + size / 2) 
        return "3" + go(r + size / 2, c, size / 2, x, y);
    else 
        return "4" + go(r + size / 2, c + size / 2, size / 2, x, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> num >> x >> y;

    long long size = (1LL << d);

    auto p = get_Coordinate(num, 0, 0, 0, size);

    p.first -= y;
    p.second += x;

    if (0 <= p.first && p.first < size && 0 <= p.second && p.second < size)
        cout << go(0, 0, size, p.first, p.second);
    else
        cout << "-1" << "\n";

    return 0;
}