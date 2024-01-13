#include<iostream>
#include<vector>
using namespace std;

vector<int> v[101];
bool visited[101];

int DFS(int cur) {
    int sum = 1;

    for (int elem : v[cur]) {
        if (visited[elem]) continue;
        visited[elem] = true;
        sum += DFS(elem);
    }
    return sum;

}

int main() {
    int amountCom, connection, comA, comB;

    cin >> amountCom >> connection;
    for (int i = 0; i < connection; i++) {
        cin >> comA >> comB;
        v[comA].push_back(comB);
        v[comB].push_back(comA);
    }
    //DFS내부의 for문에서 방문 처리하는 특성상 1은 처리 못함
    visited[1] = true;
    cout << DFS(1)-1;

}