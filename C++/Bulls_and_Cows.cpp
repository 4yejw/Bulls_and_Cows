#include "Bulls_and_Cows.h"

//생성자
BullsandCows::BullsandCows() {
	game_number = 1;
	try_number = 1;
	S = 0, B = 0, O = 0;
	total_sum = 0;
}

//게임 이름 출력
void BullsandCows::ShowGameName() {
	cout << "=============================================\n";
	cout << "|     Bulls and Cows    /    2023 08 28     |\n";
	cout << "=============================================\n";
}

//게임 규칙 출력
void BullsandCows::ShowRules() {
	cout << "=================================<<Rules>>=====================================\n";
	cout << "|                                                                             |\n";
	cout << "|  -Program Rule                                                              |\n";
	cout << "|  총 5번의 게임이 진행됩니다.                                                |\n";
	cout << "|  각 게임에서 최소한의 시도로 정답을 맞춰서 높은 점수를 획득하세요.          |\n";
	cout << "|  최종 점수는 다섯 게임의 평균 점수 입니다.                                  |\n";
	cout << "|                                                                             |\n";
	cout << "|  -Game Rule                                                                 |\n";
	cout << "|  0~9 수 중에서 중복없이 선택하여 만든 4자리수가 있습니다.                   |\n";
	cout << "|  S,B,O 결과를 통해 숫자를 추론하여 정답을 맞추세요.                         |\n";
	cout << "|  정답을 입력할 때는 1 2 3 4 이런식으로 각 숫자를 띄어서 입력해주세요.       |\n";
	cout << "|                                                                             |\n";
	cout << "|  S(Strike) : 자리와 숫자가 모두 맞을 경우                                   |\n";
	cout << "|  B(Ball) : 숫자만 맞은 경우                                                 |\n";
	cout << "|  O(Out) : 자리와 숫자가 모두 맞지 않은 경우                                 |\n";
	cout << "|                                                                             |\n";
	cout << "|  -Score Rule                                                                |\n";
	cout << "|  각 게임에서 시작 점수 100점이 부여됩니다.                                  |\n";
	cout << "|  1번째 시도에서 정답을 맞추면 100점, 이후 1번의 시도 당 -10점입니다.        |\n";
	cout << "|                                                                             |\n";
	cout << "===============================================================================\n";
}

//몇 번째 문제인지 출력
void BullsandCows::ShowStatus() {
	cout << "    :: " << game_number << "번째 문제 ::\t";
}

//정답을 설정
void BullsandCows::SetAnswer() {
	srand((unsigned int)time(NULL));

	number[1] = rand() % 10;
	number[2] = rand() % 10;
	number[3] = rand() % 10;
	number[4] = rand() % 10;
	while (number[2] == number[1])
		number[2] = rand() % 10;
	while ((number[3] == number[1]) || (number[3] == number[2]))
		number[3] = rand() % 10;
	while ((number[4] == number[1]) || (number[4] == number[2]) || (number[4] == number[3]))
		number[4] = rand() % 10;

	cout <<'\n';
}

//정답을 추론
void BullsandCows::GuessAnswer() {
	cout << "\n                                                S     B     O\n";
	while (true) {
		int a = 0, b = 0, c = 0, d = 0;
		cout << "    정답을 입력하세요 : ";
		cin >> a >> b >> c >> d;
		SetSBO(a, b, c, d);//SBO 계산
		cout << "    # " << try_number << " 번째 시도     : ";
		cout << a <<' ' << b<<' ' << c<<' ' << d << "\t\t\t";
		cout<< S << "     " << B << "     " << O << "\n\n";
		if (S==4)
			break;
		try_number++;
	}
}

//SBO 계산
void BullsandCows::SetSBO(int a,int b,int c,int d) {
	S = 0; B = 0; O = 0;
	if (number[1] == a)
		S++;
	else if (number[1] == b || number[1] == c || number[1] == d)
		B++;
	else
		O++;

	if (number[2] == b)
		S++;
	else if (number[2] == a || number[2] == c || number[2] == d)
		B++;
	else
		O++;

	if (number[3] == c)
		S++;
	else if (number[3] == b || number[3] == a || number[3] == d)
		B++;
	else
		O++;

	if (number[4] == d)
		S++;
	else if (number[4] == b || number[4] == c || number[4] == a)
		B++;
	else
		O++;
}

//각 게임의 결과를 출력
void BullsandCows::ShowGameResult() {
	cout << "    정답입니다!!\n\n";
	cout << "    ::" << game_number << "번째 문제 결과::\t";
	cout << "    총 시도 횟수 : " << try_number << "회\t";
	score[game_number] = 100 - (10 * (try_number - 1));
	cout << "    이번 게임 점수 : " << score[game_number] << "점\n";
	total_sum += score[game_number];
	game_number++;
	try_number = 1;
	cout << "\n===============================================================================\n\n";
}

//다섯 문제의 총 점수,평균점수를 출력
void BullsandCows::ShowTotalResult() {
	cout << "=================================\n";
	cout << "|                               |\n";
	cout << "|    -Score                     |\n";
	for (int i = 1; i <= 5; i++) {
		cout << "|    #" << i << "번째 게임 점수 : "<<score[i]<<"\t|\n";
	}
	cout << "|                               |\n";
	cout << "|    평균 점수 : " << total_sum / 5 << "\t\t|\n";
	cout << "|                               |\n";
	cout << "=================================\n";
}