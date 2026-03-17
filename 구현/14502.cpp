#include<iostream>
#include <cstring>
#include<vector>
using namespace std;
vector<pair<int,int>> curCombination;
vector<pair<int,int>> virusLoc;
vector<pair<int,int>> spaceLoc;
int field[9][9];
int tmpField[9][9];
int dx[4] = { -1,1,0,0};
int dy[4] = {0,0,-1,1};
int maxSafeArea=0;
void SpreadVirus(int startX,int startY,int N,int M)
{
    tmpField[startX][startY] = 2;
    
    for(int i=0;i<4;i++)
    {
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];

        if(nextX<0 || nextY<0 || nextX>=N || nextY >= M) continue;

        if(tmpField[nextX][nextY] != 0 ) continue;

        SpreadVirus(nextX,nextY,N,M);


    }

    
}

//startX와 startY에서 바이러스 진행되었을 경우
int GetSafeArea(int N,int M)
{
    //임시 필드 초기화
    memcpy(tmpField,field,sizeof(field));

    for(auto& elem :curCombination)
    {
        tmpField[elem.first][elem.second] = 1;
    }
    for(auto& elem : virusLoc)
        SpreadVirus(elem.first,elem.second,N,M);

    int safeARea=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            if(tmpField[i][j] ==0)
            safeARea++;
    }
    return safeARea;

}

void PickWallLoc(int curIdx, int selectedCnt,int N,int M)
{
    if(spaceLoc.size()-curIdx <3-selectedCnt) return;
    if(selectedCnt == 3)
    {
        maxSafeArea = max(maxSafeArea,GetSafeArea(N,M));
        return;
    }
    if(curIdx >= spaceLoc.size()) return;

    PickWallLoc(curIdx+1,selectedCnt,N,M);
    curCombination.push_back(spaceLoc[curIdx]);
    PickWallLoc(curIdx+1,selectedCnt+1,N,M);
    curCombination.pop_back();

}


int main()
{
    int N,M;

    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int type=0;
            cin>>type;
            field[i][j] = type;
            if(type ==0) spaceLoc.push_back(make_pair(i,j));
            else if(type ==2) virusLoc.push_back(make_pair(i,j));
        }
    }
    PickWallLoc(0,0,N,M);
    cout<<maxSafeArea;

}