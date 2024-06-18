#include "PW.h"

#include "unordered_map"

// Синоним контейнера для упрощения написания кода
typedef std::unordered_map<int, std::string> Cell;

// Функция вывода каждого элемента в консоль
auto print = [](const Cell::value_type& elem)
{
	std::cout << elem.first << " : " << elem.second << '\n';
};

// Предикат для поиска по условию
auto checkValue = [](const Cell::value_type& elem)
{
	return elem.second == "B2";
};



int main2()
{
	/*---   Предварительная инициализация   ---*/
	// Итератор результата поиска
	Cell::iterator it;
	// Искомый элемент для std::find
	Cell::value_type Value = Cell::value_type(59, "A1");
	//--------------------------------------------------------



	std::cout << "1. Инициализация Cell_1:\n";

	Cell Cell_1;
	Cell_1.insert(Cell::value_type(59, "A1"));
	Cell_1.insert(Cell::value_type(35, "B2"));
	Cell_1.insert(Cell::value_type(89, "C3"));
	Cell_1.insert(Cell::value_type(45, "D4"));
	Cell_1.insert(Cell::value_type(3, "E5"));
	Cell_1.insert(Cell::value_type(15, "F6"));
	Cell_1.insert(Cell::value_type(60, "A1"));
	Cell_1.insert(Cell::value_type(36, "B2"));
	Cell_1.insert(Cell::value_type(90, "C3"));
	Cell_1.insert(Cell::value_type(46, "D4"));
	Cell_1.insert(Cell::value_type(4, "E5"));
	Cell_1.insert(Cell::value_type(16, "F6"));

	// Вывод размера контейнера
	std::cout << "\nCell_1.size() = " << Cell_1.size() << '\n';
	// Вывод элементов контейнера
	std::for_each(Cell_1.begin(), Cell_1.end(), print);

	std::cout << std::endl;



	std::cout << "2. Поиск элемента по значению ( std::find ):\n";

	it = std::find(Cell_1.begin(), Cell_1.end(), Value);

	// Вывод элемента, если он найден
	if (it != Cell_1.end())
		std::cout
		<< "Номер элемента: " << Cell_1.bucket(it->first) << '\n'
		<< it->first << " : " << it->second << '\n';
	else
		std::cout << "NONE";

	std::cout << std::endl;



	std::cout << "3. Поиск элементов по условию ( std::find_if ):\n";

	it = std::find_if(Cell_1.begin(), Cell_1.end(), checkValue);

	// Вывод элемента, если он найден
	if (it != Cell_1.end())
		std::cout
		<< "Номер элемента: " << Cell_1.bucket(it->first) << '\n'
		<< it->first << " : " << it->second << '\n';
	else
		std::cout << "NONE";

	std::cout << std::endl;



	return 0;
}