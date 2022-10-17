#include<iostream>

using namespace std;

int N, K;

//연결리스트에서 사용하는 노드
struct Node {
    int data;
    Node* prev;
    Node* next;
};

//원형 연결리스트
class circularLinkedList {
private:
    int size;
    Node* head;

public:
    //생성자
    circularLinkedList() {
        size = 0;
        Node* tmpHead = new Node;
        tmpHead->data = -1;
        tmpHead->prev = tmpHead;
        tmpHead->next = tmpHead;
        head = tmpHead;
    }
    //소멸자
    ~circularLinkedList() {
        Node* node = new Node;
        Node* node1 = new Node;
        node = head->next;
        while (node != head) {
            node1 = node;
            node = node->next;
            delete node1;
        }
        //반복문 빠져나올시 head이므로
        delete node;
    }
    //맨 앞값 불러오기
    int front() {
        if (size == 0) return-1;
        return head->next->data;
    }
    //맨 뒷값 불러오기
    int back() {
        if (size == 0) return -1;
        return head->prev->data;
    }
    //앞으로 집어넣기
    void push_front(int amount) {
        if (size == 0) {
            Node* tmp = new Node;
            tmp->data = amount;
            head->next = tmp;
            head->prev = tmp;
            tmp->prev = head;
            tmp->next = head;
            size++;
        }
        else {
            Node* tmp = new Node;
            tmp->data = amount;
            head->next->prev = tmp;
            tmp->next = head->next;
            tmp->prev = head;
            head->next = tmp;
            size++;
        }
    }
    //뒤로 집어넣기
    void push_back(int amount) {
        if (size == 0) {
            Node* tmp = new Node;
            tmp->data = amount;
            head->prev = tmp;
            tmp->prev = head;
            tmp->next = head;
            head->next = tmp;
            size++;
        }
        else {
            Node* tmp = new Node;
            tmp->data = amount;
            tmp->next = head;
            tmp->prev = head->prev;
            head->prev->next = tmp;
            head->prev = tmp;
            size++;
        }
    }
    //앞에거 빼기
    void pop_front() {
        if (size == 0)
            return;
        else {
            Node* tmp = head->next;
            head->next = tmp->next;
            tmp->next->prev = head;
            delete tmp;
            size--;
        }
    }
    //뒤에거 빼기
    void pop_back() {
        if (size == 0)
            return;
        else {
            Node* tmp = head->prev;
            tmp->prev->next = head;
            head->prev = tmp->prev;
            delete tmp;
            size--;
        }

    }
    //특정 노드 지우기
    void pop(Node* node) {
        if (size == 0) return;
        else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
            size--;
        }
    }
    //크기 반환
    int Size() {
        return size;
    }

    /// <summary>
    /// target이 있는지 찾아내는 함수
    /// </summary>
    /// <param name="target"></param>
    /// <returns>몇번째 인덱스, 없다면 -1</returns>
    int Find(int target) {
        int cnt = 0;
        Node* tmp = head->next;
        while (tmp != head) {
            tmp = tmp->next;
            cnt++;
            if (tmp->data == target) return cnt;
        }
        return -1;
    }
    //중간중간 원소들 확인용
    void Print() {
        Node* tmp = head->next;
        while (tmp != head) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    Node* Head() {
        return head;
    }

};
circularLinkedList* cLL;

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cLL->push_back(i);
    }
}
void solution() {
    Node* node = new Node;
    Node* tmp = new Node;
    node = cLL->Head()->next;
    cout << "<";
    while (cLL->Size() != 0) {
        int tmpK = K;
        while (tmpK != 1) {
            node = node->next;
            //움직였을 때 head값이 되면 한번 더가야됨. head지울순 없으니
            if (node == cLL->Head()) {
                node = node->next;
            }
            tmpK--;
        }
        if (cLL->Size() != 1)
            cout << node->data << ", ";
        else
            cout << node->data << ">";
        if (node->next != cLL->Head())
            tmp = node->next;
        else
            tmp = cLL->Head()->next;
        cLL->pop(node);
        node = tmp;
    }

}

int main() {
    cLL = new circularLinkedList();
    input();
    solution();
    delete cLL;
}