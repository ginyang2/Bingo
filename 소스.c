/*
1607 ������ 
���߸�ǥ : ���������� ������� �����
1. 1�ο� 2�ο� �з�
*/
#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
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
	printf("�߸��� �� �Է��Դϴ�.");
}

int BingoLineCeck(char bingo[][LENGTH], int length) {
	int checkedLine = 0;
	int check = 0;
	//����
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
	//����
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
		//printf("����\n");
	}
	//�밢��(�Ʒ����� ��)
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
	//�밢��(������ �Ʒ�)
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
		printf("��Ʈ�� ���� ����");
	}
	if (fp2 == NULL) {
		printf("��Ʈ�� ���� ����");
	}
	int length = LENGTH;
	char a[LENGTH][LENGTH] = { 0, };
	char target;
	//printf("�������� ũ�⸦ �������ּ��� ?x?");
	//scanf("%d", &length);
	//���� �Է�
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			scanf_s(" %c", &a[i][ii]);
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			printf("%c �Է� \n", a[i][ii]);
			fprintf(fp, "%c ", a[i][ii]);
		}
		fprintf(fp, "\n");
	}
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++) {
			printf("�б�\n");
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
		printf("���� ���� ���� : %d\n", BingoLineCeck(a, length));
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
