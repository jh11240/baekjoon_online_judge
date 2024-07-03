#pragma region bottom-up dynamic programming
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int dp[1'000'002];
//value is prev num of idx
int prevNum[1'000'002];
int Dp(int idx){
    int*ret = &dp[idx];
    if(*ret != -1) return *ret;
    if(idx<1) return 0;

}

int main(){
    cin>>N;
    fill(&dp[0],&dp[1'000'001],1'000'002);
    dp[1]=0;
    dp[2]=1;
    prevNum[2]=1;
    dp[3]=1;
    prevNum[3]=1;
    for(int i=1;i<N+1;i++){
        //max idx is 1'000'001
        if(i*3<=1'000'000){
            //if minimum num changed 
            if(dp[i]+1<dp[i*3]){
                //reassign
                prevNum[i*3]=i;
                dp[i*3]=dp[i]+1;
            }
        }
        //max idx is 1'000'001
        if(i*2<=1'000'000){
            //if minimum num changed 
            if(dp[i]+1<dp[i*2]){
                //reassign
                prevNum[i*2]=i;
                dp[i*2]=dp[i]+1;
            }

        }
        //max idx is 1'000'001
        if(i+1<=1'000'000){
            //if minimum num changed 
            if(dp[i]+1<dp[i+1]){
                //reassign                
                prevNum[i+1]=i;
                dp[i+1]=dp[i]+1;
            }
        }
    }
    cout<<dp[N]<<"\n"<<N<<" ";
    int tmpIdx=N;
    while(tmpIdx!=1){
        cout<<prevNum[tmpIdx]<<" ";
        tmpIdx=prevNum[tmpIdx];
    }
}

#pragma endregion

#pragma region top-down programming
// #include<iostream>
// #include<algorithm>
// using namespace std;

// int N;
// int dp[1'000'002];
// //value is prev num of idx
// int prevNum[1'000'002];
// int Dp(int idx) {
//     int* ret = &dp[idx];
//     if (*ret != 1'000'002) return *ret;
//     if (idx < 1) return 0;
//     int prevDp;
//     if (idx % 3 == 0) {
//         prevDp = Dp(idx / 3) + 1;
//         if (*ret > prevDp) {
//             prevNum[idx] = idx / 3;
//             *ret = prevDp;
//         }
//     }
//     if (idx % 2 == 0) {
//         prevDp = Dp(idx / 2) + 1;
//         if (*ret > prevDp) {
//             prevNum[idx] = idx / 2;
//             *ret = prevDp;
//         }
//     }
//     prevDp = Dp(idx-1) + 1;
//     if (*ret > prevDp) {
//         prevNum[idx] = idx-1;
//         *ret = prevDp;
//     }
//     return *ret;
// }

// int main() {
//     cin >> N;
//     fill(&dp[0], &dp[1'000'001], 1'000'002);
//     dp[1] = 0;
//     dp[2] = 1;
//     prevNum[2] = 1;
//     dp[3] = 1;
//     prevNum[3] = 1;

//     cout << Dp(N) << "\n" << N<<" ";
//     int tmpIdx = N;
//     while (tmpIdx != 1) {
//         cout << prevNum[tmpIdx] << " ";
//         tmpIdx = prevNum[tmpIdx];
//     }
// }
#pragma endregion