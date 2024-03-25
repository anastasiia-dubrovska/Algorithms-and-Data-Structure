#include <iostream>
#include <cmath>
#include<ctime>

using namespace std;

void RestoreHeap(int arr[], int f, int l)
{
    while (f <= l / 2)
    {
        int maxson = 2 * f;
        if (maxson + 1 <= l && arr[maxson] < arr[maxson + 1]) maxson = maxson + 1;
        if (arr[maxson] > arr[f])
        {
            swap(arr[maxson], arr[f]);
            f = maxson;
        }
        else return;

    }
}
void HeapSort(int m[], int N)
{
    for (int i = N / 2; i >= 1; i--)
        RestoreHeap(m, i, N);
    for (int i = N; i > 1; i--)
    {
        swap(m[1], m[i]);
        RestoreHeap(m, 1, i - 1);
    }
}
void write_mas(int arr[], int N)
{
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
}
int main()
{
    srand(time(NULL));
    int N;
    cout << "Enter size of array" << endl;
    cin >> N;
    int* arr = new int[N];
    for (int i = 1; i <= N; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    HeapSort(arr, N);
    cout<<endl;
    write_mas(arr, N);
}