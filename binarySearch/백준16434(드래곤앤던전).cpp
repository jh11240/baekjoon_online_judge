#include<iostream>
#include<vector>

using namespace std;
int roomAmount=0, initAtk = 0;

struct roomInfo
{
	int typeRoom;
	int secondParam;
	int thirdParam;
}; 

vector<roomInfo> v;
void input() {
	int temp1=0, temp2=0, temp3=0;
	cin >> roomAmount >> initAtk;
	for (int i = 0; i < roomAmount; i++) {
		cin >> temp1 >> temp2 >> temp3;
		roomInfo rInfo = {temp1, temp2,temp3};
		v.push_back(rInfo);
	}
}
//일단 생명력보다 커지면 최대생명력만큼만 힐하는거랑, 몬스터 체력이나 주인공 공격력 초기화 실수 -> 서로 때리는과정을 1대 1로 하면 안되고 바로 계산해야할듯
/*	//몬스터나 플레이어 한명 죽을때 까지 반복
			while (monHp > 0 && curHp > 0)
			{
				//몬스터를 공격 
				monHp -= curAtk;
				//몬스터 피 0이하면 종료
				if (monHp<= 0) {
					break;
				}
				//플레이어를 공격
				curHp -= v[i].secondParam;
				//플레이어는 끝까지 살아있어야 N번 방을 깨므로 한번이라도 죽으면 false
				if (curHp <= 0) return false;

			}*/

/// <summary>
/// mid값일 때 용을 쓰러뜨린다면 true 리턴, 못쓰러뜨리면 false return
/// </summary>
/// <param name="mid"></param>
/// <returns></returns>
bool checkMxHp(long long mid) {

	long long curHp = mid,curAtk=initAtk;
	for (int i = 0; i < roomAmount; i++) {
		//몬스터 공격일 때
		if (v[i].typeRoom == 1) {
			//몬스터 피
			long long monHp = v[i].thirdParam;
			//플레이어가 몬스터 죽을때 까지 때려야할 수
			long long playerStrike = ((monHp % curAtk==0) ? monHp/curAtk : (monHp/curAtk +1));
			//몬스터가 플레이어 죽을때까지 때려야할 때린 수
			long long monsterStrike = ((curHp % v[i].secondParam == 0) ? curHp / v[i].secondParam :( curHp / v[i].secondParam + 1));
			//플레이어가 때려야하는 수가 몬스터가 때려야하는 수보다 더 많으면 플레이어가 진다.
			if (playerStrike > monsterStrike) return false;
			//플레이어가 때려야하는 수가 같거나 더 적다면 플레이어가 선공이므로 이긴다.
			//몹은 플레이어가 때린거보다 한대 덜때려야한다.
			curHp -= v[i].secondParam * (playerStrike - 1);

		}

		//회복 방이라면
		else if (v[i].typeRoom == 2) {
			//회복 수치가 maxhp값 보다 크다면
			if (curHp+v[i].thirdParam >= mid) 
				curHp = mid;
			else {
				curHp += v[i].thirdParam;
			}
			curAtk += v[i].secondParam;
		}
	}
	return true;
}


void solution() {
	long long low = 0, high = 123'456'000'000'000'001,mid=0;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		((checkMxHp(mid))? high:low)=mid;
	}
	cout << high;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solution();
}