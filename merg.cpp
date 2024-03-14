#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int>& arr);
vector<int> merge(vector<int>& left, vector<int>& right);

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> sortedArr = mergeSort(arr);
    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> leftHalf(arr.begin(), arr.begin() + mid);
    vector<int> rightHalf(arr.begin() + mid, arr.end());

    vector<int> leftSorted = mergeSort(leftHalf);
    vector<int> rightSorted = mergeSort(rightHalf);

    return merge(leftSorted, rightSorted);
}

vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int leftIdx = 0, rightIdx = 0;

    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] < right[rightIdx]) {
            result.push_back(left[leftIdx++]);
        } else {
            result.push_back(right[rightIdx++]);
        }
    }

    while (leftIdx < left.size()) {
        result.push_back(left[leftIdx++]);
    }

    while (rightIdx < right.size()) {
        result.push_back(right[rightIdx++]);
    }

    return result;
}
