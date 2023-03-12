///////////////////////////////////////////////////////// set에 N개의 숫자들을 다 저장 후 N번째 값을 출력하는 방식

// #include<iostream>
// #include<queue>
// #include<set>
// using namespace std;

// //우선순위 큐
// priority_queue<int, vector<int>, greater<int>> pq;
// //초기 k개의 소수들 
// vector<int> initialPrimeNums;
// //N개의 pop한 숫자들
// set<int> popped;

// const int MAXINT = 2147483647;
// int N, K;

// void Input() {
// 	int tmp=0;
// 	cin >> K >> N;
// 	for (int i = 0; i < K; i++) {
// 		cin >> tmp;
// 		//처음에 들어온 값 소수 벡터에 넣어주고
// 		initialPrimeNums.push_back(tmp);
// 		//우선순위큐에도 넣어줌
// 		pq.push(tmp);
// 	}
// }

// //K개의 소수를 top에 곱해서 넣고 pop하는과정은 N번 넘게 해야함!
// // 왜냐면 중복이 많아서 대체로 pq의 사이즈가 N개가 안되는 경우가 많음 
// //따라서 무한루프로 구현해야함

// void Solution() {
// 	while(1){
// 		//우선순위 큐에서 제일 작은값
// 		long long top = pq.top();
// 		for (int j = 0; j < K; j++) {
// 			//top값이 이미 뽑은 값중에 있다면 이미 계산했던 값이므로 continue
// 			if (popped.find(top) != popped.end()) break;
// 			//값을 곱했을때 int 범위 넘어갈시 continue;
// 			else if (top * initialPrimeNums[j] >= MAXINT) continue;
// 			//위의 조건들 넘어갔다면 pq에 푸시해줌
// 			pq.push(top * initialPrimeNums[j]);
// 		}
// 		//top값 insert
// 		popped.insert(top);
// 		//insert연산 아끼려고 size비교를 insert위에 넣었었는데 생각해보니 
// 		//사이즈가 N-1일때, 들어온 값이 set안에 있다면 해당값이 답이 될수없으므로 insert밑에 넣어야함
// 		if (popped.size() == N) {
// 			cout << top;
// 			return;
// 		}
// 		//K개의 소수를 pq의 top에 곱한후 pq에 넣는 연산을 다 끝냈을 때, 비로소 pop
// 		pq.pop();
// 	}

// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	Input();
// 	Solution();
// }

///////////////////////////////////////////////////////// 카운트를 통해서 저장하지 않고 N번째 원소 바로 출력하는 방식 (효율적)

#include<iostream>
#include<queue>
using namespace std;

//우선순위 큐
priority_queue<int, vector<int>, greater<int>> pq;
//초기 k개의 소수들 
vector<int> initialPrimeNums;

const int MAXINT = 2147483647;
int N, K;

void Input() {
	int tmp=0;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		//처음에 들어온 값 소수 벡터에 넣어주고
		initialPrimeNums.push_back(tmp);
		//우선순위큐에도 넣어줌
		pq.push(tmp);
	}
}

void Solution() {
	//이전값 저장용 변수
	int prev = -1;
	//N-1번째 순서의 수를 제거하는 과정
	for (int i = 0; i < N-1; i++) {
		//top값을 cur에 저장
		int cur = pq.top();
		//pop해줌
		pq.pop();
		//K개의 소수를 cur값에 곱해준 후 범위 안 넘어가면 pq에 넣어줌
		for (int j = 0; j < K; j++) {
			long long tmp = 1LL * cur * initialPrimeNums[j];
			if (tmp >= MAXINT) continue;
			pq.push(tmp);
		}
		//prev변수에 pop해준 top넣어놓고 
		prev = cur;
		//pop해준 값과 같은 수들 전부 제거 
		while (prev == pq.top()) pq.pop();
	}
	//위의 과정 끝나면 N번째 원소 남음 바로 출력
	cout << pq.top();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}