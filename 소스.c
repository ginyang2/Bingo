/*
1607 김진열 
개발목표 : 동생을위한 빙고게임 만들기
1. 1인용 2인용 분류
*/
#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#define LENGTH 3

void BingoCheck(char bingo[][LENGTH], char target, int length) {
	for (int i = 0; i <= length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			if (bingo[i][ii] == target) {
				bingo[i][ii] = '0';
				return;
			}
		}
	}
	printf("잘못된 값 입력입니다.");
}

int BingoLineCeck(char bingo[][LENGTH], int length) {
	int checkedLine = 0;
	int check = 0;
	//가로
	for (int i = 0; i < length; i++)
	{
		check = 0;
		for (int ii = 0; ii < length; ii++) {
			//printf("%c", bingo[i][ii]);
			if (bingo[i][ii] == '0') {
				check++;
			}
			else
			{
				break;
			}

		}

		if (check == length)
		{
			checkedLine++;
		}
		//printf("\n");
	}
	//세로
	for (int i = 0; i < length; i++)
	{
		check = 0;
		for (int ii = 0; ii < length; ii++) {
			//printf("%c", bingo[ii][i]);
			if (bingo[ii][i] == '0') {
				check++;
			}
			else
			{
				break;
			}
			
		}
		if (check == length)
		{
			checkedLine++;
		}
		//printf("세로\n");
	}
	//대각선(아래에서 위)
	check = 0;
	for (int i = 0; i < length; i++)
	{
		//printf("%c", bingo[i][i]);
		if (bingo[i][i] == '0') 
		{
			check++;
		}
		else 
		{
			break;
		}
	}
	if (check == length)
	{
		checkedLine++;
	}
	//printf("\n");
	//대각선(위에서 아래)
	check = 0;
	for (int i = 0; i < length; i++)
	{
		//printf("%c", bingo[length - 1 - i][i]);
		if (bingo[length - 1 - i][i] == '0')
		{
			check++;
		}
		else
		{
			break;
		}
	}
	if (check == length)
	{
		checkedLine++;
	}

	//printf("\n");
	return checkedLine;
}

int main(void) {
	FILE* fp = fopen("C:\\Users\\user\\Documents\\test.txt", "w");
	FILE* fp2 = fopen("test.txt", "r");
	char test[10];
	if (fp == NULL)
	{
		printf("스트림 오픈 실패");
	}
	if (fp2 == NULL) {
		printf("스트림 오픈 실패");
	}
	int length = LENGTH;
	char a[LENGTH][LENGTH] = { 0, };
	char target;
	//printf("빙고판의 크기를 설정해주세요 ?x?");
	//scanf("%d", &length);
	//빙고 입력
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			scanf_s(" %c", &a[i][ii]);
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			printf("%c 입력 \n", a[i][ii]);
			fprintf(fp, "%c ", a[i][ii]);
		}
		fprintf(fp, "\n");
	}
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			printf("읽기\n");
			fscanf(fp2, "%s", test);
		}
	}
	while (1)
	{
		for (int i = 0; i < LENGTH; i++)
		{
			for (int ii = 0; ii < LENGTH; ii++)
			{
				printf("%c", a[i][ii]);
			}
			printf("\n");
		}
		scanf_s(" %c", &target);
		BingoCheck(a, target, length);
		printf("현재 빙고 개수 : %d\n", BingoLineCeck(a, length));
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
