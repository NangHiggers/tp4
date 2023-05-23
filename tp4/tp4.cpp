#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "SelectionSortArray.cpp"
#include "LinkedList.h"
using namespace std;


template <typename T>
void runLinkedListMenu() {
    LinkedList<T> linkedList1;
    LinkedList<T> linkedList2;

    int choice;
    do {
        cout << "\n---- LINKED LIST MENU ----\n";
        cout << "1. Insert element into list 1\n";
        cout << "2. Insert element into list 2\n";
        cout << "3. Print list 1\n";
        cout << "4. Print list 2\n";
        cout << "5. Print list 1 + list 2\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            T element = T();
            cout << "Enter element for list 1: ";
            cin >> element;
            linkedList1.insert(element);
            cout << "Element inserted into list 1 successfully.\n";
            break;
        }
        case 2: {
            T element = T();
            cout << "Enter element for list 2: ";
            cin >> element;
            linkedList2.insert(element);
            cout << "Element inserted into list 2 successfully.\n";
            break;
        }
        case 3:
            cout << "List 1: ";
            for (int i = 0; i < linkedList1.getSize(); ++i) {
                cout << linkedList1[i] << " ";
            }
            cout << endl;
            break;
        case 4:
            cout << "List 2: ";
            for (int i = 0; i < linkedList2.getSize(); ++i) {
                cout << linkedList2[i] << " ";
            }
            cout << endl;
            break;
        case 5: {
            cout << "Combined list: ";
            for (int i = 0; i < linkedList1.getSize(); ++i) {
                cout << linkedList1[i] << " " << " ";
            }
            for (int i = 0; i < linkedList2.getSize(); ++i) {
                cout << linkedList2[i] << " " << " ";
            }
            cout << endl;
            break;
     
        }
        case 0:
            cout << "Exiting linked list menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);
}

template <typename T>
void runArraySortMenu() {
    vector<T> arr;

    int choice;
    do {
        cout << "\n---- SELECTION SORT MENU ----\n";
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. Sort in ascending order\n";
        cout << "4. Sort in descending order\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            T element;
            cout << "Enter element to add: ";
            cin >> element;
            arr.push_back(element);
            cout << "Element added successfully.\n";
            break;
        }
        case 2: {
            if (arr.empty()) {
                cout << "Array is empty. Unable to delete element.\n";
            }
            else {
                int index;
                cout << "Enter index of element to delete (0-" << arr.size() - 1 << "): ";
                cin >> index;
                if (index < 0 || index >= arr.size()) {
                    cout << "Invalid index. Deletion failed.\n";
                }
                else {
                    arr.erase(arr.begin() + index);
                    cout << "Element deleted successfully.\n";
                }
            }
            break;
        }
        case 3:
            if (arr.empty()) {
                cout << "Array is empty. Unable to sort.\n";
            }
            else {
                selectionSort(arr, true);
                cout << "Array sorted in ascending order.\n";
                cout << "Sorted array: ";
                for (const auto& element : arr) {
                    cout << element << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            if (arr.empty()) {
                cout << "Array is empty. Unable to sort.\n";
            }
            else {
                selectionSort(arr, false);
                cout << "Array sorted in descending order.\n";
                cout << "Sorted array: ";
                for (const auto& element : arr) {
                    cout << element << " ";
                }
                cout << endl;
            }
            break;
        case 0:
            cout << "Exiting array sort menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);
}

int main() {
    int mainMenuChoice;
    cout << "---- MAIN MENU ----\n";
    cout << "1. Parameterized Linked List\n";
    cout << "2. Selection Sort on Array\n";
    cout << "Enter your choice: ";
    cin >> mainMenuChoice;

    switch (mainMenuChoice) {
    case 1: {
        int dataTypeChoice;
        cout << "---- LINKED LIST MENU ----\n";
        cout << "Select data type:\n";
        cout << "1. int\n";
        cout << "2. char\n";
        cout << "3. float\n";
        cout << "4. double\n";
        cout << "5. char*\n";
        cout << "Enter your choice: ";
        cin >> dataTypeChoice;

        switch (dataTypeChoice) {
        case 1:
            runLinkedListMenu<int>();
            break;
        case 2:
            runLinkedListMenu<char>();
            break;
        case 3:
            runLinkedListMenu<float>();
            break;
        case 4:
            runLinkedListMenu<double>();
            break;
        case 5:
            runLinkedListMenu<char*>();
            break;
        default:
            cout << "Invalid data type choice. Exiting program.\n";
            break;
        }
        break;
    }
    case 2:
        runArraySortMenu<int>();
        break;
    default:
        cout << "Invalid choice. Exiting program.\n";
        break;
    }

    return 0;
}