/*
Question: Merge Sort এ ভাগ করতে করতে যখন শেষ পর্যন্ত আসে, তার আগেই অর্থাৎ, ২ ঘর যখন বাকি থাকে তখন insertion sort ব্যবহার করে সর্ট করতে হবে। 
Search: merge sort and insertion sort combo. 
Link: https://www.geeksforgeeks.org/sorting-by-combining-insertion-sort-and-merge-sort-algorithms/

 Sample Explanation of question:
      □□□□□□□
        / \
      □□□ □□□□
      / \   / \
    □□  □□ □□  □□  <-- এইখানে insertion sort use করতে হবে।
    / \
   □   □  <-- এইখানে না। এই পর্যন্ত merge sort যাবে না। 
    
   

*/

#include <bits/stdc++.h>
using namespace std;

const int INSERTION_THRESHOLD = 5;
void insertionSort(vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= start && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left + 1 <= INSERTION_THRESHOLD) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

int main() {
   vector<int> arrayToSort = {5, 1, 4, 9, 8, 2, 3, 6};

    mergeSort(arrayToSort, 0, arrayToSort.size() - 1);

    cout << "Sorted Array: ";
    for (int num : arrayToSort) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}
