/*
* @Author: mm
* @Date:   2016-02-14 20:14:50
* @Last Modified by:   mm
* @Last Modified time: 2016-02-16 09:45:01
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define PASSWORD "admin"


typedef struct bookinfo
{
	char name[30];         	//书名
	char auther[20];		//作者
	float price;			//价格
	int page;				//页数
	bool isExit;			//是否被借出
}BOOKINFO;

char* print(bool isExit)
{
	if(isExit == true)
		return "true";
	else
		return "false";
}

char getchoice(void)
{
	char choice = getch(); 
	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
	{
		printf("Please input Y or N.\n");
		choice=getch();
	}
	return choice;
}

void password(void)
{
	int password_size = sizeof(PASSWORD);
	char password[password_size];
	while(1)
	{
		int i = 0;
		for(i = 0;i < password_size-1;i++)
		{
			password[i] = getch();
			printf("*");
		}
		password[i] = '\0';
		if(strcmp(password,PASSWORD) != 0)
			printf("\nPassword Wrong.Please try again\n");
		else
			break;
	}
	printf("\nLogin Successfully\n");
	system("pause");
}

void menu(void)
{
	printf("\n\n\n\n\n");
	printf("\t\t\tLibrary Management System\n\n");
	printf("\t\t0:Modify Book Information\n");
	printf("\t\t1:Enter New Books Basic Information\n");
	printf("\t\t2:Show All Records\n");
	printf("\t\t3:Inquiry Books Basic Information\n");
	printf("\t\t4:Delete Books Information\n");
	printf("\t\t5:Books Sorted by Name\n");
	printf("\t\t6:Books Sorted by Auther\n");
	printf("\t\t7:Books Sorted by Price\n");
	printf("\t\t8:List All Information of not Lent Books\n");
	printf("\t\t9:Quit System\n");
}

void choice_2_display_all();
void choice_0_modify_information()
{

	choice_2_display_all();
	FILE *pa;
	BOOKINFO bookinfoa[100];
	int booknumbera=0;
	int na;
	char choicea;
	pa=fopen("bookinfo.data","rb");
	while(!feof(pa))
	{
		fread(&bookinfoa[booknumbera],sizeof(BOOKINFO),1,pa);
		booknumbera++;
	}
	fclose(pa);
	booknumbera--;
	printf("\n\nEnter the number of the book you want to modify:\n");
	while(scanf("%d",&na) != 1 || na < 1 || na > booknumbera)
	{
		printf("Please enter a number!(1~%d)\n",booknumbera);
		while(getchar() != '\n');
	}
	while(getchar() != '\n');
	na--;
	printf("\n\n1. %-30s\n2. %-20s\n3. %-9.2f\n4. %-8d\n5. %s\n",
				bookinfoa[na].name,bookinfoa[na].auther,
				bookinfoa[na].price,bookinfoa[na].page,
				print(bookinfoa[na].isExit));
	printf("\n\nEnter the number you want to modify:\n");
	choicea = getchar();
	while(choicea != '1' && choicea != '2' && choicea != '3' && choicea != '4' && choicea != '5')
		printf("Please enter a number!(1~5)\n");
	
	switch(choicea)
	{
		case '1': 	printf("Input Book Name:");
					gets(bookinfoa[na].name);
					break;

		case '2': 	printf("Input Book Auther:");
					gets(bookinfoa[na].auther);
					break;

		case '3': 	printf("Input Book Price:");
					while(scanf("%f",&bookinfoa[na].price) != 1)
					{
						printf("Data Wrong! Please input the price of the book:\n");
						while(getchar()!='\n');
					}
					break;

		case '4': 	printf("Input Book Page:");
					while(scanf("%d",&bookinfoa[na].page) != 1)
					{
						printf("Data Wrong! Please input the page of the book:\n");
						while(getchar()!='\n');
					}
					break;

		case '5': 	if(bookinfoa[na].isExit)
						bookinfoa[na].isExit = false;
					else
						bookinfoa[na].isExit = true;
					printf("Changed!\n");
					getch();
					break;
	}

	pa=fopen("bookinfo.data","wb");
	for(int n=0;n<booknumbera;n++)
		fwrite(&bookinfoa[n],sizeof(BOOKINFO),1,pa);
	fclose(pa);
}

void choice_1_input_new()
{
	char choice;
	FILE *p;
	BOOKINFO newbook;

	system("cls");
	while(1)
	{
		printf("Input Book Name:");
		gets(newbook.name);

		printf("Input Book Auther:");
		gets(newbook.auther);

		printf("Input Book Price:");
		while(scanf("%f",&newbook.price) != 1)
		{
			printf("Data Wrong! Please input the price of the book:\n");
			while(getchar()!='\n');
		}
		

		printf("Input Book Page:");
		while(scanf("%d",&newbook.page) != 1)
		{
			printf("Data Wrong! Please input the page of the book:\n");
			while(getchar()!='\n');
		}
		while(getchar()!='\n');


		printf(" Save ?(Y/N)\n");
		choice = getchoice();

		if(choice=='Y'||choice=='y')
		{
			newbook.isExit = true;

			p=fopen("bookinfo.data","ab");
			fwrite(&newbook,sizeof(BOOKINFO),1,p);
			fclose(p);

			printf("\nSave Successfully!\n");
		}
		else
		{
			printf("\nSave Failed\n");
		}

		printf("\nContinue to input new?(Y/N)\n");
		choice = getchoice();


		if(choice=='Y'||choice=='y')
			continue;
		else
			break;
	}
}

void choice_2_display_all()
{
	FILE *p;
	int n;
	BOOKINFO bookinfo[100];
	int booknumber=0;

	system("cls");
	p=fopen("bookinfo.data","rb");
	while(!feof(p))
	{
		fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
		booknumber++;
	}
	
	fclose(p);
	booknumber--;

	if(booknumber==0)
	{
		printf("NONE BOOK INFORMATION!\n\n");
	}
	else
	{
		n=0;
		printf("                              BOOK INFORMATION\n");
		printf("   Name                           Auther               Price     Page     isExit\n");
		while(n<booknumber)
		{
			printf("%-3d%-30s %-20s %-9.2f %-8d %s\n",
				n+1,
				bookinfo[n].name,bookinfo[n].auther,
				bookinfo[n].price,bookinfo[n].page,
				print(bookinfo[n].isExit));
			n++;
		}
	}

}

void choice_3_search_according_name()
{
	char search[20]="";
	int n;
	FILE *p;
	char choice;
	BOOKINFO bookinfo[100];
	int booknumber=0;

	system("cls");
	p=fopen("bookinfo.data","rb");
	while(!feof(p))
	{
		fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
		booknumber++;    
	}
	booknumber--;
	fclose(p);

	while(1)
	{
		printf("Enter the name of the book you want to query:");
		gets(search);
		if(booknumber==0)
		{
			printf("No Information!\n\n");
			printf("Press any key to return main menu!\n\n");
			getch();
			break;    
		}
		else
		{
			for(n=0;n<booknumber;n++)
				if(strcmp(bookinfo[n].name,search)==0)
				{
					printf("Details of the book are as follows:\n");
					printf("   Name                           Auther               Price     Page     isExit\n");
					printf("%-3d%-30s %-20s %-9.2f %-8d %s\n",
							n+1,
							bookinfo[n].name,bookinfo[n].auther,
							bookinfo[n].price,bookinfo[n].page,
							print(bookinfo[n].isExit));
					break;                            
				}
				if(n>=booknumber)
					printf("Didn't find any information of the book!\n");
				printf("\n\nContinue to inquiry?(Y/N)\n");
				choice = getchoice();

				if(choice=='Y'||choice=='y')
					continue;
				else 
					break;              
		}
	} 
}

void choice_4_delete_according_name()
{
	char search[20]="";
	int n,i;
	FILE *p;
	char choice;
	BOOKINFO bookinfo[100];
	int booknumber;

	system("cls");
	while(1)
	{
		printf("Enter the name of the book you want to delete:");
		gets(search);
		p=fopen("bookinfo.data","rb");
		booknumber=0;

		while(!feof(p))
		{
			fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
			booknumber++;    
		}
		booknumber--;
		fclose(p); 
		if(booknumber==0)
		{
			printf("No Information!\n\n");
			printf("Press any key to return main menu!\n\n");
			getch();
			break;   
		}
		else
		{    
			for(n=0;n<booknumber;n++)
			{
				if(strcmp(bookinfo[n].name,search)==0)
				{
					break;
				}
			}

			if(n>=booknumber)
				printf("No Information!\n");
			else
			{
				printf("Delete this book? (Y/N)");
				choice = getchoice();

				if(choice=='Y'||choice=='y')      
				{
					for(i=n;i<booknumber-1;i++)
						bookinfo[i]=bookinfo[i+1];    
					booknumber--;

					p=fopen("bookinfo.data","wb");
					for(n=0;n<booknumber;n++)
						fwrite(&bookinfo[n],sizeof(BOOKINFO),1,p);
					fclose(p);

					printf("Successfully Deleted!\n");
				}
				else
					printf("\n\nDelete Failed!"); 
			}    

			printf("\n\nContinue to delete?(Y/N)\n");
			choice = getchoice();
			
			if(choice=='Y'||choice=='y')
				continue;
			else 
				break;              
		}
	}
}

void choice_5_sort_according_name()
{
	FILE *p;
	int m,n;
	BOOKINFO temp;
	BOOKINFO bookinfo[100];
	int booknumber;

	p=fopen("bookinfo.data","rb");
	booknumber=0;
	system("cls");
	while(!feof(p))
	{
		fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
		booknumber++;    
	}
	booknumber--;
	fclose(p);  
	if(booknumber==0)
	{
		printf("No Information!\n\n");
	}
	else
	{
		for(m=0;m<booknumber-1;m++)
		{
			for(n=m+1;n<booknumber;n++)
			{
				if(strcmp(bookinfo[m].name,bookinfo[n].name)>0)
				{
					temp=bookinfo[m];
					bookinfo[m]=bookinfo[n];
					bookinfo[n]=temp;    
				}
			}
		}
		p=fopen("bookinfo.data","wb");
		for(m=0;m<booknumber;m++)
			fwrite(&bookinfo[m],sizeof(BOOKINFO),1,p);
		fclose(p);        
		printf("\n\nSort Completed!\n\n");      
	}

	printf("Press any key to return main menu!\n");
	getch();  
}

void choice_6_sort_according_auther()
{
	FILE *p;
	int m,n;
	BOOKINFO temp;
	BOOKINFO bookinfo[100];
	int booknumber;

	p=fopen("bookinfo.data","rb");
	booknumber=0;
	system("cls");
	while(!feof(p))
	{
		fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
		booknumber++;    
	}
	booknumber--;
	fclose(p);  
	if(booknumber==0)
	{
		printf("No Information!\n\n");
	}
	else
	{
		for(m=0;m<booknumber-1;m++)
		{
			for(n=m+1;n<booknumber;n++)
			{
				if(strcmp(bookinfo[m].auther,bookinfo[n].auther)>0)
				{
					temp=bookinfo[m];
					bookinfo[m]=bookinfo[n];
					bookinfo[n]=temp;    
				}
			}
		}
		p=fopen("bookinfo.data","wb");
		for(m=0;m<booknumber;m++)
			fwrite(&bookinfo[m],sizeof(BOOKINFO),1,p);
		fclose(p);        
		printf("\n\nSort Completed!\n\n");      
	}

	printf("Press any key to return main menu!\n");
	getch();  
}

void choice_7_sort_according_price()
{
	FILE *p;
	int m,n;
	BOOKINFO temp;
	BOOKINFO bookinfo[100];
	int booknumber;

	p=fopen("bookinfo.data","rb");
	booknumber=0;
	system("cls");
	while(!feof(p))
	{
		fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
		booknumber++;    
	}
	booknumber--;
	fclose(p);  
	if(booknumber==0)
	{
		printf("No Information!\n\n");
	}
	else
	{
		for(m=0;m<booknumber-1;m++)
		{
			for(n=m+1;n<booknumber;n++)
			{
				if(bookinfo[m].price > bookinfo[n].price)
				{
					temp=bookinfo[m];
					bookinfo[m]=bookinfo[n];
					bookinfo[n]=temp;    
				}
			}
		}
		p=fopen("bookinfo.data","wb");
		for(m=0;m<booknumber;m++)
			fwrite(&bookinfo[m],sizeof(BOOKINFO),1,p);
		fclose(p);        
		printf("\n\nSort Completed!\n\n");      
	}

	printf("Press any key to return main menu!\n");
	getch();  
}

void choice_8_display_according_exitflag()
{
	FILE *p;
	int n;
	int count=0;
	BOOKINFO bookinfo[100];
	int booknumber;

	system("cls");
	booknumber=0;
	p=fopen("bookinfo.data","rb");
	while(!feof(p))
	{
		fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
		booknumber++;    
	}
	booknumber--;  
	fclose(p);
	if(booknumber==0)
	{
		printf("No Information!\n");
	}    
	else
	{
		for(n=0;n<booknumber;n++)
		{
			if(bookinfo[n].isExit==true)
				count++;
		}

		if(count==0)
			printf("All Lent !\n");        
		else
		{
			printf("Stacks of books borrowed has not been the following information:\n\n");
			printf("   Name                           Auther               Price     Page     isExit\n");
					
			for(n=0;n<booknumber;n++)
				if(bookinfo[n].isExit==true)
				{
					printf("%-3d%-30s %-20s %-9.2f %-8d %s\n",
							n+1,
							bookinfo[n].name,bookinfo[n].auther,
							bookinfo[n].price,bookinfo[n].page,
							print(bookinfo[n].isExit));    
				}    
		}   
	}  
	printf("\nPress any key to return main menu!\n");
	getch();  
}

int main()
{
	system("mode con: cols=90 lines=30");
	char choice;
	int tm;
	printf("Welcome to the library management system.\n\
		\nPlease enter the administrator password:\n");
	password();
	while(1)
	{
		system("cls");
		menu();
		choice=getch();
		switch(choice)
		{
		case '0':choice_0_modify_information();break;	
		case '1':choice_1_input_new();break;
		case '2':choice_2_display_all();
				printf("\n\nPress any key to return main menu!\n");
				getch();break;	
		case '3':choice_3_search_according_name();break;
		case '4':choice_4_delete_according_name();break;
		case '5':choice_5_sort_according_name();break;
		case '6':choice_6_sort_according_auther();break;
		case '7':choice_7_sort_according_price();break;
		case '8':choice_8_display_according_exitflag();break;
		case '9':system("cls");printf("\n\n\t\tThank you for your use, goodbye!\n");getch();return 0;
		default:
			printf("\n\n\t\tPlease enter the number in the menu!(0~9)");
			tm=clock();
			while(clock()<tm+1800);
			break;
		}
	}
    return 0;
}
