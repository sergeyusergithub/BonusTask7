#include <iostream>

bool prime_number(int n) {
	static int k = n;
	if (k == 2)
		return true;
	if (n == 2)
		if (k % 2 == 0)
			return false;
		else
			return true;
	if (k % (n - 1) == 0)
		return false;
	else
		return prime_number(n - 1);
}

int reverse(int n) {
	int k = 1;
	int m = n;
	if (n < 10)
		return n;
	while (m > 9) {
		k = k * 10;
		m = m / 10;
	}
	return n % 10 * k + reverse(n / 10);

}

void brakets(int n) {
	if (n == 1)
		std::cout << "()";
	else {
		std::cout << "(";
		brakets(n - 1);
		std::cout << ")";
	}
	
}

void progression(int f, int k, int n) {

	if (n == 0)
		std::cout << "\n\n";
	else
	{
		std::cout << f << " ";
		f = f * k;
		progression(f, k, n - 1);
	}
	
}

int nums_sum(int n) {
	if (n < 10)
		return n;
	return n % 10 + nums_sum(n / 10);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Рекурсивная функция возвращающая true есил число простое
	std::cout << "Задача 1.\nВведите число -> ";
	std::cin >> n;

	if (prime_number(n))
		std::cout << "Число простое!\n\n";
	else
		std::cout << "Число не простое!\n\n";

	// Задача 2. Рекурсивная функция возвращающая зеркальное отражение числа
	std::cout << "Задача 2.\nВведите число -> ";
	std::cin >> n;

	std::cout << "Зеркальная копия числа: " << reverse(n) << "\n\n";

	// Задача 3. Рекурсивная функция выводящая вложенные круглые скобки
	std::cout << "Задача 3.\nВведите число -> ";
	std::cin >> n;

	brakets(n);
	std::cout << "\n\n";

	// Задача 4. Рекурсивная функция возвращающая сумму цифр введенного числа
	std::cout << "Задача 4.\nВведите число -> ";
	std::cin >> n;

	std::cout << "Сумма цифр: " << nums_sum(n) << "\n\n";

	// Задача 5. Рекурсивная функция выводящая числа прогрессии.
	std::cout << "Задача 5.\nВведите начало прогрессии -> ";
	int f, k;
	std::cin >> f;
	std::cout << "Введите множитель прогрессии -> ";
	std::cin >> k;
	std::cout << "Введите количество членов прогрессии -> ";
	std::cin >> n;

	std::cout << "Геометрическая прогрессия:\n";
	progression(f, k, n);

	return 0;
}