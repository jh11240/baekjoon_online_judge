//https://www.acmicpc.net/problem/15990

#include<iostream>

using namespace std;

long long dp[100'001][4]; //마지막에 더한 숫자
const int MOD = 1'000'000'009;

void solve()
{
    dp[1][1] =1;
    dp[2][2] =1;
    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;

    for(int i=4;i<=100'000;i++)
    {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3] )% MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3] )% MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2] )% MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    solve();
    for(int i=0;i<T;i++)
    {
        int tmp;
        cin>>tmp;
        long long ans = (dp[tmp][1] + dp[tmp][2] + dp[tmp][3]) % MOD;
        cout << ans << "\n";
    }
}
