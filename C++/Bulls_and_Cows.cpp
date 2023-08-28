#include "Bulls_and_Cows.h"

//������
BullsandCows::BullsandCows() {
	game_number = 1;
	try_number = 1;
	S = 0, B = 0, O = 0;
	total_sum = 0;
}

//���� �̸� ���
void BullsandCows::ShowGameName() {
	cout << "=============================================\n";
	cout << "|     Bulls and Cows    /    2023 08 28     |\n";
	cout << "=============================================\n";
}

//���� ��Ģ ���
void BullsandCows::ShowRules() {
	cout << "=================================<<Rules>>=====================================\n";
	cout << "|                                                                             |\n";
	cout << "|  -Program Rule                                                              |\n";
	cout << "|  �� 5���� ������ ����˴ϴ�.                                                |\n";
	cout << "|  �� ���ӿ��� �ּ����� �õ��� ������ ���缭 ���� ������ ȹ���ϼ���.          |\n";
	cout << "|  ���� ������ �ټ� ������ ��� ���� �Դϴ�.                                  |\n";
	cout << "|                                                                             |\n";
	cout << "|  -Game Rule                                                                 |\n";
	cout << "|  0~9 �� �߿��� �ߺ����� �����Ͽ� ���� 4�ڸ����� �ֽ��ϴ�.                   |\n";
	cout << "|  S,B,O ����� ���� ���ڸ� �߷��Ͽ� ������ ���߼���.                         |\n";
	cout << "|  ������ �Է��� ���� 1 2 3 4 �̷������� �� ���ڸ� �� �Է����ּ���.       |\n";
	cout << "|                                                                             |\n";
	cout << "|  S(Strike) : �ڸ��� ���ڰ� ��� ���� ���                                   |\n";
	cout << "|  B(Ball) : ���ڸ� ���� ���                                                 |\n";
	cout << "|  O(Out) : �ڸ��� ���ڰ� ��� ���� ���� ���                                 |\n";
	cout << "|                                                                             |\n";
	cout << "|  -Score Rule                                                                |\n";
	cout << "|  �� ���ӿ��� ���� ���� 100���� �ο��˴ϴ�.                                  |\n";
	cout << "|  1��° �õ����� ������ ���߸� 100��, ���� 1���� �õ� �� -10���Դϴ�.        |\n";
	cout << "|                                                                             |\n";
	cout << "===============================================================================\n";
}

//�� ��° �������� ���
void BullsandCows::ShowStatus() {
	cout << "    :: " << game_number << "��° ���� ::\t";
}

//������ ����
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

//������ �߷�
void BullsandCows::GuessAnswer() {
	cout << "\n                                                S     B     O\n";
	while (true) {
		int a = 0, b = 0, c = 0, d = 0;
		cout << "    ������ �Է��ϼ��� : ";
		cin >> a >> b >> c >> d;
		SetSBO(a, b, c, d);//SBO ���
		cout << "    # " << try_number << " ��° �õ�     : ";
		cout << a <<' ' << b<<' ' << c<<' ' << d << "\t\t\t";
		cout<< S << "     " << B << "     " << O << "\n\n";
		if (S==4)
			break;
		try_number++;
	}
}

//SBO ���
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

//�� ������ ����� ���
void BullsandCows::ShowGameResult() {
	cout << "    �����Դϴ�!!\n\n";
	cout << "    ::" << game_number << "��° ���� ���::\t";
	cout << "    �� �õ� Ƚ�� : " << try_number << "ȸ\t";
	score[game_number] = 100 - (10 * (try_number - 1));
	cout << "    �̹� ���� ���� : " << score[game_number] << "��\n";
	total_sum += score[game_number];
	game_number++;
	try_number = 1;
	cout << "\n===============================================================================\n\n";
}

//�ټ� ������ �� ����,��������� ���
void BullsandCows::ShowTotalResult() {
	cout << "=================================\n";
	cout << "|                               |\n";
	cout << "|    -Score                     |\n";
	for (int i = 1; i <= 5; i++) {
		cout << "|    #" << i << "��° ���� ���� : "<<score[i]<<"\t|\n";
	}
	cout << "|                               |\n";
	cout << "|    ��� ���� : " << total_sum / 5 << "\t\t|\n";
	cout << "|                               |\n";
	cout << "=================================\n";
}