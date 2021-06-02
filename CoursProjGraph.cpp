#include <iostream>
#include <vector>

using namespace std;


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
                cout << i + 1 << "  " << n[a] + 1 << "  " << n[b] + 1  << "  " << n[c] + 1 << endl;
            }
        }
    }
}


int main()
{
    int n;
    cout << "Nermucxeq gagatneri qanak@ \n";
    cin >> n;

    vector < vector <int> > Masiv(n, vector <int>(n));
    int a, b;
    a = 1;
    cout << "Nermucxeq grafi harevan gagatner@" << endl;
    cin >> a;
    cin >> b;
    while (a)
    {
        /*if ((a > n) || (b > n))
        {
            cout << "Wrong insert, try again" << endl;
            continue;
        }*/
        Masiv[a-1][b-1] = 1;
        Masiv[b-1][a-1] = 1;
        cin >> a;
        if (a == -1)break;
        cin >> b;
    }
    
    cout << "Graf-i harevanutyan matric@ klini" << endl;
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
            cout << "\n";        cout << "\n";
            AllStar(tox, sum, i);
            check = false;
        }
    }
    if (check)
    {
        cout << "There are no stars in your graph" << endl;
    }
}

