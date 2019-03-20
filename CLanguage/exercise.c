/*
* @Author: Zenith Dandelion
* @Date:   2016-05-08 09:25:50
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-05-24 00:38:55
*/

// #include <stdio.h>

// int main()
// {
// freopen("input.txt","r",stdin);
// 	int num, min = 1000000;
// 	int flag = 1;
// 	while(~scanf("%d",&num))
// 	{
// 		if(flag)
// 			flag = 0;
// 		else
// 		{
// 			flag = 1;
// 			continue;
// 		}
// 		min = min<num?min:num;
// 	}
// 	printf("%d",min);
// 	return 0;
// }



// #include <stdio.h>

// int n;

// int min(int *p)
// {
// 	int min = 1000000;
// 	int i;
// 	for(i = 0; i < n; i++)
// 	{
// 		min = min>*p?*p:min;
// 		p++;
// 	}
// 	return min;
// }

// int max(int *p)
// {
// 	int max = -1000000;
// 	int i;
// 	for(i = 0; i < n; i++)
// 	{
// 		max = max<*p?*p:max;
// 		p++;
// 	}
// 	return max;
// }

// int sum(int *p)
// {
// 	int minnum = min(p);
// 	int maxnum = max(p);
// 	return minnum + maxnum;
// }

// int main()
// {
// 	int a[1000];
// 	int *p = a;
// 	int sumnum;
// 	scanf("%d",&n);
// 	int i;
// 	for(i = 0; i < n; i++)
// 		scanf("%d",p++);
// 	p = a;
// 	sumnum = sum(p);
// 	printf("%d\n",sumnum);
// 	return 0;
// }



// #include <stdio.h>

// void nixu(int *p)
// {
// 	int temp;
// 	int i;
// 	for(i = 0; i < 5; i++)
// 	{
// 		temp = *p;
// 		*p = *(p+9-2*i);
// 		*(p+9-2*i) = temp;
// 		p++;
// 	}
// }

// int main()
// {
// 	int a[10] = {1,2,3,4,5,6,7,8,9,10};
// 	int *p = a;
// 	int i;
// 	nixu(p);
// 	for(i = 0; i < 10; i++)
// 		printf("%d ",*p++);
// 	return 0;
// }



// #include <stdio.h>
// int main()
// {
// 	int *p1,*p2;
// 	int a[2] = {1,2};
// 	int b[2] = {1,2};
// 	p1 = a;
// 	p2 = b;
// 	*p2 = a;
// 	printf("%d %d\n",p1,*p2);
// 	return 0;
// }


#include<stdio.h>
struct student
{
	long num;
	char name[20];
	int score1;
	int score2;
	int score3;
	int score4;
	int score5;
};

int main()
{
	struct student stu[3];
	float ave[3],max,mid,min;
	int i,b,a,c;
	printf("请按顺序输入学生学号，科目一到五的成绩，以及学生的姓名\n");
	for (i=0;i<3;i++)
		scanf("%ld%d%d%d%d%d%s",&stu[i].num,&stu[i].score1,&stu[i].score2,&stu[i].score3,&stu[i].score4,&stu[i].score5,stu[i].name);
	for(i=0;i<3;i++)
		ave[i]=(stu[i].score1+stu[i].score2+stu[i].score3+stu[i].score4+stu[i].score5)/5;
	for(i=0;i<3;i++)
		printf("%s的平均分是%f\n",stu[i].name,ave[i]);
	max=ave[0];
	for(i=0;i<3;i++)
		if(ave[i]>max)
		{
			max=ave[i];
				b=i;
		}
		printf("第一名是%s\n",stu[b].name);
	mid=ave[0];
	for(i=0;i<3;i++)
		if(ave[i]<ave[b]&&ave[i]>mid)
		{
			mid=ave[i];
			a=i;
		}
		printf("第二名是%s\n",stu[a].name);
	min=ave[0];
	for(i=0;i<3;i++)
		if(ave[i]<=min)
		{
			min=ave[i];
				c=i;
		}
		printf("第三名是%s\n",stu[c].name);
}








