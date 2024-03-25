#include <iostream>
#include <ctime>
using namespace std;
// СОРТУВАННЯ БУЛЬБАШКОЮ
/*int main()
{
	srand(time(NULL));

	const int size = 5;
	int a[size];

	
	cout << "First array: " << endl;
	for (int i = 0; i < size; ++i)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;

	// Сортування
	int count = 0;     // К-сть проходів
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				count++;
			}
		}
	}

	// Вивід
	cout << "\n" << "Result: " << endl;
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;
	}*/
	// СОРТУВАННЯ ВИБОРОМ
/*int main() {

	srand(time(NULL));

	const int size = 5;
	int b[size];
	for (int i = 0; i < size; ++i) {
		b[i] = rand() % 10;
		cout << b[i]<<endl;
	}
	int min = 99, indx = -1, count = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i; j < size; ++j) {
			if (min > b[j]) {
				min = b[j];
				indx = j;
			}
		}
		swap(b[i],b[indx]);
		count++;
		min = 99;
		
	}
	cout <<"\n" << "Result" << endl;
	for (int i = 0; i < size; ++i) {
		cout << b[i] << endl;
	}
}*/
// СОРТУВАННЯ ВКЛЮЧЕННЯМ
/*int main() {
	srand(time(NULL));
	const int size = 5;
	int a[size];

	for (int i = 0; i < size; ++i) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
		
	}
	cout << endl;

	for (int i = 0; i < size; ++i) {
		int v = a[i];
		int j = i - 1;
		for ( ;j >=0 && a[j] > v; --j) {
			a[j + 1] = a[j];
			
		}
		a[j + 1] = v;
	}
	for (int i = 0; i < size; ++i) {
		cout << a[i] << " ";
	}

}*/