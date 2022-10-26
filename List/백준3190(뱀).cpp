#include<iostream>
#include<vector>

//사실 그냥 모든 점들을 다 움직인다고 생각했는데 매우 비효율적이네 첫값 끝값만 변경해주면 되네 
using namespace std;

int N,K,L,Ans=0;
//사과 위치들
vector<pair<int,int>> appleLoc;
//뱀 움직임 
vector<pair<int, char>> snakeMove;

//뱀의 각 파트
struct Node {
	int x;
	int y;
	Node* next;
	Node* prev;
};

class Snake {
private:
	char dir;
	int size;
	Node* head;
	Node* tail;
public:
	//생성자
	Snake() {
		size = 1;
		dir = 'R';
		head = new Node;
		tail = new Node;
		//맨처음 뱀 녀석
		Node* firstSnake = new Node;
		firstSnake->x = 1;
		firstSnake->y = 1;
		firstSnake->next = head;
		firstSnake->prev = tail;
		head->prev = firstSnake;
		head->next = head;
		tail->next = firstSnake;
		tail->prev = tail;
	}
	//소멸자
	~Snake() {
		Node* tmp1 = tail; 
		Node* tmp2 = new Node;
		while (tmp1 != head) {
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			delete tmp2;
		}
		delete tmp1;
	}
	/// <summary>
	/// 움직인 칸에 사과있을 때
	/// </summary>
	/// <param name="움직인 칸의 x(행)"></param>
	/// <param name="움직인 칸의 y(열)"></param>
	bool EatApple(int x,int y) {
		//범위 벗어나면 벽 부딪힌것 이므로 false
		if (x > N || y > N || x==0 || y==0) return false;
		//스네이크 몸통중에 (x,y)값이 있으면  false
		if (Find(x, y)) return false;
		Node* newHead = new Node;
		newHead->x = x;
		newHead->y = y;
		head->prev->next = newHead;
		newHead->prev = head->prev;
		newHead->next = head;
		head->prev = newHead;
		size++;
		return true;
	}
	/// <summary>
	/// 움직였을때 사과가 아닐때
	/// </summary>
	/// <param name="움직인 칸의 x(행)"></param>
/// <param name="움직인 칸의 y(열)"></param>
bool NoApple(int x, int y) {
	//범위 벗어나면 벽 부딪힌것 이므로 false
	if (x > N || y > N || x==0 || y==0) return false;
	//스네이크 몸통중에 (x,y)값이 있으면  false
	if (Find(x, y)) {
		////만약 x,y가 꼬리값이라면 어차피 잘리기 때문에 상관없다 -> 예제 3보니 그건 아닌듯
		//if (tail->next->x == x && tail->next->y == y) {}
		//꼬리값 아니면 return false
		return false;
	}
	//head 새로생성
	Node* newHead = new Node;
	newHead->x = x;
	newHead->y = y;
	head->prev->next = newHead;
	newHead->prev = head->prev;
	newHead->next = head;
	head->prev = newHead;

	//tail 가리키는 값 지우기
	Node* tmp = tail->next;
	tail->next = tmp->next;
	tmp->next->prev = tail;
	delete tmp;

	return true;
}
/// <summary>
/// x행 y열에 노드가 있는지 찾는 함수 - >꼬리값만 닿을거라고 생각해서 모든 몸통 안찾아봄
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
bool Find(int x, int y) {
	Node* tmp = tail->next;
	while (tmp != head) {
		if (tmp->x == x && tmp->y == y) {
			return true;
		}
		else
			tmp = tmp->next;
	}
	return false;
}
//dir값은 동적으로 변경될 수 있으므로 input값의 디폴트값을 dir로 할 수 없다. 
//따라서 비정적 멤버 변수 참조는 특정 개체에 상대적입니다라는 에러가 뜬다
//https://stackoverflow.com/questions/40837314/cant-figure-out-this-non-static-member-reference-error
/*char Dir(char input = dir) {
	dir = input;
	return dir;
}*/
char GetDir() { return dir; }
void SetDir(char input) { dir = input; }

Node* Head() { return head; }

};

Snake* s;

/// <summary>
/// x행 y열에 사과 잇는지 체크
/// </summary>
/// <param name="x행"></param>
/// <param name="y열"></param>
/// <returns>사과 있다면 true, 없으면 false</returns>
bool checkIfApple(int x, int y) {


	////임시방편으로 짠거 이런식으로하면 지워져도 0,0과 계속 비교하게 되서 비효율적
	//for (int i = 0; i < K; i++) {
	//	if (x == appleLoc[i].first && y == appleLoc[i].second) {
	//		appleLoc[i].first = 0;
	//		appleLoc[i].second = 0;
	//		return true;
	//	}
	//}
	//return false;

	//erase로 좀더 효율적으로
	for (auto iter = appleLoc.begin(); iter != appleLoc.end(); ++iter) {
		if (iter->first == x && iter->second == y) {
			appleLoc.erase(iter);
			return true;
		}
		
	}
	return false;
}

void input() {
	int appleX = 0, appleY = 0, sec = 0;
	char dir = ' ';
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> appleY >> appleX;
		appleLoc.push_back(make_pair(appleY, appleX));
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> sec >> dir;
		snakeMove.push_back(make_pair(sec, dir));
	}
}

/// <summary>
/// index번째 입력값을 가지고 적힌 초만큼 이동하고, 적힌 방향으로 방향 전환함
/// </summary>
/// <param name="index"></param>
/// <returns>이동할 수 없다면 false, 이동을 완료했다면 true</returns>
bool moveSnake(int index) {
	//첫번째 인덱스일땐 index-1하면 음수값 index접근하므로 오류나므로
	if (index == 0) {
		for (int i = 0; i < snakeMove[index].first; i++) {
			//방향은 무조건 오른쪽
			//오른쪽에 사과가 있다면
			if (checkIfApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
				//오른쪽으로 성공적으로 이동했다면
				if (s->EatApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
			//사과 없다면
			else {
				//오른쪽으로 성공적으로 이동했다면
				if (s->NoApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
		}
		if (snakeMove[index].second == 'L')
			//이동 다 했다면 dir값 변경해준 후 true 리턴
			s->SetDir('U');
		else
			s->SetDir('D');
		return true;
	}
	//마지막 인덱스값까지 벽이나 몸통에 안 부딪혔다면
	if (index == L) {
		if (s->GetDir() == 'U') {
			while (1) {
				//위쪽에 사과가 있다면
				if (checkIfApple(s->Head()->prev->x - 1, s->Head()->prev->y)) {
					//위쪽으로 성공적으로 이동했다면
					if (s->EatApple(s->Head()->prev->x - 1, s->Head()->prev->y)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
				//사과 없다면
				else {
					//위쪽으로 성공적으로 이동했다면
					if (s->NoApple(s->Head()->prev->x - 1, s->Head()->prev->y)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
			}

		}
		else if (s->GetDir() == 'D') {
			while (1) {
				//아래쪽에 사과가 있다면
				if (checkIfApple(s->Head()->prev->x + 1, s->Head()->prev->y)) {
					//아래쪽으로 성공적으로 이동했다면
					if (s->EatApple(s->Head()->prev->x + 1, s->Head()->prev->y)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
				//사과 없다면
				else {
					//아래쪽으로 성공적으로 이동했다면
					if (s->NoApple(s->Head()->prev->x + 1, s->Head()->prev->y)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
			}
		}
		else if (s->GetDir() == 'L') {
			while (1) {
				//왼쪽에 사과가 있다면
				if (checkIfApple(s->Head()->prev->x, s->Head()->prev->y - 1)) {
					//왼쪽으로 성공적으로 이동했다면
					if (s->EatApple(s->Head()->prev->x, s->Head()->prev->y - 1)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
				//사과 없다면
				else {
					//왼쪽으로 성공적으로 이동했다면
					if (s->NoApple(s->Head()->prev->x, s->Head()->prev->y - 1)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
			}
		}
		else if (s->GetDir() == 'R') {
			while (1) {
				//오른쪽에 사과가 있다면
				if (checkIfApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
					//오른쪽으로 성공적으로 이동했다면
					if (s->EatApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
						//답 ++
						Ans++;
					}
					//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
					else {
						Ans++;
						return false;
					}
				}
				//사과 없다면
				else {
				//오른쪽으로 성공적으로 이동했다면
				if (s->NoApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
				}
			}
		}
		return true;
	}
	//지금 방향 왼쪽이라면
	if (s->GetDir() == 'L') {
		//해당 초만큼 왼쪽으로 움직임 
		for (int i = snakeMove[index-1].first; i < snakeMove[index].first; i++) {
			//왼쪽에 사과가 있다면
			if (checkIfApple(s->Head()->prev->x, s->Head()->prev->y - 1)) {
				//왼쪽으로 성공적으로 이동했다면
				if (s->EatApple(s->Head()->prev->x, s->Head()->prev->y - 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
			//사과 없다면
			else {
				//왼쪽으로 성공적으로 이동했다면
				if (s->NoApple(s->Head()->prev->x, s->Head()->prev->y - 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
		}
		if (snakeMove[index].second == 'L')
			//이동 다 했다면 dir값 변경해준 후 true 리턴
			s->SetDir('D');
		else
			s->SetDir('U');
		return true;

	}
	else if (s->GetDir() == 'R') {
		//해당 초만큼 오른쪽으로 움직임 
		for (int i = snakeMove[index - 1].first; i < snakeMove[index].first; i++) {

			//오른쪽에 사과가 있다면
			if (checkIfApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
				//오른쪽으로 성공적으로 이동했다면
				if (s->EatApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
			//사과 없다면
			else {
				//오른쪽으로 성공적으로 이동했다면
				if (s->NoApple(s->Head()->prev->x, s->Head()->prev->y + 1)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
		}
		if (snakeMove[index].second == 'L')
			//이동 다 했다면 dir값 변경해준 후 true 리턴
			s->SetDir('U');
		else
			s->SetDir('D');
		return true;
	}
	else if (s->GetDir() == 'U') {
		//해당 초만큼 위쪽으로 움직임 
		for (int i = snakeMove[index - 1].first; i < snakeMove[index].first; i++) {

			//위쪽에 사과가 있다면
			if (checkIfApple(s->Head()->prev->x-1, s->Head()->prev->y)) {
				//위쪽으로 성공적으로 이동했다면
				if (s->EatApple(s->Head()->prev->x-1, s->Head()->prev->y)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
			//사과 없다면
			else {
				//위쪽으로 성공적으로 이동했다면
				if (s->NoApple(s->Head()->prev->x - 1, s->Head()->prev->y)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
		}
		if (snakeMove[index].second == 'L')
			//이동 다 했다면 dir값 변경해준 후 true 리턴
			s->SetDir('L');
		else
			s->SetDir('R');
		return true;

	}
	else if (s->GetDir() == 'D') {
		//해당 초만큼 아래쪽으로 움직임 
		for (int i = snakeMove[index - 1].first; i < snakeMove[index].first; i++) {

			//아래쪽에 사과가 있다면
			if (checkIfApple(s->Head()->prev->x+1, s->Head()->prev->y )) {
				//아래쪽으로 성공적으로 이동했다면
				if (s->EatApple(s->Head()->prev->x+1, s->Head()->prev->y )) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
			//사과 없다면
			else {
				//아래쪽으로 성공적으로 이동했다면
				if (s->NoApple(s->Head()->prev->x + 1, s->Head()->prev->y)) {
					//답 ++
					Ans++;
				}
				//이동못하면 벽에막히거나 자기 몸에 막힌것이므로 false 리턴
				else {
					Ans++;
					return false;
				}
			}
		}
		if (snakeMove[index].second == 'L')
			//이동 다 했다면 dir값 변경해준 후 true 리턴
			s->SetDir('R');
		else
			s->SetDir('L');
		return true;

	}

	return true;
}

void solution() {
	for (int i = 0; i < L; i++) {
		if (!moveSnake(i))
		{
			cout << Ans;
			return;
		}

	}
	moveSnake(L);
	cout << Ans;
}

int main() {
	s = new Snake();
	input();
	solution();
	delete s;
}