#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
        int n1 = mid - left + 1; // size of left subarray
        int n2 = right - mid;    // size of right subarray

        // Create temporary arrays
        int L[n1], R[n2];

        // Copy data into temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Merge the temp arrays back into arr[]
        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[]
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[]
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }


void mergesort(int arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = (left+right)/2;
            mergesort(arr, left, mid);      // left
            mergesort(arr, mid + 1, right); // right
            merge(arr, left,mid, right);
        }
    }
int main()
    {
        int arr[] = {2, 3, 8, 7, 6, 4, 5};
        int size = 7;
        mergesort(arr, 0, size - 1);

         for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

        return 0;
    }