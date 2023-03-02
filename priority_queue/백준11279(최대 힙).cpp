#include<iostream>

using namespace std;

//기본적으로 마지막 빈칸이랑 마지막 원소찾을때를 잘못 생각했는데,
//추가할때 인덱스를 그냥 마지막 인덱스 다음 인덱스에 넣으면 되는데, 
//빈칸 인덱스를 찾을 때 밑에 자식이 있으면 오른쪽 자식으로 넘어가고 해당 자식에서 또 왼쪽 자식 검색하고 이런식으로 
//오른쪽 자식노드가 없을때까지 반복하는식으로 구현해서 이상한 값을 자꾸 넘겨줬다. 

//maxHeap
class Priority_Queue {
private:
	int* pq;
	//큐안의 원소 갯수, 마지막 원소가 들어있는 인덱스로 사용
	int size;

public:
	Priority_Queue(int n) {
		pq = new int[n];
		size = 0;
		fill(&pq[0], &pq[n], -1);
	}

	void Push(int x);
	void Pop();
	void Heapify(int curIdx);
};

void Priority_Queue::Push(int x) {
	//비어있을 경우
	if (pq[1] == -1) {
		pq[1] = x;
		size = 1;
		return;
	}

	int cur_idx = ++size;
	//반복문 빠져나왔다면 child는 비어있는 자식 노드
	pq[cur_idx] = x;

	while (1) {
		if (cur_idx / 2 == 0) return;

		if (pq[cur_idx / 2] < pq[cur_idx]) {
			swap(pq[cur_idx / 2], pq[cur_idx]);
			cur_idx /= 2;
		}
		else
			break;
	}
	return;
}
void Priority_Queue::Pop() {
	if (pq[1] == -1) {
		cout << 0 << '\n';
		return;
	}
	cout << pq[1] << "\n";
	int lastIndex =size--;
	swap(pq[1], pq[lastIndex]);
	pq[lastIndex] = -1;

	if (lastIndex != 1)
		Heapify(1);

}
void Priority_Queue::Heapify(int curIdx) {
	//curIdx가 범위를 벗어나면 리턴
	if (curIdx * 2 > 100'002) return;
	//curIdx가 범위를 만족하지만 리프노드라면 리턴
	if (curIdx * 2 <= 100'002 && pq[curIdx * 2] == -1) return;
	//임시 인덱스 tmp_idx에 curIdx값 저장
	int tmp_idx = curIdx;
	//tmp_idx 두배 해줌
	tmp_idx *= 2;
	//왼쪽 자식 오른쪽 자식 비교해 더 큰값으로 tmp_idx옮김
	if (tmp_idx + 1 <= 100'002 && pq[tmp_idx] < pq[tmp_idx + 1])
		tmp_idx++;
	//자식중에 더 큰값보다 현재값이 더 크다면 리턴
	if (pq[curIdx] > pq[tmp_idx]) return;
	swap(pq[tmp_idx], pq[curIdx]);
	Heapify(tmp_idx);
}

void Input() {
	Priority_Queue* pq = new Priority_Queue(100'001);
	int N = 0, tmp = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 0) {
			pq->Pop();
		}
		else
			pq->Push(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();

}