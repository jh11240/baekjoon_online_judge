#include<iostream>
using namespace std;

bool IsHanNum(int N) {
    int cur = N, prev = -1, diff = -1000;
    while (cur != 0) {
        //처음 시작일 때
        if (prev == -1) {
            prev = cur % 10;
            cur /= 10;
            continue;
        }
        //두번째 순서일때
        if (diff == -1000) {
            diff = prev - (cur % 10);
            prev = cur % 10;
            cur /= 10;
            continue;
        }
        //등차수열이 아닌 경우
        if (diff != (prev - (cur % 10))) {
            return false;
        }
        prev = cur % 10;
        cur /= 10;
    }
    return true;
}

int main() {
    int N, Ans = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (IsHanNum(i)) Ans++;
    }
    cout << Ans;
}