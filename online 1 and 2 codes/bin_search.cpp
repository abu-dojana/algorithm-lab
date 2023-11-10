#include <bits/stdc++.h>
using namespace std;

string bin_search(vector <int> A, int key)
{
    int low = 0;
    int hi = 20 -1;


    while (low <= hi)
    {

        int mid = (hi+low)/2;

        if (A[mid]==key)
        {
            cout << "pos: " << mid+1 << endl;
            return "FOUND";

        }

        else if ( key > A[mid])
            low= mid+1;
        else if ( key < A[mid])
            hi= mid -1;
    }
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

/*
Searching for Multiple Elements:
Instead of stopping the binary search when a single occurrence is found, modify the code to continue searching for additional occurrences.
Keep track of all found occurrences and return a list of indices.
code:

#include <bits/stdc++.h>
using namespace std;

vector <int> bin_search(vector <int> A, int key)
{
    int low = 0;
    int hi = 20 -1;
    vector <int> pos;

    while (low <= hi)
    {

        int mid = (hi+low)/2;

        if (A[mid]==key)
        {
            pos.push_back(mid+1);
            low= mid+1;
        }

        else if ( key > A[mid])
            low= mid+1;
        else if ( key < A[mid])
            hi= mid -1;
    }

    return pos;
}
*/

/*
1. Finding the First and Last Occurrence:
Perform a binary search to find the target element.
Once the element is found, modify the binary search to continue searching for the first occurrence to the left and the last occurrence to the right.
2. Counting Occurrences:
Utilize the modified binary search from the first point to find the first and last occurrences.
Calculate the count of occurrences by subtracting the index of the first occurrence from the index of the last occurrence and adding 1.

code:

#include <bits/stdc++.h>
using namespace std;

vector <int> bin_search(vector <int> A, int key)
{
    int low = 0;
    int hi = 20 -1;
    vector <int> pos;

    while (low <= hi)
    {

        int mid = (hi+low)/2;

        if (A[mid]==key)
        {
            pos.push_back(mid+1);
            low= mid+1;
        }

        else if ( key > A[mid])
            low= mid+1;
        else if ( key < A[mid])
            hi= mid -1;
    }

    return pos;
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

    vector <int> pos = bin_search(A,4);

    cout << "pos: " << pos[0] << endl;
    cout << "pos: " << pos[1] << endl;

    cout << "count: " << pos[1] - pos[0] + 1 << endl;
}

*/
