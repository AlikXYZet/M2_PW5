#include "PW.h"

#include "unordered_map"

// Синоним для упрощения написания кода
typedef std::unordered_map<int, char> Cell;

auto print = [](const Cell::value_type& elem)
{
	std::cout << elem.first << " : " << elem.second << '\n';
};

int main2()
{
	std::cout << "1. Инициализация Cell_1:\n";

	Cell Cell_1;
	Cell_1.insert(Cell::value_type(59, 'A'));
	Cell_1.insert(Cell::value_type(35, 'B'));
	Cell_1.insert(Cell::value_type(89, 'C'));
	Cell_1.insert(Cell::value_type(45, 'D'));
	Cell_1.insert(Cell::value_type(3, 'E'));
	Cell_1.insert(Cell::value_type(15, 'F'));

	std::cout << "Cell_1.size() = " << Cell_1.size() << '\n';

	std::for_each(Cell_1.begin(), Cell_1.end(), print);

	std::cout << std::endl;



	std::cout << "2. Инициализация Cell_2:\n";

	Cell Cell_2;
	Cell_2.insert(Cell::value_type(9, 'q'));
	Cell_2.insert(Cell::value_type(5, 'w'));
	Cell_2.insert(Cell::value_type(8, 'e'));
	Cell_2.insert(Cell::value_type(4, 'r'));
	Cell_2.insert(Cell::value_type(3, 't'));
	Cell_2.insert(Cell::value_type(1, 'y'));

	std::cout << "Cell_2.size() = " << Cell_2.size() << '\n';

	std::for_each(Cell_2.begin(), Cell_2.end(), print);

	std::cout << std::endl;



	std::cout << "3. Копирование элементов Cell_1 в Cell_2:\n";

	Cell::iterator it;

	//std::copy(Cell_1.begin(), Cell_1.end(), std::inserter(Cell_2, it));

	std::for_each(Cell_2.begin(), Cell_2.end(), print);

	std::cout << std::endl;


	return 0;
}