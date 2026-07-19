#include <iostream>
using namespace std;

//==================== Insertion Sort ====================
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

//==================== Selection Sort ====================
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

//==================== Bubble Sort ====================
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

//==================== Merge Sort ====================
void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[1000], R[1000];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

//==================== Quick Sort ====================
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

//==================== Print Array ====================
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

//==================== Main ====================
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[1000];

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int choice;

    cout << "\n===== SORT MENU =====\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        insertionSort(a, n);
        break;

    case 2:
        selectionSort(a, n);
        break;

    case 3:
        bubbleSort(a, n);
        break;

    case 4:
        mergeSort(a, 0, n - 1);
        break;

    case 5:
        quickSort(a, 0, n - 1);
        break;

    default:
        cout << "Invalid choice!";
        return 0;
    }

    cout << "\nSorted array:\n";
    printArray(a, n);

    return 0;
}