/*
  Question: Binary search একটা array কে ২ ভাগে ভাগ করে। মিড পয়েন্ট ১ টা থাকে। কিন্তু যদি মিড পয়েন্ট ২ টা থাকে তখন? 
 */
//Original code:
#include <bits/stdc++.h>
using namespace std;

int ternarySearch(const std::vector<int>& arr, int left, int right, int key) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }

        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }

    return -1; // Element not found
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;

    int result = ternarySearch(sortedArray, 0, sortedArray.size() - 1, key);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}

/*
Ternary Search:
Ternary search is a searching algorithm that is similar to binary search but divides the search space into three parts instead of two. It is particularly useful when the search space is sorted and you need to find the position of an element that satisfies a certain condition.

Here's a basic outline of the ternary search algorithm:

Divide the search space into three parts:

Calculate two midpoints, say mid1 and mid2, such that mid1 = left + (right - left) / 3 and mid2 = right - (right - left) / 3.
Compare the element with mid1 and mid2:

If the element is equal to either arr[mid1] or arr[mid2], return the index of the element.
If the element is less than arr[mid1], search in the first third.
If the element is between arr[mid1] and arr[mid2], search in the second third.
If the element is greater than arr[mid2], search in the last third.
Recursively repeat the process:

Repeat the process in the selected third until the element is found or the search space is empty.
*/

/*
আমার সাবমিট করা কোডঃ

#include <bits/stdc++.h>
using namespace std;

string bin_search(vector<int> A, int key)
{
    int low = 0;
    int hi = 20 -1;


    while (low <= hi)
    {
        int mid1 = (left+right) / 3;
        int mid2 = 2*(right - left) / 3;

        if (A[mid1]==key)
        {
            cout << "pos: " << mid1+1 << endl;
            return "FOUND";

        }
        if (A[mid2]==key)
        {
            cout << "pos: " << mid2+1 << endl;
            return "FOUND";

        }
          if (key < A[mid1]) {
            left = mid1-1;
        } else if (key > A[mid2]) {
            right = mid2+1;
        } else {
            mid1= mid1 + 1;
            mid2= mid2 - 1;

        }
    }
    return "Not Found";
}

int main()
{
    vector <int> A;
    int x, size;

    cout << "Enter size:";
    cin >> size;

    cout << "Enter The elements:" << endl;

    for (int i=0; i< size; i++)
    {
        cout << "A["<< i << "] :" ;
        cin >> x;
        A.push_back(x);
    }

    cout << endl;

    for (int i=0; i< size; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;

    cout << bin_search(A,4) << endl;
}
*/
