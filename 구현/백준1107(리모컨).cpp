#include<iostream>
#include<set>
#include<math.h>
#include<vector>

using namespace std;
set<int> notWorking;
//vector<int> v[7];
int Min=500'000;

int MinimumBtn(int targetNum){
    //reconfigure number
    int cur = targetNum,digit=0,reconfigured=0;
    bool isLowered=false,isHighered=false;
    while(cur!=0){
        digit++;
        cur/=10;
    }
    cur=targetNum;
    while(!isLowered && !isHighered && digit!=0){
        int digitNum = cur/pow(10, digit-1);
         cur/=pow(10,digit-1);
        //만약 digitnum이 고장나지 않은 수라면 바로 해당 자리에 push
        if(notWorking.find(digitNum) == notWorking.end()){
            reconfigured+=digitNum*pow(10,digit-1);
            digit--;
            continue;
        } 
        //고장난 수라면
        else{
            //1씩 더하면서 고장나지 않은 수 탐색
            int plusDigitNum=digitNum;

            while(plusDigitNum<10){
                plusDigitNum++;
                if(notWorking.find(plusDigitNum)!= notWorking.end()){
                    continue;
                }
                break;
            }
            //1씩 빼면서 고장나지 않은 수 탐색
            int minusdigitNum=digitNum;
            while(minusdigitNum>=0){
                minusdigitNum--;
                if(notWorking.find(minusdigitNum)!= notWorking.end()){
                    continue;
                }
                break;
            }
            //전부 고장난 수라면 
            if(plusDigitNum == 10 && minusdigitNum ==-1){
                return targetNum - 100>0? targetNum-100 : -(targetNum-100);
            } 
            //digitnum부터 10까지 다 고장났다면
            else if(plusDigitNum==10){
                reconfigured += (minusdigitNum)*pow(10,digit-1);
                isLowered = true;
                digit--;
                continue;
            }
            //digitnum부터 0까지 다 고장났다면
            else if(minusdigitNum==-1){
                reconfigured += (plusDigitNum)*pow(10,digit-1);
                isHighered = true;
                digit--;
                continue;
            }
        }
    }
    //만약 숫자가 줄어들었다면 밑의 자릿수는 무조건 제일 큰걸로 도배해야함 ~9
    if(isLowered){
        int highestNum=9;
        for(int i=9;i>=0;i--){
            if(notWorking.find(i) == notWorking.end()){
                highestNum = i;
                break;
            }
        }
        for(int i= digit ;i>0;i--){
            reconfigured += highestNum * pow(10,digit-1);
        }
    }
    //만약 숫자가 커졌다면 밑 자릿수들은 전부 제일 작은 자릿수로 도배 0~
    if(isHighered){
        int lowestNum = 0;
        for (int i = 0; i <= 9; i++)
        {
            if (notWorking.find(i) == notWorking.end())
            {
                lowestNum = i;
                break;
            }
        }
        for (int i = digit; i > 0; i--)
        {
            reconfigured += lowestNum * pow(10, digit - 1);
        }
    }
    return reconfigured-targetNum > 0? reconfigured - targetNum: -(reconfigured-targetNum);
}

  

int main(){
    int targetNum, notWorkingAmount,notWorkingNum;
    cin>>targetNum;
    for(int i=0;i<notWorkingAmount;i++){
        cin>>notWorkingNum;

        notWorking.insert(notWorkingNum);
    }
    cout<<MinimumBtn(targetNum);
}