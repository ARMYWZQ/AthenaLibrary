#include <iostream>
#include "ABigNum.h"

int main()
{
	athena::ABigNum num(1), result(1);   /*�����������������ͱ���num��result��������ֵ1*/
	std::cout << "��10����" << result << "������\n";
	for (int i = 0; i < 9; i++)
	{
		result += num;
		result *= result;
		std::cout << "��" << 9 - i << "����" << result << "������\n";
	}

	return 0;
}