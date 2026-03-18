#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    string sentence;
    string target;

    getline(cin,sentence);
    getline(cin,target);
    cin>>target;
    int answer=0;
    int pos=0;
    
    while((pos= sentence.find(target,pos)) != string::npos )
{
    answer++;
    pos += target.length();
}
    cout<<answer;
}