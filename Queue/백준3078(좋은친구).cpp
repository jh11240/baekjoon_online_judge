#include<iostream>
#include<string>
#include<queue>

using namespace std;
int N=0,K=0;
string name="";
//글자수에 맞춰서 큐를 생성
queue<int> q[21];

void input() {
	cin >> N >> K;
}

//큐에 넣는거까지 알겠어 근데 그다음에 어디부분에서 해당 쌍의 갯수를 구하기위해 
//큐의 사이즈를 ans에 넣는 건지 감이 안잡힘. -> pop하고 그다음 부분에서 남은 사이즈 넣고 이번값 푸시
void solution() {
	long long nameLen = 0,Ans=0;
	
	for (int i = 0; i < N; i++) {
		cin >> name;
		//입력된 이름의 길이 저장.
		nameLen = name.length();
		//해당 이름길이를 담당하는 큐가 비거나, 이번 인덱스와 front()의 인덱스 차이가 K보다 작거나 같을 때까지
		while (!q[nameLen].empty() && i - q[nameLen].front() > K) {
			//pop해준다
			q[nameLen].pop();
		}
		//pop과정이 끝났다면 큐안의 남은 원소들이 지금 넣으려는 이름과의 쌍이되는 원소들이므로 q[nameLen].size는 결국 쌍의 갯수가 된다.
		//따라서 답에 더해준다.
		Ans += q[nameLen].size();
		//쌍 갯수를 더했으므로 이번 인덱스 푸시.
		q[nameLen].push(i);
	}

	cout << Ans;
}

int main() {
	input();
	solution();
}