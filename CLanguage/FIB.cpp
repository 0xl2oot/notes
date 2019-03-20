#define LOCAL
#include <iostream>
using namespace std;

#define NumMode 100000000

typedef struct BigInt{
	int num[3000];
	int digit_n;
}BigInt;

BigInt f[1001];

void calc(BigInt a, BigInt b, BigInt *c){
	int length_a = a.digit_n, length_b = b.digit_n;
	int count = 0;
	int sum_mark = 0;
	for(; count < length_a && count < length_b; count++){
		sum_mark += a.num[count] + b.num[count];
		c->num[count] = sum_mark % NumMode;
		sum_mark /= NumMode;
	}
	for(; count < length_a; count++){
		sum_mark += a.num[count];
		c->num[count] = sum_mark % NumMode;
		sum_mark /= NumMode;
	}
	for(; count < length_b; count++){
		sum_mark += b.num[count];
		c->num[count] = sum_mark % NumMode;
		sum_mark /= NumMode;
	}
	if(sum_mark){
		c->num[count++] = sum_mark;
	}
	c->digit_n = count;
}

void OutPut(BigInt n){
	int count = n.digit_n - 1;
	printf("%d",n.num[count--]);
	while(count >= 0){
		printf("%08d",n.num[count--]);
	}
	cout<<endl;
}
int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int input_num[1001], count_input = 0;
	int input_max = 0, count_calc = 1;
	BigInt fa, fb, fc;
	while (cin>>input_num[count_input] && input_num[count_input]) {
		input_max = input_num[count_input] > input_max ? input_num[count_input] : input_max;
		count_input++;
	}
	fa.num[0] = 1;
	fb.num[0] = 1;
	fa.digit_n = 1;
	fb.digit_n = 1;
	
	while (count_calc <= input_max) {
		if(count_calc <= 2)
			fc = fa;
		else
			calc(fa, fb, &fc);
		for(int count  = 0; count < count_input; count++){
			if(count_calc == input_num[count])
				f[count] = fc;
		}
		fa = fb;
		fb = fc;
		count_calc++;
	}
	
	for(int count = 0; count < count_input; count++){
		OutPut(f[count]);
	}
	return 0;
}