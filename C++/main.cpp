//20230825
#include "Bulls_and_Cows.h"

int main() {
	BullsandCows BC;
	
	BC.ShowGameName();//�����̸� ���
	BC.ShowRules();//���� ��Ģ ���
	cout << '\n';
	
	for(int i=0;i<5;i++) {
		BC.ShowStatus();//�� ��° �������� ���
		BC.SetAnswer();//������ ����
		BC.GuessAnswer();//������ �߷�
		BC.ShowGameResult();//���� ����� ���
	}
	
	BC.ShowTotalResult();//�� ������ ���
}