#include<iostream>

using namespace std;

//index숫자를 만드는 경우의 수
long long dp[1'000'002];
int N,tmpNum;

int main(){
    dp[1]=1;
    dp[2]=2;
    //dp [1] + dp[2]+ 1(3도 되므로)
    dp[3]=4;
    //dp[1]+dp[2]+dp[3]
    dp[4]=7;

    /*
    dp[5]= 1+4의꼴 (dp[4]), 2+3의 꼴 (dp[3]),3 +2 꼴 (dp[2]) 13
    dp[6]=1+5 (dp[5]) +2+4 (dp[4]) +3+3 (dp[3])  = 24
    dp[7] =1+6 (dp[6]), 2+5(dp[5]), 3+4(dp[4]) = 44
    
    */
   cin>>N;

    for(int i=5;i<=1'000'001;i++ ){
        //dp[i-1]은 dp[i-1]까지의 모든 합 
        dp[i] = (dp[i-1]%1'000'000'009 + dp[i-2]%1'000'000'009+dp[i-3]%1'000'000'009)%1'000'000'009;
    }

    for(int i=0;i<N;i++){
        cin>>tmpNum;
        cout<<dp[tmpNum]<<"\n";
    }
}