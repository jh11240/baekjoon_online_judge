#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//양수만 담는 minHeap 우선순위큐
priority_queue<int,vector<int>,greater<int>> positive_pq;
//절댓값이 작은값을 가져오기 위해서 음수 우선순위큐는 maxHeap을 사용해야함
priority_queue<int,vector<int>,less<int>> negative_pq;

void Input() {
	int N=0,tmp=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		//음수 들어오면
		if (tmp < 0)
			negative_pq.push(tmp);
		//양수 들어오면
		else if (tmp > 0)
			positive_pq.push(tmp);
		//0 들어오면
		else if(tmp==0)
		{
			//만약 두 큐 다 비어있다면 0 출력
			if (negative_pq.empty() && positive_pq.empty()) {
				cout <<0<<'\n';
			}
			//음수큐 비어있다면 양수큐에서 제일 작은값 출력하고 pop
			else if (negative_pq.empty())
			{
				cout << positive_pq.top() << '\n';
				positive_pq.pop();
			}
			//양수큐 비어있다면  음수큐에서 top출력하고 pop
			else if (positive_pq.empty()) {
				cout << negative_pq.top() << '\n';
				negative_pq.pop();
			}
			//둘 다 차있다면
			else {
				//음수큐의 top의 절댓값이 양수큐의 top보다 작다면 
				if (-negative_pq.top() <= positive_pq.top()) {
					cout << negative_pq.top()<<'\n';
					negative_pq.pop();
				}
				//양수큐의 top이 더 작다면 
				else {
					cout << positive_pq.top()<<'\n';
					positive_pq.pop();

				}
			}
			
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}