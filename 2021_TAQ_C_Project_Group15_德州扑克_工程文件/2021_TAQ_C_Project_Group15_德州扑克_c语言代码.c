#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct cards {
	int point;//卡牌点数
	int colour;//卡牌花色
};

int cardtype = 0;//牌型
int cardtypeA = 0;//A的牌型
int cardtypeB = 0;//B的牌型
int Highcardtype = 0;//高牌牌型
int betall = 0;//总筹码
int betA = 0;//玩家A的筹码
int betB = 0;//玩家B的筹码
int games = 1;//局数
int rounds = 1;//轮数
char cardcolour[5];//牌的花色
char cardpoint[2];//牌的点数
int betAround = 0;//玩家A每轮下的筹码
int betBround = 0;//玩家B每轮下的筹码
int rander1 = 0;//算法随机数1
int rander2 = 0;//算法随机数2
int pointplus = 0;//加注的数量
int chooseplus = -1;//是否加注
int choose = -1;//选择
char filename[] = "memory.txt";
FILE* out;
FILE* again;

void typeprint(int m)
{
	if (m >= 3250)
	{
		printf("同花顺");
	}
	else
	{
		if (m >= 3094)
		{
			printf("四条");
		}
		else
		{
			if (m >= 2938)
			{
				printf("满堂彩");
			}
			else {
				if (m >= 2934)
				{
					printf("同花");
				}
				else {
					if (m >= 2924)
					{
						printf("顺子");
					}
					else {
						if (m >= 2911)
						{
							printf("三条");
						}
						else
						{
							if (m >= 103)
							{
								printf("两对");
							}
							else {
								if (m >= 25)
								{
									printf("一对");
								}
								else {
									printf("高牌");
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
		fputs("方块  ", again);
	}
	if (tr->colour == 2)
	{
		fputs("梅花  ", again);
	}
	if (tr->colour == 3)
	{
		fputs("红桃  ", again);
	}
	if (tr->colour== 4)
	{
		fputs("黑桃  ", again);
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


void* randnumber(int *random)//随机数生成函数
{ 
	if (*random < 100)
	{
		*random= *random + 20000;
	}
	for (;*random>=53;)
	{
		*random = *random - 52;//确保会随机选中52张牌中的每一张
	}
	return random;
}

void colour(struct cards* tr)
{
	if (tr->colour == 1)
	{
		printf("方块");
	}
	if (tr->colour == 2)
	{
		printf("梅花");
	}
	if (tr->colour == 3)
	{
		printf("红桃");
	}
	if (tr->colour == 4)
	{
		printf("黑桃");
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


void PVPsorting(struct cards* tr,int len)//将牌的点数从大到小排序的函数
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


void Highcard(struct cards* tr, int len)//判断是否为高牌的函数(1<=cardtype<=24)
{
	int i = 0;
	if (((tr + len - 1)->point) == 1)//A的高牌
	{
		if (((tr + len - 1)->colour) == 4)
		{
			cardtype = 24;//黑桃A
			return 0;
		}
		if (((tr + len - 1)->colour) == 3)
		{
			cardtype = 23;//红桃A
			return 0;
		}
		if (((tr + len - 1)->colour) == 2)
		{
			cardtype = 22;//梅花A
			return 0;
		}
		if (((tr + len - 1)->colour) == 1)
		{
			cardtype = 21;//方块A
			return 0;
		}
	}

	for (i = 1; i<=5; i++)//K到9的高牌
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


void Onepair(struct cards* tr, int len)//判断是否为一对的函数(25<=cardtype<=102)
{
	int i = 0;
	int k = 0;
	if (((tr + len - 1)->point) ==1 && ((tr + len - 2)->point) == 1)//一对A的情况
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
	
	for (k = 0; k <= 5; k++)//一对2到一对K的情况
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


void Twopairs(struct cards* tr, int len)//判断是否为两对的函数(103<=cardtype<=2910)
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


	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1))//有一对A的情况
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
	}//有一对A的情况
}


void Threeofakind(struct cards* tr, int len)//判断是否为三条的函数(2911<=cardtype<=2923)
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


void Straight(struct cards* tr, int len)//判断是否为顺子的函数(2924<=cardtype<=2933)
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


	if ((tr + len - 1)->point == 1)//顺子为10JQKA的情况
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


void Flush(struct cards* tr, int len)//判断是否为同花的函数(2934<=cardtype<=2937)
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


void Fullhouse(struct cards* tr, int len)//判断是否为满堂彩的函数(2938<=cardtype<=3093)
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

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1))//有一对A的情况
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

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1) && ((tr + len - 3)->point == 1))//有三张A的情况
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


void Fourofakind(struct cards* tr, int len)//判断是否为四条的函数(3094<=cardtype<=3249)
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

	if (((tr + len - 1)->point == 1) && ((tr + len - 2)->point == 1) && ((tr + len - 3)->point == 1) && ((tr + len - 4)->point == 1))//有四条A的情况
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


void StraightFlush(struct cards* tr, int len)//判断是否为同花顺的函数(3050<=cardtype<=3089)
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



void typeA(struct cards* tr, int len)//判断A的牌型
{
	cardtype = 0;
	StraightFlush(tr, 7);//判断牌型是否为同花顺
	if (cardtype >= 3250)
	{
		cardtypeA = cardtype;
	}
	else {
		Fourofakind(tr, 7);//判断牌型是否为炸弹
		if (cardtype >= 3094)
		{
			cardtypeA = cardtype;
		}
		else {
			Fullhouse(tr, 7);//判断牌型是否为满堂彩
			if (cardtype >= 2938)
			{
				cardtypeA = cardtype;
			}
			else {
				Flush(tr, 7);//判断牌型是否为同花
				if (cardtype >= 2934)
				{
					cardtypeA = cardtype;
				}
				else {
					Straight(tr, 7);//判断牌型是否为顺子
					if (cardtype >= 2924)
					{
						cardtypeA = cardtype;
					}
					else {
						Threeofakind(tr, 7);//判断牌型是否为三条
						if (cardtype >= 2911)
						{
							cardtypeA = cardtype;
						}
						else {
							Twopairs(tr, 7);//判断牌型是否为两对
							if (cardtype >= 103)
							{
								cardtypeA = cardtype;
							}
							else {
								Onepair(tr, 7);//判断牌型是否为一对
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


void typeB(struct cards* tr, int len)//判断B的牌型
{
	cardtype = 0;
	StraightFlush(tr, 7);//判断牌型是否为同花顺
	if (cardtype >= 3050)
	{
		cardtypeB = cardtype;
	}
	else {
		Fourofakind(tr, 7);//判断牌型是否为炸弹
		if (cardtype >= 3094)
		{
			cardtypeB = cardtype;
		}
		else {
			Fullhouse(tr, 7);//判断牌型是否为满堂彩
			if (cardtype >= 2938)
			{
				cardtypeB = cardtype;
			}
			else {
				Flush(tr, 7);//判断牌型是否为同花
				if (cardtype >= 2934)
				{
					cardtypeB = cardtype;
				}
				else {
					Straight(tr, 7);//判断牌型是否为顺子
					if (cardtype >= 2924)
					{
						cardtypeB = cardtype;
					}
					else {
						Threeofakind(tr, 7);//判断牌型是否为三条
						if (cardtype >= 2911)
						{
							cardtypeB = cardtype;
						}
						else {
							Twopairs(tr, 7);//判断牌型是否为两对
							if (cardtype >= 103)
							{
								cardtypeB = cardtype;
							}
							else {
								Onepair(tr, 7);//判断牌型是否为一对
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


void Highcardhole(struct cards*a,struct cards*b, struct cards* c, struct cards* d)//a,b为玩家一的两张底牌;c,d为玩家二的两张底牌
{
	Highcardtype = 0;//归零
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
		Highcardtype = 1;//玩家一的底牌点数大
	}

	if (pointB > pointA)
	{
		Highcardtype = 2;//玩家二的底牌点数大
	}

	if (pointA == pointB)
	{
		if (colourA > colourB)
		{
			Highcardtype = 1;//玩家一的底牌花色大
		}
		if (colourB > colourA)
		{
			Highcardtype = 2;//玩家二的底牌花色大
		}
	}

}


int PVP()
{
	int i,k;
	struct cards card[53];//定义52张牌[1]~[52]
	struct cards* tr;

	card[1].point = 1;//点数1为A
	card[1].colour = 1;//花色1为方块

	card[2].point = 1;
	card[2].colour = 2;//花色2为梅花

	card[3].point = 1;
	card[3].colour = 3;//花色3为红桃

	card[4].point = 1;
	card[4].colour = 4;//花色4为黑桃
	tr = &card[4];
	for (i = 2; i <= 13; i++)//点数11为J,点数12为Q,点数13为K
	{
		for (k = 1; k <= 4; k++)
		{
			tr = tr + 1;
			tr->point = i;
			tr->colour = k;
		}
	}	//一副牌52张已定义
	struct cards cardA1;
		cardA1.point = 20;//给玩家A的牌1的点数定义为空
		cardA1.colour = 20;//给玩家A的牌1的花色定义为空
	struct cards cardA2;
		cardA2.point = 20;//给玩家A的牌2的点数定义为空
		cardA2.colour = 20;//给玩家A的牌2的花色定义为空
	struct cards cardB1;
		cardB1.point = 20;//给玩家B的牌1的点数定义为空
		cardB1.colour = 20;//给玩家B的牌1的花色定义为空
	struct cards cardB2;
		cardB2.point = 20;//给玩家B的牌2的点数定义为空
		cardB2.colour = 20;//给玩家B的牌2的花色定义为空

		srand((unsigned)time(NULL));//取一个随机数种子

		int randnum1,randnum2,randnum3,randnum4,randnum5,randnum6,randnum7,randnum8,randnum9;//定义九个随机数
		randnum1= rand();//给randnum1随机取一个数
		int* ptr = &randnum1;
		ptr=randnumber(ptr);//使用randnumber函数将randnum1控制在1~52中
		cardA1 = card[randnum1];//给玩家A的第一张牌随机赋点数和花色

		randnum2 = rand();
		ptr = &randnum2;
		ptr = randnumber(ptr);
		for (; randnum2 == randnum1;)//确保randnum2!=randnum1
		{
			ptr = randnumber(ptr);
		}
		cardA2 = card[randnum2];//给玩家A的第二张牌随机赋点数和花色

		randnum3 = rand();
		ptr = &randnum3;
		ptr = randnumber(ptr);
		for (; randnum3 == randnum1 || randnum3 == randnum2;)
		{
			ptr = randnumber(ptr);
		}
		cardB1 = card[randnum3];//给玩家B的第一张牌随机赋点数和花色

		randnum4 = rand();
		ptr = &randnum4;
		ptr = randnumber(ptr);
		for (; randnum4 == randnum1 || randnum4 == randnum2 || randnum4 == randnum3;)
		{
			ptr = randnumber(ptr);
		}
		cardB2 = card[randnum4];//给玩家B的第二张牌随机赋点数和花色

		struct cards cardall[6];//定义庄家的牌[1]~[5]
		cardall[1] .point = 20;//给庄家牌中的第一张牌的点数定义为空
		cardall[1].colour = 20;//给庄家牌中的第一张牌的花色定义为空
		cardall[2].point = 20;//给庄家牌中的第二张牌的点数定义为空
		cardall[2].colour = 20;//给庄家牌中的第二张牌的花色定义为空
		cardall[3].point = 20;//给庄家牌中的第三张牌的点数定义为空
		cardall[3].colour = 20;//给庄家牌中的第三张牌的花色定义为空
		cardall[4].point = 20;//给庄家牌中的第四张牌的点数定义为空
		cardall[4].colour = 20;//给庄家牌中的第四张牌的花色定义为空
		cardall[5].point = 20;//给庄家牌中的第五张牌的点数定义为空
		cardall[5].colour = 20;//给庄家牌中的第五张牌的花色定义为空

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
		cardall[5] = card[randnum9];//庄家的五张牌全部随机生成完成

		struct cards A[7];//定义玩家A的两张牌和庄家的五张牌组成的牌组
		A[0] = cardA1;
		A[1] = cardA2;
		A[2] = cardall[1];
		A[3] = cardall[2];
		A[4] = cardall[3];
		A[5] = cardall[4];
		A[6] = cardall[5];

		struct cards B[7];//定义玩家B的两张牌和庄家的五张牌组成的牌组
		B[0] = cardB1;
		B[1] = cardB2;
		B[2] = cardall[1];
		B[3] = cardall[2];
		B[4] = cardall[3];
		B[5] = cardall[4];
		B[6] = cardall[5];

		PVPsorting(&A[0], 7);//将玩家A的牌和庄家的牌组成的牌组进行从大到小排序

		PVPsorting(&B[0], 7);//将玩家B的牌和庄家的牌组成的牌组进行从大到小排序

		printf("\n\n当前是第%d局\n", games);
		printf("双方自动下底注100\n\n");
		betA = betA - 100;
		betB = betB - 100;
		betall = 200;
		printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
		system("pause>nul");
		printf("下面将展示玩家A的底牌,请玩家B暂时回避\n");
		system("pause>nul");
		printf("请玩家A记住您的底牌,完成后按回车即可\n\n");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		system("pause>nul");
		printf("\r");
		printf("                            \n");
		printf("下面将展示玩家B的底牌,请玩家A暂时回避\n");
		system("pause>nul");
		printf("请玩家B记住您的底牌,完成后按回车即可\n\n");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);
		system("pause>nul");
		printf("\r");
		printf("                            \n");

		if (betA < 100)//玩家A的筹码已不足下一注
		{
			printf("\n玩家A的筹码已不足100,下面将直接发五张牌并开牌\n");
			system("pause>nul");
			printf("\n下面将进入开牌阶段\n");
			printf("牌河为:");
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
			printf("玩家A的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n玩家B的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断A的牌型
			typeB(&B[0], 7);//判断B的牌型

			system("pause>nul");

			printf("\n\n玩家A的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n玩家B的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)//B的筹码不足,判定A获胜
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
				betB = betB + betall;
				if (betA < 100)//A的筹码不足,判定B获胜
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
		}
	if (betA >= 100)//A的筹码足够下至少一注
	{
		printf("下面进入第一轮,请玩家A选择下注或弃牌\n");//第一轮
		printf("1.下注  0.弃牌\n");
		int choose = -1;
		scanf_s("%d", &choose);
		betBround = 0;
		betAround = 0;
		chooseplus = -1;
		pointplus = -1;

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n玩家A选择弃牌,这局游戏B获胜\n");
			betB = betB + betall;
			printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			if (betB < 100)
			{
				printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}

			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}
		if (choose == 1)
		{
			printf("您剩余的筹码为%d\n",betA);
			printf("请输入您要下注的数量(100的倍数):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround%100)!=0)||(betAround<100)||(betAround>betA);)//输入有误则重新输入
			{
				if(betAround>betA)
				{ 
					getchar();
					printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
				if(((betAround % 100) != 0) || (betAround < 100))
				{
				getchar();
				printf("\n输入有误,请输入100的倍数,并以回车结束\n");
				scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
		printf("\n\n玩家A下注数量为%d", betAround);//玩家A的第一轮结束


		printf("\n\n下面请玩家B选择跟注或弃牌\n");//玩家B的第一轮开始
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//B选择弃牌
		{
			printf("\n玩家B选择弃牌,这局游戏A获胜\n");
			betA = betA + betall;
			printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("\npause>nul");
				main();
			}
			if (betB < 100)
			{
				printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}

			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B的筹码不足,自动全部跟注
			{
				betBround = betB;
				betB = 0;
				betall = betBround + betall;
				printf("\n您剩余的筹码已不足玩家A下的注,已自动为您全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("玩家A的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n玩家B的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断A的牌型
				typeB(&B[0], 7);//判断B的牌型

				system("pause>nul");

				printf("\n\n玩家A的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n玩家B的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
					betA = betA + betall ;
					if (betB < 100)
					{
						printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
					
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
					betB = betB + betall;
					if (betA < 100)//A的筹码不足,判定B获胜
					{
						printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if(cardtypeA==cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;

							printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
						}
					}
					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");						
					PVP();
				}
			}
			else //B的筹码充足
			{
				betBround = betAround;
				betB = betB - betBround;
				betall = betall + betBround;
				chooseplus = -1;
				if (betB >= 100)
				{
					printf("\n已为您自动跟注,请您选择是否加注:1.加注  0.不加注\n");
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n输入有误,请输入1或0,并以回车结束\n");
						scanf_s("%d", &chooseplus);
					}
				}
				
				if (chooseplus == 1)//B选择加注
				{
					printf("您剩余的筹码为%d\n", betB);
					printf("请输入您要加注的数量(100的倍数):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//输入有误则重新输入
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n输入有误,请输入100的倍数,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
					}
				betB = betB - pointplus;
				betBround = betBround + pointplus;
				betall = pointplus + betall;
				}
			}
		}//B下注完成

		

		if (chooseplus == 1)//B加注后询问A是否跟注
		{
			printf("\n玩家B选择加注%d,请玩家A选择跟注或弃牌\n", pointplus);
			printf("1.跟注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//玩家A选择在B加注后弃牌
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}

				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//玩家A选择在B加注后跟注
			{
				if (betA <= pointplus)//A的筹码不足,自动全部跟注
				{
					betall = betA + betall;
					betAround = betA + betAround;
					betA = 0;
					printf("\n您剩余的筹码已不足玩家B加的注,已自动为您全部跟注\n\n");
					printf("下面将进入开牌阶段\n");
					printf("牌河为:");
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
					printf("玩家A的底牌为:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n玩家B的底牌为:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//判断A的牌型
					typeB(&B[0], 7);//判断B的牌型

					system("pause>nul");

					printf("\n\n玩家A的牌型为:");
					typeprint(cardtypeA);
					printf("\n\n玩家B的牌型为:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//B的筹码不足,判定A获胜
						{
							printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();

						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
						betB = betB + betall;
						if (betA < 100)//A的筹码不足,判定B获胜
						{
							printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//高牌比大小
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
									betA = betA + betall;
									if (betB < 100)//B的筹码不足,判定A获胜
									{
										printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
									betB = betB + betall;
									if (betA < 100)//A的筹码不足,判定B获胜
									{
										printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n本局双方平局");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
				}
				betA = betA - pointplus;//玩家A的筹码足够跟注
				betall = betall + pointplus;;
				betAround = betAround + pointplus;
				printf("\n玩家A选择跟注,第一轮共下注%d\n", betAround+betBround);
				system("pause>nul");
			}
			
		}
		
}	
			if ((chooseplus == 0)||(chooseplus==-1))
			{
				printf("\n玩家B选择不加注,第一轮共下注%d\n", betAround+betBround);
				system("pause>nul");
			}

//第一轮结束
		
		
		printf("\n下面进入第二轮\n");//第二轮开始
		system("pause>nul");
		printf("\n牌河发三张牌,依次为:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]); 
		colour(&cardall[3]);
		point(&cardall[3]);//牌河发三张牌完成
		printf("\n\n玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
		system("pause>nul");
		betAround = 0;//玩家A本轮下注数清零
		betBround = 0;//玩家B本轮下注数清零
		pointplus = 0;//本轮加注数清零
		choose = -1;
		chooseplus = -1;

		if (betA < 100)//玩家A的筹码已不够下一注
		{
			printf("\n玩家A的筹码已不足100,下面将直接发满五张牌并开牌\n");
			system("pause>nul");
			printf("\n下面将进入开牌阶段\n");
			printf("牌河为:");
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
			printf("玩家A的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n玩家B的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断A的牌型
			typeB(&B[0], 7);//判断B的牌型

			system("pause>nul");

			printf("\n\n玩家A的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n玩家B的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)//B的筹码不足,判定A获胜
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏,按Esc键退出游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
				betB = betB + betall;
				if (betA < 100)//A的筹码不足,判定B获胜
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏,按Esc键退出游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏,按Esc键退出游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
		}
		if (betA >= 100)//玩家A的筹码足够下至少一注
		{
			printf("请玩家A选择下注或弃牌\n");//第二轮玩家A开始
			printf("1.下注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏,按Esc键退出游戏\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏,按Esc键退出游戏\n");
					system("pause>nul");
					main();
				}

				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (choose == 1)
			{
				printf("您剩余的筹码为%d\n", betA);
				printf("请输入您要下注的数量(100的倍数):\n");
				scanf_s("%d", &betAround);
				for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
				{
					if (betAround > betA)
					{
						getchar();
						printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
						scanf_s("%d", &betAround);
					}
					if (((betAround % 100) != 0) || (betAround < 100))
					{
						getchar();
						printf("\n输入有误,请输入100的倍数,并以回车结束\n");
						scanf_s("%d", &betAround);
					}
				}
				betA = betA - betAround;
				betall = betall + betAround;
			}
			printf("\n\n玩家A下注数量为%d", betAround);//玩家A的第二轮结束
		}

		printf("\n\n下面请玩家B选择跟注或弃牌\n");//玩家B的第二轮开始
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//B选择弃牌
		{
			printf("\n玩家B选择弃牌,这局游戏A获胜\n");
			betA = betA + betall;
			printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1
			if (betB < 100)
			{
				printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}

			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B的筹码不足,自动全部跟注
			{
				betBround = betB;
				betB = 0;
				betall = betall+ betBround;
				printf("\n您剩余的筹码已不足玩家A下的注,已自动为您全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("玩家A的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n玩家B的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断A的牌型
				typeB(&B[0], 7);//判断B的牌型

				system("pause>nul");

				printf("\n\n玩家A的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n玩家B的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100) 
					{
						printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
					
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
					betB = betB + betall;
					if (betA < 100)//A的筹码不足,判定B获胜
					{
						printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
							
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
			}
			else //B的筹码充足
			{
				betBround = betAround;
				betB = betB - betBround;
				betall = betall + betBround;
				if (betB >= 100)
				{
					printf("\n已为您自动跟注,请您选择是否加注:1.加注  0.不加注\n");
					chooseplus = -1;
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n输入有误,请输入1或0,并以回车结束\n");
						scanf_s("%d", &chooseplus);
					}
				}
				


				if (chooseplus == 1)//B选择加注
				{
					printf("您剩余的筹码为%d\n", betB);
					printf("请输入您要加注的数量(100的倍数):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//输入有误则重新输入
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n输入有误,请输入100的倍数,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
					}
					betB = betB - pointplus;
					betBround = betBround + pointplus;
					betall = betall + pointplus;
				}
			}
		}//B下注完成



		if (chooseplus == 1)//B加注后询问A是否跟注
		{
			printf("\n玩家B选择加注%d,请玩家A选择跟注或弃牌\n", pointplus);
			printf("1.跟注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//玩家A选择在B加注后弃牌
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}

				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//玩家A选择在B加注后跟注
			{
				if (betA <= pointplus)//A的筹码不足,自动全部跟注
				{
					betall = betall + betA;
					betAround = betA + betAround;
					betA = 0;
					printf("\n您剩余的筹码已不足玩家B加的注,已自动为您全部跟注\n\n");
					printf("下面将进入开牌阶段\n");
					printf("牌河为:");
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
					printf("玩家A的底牌为:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n玩家B的底牌为:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//判断A的牌型
					typeB(&B[0], 7);//判断B的牌型

					system("pause>nul");

					printf("\n\n玩家A的牌型为:");
					typeprint(cardtypeA);
					printf("\n\n玩家B的牌型为:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//B的筹码不足,判定B获胜
						{
							printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
						betB = betB + betall;
						if (betA < 100)//A的筹码不足,判定B获胜
						{
							printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//高牌比大小
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
									betA = betA + betall;
									if (betB < 100)//B的筹码不足,判定B获胜
									{
										printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
									betB = betB + betall;
									if (betA < 100)//A的筹码不足,判定B获胜
									{
										printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n本局双方平局");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
				}
				betAround = betAround + pointplus;
				betA = betA - pointplus;
				betall = betall + pointplus;
				printf("\n玩家A选择跟注,第二轮共下注%d\n", betAround+betBround);
				system("pause>nul");
			}
			
		}
			if ((chooseplus == 0)||(chooseplus==-1))//B选择不加注
			{
				printf("\n玩家B选择不加注,第二轮共下注%d\n", betAround + betBround);
				system("pause>nul");
			}//第二轮结束


		printf("\n下面进入第三轮\n");//第三轮开始
		printf("\n牌河发第四张张牌:");
		colour(&cardall[4]);
		point(&cardall[4]);
		system("pause>nul");
		printf("\n\n目前牌河为:");
		colour(&cardall[1]);
		point(&cardall[1]);
		colour(&cardall[2]);
		point(&cardall[2]);
		colour(&cardall[3]);
		point(&cardall[3]);
		colour(&cardall[4]);
		point(&cardall[4]);
		printf("\n\n玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
		system("pause>nul");
		betAround = 0;//玩家A本轮下注数清零
		betBround = 0;//玩家B本轮下注数清零
		pointplus = 0;//本轮加注数清零
		choose = -1;
		chooseplus = -1;
		if (betA < 100)//玩家A的筹码已不够下一注
		{
			printf("\n玩家A的筹码已不足100,下面将直接发满五张牌并开牌\n");
			system("pause>nul");
			printf("\n下面将进入开牌阶段\n");
			printf("牌河为:");
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
			printf("玩家A的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n玩家B的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断A的牌型
			typeB(&B[0], 7);//判断B的牌型

			system("pause>nul");

			printf("\n\n玩家A的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n玩家B的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
				betA = betA + betall;
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
				betB = betB + betall;
				if (betA < 100)//A的筹码不足,判定B获胜
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
		}
		if (betA >= 100)//玩家A的筹码足够下至少一注
		{
			printf("请玩家A选择下注或弃牌\n");//第三轮玩家A开始
			printf("1.下注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (choose == 1)
			{
				printf("您剩余的筹码为%d\n", betA);
				printf("请输入您要下注的数量(100的倍数):\n");
				scanf_s("%d", &betAround);
				for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
				{
					if (betAround > betA)
					{
						getchar();
						printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
						scanf_s("%d", &betAround);
					}
					if (((betAround % 100) != 0) || (betAround < 100))
					{
						getchar();
						printf("\n输入有误,请输入100的倍数,并以回车结束\n");
						scanf_s("%d", &betAround);
					}
				}
				betA = betA - betAround;
				betall = betall + betAround;
			}
			printf("\n\n玩家A下注数量为%d", betAround);//玩家A的第三轮结束
		}

		printf("\n\n下面请玩家B选择跟注或弃牌\n");//玩家B的第三轮开始
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//B选择弃牌
		{
			printf("\n玩家B选择弃牌,这局游戏A获胜\n");
			betA = betA + betall;
			printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
			if (betA < 100)
			{
				printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("\npause>nul");
				main();
			}
			if (betB < 100)
			{
				printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B的筹码不足,自动全部跟注
			{			
				betall = betall + betB;
				betBround = betB;
				betB = 0;

				printf("\n您剩余的筹码已不足玩家A下的注,已自动为您全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("玩家A的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n玩家B的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断A的牌型
				typeB(&B[0], 7);//判断B的牌型

				system("pause>nul");

				printf("\n\n玩家A的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n玩家B的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
					betB = betB + betall;
					if (betA < 100)//A的筹码不足,判定B获胜
					{
						printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();

				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)
							{
								printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
							
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
			}
			else //B的筹码充足
			{
				betBround = betAround;
				betB = betB - betBround;
				betall = betall + betBround;
				chooseplus = -1;
				if (betB >= 100)
				{
					printf("\n已为您自动跟注,请您选择是否加注:1.加注  0.不加注\n");
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n输入有误,请输入1或0,并以回车结束\n");
						scanf_s("%d", &chooseplus);
					}
				}
				


				if (chooseplus == 1)//B选择加注
				{
					printf("您剩余的筹码为%d\n", betB);
					printf("请输入您要加注的数量(100的倍数):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//输入有误则重新输入
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n输入有误,请输入100的倍数,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
					}
					betB = betB - pointplus;
					betBround = betBround + pointplus;
					betall = betall + pointplus;
				}
			}
		}//B下注完成



		if (chooseplus == 1)//B加注后询问A是否跟注
		{
			printf("\n玩家B选择加注%d,请玩家A选择跟注或弃牌\n", pointplus);
			printf("1.跟注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//玩家A选择在B加注后弃牌
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}

				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//玩家A选择在B加注后跟注
			{
				if (betA <= pointplus)//A的筹码不足,自动全部跟注
				{
					betall = betall+ betA;
					betAround = betA + betAround;
					betA = 0;
					
					printf("\n您剩余的筹码已不足玩家B加的注,已自动为您全部跟注\n\n");
					printf("下面将进入开牌阶段\n");
					printf("牌河为:");
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
					printf("玩家A的底牌为:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n玩家B的底牌为:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//判断A的牌型
					typeB(&B[0], 7);//判断B的牌型

					system("pause>nul");

					printf("\n\n玩家A的牌型为:");
					typeprint(cardtypeA);
					printf("\n\n玩家B的牌型为:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//B的筹码不足，判定A获胜
						{
							printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏,按Esc键退出游\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
						betB = betB + betall;
						if (betA < 100)//A的筹码不足,判定B获胜
						{
							printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();

					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//高牌比大小
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
									betA = betA + betall;
									if (betB < 100)//B的筹码不足,判定A获胜
									{
										printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
									betB = betB + betall;
									if (betA < 100)//A的筹码不足,判定B获胜
									{
										printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n本局双方平局");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
				}
				betA = betA - pointplus;
				betAround = betAround + pointplus;
				betall = betall + pointplus;
				printf("\n玩家A选择跟注,第三轮共下注%d\n", betAround + betBround);
				system("pause>nul");
			}
		}
		if ((chooseplus == 0) || (chooseplus == -1))
		{
			printf("\n玩家B选择不加注,第三轮共下注%d\n", betAround + betBround);
			system("pause>nul");
		}//第三轮结束

		printf("\n下面进入决胜轮\n");
		system("pause>nul");
		printf("\n牌河发第五张牌:");
		colour(&cardall[5]);
		point(&cardall[5]);
		system("pause>nul");
		printf("\n\n牌河为:");
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

		printf("\n\n玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
		system("pause>nul");
		betAround = 0;//玩家A本轮下注数清零
		betBround = 0;//玩家B本轮下注数清零
		pointplus = 0;//本轮加注数清零

		if (betA < 100)//玩家A的筹码已不够下一注
		{
			printf("\n玩家A的筹码已不足100,下面将直接开牌\n");
			system("pause>nul");
			printf("牌河为:");
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
			printf("玩家A的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n玩家B的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断A的牌型
			typeB(&B[0], 7);//判断B的牌型

			system("pause>nul");

			printf("\n\n玩家A的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n玩家B的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)//玩家B的筹码不足100,判定A获胜
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
				betB = betB + betall;
				if (betA < 100)//A的筹码不足,判定B获胜
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}

				if (cardtypeA == cardtypeB)
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)//玩家B的筹码不足100,判定A获胜
							{
								printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}
					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
		
		}

		if (betA >= 100)//玩家A的筹码足够下至少一注
		{
			printf("请玩家A选择下注或弃牌\n");//决胜轮玩家A开始
			printf("1.下注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				if (betB < 100)
				{
					printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}

				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
			if (choose == 1)
			{
				printf("您剩余的筹码为%d\n", betA);
				printf("请输入您要下注的数量(100的倍数):\n");
				scanf_s("%d", &betAround);
				for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
				{
					if (betAround > betA)
					{
						getchar();
						printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
						scanf_s("%d", &betAround);
					}
					if (((betAround % 100) != 0) || (betAround < 100))
					{
						getchar();
						printf("\n输入有误,请输入100的倍数,并以回车结束\n");
						scanf_s("%d", &betAround);
					}
				}
				betA = betA - betAround;
				betall = betall + betAround;
			}
			printf("\n\n玩家A下注数量为%d", betAround);//玩家A的决胜轮结束
		}

		printf("\n\n下面请玩家B选择跟注或弃牌\n");//玩家B的决胜轮开始
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//B选择弃牌
		{
			printf("\n玩家B选择弃牌,这局游戏A获胜\n");
			betA = betA + betall;
			printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1
			if (betB < 100)
			{
				printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}

			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}


		if (choose == 1)
		{
			if (betB <= betAround)//B的筹码不足,自动全部跟注
			{
				betall = betall + betB;
				betBround = betB;
				betB = 0;
				printf("\n您剩余的筹码已不足玩家A下的注,已自动为您全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("玩家A的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n玩家B的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断A的牌型
				typeB(&B[0], 7);//判断B的牌型

				system("pause>nul");

				printf("\n\n玩家A的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n玩家B的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100) 
					{
						printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
					betB = betB + betall;
					if (betA < 100)//A的筹码不足,判定B获胜
					{
						printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();

				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)//B的筹码不足,判定A获胜
							{
								printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
							
						}
						if (Highcardtype == 2)
						{
							printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
							betB = betB + betall;
							if (betA < 100)//A的筹码不足,判定B获胜
							{
								printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVP();
				}
			}
			else //B的筹码充足
			{
				betBround = betAround;
				betall = betall + betBround;
				betB = betB - betBround;
				chooseplus = -1;
				if (betB >= 100)
				{
					printf("\n已为您自动跟注,请您选择是否加注:1.加注  0.不加注\n");
					scanf_s("%d", &chooseplus);
					for (; (chooseplus != 1) && (chooseplus != 0);)
					{
						getchar();
						printf("\n输入有误,请输入1或0,并以回车结束\n");
						scanf_s("%d", &chooseplus);
					}
				}
				


				if (chooseplus == 1)//B选择加注
				{
					printf("您剩余的筹码为%d\n", betB);
					printf("请输入您要加注的数量(100的倍数):\n");
					scanf_s("%d", &pointplus);
					for (; ((pointplus % 100) != 0) || (pointplus < 100) || (pointplus > betB);)//输入有误则重新输入
					{
						if (pointplus > betB)
						{
							getchar();
							printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
						if (((pointplus % 100) != 0) || (pointplus < 100))
						{
							getchar();
							printf("\n输入有误,请输入100的倍数,并以回车结束\n");
							scanf_s("%d", &pointplus);
						}
					}
					betB = betB - pointplus;
					betBround = betBround + pointplus;
					betall = betall + pointplus;
				}
			}
		}//B下注完成



		if (chooseplus == 1)//B加注后询问A是否跟注
		{
			printf("\n玩家B选择加注%d,请玩家A选择跟注或弃牌\n", pointplus);
			printf("1.跟注  0.弃牌\n");
			int choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//玩家A选择在B加注后弃牌
			{
				printf("\n玩家A选择弃牌,这局游戏B获胜\n");
				betB = betB + betall;
				printf("玩家A剩余的筹码为:%d     玩家B剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}

			if (choose == 1)//玩家A选择在B加注后跟注
			{
				if (betA <= pointplus)//A的筹码不足,自动全部跟注
				{
					betall = betall + betA;
					betAround = betA + betAround;
					betA = 0;
					
					printf("\n您剩余的筹码已不足玩家B加的注,已自动为您全部跟注\n\n");
					printf("下面将进入开牌阶段\n");
					printf("牌河为:");
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
					printf("玩家A的底牌为:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n玩家B的底牌为:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//判断A的牌型
					typeB(&B[0], 7);//判断B的牌型

					system("pause>nul");

					printf("\n\n玩家A的牌型为:");
					typeprint(cardtypeA);
					printf("\n\n玩家B的牌型为:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//B的筹码不足,判定A获胜
						{
							printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
						betB = betB + betall;
						if (betA < 100)//A的筹码不足,判定B获胜
						{
							printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++; 
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
						if (cardtypeA == cardtypeB)
						{
							if (cardtypeA <= 24)//高牌比大小
							{
								Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
								if (Highcardtype == 1)
								{
									printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
									betA = betA + betall;
									if (betB < 100)//玩家B的筹码不足100,判定A获胜
									{
										printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
								if (Highcardtype == 2)
								{
									printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
									betB = betB + betall;
									if (betA < 100)//A的筹码不足,判定B获胜
									{
										printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
										system("pause>nul");
										printf("按任意键重新开始游戏\n");
										system("pause>nul");
										main();
									}
									games++;
									printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
									system("pause>nul");
									PVP();
								}
							}
							printf("\n\n本局双方平局");
							betA = betA + betall / 2;
							betB = betB + betall / 2;
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVP();
						}
					
				}
				betA = betA - pointplus;
				betAround = betAround + pointplus;
				betall = betall + pointplus;
				printf("\n玩家A选择跟注,决胜轮共下注%d\n", betAround + betBround);
				system("pause>nul");
			}
		}
		if ((chooseplus == 0) || (chooseplus == -1))
		{
			printf("\n玩家B选择不加注,决胜轮共下注%d\n", betAround + betBround);
			system("pause>nul");
		}
		
		printf("四轮已全部结束,下面将开牌决胜");

		printf("牌河为:");
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
		printf("玩家A的底牌为:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n玩家B的底牌为:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//判断A的牌型
		typeB(&B[0], 7);//判断B的牌型

		system("pause>nul");

		printf("\n\n玩家A的牌型为:");
		typeprint(cardtypeA);
		printf("\n\n玩家B的牌型为:");
		typeprint(cardtypeB);

		system("pause>nul");
		
		if (cardtypeA > cardtypeB)
		{
			printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
			betA = betA + betall;
			games++;
			if (betB < 100)
			{
				printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
			betB = betB + betall;
			if (betA < 100)//A的筹码不足,判定B获胜
			{
				printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVP();
		}
			if (cardtypeA == cardtypeB)
			{
				if (cardtypeA <= 24)//高牌比大小
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n玩家A的牌型大,恭喜玩家A赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)
						{
							printf("\n玩家B的筹码已不足100,恭喜玩家A获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
					if (Highcardtype == 2)
					{
						printf("\n\n玩家B的牌型大,恭喜玩家B赢得这局游戏!!");
						betB = betB + betall;
						if (betA < 100)//A的筹码不足,判定B获胜
						{
							printf("\n玩家A的筹码已不足100,恭喜玩家B获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVP();
					}
				}
				printf("\n\n本局双方平局");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVP();
			}
}


int PVE()
{
	int i, k;
	struct cards card[53];//定义52张牌[1]~[52]
	struct cards* tr;

	card[1].point = 1;//点数1为A
	card[1].colour = 1;//花色1为方块

	card[2].point = 1;
	card[2].colour = 2;//花色2为梅花

	card[3].point = 1;
	card[3].colour = 3;//花色3为红桃

	card[4].point = 1;
	card[4].colour = 4;//花色4为黑桃
	tr = &card[4];
	for (i = 2; i <= 13; i++)//点数11为J,点数12为Q,点数13为K
	{
		for (k = 1; k <= 4; k++)
		{
			tr = tr + 1;
			tr->point = i;
			tr->colour = k;
		}
	}	//一副牌52张已定义
	struct cards cardA1;
	cardA1.point = 20;//给玩家的牌1的点数定义为空
	cardA1.colour = 20;//给玩家的牌1的花色定义为空
	struct cards cardA2;
	cardA2.point = 20;//给玩家的牌2的点数定义为空
	cardA2.colour = 20;//给玩家的牌2的花色定义为空
	struct cards cardB1;
	cardB1.point = 20;//给电脑的牌1的点数定义为空
	cardB1.colour = 20;//给电脑的牌1的花色定义为空
	struct cards cardB2;
	cardB2.point = 20;//给电脑的牌2的点数定义为空
	cardB2.colour = 20;//给电脑的的牌2的花色定义为空

	srand((unsigned)time(NULL));//取一个随机数种子

	int randnum1, randnum2, randnum3, randnum4, randnum5, randnum6, randnum7, randnum8, randnum9;//定义九个随机数
	randnum1 = rand();//给randnum1随机取一个数
	int* ptr = &randnum1;
	ptr = randnumber(ptr);//使用randnumber函数将randnum1控制在1~52中
	cardA1 = card[randnum1];//给玩家的第一张牌随机赋点数和花色

	randnum2 = rand();
	ptr = &randnum2;
	ptr = randnumber(ptr);
	for (; randnum2 == randnum1;)//确保randnum2!=randnum1
	{
		ptr = randnumber(ptr);
	}
	cardA2 = card[randnum2];//给玩家的第二张牌随机赋点数和花色

	randnum3 = rand();
	ptr = &randnum3;
	ptr = randnumber(ptr);
	for (; randnum3 == randnum1 || randnum3 == randnum2;)
	{
		ptr = randnumber(ptr);
	}
	cardB1 = card[randnum3];//给电脑的第一张牌随机赋点数和花色

	randnum4 = rand();
	ptr = &randnum4;
	ptr = randnumber(ptr);
	for (; randnum4 == randnum1 || randnum4 == randnum2 || randnum4 == randnum3;)
	{
		ptr = randnumber(ptr);
	}
	cardB2 = card[randnum4];//给电脑的第二张牌随机赋点数和花色

	struct cards cardall[6];//定义庄家的牌[1]~[5]
	cardall[1].point = 20;//给庄家牌中的第一张牌的点数定义为空
	cardall[1].colour = 20;//给庄家牌中的第一张牌的花色定义为空
	cardall[2].point = 20;//给庄家牌中的第二张牌的点数定义为空
	cardall[2].colour = 20;//给庄家牌中的第二张牌的花色定义为空
	cardall[3].point = 20;//给庄家牌中的第三张牌的点数定义为空
	cardall[3].colour = 20;//给庄家牌中的第三张牌的花色定义为空
	cardall[4].point = 20;//给庄家牌中的第四张牌的点数定义为空
	cardall[4].colour = 20;//给庄家牌中的第四张牌的花色定义为空
	cardall[5].point = 20;//给庄家牌中的第五张牌的点数定义为空
	cardall[5].colour = 20;//给庄家牌中的第五张牌的花色定义为空

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
	cardall[5] = card[randnum9];//庄家的五张牌全部随机生成完成

	struct cards A[7];//定义玩家的两张牌和庄家的五张牌组成的牌组
	A[0] = cardA1;
	A[1] = cardA2;
	A[2] = cardall[1];
	A[3] = cardall[2];
	A[4] = cardall[3];
	A[5] = cardall[4];
	A[6] = cardall[5];

	struct cards B[7];//定义电脑的两张牌和庄家的五张牌组成的牌组
	B[0] = cardB1;
	B[1] = cardB2;
	B[2] = cardall[1];
	B[3] = cardall[2];
	B[4] = cardall[3];
	B[5] = cardall[4];
	B[6] = cardall[5];

	PVPsorting(&A[0], 7);//将玩家的牌和庄家的牌组成的牌组进行从大到小排序

	PVPsorting(&B[0], 7);//将电脑的牌和庄家的牌组成的牌组进行从大到小排序

	printf("\n\n当前是第%d局\n", games);
	printf("双方自动下底注100\n\n");
	betA = betA - 100;
	betB = betB - 100;
	betall = 200;
	printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
	printf("下面将展示您的底牌\n");
	system("pause>nul");
	printf("请记住您的底牌,完成后按回车即可\n\n");
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
	fputs("您的底牌为:   ", again);
	putcard(&cardA1);
	fputs("  ", again);
	putcard(&cardA2);
	fclose(again);
	fclose(out);
	system("start/b memory.txt");

	system("pause>nul");

	

	if (betA < 100)//玩家的筹码已不足下一注
	{
		printf("\n您的筹码已不足100,下面将直接发五张牌并开牌\n");
		system("pause>nul");
		printf("\n下面将进入开牌阶段\n");
		printf("牌河为:");
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
		printf("您的底牌为:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n电脑的底牌为:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//判断玩家的牌型
		typeB(&B[0], 7);//判断电脑的牌型

		system("pause>nul");

		printf("\n\n您的牌型为:");
		typeprint(cardtypeA);
		printf("\n\n电脑的牌型为:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n您牌型大,恭喜您赢得这局游戏!!");
			betA = betA + betall;
			if (betB < 100)//电脑筹码不足,判定玩家获胜
			{
				printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
			betB = betB + betall;
			if (betA < 100)//玩家的筹码不足,判定电脑获胜
			{
				printf("\n您的筹码已不足100,很遗憾您输了!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//高牌比大小
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n本局双方平局");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//玩家的筹码不足自动开牌已结束

	if (betA >= 100)//玩家的筹码足够下至少一注
	{
		printf("下面进入第一轮,请您选择下注或弃牌\n");//第一轮
		printf("1.下注  0.弃牌\n");
		int choose = -1;
		scanf_s("%d", &choose);
		betBround = 0;
		betAround = 0;
		chooseplus = -1;
		pointplus = -1;

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n您选择弃牌,这局游戏电脑获胜\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)
		{
			printf("您剩余的筹码为%d\n", betA);
			printf("请输入您要下注的数量(100的倍数):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n输入有误,请输入100的倍数,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
		printf("\n\n您下注数量为%d", betAround);//玩家的第一轮结束
	}//玩家足够下一注已结束

	rander1 = rand();
	rander2 = rand();
	choose = -1;
	//电脑进行判断是否跟注和加注
	typeA(&A[0], 7);
	typeB(&B[0], 7);
	if (cardtypeB <= 24)//电脑为高牌
	{
		if ((rander1 % 4) == 0)//电脑四分之一概率跟注
		{
			choose = 1;
		}
		if (((rander1 % 4) == 1)|| ((rander1 % 4) == 2)|| ((rander1 % 4) == 3))//电脑四分之三概率弃牌
		{
			choose = 0;
		}
	}

	if ((cardtypeB >= 25) && (cardtypeB <= 102))//电脑为一对
	{
		rander1 = rand();//重新获得一个随机数

		if ((rander1 % 2) == 0)//电脑二分之一概率跟注
		{
			choose = 1;
		}
		if ((rander1 % 2) == 1)//电脑二分之一概率弃牌
		{
			choose = 0;
		}
	}

	if ((cardtypeB >= 103) && (cardtypeB <= 2910))//电脑为两对
	{
		if (((rander1 % 4) == 0) || ((rander1 % 4) == 1) || ((rander1 % 4) == 2))//电脑四分之三概率跟注
		{
			choose = 1;
		}
		if (((rander1 % 4) == 3))//电脑四分之一概率弃牌
		{
			choose = 0;
		}
	}
	if (cardtypeB >= 2911)//电脑牌型大于两对
	{
		choose = 1;//电脑跟注
	}
	if (betB <= 200)//如果电脑筹码已不多,自动跟注
	{
		choose = 1;//电脑跟注
	}

	if (choose == 0)//电脑选择弃牌
	{
		printf("\n电脑选择弃牌,恭喜您赢得这局游戏!!\n");
		betA = betA + betall;
		printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
		games++;//局数加1

		if (betB < 100)
		{
			printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
			system("pause>nul");
			printf("按任意键重新开始游戏\n");
			system("pause>nul");
			main();
		}
		printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
		system("pause>nul");
		PVE();
	}

	if (choose == 1)//电脑选择跟注(第一轮)
	{
		printf("\n电脑选择跟注\n");
		if (betB <= betAround)//电脑的筹码不足,自动全部跟注
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n电脑剩余的筹码不足您下的注,电脑的筹码已全部跟注\n\n");
			printf("下面将进入开牌阶段\n");
			system("pause>nul");
			printf("牌河为:");
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
			printf("您的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n电脑的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断玩家的牌型
			typeB(&B[0], 7);//判断电脑的牌型

			system("pause>nul");

			printf("\n\n您的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n电脑的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
				betB = betB + betall;
				if (betA < 100)//玩家的筹码不足,判定电脑获胜
				{
					printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//平局
			{
				if (cardtypeA <= 24)//高牌比大小
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//电脑的筹码不足,判定玩家获胜
						{
							printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
						betB = betB + betall;
						if (betA < 100)//玩家筹码不足,判定电脑获胜
						{
							printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n本局双方平局");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//电脑跟注,但筹码不足
		if (betB > betAround)//电脑跟注且筹码充足
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//电脑筹码不足100,不加注
			{
				chooseplus = 0;
			}
			if (betB >= 100)
			{
				if (cardtype <= 102)//电脑牌型为高牌,电脑不加注
				{
					chooseplus = 0;
				}
				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//电脑牌型为两对
				{
					rander1 = rand();
					if (rander1 % 5 == 0)//电脑五分之一概率加注100
					{
						if (betB <= 500)
						{
							chooseplus = 1;
							pointplus = 100;//电脑加注100
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
					}
					if (rander1 % 5 == 1)//电脑五分之一概率加注300
					{
						if (betB > 500)
						{
							chooseplus = 1;
							pointplus = 300;//电脑加注300
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
					if ((rander1 % 5 == 2) || (rander1 % 5 == 3) || (rander1 % 5 == 4))//电脑五分之三概率不加注
					{
						chooseplus = 0;
					}
				}
				if (cardtype >= 2911)//电脑牌型大于两对
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
			printf("\n电脑选择不加注\n");
			system("pause>nul");
			printf("\n第一轮结束,本轮共下注%d\n", betAround + betBround);
			chooseplus = -1;//归零
			pointplus = 0;
			choose = -1;
			betAround = 0;
			betBround = 0;
		}
		if (chooseplus == 1)//电脑选择加注
		{
			printf("\n电脑选择加注%d\n", pointplus);
			printf("\n请您选择跟注或弃牌\n");
			printf("1.跟注  0.弃牌\n");
			choose = -1;
			scanf_s("%d", &choose);

			for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
			{
				getchar();
				printf("\n输入有误,请输入1或0,并以回车结束\n");
				scanf_s("%d", &choose);
			}

			if (choose == 0)//玩家选择在电脑后弃牌
			{
				printf("\n您选择弃牌,很遗憾这局游戏您输了!\n");
				betB = betB + betall;
				printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
				games++;//局数加1

				if (betA < 100)
				{
					printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (choose == 1)//玩家选择跟注
			{
				if (betA <= pointplus)//玩家的筹码不足电脑加的注
				{
					betall = betall + betA;
					betAround = betAround + betA;
					betA = 0;
					printf("\n您剩余的筹码不足电脑加的注,您的筹码已全部跟注\n\n");
					printf("下面将进入开牌阶段\n");
					system("pause>nul");
					printf("牌河为:");
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
					printf("您的底牌为:");
					colour(&cardA1);
					point(&cardA1);
					colour(&cardA2);
					point(&cardA2);
					printf("\n\n电脑的底牌为:");
					colour(&cardB1);
					point(&cardB1);
					colour(&cardB2);
					point(&cardB2);

					typeA(&A[0], 7);//判断玩家的牌型
					typeB(&B[0], 7);//判断电脑的牌型

					system("pause>nul");

					printf("\n\n您的牌型为:");
					typeprint(cardtypeA);
					printf("\n\n电脑的牌型为:");
					typeprint(cardtypeB);

					system("pause>nul");

					if (cardtypeA > cardtypeB)
					{
						printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)
						{
							printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();
					}
					if (cardtypeB > cardtypeA)
					{
						printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
						betB = betB + betall;
						if (betA < 100)//玩家的筹码不足,判定电脑获胜
						{
							printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (cardtypeA == cardtypeB)//平局
					{
						if (cardtypeA <= 24)//高牌比大小
						{
							Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
							if (Highcardtype == 1)
							{
								printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
								betA = betA + betall;
								if (betB < 100)//电脑的筹码不足,判定玩家获胜
								{
									printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
									system("pause>nul");
									printf("按任意键重新开始游戏\n");
									system("pause>nul");
									main();
								}
								games++;
								printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
								system("pause>nul");
								PVE();

							}
							if (Highcardtype == 2)
							{
								printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
								betB = betB + betall;
								if (betA < 100)//玩家筹码不足,判定电脑获胜
								{
									printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
									system("pause>nul");
									printf("按任意键重新开始游戏\n");
									system("pause>nul");
									main();
								}
								games++;
								printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
								system("pause>nul");
								PVE();
							}
						}

						printf("\n\n本局双方平局");
						betA = betA + betall / 2;
						betB = betB + betall / 2;
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}
				if (betA > pointplus)//玩家剩余的筹码足够跟注
				{
					printf("\n已为您跟注\n");
					betA = betA - pointplus;
					betall = betall + pointplus;
					betAround = betAround + pointplus;
				}
			}
			printf("\n第一轮结束,本轮共下注%d\n", betAround + betBround);
			betAround = 0;
			betBround = 0;
			pointplus = 0;
			choose = -1;
			chooseplus = -1;
		}	
	}//第一轮结束

	system("pause>nul");
	printf("\n下面进入第二轮\n");
	system("pause>nul");
	betAround = 0;
	betBround = 0;
	pointplus = 0;
	choose = -1;
	chooseplus = -1;
	printf("\n牌河发三张牌,依次为:");
	colour(&cardall[1]);
	point(&cardall[1]);
	colour(&cardall[2]);
	point(&cardall[2]);
	colour(&cardall[3]);
	point(&cardall[3]);//牌河发三张牌完成
	printf("\n\n您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
	
	again = fopen(filename, "at");
	fputs("\n牌河:  ", again);
	putcard(&cardall[1]);
	fputs("  ", again);
	putcard(&cardall[2]);
	fputs("  ", again);
	putcard(&cardall[3]);
	fclose(again);
	system("taskkill/im notepad.exe>nul");
	system("start/b memory.txt");

	system("pause>nul");

	

	if (betA < 100)//玩家的筹码已不够下一注
	{
		printf("\n您的筹码已不足100,下面将直接发满五张牌并开牌\n");
		system("pause>nul");
		printf("\n下面将进入开牌阶段\n");
		printf("牌河为:");
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
		printf("您的底牌为:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n电脑的底牌为:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//判断A的牌型
		typeB(&B[0], 7);//判断B的牌型

		system("pause>nul");

		printf("\n\n您的牌型为:");
		typeprint(cardtypeA);
		printf("\n\n电脑的牌型为:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
			betA = betA + betall;
			if (betB < 100)//电脑的筹码不足,判定玩家获胜
			{
				printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
			betB = betB + betall;
			if (betA < 100)//玩家的筹码不足,判定电脑获胜
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//高牌比大小
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏,按Esc键退出游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n本局双方平局");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//第二轮开始,玩家的筹码已不够下一注

	if (betA >= 100)//第二轮开始,玩家的筹码足够下一注
	{
		printf("请您选择下注或弃牌\n");//第二轮玩家开始
		printf("1.下注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n您选择弃牌,很遗憾您输掉了这局游戏!\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)
		{
			printf("您剩余的筹码为%d\n", betA);
			printf("请输入您要下注的数量(100的倍数):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n输入有误,请输入100的倍数,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
	}//玩家第二轮结束
	//判断电脑是否跟注和加注
	choose = -1;//归零
	if ((betAround > 300) && (cardtypeB <= 24))
	{
		choose = 0;
	}
	if ((betAround > 500) && (cardtypeB <= 102))//玩家下注大且电脑牌型至多为一对,电脑二分之一概率弃牌
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
	if (cardtypeB >= 103)//电脑牌型至少为两对,跟注
	{
		choose = 1;
	}

	if (choose == 0)//电脑选择弃牌
	{
		printf("\n电脑选择弃牌,恭喜您赢得这局游戏!!\n");
		betA = betA + betall;
		printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
		games++;//局数加1

		if (betB < 100)
		{
			printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
			system("pause>nul");
			printf("按任意键重新开始游戏\n");
			system("pause>nul");
			main();
		}
		printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
		system("pause>nul");
		PVE();
	}
	if (choose == 1)//第二轮电脑选择跟注
	{
		printf("\n电脑选择跟注\n");
		if (betB <= betAround)//电脑的筹码不足,自动全部跟注
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n电脑剩余的筹码不足您下的注,电脑的筹码已全部跟注\n\n");
			printf("下面将进入开牌阶段\n");
			system("pause>nul");
			printf("牌河为:");
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
			printf("您的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n电脑的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断玩家的牌型
			typeB(&B[0], 7);//判断电脑的牌型

			system("pause>nul");

			printf("\n\n您的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n电脑的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
				betB = betB + betall;
				if (betA < 100)//玩家的筹码不足,判定电脑获胜
				{
					printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//平局
			{
				if (cardtypeA <= 24)//高牌比大小
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//电脑的筹码不足,判定玩家获胜
						{
							printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
						betB = betB + betall;
						if (betA < 100)//玩家筹码不足,判定电脑获胜
						{
							printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n本局双方平局");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//电脑跟注,但筹码不足(第二轮)

		if (betB > betAround)//电脑跟注,且筹码充足(第二轮)
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//电脑筹码不足100,不加注
			{
				chooseplus = 0;
			}
			if (betB >= 100)//电脑筹码足够100
			{
				if (cardtype <= 102)//电脑牌型为高牌或一对,电脑不加注
				{
					chooseplus = 0;
				}

				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//电脑牌型为两对
				{
					rander1 = rand();//获得一个随机数

					if ((rander1 % 5 == 0) || (rander1 % 5 == 1))//电脑五分之二概率加注
					{
						if ((betB >= 300) && (betB <= 500))
						{
							chooseplus = 1;
							pointplus = 200;//电脑加注200
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB < 300)
						{
							chooseplus = 1;
							pointplus = 100;//电脑加注100
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
					}
					if (rander1 % 5 == 0)//电脑五分之一概率加大注
					{
						if ((betB > 500) && (betB <= 1000))
						{
							chooseplus = 1;
							pointplus = 300;//电脑加注300
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB > 1000)
						{
							chooseplus = 1;
							pointplus = 500;//电脑加注500
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}

					}
					if ((rander1 % 5 == 2) || (rander1 % 5 == 3) || (rander1 % 5 == 4))//电脑五分之三概率不加注
					{
						chooseplus = 0;
					}
				}
				if (cardtype >= 2911)//电脑牌型大于两对
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
		}//电脑第二轮下注、加注已完成
	}
	if (chooseplus == 0)
	{
		printf("\n电脑选择不加注\n");
		system("pause>nul");
		printf("\n第二轮结束,本轮共下注%d\n", betAround + betBround);
		chooseplus = -1;//归零
		pointplus = 0;
		choose = -1;
		betAround = 0;
		betBround = 0;
	}
	if (chooseplus == 1)//电脑选择加注
	{
		printf("\n电脑选择加注%d\n", pointplus);
		printf("\n请您选择跟注或弃牌\n");
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//玩家选择在电脑后弃牌
		{
			printf("\n您选择弃牌,很遗憾这局游戏您输了!\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//玩家选择跟注
		{
			if (betA <= pointplus)//玩家的筹码不足电脑加的注
			{
				betall = betall + betA;
				betAround = betAround + betA;
				betA = 0;
				printf("\n您剩余的筹码不足电脑加的注,您的筹码已全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("您的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n电脑的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断玩家的牌型
				typeB(&B[0], 7);//判断电脑的牌型

				system("pause>nul");

				printf("\n\n您的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n电脑的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)//电脑的筹码不足,判定玩家获胜
							{
								printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
							betB = betB + betall;
							if (betA < 100)//玩家筹码不足,判定电脑获胜
							{
								printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			if (betA > pointplus)//玩家剩余的筹码足够跟注
			{
				printf("\n已为您跟注\n");
				betA = betA - pointplus;
				betall = betall + pointplus;
				betAround = betAround + pointplus;
			}
		}	
		printf("\n第二轮结束,本轮共下注%d\n", betAround + betBround);
		betAround = 0;
		betBround = 0;
		pointplus = 0;
		choose = -1;
		chooseplus = -1;//第二轮结束
	}

	system("pause>nul");
	printf("\n下面进入第三轮\n");
	betAround = 0;
	betBround = 0;
	pointplus = 0;
	choose = -1;
	chooseplus = -1;
	printf("\n牌河发第四张牌为:");
	colour(&cardall[4]);
	point(&cardall[4]);
	printf("\n\n您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);

	again = fopen(filename, "at");
	fputs("  ", again);
	putcard(&cardall[4]);
	fclose(again);
	system("taskkill/im notepad.exe>nul");
	system("start/b memory.txt");

	system("pause>nul");

	

	if (betA < 100)//玩家的筹码已不够下一注
	{
		printf("\n您的筹码已不足100,下面将直接发满五张牌并开牌\n");
		system("pause>nul");
		printf("\n下面将进入开牌阶段\n");
		printf("牌河为:");
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
		printf("您的底牌为:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n电脑的底牌为:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//判断A的牌型
		typeB(&B[0], 7);//判断B的牌型

		system("pause>nul");

		printf("\n\n您的牌型为:");
		typeprint(cardtypeA);
		printf("\n\n电脑的牌型为:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
			betA = betA + betall;
			if (betB < 100)//电脑的筹码不足,判定玩家获胜
			{
				printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
			betB = betB + betall;
			if (betA < 100)//玩家的筹码不足,判定电脑获胜
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//高牌比大小
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏,按Esc键退出游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n本局双方平局");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//第三轮开始,玩家的筹码已不够下一注

	if (betA >= 100)//第三轮开始,玩家的筹码足够下一注
	{
		printf("请您选择下注或弃牌\n");//第三轮玩家开始
		printf("1.下注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n您选择弃牌,很遗憾您输掉了这局游戏!\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)
		{
			printf("您剩余的筹码为%d\n", betA);
			printf("请输入您要下注的数量(100的倍数):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n输入有误,请输入100的倍数,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
	}//玩家第三轮结束

	//考虑电脑是否跟注和加注
	choose = -1;//归零
	if ((betAround > 500) && (cardtypeB <= 24))
	{
		choose = 0;
	}
	if ((betAround > 800) && (cardtypeB <= 102))//玩家下注大且电脑牌型至多为一对,电脑二分之一概率弃牌
	{
		rander1 = rand();//取一个随机数

		if (rander1 % 2 == 0)
		{
			choose = 0;
		}
		if (rander1 % 2 == 1)
		{
			choose = 1;
		}
	}
	if (cardtypeB >= 103)//电脑牌型至少为两对
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
	if (betB < 200)//电脑剩余筹码已不多,自动跟注
	{
		choose = 1;
	}

	if (choose == 1)//第三轮电脑选择跟注
	{
		printf("\n电脑选择跟注\n");
		if (betB <= betAround)//电脑的筹码不足,自动全部跟注
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n电脑剩余的筹码不足您下的注,电脑的筹码已全部跟注\n\n");
			printf("下面将进入开牌阶段\n");
			system("pause>nul");
			printf("牌河为:");
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
			printf("您的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n电脑的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断玩家的牌型
			typeB(&B[0], 7);//判断电脑的牌型

			system("pause>nul");

			printf("\n\n您的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n电脑的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
				betB = betB + betall;
				if (betA < 100)//玩家的筹码不足,判定电脑获胜
				{
					printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//平局
			{
				if (cardtypeA <= 24)//高牌比大小
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//电脑的筹码不足,判定玩家获胜
						{
							printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
						betB = betB + betall;
						if (betA < 100)//玩家筹码不足,判定电脑获胜
						{
							printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n本局双方平局");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//电脑跟注,但筹码不足(第三轮)

		if (betB > betAround)//电脑跟注,且筹码充足(第二轮)
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//电脑筹码不足100,不加注
			{
				chooseplus = 0;
			}
			if (betB >= 100)//电脑筹码足够100
			{
				if (cardtype <= 102)//电脑牌型为高牌或一对,电脑不加注
				{
					chooseplus = 0;
				}

				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//电脑牌型为两对
				{
					rander1 = rand();
					if (rander1 % 6 == 0)//电脑六分之一概率加注
					{
						if ((betB >= 300) && (betB <= 500))
						{
							chooseplus = 1;
							pointplus = 100;//电脑加注100
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB < 300)
						{
							chooseplus = 0;
						}
					}
					if ((rander1 % 5 == 0) && (cardtypeA <= cardtypeB))//电脑五分之一概率加大注
					{
						if ((betB > 500) && (betB <= 1000))
						{
							chooseplus = 1;
							pointplus = 300;//电脑加注300
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB > 1000)
						{
							chooseplus = 1;
							pointplus = 500;//电脑加注500
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}

					}
					if ((rander1 % 5 == 2) || (rander1 % 5 == 3) || (rander1 % 5 == 4))//电脑五分之三概率不加注
					{
						chooseplus = 0;
					}
				}
				if ((cardtype >= 2911)&&(cardtype<=2933))//电脑牌型为三条或顺子
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
				if (cardtype >= 2934)//电脑牌型大于顺子
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
		}//电脑第三轮下注、加注已完成
	}
	if (chooseplus == 0)
	{
		printf("\n电脑选择不加注\n");
		system("pause>nul");
		printf("\n第三轮结束,本轮共下注%d\n", betAround + betBround);
		chooseplus = -1;//归零
		pointplus = 0;
		choose = -1;
		betAround = 0;
		betBround = 0;
	}
	if (chooseplus == 1)//电脑选择加注
	{
		printf("\n电脑选择加注%d\n", pointplus);
		printf("\n请您选择跟注或弃牌\n");
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//玩家选择在电脑后弃牌
		{
			printf("\n您选择弃牌,很遗憾这局游戏您输了!\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//玩家选择跟注
		{
			if (betA <= pointplus)//玩家的筹码不足电脑加的注
			{
				betall = betall + betA;
				betAround = betAround + betA;
				betA = 0;
				printf("\n您剩余的筹码不足电脑加的注,您的筹码已全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("您的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n电脑的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断玩家的牌型
				typeB(&B[0], 7);//判断电脑的牌型

				system("pause>nul");

				printf("\n\n您的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n电脑的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)//电脑的筹码不足,判定玩家获胜
							{
								printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
							betB = betB + betall;
							if (betA < 100)//玩家筹码不足,判定电脑获胜
							{
								printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			if (betA > pointplus)//玩家剩余的筹码足够跟注
			{
				printf("\n已为您跟注\n");
				betA = betA - pointplus;
				betall = betall + pointplus;
				betAround = betAround + pointplus;
			}
		}
		printf("\n第三轮结束,本轮共下注%d\n", betAround + betBround);
		betAround = 0;
		betBround = 0;
		pointplus = 0;
		choose = -1;
		chooseplus = -1;//第三轮结束
	}

	system("pause>nul");
	printf("\n下面进入决胜轮\n");
	betAround = 0;
	betBround = 0;
	pointplus = 0;
	choose = -1;
	chooseplus = -1;
	printf("\n牌河发第五张牌为:");
	colour(&cardall[5]);
	point(&cardall[5]);
	printf("\n\n您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);

	again = fopen(filename, "at");
	fputs("  ", again);
	putcard(&cardall[5]);
	fclose(again);
	system("taskkill/im notepad.exe>nul");
	system("start/b memory.txt");

	system("pause>nul");
	if (betA < 100)//玩家的筹码已不够下一注
	{
		printf("\n您的筹码已不足100,下面将直接发满五张牌并开牌\n");
		system("pause>nul");
		printf("\n下面将进入开牌阶段\n");
		printf("牌河为:");
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
		printf("您的底牌为:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n电脑的底牌为:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//判断A的牌型
		typeB(&B[0], 7);//判断B的牌型

		system("pause>nul");

		printf("\n\n您的牌型为:");
		typeprint(cardtypeA);
		printf("\n\n电脑的牌型为:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
			betA = betA + betall;
			if (betB < 100)//电脑的筹码不足,判定玩家获胜
			{
				printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
			betB = betB + betall;
			if (betA < 100)//玩家的筹码不足,判定电脑获胜
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeA == cardtypeB)
		{
			if (cardtypeA <= 24)//高牌比大小
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (Highcardtype == 2)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏,按Esc键退出游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			printf("\n\n本局双方平局");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}//决胜轮开始,玩家的筹码已不够下一注

	if (betA >= 100)//决胜轮开始,玩家的筹码足够下一注
	{
		printf("请您选择下注或弃牌\n");//决胜轮玩家开始
		printf("1.下注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)
		{
			printf("\n您选择弃牌,很遗憾您输掉了这局游戏!\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏,按Esc键退出游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏,按Esc键退出游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//决胜轮玩家选择下注
		{
			printf("您剩余的筹码为%d\n", betA);
			printf("请输入您要下注的数量(100的倍数):\n");
			scanf_s("%d", &betAround);
			for (; ((betAround % 100) != 0) || (betAround < 100) || (betAround > betA);)//输入有误则重新输入
			{
				if (betAround > betA)
				{
					getchar();
					printf("\n您的筹码不足,请重新输入您要下注的数量,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
				if (((betAround % 100) != 0) || (betAround < 100))
				{
					getchar();
					printf("\n输入有误,请输入100的倍数,并以回车结束\n");
					scanf_s("%d", &betAround);
				}
			}
			betA = betA - betAround;
			betall = betall + betAround;
		}
	}

	choose = 1;//决胜轮电脑选择跟注
	if (choose == 1)//决胜轮电脑选择跟注
	{
		printf("\n电脑选择跟注\n");
		if (betB <= betAround)//电脑的筹码不足,自动全部跟注
		{
			betall = betall + betB;
			betBround = betB;
			betB = 0;
			printf("\n电脑剩余的筹码不足您下的注,电脑的筹码已全部跟注\n\n");
			printf("下面将进入开牌阶段\n");
			system("pause>nul");
			printf("牌河为:");
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
			printf("您的底牌为:");
			colour(&cardA1);
			point(&cardA1);
			colour(&cardA2);
			point(&cardA2);
			printf("\n\n电脑的底牌为:");
			colour(&cardB1);
			point(&cardB1);
			colour(&cardB2);
			point(&cardB2);

			typeA(&A[0], 7);//判断玩家的牌型
			typeB(&B[0], 7);//判断电脑的牌型

			system("pause>nul");

			printf("\n\n您的牌型为:");
			typeprint(cardtypeA);
			printf("\n\n电脑的牌型为:");
			typeprint(cardtypeB);

			system("pause>nul");

			if (cardtypeA > cardtypeB)
			{
				printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
				betA = betA + betall;
				if (betB < 100)
				{
					printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
			if (cardtypeB > cardtypeA)
			{
				printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
				betB = betB + betall;
				if (betA < 100)//玩家的筹码不足,判定电脑获胜
				{
					printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
					system("pause>nul");
					printf("按任意键重新开始游戏\n");
					system("pause>nul");
					main();
				}
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();

			}
			if (cardtypeA == cardtypeB)//平局
			{
				if (cardtypeA <= 24)//高牌比大小
				{
					Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
					if (Highcardtype == 1)
					{
						printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
						betA = betA + betall;
						if (betB < 100)//电脑的筹码不足,判定玩家获胜
						{
							printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();

					}
					if (Highcardtype == 2)
					{
						printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
						betB = betB + betall;
						if (betA < 100)//玩家筹码不足,判定电脑获胜
						{
							printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
							system("pause>nul");
							printf("按任意键重新开始游戏\n");
							system("pause>nul");
							main();
						}
						games++;
						printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
						system("pause>nul");
						PVE();
					}
				}

				printf("\n\n本局双方平局");
				betA = betA + betall / 2;
				betB = betB + betall / 2;
				games++;
				printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
				system("pause>nul");
				PVE();
			}
		}//电脑跟注,但筹码不足(决胜轮)

		if (betB > betAround)//电脑跟注,且筹码充足(决胜轮)
		{
			betB = betB - betAround;
			betBround = betAround;
			betall = betall + betBround;
			if (betB < 100)//电脑筹码不足100,不加注
			{
				chooseplus = 0;
			}
			if (betB >= 100)//电脑筹码足够100
			{
				if (cardtype <= 102)//电脑牌型为高牌或一对,电脑不加注
				{
					chooseplus = 0;
				}

				if ((cardtypeB >= 103) && (cardtypeB <= 2910))//电脑牌型为两对
				{
					rander1 = rand();
					if (rander1 % 3 == 0)//电脑三分之一概率加注
					{
						if ((betB >= 300) && (betB <= 500))
						{
							chooseplus = 1;
							pointplus = 200;//电脑加注200
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB < 300)
						{
							chooseplus = 0;
						}
					}
					if (rander1 % 5 == 0)//电脑五分之一概率加大注
					{
						if ((betB > 500) && (betB <= 1000))
						{
							chooseplus = 1;
							pointplus = 400;//电脑加注400
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}
						if (betB > 1000)
						{
							chooseplus = 1;
							pointplus = 600;//电脑加注600
							betBround = betBround + pointplus;
							betB = betB - pointplus;
							betall = betall + pointplus;
						}

					}
					if ((rander1 % 3 == 2) || (rander1 % 3 == 1))//电脑五分之三概率不加注
					{
						chooseplus = 0;
					}
				}
				if ((cardtype >= 2911) && (cardtype <= 2933))//电脑牌型为三条或顺子
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
				if (cardtype >= 2934)//电脑牌型大于顺子
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
		}//电脑决胜轮下注、加注已完成
	}
	if (chooseplus == 0)
	{
		printf("\n电脑选择不加注\n");
		system("pause>nul");
		chooseplus = -1;//归零
		pointplus = 0;
		choose = -1;
		betAround = 0;
		betBround = 0;
		printf("\n下面将进入开牌阶段\n");
		system("pause>nul");
		printf("牌河为:");
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
		printf("您的底牌为:");
		colour(&cardA1);
		point(&cardA1);
		colour(&cardA2);
		point(&cardA2);
		printf("\n\n电脑的底牌为:");
		colour(&cardB1);
		point(&cardB1);
		colour(&cardB2);
		point(&cardB2);

		typeA(&A[0], 7);//判断玩家的牌型
		typeB(&B[0], 7);//判断电脑的牌型

		system("pause>nul");

		printf("\n\n您的牌型为:");
		typeprint(cardtypeA);
		printf("\n\n电脑的牌型为:");
		typeprint(cardtypeB);

		system("pause>nul");

		if (cardtypeA > cardtypeB)
		{
			printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
			betA = betA + betall;
			if (betB < 100)
			{
				printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (cardtypeB > cardtypeA)
		{
			printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
			betB = betB + betall;
			if (betA < 100)//玩家的筹码不足,判定电脑获胜
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();

		}
		if (cardtypeA == cardtypeB)//平局
		{
			if (cardtypeA <= 24)//高牌比大小
			{
				Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
				if (Highcardtype == 1)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)//电脑的筹码不足,判定玩家获胜
					{
						printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (Highcardtype == 2)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}

			printf("\n\n本局双方平局");
			betA = betA + betall / 2;
			betB = betB + betall / 2;
			games++;
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
	}
	if (chooseplus == 1)//电脑选择加注
	{
		printf("\n电脑选择加注%d\n", pointplus);
		printf("\n请您选择跟注或弃牌\n");
		printf("1.跟注  0.弃牌\n");
		choose = -1;
		scanf_s("%d", &choose);

		for (; (choose != 1) && (choose != 0);)//输入有误则重新输入
		{
			getchar();
			printf("\n输入有误,请输入1或0,并以回车结束\n");
			scanf_s("%d", &choose);
		}

		if (choose == 0)//玩家选择在电脑后弃牌
		{
			printf("\n您选择弃牌,很遗憾这局游戏您输了!\n");
			betB = betB + betall;
			printf("您剩余的筹码为:%d     电脑剩余的筹码为:%d\n\n", betA, betB);
			games++;//局数加1

			if (betA < 100)
			{
				printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
				system("pause>nul");
				printf("按任意键重新开始游戏\n");
				system("pause>nul");
				main();
			}
			printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
			system("pause>nul");
			PVE();
		}
		if (choose == 1)//玩家选择跟注
		{
			if (betA <= pointplus)//玩家的筹码不足电脑加的注
			{
				betall = betall + betA;
				betAround = betAround + betA;
				betA = 0;
				printf("\n您剩余的筹码不足电脑加的注,您的筹码已全部跟注\n\n");
				printf("下面将进入开牌阶段\n");
				system("pause>nul");
				printf("牌河为:");
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
				printf("您的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n电脑的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断玩家的牌型
				typeB(&B[0], 7);//判断电脑的牌型

				system("pause>nul");

				printf("\n\n您的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n电脑的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)//电脑的筹码不足,判定玩家获胜
							{
								printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
							betB = betB + betall;
							if (betA < 100)//玩家筹码不足,判定电脑获胜
							{
								printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
			if (betA > pointplus)//玩家剩余的筹码足够跟注
			{
				printf("\n已为您跟注\n");
				betA = betA - pointplus;
				betall = betall + pointplus;
				betAround = betAround + pointplus;
				printf("\n下面将进入开牌阶段\n");
				printf("牌河为:");
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
				printf("您的底牌为:");
				colour(&cardA1);
				point(&cardA1);
				colour(&cardA2);
				point(&cardA2);
				printf("\n\n电脑的底牌为:");
				colour(&cardB1);
				point(&cardB1);
				colour(&cardB2);
				point(&cardB2);

				typeA(&A[0], 7);//判断玩家的牌型
				typeB(&B[0], 7);//判断电脑的牌型

				system("pause>nul");

				printf("\n\n您的牌型为:");
				typeprint(cardtypeA);
				printf("\n\n电脑的牌型为:");
				typeprint(cardtypeB);

				system("pause>nul");

				if (cardtypeA > cardtypeB)
				{
					printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
					betA = betA + betall;
					if (betB < 100)
					{
						printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
				if (cardtypeB > cardtypeA)
				{
					printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
					betB = betB + betall;
					if (betA < 100)//玩家的筹码不足,判定电脑获胜
					{
						printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
						system("pause>nul");
						printf("按任意键重新开始游戏\n");
						system("pause>nul");
						main();
					}
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();

				}
				if (cardtypeA == cardtypeB)//平局
				{
					if (cardtypeA <= 24)//高牌比大小
					{
						Highcardhole(&cardA1, &cardA2, &cardB1, &cardB2);
						if (Highcardtype == 1)
						{
							printf("\n\n您的牌型大,恭喜您赢得这局游戏!!");
							betA = betA + betall;
							if (betB < 100)//电脑的筹码不足,判定玩家获胜
							{
								printf("\n电脑的筹码已不足100,恭喜您获得胜利!!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();

						}
						if (Highcardtype == 2)
						{
							printf("\n\n电脑的牌型大,很遗憾您输掉了这局游戏!");
							betB = betB + betall;
							if (betA < 100)//玩家筹码不足,判定电脑获胜
							{
								printf("\n您的筹码已不足100,很遗憾您输了!!\n\n");
								system("pause>nul");
								printf("按任意键重新开始游戏\n");
								system("pause>nul");
								main();
							}
							games++;
							printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
							system("pause>nul");
							PVE();
						}
					}

					printf("\n\n本局双方平局");
					betA = betA + betall / 2;
					betB = betB + betall / 2;
					games++;
					printf("\n\n第%d局已游戏结束,按任意键进入下一局游戏\n", games - 1);
					system("pause>nul");
					PVE();
				}
			}
		}
	}

}
		

int main()
{
	int gamemode = -1;//初始化游戏模式
	games = 1;//初始化游戏局数
	cardtype = 0;//初始化卡牌点数
	cardtypeA = 0;//初始化玩家A的卡牌点数
	cardtypeB = 0;//初始化玩家B（电脑）的卡牌点数
	pointplus = 0;//初始化加注数
	choose = -1;//初始化选择
	chooseplus = -1;//初始化加注选择
	printf("欢迎来到德州扑克的世界!(本程序仅供娱乐,请勿沉迷赌博!!!)\n\n");
	printf("请选择游戏模式:\n1.双人对战\n2.人机对战\n\n请输入1或2,并以回车结束\n");
	scanf_s("%d", &gamemode);
	for(; (gamemode != 1) && (gamemode != 2);)
	{ 
		getchar();
		printf("\n输入有误,请输入1或2,并以回车结束\n");
		scanf_s("%d", &gamemode);
	}
	if (gamemode == 1)//双人对战模式
	{
		printf("\n\n您已经选择了双人对战模式,下面将介绍下注规则\n");
		system("pause>nul");
		printf("\n单注为100,下注无上限,每局自动下底注100\n");
		system("pause>nul");
		printf("\n现在请决定谁为玩家A (玩家A将在接下去的游戏过程中首先下注)\n");
		system("pause>nul");
		printf("\n现在请输入双方初始筹码数量(应为100的倍数),并以回车键结束(建议不低于2000)\n");
		scanf_s("%d", &betA);
		for (; (betA % 100 != 0) || (betA <= 100);)
		{
			getchar();
			printf("输入的值有误,请输入100的倍数,并以回车结束\n");
			scanf_s("%d", &betA);
		}
		betB = betA;
		for (; (betA >= 100) && (betB >= 100);)
		{
			PVP();
		}
	}

	if (gamemode == 2)//人机对战模式
	{
		printf("\n\n您已经选择了人机对战模式,下面将介绍规则\n");
		system("pause>nul");
		printf("\n单注为100,下注无上限,每局自动下底注100\n您为庄(每轮您将先下注)\n");
		system("pause>nul");
		printf("\n现在请输入双方初始筹码数量(应为100的倍数),并以回车键结束(建议不低于2000)\n");
		scanf_s("%d", &betA);
		for (; (betA % 100 != 0) || (betA <= 100);)
		{
			getchar();
			printf("输入的值有误,请输入100的倍数,并以回车结束\n");
			scanf_s("%d", &betA);
		}
		betB = betA;
		for (; (betA >= 100) && (betB >= 100);)
		{
			PVE();
		}
	}

}