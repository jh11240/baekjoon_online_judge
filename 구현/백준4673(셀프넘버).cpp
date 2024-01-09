#include<iostream>
using namespace std;

bool isSelfNum[10'001];

void checkD(int N){
    int cur=N;

    while(cur<=10'000){
        int origin=cur;
        int digitSum=0;
        //get all digit
        while(origin>0){
            digitSum+=origin%10;
            origin/=10;
        }
        cur+=digitSum;
        isSelfNum[cur]=false;
    }
}

int main(){
    fill(isSelfNum,isSelfNum+10'001,true);
    for(int i=1;i<10000;i++){
        if(!isSelfNum[i])continue;
        checkD(i);
    }

    for(int i=1;i<10000;i++){
        if(isSelfNum[i]) cout<<i<<"\n";
    }
}