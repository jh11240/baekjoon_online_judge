// #include<iostream>
// using namespace std;

// bool isPrime(int N){
//     if(N==1) return false;
//     for(int i=2;i<=N/2;i++){
//         if(N%i==0){
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     int M,N;

//     cin>>M>>N;

//     for(int i=M;i<=N;i++){
//         if(isPrime(i))cout<<i<<"\n";
//     }
// }

#include<iostream>
#include<math.h>
using namespace std;

bool prime[1'000'000];

bool isPrime(int N){
    for(int i=2;i<=sqrt(N);i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

void initNum(){
    prime[1]=false;
    for (int i = 2; i <= 11; i++)
    {
        for(int j=2;i*j <= 1'000'000;j++){
            if(!prime[i*j]) continue;
            prime[i*j]=false;
        }
    }
    
}

int main(){
    fill(prime,prime+1'000'000,true);
    initNum();

    int M, N;
    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        if (!prime[i])
            continue;
        if (isPrime(i))
        {
            cout << i << "\n";
        }
    }
}
