//001

// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
// 	const double pi = acos(-1.0);
// 	double r,h,s1,s2,s;
// 	scanf("%lf%lf",&r,&h);
// 	s1 = pi*r*r;
// 	s2 = 2*pi*r*h;
// 	s = s1*2 + s2;
// 	printf("Area = %.3f\n",s);
// 	return 0;
// }



//002

// #include <stdio.h>
// int main(void)
// {
// 	int n,m;
// 	scanf("%d",&n);
// 	m = (n%10)*100 + (n/10%10)*10 + (n/100);
// 	printf("%03d\n",m);
// 	return 0;
// }



//003

// #include <stdio.h>
// int main(void)
// {
// 	//001

// 	// int a,b,t;
// 	// scanf("%d%d",&a,&b);
// 	// t = a;
// 	// a = b;
// 	// b = t;

// 	//002

// 	// int a,b;
// 	// scanf("%d%d",&a,&b);
// 	// a = a + b;
// 	// b = a - b;
// 	// a = a - b;

// 	//003
// 	// int a,b;
// 	// scanf("%d%d",&a,&b);
// 	// a^=b^=a^=b;

// 	//004
// 	// int a,b;
// 	// scanf("%d%d",&a,&b);
// 	// printf("%d %d",b,a);


// 	printf("%d %d\n",a,b);
// 	return 0;
// }



//004

// #include <stdio.h>
// int main(void)
// {
// 	int a,b,m,n;
// 	scanf("%d%d",&n,&m);
// 	a = (4*n-m)/2;
// 	b = n - a;
// 	if(m%2 == 1 || a<0 || b<0)
// 		printf("No answer\n");
// 	else
// 		printf("%d %d\n",a,b);
// 	return 0;
// }



//005

// #include <stdio.h>
// int main(void)
// {
// 	// 001
// 	// int a,b,c;
// 	// scanf("%d%d%d",&a,&b,&c);
// 	// if(a <= b && b <= c) printf("%d %d %d\n",a,b,c);
// 	// else if(a <= c && c <= b) printf("%d %d %d\n",a,c,b);
// 	// else if(b <= a && a <= c) printf("%d %d %d\n",b,a,c);
// 	// else if(b <= c && c <= a) printf("%d %d %d\n",b,c,a);
// 	// else if(c <= a && a <= b) printf("%d %d %d\n",c,a,b);
// 	// else printf("%d %d %d\n",c,b,a);

// 	// 002
// 	// int a,b,c,t;
// 	// scanf("%d%d%d",&a,&b,&c);
// 	// if(a>b) {t = a; a = b; b =t;}
// 	// if(a>c) {t = a; a = c; c =t;}
// 	// if(b>c) {t = b; b = c; c =t;}
// 	// printf("%d %d %d\n",a,b,c);


// 	return 0;
// }



//006

// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
// 	printf("%d\n",11111*11111);
// 	printf("%ld\n",11111*11111);
// 	printf("%lld\n",11111*11111);

// 	printf("%d\n",111111*111111);
// 	printf("%ld\n",111111*111111);
// 	printf("%lld\n",111111*111111);

// 	printf("%d\n",111111111*111111111);
// 	printf("%ld\n",111111111*111111111);
// 	printf("%lld\n",111111111*111111111);

// 	printf("%f\n",11111.*11111);
// 	printf("%lf\n",11111.*11111);
// 	printf("%llf\n",11111.*11111);

// 	printf("%f\n",111111.*111111);
// 	printf("%lf\n",111111.*111111);
// 	printf("%llf\n",111111.*111111);

// 	printf("%f\n",111111111.*111111111);
// 	printf("%lf\n",111111111.*111111111);
// 	printf("%llf\n",111111111.*111111111);


// 	printf("%f\n",sqrt(-10));
// 	printf("%lf\n",sqrt(-10));
// 	printf("%llf\n",sqrt(-10));
// 	printf("%d\n",sqrt(-10));

// 	printf("%f\n",1.0/0.0);
// 	printf("%f\n",0.0/0.0);
// 	// printf("%f\n",1/0);
// 	// printf("%d\n",1/0);


// 	return 0;
// }



//007

// #include <stdio.h>
// int main(void)
// {
// 	double f,c;
// 	scanf("%lf",&f);
// 	c = 5*(f-32)/9;
// 	printf("%.3f\n",c);
// 	return 0;
// }



//008
//7744问题

// 开根号法
// #include <stdio.h>
// int main(void)
// {
// 	for (int a = 1; a <= 9; a++)
// 		for (int b = 0; b <= 9; b++)
// 		{
// 			int n = a*1100 + b*11;
// 			int m = floor(sqrt(n)+0.5);
// 			if(m*m == n)
// 				printf("%d\n",n);
// 		}
// 	return 0;
// }

// 枚举法
// #include <stdio.h>
// int main(void)
// {
// 	for(int x=1;;x++)               //从32开始最好了,这样就不用continue
// 	{
// 		int n =x*x;
// 		if(n < 1000) continue;      //continue可以用来偷懒... ...
// 		if(n > 9999) break;			//break也是用来偷懒的... ...
// 		int hi = n / 100;
// 		int lo = n % 100;
// 		if(hi/10 == hi%10 && lo/10 == lo%10)
// 			printf("%d\n",n);
// 	}
// 	return 0;
// }



//009
// #include <stdio.h>
// int main(void)
// {
// 	long long int n,count = 0;             //n<10^9
// 	scanf("%I64d",&n);              //%lld  Windows平台下 %I64d
// 	while(n > 1)
// 	{
// 		if(n % 2 == 1)
// 			n = n*3 + 1;         //小心乘法溢出
// 		else
// 			n /= 2;
// 		count++;
// 	}
// 	printf("%d\n",count);
// 	return 0;
// }

// #include <stdio.h>
// int main(void)
// {
// 	int n1,count = 0;
// 	scanf("%d",&n1);
// 	long long n = n1;  //巧妙避免
// 	while(n > 1)
// 	{
// 		if(n % 2 == 1)
// 			n = n*3 + 1;
// 		else
// 			n /= 2;
// 		count++;
// 	}
// 	printf("%d\n",count);
// 	return 0;
// }



//010

// #include <stdio.h>
// int main(void)
// {
// 	double sum = 0;

// 	// for(int i =0;;i++)
// 	// {
// 	// 	double term = 1.0 / (i*2+1);
// 	// 	if(i%2 == 0)
// 	// 		sum += term;
// 	// 	else
// 	// 		sum -= term;
// 	// 	if(term< 1e-6)
// 	// 		break;
// 	// }

// 	// int i = 0;
// 	// double term;
// 	// do{
// 	// 	term = 1.0 /(i*2+1);
// 	// 	if(i%2 == 0)
// 	// 		sum += term;
// 	// 	else
// 	// 		sum -= term;
// 	// 	i++;
// 	// }while(term >= 1e-6);


// 	printf("%.6f\n",sum);
// 	return 0;
// }



//011

// #define LOCAL

// #include <stdio.h>
// int main(void)
// {
// 	#ifdef LOCAL
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif
// 	const int number = 10;         //数组大小
// 	int x;
// 	int count[number];
// 	int i;

// 	for (i = 0; i < 10; i++)
// 		count[i]=0;


// 	while(~scanf("%d",&x))
// 	{
// 		if(x >= 0 && x <= 9)
// 			count[x]++;
// 	}

// 	for (i = 0; i < 10; i++)
// 		printf("%d : %d\n",i,count[i]);

// 	return 0;

// }




//012

// #include <stdio.h>
// #include <time.h>
// int main(void)
// {
// 	const int MOD = 1000000;
// 	int n,S = 0;
// 	scanf("%d",&n);
// 	if(n>25)
// 		n=25;
// 	for(int i = 1;i <= n;i++)
// 	{
// 		int factorial = 1;
// 		for (int j = 1; j < i; j++)
// 			factorial = (factorial * j % MOD);
// 		S = (S +factorial ) % MOD;
// 	}
// 	printf("%d\n",S);
// 	printf("Time used = %.2f\n",(double)clock() / CLOCKS_PER_SEC);
// 	return 0;
// }




//013
// #define LOCAL

// #define INF 1000000000
// #include <stdio.h>
// int main(void)
// {
// 	#ifdef LOCAL
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif

// 	int x,n = 0,kase = 0;
// 	while(scanf("%d",&n) == 1 && n )
// 	{
// 		int s = 0,min = INF,max = -INF;
// 		for(int i = 0;i < n ;i++)
// 		{
// 			scanf("%d",&x);
// 			s += x;
// 			if(x < min) min = x;
// 			if(x > max) max = x;
// 		}
// 		if(kase) printf("\n");
// 		printf("Case %d: %d %d %.3f\n",++kase,min,max,(double)s/n);
// 	}
// 	return 0;
// }


//014

// #define INF 1000000000
// #include <stdio.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");                //二进制不受换行符影响(不是很懂)

// 	// fin = stdin;
// 	// fout = stdout;
// 	int x,n = 0,kase = 0;
// 	while(fscanf(fin,"%d",&n) == 1 && n )
// 	{
// 		int s = 0,min = INF,max = -INF;
// 		for(int i = 0;i < n ;i++)
// 		{
// 			fscanf(fin,"%d",&x);
// 			s += x;
// 			if(x < min) min = x;
// 			if(x > max) max = x;
// 		}
// 		if(kase) fprintf(fout,"\n");             	//以二进制形式不能写入文件
// 		fprintf(fout,"Case %d: %d %d %.3f\n",++kase,min,max,(double)s/n);
// 	}
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }




//015
//水仙花数

//3位
// #include <stdio.h>
// int main(void)
// {
// 	int a,b,c,d,S;
// 	for(a = 1;a < 10;a++)
// 		for(b = 0;b < 10;b++)
// 			for(c = 0;c < 10;c++)
// 			{
// 				S = a*100 + b*10 + c;
// 				if(S == a*a*a + b*b*b + c*c*c)
// 					printf("%d%d%d\n",a,b,c);
// 			}
// 	return 0;
// }


//4位

// #include <stdio.h>
// int main(void)
// {
// 	int a,b,c,d,S=0;
// 	for(a = 1;a < 10;a++)
// 		for(b = 0;b < 10;b++)
// 			for(c = 0;c < 10;c++)
// 				for(d = 0;d < 10;d++)
// 				{
// 					S = a*1000 + b*100 + c*10 + d;
// 					if(S == a*a*a*a + b*b*b*b + c*c*c*c + d*d*d*d)
// 						printf("%d%d%d%d\n",a,b,c,d);
// 				}
// 	return 0;
// }




//016


// #include <stdio.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");
// 	int n,a,b,c,kase=0;
// 	while(~fscanf(fin,"%d%d%d",&a,&b,&c))
// 	{
// 		n = 0;
// 		fprintf(fout,"Case %d: ",++kase);
// 		for(int i = 10;i <= 100;i++)
// 		if(i%3 == a && i%5 == b && i%7 == c)
// 		{
// 			fprintf(fout,"%d\n",i);
// 			n++;
// 		}
// 		if(n == 0)
// 			fprintf(fout,"No answer");
// 	}
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }



//017

// #include <stdio.h>
// int main(void)
// {
// 	int n;
// 	scanf("%d",&n);
// 	for(int i = n;i > 0;i--)
// 	{
// 		for(int j = n;j > i;j--)
// 			printf(" ");
// 		for(int j = 0;j < i;j++)
// 			printf("#");
// 		for(int j = i;j > 1;j--)
// 			printf("#");
// 		printf("\n");
// 	}
// 	return 0;
// }


//018

// #include <stdio.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");
// 	long long int n,m;                                  //溢出问题
// 	while(~fscanf(fin,"%I64d%I64d",&n,&m))
// 	{
// 		double sum = 0;
// 		if(n == 0 && m == 0)
// 			break;
// 		for(;n<=m;n++)
// 			sum += 1.0/(n*n);
// 		fprintf(fout,"%.5f\n",sum);
// 	}
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }


//019

// #include <stdio.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");
// 	int a,b,c;
// 	while(~fscanf(fin,"%d%d%d",&a,&b,&c))
// 	{
// 		if(a == 0 && b == 0 && c == 0)
// 			break;
// 		int m = a%b;
// 		fprintf(fout,"%d.",a/b);
// 		for(int i = 0;i < c;i++)
// 		{
// 			m *= 10;
// 			fprintf(fout,"%d",m/b);
// 			m = m%b;                               //这样就有了bug,不是按照四舍五入计算的
// 		}
// 	}

// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }



//020 C++编译通过

// #include <stdio.h>

// void result(int num, int &result_add, int &result_mul)
// {
//     int i, j, k;

//     i = num / 100;        //百位
//     j = num / 10 % 10;    //十位
//     k = num % 10;         //个位

//     result_add += i + j + k;    //分解出来的位数相加
//     result_mul *= i * j * k;    //相乘
// }


// int main()
// {
//     int i, j, k;
//     int result_add, result_mul;

//     for(i = 123; i <=329; i++)
//     {
//         j = i * 2;
//         k = i * 3;

//         result_add = 0;
//         result_mul = 1;

//         result(i, result_add, result_mul);
//         result(j, result_add, result_mul);
//         result(k, result_add, result_mul);
        
//         if(result_add == 45 && result_mul == 362880)
//             printf("%d %d %d\n", i, j, k);
//     }
//     return 0;
// }




//021

// #include <stdio.h>
// int main(void)
// {
// 	float i;
// 	for(i = 0;i != 10 ;i += 0.1)
// 		printf("%.1f\n",i);
// 	return 0;
// }


//022
//OJ1001

// #include <stdio.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");	
// 	int N,M,K;
// 	float P,S,SK;
// 	while(~fscanf(fin,"%d%d%d%f",&N,&M,&K,&P))
// 	{
// 		S = 0;
// 		if(M < K)
// 		{
// 			fprintf(fout,"%.2f\n",1.00);
// 			continue;
// 		}
// 		for(;K > 0;K--)
// 		{
// 			SK = 1;
// 			for(int i = 1;i <= M;i++)
// 				SK *= i;
// 			for(int i = 1;i <= K - 1;i++)
// 				SK /= i;
// 			for(int i = 1;i <= M-K+1;i++)
// 				SK /= i;
// 			for(int i = 1;i <= K - 1;i++)
// 				SK *= (1 - P);
// 			for(int i = 1;i <= M-K+1;i++)
// 				SK *= P;
// 			S += SK;
// 		}
// 		fprintf(fout,"%.2f\n",S);
// 	}
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }




//023

// #include <stdio.h>
// int main(void)
// {
// 	int N,M,K;
// 	float P,S,SK;
// 	while(~scanf("%d%d%d%f",&N,&M,&K,&P))
// 	{
// 		S = 0;
// 		if(M < K)
// 		{
// 			printf("%.2f\n",1.00);
// 			continue;
// 		}
// 		for(;K > 0;K--)
// 		{
// 			SK = 1;
// 			for(int i = 1;i <= M;i++)
// 				SK *= i;
// 			for(int i = 1;i <= K - 1;i++)
// 				SK /= i;
// 			for(int i = 1;i <= M-K+1;i++)
// 				SK /= i;
// 			for(int i = 1;i <= K - 1;i++)
// 				SK *= (1 - P);
// 			for(int i = 1;i <= M-K+1;i++)
// 				SK *= P;
// 			S += SK;
// 		}
// 		printf("%.2f\n",S);
// 	}
// 	return 0;
// }


//024

// #include <stdio.h>
// int main(void)
// {
// 	int n,m,i = 0;
// 	scanf("%d",&n);
// 	while(i < n)
// 	{
// 		scanf("%d",&m);
// 		for(int j = 1;j < m;j += 2)
// 			printf("%d ",j);
// 		printf("\n");
// 		for(int j = 2;j <= m;j += 2)
// 			printf("%d ",j);
// 		printf("\n");	
// 		i++;
// 	}
// 	return 0;
// }

//025

// #include <stdio.h>
// int main(void)
// {
// 	int n,sum;
// 	while(~scanf("%d",&n))
// 	{
// 		sum = 0;
// 		if(n>0)
// 			for(int i = 1;i <= n;i++)
// 				sum += i;
// 		else
// 			for(int i = 1;i >= n;i--)
// 				sum += i;
// 		printf("%d\n",sum);
// 	}
// 	return 0;
// }




//026


// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
// 	int x1,y1,x2,y2,x3,y3;
// 	double a,b,c,p,s;
// 	while(~scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
// 	{
// 		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
// 			break;
// 		a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
// 		b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
// 		c = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
// 		p = (a+b+c)/2.0;
// 		s = sqrt(p*(p-a)*(p-b)*(p-c));
// 		printf("%.1f\n",s);
// 	}
// 	return 0;
// }



// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");		
// 	int x1,y1,x2,y2,x3,y3;
// 	double a,b,c,p,s;
// 	while(~fscanf(fin,"%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
// 	{
// 		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
// 			break;
// 		a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
// 		b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
// 		c = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
// 		p = (a+b+c)/2.0;
// 		s = sqrt(p*(p-a)*(p-b)*(p-c));
// 		fprintf(fout,"%.1f\n",s);
// 	}
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }


//027

// #include <stdio.h>
// int main(void)
// {
// 	int e,s;
// 	while(~scanf("%d%d",&e,&s))
// 	{
// 		printf("%d\n",(s-e)>0?(s-e):0);
// 	}
// 	return 0;
// }



//028



// #include <stdio.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");		

// 	int n,Y = 0,L = 0,T = 0;
// 	char a[4];
// 	fscanf(fin,"%d",&n);
// 	while(n--)
// 	{
// 		fscanf(fin,"%3s",a);
// 		if(a[0] == 'Y')
// 			Y++;
// 		if(a[0] == 'L') 
// 			L++;
// 		if(a[0] == 'T') 
// 			T++;
// 	}
// 	fprintf(fout,"%d %d %d\n",Y,L,T);
// 	fclose(fin);
// 	fclose(fout);	

// 	return 0;
// }




// #include <stdio.h>
// int main(void)
// {
// 	int n,Y = 0,L = 0,T = 0;
// 	char a[4];
// 	scanf("%d",&n);
// 	while(n--)
// 	{
// 		scanf("%3s",a);
// 		if(*a == 'Y')
// 			Y++;
// 		if(*a == 'L') 
// 			L++;
// 		if(*a == 'T') 
// 			T++;
// 	}
// 	printf("%d %d %d\n",Y,L,T);
// 	return 0;
// }




//029


// #include <stdio.h>
// int main(void)
// {
// 	int a,b,c;
// 	scanf("%d%d%d",&a,&b,&c);
// 	printf("%.*f",c,(float)a/b);
// 	return 0;
// }




//030

// #include <stdio.h>
// int main(void)
// {
// 	int c,q = 1;
// 	while((c = getchar()) != EOF)
// 	{
// 		if(c == '"')
// 		{
// 			printf("%s",q?"``" :"''");
// 			q = !q;
// 		}
// 		else
// 			printf("%c",c);
// 	}
// 	return 0;
// }




//031


// #include <stdio.h>
// int main(void)
// {
// 	int h1,h2,m1,m2,n;
// 	scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);
// 	printf("%d\n",(h2-h1)*60 + (m2-m1) + n*20);
// 	return 0;
// }


//032

// #include <stdio.h>
// #include <string.h>
// #define maxn 1010                   //定义稍大的数组
// int a[maxn];						//大数组定义在函数外
// int main(void)
// {
// 	int n,k;
// 	while(~scanf("%d%d",&n,&k))
// 	{
// 		memset(a,0,sizeof(a));          //数组清零
	
// 		for (int i = 1; i <= k; i++)
// 			for (int j = 1; j <= n; j++)
// 				if(j%i == 0)
// 					a[j] = !a[j];
// 		for (int i = 1; i <= n; i++)
// 			if(a[i])
// 				printf("%d ",i);
// 		printf("\n");
// 	}

// 	return 0;
// }



//033
//蛇形填数

// #include <stdio.h>
// #include <string.h>
// #define maxn 20
// int a[maxn][maxn];
// int main(void)
// {
// 	int n,x,y,tot = 0;
// 	scanf("%d",&n);
// 	memset(a,0,sizeof(a));
// 	tot = a[x = 0][y = n-1] = 1;
// 	while(tot < n*n)
// 	{
// 		while(x+1 < n && !a[x+1][y])
// 			a[++x][y] = ++tot;
// 		while(y-1 >= 0 && !a[x][y-1])
// 			a[x][--y] = ++tot;
// 		while(x-1 >= 0 && !a[x-1][y])
// 			a[--x][y] = ++tot;
// 		while(y+1 < n && !a[x][y+1])
// 			a[x][++y] = ++tot;								
// 	}
// 	for(x = 0; x < n;x++)
// 	{
// 		for(y = 0; y < n;y++)
// 			printf("%4d",a[x][y]);
// 		printf("\n");
// 	}
// 	return 0;
// }



//034 


// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// const char* rev = "A   3  HIL JM O   2TUVWXYS1SE  Z  8 ";
// const char* msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

// char r(char ch)
// {
// 	if(isalpha(ch)) rev[ch - 'A'];
// 	return rev[ch - '0' + 25];
// }


//035


// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");
// 	char s[30];
// 	while(~fscanf(fin,"%s",s))
// 	{
// 		int len = strlen(s);
// 		int p = 1,m = 1;
// 		for(int i = 0; i < (len+1)/2; i++)
// 		{
// 			if(s[i] != s[len-1-i]) p = 0;
// 			if(r(s[i]) != s[len-1-i]) m = 0;
// 		}
// 		fprintf(fout,"%s -- is %s.\n\n",s,msg[m*2+p]);
// 	}
// 	fclose(fin);
//  fclose(fout);
// 	return 0;
// }


//036


// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");
// 	char s[1001];
// 	int n,i=0;
// 	fscanf(fin,"%d",&n);
// 	while(i++ < n)
// 	{
// 		fscanf(fin,"%s",s);
// 		int flag = 1;
// 		int len = strlen(s);
// 		for(int i = 0; i < (len+1)/2; i++)
// 			if(s[i] != s[len-1-i]) flag = 0;
// 		if(flag)
// 			fprintf(fout,"YES\n");
// 		else
// 			fprintf(fout,"NO\n");
// 	}
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }



// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	FILE *fin,*fout;
// 	fin = stdin;
// 	fout = stdout;
// 	char s[1001];
// 	int n,i=0;
// 	fscanf(fin,"%d",&n);
// 	while(i++ < n)
// 	{
// 		fscanf(fin,"%s",s);
// 		int flag = 1;
// 		int len = strlen(s);
// 		for(int i = 0; i < (len+1)/2; i++)
// 			if(s[i] != s[len-1-i]) flag = 0;
// 		if(flag)
// 			fprintf(fout,"YES\n");
// 		else
// 			fprintf(fout,"NO\n");
// 	}
// 	// fclose(fin);
// 	// fclose(fout);
// 	return 0;
// }



//037

// #include <stdio.h>
// int a[100];
// int main(void)
// {
	// FILE *fin,*fout;
	// fin = fopen("input.txt","r");
	// fout = fopen("output.txt","w");
// 	fin = stdin;
// 	fout = stdout;
// 	int n,i = 0;
// 	fscanf(fin,"%d",&n);
// 	while(i++ < n)
// 	{
// 		int m,j = 0,sum = 0;
// 		fscanf(fin,"%d",&m);
// 		while(j < m)
// 			fscanf(fin,"%d",&a[j++]);
// 		for (int p = 1; p < m; p++)
// 			for (int q = 0; q < p; q++)
// 				if(a[q] > a[p])
// 					sum++;
// 		fprintf(fout,"%d\n",sum);
// 	}
	// fclose(fin);
	// fclose(fout);
// 	return 0;
// }



//038
//C++进制转换


// #include<iostream>
// #include<cmath>
// #include<cstring>
// #include<cstdio>
// using namespace std;
// int main()
// {
//     int m,b[100],sum=0,i,n,j,c[1000];
//     char d[100],a[16];
//     a[0]='0';a[1]='1';a[2]='2';a[3]='3';a[4]='4';a[5]='5';a[6]='6';a[7]='7';a[8]='8';a[9]='9';a[10]='A';a[11]='B';a[12]='C';a[13]='D';a[14]='E';a[15]='F';	
// 	cin>>m>>n>>d;
//     if(d[1]==0)
//     {
//     cout<<"0"<<endl;
// 	}
// 	else
// 	{ 
//         j=strlen(d);
//         for(i=0;i<=j-1;i++)
//         {
//             b[i]=d[i];
//             if(b[i]<65)
// 	            b[i]=b[i]-48;
//             if(b[i]>=65)
// 	            b[i]=b[i]-55;
//             sum+=pow(m,j-i-1)*b[i];
//         }  
//         i=0;
//         while(sum!=0)
//         {
// 	       i++;
// 	       c[i]=sum%n;
//             sum=sum/n;
//         }
// 	   for(j=i;j>=1;j--)
//        {
// 	       cout<<a[c[j]];
//         }
//     } 
// 	return 0;
// }


//C进制转换

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// char a[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
// char b[100];
// int r(char ch)
// {
// 	if(isalpha(ch))
// 		return ch - 'A' + 10;
// 	return ch - 48;
// }
// int pow(int a,int b)                  //math.h的函数pow不能用,精度不够
// {
//     int c = 1;
//     for(int i = 0;i<b;i++)
//         c *= a;
//     return c;
// }

// int main(void)
// {
// 	int P,Q,len,sum = 0,k = 0;
// 	char N[20];                  //将P进制的N转换为Q进制的N
// 	scanf("%d%d%s",&P,&Q,N);
// 	//先转换为十进制
// 	len = strlen(N);
// 	for (int i = len-1,j = 0; i >= 0; i--)
// 	{

// 		sum += r(N[i])*pow(P,j);

// 		j++;
// 	}

// 	//再转换为Q进制
// 	while((int)sum/Q)
// 	{
//         b[k++] = a[(int)sum%Q];
// 		sum = (int)sum/Q;
// 	}
// 	b[k] = a[(int)sum%Q];
// 	len = strlen(b);
// 	for (int i = len-1; i >= 0;i--)
//         printf("%c",b[i]);
// 	return 0;
// }




//039
//因式分解

// #include <stdio.h>
// int main(void)
// {
//   	int i, n;
// 	while(~scanf("%d", &n))
// 	{
// 	  	for (i = 2;i <= n;)
// 		{
// 	    	if (n % i == 0)
// 	    	{
// 	      		printf("%d ",i);
// 	      		n /= i;
// 	    	}
// 	    	else
// 	      		i++;
// 	  	}
// 	  	printf("\n");
// 	}
// 	return 0;
// }


//040

// #include <stdio.h>
// long long a[1000000];
// int main(void)
// {
// 	FILE *fin,*fout;
// 	// fin = fopen("input.txt","r");
// 	// fout = fopen("output.txt","w");
// 	fin = stdin;
// 	fout = stdout;
// 	long long int k,max1,max2;
// 	while(~fscanf(fin,"%I64d",&k))
// 	{
// 		max1 = -100001;
// 		max2 = -100001;
// 		for(int i = 0;i < k;i++)
// 			fscanf(fin,"%I64d",&a[i]);
// 		for(int i = 0;i < k;i++)
// 			if(a[i] > max1)
// 				max1 = a[i];
// 		for(int i = 0;i < k;i++)
// 			if(a[i] > max2 && a[i] < max1)
// 				max2 = a[i];
// 		if(max2 == -100001 )
// 			fprintf(fout,"No such number\n");
// 		else
// 			fprintf(fout,"%d\n",max2);
// 	}
// 	// fclose(fin);
// 	// fclose(fout);
// 	return 0;
// }



//041

// #include <stdio.h>
// int arr[10000];
// void quick_sort(int s[], int l, int r)          //快速排序
// {  
//     if (l < r)  
//     {  
//         //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
//         int i = l, j = r, x = s[l];  
//         while (i < j)  
//         {  
//             while(i < j && s[j] <= x) // 从右向左找第一个大于x的数  
//                 j--;    
//             if(i < j)   
//                 s[i++] = s[j];  
              
//             while(i < j && s[i] > x) // 从左向右找第一个小于等于x的数  
//                 i++;    
//             if(i < j)   
//                 s[j--] = s[i];  
//         }  
//         s[i] = x;  
//         quick_sort(s, l, i - 1); // 递归调用   
//         quick_sort(s, i + 1, r);  
//     }  
// }  
// int main(void)
// {
// 	FILE *fin,*fout;
// 	// fin = fopen("input.txt","r");
// 	// fout = fopen("output.txt","w");
// 	fin = stdin;
// 	fout = stdout;
// 	int t,i = 0;
// 	fscanf(fin,"%d",&t);
// 	while(i < t)
// 	{
// 		int n,kase = 1;
// 		fscanf(fin,"%d",&n);
// 		for (int i = 0; i < n; i++)
// 			fscanf(fin,"%d",&arr[i]);
// 		quick_sort(arr,0,n-1);
// 		for (int i = 1; i < n; i++)
// 			if(i > arr[i-1])
// 			{
// 				fprintf(fout,"%d\n",i-1);
// 				kase = 0;
// 				break;
// 			}
// 		if(kase)
// 			fprintf(fout,"%d\n",n);
// 		i++;
// 	}
// 	// fclose(fin);
// 	// fclose(fout);
// 	return 0;
// }


//042





// //下面的程序意图在于统计字符串中字符1的个数,可惜有瑕疵
// //该程序至少有3个问题,其中一个导致程序无法运行,另一个导致结果不正确,还有一个导致效率低下.你能找到它们并改正吗?

// #include <stdio.h>
// #define maxn 10000000 + 10
// int main(void)
// {
// 	char s[maxn];
// 	scanf("%s",s);
// 	int tot = 0;
// 	for (int i = 0; i < strlen(s); i++)
// 		if(s[i] == 1) tot++;
// 	printf("%d\n",tot);
// 	return 0;
// }

//一个统计字数的程序


// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>
// int main(void)
// {
// 	char c;         		//读入字符
// 	char prev;				//前一个读入字符
// 	long n_chars = 0L;		//字符数
// 	int n_lines = 0;		//行数
// 	int n_words = 0;		//单词数
// 	int p_lines = 0;		//不完整行数
// 	bool inword = false;	//如果c在一个单词中,则inword等于true

// 	prev = 'n';				//用于识别完整行
// 	while(~(c = getchar()))
// 	{
// 		n_chars++;			//统计字符
// 		if(c == '\n')
// 			n_lines++;		//统计行
// 		if(!isspace(c) && !inword)
// 		{
// 			inword = true;	//开始新单词
// 			n_words++;		//统计单词
// 		}	
// 		if(isspace(c) && inword)
// 			inword = false;	//到达单词尾部
// 		prev = c;			//保存字符值
// 	}
// 	if(prev != '\n')
// 		p_lines = 1;
// 	printf("characters = %ld\nwords = %d\nlines = %d\n",n_chars,n_words,n_lines);
// 	printf("partial lines = %d\n",p_lines);
// 	return 0;
// }


// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s[20];
// 	while(scanf("%s",s) != EOF)
// 	{
// 		int count = 0;
// 		char buf[99];
// 		for (int abc = 100; abc <= 999; abc++)
// 			for (int de = 10; de <= 99; de++)
// 			{
// 				int x = abc*(de%10),y = abc*(de/10),z = abc*de;
// 				sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
// 				int ok = 1;
// 				for (int i = 0; i < strlen(buf); i++)
// 					if(strchr(s,buf[i]) == NULL) ok = 0;
// 				if(ok)
// 					count++;
// 			}
// 		printf("%d\n",count);
// 	}
// 	return 0;
// }

//打表

// #include <stdio.h>
// unsigned w[500001];
// unsigned arr[500001] = {0};
// int main(void)
// {
// 	FILE *fin,*fout;
// 	// fin = fopen("input.txt","r");
// 	// fout = fopen("output.txt","w");
// 	fin = stdin;
// 	fout = stdout;
// 	unsigned n,m,count = 0;
// 	fscanf(fin,"%d%d",&n,&m);

// 	for(int i = 1; i <= n; i++)
// 	{
// 		fscanf(fin,"%u",&w[i]);
// 		for(int j = 1; j*i <= n; j++)
// 			arr[j*i] += w[i];
// 	}
// 	while(count < m)
// 	{
// 		unsigned p;
// 		fscanf(fin,"%u",&p);
// 		fprintf(fout,"%u\n",arr[p]);
// 		count++;
// 	}
// 	// fclose(fin);
// 	// fclose(fout);
// 	return 0;
// }



// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     int t,n,m,k,r,temp;
//     double sky,good;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);
//         m=k=1;
//         r=0;
//         while(n--)
//         {
//             scanf("%d",&temp);
//             switch(temp)
//             {
//                 case 0:++r;break;
//                 case 1:++k;r=0;break;
//                 case 2:++m;k=1;r=0;break;
//                 case 3:sky=m*1.0-pow(0.5,k)-pow(0.5,k+r);
//                        printf("skyfucker %.2f\n",sky);
//                        break;
//                 case 4:good=m*1.0-pow(0.5,k)-pow(0.5,k+r);
//                        printf("goodtime %.2f\n",good);
//                        break;
//             }
//         }
//     }
//     return 0;
// }

//使用位运算显示二进制数
//

// #include <stdio.h>
// char *itobs(int,char *);
// void show_bstr(const char *);

// int main(void)
// {
// 	char bin_str[8*sizeof(int) + 1];
// 	int number;

// 	puts("Enter integers and see them in binary.");
// 	puts("Non-numeric input terminates program.");
// 	while(scanf("%d",&number) == 1)
// 	{
// 		itobs(number,bin_str);
// 		printf("%d is \n",number);
// 		show_bstr(bin_str);
// 		putchar('\n');
// 	}
// 	puts("Bye!");
// 	return 0;
// }

// char * itobs(int n,char *ps)
// {
// 	int i;
// 	static int size = 8*sizeof(int);

// 	for(i = size -1; i >= 0; i--,n>>=1)
// 		ps[i] = (01 & n) +'0';
// 	ps[size] = '\0';

// 	return ps;
// }

// void show_bstr(const char *str)
// {
// 	int i = 0;
// 	while(str[i])
// 	{
// 		putchar(str[i]);
// 		if(++i % 4 == 0 && str[i])
// 			putchar(' ');
// 	}
// }

















































































































































































