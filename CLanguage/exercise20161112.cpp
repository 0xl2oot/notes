//#define LOCAL
//#include <iostream>
//#include <math.h>
//using namespace std;
//void perm(char ch[],int s,int t)
//{
//	int i;
// 	if(s==t)
// 	{
//		for(i=0;i<=t;i++)
//	 	cout<<ch[i];
//		cout<<endl;
// 	}
// 	else
// 	{
//		for(i=s;i<=t;i++)
//		{
//	 		swap(ch[i],ch[s]);
//	 		perm(ch,s+1,t);
//	 		swap(ch[i],ch[s]);
//		}
// 	}
//}
//
//int main()
//{
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif
//	int i,n,m;
// 	char ch[1000];
// 	while(cin>>n)
// 	{
//		cin>>m;
//		for(i=0;i<m;i++)
//	 		cin>>ch[i];
//		perm(ch,0,m-1);
//		if(n) cout<<endl;
// 	}
//}


#define LOCAL
#include <iostream>
#include <algorithm>
#include "string.h"

#define Max 101

using namespace std;

int D[Max][Max];

int num;

int MaxSum(int num){
	int i, j;
	for(i = num - 1; i >= 1; i --)
		for(j = 1; j <= i; j ++){
			D[i][j] = max(D[i+1][j],D[i+1][j+1]) + D[i][j];
		}
	return D[1][1];
}
int main(int argc, char const *argv[])
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif	
	
	int i, j;
	while (cin>>num) {

		for(i = 1; i <= num; i ++)
			for(j = 1; j <= i; j ++)
				cin >> D[i][j];
		cout << MaxSum(num) << endl;
	}
	
	return 0;
}