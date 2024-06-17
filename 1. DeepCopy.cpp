#include "PW.h"

#include "vector"

// Клас "Пункт" с хранением Названия и Номера облости
class Point
{
public:
	// Пустой конструктор
	Point() {}
	/* Примечание:
	* Пустой конструктор необходим для осуществления
	* предварительтного резервирования памяти:
	* Вызов vector.resize()
	*/

	// Конструктор с освобождением памяти при повторном вызове
	Point(const char inName, const int& inNum)
	{
		NamePoint = inName;
		AreaNumber = new int(inNum);
	}

	// Перегрузка копирования (на основе присвоения)
	Point(const Point& inPoint)
	{
		*this = inPoint;
	}
	/* Примечание:
	* Ключевое слово "const" обязательно -- C2558
	*/

	// Деструктор с освобождением памяти
	~Point()
	{
		//std::cout << "Деструктор: " << NamePoint << '\n';
		FDelete();
	}

	// Оператор присвоения
	Point& operator=(const Point& inPoint)
	{
		if (&inPoint != this)
		{
			// Освобождение занимаемой дин.памяти
			FDelete();

			// Присвоение новых значений
			NamePoint = inPoint.NamePoint;
			AreaNumber = new int(*inPoint.AreaNumber);
		}
		return *this;
	}

	// Дружественная ф-ция для вывода на консоль
	friend std::ostream& operator<<(std::ostream& out, const Point& inPoint)
	{
		if (inPoint.AreaNumber)
		{
			out
				// Имя точки
				<< inPoint.NamePoint
				// Номер области
				<< " : " << *inPoint.AreaNumber
				// Указатель (Используемая ячейка памяти)
				<< " (" << inPoint.AreaNumber << ')';
		}

		return out;
	}

private:
	// Имя точки
	char NamePoint = 0;
	// Указатель на неомер области
	int* AreaNumber = nullptr;

	// Ф-ция освобождения памяти (с перспективой на расширение)
	void FDelete()
	{
		delete AreaNumber;
	}
};

// Функция вывода каждого элемента в консоль
auto print = [](const Point& elem)
{
	std::cout << elem << '\n';
};



int main1()
{
	/*---   Проверка работоспособности класса Point   ---*/
	std::cout << "Проверка работоспособности класса Point с \"Deep Copy\":\n\n";

	std::cout << "1. Инициализация:\n";
	int Ar00 = 00;
	int Ar45 = 45;
	int Ar83 = 83;

	Point P_A('A', Ar00);
	Point P_B('B', Ar45);
	Point P_C('C', Ar83);

	std::cout << "P_A : " << P_A << '\n';
	std::cout << "P_B : " << P_B << '\n';
	std::cout << "P_C : " << P_C << '\n';
	std::cout << std::endl;



	std::cout << "2. Копирование ( P_D = P_C ) :\n";
	Point P_D = P_C;
	std::cout << "P_D : " << P_D << '\n';

	std::cout << std::endl;



	std::cout << "3. Присвоение ( P_C = P_B ) :\n";
	P_C = P_B;

	std::cout << "P_B : " << P_B << '\n';
	std::cout << "P_C : " << P_C << '\n';

	std::cout << std::endl;
	//=============================================================



	std::cout
		<< "=============================================================\n"
		<< std::endl;

	std::cout << "Демонстрация std::copy для vector<Point>:\n\n";

	std::cout << "1. Инициализация с присвоением ( VP1 ):\n\n";

	int Ar91 = 91;

	std::vector<Point> VP1;
	VP1.push_back(P_A);
	VP1.push_back(Point('F', Ar91));
	VP1.push_back(P_B);
	VP1.push_back(P_C);
	VP1.push_back(P_D);

	// Вывод каждого элемента
	std::cout << "Вывод VP1 через for_each:\n";
	std::for_each(VP1.begin(), VP1.end(), print);

	std::cout << std::endl;



	std::cout << "2. Копирование std::copy ( VP2 = VP1 ):\n\n";

	// Инициализация
	std::vector<Point> VP2;

	// Изменение размера VP2
	VP2.resize(VP1.size());
	std::cout << "VP2.resize:\n";
	std::cout << "VP1.size() = " << VP1.size() << '\n';
	std::cout << "VP2.size() = " << VP2.size() << '\n';

	std::cout << std::endl;

	// Копирование всех элементов
	std::copy(VP1.begin(), VP1.end(), VP2.begin());

	// Вывод каждого элемента
	std::cout << "Вывод VP2 через for_each:\n";
	std::for_each(VP2.begin(), VP2.end(), print);

	std::cout << std::endl;


	return 0;
}