#include<iostream>

using namespace std;
int rooms[51][51];
bool cleaned[51][51];

// 북, 동, 남, 서
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

enum dir 
{
    North,
    East,
    South,
    West
};

int cleanedArea=0;  //청소한 범위


void DFS(int curX,int curY,dir curDir,int N,int M)
{

    //현재 칸 청소가 안되었다면 청소
    if(!cleaned[curX][curY])
    {
        cleaned[curX][curY] =true;
        cleanedArea ++;
    }

    int d = (int)curDir;
    //현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 없다면
    for(int i=0;i<4;i++)
    {
        d= (d+3)%4;
        int nextX = curX + dx[d];
        int nextY = curY+ dy[d];

        if(nextX<0 || nextY <0 || nextX>=N || nextY >= M)
            continue;

        //벽이라면 패스
        if(rooms[nextX][nextY] == 1)
            continue;

        //청소 안 한 구역이 존재하면
        if(!cleaned[nextX][nextY])
        {  
            // i와 dir 의 인덱스순서는 동일하므로 방향에 i를 그대로 넣어준다.
            DFS(nextX,nextY,(dir)d,N,M);
            return; // 청소했다면 다시 1로
        }
    }

    // 주위 네칸중 청소되지 않은 빈 칸이 없는 경우

        //curIDr를 인덱스로 변경
        int dirIdx = (int)curDir;
        //후진 좌표
        int backPosX = curX -dx[dirIdx];
        int backPosY = curY - dy[dirIdx];

        if(backPosX<0 || backPosY<0 || backPosX>=N || backPosY>=M) return;


        //벽이라면 작동 중지
        if(rooms[backPosX][backPosY] == 1)
            return ;

        else
            DFS(backPosX,backPosY,curDir,N,M);

}

int main()
{
    int N,M;

    cin>>N>>M;

    int startX,startY,curDirNum;
    cin>>startX>>startY>>curDirNum;

    dir curDir = static_cast<dir>(curDirNum);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>rooms[i][j];
        }
    }

     DFS(startX,startY,curDir,N,M);
    cout<<cleanedArea;
    
}