#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int partition(int hi, int low)
{
    int pivot = A[low];
    int i = low;
    int j = hi;

    while (j > i)
    {
        while (A[i] <= pivot)
        {
            i = i + 1;
        }
        while (A[j] > pivot)
        {
            j = j - 1;
        }

        if (j > i)
        {
            swap(A[i], A[j]);
        }
    }

    swap(A[low], A[j]);

    return j;
}

void quick_sort(int low, int hi)
{
    if (hi > low)
    {
        int pos = partition(low, hi);
        quick_sort(low, pos - 1);
        quick_sort(pos + 1, hi);
    }
}

int main()
{

    A = {5, 4, 3, 2, 1};

    quick_sort(0, 4);

    for (int i = 0; i <= 4; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
modify the code for quick sort for a specific task, such as sorting in descending order.
code:

#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int partition(int hi, int low)
{
    int pivot = A[low];
    int i = low;
    int j = hi;

    while (j > i)
    {
        while (A[i] <= pivot)
        {
            i = i + 1;
        }
        while (A[j] > pivot)
        {
            j = j - 1;
        }

        if (j > i)
        {
            swap(A[i], A[j]);
        }
    }

    swap(A[low], A[j]);

    return j;
}

void quick_sort(int low, int hi)
{
    if (hi > low)
    {
        int pos = partition(low, hi);
        quick_sort(low, pos - 1);
        quick_sort(pos + 1, hi);
    }
}

int main()
{

    A = {5, 4, 3, 2, 1};

    quick_sort(0, 4);

    for (int i = 0; i <= 4; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

*/


/*
Change Pivot Selection:

Modify the code to use a different strategy for selecting the pivot in the partition function. For example, instead of always choosing the leftmost element, you could choose the middle element.

code:

#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int partition(int hi, int low)
{
    int pivot = A[low];
    int i = low;
    int j = hi;

    while (j > i)
    {
        while (A[i] <= pivot)
        {
            i = i + 1;
        }
        while (A[j] > pivot)
        {
            j = j - 1;
        }

        if (j > i)
        {
            swap(A[i], A[j]);
        }
    }

    swap(A[low], A[j]);

    return j;
}

void quick_sort(int low, int hi)
{
    if (hi > low)
    {
        int pos = partition(low, hi);
        quick_sort(low, pos - 1);
        quick_sort(pos + 1, hi);
    }
}

int main()
{

    A = {5, 4, 3, 2, 1};

    quick_sort(0, 4);

    for (int i = 0; i <= 4; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

*/

/*
Imagine you have a row of toy blocks (the vector A), and you want to arrange them in a specific order from smallest to biggest. This code uses a method called "quick sort" to do that.

partition function:

int partition(int hi, int low) is like finding a special block in the row, called the "pivot," and putting all the smaller blocks on one side and the bigger blocks on the other side.
int pivot = A[low]; means we choose the leftmost block as the pivot.
i and j are like two pointers. i starts from the left, and j starts from the right.
We move i to the right until we find a block bigger than the pivot, and we move j to the left until we find a block smaller than the pivot.
If j is still to the right of i, we swap the blocks at positions i and j.
We keep doing this until j is not to the right of i. Then, we swap the pivot with the block at position j. Now, all smaller blocks are on the left, and bigger blocks are on the right. We return the position of the pivot.
quick_sort function:

void quick_sort(int low, int hi) is like sorting smaller groups of blocks within the row.
If there is more than one block in a group, we find a new pivot using the partition function and sort the blocks on the left and right of the pivot.
main function:

We start with an unsorted row of blocks {5, 4, 3, 2, 1}.
We use quick_sort to sort the entire row.
After sorting, we print the blocks in order.
So, the code is like sorting toy blocks in a clever way by picking special blocks (pivot) and arranging the other blocks around them. This process is repeated until the entire row is sorted from smallest to biggest.
    
*/
