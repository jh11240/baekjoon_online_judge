#include<iostream>
using namespace std;

int arr[21] = { 0, };									//입력값으로 주는 수열
bool check[21] = {false,};								//방문했는지 체크하는 bool형함수
int ans = 0;											//답
void input(int& amount,int& target) {					//입력값 받는 함수
	int temp = 0;
	cin >> amount >> target;
	for (int i = 0; i < amount; i++) {
		cin >> temp;
		arr[i]=(temp);

	}
}
void solution(int startIdx,int amount,int target,int sum) {	//(시작 인덱스, 배열안의 갯수,부분수열의 합, 지금까지의 합)

	if (sum == target && startIdx!=0) {						//startIdx가 0이면 안됨. 맨처음 sum에 0을 넣어주므로 
															//target이 0이면 바로 답나옴
		ans++;												//여기서 return 해버리면 혹시 뒤에 답있어도 거름
	}
	else if (startIdx >= amount) return;					//return 조건

	for (int i = startIdx; i < amount; i++) {				//startIdx부터 amount까지
		if (check[i]==false ) {								//만약 방문안한 원소라면
			check[i] = true;								//방문 표기
			sum+=arr[i];									//지금까지의 합에 더해주고
			solution(i + 1, amount, target, sum);			//지금 인덱스의 +1부터 조사
			check[i] = false;								//빠져나왔으므로 false로 바꿔야 다음 재귀때 다시 들어감
			sum -= arr[i];									//마찬가지로 빠져나왔으므로 합에서 빼져야 함.
			

		}
	}


}
void print() {
	cout << ans;
}
int main()
{
	int amount = 0, target=0;
	input(amount,target);
	solution(0, amount, target, 0);
	print();
}