#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L = 0, C = 0;
char Letters[16];
char vowels[5] = { 'a','e','o','i','u' };
vector<char>Ans;
vector<string>printAns;

void Input() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> Letters[i];
	}
	//알파벳순으로 정렬
	sort(Letters, Letters + C);
}
/// <summary> 
/// Index를 parameter로 받아와서 Ans 길이가 답 배열과 같으면 Ans출력
/// 해당 index값을 안더해준것과 더해준 것으로 재귀를 나눠서 진행
/// 끝나고 Ans에서 해당 값을 빼줌으로서 노드 방문 초기화
/// </summary>
/// <param name="Index(cur)"></param>
void DFS(int cur, int consonant, int vowel) {
	//index가 끝에 다다르면 return한다.
	if (cur == C) return;
	//Ans.size가 L일때 출력하면 안되는 게, 만약 cur이 c-1일때 마지막값을 푸시하고 DFS(cur+1)을 실행하면
	// cur+1은 c이므로 return 당해서 출력 하는 부분이 호출이 안됨.
	if (Ans.size() == L - 1) {
		//cur인덱스의 글자가 모음이라면
		if (Letters[cur] == 'a' || Letters[cur] == 'e' || Letters[cur] == 'i' || Letters[cur] == 'o' || Letters[cur] == 'u') {
			// 지금까지 자음이 2개 이상이여야함
			if (consonant >= 2) {
			string tmp = "";
			//char문자들 합쳐준 후
			for (auto iter = Ans.begin(); iter != Ans.end(); ++iter) {
				tmp += *iter;
			}
			//cur인덱스에 해당하는 문자까지 추가해서 답벡터에 넣어줌
			printAns.push_back(tmp + Letters[cur]);
			}

		}
		//cur인덱스의 글자가 자음이라면 지금까지 자음,모음이 1개이상씩 있어야함
		else if (consonant >= 1 && vowel >= 1) {
				string tmp = "";
				for (auto iter = Ans.begin(); iter != Ans.end(); ++iter) {
					tmp += *iter;
				}
				//cur인덱스에 해당하는 문자까지 추가해서 답벡터에 넣어줌
				printAns.push_back(tmp + Letters[cur]);
		}
		//위의 조건에 해당 안되면 패스
	}

	//cur인덱스의 문자 패스하고 dfs
	DFS(cur + 1, consonant, vowel);

	//cur인덱스의 문자 포함해주고 
	Ans.push_back(Letters[cur]);
	if (Letters[cur] == 'a' || Letters[cur] == 'e' || Letters[cur] == 'i' || Letters[cur] == 'o' || Letters[cur] == 'u')
		//만약 문자가 모음이면 vowel+1해주고 dfs
		DFS(cur + 1, consonant, vowel + 1);
	else {
		//자음이면 consonant+1
		DFS(cur + 1, consonant + 1, vowel);
	}
	//매번 dfs가 끝나고 돌아오면 다시 이노드를 방문할 수 있으므로 해당 cur인덱스의 문자를 제거해준다. 
	for (auto iter = Ans.begin(); iter != Ans.end(); ++iter) {
		if (*iter == Letters[cur]) {
			Ans.erase(iter);
			break;
		}
	}
}

void Solution() {
	DFS(0, 0, 0);
	sort(printAns.begin(), printAns.end());
	for (auto iter = printAns.begin(); iter != printAns.end(); ++iter) {
		cout << *iter << '\n';
	}
}

int main() {
	Input();
	Solution();
}