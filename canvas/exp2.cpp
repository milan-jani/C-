#include <iostream>
using namespace std;

void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search_array(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int insert_element(int arr[], int& size, int capacity, int element, int position) {
    if (size >= capacity) {
        cout << "Array is full" << endl;
        return -1;
    }
    if (position < 0 || position > size) {
        cout << "Invalid Position" << endl;
        return -1;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

int delete_element(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid Position" << endl;
    }
    for (int i = position; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return 0;
}

int delete_all_occurrences(int arr[], int& size, int element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            for (int j = i; j < size; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
            count++;
        }
    }
    cout << "Deleted " << count << " occurrences of " << element << endl;
    return 0;
}

void frequency_count(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        cout << "Frequency of " << arr[i] << " is " << count << endl;
    }
}

int main() {
    int capacity = 10;
    int size = 5;
    int arr[capacity] = {1,2,3,3,4,5};
    display_array(arr, size);

    int key = 10;
    int index = search_array(arr, size, key);
    if (index != -1) {
        cout << "index found at: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    int p = 2;
    int key2 = 4;
    insert_element(arr, size, capacity, key2, p);
    cout << endl;

    int index2 = 3;
    delete_element(arr, size, index2);
    display_array(arr, size);

    int element = 4;
    delete_all_occurrences(arr, size, element);
    display_array(arr, size);

    frequency_count(arr, size);

    return 0;
}