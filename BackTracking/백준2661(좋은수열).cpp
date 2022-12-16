#include<iostream>
#include<vector>
//for string.compare()
#include<string>

using namespace std;
int N=0;
vector<char> num;
bool didPrinted = false;

void Input() {
	cin >> N;
}

/// <summary>
/// N이 좋은 수열인지 판단하는 함수
/// </summary>
/// <param name="판단할 숫자 (N)"></param>
/// <param name="어디부터 판단할건지 (offset)"></param>
/// <returns>N이 좋은 수열이면 true, 나쁜 수열이면 false </returns>
bool isGoodNum(vector<char>& num,int offset) {
	//num의 사이즈를 저장
	int N = num.size();
	//num의 사이즈가 1일시 비교할게없으므로 바로 true
	if (N == 1) return true;
	//offset이 벡터의 사이즈면 true 리턴
	if (offset == N) return true;

	//i는 비교할 앞,뒤 인접수열의 사이즈
	for (int i = 1; i <= N; i++) {
		//인접수열에서 앞수열, 뒷수열
		string front = "", back = "";
		//비교할 원소의 갯수보다 비교할 사이즈가 더커버리면 반복문 탈출
		if ((N-offset) < i*2) break;
		//offset부터 i개의 수를 앞수열에 저장
		for (int j = offset; j < offset + i; j++) {
			front += num[j];
		}
		//그다음 범위인 offset+i부터  i개의 수를 뒷수열에 저장후
		for (int j = offset + i; j < offset + 2 * i; j++) {
			back += num[j];
		}
		//string헤더의 compare함수로 비교 둘이 같다면 나쁜수열이므로 false리턴
		if (!front.compare(back)) return false;
	}
	//다음 offset부터 또 비교를 해나가서 나쁜 수열이나오면 false 리턴
	if (!isGoodNum(num, offset + 1)) return false;
	//반복문빠져나오면 true
	return true;
}

/// <summary>
/// char형으로 만든 vector에 1,2,3을 백트래킹 방식으로 추가해보며, 각 단계마다 
/// 나쁜수열로 판단되면 가지치기를 시행하여 N자리의 좋은 수열의 최소값을 출력하는 함수
/// </summary>
/// <param name="수열을 담는 char형 벡터(totNum)"></param>
/// <param name="지금 수열의 길이(length)"></param>
void MakeNum(vector<char>& totNum,int length) {

	//길이가 N이면 지금까지 담긴 수열 출력
	if (length == N) {
		for (auto iter = totNum.begin(); iter != totNum.end(); ++iter) {
			cout << *iter-'0';
		}
		//바로 탈출하기위해 didPrinted변수 true로 설정
		didPrinted = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		//int를 char형으로 바꾼후 넣어줌
		totNum.push_back(i+'0');
		//각 totNum마다 좋은수열인지 체크후 나쁜수열이면 가지치기 시행
		if (isGoodNum(totNum, 0)) {
			MakeNum(totNum, length + 1);
			//다음스텝을 방문했다가 나쁜수열이라 돌아오면 지금 넣어준값 빼주고 진행해야함
			totNum.pop_back();
		}
		else {
			//나쁜수열일시 지금 넣어준 값 빼서 초기화해주고 continue
			totNum.pop_back();
			continue;
		}
		//출력했다면 바로 탈출하기위해 return
		if (didPrinted) return;
	}
}

void Solution() {
	MakeNum(num, 0);

}

int main() {
	Input();
	Solution();
}