#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int>>> adj;

int parent[10'001];
int GetParent(int x)
{
    if(x==parent[x]) return x;

    return parent[x] = GetParent(parent[x]);
}

void MakeGroup(int x,int y)
{
    x = GetParent(x);
    y = GetParent(y);

    if(x!=y)
        parent[x] = y;
}
int main()
{
    int V,E;
    cin>>V>>E;

    for(int i=1;i<=V;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<E;i++)
    {
        int s,d,l;
        cin>>s>>d>>l;
        adj.push_back(make_pair(l,make_pair(d,s)));
    }
    sort(adj.begin(),adj.end());
    long long totalWeight=0;
    for(auto& elem: adj)
    {
        int vertex1= elem.second.first;
        int vertex2 = elem.second.second;
        //같으면 연결된거임
        if(GetParent(vertex1) == GetParent(vertex2))
            continue;
        else
            {MakeGroup(vertex1,vertex2);
            totalWeight+= elem.first;}
    }
cout<<totalWeight;
}