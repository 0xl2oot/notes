/*
* @Author: 王永红
* @Date:   2016-04-15 09:40:37
* @Last Modified by:   王永红
* @Last Modified time: 2016-04-15 14:57:43
*/

// #include <stdio.h>
// int main(void)
// {
// 	int i, n;
// 	while(~scanf("%d", &n))
// 	{
// 		for (i = 2;i <= n;)
// 		{
// 			if (n % i == 0)
// 			{
// 				printf("%d ",i);
// 				n /= i;
// 			}
// 			else
// 				i++;
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }


// #include <stdio.h>

// int Min(int number1, int number2, int number3)
// {
//     int min = (number1 < number2) ? number1 : number2;
//     min = (min < number3) ? min : number3;
 
//     return min;
// }

// int GetUglyNumber_Solution(int index)
// {
//     if(index <= 0)
//         return 0;
 
//     int *pUglyNumbers = new int[index];
//     pUglyNumbers[0] = 1;
//     int nextUglyIndex = 1;
 
//     int *pMultiply2 = pUglyNumbers;
//     int *pMultiply3 = pUglyNumbers;
//     int *pMultiply5 = pUglyNumbers;
 
//     while(nextUglyIndex < index)
//     {
//         int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
//         pUglyNumbers[nextUglyIndex] = min;
 
//         while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
//             ++pMultiply2;
//         while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
//             ++pMultiply3;
//         while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
//             ++pMultiply5;
 
//         ++nextUglyIndex;
//     }
 
//     int ugly = pUglyNumbers[nextUglyIndex - 1];
//     delete[] pUglyNumbers;
//     return ugly;
// }

// int main()
// {
// 	int n;
// 	while(scanf("%d",&n) && n)
// 		printf("%d\n",GetUglyNumber_Solution(n));
// 	return 0;
// }




// #define LOCAL
// #include <stdio.h>
// #include <string.h>

// char a[1000005];
// int next1[1000005];

// void cal()
// {
// 	int len = strlen(a);
// 	int i,j=-1;
// 	next1[0]=-1;
// 	for(i=0;i<len;)
// 	{
// 		if(j==-1||a[i]==a[j])
// 		{
// 			i++;
// 			j++;
// 			next1[i]=j;
// 		}
// 		else
// 		{
// 			j=next1[j];
// 		}
// 	}
// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int len,count=1;
// 	while(scanf("%d",&len) && len)
// 	{
// 		scanf("%s",a);
// 		cal();
// 		int i;
// 		printf("Test case #%d\n",count++);
// 		for(i=2;i<=len;i++)
// 		{
// 			if(i%(i-next1[i])==0 && i/(i-next1[i])>=2)
// 				printf("%d %d\n",i,i/(i-next1[i]));
// 		}
// 		printf("\n");;
// 	}
// 	return 0;
// }


// // #define LOCAL
// #include <iostream>
// #include <cstdio>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// typedef struct island{
// 	int x;
// 	int y;
// 	double z;
// }island;

// island land[1005];

// int cmp(island a,island b)
// {
// 	return a.z <= b.z;
// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	int n,d,num = 1;
// 	while(scanf("%d%d",&n,&d) && n && d)
// 	{
// 		int flag = 1,count = 1;
// 		for(int i = 0; i < n; i++)
// 		{
// 			scanf("%d%d",&land[i].x,&land[i].y);
// 			land[i].z = (double)land[i].x + sqrt(double(d*d - land[i].y*land[i].y));
// 			if(land[i].y > d)
// 				flag = -1;
// 		}
// 		if(flag == -1)
// 		{
// 			printf("Case %d: -1\n",num++);
// 			continue;
// 		}
// 		sort(land,land+n,cmp);
// 		double temp = land[0].z;
// 		for(int i = 1; i < n; i++)
// 			if(!((land[i].x-temp)*(land[i].x-temp)+land[i].y*land[i].y <= d*d))
// 			{
// 				temp = land[i].z;
// 				count++;
// 			}
// 		printf("Case %d: %d\n",num++,count);
// 	}
// 	return 0;
// }




#define LOCAL
#include <iostream>
#include <algorithm>
using namespace std;

int n,num[101],f[101][101],i,j,k;

int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	
	cin>>n;
	for(i = 1; i <= n; i++)
		cin>>num[i];
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			f[i][j] = 1000000;
		}
		f[i][i] = num[i];
		f[i][i+1] = 0;
	}

	for(i = n-2; i >= 1; i--)
		for(j = i+2; j <= n; j++)
			for(k = i+1; k <= j-1; k++)
				if(f[i][k]+f[k][j]*num[i]*num[j]*num[k] < f[i][j])
					f[i][j] = f[i][k] + f[k][j] + num[i]*num[k]*num[j];
	cout<<f[1][n]<<endl;
	return 0;
}




