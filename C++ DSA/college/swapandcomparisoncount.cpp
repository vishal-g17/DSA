#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int comparsions = 0;
    int swaps = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            comparsions++;
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                swaps++;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
        swaps++;
    }
    cout<<"Algorithm      "<<"Comparisons "<<"Swaps "<<endl;;
    cout<<"Insertion Sort ";
    
    cout<<comparsions<<"            "<<swaps;
}

void selectionSort(int arr[], int n)
{
    int comparsions = 0;
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int miniIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparsions++;
            if (arr[j] < arr[miniIndex])
            {
                miniIndex = j;
            }
        }
        swap(arr[miniIndex], arr[i]);
        swaps++;
    }
    cout<<"Selection Sort ";
    
    cout << comparsions << "           " << swaps;
}

void bubbleSort(int arr[], int n)
{
    int comparisons = 0;
    int swaps = 0;
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    cout<<"Bubble Sort    ";
    
    cout << comparisons << "           " << swaps;
}

int main()
{
    int arr1[] = {3, 4, 52, 23, 15};
    int arr2[] = {43, 24, 52, 3, 15};
    int arr3[] = {13, 42, 2, 32, 5};
    insertionSort(arr1, 5);
    cout<<endl;
    selectionSort(arr2, 5);
    cout<<endl;
    bubbleSort(arr3, 5);
    cout<<endl;

    return 0;
}