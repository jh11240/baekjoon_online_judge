#include<iostream>
#include<queue>

using namespace std;
//왼쪽엔 max큐
priority_queue <int, vector<int>, less<int>>  leftMaxPq;
//오른쪽엔 min큐
priority_queue <int, vector<int>, greater<int>>  rightMinPq;

vector<int> ans;
//testcase수, 각 테케의 원소의 갯수, 각 원소입력받을 값, 중앙값
int T = 0, M = 0, tmp = 0, median = 0;

/// <summary>
/// 각 테스트케이스에서 사용하기 위해 초기화용 함수
/// </summary>
void Init() {
	median = 0;
	ans.clear();
	while (!leftMaxPq.empty()) {
		leftMaxPq.pop();
	}
	while (!rightMinPq.empty()) {
		rightMinPq.pop();
	}
}
/// <summary>
/// 매개변수로 들어온 값을 넣으면서 leftMaxPq, rightMinPq큐내부와 median값 재조정
/// </summary>
/// <param name="elem(새로 들어온 값)"></param>
/// <param name="order(elem의 index)"></param>
void ReAdjustQueue(int elem,int order) {
	//맨처음 값이 들어왔을 때,
	if (order == 1) {
		//중앙값에 값 넣기
		median = elem;
		return;
	}
	else if (order == 2) {
		if (median >= elem) leftMaxPq.push(elem);
		else rightMinPq.push(elem);
		return;
	}
	//3번째 값이 들어왔을땐 큐가 하나만 비어있는 상황
	else if (order == 3) {
		//leftMaxPq가 비어있을 때
		if (leftMaxPq.empty()) {
			//elem값이 median값보다 작거나 같을 때
			if (elem <= median) {
				leftMaxPq.push(elem);
				return;
			}
			//elem값이 rightminpq.top보다 작거나 같을 때
			else if (elem <= rightMinPq.top()) {
				leftMaxPq.push(median);
				median = elem;
				return;
			}
			//elem값이 rightminpq.top값보다 클때
			else {
				leftMaxPq.push(median);
				median = rightMinPq.top();
				rightMinPq.pop();
				rightMinPq.push(elem);
				return;
			}
		}
		//rightMinPq가 비어있을 때
		else {
			//중앙값보다 크거나 같으면
			if (median <= elem) {
				rightMinPq.push(elem);
				return;
			}
			//원소가 왼쪽 top값 보다 같거나 크면
			else if (elem >=leftMaxPq.top()) {
				rightMinPq.push(median);
				median = elem;
				return;
			}
			//원소가 왼쪽top값 보다 작으면
			else {
				rightMinPq.push(median);
				median = leftMaxPq.top();
				leftMaxPq.pop();
				leftMaxPq.push(elem);
				return;
			}
		}
	}

	//order가 짝수일 때 경우
	if (order % 2 == 0) {
		//중앙값과 같다면 
		if (elem == median) {
			//왼쪽으로 푸시
			leftMaxPq.push(median);
			return;
		}
		//elem이 median보다 크고 rightminpq.top보다 작을때
		else if (elem>median && elem<=rightMinPq.top()) {
			leftMaxPq.push(median);
			median = elem;
			return;
		}
		//elem이 median보다 작고 leftmaxpq.top보다 클때
		else if (elem<median && elem>=leftMaxPq.top()) {
			leftMaxPq.push(elem);
			return;
		}
		//elem이 rightMinpq.top보다 클때
		else if (elem>rightMinPq.top()) {
			rightMinPq.push(elem);
			return;
		}
		//elem이 leftmaxpq.top보다 작을 때
		else if(elem<leftMaxPq.top()) {
			leftMaxPq.push(elem);
			return;
		}
	}
	//순서가 홀수일 때, 두 큐의 사이즈는 1차이로 다름
	else {
		//왼쪽 큐 사이즈가 더 작다면
		if (leftMaxPq.size() < rightMinPq.size()) {
			//elem이 median값과 같다면 
			if (elem == median) {
				//오른쪽 큐에 median값 넣어줘서 큐 사이즈 동일하게 만듬
				leftMaxPq.push(elem);
				return;
			}
			//중앙값보단 크면서 오른쪽 top보다 작을 때
			else if (elem > median && elem <= rightMinPq.top()) {
				leftMaxPq.push(median);
				median = elem;
				return;
			}
			//중앙값보다 elem이 작으면(왼쪽큐top과 중앙값 사이일때나 왼쪽큐top보다 작을때나 똑같이 작동)
			else if (elem < median) {
				//그냥 바로 leftMaxpq에 푸시 
				leftMaxPq.push(elem);
				return;
			}
			//오른쪽 큐 top보다 크면 
			else if (elem > rightMinPq.top()) {
				leftMaxPq.push(median);
				median = rightMinPq.top();
				rightMinPq.pop();
				rightMinPq.push(elem);
				return;
			}
		}
		//오른쪽 큐의 사이즈가 더 작을땐 
		else {
			//중앙값과 같을 때
			if (median == elem) {
				rightMinPq.push(median);
				return;
			}
			//중앙값보다 클때(중앙값과 오른쪽 큐 top사이일때나 오른쪽큐 top보다 클때나 똑같이 작동)
			else if (median < elem) {
				rightMinPq.push(elem);
				return;
			}
			//중앙값과 왼쪽 큐의 top값 사이일때
			else if (elem < median && elem >= leftMaxPq.top()) {
				rightMinPq.push(median);
				median = elem;
				return;
			}
			//왼쪽값보다 작을 때
			else if (elem < leftMaxPq.top()) {
				rightMinPq.push(median);
				median = leftMaxPq.top();
				leftMaxPq.pop();
				leftMaxPq.push(elem);
				return;
			}

		}
	}
}

void Input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M;
		Init();
		for (int j = 1; j <= M;j++ ) {
			cin >> tmp;
			ReAdjustQueue(tmp, j);
			//홀수번째라면
			if (j % 2) {
				//중앙값 ans에 넣어주기
				ans.push_back(median);
			}
		}
		//벡터 사이즈 출력
		cout << ans.size()<<'\n';
		//10개마다 줄바꿈해야해서 줄바꿈 체크용
		int cnt = 1;
		for (int elem : ans) {
			cout << elem << " ";
			//10개출력마다 줄 바꿈
			if (cnt % 10 == 0)
				cout << '\n';
			cnt++;
		}
		cout << '\n';
	}
}

int main() {
	Input();
}