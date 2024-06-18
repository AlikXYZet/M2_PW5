#include "PW.h"

#include "vector"

// Синоним контейнера для упрощения написания кода
typedef std::vector<int> Array;

// Функция вывода каждого элемента в консоль
auto print = [](const Array::value_type& elem)
{
	std::cout << elem << ' ';
};



int main3()
{
	// Инициализация пустого массива (вектора)
	Array arr;

	// Присвоение размера массиву (вектору)
	arr.resize(10);
	std::cout << "arr.size() = " << arr.size() << "\n\n";

	std::cout << "Заполнение первых 5-ти элементов массива (вектора):\n";
	std::fill_n(arr.begin(), 5, 9);

	// Вывод элементов
	std::cout << "{ ";
	std::for_each(arr.begin(), arr.end(), print);
	std::cout << "}\n\n";

	std::cout << "Заполнение всех элементов массива (вектора):\n";
	std::fill(arr.begin(), arr.end(), 5);

	// Вывод элементов
	std::cout << "{ ";
	std::for_each(arr.begin(), arr.end(), print);
	std::cout << "}\n\n";

	return 0;
}