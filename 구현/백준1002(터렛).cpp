#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;


int main(){
    int T,x1,y1,r1,x2,y2,r2;
    double dist;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        //두원의 중심 사이 거리
        dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

        //포개질 때 
        if(dist==0 && r1==r2) cout<<-1<<"\n";
        //두 원이 떨어져 있으면
        else if(r1+r2<dist) cout<<0<<"\n";

        //한점에서 만나면
        else if(r1+r2==dist) cout<<1<<"\n";

        //두 원이 두점에서 만나는 상태
        else if(r1+r2>dist && dist > max(r1,r2)-min(r1,r2)) cout<<2<<"\n";

        //한원이 한원 내부에서 한점과 만나는 상태
        else if(dist == max(r1,r2)-min(r1,r2)) cout<<1<<"\n";

        //한원이 한원 내부에 있는 상태 
        else if(dist < max(r1,r2)-min(r1,r2)) cout<<0<<"\n";

    }
}