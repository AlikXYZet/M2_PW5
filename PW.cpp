#include "PW.h"

// ����� ������������ �� ���������
int DefaultSelection = 1;
// ���������� ������������
int MaxSelection = 3;

bool MainSelection(int& sel)
{
	switch (sel)
	{
	case 1:
		main1();
		break;

	case 2:
		main2();
		break;

	case 3:
		main3();
		break;

	default:
		std::cout << "������������ ����. ����� �� ��������� : "
			<< DefaultSelection
			<< '\n'
			<< std::endl;;
		return true;
		break;
	}

	return false;
}

int main()
{
	// �����������
	setlocale(LC_ALL, "Russian");
	// <iomanip>: ������������ �� ������ ����
	std::cout << std::setiosflags(std::ios::left);
	// ������������ ������� ����� � �������� ���������� �������� ��� ���������� ��������������� �����
	srand(time(0));

	std::cout << "������ ������������� ����������:\n"
		<< "1. Deep Copy (\"��������\" �����������)\n"
		<< "2. Copy  ���  std::unordered_map\n"
		<< "3. Fill  ��� ���������� ������� ������ �������\n"
		<< '\n';

	std::cout << "�������� ����������� ��������: ";
	int Selection;
	std::cin >> Selection;
	std::cout << std::endl;

	DefaultSelection = ((DefaultSelection - 1) % MaxSelection) + 1;

	if (MainSelection(Selection))
		MainSelection(DefaultSelection);

	return 0;
}