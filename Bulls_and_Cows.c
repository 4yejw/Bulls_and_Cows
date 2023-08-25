//20220802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int k1, k2, k3, k4, a1, a2, a3, a4,try_num=0,game_num=1,S=0,B=0,O=0,x;
int* p = NULL;
char yorn;
//함수 리스트
void set_key();//정답 새로 정하기 함수
void is_this_right();//정답입력하고 sbo 확인하기 
void mark_SBO();//SBO판단하기 함수
void mark_1();
void mark_2();
void mark_3();
void mark_4();


main() {
	while (1) {
		printf("==================================%d번째 게임==================================\n",game_num);
		set_key();//정답 새로 정하기
		x = 0, try_num = 0;
		do {
			S = 0, B = 0, O = 0;
			try_num++;
			printf("#%d------------------------", try_num);
			is_this_right();//이거 맞아요?
		} while (*p==0);
		printf("\n정답입니다!\n");
		printf("한게임 더?(y or n):");
		scanf(" %c", &yorn);
		if (yorn == 'n')//no
			break;//반복 break;
		game_num++;
	}
	return 0;
}

//정답 새로 정하기 함수
void set_key() {
	
	srand((unsigned)time(NULL));
	k1 = rand() % 10;
	do {
		k2 = rand() % 10;
	}while (k1 == k2);//이 조건 일때 동안은 계속 반복
	do {
		k3 = rand() % 10;
	}while((k1 == k3) || (k2 == k3)); 
	do {
		k4 = rand() % 10;
	} while ((k1 == k4) || (k2 == k4) || (k3 == k4));
	
}

//정답입력하고 sbo 확인하기 
void is_this_right() {
	printf("\n");
	printf("정답을 입력하세요:");
	scanf(" %d  %d  %d  %d", &a1, &a2, &a3, &a4);
	mark_SBO();
	p = &x;
	if (S == 4 && B == 0 && O == 0)
		*p = 1;
}

//SBO판단하기 
void mark_SBO() {
	mark_1();
	mark_2();
	mark_3();
	mark_4();
	printf("S:%d B:%d O:%d\n", S, B, O);
}

//첫번째 수 a1판단하기 
void mark_1(){
	if (a1 == k1)
		S++;
	else if (a1 == k2)
		B++;
	else if (a1 == k3)
		B++;
	else if (a1 == k4)
		B++;
	else
		O++;
}
//두번째수 a2판단하기
void mark_2() {
	if (a2 == k2)
		S++;
	else if (a2 == k1)
		B++;
	else if (a2 == k3)
		B++;
	else if (a2 == k4)
		B++;
	else
		O++;
}
//세번째수 a3판단하기
void mark_3() {
	if (a3 == k3)
		S++;
	else if (a3 == k1)
		B++;
	else if (a3 == k2)
		B++;
	else if (a3 == k4)
		B++;
	else
		O++;
}
//네번째수 a4판단하기
void mark_4() {
	if (a4 == k4)
		S++;
	else if (a4 == k1)
		B++;
	else if (a4 == k2)
		B++;
	else if (a4 == k3)
		B++;
	else
		O++;
}

