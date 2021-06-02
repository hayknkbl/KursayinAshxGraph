#include <iostream>
#include <vector>

using namespace std;

int k1 = 0;

void AllStar(vector<int> n, int k, int i)
{
    int a, b, c;
    int l = 0;
    for (a = 0; a < k - 2; ++a)
    {
        for (b = a + 1; b < k - 1; ++b)
        {
            for (c = b + 1; c < k; ++c)
            {
                cout << "The " << k << "th star of the graph will be" << "\n";
                ++k1;
                cout <<"V(1) = {" << i << "}   V(2) = { " << n[a] << ", " << n[b] << ", " << n[c] << "} \n"  << endl;
            }
        }
    }
}

int InsertNndes(int* a, int* b, int n)
{
    cin >> *a;
    if (*a < 0)
    {
        return 0;
    }
    cin >> *b;
    if (*b < 0)
    {
        return 0;
    }
    if ((*a >= n) || (*b >= n))
    {
        cout << "Wrong insert, try again \n";
        InsertNndes(a, b, n);
    }
    return 1;
}


int main()
{
    int n;
    cout << "Insert number of nodes \n";
    cin >> n;

    vector < vector <int> > Masiv(n, vector <int>(n));
    int a, b;
    cout << "Insert endpoints of each edge \n" << endl;
    while (InsertNndes(&a, &b, n))
    {
        Masiv[a][b] = 1;
        Masiv[b][a] = 1;
    }
    
    cout << "The adjacency matrix of graph \n" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << Masiv[i][j] << "  ";
        }
        cout << "\n";
    }
    bool check = true;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        vector<int> tox;
        for (int j = 0; j < n; ++j)
        {
            if (Masiv[i][j])
            {
                ++sum;
                tox.push_back(j);
            }
        }
        if (sum < 3) {}
        else
        {      
            AllStar(tox, sum, i);
            check = false;
        }
    }
    if (check)
    {
        cout << "There are no stars in your graph" << endl;
    }
}

