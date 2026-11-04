#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MinCoins(vector<int> &coins,int n, int amt, vector <int> &chosen)
{

    vector<vector <int> > dp(n+1, vector<int>(amt+1, INT_MAX - 1));

    for(int i=1; i<=n; i++)
    {
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amt; j++)
        {
            if(coins[i-1] <= j)
            {
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int i=n, j=amt;
    while(i>0 && j>0)
    {

        if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else
        {
            chosen.push_back(coins[i-1]);
            j=j-coins[i-1];
        }
    }
    return dp[n][amt];
}

int main()
{

    int n, amt;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n),chosen;
    cout << "Enter values of coins:\n";

    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the amount: ";
    cin >> amt;

    int result = MinCoins(coins, n, amt, chosen);
    if(result==-1)
        cout << "Not possible to exchange the amount." << endl;
    else
        cout << "Minimum coins needed to exchange: " << result << endl;
        cout << "Coins chosen: " << endl;

    for(int i=chosen.size()-1; i>=0; i--)
    {
        cout << chosen[i] << " ";
    }
}
