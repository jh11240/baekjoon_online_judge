#include<iostream>

using namespace std;

//minHeap
class Priority_Queue {
private:
	//값이 저장될 배열 index 1부터 시작
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

	//배열의 마지막 원소 다음 index
	int cur_idx = ++size;
	//배열의 마지막 칸에 x를 넣어준다.
	pq[cur_idx] = x;

	//방금 들어온 원소 x를 min_heap에 따라 맞는 위치에 넣어주기
	while (1) {
		//현재 idx가 루트 노드라면 return
		if (cur_idx / 2 == 0) return;

		//부모 노드가 자식 노드값보다 크다면 
		if (pq[cur_idx / 2] > pq[cur_idx]) {
			//바꿔주기
			swap(pq[cur_idx / 2], pq[cur_idx]);
			cur_idx /= 2;
		}
		else
			break;
	}
	return;
}

void Priority_Queue::Pop() {
	//비어있다면 0출력
	if (pq[1] == -1) {
		cout << 0 << '\n';
		return;
	}
	//루트 노드 출력
	cout << pq[1] << "\n";
	int lastIndex = size--;
	//마지막 원소와 루트 노드 바꾸기
	swap(pq[1], pq[lastIndex]);
	//루트 노드값 제거
	pq[lastIndex] = -1;


	if (lastIndex != 1)
		Heapify(1);
}

/// <summary>
/// pop 후에 루트노드에 박힌 원소값 루트인덱스에서 제자리로 옮겨주는 재귀함수
/// </summary>
/// <param name="curIdx(제자리 찾아가야할 원소의 현재 index)"></param>
void Priority_Queue::Heapify(int curIdx) {
	//curIdx가 범위를 벗어나면 리턴
	if (curIdx * 2 >= 100'002) return;
	//curIdx가 리프노드라면 리턴
	if (pq[curIdx * 2] == -1) return;
	//임시 인덱스 tmp_idx에 curIdx값 저장(curIdx의 자식 인덱스 가리키는 용도)
	int tmp_idx = curIdx;
	//tmp_idx 두배 해줌으로 왼쪽 자식 인덱스 가리킴
	tmp_idx *= 2;
	//왼쪽 자식 오른쪽 자식 비교해 더 작은 값으로 tmp_idx옮김
	//maxheap과는 다르게 오른쪽 자식이 -1이라면 -1값을 바꿔버리므로 조심
	if ((tmp_idx + 1 <= 100'002) && (pq[tmp_idx + 1] != -1) && (pq[tmp_idx] > pq[tmp_idx + 1]))
		tmp_idx++;
	//자식중에 더 작은 값보다 현재값이 더 작다면 리턴
	if (pq[curIdx] < pq[tmp_idx]) return;
	swap(pq[tmp_idx], pq[curIdx]);
	Heapify(tmp_idx);
}

void Input() {
	//연산이 10만이라했으므로 10만으로 초기화
	Priority_Queue* pq = new Priority_Queue(100'002);
	

	int N = 0, tmp = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		//0 받을시 pop연산
		if (tmp == 0) {
			pq->Pop();
		}
		//push연산
		else
			pq->Push(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();


}
