#include<iostream>
#include<vector>
using namespace std;

int arr[4][8];

struct wheelPointer
{
    int topIdx;
    void RotateCounterClockWise(){topIdx = (topIdx+1)%8;};
    void RotateClockWise(){topIdx = (8+topIdx-1)%8;};
    int LeftIdx() { return (8+topIdx-2)%8;};
    int RightIdx() { return (topIdx+2)%8;};
};

wheelPointer pointers[4];

//wheelCnt에 해당하는 톱니 회전
void Rotate(int wheelCnt,int rotateDir)
{
    // 시계
    if(rotateDir >0)
        pointers[wheelCnt].RotateClockWise();

    else
        pointers[wheelCnt].RotateCounterClockWise();
}
void CheckLeft(int idx,int dir)
{
    if(idx<=0)  return;

    //내 왼쪽과 옆 휠의 오른쪽이 다르다면 
    if(arr[idx][pointers[idx].LeftIdx()] != arr[idx-1][pointers[idx-1].RightIdx()])
    {
        //들어온 인자값과 반대를 회전
        CheckLeft(idx-1,-dir);
        Rotate(idx-1,-dir);
    }
}

void CheckRight(int idx,int dir)
{
    if(idx>=3) return;

        //내 오른쪽과 옆 휠의 왼쪽이 다르다면 
    if(arr[idx][pointers[idx].RightIdx()] != arr[idx+1][pointers[idx+1].LeftIdx()])
    {
        CheckRight(idx+1,-dir);
        Rotate(idx+1,-dir);
    }
}

// 0번부터 3번까지 left right 극 분석해서 어떤게 영향을 받는지 체크
void RotateController(int wheelCnt, int rotateDir)
{

    
    CheckLeft(wheelCnt,rotateDir);
    CheckRight(wheelCnt,rotateDir);
    //기존 바퀴 돌리기
    Rotate(wheelCnt, rotateDir);
}

int main()
{
    
    for(int i=0;i<4;i++)
    {
        string state ;
        cin>>state;
        for(int j=0;j<8;j++)
        {

            arr[i][j]=state[j]-'0';
        }
    }

    int RotateCnt =0;
    cin>>RotateCnt;

    for(int i=0;i<RotateCnt;i++)
    {
        int wheelCnt,rotateDir;

        cin>>wheelCnt>>rotateDir;

        RotateController(wheelCnt-1,rotateDir);
    }

    int totalAnswer=0;

    if(arr[0][ pointers[0].topIdx] == 1)
        totalAnswer+=1;
    if(arr[1][ pointers[1].topIdx] == 1)
        totalAnswer+=2;
    if(arr[2][ pointers[2].topIdx] == 1)
        totalAnswer+=4;
    if(arr[3][ pointers[3].topIdx] == 1)
        totalAnswer+=8;

    cout<<totalAnswer;
}