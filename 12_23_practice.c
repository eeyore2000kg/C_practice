#if 1
/*
1. Program name : project part1_02
2. ver 1.0
3. 작성자 : kyunggu
4. 기능 : 비트연산자 수행 및 정수를 이진수로 표현하여 비트 연산 확인 
5. 작성일 : 2022.12.24 
*/

/*
1. 주요 입출력 
	1) 입력 : 네개의 연산자 중 하나의 연산자 번호 선택, 피연산자인 정수값
	2) 출력 : 피연산자의 정수와 이진수, 결과의 정수와 이진수  
2. 주요 자료 - 정수형 변수 : 메뉴 선택 변수와 피연산자 변수 하나 또는 두개
3. 처리 
	1) 연산자 종류 선택 메뉴  
	2) 정수 x의 이진수 출력모드
	3. 프로그램 구조 : switch 또는 if문
*/

#include <stdio.h>
#include <string.h>  // strcpy strcat strncpy strncmp
#include <stdlib.h>  // atoi (ascii to integer) : ascii를 int변환 함수

int operator;
int i=0, j=0;
char input_op[10];	
char input_bits[100];	

void op_select(void);
void space_check(void);
void end_bits(void);
void express_bits(int a);

int main(void)
{
	int x,y;
	int cal;
	char input_op[10];	
	char ch_1[100], ch_2[100];

	while(1)
	{ 
	//연산 메뉴출력 
	op_select();
	 
	fgets(input_op,10,stdin);			//연산 메뉴 받기 

	operator = atoi(input_op);			//입력받은 char를 int로
	
	if(strncmp(input_op,"0",strlen("0")) == 0) 	//0 입력시 종료 
	{
		printf(" 연산을 종료합니다.\n");
		break; 
	}
	
	// 4번은 정수 하나만 받으므로 별도의 예외처리 
	if(strncmp(input_op,"4",strlen("4")) == 0) 	
	{
		printf("비트 보수(~) 연산할 하나의 정수 입력 >> "); 
		fgets(input_bits,100,stdin);

		space_check();			
		strcpy(ch_1,input_bits+i);
		x = atoi(ch_1);

			//비트 표현 x 
		printf("x = ");
		express_bits(x);
		printf("%8d\n",x);
			//비트 표현 ~ x
		printf("~x = ");
		cal = ~x;
		express_bits(cal);
		printf("%8d\n",cal);
	
		continue;
	}

	printf("비트 연산할 두 정수 입력 >> ");
	fgets(input_bits,100,stdin);
	
	i=0; 
	space_check();
    strcpy(ch_1, &input_bits[i]); // a       b
	i++;
	end_bits();
	i++;
	
	space_check();	    	
	strncpy(ch_2, &input_bits[i],100-i);
	
	x = atoi(ch_1);
	y = atoi(ch_2);
	
	switch (operator)
	{
		default : 
			printf("잘못 선택하셨습니다. 다시해주세요.\n");
			continue;
	
		case 1:		// x & y
				//비트 표현 x 
			printf("x = ");
			express_bits(x);
			printf("%8d\n",x);
				//비트 표현 y
			printf("y = ");
			express_bits(y);
			printf("%8d\n",y);
				//비트 표현 x&y
			printf("x & y = ");
			cal = x & y;
			express_bits(cal);
			printf("%8d\n",cal);
			
			break;

		case 2:		// x | y
				//비트 표현 x 
			printf("x = ");
			express_bits(x);
			printf("%8d\n",x);
				//비트 표현 y
			printf("y = ");
			express_bits(y);
			printf("%8d\n",y);
				//비트 표현 x | y
			printf("x | y = ");
			cal = x | y;
			express_bits(cal);
			printf("%8d\n",cal);
			
			break;
			
		case 3:		// x ^ y
				//비트 표현 x 
			printf("x = ");
			express_bits(x);
			printf("%8d\n",x);
				//비트 표현 y
			printf("y = ");
			express_bits(y);
			printf("%8d\n",y);
				//비트 표현 x ^ y
			printf("x ^ y = ");
			cal = x ^ y;
			express_bits(cal);
			printf("%8d\n",cal);
			
			break;
				 
	}
	
	}
	return 0; 
}

void op_select()
{
	printf("\t [1] 비트 AND(&)\n"); 
	printf("\t [2] 비트 OR(|)\n"); 
	printf("\t [3] 비트 XOR(^)\n"); 
	printf("\t [4] 비트 COMPLEMENT(~)\n"); 
	printf("\t [0] 종료 STOP\n"); 
	printf("위 연산 중 하나를 선택하세요 >> ");
}

void space_check(void)  // 리턴되는겂도  없고 매개변수(argument)  
{
   for (; i < 100; i++)
   {
   	  	if (input_bits[i] != ' ')
   	  		break;
   }
   	
}

void end_bits(void)
{
	for(; i<100; i++)
	{
		if(input_bits[i] == ' ')
		break;
	}
	
}

void express_bits(int a)
{
	for( j=31; j>0; j--)
	{
		printf("%c", ((a >> j)&1) ? '1': '0' );
		if(j%4 == 0)
		{
			printf(" ");
		}
	}
	printf("%c", (a & 1)? '1': '0');
}

#endif 

