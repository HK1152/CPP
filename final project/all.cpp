#include<iostream>

using namespace std;

void llm(),arraysort(), binaryMenu();

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL; 
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail; 

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL; 
        tail = NULL; 
    }

    void insert_front(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) { // List  empty ho tab
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << value << " at the front." << endl;
    }

    void insert_last(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) { // empty ho tab
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Inserted " << value << " at the last." << endl;
    }

    void insert_middle(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position. Position must be 1 or greater." << endl;
            return;
        }
        if (pos == 1) { //  front Insert karne ke liye
            insert_front(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
       
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

      

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << "." << endl;
    }

    void delete_first() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from front." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
      
        cout << "Deleted first node." << endl;
    }

    void delete_last() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from last." << endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = NULL;
            tail = NULL;
            cout << "Deleted the only node." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) { 
            temp = temp->next;
        }
        delete tail; 
        tail = temp;
        tail->next = NULL; // New tail's next should be null
        cout << "Deleted last node." << endl;
    }

    void delete_middle(int pos) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (pos < 1) {
            cout << "Invalid position. Position must be 1 or greater." << endl;
            return;
        }
        if (pos == 1) { 
            delete_first();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        for (int i = 1; i < pos && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) { 
            cout << "Position " << pos << " is out of bounds. Cannot delete." << endl;
            return;
        }
        if (temp == tail) { 
            delete_last();
            return;
        }

        prev->next = temp->next;
        delete temp; 
        cout << "Deleted node at position " << pos << "." << endl;
    }

    void print() {
        if (head == NULL) {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void modifyNode(int oldVal, int newVal) {
        if (head == NULL) {
            cout << "List is empty. Cannot modify." << endl;
            return;
        }

        Node* current = head;
        while (current != NULL && current->data != oldVal) {
            current = current->next;
        }

        if (current == NULL) {
            cout << oldVal << " not found in the list. Cannot modify." << endl;
        } else {
            current->data = newVal;
            cout << oldVal << " modified to " << newVal << " in the list." << endl;
        }
    }
};

int* newarr = NULL,snewarr = 0; // new array and second new array

void printArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void createArray() {
    if (newarr != NULL) {
        delete[] newarr; 
    }
    cout << "Enter the number of elements for the array: ";
    cin >> snewarr;

    if (snewarr <= 0) {
        cout << "Invalid size. Array will be empty." << endl;
        newarr = NULL;
        snewarr = 0;
        return;
    }

    newarr = new int[snewarr];
    cout << "Enter " << snewarr << " elements:" << endl;
    for (int i = 0; i < snewarr; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> newarr[i];
    }
    cout << "Array created successfully." << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(int arr[], int l, int m, int r) {
    int size1 = m - l + 1;
    int size2 = r - m;

    int* a1 = new int[size1];
    int* a2 = new int[size2];

    for (int i = 0; i < size1; i++) {
        a1[i] = arr[l + i];
    }
    for (int i = 0; i < size2; i++) {
        a2[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < size1 && j < size2) {
        if (a1[i] <= a2[j]) {
            arr[k] = a1[i];
            i++;
        } else {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = a1[i];
        k++;
        i++;
    }

    while (j < size2) {
        arr[k] = a2[j];
        k++;
        j++;
    }

    delete[] a1;
    delete[] a2; 
}

// Merge Sort 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int quickSortPartition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);     

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = quickSortPartition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else { 
            right = mid - 1;
        }
    }
    return -1; 
}


void llm() {
    LinkedList obj; 
    int ch, num, pos;
    do {
        cout << "\n\n**********************Linked List Operations**********************\n";
        cout << "\nselect your choice:-";
        cout << "\n1. Insert at Front \n2. Insert at Last \n3. Insert at Middle";
        cout << "\n4. Delete First \n5. Delete Last \n6. Delete Middle";
        cout << "\n7. Modify Node \n8. Display \n9. Back to Main Menu";
        cout << "\n\n******************************************************\n";
        cout << "\nEnter Your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter a value to insert at front: ";
                cin >> num;
                obj.insert_front(num);
                break;
            case 2:
                cout << "\nEnter a value to insert at last: ";
                cin >> num;
                obj.insert_last(num);
                break;
            case 3:
                cout << "\nEnter position to insert (1 for front): ";
                cin >> pos;
                cout << "Enter a value to insert: ";
                cin >> num;
                obj.insert_middle(num, pos);
                break;
            case 4:
                obj.delete_first();
                break;
            case 5:
                obj.delete_last();
                break;
            case 6:
                cout << "\nEnter position to delete: ";
                cin >> pos;
                obj.delete_middle(pos);
                break;
            case 7: {
                int oldVal, newVal;
                cout << "Enter the value to modify: ";
                cin >> oldVal;
                cout << "Enter the new value: ";
                cin >> newVal;
                obj.modifyNode(oldVal, newVal);
                break;
            }
            case 8:
                obj.print();
                break;
            case 9:
                cout << "Returning to Main Menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 9);
}

void arraysort() {
    int choice;
    do {
        cout << "\n\n**********************Array Sorting Options**********************\n";
        cout << "\nCurrent Array: ";
        printArray(newarr, snewarr);
        cout << "\nselect your choice:-";
        cout << "\n1. Create/Modify Array";
        cout << "\n2. Merge Sort";
        cout << "\n3. Quick Sort";
        cout << "\n4. Back to Main Menu";
        cout << "\n\n******************************************************\n";
        cout << "\nEnter Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                if (snewarr == 0) {
                    cout << "Array is empty. Please create/modify array first." << endl;
                } else {
                 
                    int* tempArr = new int[snewarr];
                    for (int i = 0; i < snewarr; ++i) {
                        tempArr[i] = newarr[i];
                    }
                    mergeSort(tempArr, 0, snewarr - 1);
                    cout << "Array after Merge Sort: ";
                    printArray(tempArr, snewarr);
                    delete[] tempArr; 
                }
                break;
            case 3:
                if (snewarr == 0) {
                    cout << "Array is empty. Please create/modify array first." << endl;
                } else {
                  
                    int* tempArr = new int[snewarr];
                    for (int i = 0; i < snewarr; ++i) {
                        tempArr[i] = newarr[i];
                    }
                    quickSort(tempArr, 0, snewarr - 1);
                    cout << "Array after Quick Sort: ";
                    printArray(tempArr, snewarr);
                    delete[] tempArr; 
                }
                break;
            case 4:
                cout << "Returning to Main Menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

void binaryMenu() {
    if (snewarr == 0) {
        cout << "Array is empty. Please create/modify an array first in the sorting menu." << endl;
        return;
    }

    int* sortedArr = new int[snewarr];
    for (int i = 0; i < snewarr; ++i) {
        sortedArr[i] = newarr[i];
    }

    mergeSort(sortedArr, 0, snewarr - 1);

    cout << "\n\n**********************Binary Search**********************\n";
    cout << "Sorted Array for search: ";
    printArray(sortedArr, snewarr);

    int target;
    cout << "Enter value to search for: ";
    cin >> target;

    int resultIndex = binarySearch(sortedArr, snewarr, target);
    if (resultIndex != -1) {
        cout << "Value " << target << " found at index: " << resultIndex << endl;
    } else {
        cout << "Value " << target << " not found in the array." << endl;
    }

    delete[] sortedArr; 
}

int main() {
    int mainChoice;
    do {
        cout << "\n\n**********************Main Menu********************************\n";
        cout << "\nselect your choice:-";
        cout << "\n1. Linked List Operations";
        cout << "\n2. Array Sorting (Merge & Quick Sort)";
        cout << "\n3. Binary Search in Array";
        cout << "\n4. Exit";
        cout << "\n\n******************************************************\n";
        cout << "\nEnter Your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                llm();
                break;
            case 2:
                arraysort();
                break;
            case 3:
                binaryMenu();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (mainChoice != 4);
return 0;
}
