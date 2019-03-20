/*
* @Author: Wang Yonghong
* @Date:   2016-02-11 19:48:05
* @Last Modified by:   mm
* @Last Modified time: 2016-03-29 10:01:40
*/

//001


// #include <stdio.h>
// #define COLS 4
// int sum2d(int ar[][COLS],int rows);
// int sum(int ar[],int n);
// int main(void)
// {
// 	int total1,total2,total3;
// 	int *pt1;
// 	int (*pt2)[COLS];

// 	pt1 = (int [2]){10,20};
// 	pt2 = (int [2][COLS]){{1,2,3,-9},{4,5,6,-8}};

// 	total1 = sum(pt1,2);
// 	total2 = sum2d(pt2,2);
// 	total3 = sum((int []){4,4,4,5,5,5},6);
// 	printf("total1 = %d\n",total1);
// 	printf("total2 = %d\n",total2);
// 	printf("total3 = %d\n",total3);

//     return 0;
// }

// int sum(int ar[],int n)
// {
// 	int i;
// 	int total = 0;
// 	for(i = 0; i < n; i++)
// 		total += ar[i];

// 	return total;
// }

// int sum2d(int ar[][COLS],int rows)
// {
// 	int r;
// 	int c;
// 	int tot = 0;

// 	for(r = 0; r < rows; r++)
// 		for(c = 0; c < COLS; c++)
// 			tot += ar[r][c];

// 	return tot;
// }



//002
//这是错误的

// #include <stdio.h>
// int main(void)
// {
// 	char a[] = {'1','2','3'};
// 	puts(a);
// 	return 0;
// }


//003

//命令行

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc,char *argv[])
// {
// 	int ch;
// 	FILE *fp;
// 	long count = 0;

// 	if(argc != 2)
// 	{
// 		printf("Usage : %s filename\n",argv[1]);
// 		exit(1);
// 	}
// 	if((fp = fopen(argv[1],"r")) == NULL)
// 	{
// 		printf("Can't open %s\n",argv[1]);
// 		exit(1);
// 	}
// 	while((ch = getc(fp)) != EOF)
// 	{
// 		putc(ch,stdout);
// 		count++;
// 	}
// 	printf("\n\n");
// 	fclose(fp);
// 	printf("File %s has %ld characters\n",argv[1],count);
// 	return 0;
// }


//004

// /* pe14-3.c */
// #include <stdio.h>
// #include <string.h>
// char * s_gets(char * st, int n);
// #define MAXTITL   40
// #define MAXAUTL   40
// #define MAXBKS   100            /* maximum number of books  */
// struct book {                   /* set up book template     */
//     char title[MAXTITL];
//     char author[MAXAUTL];
//     float value;
// };

// void sortt(struct book * pb[], int n);
// void sortv(struct book * pb[], int n);

// int main(void)
// {
//      struct book library[MAXBKS]; /* array of book structures */
//      struct book * pbk[MAXBKS];   /* pointers for sorting     */
//      int count = 0;
//      int index;

//      printf("Please enter the book title.\n");
//      printf("Press [enter] at the start of a line to stop.\n");
//      while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
//                          && library[count].title[0] != '\0')
//      {
//           printf("Now enter the author.\n");
//           s_gets(library[count].author, MAXAUTL);
//           printf("Now enter the value.\n");
//           scanf("%f", &library[count].value);
//           pbk[count] = &library[count];
//           count++;
//           while (getchar() != '\n')
//                continue;                /* clear input line */
//           if (count < MAXBKS)
//           printf("Enter the next title.\n");
//      }
//      printf("Here is the list of your books:\n");
//      for (index = 0; index < count; index++)
//          printf("%s by %s: $%.2f\n", library[index].title,
//           library[index].author, library[index].value);

//      printf("Here is the list of your books sorted by title:\n");
//      sortt(pbk, count);
//      for (index = 0; index < count; index++)
//          printf("%s by %s: $%.2f\n", pbk[index]->title,
//           pbk[index]->author, pbk[index]->value);
//      sortv(pbk, count);
//      printf("Here is the list of your books sorted by value:\n");
//      for (index = 0; index < count; index++)
//          printf("%s by %s: $%.2f\n", pbk[index]->title,
//           pbk[index]->author, pbk[index]->value);

//      return 0;
// }

// void sortt(struct book * pb[], int n)
// {
//    int top, search;
//    struct book * temp;

//    for (top = 0; top < n -1; top++)
//        for (search = top + 1; search < n; search++)
//             if (strcmp(pb[search]->title, pb[top]->title) < 0)
//             {
//                  temp = pb[search];
//                  pb[search] = pb[top];
//                  pb[top] = temp;
//             }
// }

// void sortv(struct book * pb[], int n)
// {
//    int top, search;
//    struct book * temp;

//    for (top = 0; top < n -1; top++)
//        for (search = top + 1; search < n; search++)
//             if (pb[search]->value < pb[top]->value)
//             {
//                  temp = pb[search];
//                  pb[search] = pb[top];
//                  pb[top] = temp;
//             }
// }

// char * s_gets(char * st, int n)
// {
//     char * ret_val;
//     char * find;

//     ret_val = fgets(st, n, stdin);
//     if (ret_val)
//     {
//         find = strchr(st, '\n');   // look for newline
//         if (find)                  // if the address is not NULL,
//             *find = '\0';          // place a null character there
//         else
//             while (getchar() != '\n')
//                 continue;          // dispose of rest of line
//     }
//     return ret_val;
// }


// #include <stdio.h>
// int main(void)
// {
//     int a,b,c,d;
//     while(~scanf("%d%d%d%d",&a,&b,&c,&d))
//     {
//         if(a == b && c != d)
//             printf("A\n");
//         else if(a != b && c == d)
//             printf("B\n");
//         else if(a == b && c == d)
//                 {
//                     if(a > c)
//                         printf("A\n");
//                     else if(a < c)
//                         printf("B\n");
//                     else
//                         printf("N\n");
//                 }
//         else
//         {
//             if((a+b)%10 > (c+d)%10)
//                 printf("A\n");
//             else if((a+b)%10 < (c+d)%10)
//                 printf("B\n");
//             else
//                 printf("N\n");
//         }       
//     }
// }


// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// int main(void)
// {
//     int i = 0;
//     char str[101];
//     gets(str);
//     while(str[i])
//     {
//         str[i] = toupper(str[i]);
//         i++;
//     }
//     puts(str);
//     return 0;
// }



// 高级数据表示 


// #include <stdio.h>
// #include <string.h>						// 提供strcpy()原型
// #include <stdlib.h>						// 提供malloc()原型
// #define TSIZE 45						// 存放片名的数组大小
// struct film{
// 	char title[TSIZE];
// 	int rating;
// 	struct film * next;					// 指向链表的下一个结构
// };

// int main(void)
// {
// 	struct film * head = NULL;
// 	struct film * prev,* current;
// 	char input[TSIZE];

// 	// 收集并存储信息
// 	puts("Enter first moive title :");
// 	while(gets(input) != NULL && input[0] != '\0' )
// 	{
// 		current = (struct film *)malloc(sizeof(struct film));
// 		if(head == NULL)	// 第一个结构
// 			head = current;
// 		else
// 			prev->next = current;
// 		current->next = NULL;
// 		strcpy(current->title,input);
// 		puts("Enter your rating <0-10> :");
// 		scanf("%d",&current->rating);
// 		while(getchar() != '\n')
// 			continue;
// 		puts("Enter next moive title (empty line to stop) :");
// 		prev = current;
// 	}

// 	// 给出电影列表
// 	if(head == NULL)
// 		printf("No data entered!");
// 	else
// 		printf("Here is the moive list :\n");
// 	current = head;
// 	while(current != NULL)
// 	{
// 		printf("Moive : %s Rating : %d\n",current->title,current->rating);
// 		current = current->next;
// 	}


// 	// 任务完成,释放所分配内存
// 	current = head;
// 	while(current != NULL)
// 	{
// 		free(current);
// 		current = current->next;
// 	}

// 	printf("Bye!\n");
// }



// #include <iostream>
// #include <cstdio>
// #include <cstring>

// using namespace std;

// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// #define MAXN 111

// int map[MAXN][MAXN];
// int d[2][MAXN][MAXN];

// int MaxSum(int m, int n)
// {
//     memset(d, 0, sizeof(d));
//     int i, j, k, x, y;
//     for (k = m+n-3; k > 0; k--)
//     {
//         for (i = 0, j = k; i < m-1; i++, j--)
//         {
//             if (j >= n)
//             {
//                 continue;
//             }
//             for (x = i+1, y = j-1; x < m; x++, y--)
//             {
//                 d[k%2][i][x] = map[i][j] + map[x][y];
//                 int r = (k+1) % 2;
//                 d[k%2][i][x] +=
//                     MAX(MAX(d[r][i][x], d[r][i][x+1]), MAX(d[r][i+1][x], d[r][i+1][x+1]));
//             }
//         }
//     }
//     return d[1][0][1];
// }

// int main(void)
// {
//         int m, n;
//        	cin>>m>>n;

//         memset(map, 0, sizeof(map));
//         int i, j;
//         for (i = 0; i < m; i++)
//         {
//             for (j = 0; j < n; j++)
//             {
//                 cin>>map[i][j];
//             }
//         }

//         cout<< MaxSum(m, n);

//     return 0;
// }

// #include<iostream>
// #include<cstdio>
// using namespace std;
// int main()
// {
// 	int a,b,c=1;
// 	cin >> a >> b;
// 	for (int i = 0; i < 100; i++)
// 	{
// 		if ((a * 100 + i) % b == 0)
// 		{
// 			if (c)
// 			{
// 				printf("%02d", i);
// 				c = 0;
// 			}
// 			else
// 			printf(" %02d", i);
// 		}
// 	}
// 	return 0;
// }



// #include<iostream>
// #include<cstring>
// using namespace std;
// int main()
// {
// 	int n,a,b,i,k,d;
// 	char c[1111];
// 	cin >> n;
// 	while (n--)
// 	{
// 		cin >> c;
// 		i = 0,a=0,b=0,k=0,d=0;
// 		k = strlen(c);
// 		for (int i = 0; i < k; ++i)
// 		{
// 			switch (c[i])
// 			{
// 			case '[':++a; break;
// 			case ']':--a; break;
// 			case '(':++b; break;
// 			default:--b; break;
// 			}
// 			if ((c[i] == '['&&c[i + 1] == ')') || (c[i] == '('&&c[i + 1] == ']')||a<0||b<0)
// 				{
// d = 1;
// break;
// }
// 		}
// 		if (a != 0 || b != 0 || d)
// 			cout << "NO" << endl;
// 		else
// 			cout << "YES" << endl;
// 	}
// 	return 0;
// }





// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// char str[1000];
// int main()
// {
//     int j,i,a=0,b=0,c=0,e=0;
//     gets(str);
//     j=strlen(str);
//     for(i=0;i<j;i++)
//     {
//         if(isdigit(str[i]))
//             a++;
//         else if(isalpha(str[i]))
//             b++;
//         else if(str[i]== 32)
//             c++;
//         else
//             e++;
//     }
//     printf("%d %d %d %d",b,a,c,e);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
// 	long long s,n,i,j,p;s=0;
// 	scanf("%I64d",&n);
// 	for(i=1;i <= n;i++)
//    	{   
//    		p=1;
//        	for(j=1;j <= i;j++)
//        		p *= j;
//      	s += p;
// 	}
//  	printf("%d\n",s);
// 	return 0;
// }



// #include <stdio.h>
// int main(void)
// {
// 	int a[10],i;
// 	for(i = 0; i < 10;i++)
// 		scanf("%d",&a[i]);
// 	while(i--)
// 	{
// 		printf("%d",a[i]);
// 		if(i)
// 			printf(" ");
// 	}
// 	return 0;
// }



// #include <stdio.h>
// #include <string.h>
// #define maxn 1010
// int a[maxn];
// int main(void)
// {
// 	int n,k,m;
// 	memset(a,0,sizeof(a));
// 	scanf("%d%d",&n,&k);
// 	for (int i = 1; i <= n; i++)
// 		for(int j = 1; j <= n; j++)
// 			if(j % i == 0) 
// 				a[j] = !a[j];
// 	for(int i = 1; i <= k; i++)
// 	{
// 		scanf("%d",&m);
// 		if(a[m])
// 			printf("yes\n");
// 		else
// 			printf("no\n");
// 	}
// 	return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #define maxn 1000010
// int a[maxn];
// int sum[maxn];
// int main(void)
// {
// 	int n,k,m1,m2;
// 	memset(a,0,sizeof(a));
// 	memset(sum,0,sizeof(sum));
// 	scanf("%d%d",&n,&k);
// 	for (int i = 1; i <= n; i++)
// 		for(int j = i; j <= n; j += i)
// 			a[j] = !a[j];
// 	for(int i = 1; i <= n; i++)
// 	{
// 		if(a[i])
// 			sum[i] = sum[i-1] + 1;
// 		else
// 			sum[i] = sum[i-1];
// 	}
// 	for(int i = 1; i <= k; i++)
// 	{
// 		scanf("%d%d",&m1,&m2);
// 		printf("%d\n",sum[m2]-sum[m1-1]);
// 	}
// 	return 0;
// }





// #include <stdio.h>
// #include <string.h>
// #define maxn 50010
// int a[maxn];
// int main(void)
// {
// 	int n,k,m1,m2,sum;
// 	char m;
// 	memset(a,0,sizeof(a));
// 	scanf("%d%d",&n,&k);
// 	while(getchar()!='\n')
// 			continue;
// 	for(int i = 1; i <= k; i++)
// 	{
// 		sum = 0;
// 		scanf("%c",&m);
// 		scanf("%d%d",&m1,&m2);
// 		while(getchar()!='\n')
// 			continue;		
// 		if(m == 79)
// 			for(int i = m1; i <= m2; i++)
// 				a[i] = !a[i];
// 		else
// 		{
// 			for(int i = m1; i <= m2; i++)
// 				if(a[i])
// 					sum++;
// 			printf("%d\n",sum);

// 		}

// 	}
// 	return 0;
// }


// #include <stdio.h>

// int f1[100],f2[100],num[100];
// int ans;

// int main(void)
// {
// 	int n;
// 	int i,j;
// 	scanf("%d",&n);
// 	for(i = 0; i < n; i++)
// 		scanf("%d",&num[i]);
// 	for(i = 0; i < n; i++)
// 	{
// 		f1[i] = 1;
// 		for(j = 0; j < i; j++)
// 			if(num[j] < num[i] && f1[i] < f1[j] +1)
// 				f1[i] = f1[j] + 1;
// 	}
// 	for(i = n - 1; i >= 0; i--)
// 	{
// 		f2[i] = 1;
// 		for(j = n -1; j > i; j--)
// 			if(num[j] < num[i] && f2[i] < f2[j] + 1)
// 				f2[i] = f2[j] + 1;
// 	}
// 	for(i = 0; i < n; i++)
// 		if(ans < f1[i] + f2[i] -1)
// 			ans = f1[i] + f2[i] -1;
// 	printf("%d\n",n-ans);
// 	return 0;
// }


// #include <stdio.h>
// #include <math.h>
// int main()
// {
// 	int t,n,f,i;
// 	double m;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 		scanf("%d",&n);
// 		m = 0;
// 		for(i = 2; i <= n; i++)
// 			m += log10(i);
// 		f = (int)m+1;
// 		printf("%d\n",f);
// 	}
// 	return 0;
// }

// 错误代码

// #include <stdio.h>
// int main()
// {
// 	int a,b;
// 	while(~scanf("%d%d",&a,&b))
// 	{
// 		if((a==11&&b<=9)||(a<=9&&b==11))
// 			printf("Game Over\n");
// 		else if(a==10&&b==10)
// 			printf("A\n");
// 		else if((a==10&&b==12)||(a==12&&b==10))
// 			printf("Game Over\n");
// 		else if((a+b)%4==0||(a+b)%4==1)
// 			printf("A\n");
// 		else
// 			printf("B\n");
// 	}
// 	return 0;
// }

// #include <stdio.h>
// #include <malloc.h>
// typedef struct polynode
// {
// 	int c;
// 	int e;
// 	struct polynode *next;
// } poly;
// poly *creatpoly()
// {
// 	poly *p,  *q,  *h;
// 	q = NULL, h = NULL;
// 	int c;
// 	int e;

// 	while (e!=-1)
// 	{
//     scanf("%d%d", &c, &e);          /*将scanf位置改变下*/
//     h = (poly*)malloc(sizeof(poly));
//     h->c = c;
//     h->e = e;
//     h->next = NULL;
//     if (q == NULL)
//       q = h;
//     else
//       p->next = h;
//     p = h;
//   }
//   return q;
// }

// poly *qiudao(poly *p)
// {
//   poly *s;
//   s = p;
//   while (p)
//   {
//     p->c = (p->c)*(p->e);
//     p->e = (p->e) - 1;
//     p = p->next;
//   }

//   return s;
// }

// void print(poly *p)
// {
//   int i = 0;
//   if (p->e ==  - 1)
//   {
//     printf("0");
//     i++;
//   }

//   {
//     while (p->next != NULL)
//     {
//       if (p->c != 0)
//       {
//         printf("%d %d ", p->c, p->e);
//         i++;
//       }
//       else
//         ;

//       p = p->next;
//     }
//     if (p->next == NULL)
//     {
//       if (p->c != 0 && p->e > -1)        /*加上约束条件p->e>-1*/
//       {
//         printf("%d %d ", p->c, p->e);
//         i++;
//       }
//       else
//         ;
//     }

//     if (i == 0)
//       printf("0");
//     printf("\n");
//   }
// }

// int main()
// {
//   poly *d,  *h;
//   d = creatpoly();
//   h = qiudao(d);
//   print(h);
//   getchar();
//   getchar();
//   return 0;
// }


// #include <stdio.h>
// int main()
// {
// 	char a[257]={0};
// 	int b[257]={0};
// 	int s,i,j;
// 	while(scanf("%s",a)!=EOF)
// 	{
// 		s=0;
// 		for(i=0;a[i]!='\0';i++)
// 		{
// 			if(a[i]=='C'||a[i]=='D'||a[i]=='E'||a[i]=='I')
// 			b[i]=-1;
// 			 if(a[i]>=112&&a[i]<=122)
// 			b[i]=1;
// 			if(a[i]=='N')
// 			b[i]=0;
// 			s+=b[i];
// 		}
// 		if(s==1)
// 		printf("YES");
// 		else
// 		printf("NO");
// 		printf("\n");
// 	}
// }


// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char s1[1000];
//     int c=0,i=0,t=0,j=0;
//     while(scanf("%s",s1),s1)
//     {
//         while(s1[i]!='\0')
//         {
//             c++;
//             i++;
//         }
//         while(s1[j]!='\0')
//         {
//             if(s1[j]==s1[c-j-1]) t=t;
//             else t++;
//             j++;
//         }
//         if(t==0) printf("YES\n");
//         else printf("NO\n");
//     }
// }




// #include<stdio.h>
// #include<string.h>
// int paixu(int a[],int n)//从小到大排序 
// {
// 	int i,j,t;
// 	for(i=1;i<n;i++)
// 	{
// 		for(j=0;j<n-i;j++)
// 		{
// 			if(a[j]>a[j+1])
// 			{
// 				t=a[j];
// 				a[j]=a[j+1];
// 				a[j+1]=t;
// 			}
// 		}
// 	}
// } 

// int main()
// {
// 	int n,a[10000],b[10000],i,j,m;
// 	scanf("%d",&n);
// 	for(i=0;i<n;i++)
// 	{
// 		scanf("%d",&a[i]);
// 	}
// 	paixu(a,n);
// 	for(i=0;i<n;i++)//计算每次搬运花费体力 
// 	{	
// 		b[i]=a[n-1]+a[n-2];
// 		n=n-1;
// 		paixu(a,n);
// 	}
// 	for(m=0,j=0;j<n;j++)//体力的和 
// 	{
// 		m=m+b[j];
// 	}
// 	printf("%d",m);
// }

// #include <stdio.h>
// #define N 100
// int count[N];
// int main()
// {
//     int kind,i;
//     double sum=0;
//     void compare(int m);
//     scanf("%d",&kind);
//     for(i=0;i<kind;i++)
//         scanf("%d",&count[i]);
//     for(i=0;i<kind-1;i++)
//     {
//         compare(kind);
//         sum+=count[0]+count[1];
//         count[0]=sum;
//         count[1]=count[kind-1]+1;
         
//     }
//     printf("%lf",sum);
//     return 0;
// }
// void compare(int m)
// {
//     int i,j;
//     for(i=0;i<m-1;i++)
//         for(j=i;j<m-i-1;j++)
//             if(count[j]>count[j+1])
//             {
//                 count[j]=count[j]+count[j+1];
//                 count[j+1]=count[j]-count[j+1];
//                 count[j]=count[j]-count[j+1];
//             }
// }



// #include <stdio.h>

// int main(void)
// {
// 	int n,sum;
// 	scanf("%d",&n);
// 	for (int i = 1; i < n; i++)
// 	{
// 		sum = 0;
// 		for (int j = 1; j <= i/2; j++)
// 			if(i%j == 0)
// 				sum += j;
// 		if(sum == i)
// 		{
// 			printf("%d its factors are ",i);
// 			for (int k = 1; k <= i/2; k++)
// 			{
// 				if(i%k == 0)
// 					printf("%d ",k);
// 			}
// 			printf("\n");
// 		}
// 	}
// 	return 0;
// }



// #include <stdio.h>
// int main ()
// {
// 	double PI=3.14;
// 	float r,h,C1,Sa,Sb,Va,Vb;
// 	scanf("%lf%lf",&r,&h);
// 	C1=2*PI*r;
// 	Sa=PI*r*r;
// 	Sb=4*PI*r*r;
// 	Va=4.0/3*PI*r*r*r;
// 	Vb=PI*r*r*h;
// 	printf("C1=%.2f\nSa=%.2f\nSb=%.2f\nVa=%.2f\nVb=%.2f\n",C1,Sa,Sb,Va,Vb);
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0

// typedef int Status;

// typedef int Elemtype;

// typedef struct Node{
// 	Elemtype cof;
// 	Elemtype inx;
// 	struct Node *next;
// }Node, *Linklist;

// Status visit(Elemtype a, Elemtype b)
// {
// 	printf("%d %d", a, b);
// 	return OK;
// }

// Status InitList(Linklist *L)
// {
// 	(*L) = (Linklist)malloc (sizeof(Node));
// 	if(!(*L))
// 		return ERROR;
// 	(*L)->next = NULL;
// 	return OK;
// }

// int ListLength(Linklist L)
// {
// 	int i;
// 	Linklist p;
// 	p = L->next;
// 	i = 0;
// 	while(p){
// 		i++;
// 		p = p->next;
// 	}
// 	return i;
// }

// Status GetElem(Linklist L, int i, Elemtype *cof, Elemtype *inx)
// {
// 	Linklist p;
// 	int j;
// 	p = L;
// 	j = 1;
// 	while(p && j < i){
// 		p = p->next;
// 		j++;
// 	}
// 	if(!p || j > i){
// 		return ERROR;
// 	}
// 	*cof = p->next->cof;
// 	*inx = p->next->inx;
// 	return OK;
// }

// int ElemLocate(Linklist L, Elemtype cof, Elemtype inx)
// {
// 	Linklist p;
// 	int i;
// 	i = 1;
// 	p = L->next;
// 	while(p && (p->cof != cof || p->inx != inx)){
// 		p = p->next;
// 		i++;
// 	}
// 	if(i <= ListLength(L))
// 		return i;
// 	else
// 		return 0;
// }

// Status ListInsert(Linklist *L, int i, Elemtype cof, Elemtype inx)
// {
// 	if(i < 1 || i > ListLength(*L) + 1)
// 		return ERROR;
// 	int j;
// 	Linklist p, q;
// 	q = (Linklist)malloc (sizeof(Node));
// 	p = *L;
// 	j = 1;
// 	while(p && j < i){
// 		p = p->next;
// 		++j;
// 	}
// 	if(!p || j > i)
// 		return ERROR;
// 	q->next = p->next;
// 	p->next = q;
// 	q->cof = cof;
// 	q->inx = inx;
// 	return OK;
// }

// Status ListDelete(Linklist *L, int i, Elemtype *cof, Elemtype *inx)
// {
// 	int j;
// 	Linklist p, q;
// 	p = *L;
// 	j = 1;
// 	while(p && j < i){
// 		p = p->next;
// 		++j;
// 	}
// 	if(!p || j > i)
// 		return ERROR;
// 	q = p->next;
// 	p->next = p->next->next;
// 	free(q);
// 	return OK;
// }

// Status ClearList(Linklist *L)
// {
// 	Linklist p, q;
// 	p = (*L)->next;
// 	while(p){
// 		q = p;
// 		p = p->next;
// 		free(q);
// 	}
// 	(*L)->next = NULL;
// 	return OK;
// }

// Status ListEmpty(Linklist L)
// {
// 	if(L->next == NULL)
// 		return TRUE;
// 	return FALSE;
// }

// Status ListTraverse(Linklist L)
// {
// 	Linklist p;
// 	int juge;
// 	juge = 0;
// 	p = L->next;
// 	while(p){
// 		juge = p->cof;
// 		if(juge)
// 			break;
// 		p = p->next;
// 	}
// 	if(!juge){
// 		printf("0\n");
// 		return OK;
// 	}
// 	p = L->next;
// 	while(p && p->next != NULL){
// 		if(p->cof != 0){
// 			visit(p->cof, p->inx);
// 			printf(" ");
// 		}
// 		p = p->next;
// 	}
// 	visit(p->cof, p->inx);
// 	printf("\n");
// 	return OK;
// }

// Status PopList(Linklist *L)
// {
// 	Linklist p, q;
// 	Elemtype temp;
// 	for(p = (*L)->next; p != NULL; p = p->next){
// 		for(q = p->next; q != NULL; q = q->next){
// 			if(p->inx < q->inx){
// 				temp = p->inx;
// 				p->inx = q->inx;
// 				q->inx = temp;
// 				temp = p->cof;
// 				p->cof = q->cof;
// 				q->cof = temp;
// 			}
// 		}
// 	}
// 	return OK;
// }

// Status FinalList(Linklist *L)
// {
// 	Linklist p, q;
// 	//q = (Linklist *)malloc (sizeof(Node));
// 	p = (*L)->next;
// 	while(p){
// 		if(p->next != NULL && p->next->inx == p->inx){
// 			p->cof += p->next->cof;
// 			q = p->next;
// 			p->next = p->next->next;
// 			free(q);
// 			continue;
// 		}
// 		p = p->next;
// 	}
// 	return OK;
// }


// Status MulList(Linklist *L3, Linklist L1, Linklist L2)
// {
// 	int i;//L1循环
// 	int j;//L2循环
// 	int k;//L3循环
// 	Elemtype cof1, inx1;
// 	Elemtype cof2, inx2;
// 	Elemtype cof3, inx3;
// 	//int *num;
// 	k = 1;
// 	for(i = 1; i <= ListLength(L1); i++){
// 		for(j = 1; j <= ListLength(L2); j++){
// 			GetElem(L1, i, &cof1, &inx1);
// 			GetElem(L2, j, &cof2, &inx2);
// 			cof3 = cof1 * cof2;
// 			inx3 = inx1 + inx2;
// 			ListInsert(L3, k++, cof3, inx3);
// 		}
// 	}
// 	PopList(L3);
// 	return OK;
// }

// int main()
// {
// 	Linklist L1, L2, L3;
// 	int cofn, inxn;//输入的系数和指数
// 	int i;//循环
// 	InitList(&L1);
// 	InitList(&L2);
// 	InitList(&L3);
// 	i = 1;
// 	while(scanf("%d%d", &cofn, &inxn), inxn != -1 && cofn != -1){
// 		ListInsert(&L1, i++, cofn, inxn);
// 	}
// 	i = 1;
// 	while(scanf("%d%d", &cofn, &inxn), cofn != -1){
// 		ListInsert(&L2, i++, cofn, inxn);
// 	}
// 	MulList(&L3, L1, L2);
// 	FinalList(&L3);
// 	ListTraverse(L3);
// 	return 0;
// }


// #include <stdio.h>

// #define N 1000

// int ap[N];
// int ae[N];
// int bp[N];
// int be[N];

// int main() {
//     int i = 0, j = 0;
//     int alen, blen;
//     while (scanf("%d%d", &ap[i], &ae[i]), ap[i] >= 0 && ae[i] >= 0) {
//         i++;
//     }
//     while (scanf("%d%d", &bp[j], &be[j]), bp[j] >= 0 && be[j] >= 0) {
//         j++;
//     }
//     alen = i, blen = j;
//     i = j = 0;
//     while (i < alen && j < blen) {
//         if (ae[i] > be[j]) {
//             printf("%d %d ", ap[i], ae[i]);
//             i++;
//         } else if (ae[i] < be[j]) {
//             printf("%d %d ", bp[j], be[j]);
//             j++;
//         } else {
//             printf("%d %d ", bp[j]+ap[i], be[j]);
//             i++; j++;
//         }
//     }
//     while (i < alen) {
//         printf("%d %d ", ap[i], ae[i]);
//         i++;
//     }
//     while (j < blen) {
//         printf("%d %d ", bp[j], be[j]);
//         j++;
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char str[1000];
//     int i,n,len,k,flag=0;
//     scanf("%d",&n);
//     for(k=0;k<n;k++)
//     {
// 	    flag = 0;
// 	    scanf("%s",str);
// 	    len=strlen(str);
// 	    for(i=0;i<len/2;i++)
// 	    {
// 	        if(str[i]!=str[len-1])
// 	        {
// 	            flag=1;
// 	            break;
// 	        }
// 	    }
// 	    if(flag==1)
// 	        printf("NO\n");
// 	    else
// 	        printf("YES\n");
//     }
// }




// #include <stdio.h>
// int flag;
// void check(char str[],int len){
//     if (len ==0) {
//         return ;
//     } else {
//         if(str[len-1] >= 'p' && str[len-1] <= 'z'){
//             flag++;
//             if (flag > 3) {
//                 return ;
//             }
//             check(str, --len);
//         } else if(str[len-1] == 'N'){
//             check(str, --len);
//         } else if(str[len-1] == 'C' || str[len-1] == 'D' || str[len-1] == 'E' || str[len-1] == 'I'){
//             flag--;
//             if (flag <= 0) {
//                 return ;
//             }
//             check(str, --len);
//         } else {
//             return ;
//         }
//     }
// }


// int main() {
//     char str[1000];
//     while (scanf("%s",str) != EOF) {
//         flag = 0;
//         check(str, strlen(str));
//         if(flag == 1){
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }
//     }
//     return 0;
// }





































































































































































































































