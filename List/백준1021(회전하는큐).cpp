#include<iostream>

using namespace std;

int N, M;
int inputArr[51];

//연결리스트에서 사용하는 노드
struct Node {
    int data;
    Node* prev;
    Node* next;
};

//이중 연결리스트
class doubledLinkedList {
private:
    int size;
    Node* head;
    Node* tail;

public:
    //생성자
    doubledLinkedList() {
        size = 0;
        Node* tmpHead = new Node;
        Node* tmpTail = new Node;
        tmpHead->data = -1;
        tmpTail->data = -1;
        tmpHead->prev = tmpHead;
        tmpHead->next = tmpTail;
        tmpTail->prev = tmpHead;
        tmpTail->next = tmpTail;
        head = tmpHead;
        tail = tmpTail;
    }
    //소멸자
    ~doubledLinkedList() {
        Node* node = new Node;
        Node* node1 = new Node;
        node = head;
        while (node != tail) {
            node1 = node;
            node = node->next;
            delete node1;
        }
        //반복문 빠져나올시 tail이므로
        delete node;
    }
    //맨 앞값 불러오기
    int front() {
        return head->next->data;
    }
    //맨 뒷값 불러오기
    int back() {
        return tail->prev->data;
    }
    //앞으로 집어넣기
    void push_front(int amount) {
        if (size == 0) {
            Node* tmp = new Node;
            tmp->data = amount;
            head->next = tmp;
            tmp->prev = head;
            tmp->next = tail;
            tail->prev = tmp;
            size++;
        }
        else {
            Node* tmp = new Node;
            tmp->data = amount;
            head->next->prev = tmp;
            tmp->next=head->next;
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
            head->next = tmp;
            tmp->prev = head;
            tmp->next = tail;
            tail->prev = tmp;
            size++;
        }
        else {
            Node* tmp = new Node;
            tmp->data = amount;
            tail->prev->next = tmp;
            tmp->prev = tail->prev;
            tmp->next = tail;
            tail->prev = tmp;
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
            Node* tmp = tail->prev;
            tmp->prev->next = tail;
            tail->prev = tmp->prev;
            delete tmp;
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
        Node* tmp = head;
        while (tmp != tail) {
            tmp = tmp->next;
            cnt++;
            if (tmp->data == target) return cnt;
        }
        return -1;
    }
    //중간중간 원소들 확인용
    void Print() {
        Node* tmp = head;
        while (tmp != tail) {
            cout << tmp->data<<" ";
            tmp = tmp->next;
        }
        cout << endl;
    }

};

doubledLinkedList* dLL;

/// <summary>
/// target뺄때 2,3번 몇번 돌려야하는지 체크하는 함수
/// </summary>
/// <param name="target"></param>
/// <returns>사용한 2,3번 갯수</returns>
int check(int target) {
    int targetCnt, differ, tmp,retCnt=0;
    //타겟이 덱에 몇번째로 들어있는지 순서
    targetCnt = dLL->Find(target);
    if (targetCnt < 0) return -1;
    //덱 전체 사이즈 - 타겟의 순서
    differ = dLL->Size() - targetCnt;
    //전체 리스트에서 왼쪽에 있다면
    if (differ >= (dLL->Size() / 2)) {
        for (int i = 0; i < targetCnt-1; i++) {
            tmp = dLL->front();
            dLL->pop_front();
            dLL->push_back(tmp);
            retCnt++;
        }
        //target값은 방출
        dLL->pop_front();

        return retCnt;
    }

    //전체 리스트에서 오른쪾에 있다면
    else {
        for (int i = 0; i < differ+1; i++) {
            tmp = dLL->back();
            dLL->pop_back();
            dLL->push_front(tmp);
            retCnt++;

        }
        //target값은 방출
        dLL->pop_front();

        return retCnt;
    }
   
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> inputArr[i];
    }
    for (int i = 1; i <= N; i++) {
        dLL->push_back(i);
    }
}
void solution() {
    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans += check(inputArr[i]);
    }
    cout << ans;
}

int main() {
    dLL = new doubledLinkedList();
    input();
    solution();
    delete dLL;
}