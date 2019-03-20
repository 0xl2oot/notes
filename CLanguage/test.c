// #include <stdio.h>
// #include <conio.h>
// int main(void)
// {
// 	int i,a = 0, b = 0, c = 0;
// 	char ch;
// 	for(i = 0; i < 100; i++)
// 	{
// 		ch = getchar();
// 		if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
// 			a++;
// 		else if('0' <= ch && ch <= '9')
// 			b++;
// 		else
// 			c++;
// 	}
// 	printf("%d %d %d \n",a,b,c);
// 	getch();
// 	return 0;
// }



#include <stdio.h>
#include <malloc.h>
typedef struct 
{
	int a,b;
	int e;
}three;

typedef struct 
{
	three *elem;
	int length;
}list;

int main()
{
	list.*elem =(three)malloc(sizeof(list));
	return 0;
}