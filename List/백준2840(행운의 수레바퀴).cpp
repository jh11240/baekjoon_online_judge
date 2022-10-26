#include<iostream>
#include<vector>
using namespace std;

int N, K, cursor=0;
//답 배열
vector<char> ans;
//입력받는 두개 값 배열
vector<pair<int, char>> inputArr;

void input() {
	//몇번 돌린건지
	int inputInt =0;
	//어떤 바퀴나왔는지
	char inputChar = ' ';
	cin >> N>> K;
	for (int i = 0; i < N; i++) {
		ans.push_back('?');
	}
	for (int i = 0; i < K; i++) {
		cin >> inputInt >> inputChar;
		inputArr.push_back(make_pair(inputInt, inputChar));
	}
}
/// <summary>
/// inputArr[index]의 문자 ans벡터에 넣어주기 
/// </summary>
/// <param name="index"></param>
/// <returns>ans벡터에 같은 문자가 있거나, 같은 자리에 다른 문자가 오게될 경우 false 나머지 true</returns>
bool setAns(int index) {
	//S 변수(바퀴 몇번 돌렸는지)
	int S=inputArr[index].first;
	//커서가 ans벡터 사이즈 넘어가면 0으로 초기화하는 부분
	for (int i = 0; i < S; i++) {
		if (cursor + 1 == ans.size())
			cursor = 0;
		else
			cursor++;
	}
	//ans의 cursor자리에 ?가 잇다면 그냥 해당 자리에 넣어줌
	if(ans[cursor]=='?')
	ans[cursor] = inputArr[index].second;
	//만약 cursor자리에 다른 문자가 이미 들어가 있다면 false return해서 ! 출력
	else if(ans[cursor]!= inputArr[index].second)
	{
		return false;
	}
	//cursor자리 제외하고 나머지 칸에 다른 문자 들어가 있다면 false 리턴해서 ! 출력
	for (int i = 0; i < cursor;i++) {
		if (ans[i] == inputArr[index].second)
			return false;
	}
	//cursor자리 제외할때 cursor가 ans벡터의 끝을 가리키는지 아닌지 검색
	if (cursor + 1 < ans.size()) {
		for (int i = cursor + 1; i < ans.size(); i++) {
			if (ans[i] == inputArr[index].second)
				return false;
		}
	}
	//나머진 다 true 반환
	return true;
}

void solution() {
	//K번 만큼 반복
	for (int i = 0; i < K; i++) {
		//false 하나라도 나올 시 ! 출력
		if (!setAns(i)) {
			cout << "!";
			return;
		}

	}
	//마지막 문자를 기준으로 시계방향으로 출력해야하므로 cursor--를 ans벡터사이즈만큼 반복하면서 출력
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[cursor];
		if (cursor - 1 < 0) cursor = ans.size() - 1;
		else cursor--;
	}


}

int main() {
	input();
	solution();
}