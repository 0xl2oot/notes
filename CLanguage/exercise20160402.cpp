//C++黑魔法
// #include <cstdio>
// int main(void)
// {
// 	int x = 10;
// 	while(0 <---- x)
// 	{
// 		printf("%d\n",x);
// 	}
// 	return 0;
// }





// #include <cstdio>

// int main(){
//     //通过class关键字类定义类
//     class Student{
//     public:  //类包含的变量
//         char const *name;
//         int age;
//         float score;
//         void say(){
//             printf("%s is %d years old , his score is %f\n", name, age, score);
//         }
//     };

//     //通过类来定义变量，即创建对象
//     class Student stu1;  //也可以省略关键字class
//     //操作类的成员
//     stu1.name = "Xiao Ming";
//     stu1.age = 15;
//     stu1.score = 92.5f;
//     stu1.say();
//     return 0;
// }



// #include <cstdio>

// //将类定义在命名空间中
// namespace diy{
//     class Student{
//     public:
//         char const *name;
//         int age;
//         float score;
//         void say(){
//             printf("%s is %d years old , his score is %f\n", name, age, score);
//         }
//     };
// }

// int main(){
//     diy::Student stu1;
//     stu1.name = "Xiao Ming";
//     stu1.age = 15;
//     stu1.score = 92.5f;
//     stu1.say();

//     return 0;
// }


// #include <cstdio>
// using namespace std;

// class Book{
// private:
//     float price;
// public:
//     void setprice(float price1){
//         price = price1;
//     }
//     float getprice(){
//         return price;
//     }  
// };

// int main(){
//     float price;
//     Book book;
   
//     scanf("%f", &price);
//     book.setprice(price);
//     printf("The price of the book is %f.\n", book.getprice());

//     return 0;
// }


// #include <iostream>
// using namespace std;
// int main(){
//     int x;
//     float y;
//     cout<<"Please input an int number:"<<endl;
//     cin>>x;
//     cout<<"The int number is x= "<<x<<endl;
//     cout<<"Please input a float number:"<<endl;
//     cin>>y;
//     cout<<"The float number is y= "<<y<<endl;   
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main(){
//     int x;
//     float y;
//     cout<<"Please input an int number:"<<endl;
//     cin>>x;
//     cout<<"The int number is x= "<<x<<endl;
//     cout<<"Please input a float number:"<<endl;
//     cin>>y;
//     cout<<"The float number is y= "<<y<<endl;   
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[10001];
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++) cin>>a[i];
//     sort(a,a+n);
//     int m=n-1;
//     int s=0;
//     for(int i=0;i<m;i++)
//     {
//         a[0]=a[0]+a[1];
//         s+=a[0];
//         for(int j=1;j<n;j++)
//             a[j]=a[j+1];
//         n--;
//         sort(a,a+n);
//     }
//     cout<<s;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// long long pow(int i);
// int main()
// {
// 	long long seven[10];
// 	long long n;
// 	seven[0] = 0L;
// 	for(int i = 0; i < 10; i++)
// 		seven[i] = pow(i);
// 	while(cin>>n)
// 	{
// 		long long sum = 0L,t = n;
// 		for(int i = 0; i < 7; i++)
// 		{
// 			sum += seven[t%10];
// 			t /= 10;
// 		}
// 		if(sum == n)
// 			cout<<"Y"<<endl;
// 		else
// 			cout<<"N"<<endl;

// 	}
// }
// long long pow(int a)
// {
// 	long long b = 1L;
// 	for(int i = 0; i < 7; i++)
// 		b *= a;
// 	return b;
// }


// #include <cstdio>
// #include <algorithm>
// #include <cstring>

// using namespace std;
// struct E
// {
// 	char name[101];
// 	int score;
// }buf[1000];
// bool cmp(E a,E b){
// 	if(a.score != b.score) return a.score > b.score;
// 	int tmp = strcmp(a.name,b.name);
// 	if(tmp != 0) return tmp < 0;
// }
// int main(void){

// 	FILE *fin,*fout;
// 	fin = fopen("input.txt","r");
// 	fout = fopen("output.txt","w");		

// 	int n;
// 	fscanf(fin,"%d",&n);
// 	for (int i = 0; i < n; i++)
// 		fscanf(fin,"%s%d",buf[i].name,&buf[i].score);
// 	sort(buf,buf + n,cmp);
// 	for (int i = 0; i < n; i++)
// 		fprintf(fout,"%s %d\n",buf[i].name,buf[i].score);
// 	fclose(fin);
// 	fclose(fout);
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

// #include <iostream>

// using namespace std;
// int main(void)
// {
// 	long long k,x,y,z;
// 	while(cin>>k)
// 	{
// 		z = k*(k+1);
// 		for(y = k+1; y <= k*2; y++)
// 		{
// 			x = z;
// 			while(x >= k*2)
// 			{
// 				if(x*y == k*(x+y))
// 				{
// 					cout<<"1/"<<k<<"=1/"<<x<<"+1/"<<y<<endl;
// 					z = x;
// 					break;
// 				}
// 				else
// 					x--;
// 			}	
// 		}		
// 	}
// 	return 0;
// }



// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int a,b,c;
// 	while(cin>>a>>b>>c)
// 	{
// 		if((a+b)<=c || (a-b)>=c)
// 		{
// 			cout<<"ERROR"<<endl;
// 			continue;
// 		}
// 		else if(a == b && b == c)
// 		{
// 			cout<<"DB"<<endl;
// 			continue;
// 		}
// 		else if((a == b && b != c) || (a == c && b != a) || (c == b && b != a))
// 		{
// 			cout<<"DY"<<endl;
// 			continue;
// 		}
// 		else if((a*a + b*b) == c*c || (a*a + c*c) == b*b || (b*b + c*c) == a*a)
// 		{
// 			cout<<"ZJ"<<endl;
// 			continue;
// 		}
// 		else
// 		{
// 			cout<<"PT"<<endl;
// 			continue;
// 		}
// 	}
// 	return 0;
// }


//不懂这个

// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>
// using namespace std;

// int judge(int a[][2],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(a[i][0]==0)
//             return 1;
//     }
//     return 0;
// } 
// int main()
// {
//     int a[100][2]={0};
//     int n,m,l[1000][2];
//     int i,k;
//     while(cin>>n>>m)
//     {
//         if(n==0&&m==0)
//           break;
//         k=0;
          
//         for(i=0;i<n;i++)
//         {
//             a[i][0]=0;
//             a[i][1]=0;
//         }
//        for(i=0;i<m;i++)
//        	{
//           	cin>>l[i][0]>>l[i][1];
//           	a[l[i][0]-1][1]++;
//           	a[l[i][1]-1][0]++;
//        	}
//        	while(judge(a,n))
//        	{
//          	for(i=0;i<n;i++)
// 	        {
// 	            if(a[i][0]==0)
// 	            {
// 	                for(int j=0;j<m;j++)
// 	                {
// 	                    if(l[j][0]==i+1)
// 	                    {
// 	                        a[l[j][1]-1][0]--;
// 	                    }
// 	                }
// 	                k++;
// 	                a[i][0]=1000;
// 	            }
// 	       	}
//        	}
//       	if(k==n)
//         	cout<<"NO"<<endl;
//        	else
//         	cout<<"YES"<<endl;
//     }
// }



// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;
 
// char str[10];
// void Perm(char *str, int k, int m);
// void Swap(char &a, char &b);
 
// int main()
// {
// 	int n;
// 	while(scanf("%d", &n) != EOF)
// 	{
// 		for(int i=0; i<=n; ++i)
// 		{
// 			str[i] = i+'0';
// 		}
//         Perm(str, 1, n);
// 	}
// 	return 0;
// }
 
 
// void Perm(char *str, int k, int m)
// {
//         int i;
//         if(k == m)
//         {
//                 for(i=1; i<=m; ++i)
//                     cout<<str[i]<<" "<<flush;
//                 cout<<endl;
//                 return;
//         }
 
//         for(i=k; i<=m; ++i)
//         {
//                 Swap(str[k], str[i]);
//                 Perm(str, k+1, m);
//                 Swap(str[k], str[i]);
//         }
 
// }
 
 
// void Swap(char &a, char &b)
// {
//         char tmp = a;
//         a = b;
//         b = tmp;
// }


// #include <cstdio>
// #include <iostream>  
// #include <algorithm> 
// using namespace std;  
  
// void permutation(char* str,int length)  
// {  
//     sort(str,str+length);  
//     do  
//     {  
//         for(int i=0;i<length;i++)  
//             cout<<str[i]<<" ";  
//         cout<<endl;  
//     }while(next_permutation(str,str+length));  
  
// }  
// int main(void)  
// {  
//     int n;
//     char str[8];
//     while(scanf("%d", &n) != EOF)
//     {
// 	    for(int i = 0; i <= n; ++i)
// 	    	str[i] = i + '1'; 
// 	    permutation(str,n);
//     }
      
//     return 0;  
// }  







// #include <algorithm>
// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int t,n,m,k;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int flag = 1,a[101],b = 0,sum = 0;
// 		cin>>n>>m>>k;
// 		for(int i = k;i > 0; --i)
// 			cin>>a[i];
// 		sort(a,a+k);
// 		for(int i = k;i > 0; --i)
// 		{
// 			sum += a[i];
// 			b++;
// 			if(sum >= (n-m))
// 			{
// 				flag = 0;
// 				break;
// 			}
// 		}
// 		if(flag)
// 			cout<<"-1"<<endl;
// 		else
// 			cout<<b<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// using namespace std;
// int main()
// {
// 	long long s,n,i,j,p;s=0;
// 	cin>>n;
// 	for(i=1;i<=n;i++)
//    	{  
//    		p=1;
//        	for(j=1;j<=i;j++) p*=j;
//      	s+=p;
// 	}
//  	cout<<s<<endl;
// 	return 0;
// }

// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #define maxn 50010

// using namespace std;

// int a[maxn];
// int sum[maxn];
// int main(void)
// {
// 	int n,k,m1,m2,suma;
// 	char m;
// 	memset(a,0,sizeof(a));
// 	memset(sum,0,sizeof(sum));
// 	cin>>n>>k;
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
// 		cin>>m>>m1>>m2;	
// 		suma = sum[m2]-sum[m1-1];
// 		if(m == 76)
// 			cout<<suma<<endl;
// 		else
// 			cout<<m2-m1+1-suma<<endl;
// 	}
// 	return 0;
// }


// #include <iostream>
// #include <cstring>
// #define maxn 50010

// using namespace std;

// int a[maxn];
// int main(void)
// {
// 	int n,k,m1,m2,sum;
// 	char m;
// 	memset(a,0,sizeof(a));
// 	cin>>n>>k;
// 	for(int i = 1; i <= k; i++)
// 	{
// 		sum = 0;
// 		cin>>m>>m1>>m2;			
// 		if(m == 79)
// 			for(int i = m1; i <= m2; i++)
// 				a[i] = !a[i];
// 		else
// 		{
// 			for(int i = m1; i <= m2; i++)
// 				if(a[i])
// 					sum++;
// 			cout<<sum<<endl;
// 		}
// 	}
// 	return 0;
// }


// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main(void)
// {
// 	int n,a[101],sum = 0;
// 	cin>>n;
// 	for(int i = 0; i < n; i++)
// 		cin>>a[i];
// 	sort(a,a+n);
// 	while(a[0] != a[n-1])
// 	{
// 		for(int i = n-1;i >= 0; i--)
// 		{
// 			if(a[n-1] != a[i])
// 			{
// 				a[n-1] = a[n-1] - a[i];
// 				break;
// 			}
// 		}
// 		sort(a,a+n);
// 	}
// 	for(int i = 0; i < n; i++)
// 		sum += a[i];
// 	cout<<sum<<endl;
// 	return 0;
// }



// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[1001],b[1001];
// int main(void)
// {					// 此题另一种解法是给定数组，分别记录每个数字出现的次数
// 	int n,m = 0,k = 1;
// 	cin>>n;
// 	for(int i = 0; i < n; i++)
//  		cin>>a[i];
//  	sort(a,a+n);
//  	for(int i = 1; i < n;i++)
//  	{
//  		if(a[i] != a[i-1])
//  		{
//  			b[m++] = k;
//  			k = 1;
//  		}
//  		else
//  			k++;
//  	}
//  	b[m] = k;
//  	sort(b,b+m+1);
//  	cout<<b[m]<<" "<<m+1<<endl;
// 	return 0;
// }



// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	long long n,s;
// 	while(cin>>n)
// 	{
// 		s = 0L;
// 		for(long long i = 1L; i <= n; i++)
// 			s += i;
// 		cout<<s<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// using namespace std;
// long b[1000001];
// int main(void)
// {
// 	long m,a[1001],i,n2,n;
// 	int flag = 0,k = 0;
// 	cin>>n>>m;
// 	while(k<n)
// 		cin>>a[k++];
// 	i = 0L;
// 	for(int i1 = 0; i1 < n; i1++)
// 		for(int i2 = 0; i2 < n; i2++)
// 			b[i++] = a[i1] + a[i2];
// 	n2 = n*n-1;
// 	for(long i3 = 0L; i3 < n2; i3++)
// 		for(long i4 = 0L; i4 < n2; i4++)
// 			if((a[i3]+a[i4]) == m)
// 			{
// 				flag = 1;
// 				break;
// 			}
// 	if(flag)
// 		cout<<"Yes"<<endl;
// 	else
// 		cout<<"No"<<endl;

// 	return 0;
// }




		
			// for(int i3 = 0; i3 < n; i3++)
			// 	for(int i4 = 0; i4 < n; i4++)
			// 		if((a[i1]+a[i2]+a[i3]+a[i4]) == m)




// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
// 	int a,b,c,n;
// 	cin>>n;
// 	while(n--)
// 	{
// 		cin>>a;
// 		b = sqrt(a);
// 		c = 1;
// 		for (int i = 2; i <= b; ++i)
// 		{
// 			if(a%i == 0)
// 			{
// 				c = 0;
// 				break;
// 			}
// 		}
// 		if(c)
// 			cout<<"yes"<<endl;
// 		else
// 			cout<<"no"<<endl;
		
// 	}	
// 	return 0;
// }


// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int m,n,a[101];
// 	cin>>m;
// 	while(m--)
// 	{
// 		cin>>n;
// 		int i = 0, k =0, sum = 0;
// 		for(int i = 0; i < n ;i++)
// 			cin>>a[++i];
// 		for(int i = 1; i <= n; i++)
// 			if(a[i] == 0)
// 			{
// 				k++;
// 				int j = i;
// 				while(!a[++j] && j <= n);
// 				a[i] = a[j];
// 				sum += (j-i)*a[j];
// 			}
// 		cout<<sum<<" "<<k;
// 		n = n - k;
// 		i = 0;
// 		while(n--)
// 			cout<<" "<<a[++i];
//  	}

// 	return 0;
// }









// #include <iostream> 
// using namespace std; 
// int  main() 
// { 
//     int a,b; 
//     cin >> a >> b; 
//     cout << a+b << endl; 
//     return 0; 
// }

// #include <iostream>
// using namespace std;

// int sum(int a)
// {
// 	while(a)
// 		return (a + sum(a-1));
// }

// int main(void)
// {
// 	int n,m;
// 	cin>>n;
// 	m = sum(n);
// 	cout<<m<<endl;
// 	return 0;
// }



// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// char a[11][11];
// int main(void)
// {
// 	int n,m;
// 	while(cin>>n)
// 	{
// 		if(n == 0)
// 			break;
// 		memset(a, 0, sizeof(a));
// 		m = 1;
// 		for (int i = 0; i < n; i++)
// 			a[0][i] = m++;
// 		for (int i = 1; i < n; i++)
// 			a[i][n-1] = m++;
// 		for (int i = n-2; i >= 0; i--)
// 			a[n-1][i] = m++;
// 		for (int i = n-2; i > 0; i--)
// 			a[i][0] = m++;
// 		for (int i = 0; i < n; i++)
// 		{
// 			for (int j = 0; j < n; j++)
// 			{
// 				if(a[i][j])
// 					printf("%3d",a[i][j]);
// 				else
// 					printf("   ");
// 			}	
// 			printf("\n");
// 		}
// 	}

// 	return 0;
// }


// #include <iostream>
// #include <cmath>
// using namespace std;
// int main(void)
// {
// 	int a,b;
// 	while(cin>>a>>b)
// 	{
// 		if((a == 11 && b == 9) || (a == 9 && b == 11))
// 			cout<<"Game Over"<<endl;
// 		else if(a >= 10 && b >= 10 && abs(a-b) >= 2)
// 			cout<<"Game Over"<<endl;
// 		else if(a >= 10 && b >= 10 && (a+b)%2 == 0)
// 			cout<<"A"<<endl;
// 		else if(a >= 10 && b >= 10 && (a+b)%2 == 1)
// 			cout<<"B"<<endl;
// 		else if((a+b)%4==0 || (a+b)%4==1)
// 				cout<<"A"<<endl;
// 		else if((a+b)%4==2 || (a+b)%4==3)
// 				cout<<"B"<<endl;
// 	}
// 	return 0;
// }


// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	double a,b;
// 	while(cin>>a>>b) 
// 	{
// 		if(b == 0)
// 		{
// 			cout<<"error"<<endl;
// 			continue;
// 		}
// 		cout<<(int)(a/b+0.5)<<endl;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// int main(void)
// {
// 	char str[11];
// 	int len;
// 	cin>>str;
// 	len = strlen(str);
// 	cout<<len<<endl;
// 	for(int i = len - 1; i >= 0; i--)
// 		cout<<str[i];
// 	cout<<endl;
// 	return 0;
// }


// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	for(int i = 1; i <= 1000; i++)
// 	{
// 		if(i%3 == 0 && i%5 == 0)
// 			cout<<"great"<<endl;
// 		else if(i%3 == 0)
// 			cout<<"tri"<<endl;
// 		else if(i%5 == 0)
// 			cout<<"fri"<<endl;
// 		else
// 			cout<<i<<endl;
// 	}
// 	return 0;
// }







// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int m,n,a[101];
// 	cin>>m;
// 	while(m--)
// 	{
// 		cin>>n;
// 		int i = 0, k =0, sum = 0;
// 		for(int i = 0; i < n ;i++)
// 			cin>>a[++i];
// 		for(int i = 1; i <= n; i++)
// 			if(a[i] == 0)
// 			{
// 				k++;
// 				int j = i;
// 				while(!a[++j] && j <= n);
// 				a[i] = a[j];
// 				sum += (j-i)*a[i];
// 			}
// 		cout<<sum<<" "<<k;
// 		n = n - k;
// 		i = 0;
// 		while(n--)
// 			cout<<" "<<a[++i];
//  	}

// 	return 0;
// }



// 不高兴的津津

// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int a[7][2],max = 8,n;
// 	for(int i = 0; i < 7; i++)
// 		cin>>a[i][0]>>a[i][1];
// 	for(int i = 6; i >= 0; i--)
// 		if((a[i][0]+a[i][1]) >= max)
// 		{
// 			n = i+1;
// 			max = a[i][0]+a[i][1];
// 		}
// 	cout<<n;
// 	return 0;
// }

// 求阶乘的位数

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main(void)
// {
// 	int t,n,f,i;
// 	double m;
// 	cin>>t;
//     while(t--)
//     {
// 	    cin>>n;
// 	    m = 0;
// 	    for(i = 2; i <= n; i++)
// 	        m += log10(i);
// 	    f = (int)m+1;
// 	    cout<<f<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <cmath>
// const double PI = 3.14159265;
// using namespace std;

// int main()
// {
// 	int N,T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		cin>>N;
// 		int len=ceil((N*log((double)N)-N+log(2.0*(double)N*PI)/2.0)/log(10.0)); 		// 斯特林公式
// 		if(!len)len++; //len=0 when n=1 notice
// 		cout<<len<<endl;
// 	}
// 	return 0;
// }

// #include<stdio.h>
// int main()
// {
// 	int n,j,k,m,p;
	// while(~scanf("%d",&n))
// 	{
// 	    if(n==1)printf("%3d\n",n);
// 	    else
// 	    {
// 	        for(j=1;j<=n;j++)
// 		    {
//         	    printf("%3d",j);
// 		    }
// 	        printf("\n");
// 	        for(k=n+1;k<2*n-1;k++)  	
// 		    {   
// 		        printf("%3d",5*n-3-k);
// 		        for(m=1;m<n-1;m++)
// 				{
// 				    printf("   ");
// 			    }
// 		        printf("%3d",k);
// 			    printf("\n");
// 		    }
// 		    for(p=3*n-2;p>=2*n-1;p--)
// 		    {
// 			    printf("%3d",p);
// 		    }	
// 		    printf("\n");
//      	}
// 	}
// 	return 0;
// } 



// #include <iostream>
// #include <cmath>
// using namespace std;
// int main(void)
// {
// 	int a,b;
// 	cin>>a>>b;
// 	cout<<abs((a+b)%10)<<endl;
// 	return 0;
// }


// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int x,m,n,sum = 0;
// 	cin>>x>>m>>n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		sum += x;
// 		x += m;
// 	}
// 	cout<<sum<<endl;
// 	return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// int main(void)
// {
//     char s[1001];
//     int n;
//     cin>>n;
//     while(n--)
//     {
//         cin>>s;
//         int flag = 1;
//         int len = strlen(s);
//         for(int i = 0; i < (len+1)/2; i++)
//             if(s[i] != s[len-1-i]) flag = 0;
//         if(flag)
//             cout<<"Yes"<<endl;
//         else
//             cout<<"No"<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <cstdio>
// using namespace std;
// int main(void)
// {
// 	int a1,a2,a3,b1,b2,b3,c1,c2,c3,sum;
// 	scanf("%d:%d:%d",&a1,&b1,&c1);
// 	scanf("%d:%d:%d",&a2,&b2,&c2);
// 	sum = (a2-a1)*3600 + (b2-b1)*60 + (c2-c1);
// 	a3 = sum/3600;
// 	b3 = (sum%3600)/60;
// 	c3 = sum%60;
// 	printf("%02d:%02d:%02d\n",a3,b3,c3);
// 	return 0;
// }


// #include <iostream>
// #include <cstdio>
// using namespace std;
// int main(void)
// {
// 	int a1,a2,b1,b2,c,sum;
// 	scanf("%d:%d",&a1,&b1);
// 	scanf("%d:%d",&a2,&b2);
// 	scanf("%d",&c);
// 	sum = (a2-a1)*60 + (b2-b1) + c*20;
// 	cout<<sum<<endl;
// 	return 0;
// }


// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int m,n;
// 	while(cin>>m>>n)
// 	cout<<m-n<<endl;
// 	return 0;
// }


// #include <iostream>
// #include <cstdio>
// #include <cstring>
// char str[1001];
// using namespace std;
// int main(void)
// {
// 	int len,flag = 0;
// 	gets(str);
// 	len = strlen(str);
// 	for (int i = 0; i < len - 1; i++)
// 	{
// 		if(str[i] == str[i+1])
// 		{
// 			cout<<str[i];
// 			flag = 1;
// 			return 0;
// 		}
// 	}
// 	if(!flag)
// 		cout<<"No"<<endl;
// 	return 0;
// }

// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int a,b;
// 	while(cin>>a>>b)
// 		cout<<a+b<<endl;
// 	return 0;
// }


// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	int a,b,c,d;
// 	while(cin>>a>>b>>c>>d)
// 	{
// 		if(a == b && c != d)
// 			cout<<"A"<<endl;
// 		else if(a != b && c == d)
// 			cout<<"B"<<endl;
// 		else if(a == b && c == d && a > c)
// 			cout<<"A"<<endl;
// 		else if(a == b && c == d && a < c)
// 			cout<<"B"<<endl;
// 		else if(a != b && c != d && (a+b)%10 > (c+d)%10)
// 			cout<<"A"<<endl;
// 		else if(a != b && c != d && (a+b)%10 < (c+d)%10)
// 			cout<<"B"<<endl;
// 		else
// 			cout<<"N"<<endl;
// 	}
// 	return 0;
// }


// #include <iostream>
// using namespace std;

// //函数声明
// int max(int, int, int);
// double max(double, double, double);
// long max(long, long, long);

// int main( )
// {
//     //求三个整数的最大值
//     int i1, i2, i3, i_max;
//     cin >> i1 >> i2 >> i3;
//     i_max = max(i1,i2,i3);
//     cout << "i_max=" << i_max << endl;

//     //求三个浮点数的最大值
//     double d1, d2, d3, d_max;
//     cin >> d1 >> d2 >> d3;
//     d_max = max(d1,d2,d3);
//     cout << "d_max=" << d_max << endl;

//     //求三个长整型数的最大值
//     long g1, g2, g3, g_max;
//     cin >> g1 >> g2 >> g3;
//     g_max = max(g1,g2,g3);
//     cout << "g_max=" << g_max << endl;
// }

// //求三个整数的最大值
// int max(int a, int b, int c)
// {
//     if(b>a) a=b;
//     if(c>a) a=c;
//     return a;
// }

// //求三个浮点数的最大值
// double max(double a, double b, double c)
// {
//     if(b>a) a=b;
//     if(c>a) a=c;
//     return a;
// }

// //求三个长整型数的最大值
// long max(long a, long b, long c)
// {
//     if(b>a) a=b;
//     if(c>a) a=c;
//     return a;
// }






// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// int flag;
// void cal(string s)
// {
// 	if(s.length() == 0)
// 		return ;
// 	else
// 	{
// 		int len=s.length();
// 		if(s[len-1]>='p' && s[len-1]<='z')
// 		{
// 			flag++;
// 			cal(s.substr(0,len-1));
// 		}
// 		else if(s[len-1]=='N')
// 			cal(s.substr(0,len-1));
// 		else if(s[len-1]=='C'||s[len-1]=='D'||s[len-1]=='E'||s[len-1]=='I')
// 		{
// 			flag--;
// 			cal(s.substr(0,len-1));
// 		}
// 		else
// 		{
// 			flag=0;
// 			return ;
// 		}
// 	}
// }
// int main()
// {
// 	string s;
// 	while(cin>>s)  
// 	{
// 		flag=0;
// 		cal(s);
// 		if(flag==1)
// 			cout<<"YES"<<endl;
// 		else
// 			cout<<"NO"<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <algorithm>
// using namespace std;
// long long a[10001];
// int main()
// {
// 	int n;
// 	long long sum = 0L;
// 	cin>>n;
// 	for (int i = 0; i < n; i++)
// 		cin>>a[i];
// 	for (int j = n-1; j > 0; j--)
// 	{
// 		sort(a,a+n--);
// 		a[0] += a[1];
// 		a[1] = a[j];
// 		sum += a[0];
// 	}
// 	cout<<sum;
// 	return 0;
// }


// #include <iostream>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// int main()
// {
// 	float a,b,c,d,L,R,max = 0,f;
// 	while(cin>>a>>b>>c>>d>>L>>R)
// 	{
// 		for (int i = L; i <= R; i++)
// 		{
// 			f = abs(a*i*i*i + b*i*i + c*i + d);
// 			max = max > f ? max:f;
// 		}
// 		printf("%.2f\n",max);
// 	}
// 	return 0;
// }


// 1220

// #include <iostream>
// using namespace std;
// int main(void)
// {
// 	long long m,n,f[10001] = {0,1};
// 	for (int i = 2; i < 10001; i++)
// 		f[i] = 2*f[i-1] - 3*f[i-2] + 1;
// 	cin>>m;
// 	while(m--)
// 	{
// 		cin>>n;
// 		cout<<f[n]<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     if(n == 1){
//         int x;
//         cin >> x;
//         cout << x << endl;;
//     }
//     else{
//     int sum = 0;
//     vector <int> a,b;
//     for(int i = 0;i < n;i++){
//         int x;
//         cin >> x;
//         a.push_back(x);
//     }
//     sort(a.begin(),a.end());
//     b = a;
//     while(b.size() > 2){
//         int s;
//         s= b[0] + b[1];
//         sum += s;
//         b.push_back(s);
//         a.clear();
//         for(int i = 2;i < b.size();i++){
//             a.push_back(b[i]);
//         }
//         sort(a.begin(),a.end());
//         b = a;
//     }
//     cout << sum + b[0] + b[1] << endl;
//     }
// }


// #include <iostream>
// #include <algorithm>
// using namespace std;
// long a[101];
// long b[100001];

// const long max_value(long arr[],long size)
// {
//  	long max=arr[0];
//  	for (int i=1;i<size;i++) 
//   		if(max < arr[i]) max = arr[i];
//  	return max;
// }

// int main(void)
// {
// 	long n,m;
// 	char c[4]={'A','B','C','D'};
// 	for(long i = 0L; i < 100001; i++)
// 	{	
// 		n = 0L;
// 		for (long j = 1L; j < i/2; j++)
// 			if(i%j == 0)
// 				n++;
// 		b[i] = n;
// 	}
// 	while(cin>>m,m)
// 		cout<<c[max_value(b+1,m)%4]<<endl;

// 	return 0;
// }


// #include <stdio.h>

// //类可以在所有函数之外定义
// class Student{
// public:  //类包含的变量
//     char *name;
//     int age;
//     float score;

// public:  //类包含的函数
//     void say(){
//         printf("%s的年龄是 %d，成绩是 %f\n", name, age, score);
//     }
// };

// int main(){
//     //创建对象
//     Student stu;
//     stu.name = "小明";
//     stu.age = 15;
//     stu.score = 92.5f;
//     stu.say();

//     //定义指针
//     Student *pt_stu = &stu;
//     pt_stu->name = "李雷";
//     pt_stu->age = 16;
//     pt_stu->score = 80;
//     pt_stu->say();

//     return 0;
// }














































































