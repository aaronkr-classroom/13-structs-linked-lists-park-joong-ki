#include <stdio.h>

//unsigned short int ���� US��� ���ο� �̸����� ���� ��
typedef unsigned short int US;

int main(void) {
	US data = 5;
	US temp;

	temp = data;
	printf("temp = %d\n", temp);

	return 0;
}