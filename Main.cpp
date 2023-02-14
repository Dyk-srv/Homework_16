#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
	setlocale(LC_ALL, "Russian");
	

	// 16.1 Среднее арифметическое одномерного массива
	std::cout << "\t16.1 Среднее арифметическое одномерного массива\n";
	const int size1 = 10;
	int arr1[size1];
	int sum = 0, counter = 0;
	double ariph_mean;
	srand(time(NULL));
	std::cout << "Массив, заполненный случайными числами от 1 до 10:\n";
	for (int i = 0; i < size1; i++){
		arr1[i] = rand() % 10 + 1;				// [1,10]
		sum += arr1[i];
		std::cout << arr1[i] << "  ";
	}
	ariph_mean = double(sum) / size1;
	std::cout << "\n\nСреднее арифметическое = " << ariph_mean << '\n';
	for (int i = 0; i < size1; i++)
		if (arr1[i] < ariph_mean)
			counter++;
	std::cout << "Кол-во элементов, меньших среднего арифметического: " << counter << '\n';


	// 16.2 Суммирование квадратных матриц
	std::cout << "\n\t16.2 Суммирование квадратных матриц\n";
	const int size2 = 5;
	int mxA[size2][size2], mxB[size2][size2], mxC[size2][size2];
	std::cout << "\n\t   Матрица A:\n\n";
	for (int i = 0; i < size2; i++){
		for (int j = 0; j < size2; j++) {
		mxA[i][j] = rand() % 10 + 1;				// [1,10]
		std::cout << mxA[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << "\n\t   Матрица B:\n\n";
	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size2; j++) {
			mxB[i][j] = rand() % 10 + 1;			// [1,10]
			std::cout << mxB[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << "\n\tМатрица C = A + B:\n\n";
	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size2; j++) {
			mxC[i][j] = mxA[i][j] + mxB[i][j];
			std::cout << mxC[i][j] << '\t';
		}
		std::cout << '\n';
	}

	// 16.3 Цифры числа в одномерный массив
	const int size3 = 6;
	int arr3[size3];
	int n, copy_n, length = 0;
	std::cout << "\n\t16.3 Цифры числа в одномерный массив\nВведите " << size3 <<"-значное число -> ";
	std::cin >> n;
	copy_n = n;
	counter = 0;
	do {
		copy_n /= 10;
		length++;
	} while (copy_n);			
	if (length == size3) {
		std::cout << "\nЗаполненный массив:\n";
		for (int i = 0; i < size3; i++) {
			if (n < 0 && i > 0)			// Для 2-й и последующих цифр отрицательного числа
				arr3[i] = abs(n / (int)pow(10, size3 - 1  - i) % 10);
			else 
				arr3[i] = n / (int)pow(10, size3 - 1 - i) % 10;
			std::cout << arr3[i] << ", ";
		}
		std::cout << "\b\b.\n";
	}
	else
		std::cout << "\nОшибка ввода!\n";

	return 0;
}