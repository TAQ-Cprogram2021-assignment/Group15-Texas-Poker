#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct cards {
	int point;//���Ƶ���
	int colour;//���ƻ�ɫ
};

int cardtype = 0;//����
int cardtypeA = 0;//A������
int cardtypeB = 0;//B������
int Highcardtype = 0;//��������
int betall = 0;//�ܳ���
int betA = 0;//���A�ĳ���
int betB = 0;//���B�ĳ���
int games = 1;//����
int rounds = 1;//����
char cardcolour[5];//�ƵĻ�ɫ
char cardpoint[2];//�Ƶĵ���
int betAround = 0;//���Aÿ���µĳ���
int betBround = 0;//���Bÿ���µĳ���
int rander1 = 0;//�㷨�����1
int rander2 = 0;//�㷨�����2
int pointplus = 0;//��ע������
int chooseplus = -1;//�Ƿ��ע
int choose = -1;//ѡ��
char filename[] = "memory.txt";
FILE* out;
FILE* again;

void typeprint(int m)
{
	if (m >= 3250)
	{
		printf("ͬ��˳");
	}
	else
	{
		if (m >= 3094)
		{
			printf("����");
		}
		else
		{
			if (m >= 2938)
			{
				printf("���ò�");
			}
			else {
				if (m >= 2934)
				{
					printf("ͬ��");
				}
				else {
					if (m >= 2924)
					{
						printf("˳��");
					}
					else {
						if (m >= 2911)
						{
							printf("����");
						}
						else
						{
							if (m >= 103)
							{
								printf("����");
							}
							else {
								if (m >= 25)
								{
									printf("һ��");
								}
								else {
									printf("����");
								}
							}
						}
					}
				}
			}
		}
	}
}
void putcard(struct cards* tr)
{
	if (tr->colour == 1)
	{
		fputs("����  ", again);
	}
	if (tr->colour == 2)
	{
		fputs("÷��  ", again);
	}
	if (tr->colour == 3)
	{
		fputs("����  ", again);
	}
	if (tr->colour== 4)
	{
		fputs("����  ", again);
	}
	if (tr->point == 1)
	{
		fputs("A  ", again);
	}
	if (tr->point == 2)
	{
		fputs("2  ", again);
	}
	if (tr->point == 3)
	{
		fputs("3  ", again);
	}
	if (tr->point == 4)
	{
		fputs("4  ", again);
	}
	if (tr->point == 5)
	{
		fputs("5  ", again);
	}
	if (tr->point == 6)
	{
		fputs("6  ", again);
	}
	if (tr->point == 7)
	{
		fputs("7  ", again);
	}
	if (tr->point == 8)
	{
		fputs("8  ", again);
	}
	if (tr->point == 9)
	{
		fputs("9  ", again);
	}
	if (tr->point == 10)
	{
		fputs("10  ", again);
	}
	if (tr->point == 11)
	{
		fputs("J  ", again);
	}
	if (tr->point == 12)
	{
		fputs("Q  ", again);
	}
	if (tr->point == 13)
	{
		fputs("K  ", again);
	}
}


void* randnumber(int *random)//��������ɺ���
{ 
	if (*random < 100)
	{
		*random= *random + 20000;
	}
	for (;*random>=53;)
	{
		*random = *random - 52;//ȷ�������ѡ��52�����е�ÿһ��
	}
	return random;
}

void colour(struct cards* tr)
{
	if (tr->colour == 1)
	{
		printf("����");
	}
	if (tr->colour == 2)
	{
		printf("÷��");
	}
	if (tr->colour == 3)
	{
		printf("����");
	}
	if (tr->colour == 4)
	{
		printf("����");
	}
}


void point(struct cards* tr)
{
	if (tr->point == 1)
	{
		printf(" A   ");
	}
	if (tr->point == 2)
	{
		printf(" 2   ");
	}
	if (tr->point == 3)
	{
		printf(" 3   ");
	}
	if (tr->point == 4)
	{
		printf(" 4   ");
	}
	if (tr->point == 5)
	{
		printf(" 5   ");
	}
	if (tr->point == 6)
	{
		printf(" 6   ");
	}
	if (tr->point == 7)
	{
		printf(" 7   ");
	}
	if (tr->point == 8)
	{
		printf(" 8   ");
	}
	if (tr->point == 9)
	{
		printf(" 9   ");
	}
	if (tr->point == 10)
	{
		printf(" 10   ");
	}
	if (tr->point == 11)
	{
		printf(" J   ");
	}
	if (tr->point == 12)
	{
		printf(" Q   ");
	}
	if (tr->point == 13)
	{
		printf(" K   ");
	}
}


void PVPsorting(struct cards* tr,int len)//���Ƶĵ����Ӵ�С����ĺ���
{
	struct cards zero;
	zero.colour = 0;
	zero.point = 0;
	struct cards* tmp=NULL;
	tmp = &zero;
	int i, j;

	for (i = 1; i < len; i++)
	{
		for (j = i; j <=6; j++)
		{
			if (((tr+i-1)->point)<((tr+j)->point))
			{
				tmp->colour = (tr + i-1)->colour;
				(tr + i-1)->colour = (tr + j)->colour;
				(tr + j)->colour = tmp->colour;

				tmp->point = (tr + i-1)->point;
				(tr + i-1)->point = (tr + j)->point;
				(tr + j)->point = tmp->point;
			}
		}
	}
}


void Highcard(struct cards* tr, int len)//�ж��Ƿ�Ϊ���Ƶĺ���(1<=cardtype<=24)
{
	int i = 0;
	if (((tr + len - 1)->point) == 1)//A�ĸ���
	{
		if (((tr + len - 1)->colour) == 4)
		{
			cardtype = 24;//����A
			return 0;
		}
		if (((tr + len - 1)->colour) == 3)
		{
			cardtype = 23;//����A
			return 0;
		}
		if (((tr + len - 1)->colour) == 2)
		{
			cardtype = 22;//÷��A
			return 0;
		}
		if (((tr + len - 1)->colour) == 1)
		{
			cardtype = 21;//����A
			return 0;
		}
	}

	for (i = 1; i<=5; i++)//K��9�ĸ���
	{
		if ((tr->point) == 14-i)
		{
			if ((tr->colour) == 4)
			{
				cardtype = (24 - 4 * i);
				return 0;
			}
			if ((tr->colour) == 3)
			{
				cardtype = (23 - 4 * i);
				return 0;
			}
			if ((tr->colour) == 2)
			{
				cardtype = (22 - 4 * i);
				return 0;
			}
			if ((tr->colour) == 1)
			{
				cardtype = (21 - 4 * i);
				return 0;
			}
		}
	}
}


void Onepair(struct cards* tr, int len)//�ж��Ƿ�Ϊһ�Եĺ���(25<=cardtype<=102)
{
	int i = 0;
	int k = 0;
	if (((tr + len - 1)->point) ==1 && ((tr + len - 2)->point) == 1)//һ��A�����
	{
		if ((((tr + len - 1)->colour) == 4 )&& (((tr + len - 2)->colour) == 3))
		{
			cardtype = 102;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 3) && (((tr + len - 2)->colour) == 4))
		{
			cardtype = 102;
			return 0;
		}

		if ((((tr + len - 1)->colour) == 4) && (((tr + len - 2)->colour) == 2))
		{
			cardtype = 101;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 2) && (((tr + len - 2)->colour) == 4))
		{
			cardtype = 101;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 4) && (((tr + len - 2)->colour) == 1))
		{
			cardtype = 100;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 1) && (((tr + len - 2)->colour) == 4))
		{
			cardtype = 100;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 3) && (((tr + len - 2)->colour) == 2))
		{
			cardtype = 99;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 2) && (((tr + len - 2)->colour) == 3))
		{
			cardtype = 99;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 3) && (((tr + len - 2)->colour) == 1))
		{
			cardtype = 98;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 1) && (((tr + len - 2)->colour) == 3))
		{
			cardtype = 98;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 2) && (((tr + len - 2)->colour) == 1))
		{
			cardtype = 97;
			return 0;
		}
		if ((((tr + len - 1)->colour) == 1) && (((tr + len - 2)->colour) == 2))
		{
			cardtype = 97;
			return 0;
		}
	}
	
	for (k = 0; k <= 5; k++)//һ��2��һ��K�����
	{
		for (i = 1; i <= 12; i++)
		{
			if (((tr + k)->point == 14 - i) && ((tr + k + 1)->point == 14 - i))
			{
				if ((tr + k)->colour == 4 && (tr + k + 1)->colour == 3)
				{
					cardtype = 102 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 3 && (tr + k + 1)->colour == 4)
				{
					cardtype = 102 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 4 && (tr + k + 1)->colour == 2)
				{
					cardtype = 101 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 2 && (tr + k + 1)->colour == 4)
				{
					cardtype = 101 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 4 && (tr + k + 1)->colour == 1)
				{
					cardtype = 100 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 1 && (tr + k + 1)->colour == 4)
				{
					cardtype = 100 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 3 && (tr + k + 1)->colour == 2)
				{
					cardtype = 99 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 2 && (tr + k + 1)->colour == 3)
				{
					cardtype = 99 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 3 && (tr + k + 1)->colour == 1)
				{
					cardtype = 98 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 1 && (tr + k + 1)->colour == 3)
				{
					cardtype = 98 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 2 && (tr + k + 1)->colour == 1)
				{
					cardtype = 97 - 6 * i;
					return 0;
				}

				if ((tr + k)->colour == 1 && (tr + k + 1)->colour == 2)
				{
					cardtype = 97 - 6 * i;
					return 0;
				}
			}
		}
	}
}


void Twopairs(struct cards* tr, int len)//�ж��Ƿ�Ϊ���Եĺ���(103<=cardtype<=2910)
{
	int s = 0;
	int i = 0;
	int k = 0;
	int t = 0;
	int m = 0;
	int count[12];
	count[0] = 0;
	count[1] = 396;//K
	count[2] = 756;//Q
	count[3] = 1080;//J
	count[4] = 1368;//10
	count[5] = 1620;//9
	count[6] = 1836;//8
	count[7] = 2016;//7
	count[8] = 2160;//6
	count[9] = 2268;//5
	count[10] = 2340;//4
	count[11] = 2376;//3

	int num[12];
	num[0] = 66;//K
	num[1] = 60;//Q
	num[2] = 54;//J
	num[3] = 48;//10
	num[4] = 42;//9
	num[5] = 36;//8
	num[6] = 30;//7
	num[7] = 24;//6
	num[8] = 18;//5
	num[9] = 12;//4
	num[10] = 6;//3
	num[11] = 0;

	for (s = 0; s <= len - 4; s++)
	{
		for (i = 2; i <= 12; i++)
		{
			if ((((tr + len - 1 - s)->point) == 14 - i) && (((tr + len - 1 - s - 1)->point) == 14 - i))
			{
				for (k = 1; k <= len - s - 3; k++)
				{
					if (((tr + len - 2 - s - k)->point) == (tr + len - 3 - s - k)->point)
					{
						if ((((tr + len - 2 - s - k)->colour == 4) && ((tr + len - 3 - s - k)->colour == 3))|| (((tr + len - 2 - s - k)->colour == 3) && ((tr + len - 3 - s - k)->colour == 4)))
						{
							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}

							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i);
							}
						}

						if ((((tr + len - 2 - s - k)->colour == 4) && ((tr + len - 3 - s - k)->colour == 2)) || (((tr + len - 2 - s - k)->colour == 2) && ((tr + len - 3 - s - k)->colour == 4)))
						{
							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - num[13 - (tr + len - 2 - s - k)->point];
							}
						}

						if ((((tr + len - 2 - s - k)->colour == 4) && ((tr + len - 3 - s - k)->colour == 1)) || (((tr + len - 2 - s - k)->colour == 1) && ((tr + len - 3 - s - k)->colour == 4)))
						{
							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 2*num[13 - (tr + len - 2 - s - k)->point];
							}
						}

						if ((((tr + len - 2 - s - k)->colour == 3) && ((tr + len - 3 - s - k)->colour == 2)) || (((tr + len - 2 - s - k)->colour == 2) && ((tr + len - 3 - s - k)->colour == 3)))
						{
							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 3 * num[13 - (tr + len - 2 - s - k)->point];
							}
						}

						if ((((tr + len - 2 - s - k)->colour == 3) && ((tr + len - 3 - s - k)->colour == 1)) || (((tr + len - 2 - s - k)->colour == 1) && ((tr + len - 3 - s - k)->colour == 3)))
						{
							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 4 * num[13 - (tr + len - 2 - s - k)->point];
							}
						}

						if ((((tr + len - 2 - s - k)->colour == 2) && ((tr + len - 3 - s - k)->colour == 1)) || (((tr + len - 2 - s - k)->colour == 1) && ((tr + len - 3 - s - k)->colour == 2)))
						{
							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2478 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2477 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 4) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 4))
							{
								cardtype = 2476 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2475 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 3) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 3))
							{
								cardtype = 2474 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13 - (tr + len - 2 - s - k)->point];
							}

							if (((tr + len - 1 - s)->colour == 2) && ((tr + len - 2 - s)->colour == 1))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13-(tr + len - 2 - s - k)->point];
							}
							if (((tr + len - 1 - s)->colour == 1) && ((tr + len - 2 - s)->colour == 2))
							{
								cardtype = 2473 - count[13 - (tr + len - 2 - s - k)->point] - 6 * ((tr + len - 2 - s - k)->point - 15 + i) - 5 * num[13-(tr + len - 2 - s - k)->point];
							}
						}
					}
				}
			}
		}
	}


	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1))//��һ��A�����
	{
		for (t = 3; t >= 1; t--)
		{
			if ((((tr + len - 1)->colour == 4) && ((tr + len - 2)->colour == t)) || (((tr + len - 1)->colour == t) && ((tr + len - 2)->colour == 4)))
			{
				for (k = 4; k >= 1; k--)
				{
					for (i = 1; i <= 12; i++)
					{
						if (((tr + k)->point == 14 - i) && ((tr + k - 1)->point == 14 - i))
						{
							if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 3))
							{
								cardtype = 2916 - 6 * i - 72 * (3 - t);
							}
							if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 4))
							{
								cardtype = 2916 - 6 * i - 72 * (3 - t);
							}

							if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 2))
							{
								cardtype = 2915 - 6 * i - 72 * (3 - t);
							}
							if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 4))
							{
								cardtype = 2915 - 6 * i - 72 * (3 - t);
							}

							if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 1))
							{
								cardtype = 2914 - 6 * i - 72 * (3 - t);
							}
							if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 4))
							{
								cardtype = 2914 - 6 * i - 72 * (3 - t);
							}

							if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 2))
							{
								cardtype = 2913 - 6 * i - 72 * (3 - t);
							}
							if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 3))
							{
								cardtype = 2913 - 6 * i - 72 * (3 - t);
							}

							if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 1))
							{
								cardtype = 2912 - 6 * i - 72 * (3 - t);
							}
							if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 3))
							{
								cardtype = 2912 - 6 * i - 72 * (3 - t);
							}

							if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 1))
							{
								cardtype = 2911 - 6 * i - 72 * (3 - t);
							}
							if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 2))
							{
								cardtype = 2911 - 6 * i - 72 * (3 - t);
							}
						}
					}
				}
			}
		}

		for (t = 2; t >= 1; t--)
		{
			if ((((tr + len - 1)->colour == 3) && ((tr + len - 2)->colour == t)) || (((tr + len - 1)->colour == t) && ((tr + len - 2)->colour == 3)))
			{
				for (k = 4; k >= 1; k--)
				{
					for (i = 1; i <= 12; i++)
					{
						if (((tr + k)->point == 14 - i) && ((tr + k - 1)->point == 14 - i))
						{
							if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 3))
							{
								cardtype = 2700 - 6 * i - 72 * (2 - t);
							}
							if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 4))
							{
								cardtype = 2700 - 6 * i - 72 * (2 - t);
							}

							if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 2))
							{
								cardtype = 2699 - 6 * i - 72 * (2 - t);
							}
							if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 4))
							{
								cardtype = 2699 - 6 * i - 72 * (2 - t);
							}

							if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 1))
							{
								cardtype = 2698 - 6 * i - 72 * (2 - t);
							}
							if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 4))
							{
								cardtype = 2698 - 6 * i - 72 * (2 - t);
							}

							if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 2))
							{
								cardtype = 2697 - 6 * i - 72 * (2 - t);
							}
							if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 3))
							{
								cardtype = 2697 - 6 * i - 72 * (2 - t);
							}

							if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 1))
							{
								cardtype = 2696 - 6 * i - 72 * (2 - t);
							}
							if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 3))
							{
								cardtype = 2696 - 6 * i - 72 * (2 - t);
							}

							if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 1))
							{
								cardtype = 2695 - 6 * i - 72 * (2 - t);
							}
							if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 2))
							{
								cardtype = 2695 - 6 * i - 72 * (2 - t);
							}
						}
					}
				}
			}
		}

		if ((((tr + len - 1)->colour == 2) && ((tr + len - 2)->colour == 1)) || (((tr + len - 1)->colour == 1) && ((tr + len - 2)->colour == 2)))
		{
			for (k = 4; k >=1; k--)
			{
				for (i = 1; i <= 12; i++)
				{
					if (((tr + k)->point == 14 - i) && ((tr + k - 1)->point == 14 - i))
					{
						if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 3))
						{
							cardtype = 2556 - 6 * i;
						}
						if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 4))
						{
							cardtype = 2556 - 6 * i;
						}

						if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 2))
						{
							cardtype = 2555 - 6 * i;
						}
						if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 4))
						{
							cardtype = 2555 - 6 * i;
						}

						if (((tr + k)->colour == 4) && ((tr + k - 1)->colour == 1))
						{
							cardtype = 2554 - 6 * i;
						}
						if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 4))
						{
							cardtype = 2554 - 6 * i;
						}

						if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 2))
						{
							cardtype = 2553 - 6 * i;
							return 0;
						}
						if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 3))
						{
							cardtype = 2553 - 6 * i;
						}

						if (((tr + k)->colour == 3) && ((tr + k - 1)->colour == 1))
						{
							cardtype = 2552 - 6 * i;
						}
						if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 3))
						{
							cardtype = 2552 - 6 * i;
						}

						if (((tr + k)->colour == 2) && ((tr + k - 1)->colour == 1))
						{
							cardtype = 2551 - 6 * i;
						}
						if (((tr + k)->colour == 1) && ((tr + k - 1)->colour == 2))
						{
							cardtype = 2551 - 6 * i;
						}
					}
				}
			}
		}
	}//��һ��A�����
}


void Threeofakind(struct cards* tr, int len)//�ж��Ƿ�Ϊ�����ĺ���(2911<=cardtype<=2923)
{
	int i = 0;
	int k = 0;
	for (k = len-3; k >= 0; k--)
	{
		for (i = 1; i <= 12; i++)
		{
			if ((((tr + k)->point) == 14 - i) && ((tr + k + 1)->point == 14 - i) && ((tr + k + 2)->point == 14 - i))
			{
				cardtype = 2923 - i;
			}
		}
	}

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1) && ((tr + len - 3)->point == 1))
	{
		cardtype = 2923;
	}
	
}


void Straight(struct cards* tr, int len)//�ж��Ƿ�Ϊ˳�ӵĺ���(2924<=cardtype<=2933)
{
	if (((tr + len - 1)->point == ((tr + len - 2)->point - 1))&& ((tr + len - 2)->point == ((tr + len - 3)->point - 1))&& ((tr + len - 3)->point == ((tr + len - 4)->point - 1)))
	{
		if ((tr + 2)->point == ((tr + 3)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
		if ((tr + 1)->point == ((tr + 3)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
		if (tr->point == ((tr + 3)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 2)->point - 1)) && ((tr + len - 2)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + len - 5)->point - 1)))
	{
		if ((tr+1)->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
		if (tr->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 2)->point - 1)) && ((tr + len - 2)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 2)->point - 1)) && ((tr + len - 2)->point == ((tr + len - 4)->point - 1)) && ((tr + len - 4)->point == ((tr + len - 5)->point - 1)))
	{
		if ((tr + 1)->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
		if (tr->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 2)->point - 1)) && ((tr + len - 2)->point == ((tr + len - 4)->point - 1)) && ((tr + len - 4)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 2)->point - 1)) && ((tr + len - 2)->point == ((tr + 2)->point - 1)) && ((tr + 2)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + len - 4)->point - 1)) && ((tr + len - 4)->point == ((tr + len - 5)->point - 1)))
	{
		if ((tr + 1)->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
		if (tr->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + len - 4)->point - 1)) && ((tr + len - 4)->point == ((tr +1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + 2)->point - 1)) && ((tr + 2)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 1)->point == ((tr + len - 4)->point - 1)) && ((tr + len - 4)->point == ((tr + 2)->point - 1)) && ((tr + 2)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 1)->point;
		}
	}

	if (((tr + len - 2)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + 3)->point - 1)) && ((tr + 3)->point == ((tr + 2)->point - 1)))
	{
		if ((tr + 1)->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 2)->point;
		}
		if (tr->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 2)->point;
		}
	}

	if (((tr + len - 2)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + 3)->point - 1)) && ((tr + 3)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 2)->point;
		}
	}

	if (((tr + len - 2)->point == ((tr + len - 3)->point - 1)) && ((tr + len - 3)->point == ((tr + 2)->point - 1)) && ((tr + 2)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 2)->point + 1))
		{
			cardtype = 2923 + (tr + len - 2)->point;
		}
	}

	if (((tr + len - 2)->point == ((tr + len - 4)->point - 1)) && ((tr + len - 4)->point == ((tr + 2)->point - 1)) && ((tr + 2)->point == ((tr + 1)->point - 1)))
	{
		if (tr->point == ((tr + 1)->point + 1))
		{
			cardtype = 2923 + (tr + len - 2)->point;
		}
	}

	if ((tr + len - 3)->point == ((tr + len - 4)->point - 1))
	{
		if ((tr + 3)->point == ((tr + 2)->point - 1))
		{
			if ((tr + 2)->point == ((tr + 1)->point - 1))
			{
				if (tr->point == ((tr + 1)->point + 1))
				{
					cardtype = 2923 + (tr + len - 3)->point;
				}
			}
		}
	}


	if ((tr + len - 1)->point == 1)//˳��Ϊ10JQKA�����
	{
		if (tr->point == 13)
		{
			if ((tr + 1)->point == 12)
			{
				if (((tr + 2)->point == 11) || ((tr + 3)->point == 11) || ((tr + 4)->point == 11))
				{
					if (((tr + 3)->point == 10) || ((tr + 4)->point == 10) || ((tr + 5)->point == 10))
					{
						cardtype = 2933;
					}
				}
			}
			
			if ((tr + 2)->point == 12)
			{
				if (((tr + 3)->point == 11) || ((tr + 4)->point == 11))
				{
					if (((tr + 4)->point == 10) || ((tr + 5)->point == 10))
					{
						cardtype = 2933;
					}
				}
			}

			if (((tr + 3)->point == 12)&& ((tr + 4)->point == 11)&& ((tr + 5)->point == 10))
			{
				cardtype = 2933;
			}
		}

		if ((tr+1)->point == 13)
		{
			if ((tr + 2)->point == 12)
			{
				if (((tr + 3)->point == 11) || ((tr + 4)->point == 11))
				{
					if (((tr + 4)->point == 10) || ((tr + 5)->point == 10))
					{
						cardtype = 2933;
					}
				}
			}

			if ((tr + 3)->point == 12)
			{
				if (((tr + 4)->point == 11) && ((tr + 5)->point == 10))
				{
					cardtype = 2933;
				}
			}
		}

		if (((tr + 2)->point == 13)&& ((tr + 3)->point == 12)&& ((tr + 4)->point == 11)&& ((tr + 5)->point == 10))
		{
			cardtype = 2933;
		}
	}
}


void Flush(struct cards* tr, int len)//�ж��Ƿ�Ϊͬ���ĺ���(2934<=cardtype<=2937)
{
	int i = 0;
	int k = 0;
	int t = 0;
	int count[5] = {0};

	for (k = 1; k <= 4; k++)
	{
		for (i = 0; i <= len - 1; i++)
		{
			if ((tr + i)->colour == k)
			{
				count[k] = count[k] + 1;
			}
		}
	}

	for (t = 1; t <= 4; t++)
	{
		if (count[t] >= 5)
		{
			cardtype = 2933 + t;
		}
	}
}


void Fullhouse(struct cards* tr, int len)//�ж��Ƿ�Ϊ���òʵĺ���(2938<=cardtype<=3093)
{
	int i = 0;
	int k = 0;
	int t = 0;
	int m = 0;

	for (m = len-1; m >= 2; m--)
	{
		for (i = 1; i <= 12; i++)
		{
			if (((tr + m)->point == (14 - i)) && ((tr + m - 1)->point == (14 - i)) && ((tr + m - 2)->point == (14 - i)))
			{
				for (t = len - 1; t >= 1; t--)
				{
					for (k = 1; k <= 12; k++) 
					{
						if (k != i) 
						{
							if (((tr + t)->point == (14 - k)) && ((tr + t - 1)->point == (14 - k)))
							{
								if (k < i)
								{
									cardtype = 3080 - 12 * (i - 1) - (k - 1);
								}
								if (k > i)
								{
									cardtype = 3080 - 12 * (i - 1) - (k - 1) + 1;
								}
							}
						}
					}
				}
			}
		}
	}

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1))//��һ��A�����
	{
		for (k = len - 3; k >= 2; k--)
		{
			for (i = 1; i <= 12; i++)
			{
				if (((tr + k)->point == 14 - i) && ((tr + k - 1)->point == 14 - i) && ((tr + k - 2)->point == 14 - i))
				{
					cardtype = 3081 - 12 * (i - 1);
				}
			}
		}
	}

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1) && ((tr + len - 3)->point == 1))//������A�����
	{

		for (k = len - 4; k >= 1; k--)
		{
			for (i = 1; i <= 12; i++)
			{
				if (((tr + k)->point == 14 - i) && ((tr + k - 1)->point == 14 - i))
				{
					cardtype = 3080 + 14 - i;
				}
			}
		}
	}
}


void Fourofakind(struct cards* tr, int len)//�ж��Ƿ�Ϊ�����ĺ���(3094<=cardtype<=3249)
{
	int i = 0;
	int k = 0;
	int t = 0;
	int max = 0;
	for (k = len - 1; k >= 3; k--)
	{
		for (i = 1; i <= 12; i++)
		{
			if (((tr + k)->point == 14 - i) && ((tr + k - 1)->point == 14 - i) && ((tr + k - 2)->point == 14 - i) && ((tr + k - 3)->point == 14 - i))
			{
				for (t = len - 1; t >= 0; t--)
				{
					if ((tr + t)->point != 14 - i)
					{
						max = (tr + t)->point;
					}
					if ((tr + len - 1)->point == 1)
					{
						max = 14;
					}
					if (max > 14 - i)
					{
						cardtype = 3237 - 12 * (i - 1) - (14 - max);
					}
					if (max < 14 - i)
					{
						cardtype = 3238 - 12 * (i - 1) - (14 - max);
					}
				}
			}
		}
	}

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1) && ((tr + len - 3)->point == 1) && ((tr + len - 4)->point == 1))//������A�����
	{
		for (i = 1; i <= 12; i++)
		{
			if (tr->point == 14 - i)
			{
				cardtype = 3250 - i;
			}
		}
	}
}


void StraightFlush(struct cards* tr, int len)//�ж��Ƿ�Ϊͬ��˳�ĺ���(3050<=cardtype<=3089)
{
	int colour = 0;
	int k = 0;
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	Flush(tr, 7);

	for (i = 1; i <= 4; i++)
	{
		if (cardtype == 2933+i)
		{
			colour = i;
		}
	}

	for (e = len - 1; e >= 4; e--)
	{
		for (d = e - 1; d >= 3; d--)
		{
			for (c = d - 1; c >= 2; c--)
			{
				for (b = c - 1; b >= 1; b--)
				{
					for (a = b - 1; a >= 0; a--)
					{
						if (((tr + a)->point == (tr + b)->point + 1) && ((tr + b)->point == (tr + c)->point + 1) && ((tr + c)->point == (tr + d)->point + 1) && ((tr + d)->point == (tr + e)->point + 1))
						{
							if (((tr + a)->colour == colour) && ((tr + b)->colour == colour) && ((tr + c)->colour == colour) && ((tr + d)->colour == colour) && ((tr + e)->colour == colour))
							{
								cardtype = 3285 - 4 * (13 - (tr + a)->point) - (4 - colour);
							}
						}
					}
				}
			}
		}
	}

	for (e = len - 1; e >= 4; e--)
	{
		if ((tr + e)->point == 1)
		{
			for (d = e - 1; d >= 3; d--)
			{
				if ((tr + d)->point == 10)
				{
					for (c = d - 1; c >= 2; c--)
					{
						if ((tr + c)->point == 11)
						{
							for (b = c - 1; b >= 1; b--)
							{
								if ((tr + b)->point == 12)
								{
									for (a = b - 1; a >= 0; a--)
									{
										if ((tr + a)->point == 13)
										{
											if (((tr + a)->colour == colour) && ((tr + b)->colour == colour) && ((tr + c)->colour == colour) && ((tr + d)->colour == colour) && ((tr + e)->colour == colour))
											{
												cardtype = 3289 - (4 - colour);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



void typeA(struct cards* tr, int len)//�ж�A������
{
	cardtype = 0;
	StraightFlush(tr, 7);//�ж������Ƿ�Ϊͬ��˳
	if (cardtype >= 3250)
	{
		cardtypeA = cardtype;
	}
	else {
		Fourofakind(tr, 7);//�ж������Ƿ�Ϊը��
		if (cardtype >= 3094)
		{
			cardtypeA = cardtype;
		}
		else {
			Fullhouse(tr, 7);//�ж������Ƿ�Ϊ���ò�
			if (cardtype >= 2938)
			{
				cardtypeA = cardtype;
			}
			else {
				Flush(tr, 7);//�ж������Ƿ�Ϊͬ��
				if (cardtype >= 2934)
				{
					cardtypeA = cardtype;
				}
				else {
					Straight(tr, 7);//�ж������Ƿ�Ϊ˳��
					if (cardtype >= 2924)
					{
						cardtypeA = cardtype;
					}
					else {
						Threeofakind(tr, 7);//�ж������Ƿ�Ϊ����
						if (cardtype >= 2911)
						{
							cardtypeA = cardtype;
						}
						else {
							Twopairs(tr, 7);//�ж������Ƿ�Ϊ����
							if (cardtype >= 103)
							{
								cardtypeA = cardtype;
							}
							else {
								Onepair(tr, 7);//�ж������Ƿ�Ϊһ��
								if (cardtype >= 25)
								{
									cardtypeA = cardtype;
								}
								else {
									Highcard(tr, 7);
									cardtypeA = cardtype;
								}
							}
						}
					}
				}

			}

		}
	}
}


void typeB(struct cards* tr, int len)//�ж�B������
{
	cardtype = 0;
	StraightFlush(tr, 7);//�ж������Ƿ�Ϊͬ��˳
	if (cardtype >= 3050)
	{
		cardtypeB = cardtype;
	}
	else {
		Fourofakind(tr, 7);//�ж������Ƿ�Ϊը��
		if (cardtype >= 3094)
		{
			cardtypeB = cardtype;
		}
		else {
			Fullhouse(tr, 7);//�ж������Ƿ�Ϊ���ò�
			if (cardtype >= 2938)
			{
				cardtypeB = cardtype;
			}
			else {
				Flush(tr, 7);//�ж������Ƿ�Ϊͬ��
				if (cardtype >= 2934)
				{
					cardtypeB = cardtype;
				}
				else {
					Straight(tr, 7);//�ж������Ƿ�Ϊ˳��
					if (cardtype >= 2924)
					{
						cardtypeB = cardtype;
					}
					else {
						Threeofakind(tr, 7);//�ж������Ƿ�Ϊ����
						if (cardtype >= 2911)
						{
							cardtypeB = cardtype;
						}
						else {
							Twopairs(tr, 7);//�ж������Ƿ�Ϊ����
							if (cardtype >= 103)
							{
								cardtypeB = cardtype;
							}
							else {
								Onepair(tr, 7);//�ж������Ƿ�Ϊһ��
								if (cardtype >= 25)
								{
									cardtypeB = cardtype;
								}
								else {
									Highcard(tr, 7);
									cardtypeB = cardtype;
								}
							}
						}
					}
				}

			}

		}
	}
}


void Highcardhole(struct cards*a,struct cards*b, struct cards* c, struct cards* d)//a,bΪ���һ�����ŵ���;c,dΪ��Ҷ������ŵ���
{
	Highcardtype = 0;//����
	int pointA = 0;
	int pointB = 0;
	int colourA = 0;
	int colourB = 0;

	if ((a->point) > (b->point))
	{
		pointA = a->point;
		colourA = a->colour;
	}
	else
	{
		pointA = b->point;
		colourA = b->colour;
	}
	if ((c->point) > (d->point))
	{
		pointB = c->point;
		colourB = c->colour;
	}
	else
	{
		pointB = d->point;
		colourB = d->colour;
	}
	if (pointA > pointB)
	{
		Highcardtype = 1;//���һ�ĵ��Ƶ�����
	}

	if (pointB > pointA)
	{
		Highcardtype = 2;//��Ҷ��ĵ��Ƶ�����
	}

	if (pointA == pointB)
	{
		if (colourA > colourB)
		{
			Highcardtype = 1;//���һ�ĵ��ƻ�ɫ��
		}
		if (colourB > colourA)
		{
			Highcardtype = 2;//��Ҷ��ĵ��ƻ�ɫ��
		}
	}

}


int PVP()
{
	int i,k;
	struct cards card[53];//����52����[1]~[52]
	struct cards* tr;

	card[1].point = 1;//����1ΪA
	card[1].colour = 1;//��ɫ1Ϊ����

	card[2].point = 1;
	card[2].colour = 2;//��ɫ2Ϊ÷��

	card[3].point = 1;
	card[3].colour = 3;//��ɫ3Ϊ����

	card[4].point = 1;
	card[4].colour = 4;//��ɫ4Ϊ����
	tr = &card[4];
	for (i = 2; i <= 13; i++)//����11ΪJ,����12ΪQ,����13ΪK
	{
		for (k = 1; k <= 4; k++)
		{
			tr = tr + 1;
			tr->point = i;
			tr->colour = k;
		}
	}	//һ����52���Ѷ���
	struct cards cardA1;
		cardA1.point = 20;//�����A����1�ĵ�������Ϊ��
		cardA1.colour = 20;//�����A����1�Ļ�ɫ����Ϊ��
	struct cards cardA2;
		cardA2.point = 20;//�����A����2�ĵ�������Ϊ��
		cardA2.colour = 20;//�����A����2�Ļ�ɫ����Ϊ��
	struct cards cardB1;
		cardB1.point = 20;//�����B����1�ĵ�������Ϊ��
		cardB1.colour = 20;//�����B����1�Ļ�ɫ����Ϊ��
	struct cards cardB2;
		cardB2.point = 20;//�����B����2�ĵ�������Ϊ��
		cardB2.colour = 20;//�����B����2�Ļ�ɫ����Ϊ��

		srand((unsigned)time(NULL));//ȡһ�����������

		int randnum1,randnum2,randnum3,randnum4,randnum5,randnum6,randnum7,randnum8,randnum9;//����Ÿ������
		randnum1= rand();//��randnum1���ȡһ����
		int* ptr = &randnum1;
		ptr=randnumber(ptr);//ʹ��randnumber������randnum1������1~52��
		cardA1 = card[randnum1];//�����A�ĵ�һ��������������ͻ�ɫ

		randnum2 = rand();
		ptr = &randnum2;
		ptr = randnumber(ptr);
		for (; randnum2 == randnum1;)//ȷ��randnum2!=randnum1
		{
			ptr = randnumber(ptr);
		}
		cardA2 = card[randnum2];//�����A�ĵڶ���������������ͻ�ɫ

		randnum3 = rand();
		ptr = &randnum3;
		ptr = randnumber(ptr);
		for (; randnum3 == randnum1 || randnum3 == randnum2;)
		{
			ptr = randnumber(ptr);
		}
		cardB1 = card[randnum3];//�����B�ĵ�һ��������������ͻ�ɫ

		randnum4 = rand();
		ptr = &randnum4;
		ptr = randnumber(ptr);
		for (; randnum4 == randnum1 || randnum4 == randnum2 || randnum4 == randnum3;)
		{
			ptr = randnumber(ptr);
		}
		cardB2 = card[randnum4];//�����B�ĵڶ���������������ͻ�ɫ

		struct cards cardall[6];//����ׯ�ҵ���[1]~[5]
		cardall[1] .point = 20;//��ׯ�����еĵ�һ���Ƶĵ�������Ϊ��
		cardall[1].colour = 20;//��ׯ�����еĵ�һ���ƵĻ�ɫ����Ϊ��
		cardall[2].point = 20;//��ׯ�����еĵڶ����Ƶĵ�������Ϊ��
		cardall[2].colour = 20;//��ׯ�����еĵڶ����ƵĻ�ɫ����Ϊ��
		cardall[3].point = 20;//��ׯ�����еĵ������Ƶĵ�������Ϊ��
		cardall[3].colour = 20;//��ׯ�����еĵ������ƵĻ�ɫ����Ϊ��
		cardall[4].point = 20;//��ׯ�����еĵ������Ƶĵ�������Ϊ��
		cardall[4].colour = 20;//��ׯ�����еĵ������ƵĻ�ɫ����Ϊ��
		cardall[5].point = 20;//��ׯ�����еĵ������Ƶĵ�������Ϊ��
		cardall[5].colour = 20;//��ׯ�����еĵ������ƵĻ�ɫ����Ϊ��

		randnum5 = rand();
		ptr = &randnum5;
		ptr = randnumber(ptr);
		for (; randnum5 == randnum1 || randnum5 == randnum2 || randnum5 == randnum3||randnum5 == randnum4;)
		{
			ptr = randnumber(ptr);
		}
		cardall[1] = card[randnum5];

		randnum6 = rand();
		ptr = &randnum6;
		ptr = randnumber(ptr);
		for (; randnum6 == randnum1 || randnum6 == randnum2 || randnum6 == randnum3 || randnum6 == randnum4||randnum6==randnum5;)
		{
			ptr = randnumber(ptr);
		}
		cardall[2] = card[randnum6];

		randnum7 = rand();
		ptr = &randnum7;
		ptr = randnumber(ptr);
		for (; randnum7 == randnum1 || randnum7 == randnum2 || randnum7 == randnum3 || randnum7 == randnum4 || randnum7 == randnum5 || randnum7==randnum6;)
		{
			ptr = randnumber(ptr);
		}
		cardall[3] = card[randnum7];
		
		randnum8 = rand();
		ptr = &randnum8;
		ptr = randnumber(ptr);
		for (; randnum8 == randnum1 || randnum8 == randnum2 || randnum8 == randnum3 || randnum8 == randnum4 || randnum8 == randnum5 || randnum8 == randnum6 || randnum8 == randnum7;)
		{
			ptr = randnumber(ptr);
		}
		cardall[4] = card[randnum8];
		
		randnum9 = rand();
		ptr = &randnum9;
		ptr = randnumber(ptr);
		for (; randnum9 == randnum1 || randnum9 == randnum2 || randnum9 == randnum3 || randnum9 == randnum4 || randnum9 == randnum5 || randnum9 == randnum6 || randnum9 == randnum7 || randnum9 == randnum8;)
		{
			ptr = randnumber(ptr);
		}
		cardall[5] = card[randnum9];//ׯ�ҵ�������ȫ������������

		struct cards A[7];//�������A�������ƺ�ׯ�ҵ���������ɵ�����
		A[0] = cardA1;
		A[1] = cardA2;
		A[2] = cardall[1];
		A[3] = cardall[2];
		A[4] = cardall[3];
		A[5] = cardall[4];
		A[6] = cardall[5];

		struct cards B[7];//�������B�������ƺ�ׯ�ҵ���������ɵ�����
		B[0] = cardB1;
		B[1] = cardB2;
		B[2] = cardall[1];
		B[3] = cardall[2];
		B[4] = cardall[3];
		B[5] = cardall[4];
		B[6] = cardall[5];

		PVPsorting(&A[0], 7);//�����A���ƺ�ׯ�ҵ�����ɵ�������дӴ�С����

		PVPsorting(&B[0], 7);//�����B���ƺ�ׯ�ҵ�����ɵ�������дӴ�С����

		printf("\n\n��ǰ�ǵ�%d��\n", games);
		printf("˫���Զ��µ�ע100\n\n");
		betA = betA - 100;
		betB = betB - 100;
		betall = 200;
		printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
		system("pause>nul");
		printf("���潫չʾ���A�ĵ���,�����B��ʱ�ر�\n");
		system("pause>nul");
		printf("�����A��ס���ĵ���,��ɺ󰴻س�����\n\n");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		system("pause>nul");
		printf("\r");
		printf("                            \n");
		printf("���潫չʾ���B�ĵ���,�����A��ʱ�ر�\n");
		system("pause>nul");
		printf("�����B��ס���ĵ���,��ɺ󰴻س�����\n\n");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);
		system("pause>nul");
		printf("\r");
		printf("                            \n");

		if (betA < 100)//���A�ĳ����Ѳ�����һע
		{
			printf("\n���A�ĳ����Ѳ���100,���潫ֱ�ӷ������Ʋ�����\n");
			system("pause>nul");
			printf("\n���潫���뿪�ƽ׶�\n");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���A�ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���B�ĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж�A������
			typeB(&B[0], 7);//�ж�B������

			system("pause>nul");

			printf("\n\n���A������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���B������Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
				betB = betB + betall;
				if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
		}
	if (betA >= 100)//A�ĳ����㹻������һע
	{
		printf("��������һ��,�����Aѡ����ע������\n");//��һ��
		printf("1.��ע  0.����\n");
		int choose = -1;
		scanf_s("%d", &choose);
		betBround = 0;
		betAround = 0;
		chooseplus = -1;
		pointplus = -1;

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n���Aѡ������,�����ϷB��ʤ\n");
			betB = betB + betall;
			printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			if (betB < 100)
			{
				printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}

			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}
		if (choose == 1)
		{
			printf("��ʣ��ĳ���Ϊ%d\n",betA);
			printf("��������Ҫ��ע������(100�ı���):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround%100)!=0)||(betAround<100)||(betAround>betA);)//������������������
			{
				if(betAround>betA)
				{ 
					getchar();
					printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
				if(((betAround % 100) != 0) || (betAround < 100))
				{
				getchar();
				printf("\n��������,������100�ı���,���Իس�����\n");
				scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
		printf("\n\n���A��ע����Ϊ%d", betAround);//���A�ĵ�һ�ֽ���


		printf("\n\n���������Bѡ���ע������\n");//���B�ĵ�һ�ֿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//Bѡ������
		{
			printf("\n���Bѡ������,�����ϷA��ʤ\n");
			betA = betA + betall;
			printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("\npause>nul");
				main();
			}
			if (betB < 100)
			{
				printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}

			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B�ĳ��벻��,�Զ�ȫ����ע
			{
				betBround = betB;
				betB = 0;
				betall = betBround + betall;
				printf("\n��ʣ��ĳ����Ѳ������A�µ�ע,���Զ�Ϊ��ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]); 
				colour(&cardall[4]);
				point(&cardall[4]); 
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���A�ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���B�ĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж�A������
				typeB(&B[0], 7);//�ж�B������

				system("pause>nul");

				printf("\n\n���A������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���B������Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
					betA = betA + betall ;
					if (betB < 100)
					{
						printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
					
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
					betB = betB + betall;
					if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
					{
						printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if(cardtypeA==cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;

							printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
						}
					}
					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");						
					PVP();
				}
			}
			else //B�ĳ������
			{
				betBround = betAround;
				betB = betB - betBround;
				betall = betall + betBround;
				chooseplus = -1;
				if (betB >= 100)
				{
					printf("\n��Ϊ���Զ���ע,����ѡ���Ƿ��ע:1.��ע  0.����ע\n");
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n��������,������1��0,���Իس�����\n");
						scanf_s("%d", &chooseplus);
					}
				}
				
				if (chooseplus == 1)//Bѡ���ע
				{
					printf("��ʣ��ĳ���Ϊ%d\n", betB);
					printf("��������Ҫ��ע������(100�ı���):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//������������������
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n��������,������100�ı���,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
					}
				betB = betB - pointplus;
				betBround = betBround + pointplus;
				betall = pointplus + betall;
				}
			}
		}//B��ע���

		

		if (chooseplus == 1)//B��ע��ѯ��A�Ƿ��ע
		{
			printf("\n���Bѡ���ע%d,�����Aѡ���ע������\n", pointplus);
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//���Aѡ����B��ע������
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}

				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//���Aѡ����B��ע���ע
			{
				if (betA <= pointplus)//A�ĳ��벻��,�Զ�ȫ����ע
				{
					betall = betA + betall;
					betAround = betA + betAround;
					betA = 0;
					printf("\n��ʣ��ĳ����Ѳ������B�ӵ�ע,���Զ�Ϊ��ȫ����ע\n\n");
					printf("���潫���뿪�ƽ׶�\n");
					printf("�ƺ�Ϊ:");
					colour(&cardall[1]);
					point(&cardall[1]);
					colour(&cardall[2]);
					point(&cardall[2]);
					colour(&cardall[3]);
					point(&cardall[3]);
					colour(&cardall[4]);
					point(&cardall[4]);
					colour(&cardall[5]);
					point(&cardall[5]);
					printf("\n\n");
					printf("���A�ĵ���Ϊ:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n���B�ĵ���Ϊ:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//�ж�A������
					typeB(&B[0], 7);//�ж�B������

					system("pause>nul");

					printf("\n\n���A������Ϊ:");
					typeprint(cardtypeA);
					printf("\n\n���B������Ϊ:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
						{
							printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();

						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
						betB = betB + betall;
						if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
						{
							printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//���Ʊȴ�С
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
									betA = betA + betall;
									if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
									{
										printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
									betB = betB + betall;
									if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
									{
										printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n����˫��ƽ��");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
				}
				betA = betA - pointplus;//���A�ĳ����㹻��ע
				betall = betall + pointplus;;
				betAround = betAround + pointplus;
				printf("\n���Aѡ���ע,��һ�ֹ���ע%d\n", betAround+betBround);
				system("pause>nul");
			}
			
		}
		
}	
			if ((chooseplus == 0)||(chooseplus==-1))
			{
				printf("\n���Bѡ�񲻼�ע,��һ�ֹ���ע%d\n", betAround+betBround);
				system("pause>nul");
			}

//��һ�ֽ���
		
		
		printf("\n�������ڶ���\n");//�ڶ��ֿ�ʼ
		system("pause>nul");
		printf("\n�ƺӷ�������,����Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]); 
		colour(&cardall[3]);
		point(&cardall[3]);//�ƺӷ����������
		printf("\n\n���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
		system("pause>nul");
		betAround = 0;//���A������ע������
		betBround = 0;//���B������ע������
		pointplus = 0;//���ּ�ע������
		choose = -1;
		chooseplus = -1;

		if (betA < 100)//���A�ĳ����Ѳ�����һע
		{
			printf("\n���A�ĳ����Ѳ���100,���潫ֱ�ӷ��������Ʋ�����\n");
			system("pause>nul");
			printf("\n���潫���뿪�ƽ׶�\n");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���A�ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���B�ĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж�A������
			typeB(&B[0], 7);//�ж�B������

			system("pause>nul");

			printf("\n\n���A������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���B������Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
				betB = betB + betall;
				if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
		}
		if (betA >= 100)//���A�ĳ����㹻������һע
		{
			printf("�����Aѡ����ע������\n");//�ڶ������A��ʼ
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
					system("pause>nul");
					main();
				}

				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (choose == 1)
			{
				printf("��ʣ��ĳ���Ϊ%d\n", betA);
				printf("��������Ҫ��ע������(100�ı���):\n");
				scanf_s("%d", &betAround);
				for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
				{
					if (betAround > betA)
					{
						getchar();
						printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
						scanf_s("%d", &betAround);
					}
					if (((betAround % 100) != 0) || (betAround < 100))
					{
						getchar();
						printf("\n��������,������100�ı���,���Իس�����\n");
						scanf_s("%d", &betAround);
					}
				}
				betA = betA - betAround;
				betall = betall + betAround;
			}
			printf("\n\n���A��ע����Ϊ%d", betAround);//���A�ĵڶ��ֽ���
		}

		printf("\n\n���������Bѡ���ע������\n");//���B�ĵڶ��ֿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//Bѡ������
		{
			printf("\n���Bѡ������,�����ϷA��ʤ\n");
			betA = betA + betall;
			printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1
			if (betB < 100)
			{
				printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}

			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B�ĳ��벻��,�Զ�ȫ����ע
			{
				betBround = betB;
				betB = 0;
				betall = betall+ betBround;
				printf("\n��ʣ��ĳ����Ѳ������A�µ�ע,���Զ�Ϊ��ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���A�ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���B�ĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж�A������
				typeB(&B[0], 7);//�ж�B������

				system("pause>nul");

				printf("\n\n���A������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���B������Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100) 
					{
						printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
					
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
					betB = betB + betall;
					if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
					{
						printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
							
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
			}
			else //B�ĳ������
			{
				betBround = betAround;
				betB = betB - betBround;
				betall = betall + betBround;
				if (betB >= 100)
				{
					printf("\n��Ϊ���Զ���ע,����ѡ���Ƿ��ע:1.��ע  0.����ע\n");
					chooseplus = -1;
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n��������,������1��0,���Իس�����\n");
						scanf_s("%d", &chooseplus);
					}
				}
				


				if (chooseplus == 1)//Bѡ���ע
				{
					printf("��ʣ��ĳ���Ϊ%d\n", betB);
					printf("��������Ҫ��ע������(100�ı���):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//������������������
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n��������,������100�ı���,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
					}
					betB = betB - pointplus;
					betBround = betBround + pointplus;
					betall = betall + pointplus;
				}
			}
		}//B��ע���



		if (chooseplus == 1)//B��ע��ѯ��A�Ƿ��ע
		{
			printf("\n���Bѡ���ע%d,�����Aѡ���ע������\n", pointplus);
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//���Aѡ����B��ע������
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}

				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//���Aѡ����B��ע���ע
			{
				if (betA <= pointplus)//A�ĳ��벻��,�Զ�ȫ����ע
				{
					betall = betall + betA;
					betAround = betA + betAround;
					betA = 0;
					printf("\n��ʣ��ĳ����Ѳ������B�ӵ�ע,���Զ�Ϊ��ȫ����ע\n\n");
					printf("���潫���뿪�ƽ׶�\n");
					printf("�ƺ�Ϊ:");
					colour(&cardall[1]);
					point(&cardall[1]);
					colour(&cardall[2]);
					point(&cardall[2]);
					colour(&cardall[3]);
					point(&cardall[3]);
					colour(&cardall[4]);
					point(&cardall[4]);
					colour(&cardall[5]);
					point(&cardall[5]);
					printf("\n\n");
					printf("���A�ĵ���Ϊ:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n���B�ĵ���Ϊ:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//�ж�A������
					typeB(&B[0], 7);//�ж�B������

					system("pause>nul");

					printf("\n\n���A������Ϊ:");
					typeprint(cardtypeA);
					printf("\n\n���B������Ϊ:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//B�ĳ��벻��,�ж�B��ʤ
						{
							printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
						betB = betB + betall;
						if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
						{
							printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//���Ʊȴ�С
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
									betA = betA + betall;
									if (betB < 100)//B�ĳ��벻��,�ж�B��ʤ
									{
										printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
									betB = betB + betall;
									if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
									{
										printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n����˫��ƽ��");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
				}
				betAround = betAround + pointplus;
				betA = betA - pointplus;
				betall = betall + pointplus;
				printf("\n���Aѡ���ע,�ڶ��ֹ���ע%d\n", betAround+betBround);
				system("pause>nul");
			}
			
		}
			if ((chooseplus == 0)||(chooseplus==-1))//Bѡ�񲻼�ע
			{
				printf("\n���Bѡ�񲻼�ע,�ڶ��ֹ���ע%d\n", betAround + betBround);
				system("pause>nul");
			}//�ڶ��ֽ���


		printf("\n������������\n");//�����ֿ�ʼ
		printf("\n�ƺӷ�����������:");
		colour(&cardall[4]);
		point(&cardall[4]);
		system("pause>nul");
		printf("\n\nĿǰ�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		printf("\n\n���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
		system("pause>nul");
		betAround = 0;//���A������ע������
		betBround = 0;//���B������ע������
		pointplus = 0;//���ּ�ע������
		choose = -1;
		chooseplus = -1;
		if (betA < 100)//���A�ĳ����Ѳ�����һע
		{
			printf("\n���A�ĳ����Ѳ���100,���潫ֱ�ӷ��������Ʋ�����\n");
			system("pause>nul");
			printf("\n���潫���뿪�ƽ׶�\n");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���A�ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���B�ĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж�A������
			typeB(&B[0], 7);//�ж�B������

			system("pause>nul");

			printf("\n\n���A������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���B������Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
				betA = betA + betall;
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
				betB = betB + betall;
				if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
		}
		if (betA >= 100)//���A�ĳ����㹻������һע
		{
			printf("�����Aѡ����ע������\n");//���������A��ʼ
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (choose == 1)
			{
				printf("��ʣ��ĳ���Ϊ%d\n", betA);
				printf("��������Ҫ��ע������(100�ı���):\n");
				scanf_s("%d", &betAround);
				for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
				{
					if (betAround > betA)
					{
						getchar();
						printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
						scanf_s("%d", &betAround);
					}
					if (((betAround % 100) != 0) || (betAround < 100))
					{
						getchar();
						printf("\n��������,������100�ı���,���Իس�����\n");
						scanf_s("%d", &betAround);
					}
				}
				betA = betA - betAround;
				betall = betall + betAround;
			}
			printf("\n\n���A��ע����Ϊ%d", betAround);//���A�ĵ����ֽ���
		}

		printf("\n\n���������Bѡ���ע������\n");//���B�ĵ����ֿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//Bѡ������
		{
			printf("\n���Bѡ������,�����ϷA��ʤ\n");
			betA = betA + betall;
			printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			if (betA < 100)
			{
				printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("\npause>nul");
				main();
			}
			if (betB < 100)
			{
				printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B�ĳ��벻��,�Զ�ȫ����ע
			{			
				betall = betall + betB;
				betBround = betB;
				betB = 0;

				printf("\n��ʣ��ĳ����Ѳ������A�µ�ע,���Զ�Ϊ��ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���A�ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���B�ĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж�A������
				typeB(&B[0], 7);//�ж�B������

				system("pause>nul");

				printf("\n\n���A������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���B������Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
					betB = betB + betall;
					if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
					{
						printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();

				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
							
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
			}
			else //B�ĳ������
			{
				betBround = betAround;
				betB = betB - betBround;
				betall = betall + betBround;
				chooseplus = -1;
				if (betB >= 100)
				{
					printf("\n��Ϊ���Զ���ע,����ѡ���Ƿ��ע:1.��ע  0.����ע\n");
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n��������,������1��0,���Իس�����\n");
						scanf_s("%d", &chooseplus);
					}
				}
				


				if (chooseplus == 1)//Bѡ���ע
				{
					printf("��ʣ��ĳ���Ϊ%d\n", betB);
					printf("��������Ҫ��ע������(100�ı���):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//������������������
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n��������,������100�ı���,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
					}
					betB = betB - pointplus;
					betBround = betBround + pointplus;
					betall = betall + pointplus;
				}
			}
		}//B��ע���



		if (chooseplus == 1)//B��ע��ѯ��A�Ƿ��ע
		{
			printf("\n���Bѡ���ע%d,�����Aѡ���ע������\n", pointplus);
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//���Aѡ����B��ע������
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}

				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//���Aѡ����B��ע���ע
			{
				if (betA <= pointplus)//A�ĳ��벻��,�Զ�ȫ����ע
				{
					betall = betall+ betA;
					betAround = betA + betAround;
					betA = 0;
					
					printf("\n��ʣ��ĳ����Ѳ������B�ӵ�ע,���Զ�Ϊ��ȫ����ע\n\n");
					printf("���潫���뿪�ƽ׶�\n");
					printf("�ƺ�Ϊ:");
					colour(&cardall[1]);
					point(&cardall[1]);
					colour(&cardall[2]);
					point(&cardall[2]);
					colour(&cardall[3]);
					point(&cardall[3]);
					colour(&cardall[4]);
					point(&cardall[4]);
					colour(&cardall[5]);
					point(&cardall[5]);
					printf("\n\n");
					printf("���A�ĵ���Ϊ:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n���B�ĵ���Ϊ:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//�ж�A������
					typeB(&B[0], 7);//�ж�B������

					system("pause>nul");

					printf("\n\n���A������Ϊ:");
					typeprint(cardtypeA);
					printf("\n\n���B������Ϊ:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//B�ĳ��벻�㣬�ж�A��ʤ
						{
							printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ,��Esc���˳���\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
						betB = betB + betall;
						if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
						{
							printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();

					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//���Ʊȴ�С
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
									betA = betA + betall;
									if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
									{
										printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
									betB = betB + betall;
									if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
									{
										printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n����˫��ƽ��");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
				}
				betA = betA - pointplus;
				betAround = betAround + pointplus;
				betall = betall + pointplus;
				printf("\n���Aѡ���ע,�����ֹ���ע%d\n", betAround + betBround);
				system("pause>nul");
			}
		}
		if ((chooseplus == 0) || (chooseplus == -1))
		{
			printf("\n���Bѡ�񲻼�ע,�����ֹ���ע%d\n", betAround + betBround);
			system("pause>nul");
		}//�����ֽ���

		printf("\n��������ʤ��\n");
		system("pause>nul");
		printf("\n�ƺӷ���������:");
		colour(&cardall[5]);
		point(&cardall[5]);
		system("pause>nul");
		printf("\n\n�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);

		printf("\n\n���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
		system("pause>nul");
		betAround = 0;//���A������ע������
		betBround = 0;//���B������ע������
		pointplus = 0;//���ּ�ע������

		if (betA < 100)//���A�ĳ����Ѳ�����һע
		{
			printf("\n���A�ĳ����Ѳ���100,���潫ֱ�ӿ���\n");
			system("pause>nul");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���A�ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���B�ĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж�A������
			typeB(&B[0], 7);//�ж�B������

			system("pause>nul");

			printf("\n\n���A������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���B������Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)//���B�ĳ��벻��100,�ж�A��ʤ
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
				betB = betB + betall;
				if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}

				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)//���B�ĳ��벻��100,�ж�A��ʤ
							{
								printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
		
		}

		if (betA >= 100)//���A�ĳ����㹻������һע
		{
			printf("�����Aѡ����ע������\n");//��ʤ�����A��ʼ
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}

				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (choose == 1)
			{
				printf("��ʣ��ĳ���Ϊ%d\n", betA);
				printf("��������Ҫ��ע������(100�ı���):\n");
				scanf_s("%d", &betAround);
				for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
				{
					if (betAround > betA)
					{
						getchar();
						printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
						scanf_s("%d", &betAround);
					}
					if (((betAround % 100) != 0) || (betAround < 100))
					{
						getchar();
						printf("\n��������,������100�ı���,���Իس�����\n");
						scanf_s("%d", &betAround);
					}
				}
				betA = betA - betAround;
				betall = betall + betAround;
			}
			printf("\n\n���A��ע����Ϊ%d", betAround);//���A�ľ�ʤ�ֽ���
		}

		printf("\n\n���������Bѡ���ע������\n");//���B�ľ�ʤ�ֿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//Bѡ������
		{
			printf("\n���Bѡ������,�����ϷA��ʤ\n");
			betA = betA + betall;
			printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1
			if (betB < 100)
			{
				printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}

			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B�ĳ��벻��,�Զ�ȫ����ע
			{
				betall = betall + betB;
				betBround = betB;
				betB = 0;
				printf("\n��ʣ��ĳ����Ѳ������A�µ�ע,���Զ�Ϊ��ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���A�ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���B�ĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж�A������
				typeB(&B[0], 7);//�ж�B������

				system("pause>nul");

				printf("\n\n���A������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���B������Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100) 
					{
						printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
					betB = betB + betall;
					if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
					{
						printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();

				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
							{
								printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
							
						}
						if (Highcardtype == 2)
						{
							printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
							betB = betB + betall;
							if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
							{
								printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVP();
				}
			}
			else //B�ĳ������
			{
				betBround = betAround;
				betall = betall + betBround;
				betB = betB - betBround;
				chooseplus = -1;
				if (betB >= 100)
				{
					printf("\n��Ϊ���Զ���ע,����ѡ���Ƿ��ע:1.��ע  0.����ע\n");
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n��������,������1��0,���Իس�����\n");
						scanf_s("%d", &chooseplus);
					}
				}
				


				if (chooseplus == 1)//Bѡ���ע
				{
					printf("��ʣ��ĳ���Ϊ%d\n", betB);
					printf("��������Ҫ��ע������(100�ı���):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//������������������
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n��������,������100�ı���,���Իس�����\n");
							scanf_s("%d", &pointplus);
						}
					}
					betB = betB - pointplus;
					betBround = betBround + pointplus;
					betall = betall + pointplus;
				}
			}
		}//B��ע���



		if (chooseplus == 1)//B��ע��ѯ��A�Ƿ��ע
		{
			printf("\n���Bѡ���ע%d,�����Aѡ���ע������\n", pointplus);
			printf("1.��ע  0.����\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//���Aѡ����B��ע������
			{
				printf("\n���Aѡ������,�����ϷB��ʤ\n");
				betB = betB + betall;
				printf("���Aʣ��ĳ���Ϊ:%d     ���Bʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//���Aѡ����B��ע���ע
			{
				if (betA <= pointplus)//A�ĳ��벻��,�Զ�ȫ����ע
				{
					betall = betall + betA;
					betAround = betA + betAround;
					betA = 0;
					
					printf("\n��ʣ��ĳ����Ѳ������B�ӵ�ע,���Զ�Ϊ��ȫ����ע\n\n");
					printf("���潫���뿪�ƽ׶�\n");
					printf("�ƺ�Ϊ:");
					colour(&cardall[1]);
					point(&cardall[1]);
					colour(&cardall[2]);
					point(&cardall[2]);
					colour(&cardall[3]);
					point(&cardall[3]);
					colour(&cardall[4]);
					point(&cardall[4]);
					colour(&cardall[5]);
					point(&cardall[5]);
					printf("\n\n");
					printf("���A�ĵ���Ϊ:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n���B�ĵ���Ϊ:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//�ж�A������
					typeB(&B[0], 7);//�ж�B������

					system("pause>nul");

					printf("\n\n���A������Ϊ:");
					typeprint(cardtypeA);
					printf("\n\n���B������Ϊ:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//B�ĳ��벻��,�ж�A��ʤ
						{
							printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
						betB = betB + betall;
						if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
						{
							printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++; 
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//���Ʊȴ�С
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
									betA = betA + betall;
									if (betB < 100)//���B�ĳ��벻��100,�ж�A��ʤ
									{
										printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
									betB = betB + betall;
									if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
									{
										printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
										system("pause>nul");
										printf("����������¿�ʼ��Ϸ\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n����˫��ƽ��");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVP();
						}
					
				}
				betA = betA - pointplus;
				betAround = betAround + pointplus;
				betall = betall + pointplus;
				printf("\n���Aѡ���ע,��ʤ�ֹ���ע%d\n", betAround + betBround);
				system("pause>nul");
			}
		}
		if ((chooseplus == 0) || (chooseplus == -1))
		{
			printf("\n���Bѡ�񲻼�ע,��ʤ�ֹ���ע%d\n", betAround + betBround);
			system("pause>nul");
		}
		
		printf("������ȫ������,���潫���ƾ�ʤ");

		printf("�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);
		printf("\n\n");
		printf("���A�ĵ���Ϊ:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n���B�ĵ���Ϊ:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//�ж�A������
		typeB(&B[0], 7);//�ж�B������

		system("pause>nul");

		printf("\n\n���A������Ϊ:");
		typeprint(cardtypeA);
		printf("\n\n���B������Ϊ:");
		typeprint(cardtypeB);

		system("pause>nul");
		
		if (cardtypeA > cardtypeB)
		{
			printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
			betA = betA + betall;
			games++;
			if (betB < 100)
			{
				printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
			betB = betB + betall;
			if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
			{
				printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVP();
		}
			if (cardtypeA == cardtypeB)
			{
				if (cardtypeA <= 24)//���Ʊȴ�С
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n���A�����ʹ�,��ϲ���AӮ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)
						{
							printf("\n���B�ĳ����Ѳ���100,��ϲ���A���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (Highcardtype == 2)
					{
						printf("\n\n���B�����ʹ�,��ϲ���BӮ�������Ϸ!!");
						betB = betB + betall;
						if (betA < 100)//A�ĳ��벻��,�ж�B��ʤ
						{
							printf("\n���A�ĳ����Ѳ���100,��ϲ���B���ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVP();
					}
				}
				printf("\n\n����˫��ƽ��");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVP();
			}
}


int PVE()
{
	int i, k;
	struct cards card[53];//����52����[1]~[52]
	struct cards* tr;

	card[1].point = 1;//����1ΪA
	card[1].colour = 1;//��ɫ1Ϊ����

	card[2].point = 1;
	card[2].colour = 2;//��ɫ2Ϊ÷��

	card[3].point = 1;
	card[3].colour = 3;//��ɫ3Ϊ����

	card[4].point = 1;
	card[4].colour = 4;//��ɫ4Ϊ����
	tr = &card[4];
	for (i = 2; i <= 13; i++)//����11ΪJ,����12ΪQ,����13ΪK
	{
		for (k = 1; k <= 4; k++)
		{
			tr = tr + 1;
			tr->point = i;
			tr->colour = k;
		}
	}	//һ����52���Ѷ���
	struct cards cardA1;
	cardA1.point = 20;//����ҵ���1�ĵ�������Ϊ��
	cardA1.colour = 20;//����ҵ���1�Ļ�ɫ����Ϊ��
	struct cards cardA2;
	cardA2.point = 20;//����ҵ���2�ĵ�������Ϊ��
	cardA2.colour = 20;//����ҵ���2�Ļ�ɫ����Ϊ��
	struct cards cardB1;
	cardB1.point = 20;//�����Ե���1�ĵ�������Ϊ��
	cardB1.colour = 20;//�����Ե���1�Ļ�ɫ����Ϊ��
	struct cards cardB2;
	cardB2.point = 20;//�����Ե���2�ĵ�������Ϊ��
	cardB2.colour = 20;//�����Եĵ���2�Ļ�ɫ����Ϊ��

	srand((unsigned)time(NULL));//ȡһ�����������

	int randnum1, randnum2, randnum3, randnum4, randnum5, randnum6, randnum7, randnum8, randnum9;//����Ÿ������
	randnum1 = rand();//��randnum1���ȡһ����
	int* ptr = &randnum1;
	ptr = randnumber(ptr);//ʹ��randnumber������randnum1������1~52��
	cardA1 = card[randnum1];//����ҵĵ�һ��������������ͻ�ɫ

	randnum2 = rand();
	ptr = &randnum2;
	ptr = randnumber(ptr);
	for (; randnum2 == randnum1;)//ȷ��randnum2!=randnum1
	{
		ptr = randnumber(ptr);
	}
	cardA2 = card[randnum2];//����ҵĵڶ���������������ͻ�ɫ

	randnum3 = rand();
	ptr = &randnum3;
	ptr = randnumber(ptr);
	for (; randnum3 == randnum1 || randnum3 == randnum2;)
	{
		ptr = randnumber(ptr);
	}
	cardB1 = card[randnum3];//�����Եĵ�һ��������������ͻ�ɫ

	randnum4 = rand();
	ptr = &randnum4;
	ptr = randnumber(ptr);
	for (; randnum4 == randnum1 || randnum4 == randnum2 || randnum4 == randnum3;)
	{
		ptr = randnumber(ptr);
	}
	cardB2 = card[randnum4];//�����Եĵڶ���������������ͻ�ɫ

	struct cards cardall[6];//����ׯ�ҵ���[1]~[5]
	cardall[1].point = 20;//��ׯ�����еĵ�һ���Ƶĵ�������Ϊ��
	cardall[1].colour = 20;//��ׯ�����еĵ�һ���ƵĻ�ɫ����Ϊ��
	cardall[2].point = 20;//��ׯ�����еĵڶ����Ƶĵ�������Ϊ��
	cardall[2].colour = 20;//��ׯ�����еĵڶ����ƵĻ�ɫ����Ϊ��
	cardall[3].point = 20;//��ׯ�����еĵ������Ƶĵ�������Ϊ��
	cardall[3].colour = 20;//��ׯ�����еĵ������ƵĻ�ɫ����Ϊ��
	cardall[4].point = 20;//��ׯ�����еĵ������Ƶĵ�������Ϊ��
	cardall[4].colour = 20;//��ׯ�����еĵ������ƵĻ�ɫ����Ϊ��
	cardall[5].point = 20;//��ׯ�����еĵ������Ƶĵ�������Ϊ��
	cardall[5].colour = 20;//��ׯ�����еĵ������ƵĻ�ɫ����Ϊ��

	randnum5 = rand();
	ptr = &randnum5;
	ptr = randnumber(ptr);
	for (; randnum5 == randnum1 || randnum5 == randnum2 || randnum5 == randnum3 || randnum5 == randnum4;)
	{
		ptr = randnumber(ptr);
	}
	cardall[1] = card[randnum5];

	randnum6 = rand();
	ptr = &randnum6;
	ptr = randnumber(ptr);
	for (; randnum6 == randnum1 || randnum6 == randnum2 || randnum6 == randnum3 || randnum6 == randnum4 || randnum6 == randnum5;)
	{
		ptr = randnumber(ptr);
	}
	cardall[2] = card[randnum6];

	randnum7 = rand();
	ptr = &randnum7;
	ptr = randnumber(ptr);
	for (; randnum7 == randnum1 || randnum7 == randnum2 || randnum7 == randnum3 || randnum7 == randnum4 || randnum7 == randnum5 || randnum7 == randnum6;)
	{
		ptr = randnumber(ptr);
	}
	cardall[3] = card[randnum7];

	randnum8 = rand();
	ptr = &randnum8;
	ptr = randnumber(ptr);
	for (; randnum8 == randnum1 || randnum8 == randnum2 || randnum8 == randnum3 || randnum8 == randnum4 || randnum8 == randnum5 || randnum8 == randnum6 || randnum8 == randnum7;)
	{
		ptr = randnumber(ptr);
	}
	cardall[4] = card[randnum8];

	randnum9 = rand();
	ptr = &randnum9;
	ptr = randnumber(ptr);
	for (; randnum9 == randnum1 || randnum9 == randnum2 || randnum9 == randnum3 || randnum9 == randnum4 || randnum9 == randnum5 || randnum9 == randnum6 || randnum9 == randnum7 || randnum9 == randnum8;)
	{
		ptr = randnumber(ptr);
	}
	cardall[5] = card[randnum9];//ׯ�ҵ�������ȫ������������

	struct cards A[7];//������ҵ������ƺ�ׯ�ҵ���������ɵ�����
	A[0] = cardA1;
	A[1] = cardA2;
	A[2] = cardall[1];
	A[3] = cardall[2];
	A[4] = cardall[3];
	A[5] = cardall[4];
	A[6] = cardall[5];

	struct cards B[7];//������Ե������ƺ�ׯ�ҵ���������ɵ�����
	B[0] = cardB1;
	B[1] = cardB2;
	B[2] = cardall[1];
	B[3] = cardall[2];
	B[4] = cardall[3];
	B[5] = cardall[4];
	B[6] = cardall[5];

	PVPsorting(&A[0], 7);//����ҵ��ƺ�ׯ�ҵ�����ɵ�������дӴ�С����

	PVPsorting(&B[0], 7);//�����Ե��ƺ�ׯ�ҵ�����ɵ�������дӴ�С����

	printf("\n\n��ǰ�ǵ�%d��\n", games);
	printf("˫���Զ��µ�ע100\n\n");
	betA = betA - 100;
	betB = betB - 100;
	betall = 200;
	printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
	printf("���潫չʾ���ĵ���\n");
	system("pause>nul");
	printf("���ס���ĵ���,��ɺ󰴻س�����\n\n");
	colour(&cardA1);
	point(&cardA1);
	colour(&cardA2);
	point(&cardA2);
	printf("\n");
	if (games > 1)
	{
		system("taskkill/im notepad.exe>nul");
	}
	out = fopen(filename, "w");
	again = fopen(filename, "at");
	fputs("", out);
	fputs("���ĵ���Ϊ:   ", again);
	putcard(&cardA1);
	fputs("  ", again);
	putcard(&cardA2);
	fclose(again);
	fclose(out);
	system("start/b memory.txt");

	system("pause>nul");

	

	if (betA < 100)//��ҵĳ����Ѳ�����һע
	{
		printf("\n���ĳ����Ѳ���100,���潫ֱ�ӷ������Ʋ�����\n");
		system("pause>nul");
		printf("\n���潫���뿪�ƽ׶�\n");
		printf("�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);
		printf("\n\n");
		printf("���ĵ���Ϊ:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n���Եĵ���Ϊ:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//�ж���ҵ�����
		typeB(&B[0], 7);//�жϵ��Ե�����

		system("pause>nul");

		printf("\n\n��������Ϊ:");
		typeprint(cardtypeA);
		printf("\n\n���Ե�����Ϊ:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n�����ʹ�,��ϲ��Ӯ�������Ϸ!!");
			betA = betA + betall;
			if (betB < 100)//���Գ��벻��,�ж���һ�ʤ
			{
				printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
			betB = betB + betall;
			if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//���Ʊȴ�С
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n����˫��ƽ��");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//��ҵĳ��벻���Զ������ѽ���

	if (betA >= 100)//��ҵĳ����㹻������һע
	{
		printf("��������һ��,����ѡ����ע������\n");//��һ��
		printf("1.��ע  0.����\n");
		int choose = -1;
		scanf_s("%d", &choose);
		betBround = 0;
		betAround = 0;
		chooseplus = -1;
		pointplus = -1;

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n��ѡ������,�����Ϸ���Ի�ʤ\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)
		{
			printf("��ʣ��ĳ���Ϊ%d\n", betA);
			printf("��������Ҫ��ע������(100�ı���):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n��������,������100�ı���,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
		printf("\n\n����ע����Ϊ%d", betAround);//��ҵĵ�һ�ֽ���
	}//����㹻��һע�ѽ���

	rander1 = rand();
	rander2 = rand();
	choose = -1;
	//���Խ����ж��Ƿ��ע�ͼ�ע
	typeA(&A[0], 7);
	typeB(&B[0], 7);
	if (cardtypeB <= 24)//����Ϊ����
	{
		if ((rander1 % 4) == 0)//�����ķ�֮һ���ʸ�ע
		{
			choose = 1;
		}
		if (((rander1 % 4) == 1)|| ((rander1 % 4) == 2)|| ((rander1 % 4) == 3))//�����ķ�֮����������
		{
			choose = 0;
		}
	}

	if ((cardtypeB >= 25) && (cardtypeB <= 102))//����Ϊһ��
	{
		rander1 = rand();//���»��һ�������

		if ((rander1 % 2) == 0)//���Զ���֮һ���ʸ�ע
		{
			choose = 1;
		}
		if ((rander1 % 2) == 1)//���Զ���֮һ��������
		{
			choose = 0;
		}
	}

	if ((cardtypeB >= 103) && (cardtypeB <= 2910))//����Ϊ����
	{
		if (((rander1 % 4) == 0) || ((rander1 % 4) == 1) || ((rander1 % 4) == 2))//�����ķ�֮�����ʸ�ע
		{
			choose = 1;
		}
		if (((rander1 % 4) == 3))//�����ķ�֮һ��������
		{
			choose = 0;
		}
	}
	if (cardtypeB >= 2911)//�������ʹ�������
	{
		choose = 1;//���Ը�ע
	}
	if (betB <= 200)//������Գ����Ѳ���,�Զ���ע
	{
		choose = 1;//���Ը�ע
	}

	if (choose == 0)//����ѡ������
	{
		printf("\n����ѡ������,��ϲ��Ӯ�������Ϸ!!\n");
		betA = betA + betall;
		printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
		games++;//������1

		if (betB < 100)
		{
			printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
			system("pause>nul");
			printf("����������¿�ʼ��Ϸ\n");
			system("pause>nul");
			main();
		}
		printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
		system("pause>nul");
		PVE();
	}

	if (choose == 1)//����ѡ���ע(��һ��)
	{
		printf("\n����ѡ���ע\n");
		if (betB <= betAround)//���Եĳ��벻��,�Զ�ȫ����ע
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n����ʣ��ĳ��벻�����µ�ע,���Եĳ�����ȫ����ע\n\n");
			printf("���潫���뿪�ƽ׶�\n");
			system("pause>nul");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���Եĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж���ҵ�����
			typeB(&B[0], 7);//�жϵ��Ե�����

			system("pause>nul");

			printf("\n\n��������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���Ե�����Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
				betB = betB + betall;
				if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
				{
					printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//ƽ��
			{
				if (cardtypeA <= 24)//���Ʊȴ�С
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
						{
							printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
						betB = betB + betall;
						if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
						{
							printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n����˫��ƽ��");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//���Ը�ע,�����벻��
		if (betB > betAround)//���Ը�ע�ҳ������
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//���Գ��벻��100,����ע
			{
				chooseplus = 0;
			}
			if (betB >= 100)
			{
				if (cardtype <= 102)//��������Ϊ����,���Բ���ע
				{
					chooseplus = 0;
				}
				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//��������Ϊ����
				{
					rander1 = rand();
					if (rander1 % 5 == 0)//�������֮һ���ʼ�ע100
					{
						if (betB <= 500)
						{
							chooseplus = 1;
							pointplus = 100;//���Լ�ע100
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
					}
					if (rander1 % 5 == 1)//�������֮һ���ʼ�ע300
					{
						if (betB > 500)
						{
							chooseplus = 1;
							pointplus = 300;//���Լ�ע300
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						else
						{
							chooseplus = 1;
							pointplus = 100;
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
					}
					if ((rander1 % 5 == 2) || (rander1 % 5 == 3) || (rander1 % 5 == 4))//�������֮�����ʲ���ע
					{
						chooseplus = 0;
					}
				}
				if (cardtype >= 2911)//�������ʹ�������
				{
					if (betB < 300)
					{
						chooseplus = 1;
						pointplus = 100;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1000) && (betB >= 300))
					{
						chooseplus = 1;
						pointplus = 300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if (betB >= 1000)
					{
						chooseplus = 1;
						pointplus = 1000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
				}
			}
		}
		if (chooseplus == 0)
		{
			printf("\n����ѡ�񲻼�ע\n");
			system("pause>nul");
			printf("\n��һ�ֽ���,���ֹ���ע%d\n", betAround + betBround);
			chooseplus = -1;//����
			pointplus = 0;
			choose = -1;
			betAround = 0;
			betBround = 0;
		}
		if (chooseplus == 1)//����ѡ���ע
		{
			printf("\n����ѡ���ע%d\n", pointplus);
			printf("\n����ѡ���ע������\n");
			printf("1.��ע  0.����\n");
			choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//������������������
			{
				getchar();
				printf("\n��������,������1��0,���Իس�����\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//���ѡ���ڵ��Ժ�����
			{
				printf("\n��ѡ������,���ź������Ϸ������!\n");
				betB = betB + betall;
				printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
				games++;//������1

				if (betA < 100)
				{
					printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (choose == 1)//���ѡ���ע
			{
				if (betA <= pointplus)//��ҵĳ��벻����Լӵ�ע
				{
					betall = betall + betA;
					betAround = betAround + betA;
					betA = 0;
					printf("\n��ʣ��ĳ��벻����Լӵ�ע,���ĳ�����ȫ����ע\n\n");
					printf("���潫���뿪�ƽ׶�\n");
					system("pause>nul");
					printf("�ƺ�Ϊ:");
					colour(&cardall[1]);
					point(&cardall[1]);
					colour(&cardall[2]);
					point(&cardall[2]);
					colour(&cardall[3]);
					point(&cardall[3]);
					colour(&cardall[4]);
					point(&cardall[4]);
					colour(&cardall[5]);
					point(&cardall[5]);
					printf("\n\n");
					printf("���ĵ���Ϊ:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n���Եĵ���Ϊ:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//�ж���ҵ�����
					typeB(&B[0], 7);//�жϵ��Ե�����

					system("pause>nul");

					printf("\n\n��������Ϊ:");
					typeprint(cardtypeA);
					printf("\n\n���Ե�����Ϊ:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)
						{
							printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
						betB = betB + betall;
						if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
						{
							printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (cardtypeA == cardtypeB)//ƽ��
					{
						if (cardtypeA <= 24)//���Ʊȴ�С
						{
							Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
							if (Highcardtype == 1)
							{
								printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
								betA = betA + betall;
								if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
								{
									printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
									system("pause>nul");
									printf("����������¿�ʼ��Ϸ\n");
									system("pause>nul");
									main();
								}
								games++;
								printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
								system("pause>nul");
								PVE();

							}
							if (Highcardtype == 2)
							{
								printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
								betB = betB + betall;
								if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
								{
									printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
									system("pause>nul");
									printf("����������¿�ʼ��Ϸ\n");
									system("pause>nul");
									main();
								}
								games++;
								printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
								system("pause>nul");
								PVE();
							}
						}

						printf("\n\n����˫��ƽ��");
						betA = betA + betall / 2;
						betB = betB + betall / 2;
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}
				if (betA > pointplus)//���ʣ��ĳ����㹻��ע
				{
					printf("\n��Ϊ����ע\n");
					betA = betA - pointplus;
					betall = betall + pointplus;
					betAround = betAround + pointplus;
				}
			}
			printf("\n��һ�ֽ���,���ֹ���ע%d\n", betAround + betBround);
			betAround = 0;
			betBround = 0;
			pointplus = 0;
			choose = -1;
			chooseplus = -1;
		}	
	}//��һ�ֽ���

	system("pause>nul");
	printf("\n�������ڶ���\n");
	system("pause>nul");
	betAround = 0;
	betBround = 0;
	pointplus = 0;
	choose = -1;
	chooseplus = -1;
	printf("\n�ƺӷ�������,����Ϊ:");
	colour(&cardall[1]);
	point(&cardall[1]);
	colour(&cardall[2]);
	point(&cardall[2]);
	colour(&cardall[3]);
	point(&cardall[3]);//�ƺӷ����������
	printf("\n\n��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
	
	again = fopen(filename, "at");
	fputs("\n�ƺ�:  ", again);
	putcard(&cardall[1]);
	fputs("  ", again);
	putcard(&cardall[2]);
	fputs("  ", again);
	putcard(&cardall[3]);
	fclose(again);
	system("taskkill/im notepad.exe>nul");
	system("start/b memory.txt");

	system("pause>nul");

	

	if (betA < 100)//��ҵĳ����Ѳ�����һע
	{
		printf("\n���ĳ����Ѳ���100,���潫ֱ�ӷ��������Ʋ�����\n");
		system("pause>nul");
		printf("\n���潫���뿪�ƽ׶�\n");
		printf("�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);
		printf("\n\n");
		printf("���ĵ���Ϊ:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n���Եĵ���Ϊ:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//�ж�A������
		typeB(&B[0], 7);//�ж�B������

		system("pause>nul");

		printf("\n\n��������Ϊ:");
		typeprint(cardtypeA);
		printf("\n\n���Ե�����Ϊ:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
			betA = betA + betall;
			if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
			{
				printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
			betB = betB + betall;
			if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//���Ʊȴ�С
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n����˫��ƽ��");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//�ڶ��ֿ�ʼ,��ҵĳ����Ѳ�����һע

	if (betA >= 100)//�ڶ��ֿ�ʼ,��ҵĳ����㹻��һע
	{
		printf("����ѡ����ע������\n");//�ڶ�����ҿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n��ѡ������,���ź�������������Ϸ!\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)
		{
			printf("��ʣ��ĳ���Ϊ%d\n", betA);
			printf("��������Ҫ��ע������(100�ı���):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n��������,������100�ı���,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
	}//��ҵڶ��ֽ���
	//�жϵ����Ƿ��ע�ͼ�ע
	choose = -1;//����
	if ((betAround > 300) && (cardtypeB <= 24))
	{
		choose = 0;
	}
	if ((betAround > 500) && (cardtypeB <= 102))//�����ע���ҵ�����������Ϊһ��,���Զ���֮һ��������
	{
		rander1 = rand();
		if (rander1 % 2 == 0)
		{
			choose = 0;
		}
		if (rander1 % 2 == 1)
		{
			choose = 1;
		}
	}
	if (cardtypeB >= 103)//������������Ϊ����,��ע
	{
		choose = 1;
	}

	if (choose == 0)//����ѡ������
	{
		printf("\n����ѡ������,��ϲ��Ӯ�������Ϸ!!\n");
		betA = betA + betall;
		printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
		games++;//������1

		if (betB < 100)
		{
			printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
			system("pause>nul");
			printf("����������¿�ʼ��Ϸ\n");
			system("pause>nul");
			main();
		}
		printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
		system("pause>nul");
		PVE();
	}
	if (choose == 1)//�ڶ��ֵ���ѡ���ע
	{
		printf("\n����ѡ���ע\n");
		if (betB <= betAround)//���Եĳ��벻��,�Զ�ȫ����ע
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n����ʣ��ĳ��벻�����µ�ע,���Եĳ�����ȫ����ע\n\n");
			printf("���潫���뿪�ƽ׶�\n");
			system("pause>nul");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���Եĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж���ҵ�����
			typeB(&B[0], 7);//�жϵ��Ե�����

			system("pause>nul");

			printf("\n\n��������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���Ե�����Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
				betB = betB + betall;
				if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
				{
					printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//ƽ��
			{
				if (cardtypeA <= 24)//���Ʊȴ�С
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
						{
							printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
						betB = betB + betall;
						if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
						{
							printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n����˫��ƽ��");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//���Ը�ע,�����벻��(�ڶ���)

		if (betB > betAround)//���Ը�ע,�ҳ������(�ڶ���)
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//���Գ��벻��100,����ע
			{
				chooseplus = 0;
			}
			if (betB >= 100)//���Գ����㹻100
			{
				if (cardtype <= 102)//��������Ϊ���ƻ�һ��,���Բ���ע
				{
					chooseplus = 0;
				}

				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//��������Ϊ����
				{
					rander1 = rand();//���һ�������

					if ((rander1 % 5 == 0) || (rander1 % 5 == 1))//�������֮�����ʼ�ע
					{
						if ((betB >= 300) && (betB <= 500))
						{
							chooseplus = 1;
							pointplus = 200;//���Լ�ע200
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB < 300)
						{
							chooseplus = 1;
							pointplus = 100;//���Լ�ע100
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
					}
					if (rander1 % 5 == 0)//�������֮һ���ʼӴ�ע
					{
						if ((betB > 500) && (betB <= 1000))
						{
							chooseplus = 1;
							pointplus = 300;//���Լ�ע300
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB > 1000)
						{
							chooseplus = 1;
							pointplus = 500;//���Լ�ע500
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}

					}
					if ((rander1 % 5 == 2) || (rander1 % 5 == 3) || (rander1 % 5 == 4))//�������֮�����ʲ���ע
					{
						chooseplus = 0;
					}
				}
				if (cardtype >= 2911)//�������ʹ�������
				{
					if (betB < 200)
					{
						chooseplus = 1;
						pointplus = 100;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 200) && (betB < 300))
					{
						chooseplus = 1;
						pointplus = 200;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 600) && (betB >= 300))
					{
						chooseplus = 1;
						pointplus = 300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1000) && (betB >= 600))
					{
						chooseplus = 1;
						pointplus = 600;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 3000) && (betB >= 1000))
					{
						chooseplus = 1;
						pointplus = 1000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if (betB >= 3000)
					{
						chooseplus = 1;
						pointplus = 2000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
				}
			}
		}//���Եڶ�����ע����ע�����
	}
	if (chooseplus == 0)
	{
		printf("\n����ѡ�񲻼�ע\n");
		system("pause>nul");
		printf("\n�ڶ��ֽ���,���ֹ���ע%d\n", betAround + betBround);
		chooseplus = -1;//����
		pointplus = 0;
		choose = -1;
		betAround = 0;
		betBround = 0;
	}
	if (chooseplus == 1)//����ѡ���ע
	{
		printf("\n����ѡ���ע%d\n", pointplus);
		printf("\n����ѡ���ע������\n");
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//���ѡ���ڵ��Ժ�����
		{
			printf("\n��ѡ������,���ź������Ϸ������!\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//���ѡ���ע
		{
			if (betA <= pointplus)//��ҵĳ��벻����Լӵ�ע
			{
				betall = betall + betA;
				betAround = betAround + betA;
				betA = 0;
				printf("\n��ʣ��ĳ��벻����Լӵ�ע,���ĳ�����ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���Եĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж���ҵ�����
				typeB(&B[0], 7);//�жϵ��Ե�����

				system("pause>nul");

				printf("\n\n��������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���Ե�����Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
							{
								printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
							betB = betB + betall;
							if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
							{
								printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			if (betA > pointplus)//���ʣ��ĳ����㹻��ע
			{
				printf("\n��Ϊ����ע\n");
				betA = betA - pointplus;
				betall = betall + pointplus;
				betAround = betAround + pointplus;
			}
		}	
		printf("\n�ڶ��ֽ���,���ֹ���ע%d\n", betAround + betBround);
		betAround = 0;
		betBround = 0;
		pointplus = 0;
		choose = -1;
		chooseplus = -1;//�ڶ��ֽ���
	}

	system("pause>nul");
	printf("\n������������\n");
	betAround = 0;
	betBround = 0;
	pointplus = 0;
	choose = -1;
	chooseplus = -1;
	printf("\n�ƺӷ���������Ϊ:");
	colour(&cardall[4]);
	point(&cardall[4]);
	printf("\n\n��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);

	again = fopen(filename, "at");
	fputs("  ", again);
	putcard(&cardall[4]);
	fclose(again);
	system("taskkill/im notepad.exe>nul");
	system("start/b memory.txt");

	system("pause>nul");

	

	if (betA < 100)//��ҵĳ����Ѳ�����һע
	{
		printf("\n���ĳ����Ѳ���100,���潫ֱ�ӷ��������Ʋ�����\n");
		system("pause>nul");
		printf("\n���潫���뿪�ƽ׶�\n");
		printf("�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);
		printf("\n\n");
		printf("���ĵ���Ϊ:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n���Եĵ���Ϊ:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//�ж�A������
		typeB(&B[0], 7);//�ж�B������

		system("pause>nul");

		printf("\n\n��������Ϊ:");
		typeprint(cardtypeA);
		printf("\n\n���Ե�����Ϊ:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
			betA = betA + betall;
			if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
			{
				printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
			betB = betB + betall;
			if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//���Ʊȴ�С
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n����˫��ƽ��");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//�����ֿ�ʼ,��ҵĳ����Ѳ�����һע

	if (betA >= 100)//�����ֿ�ʼ,��ҵĳ����㹻��һע
	{
		printf("����ѡ����ע������\n");//��������ҿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n��ѡ������,���ź�������������Ϸ!\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)
		{
			printf("��ʣ��ĳ���Ϊ%d\n", betA);
			printf("��������Ҫ��ע������(100�ı���):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n��������,������100�ı���,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
	}//��ҵ����ֽ���

	//���ǵ����Ƿ��ע�ͼ�ע
	choose = -1;//����
	if ((betAround > 500) && (cardtypeB <= 24))
	{
		choose = 0;
	}
	if ((betAround > 800) && (cardtypeB <= 102))//�����ע���ҵ�����������Ϊһ��,���Զ���֮һ��������
	{
		rander1 = rand();//ȡһ�������

		if (rander1 % 2 == 0)
		{
			choose = 0;
		}
		if (rander1 % 2 == 1)
		{
			choose = 1;
		}
	}
	if (cardtypeB >= 103)//������������Ϊ����
	{
		if (cardtypeA > cardtypeB)
		{
			rander1 = rand();

			if (rander1 % 4 == 0)
			{
				choose = 0;
			}
			else 
			{
				choose = 1;
			}

		}
		if (cardtypeA <= cardtypeB)
		{
			choose = 1;
		}

	}
	if (betB < 200)//����ʣ������Ѳ���,�Զ���ע
	{
		choose = 1;
	}

	if (choose == 1)//�����ֵ���ѡ���ע
	{
		printf("\n����ѡ���ע\n");
		if (betB <= betAround)//���Եĳ��벻��,�Զ�ȫ����ע
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n����ʣ��ĳ��벻�����µ�ע,���Եĳ�����ȫ����ע\n\n");
			printf("���潫���뿪�ƽ׶�\n");
			system("pause>nul");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���Եĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж���ҵ�����
			typeB(&B[0], 7);//�жϵ��Ե�����

			system("pause>nul");

			printf("\n\n��������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���Ե�����Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
				betB = betB + betall;
				if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
				{
					printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//ƽ��
			{
				if (cardtypeA <= 24)//���Ʊȴ�С
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
						{
							printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
						betB = betB + betall;
						if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
						{
							printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n����˫��ƽ��");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//���Ը�ע,�����벻��(������)

		if (betB > betAround)//���Ը�ע,�ҳ������(�ڶ���)
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//���Գ��벻��100,����ע
			{
				chooseplus = 0;
			}
			if (betB >= 100)//���Գ����㹻100
			{
				if (cardtype <= 102)//��������Ϊ���ƻ�һ��,���Բ���ע
				{
					chooseplus = 0;
				}

				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//��������Ϊ����
				{
					rander1 = rand();
					if (rander1 % 6 == 0)//��������֮һ���ʼ�ע
					{
						if ((betB >= 300) && (betB <= 500))
						{
							chooseplus = 1;
							pointplus = 100;//���Լ�ע100
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB < 300)
						{
							chooseplus = 0;
						}
					}
					if ((rander1 % 5 == 0) && (cardtypeA <= cardtypeB))//�������֮һ���ʼӴ�ע
					{
						if ((betB > 500) && (betB <= 1000))
						{
							chooseplus = 1;
							pointplus = 300;//���Լ�ע300
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB > 1000)
						{
							chooseplus = 1;
							pointplus = 500;//���Լ�ע500
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}

					}
					if ((rander1 % 5 == 2) || (rander1 % 5 == 3) || (rander1 % 5 == 4))//�������֮�����ʲ���ע
					{
						chooseplus = 0;
					}
				}
				if ((cardtype >= 2911)&&(cardtype<=2933))//��������Ϊ������˳��
				{
					if (betB < 200)
					{
						chooseplus = 1;
						pointplus = 100;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 200) && (betB < 300))
					{
						chooseplus = 1;
						pointplus = 200;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 600) && (betB >= 300) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1000) && (betB >= 600) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 600;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 3000) && (betB >= 1000) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 1000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 3000) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 2000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
				}
				if (cardtype >= 2934)//�������ʹ���˳��
				{
					if (betB < 200)
					{
						chooseplus = 1;
						pointplus = 100;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 200) && (betB < 300))
					{
						chooseplus = 1;
						pointplus = 200;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 400) && (betB >= 300))
					{
						chooseplus = 1;
						pointplus = 300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 600) && (betB >= 400) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 400;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 800) && (betB >= 600) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 600;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1000) && (betB >= 800) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 800;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 2000) && (betB >= 1000) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 1000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 2000) && (betB >= 1000) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 1500;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 3000) && (cardtypeA <= cardtypeB))
					{
						chooseplus = 1;
						pointplus = 3000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
				}
			}
		}//���Ե�������ע����ע�����
	}
	if (chooseplus == 0)
	{
		printf("\n����ѡ�񲻼�ע\n");
		system("pause>nul");
		printf("\n�����ֽ���,���ֹ���ע%d\n", betAround + betBround);
		chooseplus = -1;//����
		pointplus = 0;
		choose = -1;
		betAround = 0;
		betBround = 0;
	}
	if (chooseplus == 1)//����ѡ���ע
	{
		printf("\n����ѡ���ע%d\n", pointplus);
		printf("\n����ѡ���ע������\n");
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//���ѡ���ڵ��Ժ�����
		{
			printf("\n��ѡ������,���ź������Ϸ������!\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//���ѡ���ע
		{
			if (betA <= pointplus)//��ҵĳ��벻����Լӵ�ע
			{
				betall = betall + betA;
				betAround = betAround + betA;
				betA = 0;
				printf("\n��ʣ��ĳ��벻����Լӵ�ע,���ĳ�����ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���Եĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж���ҵ�����
				typeB(&B[0], 7);//�жϵ��Ե�����

				system("pause>nul");

				printf("\n\n��������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���Ե�����Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
							{
								printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
							betB = betB + betall;
							if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
							{
								printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			if (betA > pointplus)//���ʣ��ĳ����㹻��ע
			{
				printf("\n��Ϊ����ע\n");
				betA = betA - pointplus;
				betall = betall + pointplus;
				betAround = betAround + pointplus;
			}
		}
		printf("\n�����ֽ���,���ֹ���ע%d\n", betAround + betBround);
		betAround = 0;
		betBround = 0;
		pointplus = 0;
		choose = -1;
		chooseplus = -1;//�����ֽ���
	}

	system("pause>nul");
	printf("\n��������ʤ��\n");
	betAround = 0;
	betBround = 0;
	pointplus = 0;
	choose = -1;
	chooseplus = -1;
	printf("\n�ƺӷ���������Ϊ:");
	colour(&cardall[5]);
	point(&cardall[5]);
	printf("\n\n��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);

	again = fopen(filename, "at");
	fputs("  ", again);
	putcard(&cardall[5]);
	fclose(again);
	system("taskkill/im notepad.exe>nul");
	system("start/b memory.txt");

	system("pause>nul");
	if (betA < 100)//��ҵĳ����Ѳ�����һע
	{
		printf("\n���ĳ����Ѳ���100,���潫ֱ�ӷ��������Ʋ�����\n");
		system("pause>nul");
		printf("\n���潫���뿪�ƽ׶�\n");
		printf("�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);
		printf("\n\n");
		printf("���ĵ���Ϊ:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n���Եĵ���Ϊ:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//�ж�A������
		typeB(&B[0], 7);//�ж�B������

		system("pause>nul");

		printf("\n\n��������Ϊ:");
		typeprint(cardtypeA);
		printf("\n\n���Ե�����Ϊ:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
			betA = betA + betall;
			if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
			{
				printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
			betB = betB + betall;
			if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//���Ʊȴ�С
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n����˫��ƽ��");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//��ʤ�ֿ�ʼ,��ҵĳ����Ѳ�����һע

	if (betA >= 100)//��ʤ�ֿ�ʼ,��ҵĳ����㹻��һע
	{
		printf("����ѡ����ע������\n");//��ʤ����ҿ�ʼ
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n��ѡ������,���ź�������������Ϸ!\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ,��Esc���˳���Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ,��Esc���˳���Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//��ʤ�����ѡ����ע
		{
			printf("��ʣ��ĳ���Ϊ%d\n", betA);
			printf("��������Ҫ��ע������(100�ı���):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//������������������
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n���ĳ��벻��,������������Ҫ��ע������,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n��������,������100�ı���,���Իس�����\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
	}

	choose = 1;//��ʤ�ֵ���ѡ���ע
	if (choose == 1)//��ʤ�ֵ���ѡ���ע
	{
		printf("\n����ѡ���ע\n");
		if (betB <= betAround)//���Եĳ��벻��,�Զ�ȫ����ע
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n����ʣ��ĳ��벻�����µ�ע,���Եĳ�����ȫ����ע\n\n");
			printf("���潫���뿪�ƽ׶�\n");
			system("pause>nul");
			printf("�ƺ�Ϊ:");
			colour(&cardall[1]);
			point(&cardall[1]);
			colour(&cardall[2]);
			point(&cardall[2]);
			colour(&cardall[3]);
			point(&cardall[3]);
			colour(&cardall[4]);
			point(&cardall[4]);
			colour(&cardall[5]);
			point(&cardall[5]);
			printf("\n\n");
			printf("���ĵ���Ϊ:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n���Եĵ���Ϊ:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//�ж���ҵ�����
			typeB(&B[0], 7);//�жϵ��Ե�����

			system("pause>nul");

			printf("\n\n��������Ϊ:");
			typeprint(cardtypeA);
			printf("\n\n���Ե�����Ϊ:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
				betB = betB + betall;
				if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
				{
					printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
					system("pause>nul");
					printf("����������¿�ʼ��Ϸ\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//ƽ��
			{
				if (cardtypeA <= 24)//���Ʊȴ�С
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
						betA = betA + betall;
						if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
						{
							printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
						betB = betB + betall;
						if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
						{
							printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
							system("pause>nul");
							printf("����������¿�ʼ��Ϸ\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n����˫��ƽ��");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//���Ը�ע,�����벻��(��ʤ��)

		if (betB > betAround)//���Ը�ע,�ҳ������(��ʤ��)
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//���Գ��벻��100,����ע
			{
				chooseplus = 0;
			}
			if (betB >= 100)//���Գ����㹻100
			{
				if (cardtype <= 102)//��������Ϊ���ƻ�һ��,���Բ���ע
				{
					chooseplus = 0;
				}

				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//��������Ϊ����
				{
					rander1 = rand();
					if (rander1 % 3 == 0)//��������֮һ���ʼ�ע
					{
						if ((betB >= 300) && (betB <= 500))
						{
							chooseplus = 1;
							pointplus = 200;//���Լ�ע200
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB < 300)
						{
							chooseplus = 0;
						}
					}
					if (rander1 % 5 == 0)//�������֮һ���ʼӴ�ע
					{
						if ((betB > 500) && (betB <= 1000))
						{
							chooseplus = 1;
							pointplus = 400;//���Լ�ע400
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB > 1000)
						{
							chooseplus = 1;
							pointplus = 600;//���Լ�ע600
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}

					}
					if ((rander1 % 3 == 2) || (rander1 % 3 == 1))//�������֮�����ʲ���ע
					{
						chooseplus = 0;
					}
				}
				if ((cardtype >= 2911) && (cardtype <= 2933))//��������Ϊ������˳��
				{
					if (betB < 200)
					{
						chooseplus = 1;
						pointplus = 100;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 200) && (betB < 300))
					{
						chooseplus = 1;
						pointplus = 200;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 600) && (betB >= 300))
					{
						chooseplus = 1;
						pointplus = 300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1000) && (betB >= 600))
					{
						chooseplus = 1;
						pointplus = 600;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 3000) && (betB >= 1000))
					{
						chooseplus = 1;
						pointplus = 1000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if (betB >= 3000)
					{
						chooseplus = 1;
						pointplus = 1500;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
				}
				if (cardtype >= 2934)//�������ʹ���˳��
				{
					if (betB < 200)
					{
						chooseplus = 1;
						pointplus = 100;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB >= 200) && (betB < 300))
					{
						chooseplus = 1;
						pointplus = 200;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 500) && (betB >= 300))
					{
						chooseplus = 1;
						pointplus = 300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 600) && (betB >= 500))
					{
						chooseplus = 1;
						pointplus = 500;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 800) && (betB >= 700))
					{
						chooseplus = 1;
						pointplus = 700;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 900) && (betB >= 800))
					{
						chooseplus = 1;
						pointplus = 900;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1000) && (betB >= 900))
					{
						chooseplus = 1;
						pointplus = 900;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1300) && (betB >= 1000))
					{
						chooseplus = 1;
						pointplus = 1000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 1500) && (betB >= 1300))
					{
						chooseplus = 1;
						pointplus = 1300;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 2000) && (betB >= 1500))
					{
						chooseplus = 1;
						pointplus = 1500;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if ((betB < 5000) && (betB >= 3000))
					{
						chooseplus = 1;
						pointplus = 3000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
					if (betB >= 5000)
					{
						chooseplus = 1;
						pointplus = 5000;
						betBround = betBround + pointplus;
						betB = betB - pointplus;
						betall = betall + pointplus;
					}
				}
			}
		}//���Ծ�ʤ����ע����ע�����
	}
	if (chooseplus == 0)
	{
		printf("\n����ѡ�񲻼�ע\n");
		system("pause>nul");
		chooseplus = -1;//����
		pointplus = 0;
		choose = -1;
		betAround = 0;
		betBround = 0;
		printf("\n���潫���뿪�ƽ׶�\n");
		system("pause>nul");
		printf("�ƺ�Ϊ:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		colour(&cardall[5]);
		point(&cardall[5]);
		printf("\n\n");
		printf("���ĵ���Ϊ:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n���Եĵ���Ϊ:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//�ж���ҵ�����
		typeB(&B[0], 7);//�жϵ��Ե�����

		system("pause>nul");

		printf("\n\n��������Ϊ:");
		typeprint(cardtypeA);
		printf("\n\n���Ե�����Ϊ:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
			betA = betA + betall;
			if (betB < 100)
			{
				printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
			betB = betB + betall;
			if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();

		}
		if (cardtypeA == cardtypeB)//ƽ��
		{
			if (cardtypeA <= 24)//���Ʊȴ�С
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
					{
						printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (Highcardtype == 2)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}

			printf("\n\n����˫��ƽ��");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}
	if (chooseplus == 1)//����ѡ���ע
	{
		printf("\n����ѡ���ע%d\n", pointplus);
		printf("\n����ѡ���ע������\n");
		printf("1.��ע  0.����\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//������������������
		{
			getchar();
			printf("\n��������,������1��0,���Իس�����\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//���ѡ���ڵ��Ժ�����
		{
			printf("\n��ѡ������,���ź������Ϸ������!\n");
			betB = betB + betall;
			printf("��ʣ��ĳ���Ϊ:%d     ����ʣ��ĳ���Ϊ:%d\n\n", betA, betB);
			games++;//������1

			if (betA < 100)
			{
				printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
				system("pause>nul");
				printf("����������¿�ʼ��Ϸ\n");
				system("pause>nul");
				main();
			}
			printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//���ѡ���ע
		{
			if (betA <= pointplus)//��ҵĳ��벻����Լӵ�ע
			{
				betall = betall + betA;
				betAround = betAround + betA;
				betA = 0;
				printf("\n��ʣ��ĳ��벻����Լӵ�ע,���ĳ�����ȫ����ע\n\n");
				printf("���潫���뿪�ƽ׶�\n");
				system("pause>nul");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���Եĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж���ҵ�����
				typeB(&B[0], 7);//�жϵ��Ե�����

				system("pause>nul");

				printf("\n\n��������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���Ե�����Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
							{
								printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
							betB = betB + betall;
							if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
							{
								printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			if (betA > pointplus)//���ʣ��ĳ����㹻��ע
			{
				printf("\n��Ϊ����ע\n");
				betA = betA - pointplus;
				betall = betall + pointplus;
				betAround = betAround + pointplus;
				printf("\n���潫���뿪�ƽ׶�\n");
				printf("�ƺ�Ϊ:");
				colour(&cardall[1]);
				point(&cardall[1]);
				colour(&cardall[2]);
				point(&cardall[2]);
				colour(&cardall[3]);
				point(&cardall[3]);
				colour(&cardall[4]);
				point(&cardall[4]);
				colour(&cardall[5]);
				point(&cardall[5]);
				printf("\n\n");
				printf("���ĵ���Ϊ:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n���Եĵ���Ϊ:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//�ж���ҵ�����
				typeB(&B[0], 7);//�жϵ��Ե�����

				system("pause>nul");

				printf("\n\n��������Ϊ:");
				typeprint(cardtypeA);
				printf("\n\n���Ե�����Ϊ:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
					betB = betB + betall;
					if (betA < 100)//��ҵĳ��벻��,�ж����Ի�ʤ
					{
						printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
						system("pause>nul");
						printf("����������¿�ʼ��Ϸ\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//ƽ��
				{
					if (cardtypeA <= 24)//���Ʊȴ�С
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n�������ʹ�,��ϲ��Ӯ�������Ϸ!!");
							betA = betA + betall;
							if (betB < 100)//���Եĳ��벻��,�ж���һ�ʤ
							{
								printf("\n���Եĳ����Ѳ���100,��ϲ�����ʤ��!!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n���Ե����ʹ�,���ź�������������Ϸ!");
							betB = betB + betall;
							if (betA < 100)//��ҳ��벻��,�ж����Ի�ʤ
							{
								printf("\n���ĳ����Ѳ���100,���ź�������!!\n\n");
								system("pause>nul");
								printf("����������¿�ʼ��Ϸ\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n����˫��ƽ��");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n��%d������Ϸ����,�������������һ����Ϸ\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
		}
	}

}
		

int main()
{
	int gamemode = -1;//��ʼ����Ϸģʽ
	games = 1;//��ʼ����Ϸ����
	cardtype = 0;//��ʼ�����Ƶ���
	cardtypeA = 0;//��ʼ�����A�Ŀ��Ƶ���
	cardtypeB = 0;//��ʼ�����B�����ԣ��Ŀ��Ƶ���
	pointplus = 0;//��ʼ����ע��
	choose = -1;//��ʼ��ѡ��
	chooseplus = -1;//��ʼ����עѡ��
	printf("��ӭ���������˿˵�����!(�������������,������ԶĲ�!!!)\n\n");
	printf("��ѡ����Ϸģʽ:\n1.˫�˶�ս\n2.�˻���ս\n\n������1��2,���Իس�����\n");
	scanf_s("%d", &gamemode);
	for(; (gamemode != 1) && (gamemode != 2);)
	{ 
		getchar();
		printf("\n��������,������1��2,���Իس�����\n");
		scanf_s("%d", &gamemode);
	}
	if (gamemode == 1)//˫�˶�սģʽ
	{
		printf("\n\n���Ѿ�ѡ����˫�˶�սģʽ,���潫������ע����\n");
		system("pause>nul");
		printf("\n��עΪ100,��ע������,ÿ���Զ��µ�ע100\n");
		system("pause>nul");
		printf("\n���������˭Ϊ���A (���A���ڽ���ȥ����Ϸ������������ע)\n");
		system("pause>nul");
		printf("\n����������˫����ʼ��������(ӦΪ100�ı���),���Իس�������(���鲻����2000)\n");
		scanf_s("%d", &betA);
		for (; (betA % 100 != 0) || (betA <= 100);)
		{
			getchar();
			printf("�����ֵ����,������100�ı���,���Իس�����\n");
			scanf_s("%d", &betA);
		}
		betB = betA;
		for (; (betA >= 100) && (betB >= 100);)
		{
			PVP();
		}
	}

	if (gamemode == 2)//�˻���սģʽ
	{
		printf("\n\n���Ѿ�ѡ�����˻���սģʽ,���潫���ܹ���\n");
		system("pause>nul");
		printf("\n��עΪ100,��ע������,ÿ���Զ��µ�ע100\n��Ϊׯ(ÿ����������ע)\n");
		system("pause>nul");
		printf("\n����������˫����ʼ��������(ӦΪ100�ı���),���Իس�������(���鲻����2000)\n");
		scanf_s("%d", &betA);
		for (; (betA % 100 != 0) || (betA <= 100);)
		{
			getchar();
			printf("�����ֵ����,������100�ı���,���Իس�����\n");
			scanf_s("%d", &betA);
		}
		betB = betA;
		for (; (betA >= 100) && (betB >= 100);)
		{
			PVE();
		}
	}

}