//20230825
#include "Bulls_and_Cows.h"

int main() {
	BullsandCows BC;
	
	BC.ShowGameName();//게임이름 출력
	BC.ShowRules();//게임 규칙 출력
	cout << '\n';
	
	for(int i=0;i<5;i++) {
		BC.ShowStatus();//몇 번째 문제인지 출력
		BC.SetAnswer();//정답을 설정
		BC.GuessAnswer();//정답을 추론
		BC.ShowGameResult();//게임 결과를 출력
	}
	
	BC.ShowTotalResult();//총 점수를 출력
}