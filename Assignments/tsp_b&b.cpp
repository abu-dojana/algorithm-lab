#include <bits/stdc++.h>
using namespace std;

#define N 5
#define INF INT_MAX

// State Space Tree nodes
struct Node
{
    vector<pair<int, int>> path;
    int reducedMatrix[N][N];
    int cost;
    int node_curr_city_num;
    int level;
};

// create new node in the state space tree
Node *newNode(int parentMatrix[N][N], const vector<pair<int, int>> &path, int level, int i, int j)
{
    Node *node = new Node;
    node->path = path;

    if (level != 0)
    {
        node->path.push_back(make_pair(i, j));
    }

    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            node->reducedMatrix[r][c] = parentMatrix[r][c];
        }
    }

    if (level != 0)
    {
        for (int k = 0; k < N; ++k)
        {
            node->reducedMatrix[i][k] = INF;
            node->reducedMatrix[k][j] = INF;
        }
    }

    node->reducedMatrix[j][0] = INF;
    node->level = level;
    node->node_curr_city_num = j;

    return node;
}

// row reduction function
void rowReduction(int reducedMatrix[N][N], int row[N])
{
    // initialize array row to INF
    for (int i = 0; i < N; i++)
    {
        row[i] = INF;
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reducedMatrix[i][j] < row[i])
            {
                row[i] = reducedMatrix[i][j];
            }
        }
    }

    // row element reduction to min
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reducedMatrix[i][j] != INF && row[i] != INF)
            {
                reducedMatrix[i][j] -= row[i];
            }
        }
    }
}



// column reduction function
void columnReduction(int reducedMatrix[N][N], int col[N])
{
    //initialize array col to INF
    for (int j = 0; j < N; j++)
    {
        col[j] = INF;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reducedMatrix[i][j] < col[j])
            {
                col[j] = reducedMatrix[i][j];
            }
        }
    }

    // col element reduction to min
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reducedMatrix[i][j] != INF && col[j] != INF)
            {
                reducedMatrix[i][j] -= col[j];
            }
        }
    }
}


// lower bound function
int calculateCost(int reducedMatrix[N][N])
{
    int cost = 0;
    
    int row[N];
    rowReduction(reducedMatrix, row);

    int col[N];
    columnReduction(reducedMatrix, col);

    // total expected cost = row cost + col cost
    for (int i = 0; i < N; i++)
    {
        cost += (row[i] != INT_MAX) ? row[i] : 0, cost += (col[i] != INT_MAX) ? col[i] : 0;
    }

    return cost;
}


void print_path(vector<pair<int, int>> const &list)
{
    cout << "Tour Path: " << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i].first + 1 << " -> " << list[i].second + 1 << endl;
    }
}


//compparison object to be used to order the heap
struct comp_heap
{
    bool operator()(const Node *left, const Node *right) const
    {
        return right->cost < left->cost;
    }
};



// solve function
int solve(int weight[N][N])
{
    // live nodes of the search tree
    priority_queue<Node *, vector<Node *>, comp_heap> curr_node;
    
    vector<pair<int, int>> v;
    Node *root = newNode(weight, v, 0, -1, 0);

    root->cost = calculateCost(root->reducedMatrix);
    curr_node.push(root);

    while (!curr_node.empty())
    {
        Node *min = curr_node.top();

        curr_node.pop();

        int i = min->node_curr_city_num;

        // if all cities are visited
        if (min->level == N - 1)
        {
            // return to starting city
            min->path.push_back(make_pair(i, 0));
            print_path(min->path);

            cout << endl;
            cout << "Total minimum Cost: ";

            return min->cost;
        }

        for (int j = 0; j < N; j++)
        {
            if (min->reducedMatrix[i][j] != INF)
            {

                Node *child = newNode(min->reducedMatrix, min->path, min->level + 1, i, j);
                
                // Cost of the child = cost of the parent node + cost of the edge(i, j) + lower bound of the path starting at node j
                child->cost = min->cost + min->reducedMatrix[i][j] + calculateCost(child->reducedMatrix);
                curr_node.push(child);
            }
        }
    }
    return 0;
}

int main()
{
    // input cost matrix

    int weight[N][N] =
        {
            {INF, 20, 30, 10, 11},
            {15, INF, 16, 4, 2},
            {3, 5, INF, 2, 4},
            {19, 6, 18, INF, 3},
            {16, 4, 7, 16, INF}};

    // cost 28

    cout << solve(weight) << endl;

    return 0;
}
