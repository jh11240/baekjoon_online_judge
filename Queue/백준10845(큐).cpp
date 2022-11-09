#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class queue {
private:
	int size;
	Node* head;
	Node* tail;

public:
	queue() {
		size = 0;
		head = new Node;
		tail = new Node;
		head->data = -1;
		tail->data = -1;
		head->next = tail;
		tail->next = tail;
		tail->prev = head;
		head->prev = head;

	}
	~queue() {
		Node* tmp = head;
		Node* delNode = new Node;
		while (tmp != tail) {
			delNode = tmp;
			tmp = tmp->next;
			delete delNode;
		}
		delete tmp;
	}

	void push(int data) {
		Node* pushNode = new Node;
		pushNode->data = data;
		tail->prev->next = pushNode;
		pushNode->prev = tail->prev;
		pushNode->next = tail;
		tail->prev = pushNode;
		size++;
	}
	void pop() {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		Node* popNode = head->next;
		cout << popNode->data << '\n';
		head->next = popNode->next;
		popNode->next->prev = head;
		delete popNode;
		size--;
	}
	bool empty() {
		if (!Size()) return 1;
		else return 0;
	}
	int front() {
		if (empty()) {
			return -1;
		}
		return head->next->data;

	}
	int back() {
		if (empty()) {
			return -1;
		}
		return tail->prev->data;
	}
	int Size() {
		return size;
	}
};

void input() {
	queue* q = new queue();
	int N=0,pushInt=0;
	string cmd="";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> pushInt;
			q->push(pushInt);
		}
		else if (cmd == "pop") {
			q->pop();
		}
		else if (cmd == "size") {
			cout<<q->Size()<<'\n';
		}
		else if (cmd == "front") {
			cout << q->front() << '\n';
		}
		else if (cmd == "back") {

			cout << q->back() << '\n';
		}
		else if (cmd == "empty") {
			cout << q->empty() << '\n';
		}

	}

}

int main() {
	input();
}