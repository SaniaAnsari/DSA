#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {5, 6, 4, 2, 4, 1, 3};
    for (int i = 1; i < 7; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    for (int k = 0; k < 7; k++)
    {
        cout << arr[k] << ",";
    }
}