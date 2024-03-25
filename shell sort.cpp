#include<iostream>
#include<ctime>
using namespace std;
int main() {
	srand(time(NULL));
	int s;
	cout << "Enter size of array" << endl;
	cin >> s;
	int* arr = new int[s];
	for (int i = 0; i < s; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int g = s / 2; g >= 1; g /= 2) {
		for (int i = g; i < s; i++) {
			for (int j = i; (j >= g )&& (arr[j - g]) > arr[j]; j -= g) {
				swap(arr[j], arr[j - g]);
			}
		}

	}
	cout << "\n" << "Result: " << endl;
	for (int i = 0; i < s; ++i)
		cout << arr[i] << " ";
	cout << endl;
	delete[] arr;
}