#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#define num_mode 100000000

typedef struct big_int
{
	int num[3000];
	int num_digit;
}big_int;

big_int mark[1001];

void calculate(big_int num1,big_int num2,big_int *num3);
void outPut(big_int num1);
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int input_mark[1001],count_input=0;
	int input_figure,count_calculate=1,figure_max=0;
	big_int figure_mark1,figure_mark2,figure_mark3;
	while(scanf("%d",&input_figure)!=EOF)
	{

		if(input_figure==0) break;
		input_mark[count_input++]=input_figure;
		if(figure_max<input_figure) figure_max=input_figure;
	}
	figure_mark1.num[0]=1;
	figure_mark2.num[0]=1;
	figure_mark1.num_digit=1;
	figure_mark2.num_digit=1;

	while(count_calculate<=figure_max)
	{
		if(count_calculate<=2)
			figure_mark3=figure_mark1;
		else
		{
			calculate(figure_mark1,figure_mark2,&figure_mark3);

		}
		for(int count1=0;count1<count_input;count1++)
		{
			if(count_calculate==input_mark[count1])
			{
				mark[count1]=figure_mark3;
			}
		}
		figure_mark1=figure_mark2;
		figure_mark2=figure_mark3;
		count_calculate++;
	}
	for(int count1=0;count1<count_input;count1++)
	{
		outPut(mark[count1]);
	}
	return 0;
}

void calculate(big_int num1,big_int num2,big_int *num3)
{
	int length_1=num1.num_digit,length_2=num2.num_digit;
	int count1=0;
	int sum_mark=0;
	for(;count1<length_1&&count1<length_2;count1++)
	{
		sum_mark+=num1.num[count1]+num2.num[count1];
		num3->num[count1]=sum_mark%num_mode;
		sum_mark/=num_mode;
	}
	for(;count1<length_2;count1++)
	{
		sum_mark+=num2.num[count1];
		num3->num[count1]=sum_mark%num_mode;
		sum_mark/=num_mode;
	}
	for(;count1<length_1;count1++)
	{
		sum_mark+=num1.num[count1];
		num3->num[count1]=sum_mark%num_mode;
		sum_mark/=num_mode;
	}
	if(sum_mark)
	{
		num3->num[count1++]=sum_mark;
	}
	num3->num_digit=count1;
}
void outPut(big_int num1)
{
	int count1=num1.num_digit-1;
	printf("%d",num1.num[count1--]);
	while(count1>=0)
	{
		printf("%08d",num1.num[count1--]);
	}
	printf("\n");
}