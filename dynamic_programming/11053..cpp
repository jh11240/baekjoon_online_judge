#include <iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<memory>
using namespace std;

int dp[1000];
int num[1000];

int main()
{
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>num[i];
    }

    fill(dp,dp+1001,1);

    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            if(num[j]>num[i])
                dp[j] = max(dp[j],dp[i]+1);
        }
    }
    int maxN= 0;
    for(int i=0;i<N;i++)
    {
        maxN = max(maxN,dp[i]);
    }
    cout<<maxN;
}