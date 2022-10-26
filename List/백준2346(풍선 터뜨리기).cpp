#include<iostream>

using namespace std;

int N;

//연결리스트에서 사용하는 노드
struct Node {
    int data;
    //각각 노드의 순서 저장
    int cnt;
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
    void push_back(int amount,int cnt) {
        if (size == 0) {
            Node* tmp = new Node;
            tmp->data = amount;
            tmp->cnt = cnt;
            head->prev = tmp;
            tmp->prev = head;
            tmp->next = head;
            head->next = tmp;
            size++;
        }
        else {
            Node* tmp = new Node;
            tmp->data = amount;
            tmp->cnt = cnt;
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
    //리스트사용시 head를 건드리면 안되므로 각 노드에서 head 노드인지 확인용
    Node* Head() {
        return head;
    }

};

circularLinkedList* cLL;

void input() {
    int tmp=0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        cLL->push_back(tmp,i);
    }
}
/// <summary>
/// 해당 원소 지우고 해당 원소의 값만큼 노드 이동한 후 노드값 반환
/// </summary>
/// <param name="node"></param>
/// <returns>모든 처리가 끝난 후 현재 노드</returns>
Node* RemoveAndTurn(Node* node) {
    //노드 지워야하므로 노드의 다음 노드 저장할 임시 노드
    Node* tmpNode =new Node;
    //몇번째 돌아가는지 저장용 변수, 노드 지워야하므로 지우기전 노드의 data값 저장용 변수
    int tmp=0,target=0;
    
    //노드의 값이 양수일 때
    if (node->data > 0) {
        tmp = 1;
        //해당노드 다음값 저장
        tmpNode = node->next;
        //head면 건드리면 안되므로 하나 더 이동
        if (tmpNode == cLL->Head()) tmpNode = tmpNode->next;
        //target에 노드의 데이터값 저장
        target=node->data;
        //지울 노드 순서 출력
        cout << node->cnt << " ";
        //노드 지움
        cLL->pop(node);
        //다음 값 노드 원래 노드 포인터에 저장
        node = tmpNode;
        //해당 노드값만큼 이동해야하므로 이동후 tmp값 ++ 하면서 체크
        while (tmp != target) {
            node = node->next;
            //마찬가지로 헤드값 건드리지 못하도록 하나 더 이동
            if (node == cLL->Head()) node = node->next;
            tmp++;
        }
    }
    //노드의 값이 음수일 때
    else {
        //위의 방식과 같지만 음수값만큼 뒤로가야하므로 tmp음수 설정후 tmp--
        tmp = -1;
        tmpNode = node->prev;
        if (tmpNode == cLL->Head()) tmpNode = tmpNode->prev;
        target = node->data;
        cout << node->cnt << " ";
        cLL->pop(node);
        node = tmpNode;
        while (tmp != target) {
            node = node->prev;
            if (node == cLL->Head()) node = node->prev;
            tmp--;
        }
    }
    return node;
    

}

void solution() {
    Node* node = new Node;

    //헤드 다음값 넣어줌.
    node=RemoveAndTurn(cLL->Head()->next);
    //위에서 한번 진행했으므로 N-1번 반복
    for (int i = 1; i < N; i++) {
        node=RemoveAndTurn(node);
    }
}

int main() {
    cLL = new circularLinkedList();
    input();
    solution();
    delete cLL;
}