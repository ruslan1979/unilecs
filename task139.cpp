//дан массив целых чисел. Необходимо вычислить произведение чисел в массиве между минимальным и максимальным элементом. 
//Известно, что минимальный и максимальный элемент встречается в массиве только один раз.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//указываем количество элементов в массиве
	unsigned int n;
	cin >> n;
	vector<int> list(n);
	
	// заполняем массив
	for (unsigned int i = 0; i != n; ++i){
		cin >> list[i];
	}
	
	// определяем нахождение минимального и максимального элементов массива
	auto min_pos = min_element(list.begin(), list.end());
	auto max_pos = max_element(list.begin(), list.end());
	
	//рассчитываем произведение
	unsigned int mul = 1;
	for (auto it = min_pos + 1; it != max_pos; ++it) {
		mul *= *it;
	}
	
	cout << mul << endl;
}