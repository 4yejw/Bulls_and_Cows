#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class BullsandCows {
public:
	BullsandCows();//������
	void ShowGameName();//�����̸� ���
	void ShowRules();//���ӱ�Ģ ���
	void ShowStatus();//�� ��° �������� ��� 
	void SetAnswer();//������ ����
	void ShowGameResult();//�� ������ ����� ���
	void GuessAnswer();//������ �߷�
	void SetSBO(int a, int b, int c, int d);//SBO ���
	void ShowTotalResult();//���ݱ��� �������� �� ���,�õ�Ƚ��,����,������,��������� ���

private:
	int game_number;//�� ��° ����
	int number[5] = { 0, };//����
	int try_number;//�� ������ �õ� Ƚ��
	int S , B , O ;//Strike,Ball,Out
	int score[6] = { 0, };//�� ������ ����
	int total_sum;//�� ����
};