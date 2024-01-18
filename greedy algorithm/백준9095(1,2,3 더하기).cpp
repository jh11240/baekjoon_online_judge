#pragma region casebycase 
// #include<iostream>
// using namespace std;

// int HowManyWays(int N) {
//     // 3을 사용할수 있는 최대 갯수
//     int amount3 = N / 3, usedNum = 0, amount2, used3 = 0, used2 = 0, used1 = 0;
//     // 3을 최대 개수부터 0개까지 사용했을 때 반복문
//     for (int i = amount3; i >= 0; i--)
//     {
//         int cur = N;
//         cur -= i * 3;
//         used3 = i;
//         amount2 = cur / 2;
//         //3을 i개만큼 사용하고 남은 수에서 2를 최대 갯수부터 0개 까지 사용했을 때 반복문
//         for (int j = amount2; j >= 0; j--)
//         {
//             int tmp = cur;
//             tmp -= j * 2;
//             used2 = j;
//             //2사용하고 남은 숫자가 곧 1의 갯수
//             used1 = tmp;

//             //같은 원소를 가진 순열 계산
//             int allMul = 1, Mul3 = 1, Mul2 = 1, Mul1 = 1;
//             for (int k = 1; k <= used3 + used2 + used1; k++)
//             {
//                 allMul *= k;
//             }
//             for (int k = 1; k <=used3; k++)
//             {
//                 Mul3 *= k;
//             }
//             for (int k = 1; k <= used2; k++)
//             {
//                 Mul2 *= k;
//             }
//             for (int k = 1; k <= used1; k++)
//             {
//                 Mul1 *= k;
//             }
//             usedNum += (allMul / (Mul3 * Mul2 * Mul1));

//         }
//     }
//     return usedNum;
// }

// int main() {
//     int testCase, targetNum;
//     cin >> testCase;

//     for (int i = 0; i < testCase; i++) {
//         cin >> targetNum;
//         cout << HowManyWays(targetNum)<<"\n";
//     }
// }

#pragma endregion

#pragma region dynamic programming

#include<iostream>
using namespace std;
int dp[12];
void Init(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<=11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
}

int main()
{
    int T, targetNum;
    cin >> T;
    Init();
    for (int i = 0; i < T; i++)
    {
        cin >> targetNum;
        cout << dp[targetNum] << "\n";
    }
}
#pragma endregion