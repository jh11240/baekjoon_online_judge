#include<iostream>


using namespace std;

int N;

template <typename T>

struct Node {
	T data;
	Node* next;
};

template <typename T>
class stack {
private:
	int q_size;								//스택 사이즈
	Node<T>* head;							//스택의 top부분 가리키는 포인터


public:
	//생성자
	stack() {						
		q_size = 0;
		Node<T>* tmpHead = new Node<T>;		
		tmpHead->data = T();
		tmpHead->next = tmpHead;
		head = tmpHead;
	}
	//소멸자
	~stack() {
		Node<T>* tmp = head;
		Node<T>* delNode = tmp;
		while (tmp != nullptr) {
			delNode = tmp;
			tmp = tmp->next;
			delete delNode;
		}

	}
	//원소 넣기
	void push(T elem) {				
		//새로운 노드 생성
		Node<T>* newNode = new Node<T>;
		newNode->data = elem;
		//연결작업
		newNode->next = head->next;
		head->next = newNode;
		q_size++;

	}
	void pop() {							//원소 빼기
		if (!empty()) {						//비어있지 않을 때
			Node<T>* delNode = head->next;
			head->next = delNode->next;
			delete delNode;
			q_size--;
		}
		else {
			cout << -1 << '\n';
		}
	}
	T top() {								//큐의 제일 앞 값(먼저 빠짐)
		if (empty())return -1;
		else return head->next->data;

	}
	bool empty() {							//큐가 비어있는지 여부
		if (q_size == 0)
			return true;
		else return false;
	}
	int size() {								//큐의 크기
		return q_size;
	}
};

stack<int>* q = new stack<int>();

void input() {
	string tmp="";
	int tmpInt = 0;
	cin >> N;
	for (int i=0; i < N; i++) {
		cin >> tmp;
		if (tmp == "push") {
			cin >> tmpInt;
			q->push(tmpInt);
		}
		else if (tmp == "pop") {
			if(!q->empty())cout<<q->top() << '\n';
			q->pop();
		}
		else if (tmp == "size") {
			cout<<q->size()<<'\n';
		}
		else if (tmp == "empty") {
			cout << q->empty() << '\n';
		}
		else if (tmp == "top") {
			cout << q->top() << '\n';
		}

	}
}


int main() {
	input();
}