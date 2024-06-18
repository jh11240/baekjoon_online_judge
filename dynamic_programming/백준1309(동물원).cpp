#include<iostream>
#include<vector>

using namespace std;

//0 for 0,0 / 1 for 0,1 / 2 for 1,0
int dpArr2[100'002][3];
int N;

int Dp(int idx, int idx2) {
   int* ret = &dpArr2[idx][idx2];
    if (idx == 0) {
        *ret = 1;
        return *ret;
    }
    if (*ret != -1) return *ret;

    if (idx2 == 0)
        *ret = ((Dp(idx - 1, 0) % 9901) + (Dp(idx - 1, 1) % 9901) + (Dp(idx - 1, 2) % 9901))%9901;
    else if (idx2 == 1)
        *ret = ((Dp(idx - 1, 0) % 9901) + (Dp(idx - 1, 2) % 9901))%9901;
    else
        *ret = ((Dp(idx - 1, 0) % 9901) + (Dp(idx - 1, 1) % 9901))%9901;

    return *ret % 9901;
}

int main() {
    cin >> N;
    fill(&dpArr2[0][0], &dpArr2[100'001][2], -1);
    int answer = (Dp(N-1, 0) + Dp(N-1, 1) + Dp(N-1, 2))%9901;
    cout << answer % 9901;
}