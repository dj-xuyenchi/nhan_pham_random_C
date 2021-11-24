#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
@Quang ANh
@PH19418
*/


// class nguoi choi
struct member 
{
	char name[10];  // ten
	unsigned int quantityChip;  // so luong chip co
	float cash = 10; // so tien // khoi dau co 10$
};
// Ham in thong tin nguoi choi
void showInfo(member *input)  // con tro den dia chi nguoi choi dang nhap
{
	printf("Ten nguoi choi: %s\n", (*input).name);
	printf("So luong chip hien dang co: %d\n", (*input).quantityChip);
	printf("So tien hien co: %0.2f$\n", (*input).cash);
}

//funtion mua chip gia 0.25/1chip
void buyChip(float *cash,unsigned int *quantityChip)
{ //pointer den dia chi member
	int quantityBuy;
	float limitChecker;
	printf("Gia Chip 0.25$/1 Chip\n");
	printf("Ban co %0.2f $\n", *cash);
	printf("Nhap So Luong Chip Muon Mua\n");
tryAgain:
	scanf("%d", &quantityBuy);  // nhap so chip muon mua
	limitChecker = quantityBuy * 0.25;  // tao mot bien la so tien can de mua so chip
	float cashEnough = limitChecker - *cash;
	if (limitChecker > *cash)  // kiem tra xem có du tien mua ko
	{
		printf("Khong Du Tien De Mua %d Chip Ban Con Thieu %0.2f$\n", quantityBuy, cashEnough);
		goto tryAgain;
	}
	*cash = *cash - quantityBuy * 0.25;
	*quantityChip += quantityBuy;
	printf("Mua Thanh Cong\n");
	printf("Ban Co %d Chip va %0.2f$\n", *quantityChip, *cash);
}
//funtion ban chip gia ban 0.2/1chip
void shellChip(float *cash,unsigned int *quantityChip)
{ //pointer den dia chi member
	int quantityShell;
	printf("Gia Ban Chip 0.2$/1 Chip\n");
	printf("Ban co %d Chip\n", *quantityChip);
	printf("Nhap So Luong Chip Muon Ban\n");
tryAgain:
	scanf("%d", &quantityShell);
	if (quantityShell > *quantityChip)  // kiem tra xem co du chip de ban ko
	{
		printf("Ban Khong co Du %d Chip De Ban\n", quantityShell);
		goto tryAgain;
	}
	*cash += quantityShell * 0.2;
	*quantityChip -= quantityShell;
	printf("Ban Thanh Cong\n");
	printf("Ban Co %d Chip va %0.2f$\n", *quantityChip, *cash);
}

//funtion test nhan pham
void nhanPham(unsigned int *quantity)
{
	*quantity -= 1;  // moi lan choi mat 1 chip

	int num1 = rand() % 10;   // tao random 3 so 
	int num2 = rand() % 10;
	int num3 = rand() % 10;
	//	int oneMore;// Phat nua??
	if (num1 == num2 && num1 == num3)  // neu 3 so giong nhau no hu cong 10 chip
	{
		printf("%d-%d-%d\n", num1, num2, num3);
		printf("No Hu~ +10 Chip\n");
		*quantity += 10;
		//return 10
	}
	else if (num1 == num2 || num1 == num3)    // 2 so giong nhau + 3 chip
	{
		if (num1 == num2)
		{
			printf("%d-%d %d\n", num1, num2, num3);
			printf("Trung Thuong +3 Chip\n");
			*quantity += 3;
			//return 3
		}
		else    // 2 so giong nhau + 3 chip
		{
			printf("%d %d %d\n", num1, num2, num3);
			printf("%d   %d\n", num1, num3);
			printf("Trung Thuong +3 Chip\n");
			*quantity += 3;
			//return 3
		}
	}
	else if (num2 == num3)  // 2 so giong nhau + 3 chip
	{
		printf("%d %d-%d\n", num1, num2, num3);
		printf("Trung Thuong +3 Chip\n");
		*quantity += 3;
	}
	else
	{
		printf("%d %d %d\n", num1, num2, num3);  // neu ko co so nao giong nhau thi ko cong chip
	}

	//		printf("Phat Nua??? go~ 1");
	//		scanf("%d", &oneMore);
	//		if (oneMore == 1){
	//		nhanPham();
	//		}else{
	//		}
}

// dang nhap hien thi manu lua chon
void memberMain(member *userName)
{
	srand(time(NULL)); // cmn phai dat o ham goi random no moi chiu chay
	char funtionChecker = NULL;
memberMain:

	printf("                   ***** Hello %s *****\n", (*userName).name);
	printf("                    1. Quay So\n");
	printf("                    2. Mua Chip\n");
	printf("                    3. Ban Chip\n");
	printf("                    4. Xem Thong Tin\n");
	printf("                    5. Dang Xuat\n");

tryAgain:
	scanf("%c", &funtionChecker);
	switch (funtionChecker)
	{
	case '1':
		printf("      1. Phat Mot\n");
		printf("      2. Nhieu Lan Mot\n");
		int checker;
		int timeRound;
		scanf("%d", &checker);
		if (checker == 1)
		{
			if ((*userName).quantityChip < 1)
			{
				printf("Khong Du Chip De Choi\n");
				goto memberMain;
			}
			nhanPham(&(*userName).quantityChip);
			goto memberMain;
		}
		else
		{
			printf("So lan quay\n");
			scanf("%d", &timeRound);
			if ((*userName).quantityChip < timeRound)
			{
				printf("Khong Du Chip De Choi\n");
				goto memberMain;
			}
			for (int i = 1; i < timeRound + 1; i++)
			{
				printf("Lan quay thu %d\n", i);
				nhanPham(&(*userName).quantityChip);
			}
			goto memberMain;
		}
		break;
	case '2':
		if ((*userName).cash > 0.25)
		{
			buyChip(&(*userName).cash, &(*userName).quantityChip);
			goto memberMain;
		}
		else
		{
			printf("So Du Tai Khoan Khong Du Toi Thieu 0.25$ Khong The Mua Chip Nap Tien Di\n");
			goto memberMain;
		}
		//
		break;
	case '3':
		if ((*userName).quantityChip >= 1)
		{
			shellChip(&(*userName).cash, &(*userName).quantityChip);
			goto memberMain;
		}
		else
		{
			printf("Chip Du Khong Co Vao Test Nham Pham Di\n");
			goto memberMain;
		}
		break;
	case '4':
		showInfo(&(*userName));
		goto memberMain;
		break;
	case '5':
		exit(0);
		break;
	default:
		printf("Hay Chon Chuc Nang\n");
		goto tryAgain;
		break;
	}
}

//void test1(member *abc){
//	(*abc).cash = 20;
//}
//void test2(member abc){
//	printf("%d",abc.cash);
//}

//Dang Nhap
void login()
{
	struct member loginUserMark; // tao mot bien class member lam mat na de truy xuat du lieu
	strcpy(loginUserMark.name, "Quang Anh");
	char userName[10];
	printf("                    User:\n ");
	
	//scanf("%c", &userName);
	memberMain(&loginUserMark);
//	showInfo(&loginUserMark);
}
//Dang Ky
void signIn()
{
}
//Menu main bat dau game
void menuMain()
{

	char funtionChecker;
	printf("                    *****Las Vegas*****\n");
	printf("                    1. Dang Nhap\n");
	printf("                    2. Dang Ky\n");
tryAgain:
	scanf("%c", &funtionChecker);
	fflush(stdin);
//	if (funtionChecker != 1 && funtionChecker != 2)
//	{
//		printf("Hay Chon Dung Chuc Nang\n");
//		goto tryAgain;
//	}
	switch (funtionChecker)
	{
	case '1':
		login();
		break;
	case '2':
		signIn();
		break;
	default:
		printf("Hay Chon Dung Chuc Nang\n");
		goto tryAgain;
		break;
	}
}

// main
int main()
{
	// struct member qa;
	// test1(&qa);

	// test2(qa);

	// FILE *filePointer;
	menuMain();
}
