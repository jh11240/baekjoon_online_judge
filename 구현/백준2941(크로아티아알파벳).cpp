#include<iostream>
#include<set>
using namespace std;

int main(){
    set<string> s;
    s.insert("c=");
    s.insert("c-");
    s.insert("dz=");
    s.insert("d-");
    s.insert("lj");
    s.insert("nj");
    s.insert("s=");
    s.insert("z=");

    string input;
    cin>>input;
    int numAlphabet=0;
    //입력으로 들어온 문장 길이만큼 반복
    for(int i=0;i<input.size();i++){
        int cur=i;
        string elem="";
        bool foundInSet=false;
        //크로아티아 알파벳이 최대 3글자이므로 현재 인덱스에서 3개만큼 봄
        for(cur;cur<i+3;cur++){
            //범위 넘어가면 인덱스오류나므로
            if(cur>=input.size()) break;
            elem += input[cur];
            //겹치는 문자가 (ex) d-, d--) 없으므로 찾으면 바로 종료
            if(s.find(elem)!=s.end()){
                numAlphabet++;
                foundInSet=true;
                break;
            }
        }
        if(!foundInSet)
            numAlphabet++;
        else 
            i=cur;
    }
    cout<<numAlphabet;
}