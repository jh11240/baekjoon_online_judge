#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> curCombination;
vector<pair<int,int>> chickenHouseLoc;
vector<pair<int,int>> houseLoc;
int cities[51][51];
int minCityChickenDist = 1e9;

int ChikenDistance(const pair<int,int>& start,const pair<int,int>& target)
{
    return abs(start.first - target.first) + abs(start.second-target.second);
}

void Calculate()
{
    int totalChickenDist=0;
    for(auto& i : houseLoc)
    {
        int minChickenDist=1e9;
        for(auto& j : curCombination)
        {
            minChickenDist= min(minChickenDist, ChikenDistance(i,j));
        }
        totalChickenDist += minChickenDist;
    }
    minCityChickenDist = min(minCityChickenDist,totalChickenDist);

}

/// @brief 선택하거나 선택안하면서 조합 고르기
/// @param curIdx 
/// @param maxIdx 
/// @param selectedCnt 현재 선택한 횟수 (가지치기용)
void DFS(int curIdx,int selectedCnt,int maxSelect)
{


    if(selectedCnt == maxSelect) 
    {
        Calculate();
        return;
    }
    if(curIdx == chickenHouseLoc.size()) return;

    DFS(curIdx+1,selectedCnt,maxSelect);

    //현재 치킨집 넣기
    curCombination.push_back(chickenHouseLoc[curIdx]);
    DFS(curIdx+1,selectedCnt+1,maxSelect);
    //빠져나왔으므로 빼기
    curCombination.pop_back();


}

int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>cities[i][j];
            if(cities[i][j] ==1)
                houseLoc.push_back(make_pair(i,j));
            else if(cities[i][j] == 2)
                chickenHouseLoc.push_back(make_pair(i,j));
        }
    }
    DFS(0,0,M);
    cout<<minCityChickenDist;
}