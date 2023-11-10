#include <bits\stdc++.h>
using namespace std;

void insertion_sort(vector<int> &A)
{
    int i, j, key;

    for (i = 1; i < A.size(); i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
}

/*
void insertion_sort(vector<int> &A)
{
    int i, j, key;

    // Imagine you have a row of toy blocks (the vector A).
    // We start from the second block (i = 1), not the first one.

    for (i = 1; i < A.size(); i++)
    {
        // Take one block (key) from the row.
        key = A[i];

        // Look at the blocks to the left of the one you are holding.
        j = i - 1;

        // As long as the blocks on the left are bigger, move them to the right.
        // Think of it like finding the right spot to put the block you are holding.
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j]; // Move the bigger block to the right.
            j = j - 1;       // Move to the next block on the left.
        }

        // Put the block you are holding in the right spot.
        A[j + 1] = key;
    }
}

In simpler terms:

1. Imagine you have a row of toy blocks (the vector A).
2. Starting from the second block, pick up one block at a time (key).
3. Look at the blocks to the left. If they are bigger, move them to the right until you find the right spot.
4. Put the block you are holding in the right spot.
5. Repeat these steps until you have sorted all the blocks in the row.
So, it's like sorting a row of toy blocks from left to right, making sure each block is in the correct order by comparing and moving them around.

Description of Variables:

i: Think of i as your pointer to the current block in the line. It helps you go through each block one by one.
j: This is like another pointer that helps you compare the block you are holding with the blocks on the left. It moves to the left to check and make space for the key block.
key: The block you are currently holding. You compare it with the blocks on the left and find the right place to insert it into the line.
So, i and key help you go through the entire line, and j helps you compare and make space for the key block in the right position.
*/
