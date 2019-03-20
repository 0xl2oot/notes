// // #define LOCAL
// // #include <iostream>

// // using namespace std;

// // #include <cstdio>
// // #include <cstring>
// // using namespace std;

// // int dp[110][110];
// // int n,a[110];
// // int dfs(int s,int r)
// // {
// // 	if(r-s < 2)
// // 		return 0;
// // 	if(dp[s][r] != -1)
// // 		return dp[s][r];
// // 	int _min=(1<<15)-1;
// // 	int cnt = 0;
// // 	for(int i = s+1; i < r; i++)
// // 	{
// // 		cnt = dfs(s,i) + dfs(i,r) + a[s]*a[i]*a[r];
// // 		if(cnt<_min)
// // 			_min=cnt;
// // 	}
// // 	return dp[s][r] = _min;
// // }

// // int main()
// // {
// // #ifdef LOCAL
// // 	freopen("input.txt","r",stdin);
// // #endif
// // 	while(cin>>n)
// // 	{
// // 		memset(dp,-1,sizeof(dp));
// // 		for(int i = 1; i <= n; i++)
// // 			cin>>a[i];
// // 		int cnt = dfs(1,n);
// // 		cout<<cnt<<endl;
// // 	}
// // 	return 0;
// // }


























// #define LOCAL
// #include <iostream> 
// #include <algorithm> 
// #include <string> 
//  using   namespace  std;

//  void  Perm( const   char   *  str)
//  {
//     if (str==NULL || *str==NULL) return; 
//     string s(str),b(str); 
//     int c=1; 
//     sort(s.begin(),s.end()); 
//     if(s==b)
//     {
//         cout<<c<<endl;
//         return;
//     }
//     for (;next_permutation(s.begin(),s.end());) 
//     { 
//         c++;
//         if(s==b)
//         {
//             cout<<c<<endl;
//             return;
//         } 
//     } 
// } 

//  int  main()
//  {
//     int i,n;
//     string str;
//     cin>>n;
//     for(i=0;i<n;i++)
//     {
//         cin>>str;
//         Perm(str.c_str());
//     }
//     return 0;
// }





// newcger





#include <stdio.h>
#include <string.h>

int main()
{
	char str[1005];
	int i,j;
	int len,flag1,flag2,flag3;
	while(~scanf("%s",str))
	{
		flag1 = flag2 = flag3 = 0;
		len = strlen(str);	// 求字符串长度
		for(i = 0; i < len; i++)
		{
			if(str[i] == ')' || str[j] == ']')
			{
				for(j = i; j >= 0; j--)
				{
					if(str[j] == ')')
					{
						flag1++;
						flag3++;
					}
					if(str[j] == '(')
					{
						flag1--;
						flag3--;
					}
					if(str[j] == ']')
					{
						flag2++;
						flag3++;
					}
					if(str[j] == '[')
					{
						flag2--;
						flag3--;
					}
					if(flag1 == 0 && flag2 == 0 && flag3 == 0)
						break;
				}
			}
			if(flag1 != 0 || flag2 != 0 || flag3 != 0)
			{
				printf("No!\n");
				break;
			}
		}
		if(flag1 == 0 && flag2 == 0 && flag3 == 0)
			printf("Yes!\n");
	}
	return 0;
}


