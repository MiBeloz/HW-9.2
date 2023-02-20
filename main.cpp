#include "main.h"


int main() {
	setlocale(LC_ALL, "ru");

	Fraction f1;
	Fraction f2;
	Fraction f3;

	int num = 1;
	while (true) {
		std::cout << "Операции с дробями.\n" << std::endl;

		enterFraction(f1, num++);
		enterFraction(f2, num--);

		std::cout << "\n\t" << f1 << " + " << f2 << " = ";
		f3 = f1 + f2;
		std::cout << f3 << std::endl;

		std::cout << "\t" << f1 << " - " << f2 << " = ";
		f3 = f1 - f2;
		std::cout << f3 << std::endl;

		std::cout << "\t" << f1 << " * " << f2 << " = ";
		f3 = f1 * f2;
		std::cout << f3 << std::endl;

		try {
			std::cout << "\t" << f1 << " / " << f2 << " = ";
			f3 = f1 / f2;
			std::cout << f3 << std::endl << std::endl;
		}
		catch (const std::exception& ex) {
			std::cerr << ex.what() << std::endl;
		}
		

		std::cout << "\t" << "++" << f1 << " * " << f2 << " = ";
		f3 = ++f1 * f2;
		std::cout << f3 << std::endl;
		std::cout << "\t" << "Значение дроби 1 = " << f1 << std::endl << std::endl;

		std::cout << "\t" << f1 << "-- * " << f2 << " = ";
		f3 = f1-- * f2;
		std::cout << f3 << std::endl;
		std::cout << "\t" << "Значение дроби 1 = " << f1 << std::endl << std::endl << std::endl;
	}

	return 0;
}

void enterFraction(Fraction& f, const int num) {
	int numerator{}, denominator{};
	const int MaxNum = 10000;

	std::cout << "\tВведите числитель дроби " << num << ": ";
	while (true) {
		std::cin >> numerator;
		if (numerator < -MaxNum || numerator > MaxNum) {
			std::cout << "\tЧислитель должен быть не меньше " << -MaxNum << " и не больше " << MaxNum << "! Введите еще раз : ";
		}
		else {
			break;
		}
	}

	std::cout << "\tВведите знаменатель дроби " << num << ": ";
	while (true) {
		std::cin >> denominator;
		if (denominator < -MaxNum || denominator > MaxNum) {
			std::cout << "\tЗнаменатель должен быть не меньше " << -MaxNum << " и не больше " << MaxNum << "! Введите еще раз : ";
		}
		else {
			break;
		}
	}

	try {
		Fraction temp(numerator, denominator);
		f = temp;
	}
	catch (const std::exception& ex) {
		std::cerr << "\t" << ex.what() << std::endl;
		std::cout << "\tВместо дроби будет создано число по умолчанию - 0." << std::endl;
		Fraction temp;
		f = temp;
	}
}