#include<iostream>
using namespace std;

int N, M, Max=0;
int inputArr[100'001];

// 입력값
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
		Max = inputArr[i] > Max ? inputArr[i] : Max;
	}
}

//한글말을 보고 이해한 건 돈을 K원 인출-> 첫날에 K보다 작은 돈이면 ->지갑에 K-첫날돈-> 둘째날에 K-첫날돈보다 작은돈이면 k-첫날돈-둘째돈  -> 셋째날에 k-첫날돈-둘1재돈보다
//크다면 새로 인출 이런식으로 이해 했는데

//2343문제와 같이 M을 맞추기 위해서 남은돈을 우겨써도 된다는 뜻인듯 

/// <summary>
/// price값을 M번 인출가능한지 여부 반환 함수
/// </summary>
/// <param name="price"></param>
bool checkIsPriceAnswer(int price) {
	//M 번 인출가능한지 확인하는 변수, 임시 가격값
	int limit = M, tmpPrice = price;

	for (int i = 0; i < N; i++) {
		if (inputArr[i] > price) {
			if (price == 500) cout << "here";
			return false;
		}
		//현재 가격보다 해당 날짜에 사용액이 더크다면
		if (inputArr[i] > tmpPrice) {
			//한번 인출 후 
			limit--;
			//limit이 음수가 되면 false 반환
			if (limit <= 0) {
				if (price == 500) cout << "here";
				return false;
			}
			//tmpPrice새로 설정
			tmpPrice = price;
		}
		tmpPrice -= inputArr[i];
	}
	////m번보다 적게 인출되면 false
	//if (limit != 0) return false;
	return true;

}

void solution() {
	int mid=0,low = 0, high = 1'000'000'000;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		(checkIsPriceAnswer(mid) ? high : low) = mid;
	}
	cout << high;


}

int main() {
	input();
	solution();
}