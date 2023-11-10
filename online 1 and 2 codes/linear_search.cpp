#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key)
{
    for (int i=0; i< v.size(); i++)
    {
        if (v[i]== key)
        {
            cout << key << " Found at index: " << i << endl; 
            return;
        }
    }

    cout << "Not Found"<< endl;

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

    linearSearch(A,4);
}

/*
Finding the First Occurrence:

Modify the linear search code to find the index of the first occurrence of a specific element in the list.
If the element is not found, print -1.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key)
{
    for (int i=0; i< v.size(); i++)
    {
        if (v[i]== key)
        {
            cout << key << " Found at index: " << i << endl; 
            return;
        }
    }

    cout << "Not Found"<< endl;

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

    linearSearch(A,4);
}
*/

/*
Counting Occurrences:

Extend the linear search code to count and print the number of occurrences of a particular element in the list.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key)
{
    int count = 0;
    for (int i=0; i< v.size(); i++)
    {
        if (v[i]== key)
        {
            count++;
        }
    }

    cout << key << " Found " << count << " times." << endl;

}
*/

/*
Finding the Last Occurrence:

Modify the linear search code to find the index of the last occurrence of a specific element in the list.
If the element is not found, print -1.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key)
{
    int index = -1;
    for (int i=0; i< v.size(); i++)
    {
        if (v[i]== key)
        {
            index = i;
        }
    }

    cout << key << " Found at index: " << index << endl;

}
*/

/*
Searching in a Range:

Ask you to modify the code to perform a linear search within a specified range of indices in the list.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key, int start, int end)
{
    int index = -1;
    for (int i=start; i<= end; i++)
    {
        if (v[i]== key)
        {
            index = i;
        }
    }

    cout << key << " Found at index: " << index << endl;

}
*/

/*
Finding Maximum or Minimum:

Use linear search to find the maximum or minimum element in the list.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v)
{
    int max = v[0];
    for (int i=1; i< v.size(); i++)
    {
        if (v[i]> max)
        {
            max = v[i];
        }
    }

    cout << "Max: " << max << endl;

}
*/

/*
Searching for Multiple Elements:

Modify the code to search for multiple elements and return a list of indices where those elements are found.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key)
{
    vector <int> indices;
    for (int i=0; i< v.size(); i++)
    {
        if (v[i]== key)
        {
            indices.push_back(i);
        }
    }

    cout << key << " Found at indices: ";
    for (int i=0; i< indices.size(); i++)
    {
        cout << indices[i] << " ";
    }
    cout << endl;

}
*/

/*
Sorting and Searching:

Combine linear search with a sorting algorithm (e.g., bubble sort) and modify the code to search for an element in the sorted list.
code:

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector <int> v, int key)
{
    int index = -1;
    for (int i=0; i< v.size(); i++)
    {
        if (v[i]== key)
        {
            index = i;
        }
    }

    cout << key << " Found at index: " << index << endl;

}

void bubbleSort(vector <int> &v)
{
    for (int i=0; i< v.size(); i++)
    {
        for (int j=0; j< v.size()-1; j++)
        {
            if (v[j]> v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }
}
*/
