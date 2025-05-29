#include <iostream>
using namespace std;

class SelectionSort
{
public:
    void sort(int arr[], int ch) // arr[] means real arr[] and n means size
    {
        for (int i = 0; i < ch - 1; i++) { 
            for (int j = i + 1; j < ch; j++) {
                if (arr[i] > arr[j]) { // i pe j ka sara index comper hoga
              
					 int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display(const int arr[], int n)
    {
        cout << "Sorted array: ";
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class MergeSort
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        int size1 = m - l + 1;  // ye size 1 left ke liye 
        int size2 = r - m; // yer size 2 right ke liye

        int *a1 = new int[size1]; // left ki location ke liye
        int *a2 = new int[size2]; // right ki location ke liye

        for (int i = 0; i < size1; ++i) // left ka for loop
        {
            a1[i] = arr[l + i];
        }
        for (int i = 0; i < size2; ++i) // right ka for loop
        {
            a2[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l; // k means temp index value
        while (i < size1 && j < size2) //size 1 vo i se bada hona chahiae or size 2 vo j se bada hona chahiae
        {
            if (a1[i] <= a2[j]) 
            {
                arr[k] = a1[i];
                ++i;
            }
            else
            {
                arr[k] = a2[j];
                ++j;
            }
            ++k;
        }
        while (i < size1)
        {
            arr[k] = a1[i];
            ++k;
            ++i;
        }

        while (j < size2)
        {
            arr[k] = a2[j];
            ++k;
            ++j;
        }

        delete[] a1;
        delete[] a2;
    }
    void partition(int arr[], int l, int r)
    {
        if (l < r)
        {
            int mid = (r + l) / 2; 
            partition(arr, l, mid); // ye left ke liye partition 
            partition(arr, mid + 1, r); // ye right ke liye partition 
            merge(arr, l, mid, r); // merge fun. ko call karaya 
        }
    }

    void display(const int arr[], int n)
    {
        cout << "Sorted array: ";
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class BinarySearch
{
public:
    int search(int arr[], int target, int n)
    {
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)// mid target ke barabar hona chahiae
            {
                return mid; 
            }
            else if (arr[mid] < target)// mid target se chhota hona chahiae
            {
                left = mid + 1;
            }
            else // mid target se bada hona chahiae
            {
                right = mid - 1;
            }
        }
        return -1; 
    }
};

int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;

    int *arr = new int[size]; 
    cout << "Enter " << size << " integer values:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }



    SelectionSort selectionSorter;
    MergeSort mergeSorter;
    BinarySearch binarySearcher; 

    int *oldarr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        oldarr[i] = arr[i];
    }

        int ch;
        cout << "\n*********************************************";
        cout << "\n1. Selection Sort \n2. Merge Sort \n3. Binary Search"; 
        cout << "\n*********************************************";
        cout << "\nEnter your choice: ";
        cin >> ch;

//        for (int i = 0; i < size; ++i)
//        {
//            arr[i] = oldarr[i];
//        }

        switch (ch)
        {
        case 1:
            cout << "\n--- Selection Sort ---\n";
            selectionSorter.sort(arr, size);
            selectionSorter.display(arr, size);
            break;
        case 2:
            cout << "\n--- Merge Sort ---\n";
            mergeSorter.partition(arr, 0, size - 1);
            mergeSorter.display(arr, size);
            break;
        case 3:
  
            cout << "\n--- Performing Binary Search ---\n";
            mergeSorter.partition(arr, 0, size - 1); 
            mergeSorter.display(arr, size); 
            int target;
            cout << "Enter search value: ";
            cin >> target;

            int result = binarySearcher.search(arr, target, size); 

            if (result == -1)
            {
                cout << "Item " << target << "is not found in this array." << endl;   break; 
            }
            else
            {
                cout << "Item " << target << " found at index: " << result << endl;   break; 
            }
          
      
        }
   

    return 0;
}
