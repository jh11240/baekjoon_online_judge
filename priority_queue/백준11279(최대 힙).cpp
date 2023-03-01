#include<iostream>

using namespace std;

//maxHeap
class Priority_Queue {
private:
	int* pq;
public:
	Priority_Queue(int n) {
		pq = new int[n];
		fill(&pq[0], &pq[n], -1);
	}
	Priority_Queue() {
		pq = new int[100'001];
		fill(&pq[0], &pq[100'001], -1);
	}

	void Push(int x);
	void Pop();
	void Heapify(int curIdx);
	int FindLastEmptyIndex();
	int FindLastIndex();
};

int Priority_Queue::FindLastEmptyIndex() {
	int cur_idx = 1;

	while (cur_idx*2 <= 100'001 && pq[cur_idx] != -1) {
		//부모인덱스의 2배를 하면 child는 부모의 왼쪽 자식인덱스가 된다
		cur_idx *= 2;
		//왼쪽자식이 비어있지 않다면
		if (cur_idx <= 100'001 && pq[cur_idx] != -1) {
			//오른쪽자식으로
			cur_idx++;
		}
	}

	return cur_idx;
}

int Priority_Queue::FindLastIndex() {
	int cur_idx = 1;

	while (cur_idx*2 <= 100'001&&pq[cur_idx] != -1) {
		//부모인덱스의 2배를 하면 child는 부모의 왼쪽 자식인덱스가 된다
		cur_idx *= 2;
		if (pq[cur_idx] == -1) {
			cur_idx /= 2;
			break;
		}
		else {
			if (cur_idx <= 100'001&&pq[cur_idx + 1] == -1) {
				break;
			}
			cur_idx++;
		}
		
	}
	return cur_idx;
}

void Priority_Queue::Push(int x) {
	//비어있을 경우
	if (pq[1] == -1) {
		pq[1] = x;
		return;
	}
	int cur_idx=0;
	cur_idx = FindLastEmptyIndex();

	//반복문 빠져나왔다면 child는 비어있는 자식 노드
	pq[cur_idx] = x;

	while (1) {
		if (cur_idx / 2 == 0) return;

		if (pq[cur_idx/2] < pq[cur_idx]) {
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
	int lastIndex = FindLastIndex();
	swap(pq[1], pq[lastIndex]);
	pq[lastIndex] = -1;

	if(lastIndex!=1)
		Heapify(1);
	
}
void Priority_Queue::Heapify(int curIdx) {
	if (curIdx*2<=100'001 && pq[curIdx * 2] == -1) return;
	int tmp_idx = curIdx;

	if (tmp_idx* 2 <= 100'000 && pq[tmp_idx* 2] > pq[tmp_idx]) {
		tmp_idx*=2;
	}
	if (tmp_idx!=curIdx &&tmp_idx + 1 <= 100'000 && pq[tmp_idx + 1] > pq[tmp_idx]) {
		tmp_idx++;
	}
	if (curIdx == tmp_idx) return;
	swap(pq[tmp_idx], pq[curIdx]);
	Heapify(tmp_idx);
}

void Input() {
	Priority_Queue* pq=new Priority_Queue();
	int N=0,tmp=0;
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
	Input();

}