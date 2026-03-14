#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//키는 시작점, value의 first 도착점, second 시간
vector<pair<int,int>> adj[10'001];
//first 는 거리,second 는 지점
priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>> pq;
long long dist[10'001];
const long long INF = 1e18;
void Dijkstra(int start,int n)
{
    while(!pq.empty()) pq.pop();
    fill(&dist[0],&dist[0]+n+1,INF);
    pq.push(make_pair(0,start));
    dist[start]=0;

    while(!pq.empty())
    {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        
        if(curDist> dist[curNode]) continue;

        for(auto& val : adj[curNode])
        {
            int nextNode= val.first;
            int nextDist= val.second;
            

            if(dist[nextNode]> curDist+nextDist )
            {
                dist[nextNode] = curDist + nextDist;
                pq.push({dist[nextNode],nextNode});
            }
        }
    }

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,d,c;
        cin>>n>>d>>c;
        for(int i=1;i<=n;i++)
        adj[i].clear();
        // 의존성 갯수 처리
        for(int i=0;i<d;i++)
        {
            //목적지,출발지, 길이 순서
            int d,s,l;
            cin>>d>>s>>l;
            adj[s].push_back(make_pair(d,l));
        }
        //다익스트라 돌리고
        Dijkstra(c,n);

        int hackedComCnt=0;
        long long hackedTime=0;
        //해킹당한 컴퓨터와 시간 출력
        for(int i=1;i<=n;i++)
        {
            if(dist[i] == INF) continue;
            hackedComCnt++;
            hackedTime= max(dist[i],hackedTime);
        }
        cout<<hackedComCnt<<" "<<hackedTime<<"\n";
    }
    

}