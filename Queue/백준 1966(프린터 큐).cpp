///////////////////////////////////////////////////////////////
// 배열에 중요도를 따로 저장후 정렬하는 방법
// # include<iostream>
// # include<queue>
// # include<algorithm>

// using namespace std;

// struct document {
// 	int index;
// 	int priority;
// };
// queue<document> q;
// //전체우선도 저장용 배열
// int prioritySave[101];
// int N=0;

// //큐 초기화
// void initQ() {
// 	while (!q.empty()) {
// 		q.pop();
// 	}
// }

// //타겟 문서가 뽑히는 순서 출력
// void printDocumentOrder() {
// 	//각 테케의 문서갯수, 타겟문서의 index, 각 문서의 중요도, 중요도배열에서 index용도로 사용할 cnt변수, 출력할 답
// 	int documentAmount,targetDocumentNum=0,elemPriority=0,cnt=0,ans=1;
// 	cin >> documentAmount >> targetDocumentNum;
// 	for (int i = 0; i < documentAmount; i++) {
// 		cin >> elemPriority;
// 		prioritySave[i] = elemPriority;
// 		document d = { i,elemPriority };
// 		q.push(d);
// 	}
// 	//중요도 배열 정렬
// 	sort(prioritySave, prioritySave+documentAmount,greater<int>());

// 	while (1) {

// 		//큐의 front값의 우선순위가 제일 높은게 나올때까지 front의 원소를 뒤로 push
// 		while (q.front().priority != prioritySave[cnt]) {
// 			document tmp = q.front();
// 			q.pop();
// 			q.push(tmp);
// 		}
// 		//큐의 front값의 index가 타겟문서의 index랑 같다면 답이므로 출력
// 		if (q.front().index == targetDocumentNum) {
// 			cout << ans<<'\n';
// 			return;
// 		}
// 		//front원소의 우선순위가 제일 높지만 타겟 문서가 아니라면 
// 		else {
// 			//해당 원소 pop해준 후,
// 			q.pop();
// 			//답++,
// 			ans++;
// 			//중요도배열index++
// 			cnt++;
// 		}
// 	}

// }

// void solution() {
// 	for (int i = 0; i < N; i++) {
// 		initQ();
// 		printDocumentOrder();
// 	}

// }

// void input() {
// 	cin >> N;
// }

// int main() {
// 	input();
// 	solution();
// }


////////////////////////////////////////////////////////////////////////////////////
//priority_queue를 사용한 방법

#include<iostream>
#include<queue>

using namespace std;

//index, cost
queue<pair<int,int>> q;
struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) {	
			return a.second < b.second;
		}
		else {
			return a.first < b.first;
		}
	}
};

priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;

void init() {
	while (!q.empty())
		q.pop();
	while (!pq.empty())
		pq.pop();
}

int main() {
	int N, docAmount, targetDocIndex = 0,cnt=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cnt = 0;
		init();
		cin >> docAmount >> targetDocIndex;
		for (int j = 0; j < docAmount; j++) {
			int cost = 0;
			cin >> cost;
			q.push(make_pair(j,cost));
			pq.push(make_pair(j,cost));
		}
		while (1) {
			//q의 중요도가 pq의 탑(제일 높은 중요도)보다 작다면
			while (q.front().second < pq.top().second)
			{
				//큐의 앞값 뒤로 넣어주고
				q.push(q.front());
				//앞값 삭제
				q.pop();
			}
			if (q.front().first == targetDocIndex) {
				cnt++;
				cout << cnt<<'\n';
				break;
			}
			//반복문이 위의 if문에 안걸리고 끝났다면 앞값은 지워야하므로 pop
			q.pop();
			pq.pop();
			cnt++;
		}

	}
}