#if 1
/*
1. Program name : project part1_02
2. ver 1.0
3. �ۼ��� : kyunggu
4. ��� : ��Ʈ������ ���� �� ������ �������� ǥ���Ͽ� ��Ʈ ���� Ȯ�� 
5. �ۼ��� : 2022.12.24 
*/

/*
1. �ֿ� ����� 
	1) �Է� : �װ��� ������ �� �ϳ��� ������ ��ȣ ����, �ǿ������� ������
	2) ��� : �ǿ������� ������ ������, ����� ������ ������  
2. �ֿ� �ڷ� - ������ ���� : �޴� ���� ������ �ǿ����� ���� �ϳ� �Ǵ� �ΰ�
3. ó�� 
	1) ������ ���� ���� �޴�  
	2) ���� x�� ������ ��¸��
	3. ���α׷� ���� : switch �Ǵ� if��
*/

#include <stdio.h>
#include <string.h>  // strcpy strcat strncpy strncmp
#include <stdlib.h>  // atoi (ascii to integer) : ascii�� int��ȯ �Լ�

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
	//���� �޴���� 
	op_select();
	 
	fgets(input_op,10,stdin);			//���� �޴� �ޱ� 

	operator = atoi(input_op);			//�Է¹��� char�� int��
	
	if(strncmp(input_op,"0",strlen("0")) == 0) 	//0 �Է½� ���� 
	{
		printf(" ������ �����մϴ�.\n");
		break; 
	}
	
	// 4���� ���� �ϳ��� �����Ƿ� ������ ����ó�� 
	if(strncmp(input_op,"4",strlen("4")) == 0) 	
	{
		printf("��Ʈ ����(~) ������ �ϳ��� ���� �Է� >> "); 
		fgets(input_bits,100,stdin);

		space_check();			
		strcpy(ch_1,input_bits+i);
		x = atoi(ch_1);

			//��Ʈ ǥ�� x 
		printf("x = ");
		express_bits(x);
		printf("%8d\n",x);
			//��Ʈ ǥ�� ~ x
		printf("~x = ");
		cal = ~x;
		express_bits(cal);
		printf("%8d\n",cal);
	
		continue;
	}

	printf("��Ʈ ������ �� ���� �Է� >> ");
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
			printf("�߸� �����ϼ̽��ϴ�. �ٽ����ּ���.\n");
			continue;
	
		case 1:		// x & y
				//��Ʈ ǥ�� x 
			printf("x = ");
			express_bits(x);
			printf("%8d\n",x);
				//��Ʈ ǥ�� y
			printf("y = ");
			express_bits(y);
			printf("%8d\n",y);
				//��Ʈ ǥ�� x&y
			printf("x & y = ");
			cal = x & y;
			express_bits(cal);
			printf("%8d\n",cal);
			
			break;

		case 2:		// x | y
				//��Ʈ ǥ�� x 
			printf("x = ");
			express_bits(x);
			printf("%8d\n",x);
				//��Ʈ ǥ�� y
			printf("y = ");
			express_bits(y);
			printf("%8d\n",y);
				//��Ʈ ǥ�� x | y
			printf("x | y = ");
			cal = x | y;
			express_bits(cal);
			printf("%8d\n",cal);
			
			break;
			
		case 3:		// x ^ y
				//��Ʈ ǥ�� x 
			printf("x = ");
			express_bits(x);
			printf("%8d\n",x);
				//��Ʈ ǥ�� y
			printf("y = ");
			express_bits(y);
			printf("%8d\n",y);
				//��Ʈ ǥ�� x ^ y
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
	printf("\t [1] ��Ʈ AND(&)\n"); 
	printf("\t [2] ��Ʈ OR(|)\n"); 
	printf("\t [3] ��Ʈ XOR(^)\n"); 
	printf("\t [4] ��Ʈ COMPLEMENT(~)\n"); 
	printf("\t [0] ���� STOP\n"); 
	printf("�� ���� �� �ϳ��� �����ϼ��� >> ");
}

void space_check(void)  // ���ϵǴ���  ���� �Ű�����(argument)  
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

