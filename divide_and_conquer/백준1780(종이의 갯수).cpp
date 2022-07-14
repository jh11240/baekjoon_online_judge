#include<iostream>
#include<vector>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
vector<vector<int>> v;
vector<int> v2;
int minusOne=0, zero=0, one = 0;
void input(int& amount){
	int temp=0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		v2.clear();
		for (int j = 0; j < amount; j++) {
			cin >> temp;
			v2.push_back(temp);
		}
		v.push_back(v2);

	}


}

void solution(int x, int y, int length) {
	int temp = v[x][y];								//각 단계에서 첫값을 넣어준 후 이값과 다르면 같은 숫자로 이뤄지지 않음 판단

	if (length == 0) return;						//3으로 나눴을 때 길이 0이면 return
	for (int i = x; i < x+length; i++) {				//x부터 length가 아니라 x부터 x+length로 해야지
		for (int j = y; j < y+length; j++) {
			if (v[i][j] != temp) {					//만약 다르면 전체가 같은걸로 이뤄지지 않았으므로 재귀
				solution(x, y, length / 3);
				solution(x, y + length / 3, length / 3);
				solution(x, y + 2 * length / 3, length / 3);
				solution(x + length / 3, y, length / 3);
				solution(x + length / 3, y + length / 3, length / 3);
				solution(x + length / 3, y + 2 * length / 3, length / 3);
				solution(x + 2 * length / 3, y, length / 3);
				solution(x + 2 * length / 3, y + length / 3, length / 3);
				solution(x + 2 * length / 3, y + 2 * length / 3, length / 3);
				return;								//똑같은거로 이뤄져있는데 빠져나와서 밑에 답에 영향주는 식으로 가면 안돼!
			}
		}
	}												//빠져나왔다면 같은 것으로 이뤄져있으므로
	if (temp == 0) {
		zero++;
		return;
	}
	else if (temp == 1) {
		one++;
		return;
	}
	else
	{
		minusOne++;
		return;
	}

}

int main() {
	FAST
	int amount;
	input(amount);
	solution(0, 0, amount);
	cout << minusOne<<'\n' << zero<<'\n' << one;
}