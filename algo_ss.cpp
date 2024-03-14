#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_index = i;
        // Finding the min element
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swapping
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    selectionSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
