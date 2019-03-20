#define LOCAL
#include <stdio.h>
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif	
	int score[301][5];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		score[i][0] = i+1;
		scanf("%d%d%d",&score[i][1],&score[i][2],&score[i][3]);
		score[i][4] = score[i][1] + score[i][2] + score[i][3];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(score[i][4] < score[j][4])
			{
				int temp = score[i][0];
				score[i][0] = score[j][0];
				score[j][0] = temp;
				temp = score[i][1];
				score[i][1] = score[j][1];
				score[j][1] = temp;
				temp = score[i][4];
				score[i][4] = score[j][4];
				score[j][4] = temp;
			}
			if(score[i][4] == score[j][4])
			{
				if((score[i][1] < score[j][1]) || ((score[i][1] == score[j][1]) && (score[i][0] > score[j][0])))
				{
					int temp = score[i][0];
					score[i][0] = score[j][0];
					score[j][0] = temp;
					temp = score[i][1];
					score[i][1] = score[j][1];
					score[j][1] = temp;
					temp = score[i][4];
					score[i][4] = score[j][4];
					score[j][4] = temp;
				}
			}
			
		}
	}
	for(int i = 0; i < 5; i++)
		printf("%d %d\n",score[i][0],score[i][4]);
	return 0;
}