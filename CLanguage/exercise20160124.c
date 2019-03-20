/* Programming Exercise 2-4  */
//#include <stdio.h>
//void jolly(void);
//void deny(void);
//int main(void)
//{
//    jolly();
//    jolly();
//    jolly();
//    deny();
//    return 0;
//}
//void jolly(void)
//{
//    printf("For he's a jolly good fellow!\n");
//}
//void deny(void)
//{
//    printf("Which nobody can deny!\n");
//}

//#include <stdio.h>
//int main()
//{
//    printf("\007");
//    return 0;
//}

//这是注释,仅供测试

//#include <stdio.h>
//int main(void)
//{
//    float weight;
//    float value;
//    printf("Are you worth your weight in rhodium?\n");
//    printf("Let's check it out.\n");
//    printf("Please enter your weight in pounds:");
//    scanf("%f",&weight);
//    value = 770 * weight * 14.5833;
//    printf("Your weight in rhodium is worth $%f.\n",value);
//    printf("You are easily worth that! If rhodium prices drop.\n");
//    printf("eat more to maintain your value");
//    return 0;
//}


//#include <stdio.h>
//int main(void)
//{
//    printf("这是中文,仅用于测试");
//    printf("这是怎么了?");
//    return 0;
//}

// #include <stdio.h>
// int main(void)
// {
// 	;
// 	return 0;
// }



//C的数据关键字
//K&R int long short unsigned char float double
//C90 signed void
//C99 _Bool _Complex _Imaginary

// #include <stdio.h>
// int main(void)
// {
// 	int x = 100;
// 	printf("dec = %d ; octal = %o ; hex = %x\n",x,x,x);
// 	printf("dec = %#d ; octal = %#o ; hex = %#x",x,x,x);
// 	return 0;
// }

// #include <stdio.h>
// int main(void)
// {
// 	unsigned int un = 3000000000;
// 	short end = 200;
// 	long big = 65537;
// 	long long verybig = 12345678908642;
// 	printf("un = %u and not %d\n",un,un);
// 	printf("end = %hd and not %d\n",end,end);
// 	printf("big = %ld and not %hd\n",big,big);
// 	printf("verybig = %lld and not %ld\n",verybig,verybig);
// 	return 0;
// }

// #include <stdio.h>
// int main(void)
// {
// 	float aboat = 32000.0;
// 	double abet = 2.14e9;
// 	double dip = 5.32e-5;
// 	printf("%f can be written %e\n",aboat,aboat);
// 	printf("%f can be written %e\n",abet,abet);
// 	printf("%f can be written %e\n",dip,dip);
// 	return 0;
// }

// #include <stdio.h>
// int main(void)
// {
// 	float some;
// 	some = 4.0F * 2.0F;
// 	printf("%f\n",some);
// 	return 0;
// }

// #include <stdio.h>
// int main(void)
// {
// 	printf("Type int has a size of %u bytes.\n",sizeof(int));
// 	printf("Type char has a size of %u bytes.\n",sizeof(char));
// 	printf("Type long has a size of %u bytes.\n",sizeof(long));
// 	printf("Type double has a size of %u bytes.\n",sizeof(double));
// 	printf("Type long double has a size of %u bytes.\n",sizeof(long double));
// 	printf("Type long long int has a size of %u bytes.\n",sizeof(long long int));

// 	return 0;
// }


// #include <stdio.h>
// int main(void)
// {
// 	float salary;
// 	printf("\aEnter your desired monthly salary: ");
// 	printf(" $_____\b\b\b\b\b");
// 	scanf("%f",&salary);
// 	printf("\n\t$%.2f a month is %.2f a year.",salary,salary*12.0);
// 	printf("\rGee!\n");
// 	return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #define DENSITY 62.4
// int main(void)
// {
// 	float volume,weight;
// 	int size,letters;
// 	char name[40];
// 	printf("Hi! What's your first name?\n");
// 	scanf("%s",name);
// 	printf("%s,what's your weight in pounds?\n");
// 	scanf("%f",&weight);
// 	size = sizeof name;
// 	letters = strlen(name);
// 	volume = weight / DENSITY;
// 	printf("Well,%s,your volume is %2.2f cubic feet.\n",name,volume);
// 	printf("Also,your first name has %d letters.\n",letters);
// 	printf("and we have %d bytes to store it in.\n",size);
// 	return 0;
// }



// #include <stdio.h>
// #define PRAISE "What a super marvelous name!"
// int main(void)
// {
// 	char name[40];

// 	printf("What's your name?\n");
// 	scanf("%s",name);
// 	printf("Hello,%s. %sn",name,PRAISE);
// 	return 0;
// }
// 





// #include <stdio.h>
// #include <string.h>
// #define PRAISE "What a super marvelous name!"
// int main(void)
// {
// 	char name[40];

// 	printf("What's your name?\n");
// 	scanf("%s",name);
// 	printf("Hello,%s. %s\n",name,PRAISE);
// 	printf("Your name of %d letters occupies %d memory cells.\n",strlen(name),sizeof name);
// 	printf("The phrase of phrase has %d letters and occupies %d memory cells.\n",strlen(PRAISE),sizeof PRAISE);

// 	return 0;
// }


// #include <stdio.h>
// #include <limits.h>
// #include <float.h>
// int main(void)
// {
// 	printf("Some number limits for this system:\n");
// 	printf("Biggest int: %d\n",INT_MAX);
// 	printf("Smallest unsigned long: %lld\n",LLONG_MIN);
// 	printf("One byte = %d bits on this system.\n",CHAR_BIT);
// 	printf("Largest double float: %e\n",DBL_MAX);
// 	printf("Smallest normal float: %e\n",FLT_MIN);
// 	printf("float precision = %d digits\n",FLT_DIG);
// 	printf("float epsilon = %e \n",FLT_EPSILON);
// 	return 0;
// }



//C++黑魔法
// #include <stdio.h>
// int main(void)
// {
// 	int x = 10;
// 	while(0 <---- x)
// 	{
// 		printf("%d\n",x);
// 	}
// 	return 0;
// }


//C黑魔法
#include <stdio.h>
int main(void)
{
	int x = 10;
	while(x --> 0)
	{
		printf("%d\n",x);
	}
	return 0;
}


















































