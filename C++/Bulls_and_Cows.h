#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class BullsandCows {
public:
	BullsandCows();//생성자
	void ShowGameName();//게임이름 출력
	void ShowRules();//게임규칙 출력
	void ShowStatus();//몇 번째 문제인지 출력 
	void SetAnswer();//정답을 설정
	void ShowGameResult();//각 게임의 결과를 출력
	void GuessAnswer();//정답을 추론
	void SetSBO(int a, int b, int c, int d);//SBO 계산
	void ShowTotalResult();//지금까지 문제들의 총 결과,시도횟수,점수,총점수,평균점수를 출력

private:
	int game_number;//몇 번째 문제
	int number[5] = { 0, };//정답
	int try_number;//한 문제의 시도 횟수
	int S , B , O ;//Strike,Ball,Out
	int score[6] = { 0, };//각 게임의 점수
	int total_sum;//총 점수
};