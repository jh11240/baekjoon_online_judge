// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> dp;
// int arr[1001];
// int N;

// int main(){
//     cin>>N;

//     for(int i=0;i<N;i++){
//         cin>>arr[i];
//     }    

//     // 핵심 논리
//     // arr을 순회하며 현재 arr[i]값이 dp의 마지막 값보다 작다면 push
//     //dp의 마지막 값보다 크면 dp에서 arr[i]보다 작은 수 중 제일 큰 수를 교체 함
//     // ex 30 20 10 에 40이 들어올 차례라면 30이 40보다 작은 수중 제일 큰수 -> 40 20 10
//     //이유는 20 10 40 30 10 이런 수열에서 dp가 30 20 으로 구성되어있다가 더 큰 수가 오면 앞부분을 변경해줘야 원활하게 40 30 값이 들어옴
//     for( int i=0;i<N;i++){
//         if(dp.empty() || dp.back() > arr[i])
//         {
//             dp.push_back(arr[i]);
//             continue;
//         }
//         else if(dp.back() < arr[i]){
//             for(int j=0;j<dp.size();j++){
//                 if( dp[j]> arr[i]) continue;
//                 dp[j]=arr[i];
//                 break;
//             }
//         }

//     }
//     cout<<dp.size();
// }


#pragma region using dp


#include<iostream>
#include<vector>
using namespace std;
int dp[1002];
int arr[1001];
int N;

int main(){
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }    
    fill(&dp[0],&dp[1001],1);
    int maxLength=1;

    for( int i=0;i<N;i++){

        for(int j=0;j<i;j++){
            if(arr[i]< arr[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }

        }
        maxLength= max(dp[i],maxLength);
    }
    cout<< maxLength;

    
}

#pragma endregion