#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DynamicArray {
private: 
    T* arr;             // the static array
    int len;            // number of elements user thinks exists
    int capacity;       // actual allocated size

public:
    // Default constructor
    DynamicArray() : DynamicArray(16) {}

    //constructor with capacity
    DynamicArray(int cap) {
        if (cap < 0) {
            throw invalid_argument("illegal capacity");
        }

        capacity = cap;
        len =0;
        arr = new T[capacity];
    }

    //deconstructor
    ~DynamicArray() {
        delete[] arr;
    }

    //return current size
    int size() const{
        return len;
    }

    // check if the array is empty
    int isEmpty() const{
        return len == 0;
    }

    // get elements at index
    T get(int index) const{
        if (index < 0 || index >= len) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    // set element at index
    void set(int index, T elem) {
        if (index < 0 || index >= len) {
            throw out_of_range("Index out of bounds");
        }
        arr[index] = elem;
    }

    // clear array
    void clear() {
        len = 0; // this is a logical clear (the allocated memory stays the same)
    }

    //add elements to end
    void add(T elem) {
        // Resize if the array is full
        if (len >= capacity) {
            if (capacity == 0) capacity = 1;
            else capacity *= 2;

            T* new_arr = new T[capacity];
            for(int i = 0; i < len; i++) {
                new_arr[i] = arr[i];
            }

            delete[] arr;
            arr = new_arr;
        }

        arr[len++] = elem;
    }


    // Removing element at index
    T removeAt (int rm_index) {
        if (rm_index < 0 || rm_index >= len) {
            throw out_of_range("Index out of bounds");
        }

        T data = arr[rm_index]; // store the data to be detele temporarily as data

        // shift the entire array to the left 
        for (int i = rm_index; i < len - 1; i++) {
            arr[i] = arr[i + 1];
        }

        len--;
        return data;
    }


    // Remove first occurance of element
    bool remove(const T& elem) {
        int index = indexOf(elem);
        if (index ==-1) return false;
        removeAt(index);
        return true;
    }

    // find index of element
    int indexOf(const T& elem) const{
        for (int i = 0; i < len; i++) {
            if (arr[i] == elem) return i;
        }

        return -1;
    }

    //check if contains element
    bool contains(const T& elem) const{
        return indexOf(elem) != -1;
    }

    // print array (for debugging purposes)
    void print() const{
        cout << "[";
        for (int i = 0; i < len; i++) {
            cout << arr[i];
            if (i != len - 1) cout << ", ";
        }

        cout << "]\n";
    }
};





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DynamicArray<int> da;

    da.add(10);
    da.add(20);
    da.add(23);
    da.add(44);
    da.add(40);
    da.add(66);

    da.print();

    da.removeAt(1);
    da.print();

    cout << "Size: " << da.size() << "\n";
    cout << "Contains 40? " << da.contains(40) << "\n";

    return 0;
}
