#include <stdio.h>
#define N 100

int main() {
	int n;
	float a[N], x;
	double v;
	
	// 输入数据
	printf("Please input n = \n");
	scanf("%d", &n);
	printf("Please input fator a0, a1, ..., a%d =\n", n);
	for(int i = 0; i <= n; i++)
		scanf("%f", &a[i]);
	printf("Please input x = \n");
	scanf("%f", &x);
	v = a[0];
	// 判断 k 是否等于 n
	for(int k = 1; k <= n; k++)
		v = x*v + a[k];
	printf("The answer is v = %lf", v);
	return 0;
}