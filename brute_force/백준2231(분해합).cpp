#include<iostream>

using namespace std;

void solution(int& input);

void input(int& input) {
	cin >> input;
}

void solution(int& input) {
	int sum = 0;						//합
	for (int i = 0; i < input; i++) {	//범위는 0부터 입력값까지

		int temp = i;					//임시값인 temp에 i를 넣어준다.
		sum += temp;					//원래 수 더해준 후
		while (temp > 0) {				//각 자리 수 더해준다.
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == input) {				//만약 생성자라면
			cout << i;					//출력후 return
			return;
		}
		else                            //아니면 sum=0으로 초기화
			sum = 0;
			
	}
	cout << 0;							//반복문 빠져나온거면
	return;								//생성자가 없는것이므로 0출력
}



int main() {			
	int in = 0;
	input(in);
	solution(in);

}