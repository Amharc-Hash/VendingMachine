#include<stdio.h>
typedef struct {
	int a, b, c, d;
}coinReturn;

coinReturn vending(int money, int price)
{
	char coin[4] = { 1,2,5,10 };
	int one = 0, two = 0, five = 0, ten = 0;
	coinReturn x{};
	if (money > price && money >= 0 && price >= 0)
	{
		money -= price;
		for (int i = 3; i >= 0; i--)
		{
				if (i == 3)
				{
					ten = money / coin[i];
					money -= coin[i] * ten;
				}
				else if (i == 2)
				{
					five = money / coin[i];
					money -= coin[i] * five;
				}
				else if (i == 1)
				{
					two = money / coin[i];
					money -= coin[i] * two;
				}
				else if (i == 0)
				{
					one = money / coin[i];
					money -= coin[i] * one;
				}
		}
	}

	x.a = one;
	x.b = two;
	x.c = five;
	x.d = ten;
	return x;
}



int main()
{
	int money,price;
	printf("Input your money : ");
	scanf_s("%d", &money);
	printf("Input your price : ");
	scanf_s("%d", &price);
	if (money > price && money >= 0 && price >= 0)
	{
		coinReturn r = vending(money, price);
		printf("\nreturn coin\none = %d two = %d five = %d ten = %d\n", r.a, r.b, r.c, r.d);
	}
	else if (money == price && money >= 0 && price >= 0)
	{
		printf("NO CHANGE\n");
	}
	else if (money < price && money >= 0 && price >= 0)
	{
		printf("NOT ENOUGH MONEY\n");
	}
	else
	{
		printf("ERROR");
	}
	return 0;
}

