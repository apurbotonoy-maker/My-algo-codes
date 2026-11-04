#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int n, int capacity, vector<string> &name, vector<int> &profit, vector<int> &weight, vector<string> &chosen)
{

    vector<vector<int> > KS(n+1, vector<int> (capacity+1, 0));

    for(int i=1; i<=n; i++)
    {

        for(int c=1; c<=capacity; c++)
        {

            if(weight[i-1] <= c)
            {

                KS[i][c]=max(KS[i-1][c], profit[i-1]+KS[i-1][c-weight[i-1]]);
            }
            else
            {

                KS[i][c]=KS[i-1][c];
            }
        }
    }

    int c = capacity;
    for(int i=n; i>0; i--)
    {

        if(KS[i][c] != KS[i-1][c])
        {

            chosen.push_back(name[i-1]);
            c-=weight[i-1];
        }
    }

    return KS[n][capacity];
}




int main()
{

    int i,n;

    cout << "Enter the number of items: " << endl;
    cin >> n;
    vector <int> weight(n),profit(n);
    vector <string> name(n);

    for(i=0; i<n; i++)
    {

        cout << "Enter the name of item " << i+1 <<": ";
        cin >> name[i];

        cout << "Enter the profit of item " << i+1 <<": ";
        cin >> profit[i];

        cout << "Enter the weight of item " << i+1 <<": ";
        cin >> weight[i];
    }

    int capacity;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector <string> chosen;

    int max_profit = 0;
    max_profit = knapsack(n, capacity, name, profit, weight, chosen);
    cout << "Max profit: " << max_profit << endl;
    cout << "Item chosen: " << endl;

    for(int i=chosen.size() - 1; i>=0 && chosen.size() > 0; i--)
    {
        cout << chosen[i] << " ";
        cout << endl;
    }
}
