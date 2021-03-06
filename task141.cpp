//Задача: математики придумали свою версию лотереи. На лотерейном билете указана прямоугольная числовая матрица N*M, 
//также есть скрытая часть, где указаны координаты ячейки X. Есть четыре возможных выигрышных направления: вверх, 
//вниз, влево и вправо. Направление считается выигрышным, если все числа в этом направлении от ячейки X строго меньше 
//числа в самой ячейке X. Если ячейка X находится на краю матрицы, то вы автоматически имеете выигрышное направление.
//
//Необходимо выбрать такой лотерейный билет, ктр имеет максимальное общее кол-во выигрышных направлений для всех возможных 
//игровых ячеек (определить только по исходной матрице, скрытая часть ест-но вам неизвестна).
//
//Входные данные: arr - числовая матрицы N*M, эл-ты матрицы - натуральные числа от 1 до 10^3. N,M от 1 до 100.
//
//Вывод: вывести общее кол-во выигрышных направлений для заданной таблицы.
//
//Пример: 
//
//[ { 6, 4, 10, 11 },
//   { 2, 9, 9, 3 },
//   { 5, 4, 5, 4 } ]
//
//Answer: 25

#include <iostream>
using namespace std;

// определение количества возможных шагов
int number_of_steps(int lottery[100][100], int n, int m) {
	int count = 0;
    
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != m; ++j) {
			// если это любая точка кроме в начале ряда или колонки
			int cell = lottery[i][j];
			bool is_won = true; // ряд по умолчанию выигрышный
			
				
			//если крайняя правая точка, то вправо уже не идти. увеличиваем счетчик
			if (j == m - 1)
				++count;
			else {
				//идти вправо до конца ряда
				for (int k = j + 1; k != m; ++k)
					if (cell <= lottery[i][k]) {
						// ряд проигрышный
						is_won = false;
						// дальше нет смысла идти. завершаем цикл
						break;
					}
				// если ряд выигрышный, то увеличиваем счетчик хода.
				count += is_won ? 1 : 0;
			}
			
			is_won = true;
			// если крайняя левая точка, то левее уже не идти. увеличение счетчика
			if (j == 0)
				++count;
			else {
				//идти влево до конца ряда
				for (int k = j - 1; k != -1; --k)
					if (cell <= lottery[i][k]) {
						// ряд проигрышный
						is_won = false;
						// дальше нет смысла идти. завершаем цикл
						break;
					}
				// если ряд выигрышный, то увеличиваем счетчик хода.
				count += is_won ? 1 : 0;
			}
			
			is_won = true;
			// если крайняя верхняя точка, то выше уже не поднимешься
			if (i == 0)
				++count;
			else {
				// идти вверх до конца столбца
				for (int k = i - 1; k != -1; --k)
					if (cell <= lottery[k][j]) {
						// ряд проигрышный
						is_won = false;
						// дальше нет смысла идти. завершаем цикл
						break;
					}
				// если ряд выигрышный, то увеличиваем счетчик хода.
				count += is_won ? 1 : 0;
			}
			
			is_won = true;
			// если крайняя нижняя точка, то ниже не опуститься
			if (i == n - 1)
				++count;
			else {
				// идти вниз до конца столбца
				for (int k = i + 1; k != n; ++k)
					if (cell <= lottery[k][j]) {
						// ряд проигрышный
						is_won = false;
						// дальше нет смысла идти. завершаем цикл
						break;
					}
				// если ряд выигрышный, то увеличиваем счетчик хода.
				count += is_won ? 1 : 0;
			}
		}
	
	return count;
} 

// Ввод: числа n, m
// Элементы матрицы в n рядов и m колонок
// Например:
//
//               3 4
//               6 4 10 11
//               2 9 9 3
//               5 4 5 4
// Вывод: 25

int main() {
	// your code goes here
	int n, m;
	//задаем размеры матрицы
	cin >> n >> m;
	//формируем матрицу
	int matrix[100][100];

	//заполняем значения
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != m; ++j) {
			cin >> matrix[i][j];
		}
		
	// вывод ответа - максимальное количество возможных ходов	
    cout << number_of_steps(matrix, n, m) << endl;
	return 0;
}