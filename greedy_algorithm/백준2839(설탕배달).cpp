#include<iostream>
using namespace std;

int main(){
    int N,amount5,remain,amount3;
    cin>>N;
    //5키로를 사용할 수 있는 총 갯수
    amount5=N/5;
    
    for(int i=amount5;i>=0;i--){
        remain=N-5*i;
        if(remain%3==0){
            amount3=remain/3;
            cout<<i+amount3;
            return 0;
        }

    }
    cout<<-1;
    
}