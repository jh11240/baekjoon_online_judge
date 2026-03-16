#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int weight[31];

void GetSum(int curIdx,int curWeight,int maxIdx,int maxWeight,vector<int>& sum)
{
    if(curIdx==maxIdx) 
    {
        sum.push_back(curWeight);
        return;
    }

    if(curWeight+(long long)weight[curIdx] <=maxWeight)
        GetSum(curIdx+1,curWeight+weight[curIdx],maxIdx,maxWeight,sum);

    GetSum(curIdx+1,curWeight,maxIdx,maxWeight,sum);
}


int main()
{
    int N,C;
    cin >> N>>C;

    for(int i=0;i<N;i++)
    {
        cin>>weight[i] ;
    }
    vector<int> SumA;
    vector<int> SumB;
    //0부터 n/2까지 모든 조합 구하기
    GetSum(0,0,N/2,C,SumA);
    //n/2부터 n까지의 모든 조합 구하기
    GetSum(N/2,0,N,C,SumB);

    //sumb를 이분탐색할것이므로 정렬
    sort(SumB.begin(),SumB.end());

    int leftOver=0,totalCnt=0;
    //sumA를 순회하며 꺼낸 elem과 합해서 C가 안넘는 조합의 갯수를 sumB에서 구하기
    for(int elem : SumA)
    {
         leftOver = C-elem;
         totalCnt += upper_bound(SumB.begin(),SumB.end(),leftOver) - SumB.begin();
    }

    cout<<totalCnt;
}