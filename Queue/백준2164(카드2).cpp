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
			return;
		}
		Node* popNode = head->next;
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

queue* q = new queue();
int N=0;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q->push(i);
	}
}
void solution() {
	int tmp = 0;
	while (q->Size() != 1) {
		q->pop();
		tmp = q->front();
		q->pop();
		q->push(tmp);
	}
	cout << q->front();
}

int main() {
	input();
	solution();
}