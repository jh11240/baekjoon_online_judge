#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int MaxNum=-1'000'000'000, MinNum=1'000'000'000,operandsSize;
int operandVisited[4];
//bool numVisited[12];
vector<int> nums;
//+ - * / 순서
vector<int> operands;

void Backtracking(int curStep, bool isNumTurn, int prevResult, int prevOperand) {
	if (curStep == nums.size() + operandsSize) {
		MaxNum = prevResult > MaxNum ? prevResult : MaxNum;
		MinNum = prevResult > MinNum ? MinNum : prevResult;
		return;
	}
	//숫자 차례라면
	if (isNumTurn) {
		//처음 순서면 연산필요없으므로 바로저장
		if (curStep == 0) {
			Backtracking(1, false, prevResult, 0);
			return;
		}
		//처음 순서 아니라면
		else
			switch (prevOperand)
			{
			case 0:
				Backtracking(curStep + 1, false, prevResult + nums[curStep / 2], 0);
				break;

			case 1:
				//재귀함수에서 값 자체 건드려버리면 함수 빠져나오고 다시처리해야되서 그냥 함수넣어줄때 해주는게 편함
				//prevResult -= elem;
				Backtracking(curStep + 1, false, prevResult - nums[curStep / 2], 0);
				break;

			case 2:
				Backtracking(curStep + 1, false, prevResult * nums[curStep / 2], 0);
				break;

			case 3:
				Backtracking(curStep + 1, false, prevResult / nums[curStep / 2], 0);
				break;

			default:
				break;
			}
	}

    //연산자 차례라면 
    else
        //4개의 연산자 중
        for (int i = 0; i < 4; i++) {
            if (operands[i] == 0) continue;
            //방문한 횟수가 연산자 갯수보다 많다면 안됨
            if (operandVisited[i] == operands[i]) continue;
            operandVisited[i]++;
            Backtracking(curStep + 1, true, prevResult, i);
			//빠져나가면서 현재 사용한 operand초기화 
            operandVisited[i]--;
        }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int amount, num, operand;
    cin >> amount;
    for (int i = 0; i < amount; i++) {
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 0; i < 4; i++) {
        cin >> operand;
        operandsSize += operand;
        operands.push_back(operand);
    }
    Backtracking(0, true, nums[0], 0);
    cout << MaxNum << "\n";
    cout << MinNum;
}