#include<bits/stdc++.h>
using namespace std;
struct Item
{
    char name[10];
    int profit, weight;
    float Ratio;
};
int main (){

    int n;
    cout << "Enter the number of item: ";
    cin >> n;

    Item item[n];

    for (int i=0;i<n;i++){

        cout << "Enter the name of item " << i+1 << " : ";
        cin >> item[i].name;
        cout << "Enter the weight of item " << i+1 << " : ";
        cin >> item[i].weight;
        cout << "Enter the profit of item " << i+1 << " : ";
        cin >> item[i].profit;

        item[i].Ratio = (double)item[i].profit / item[i].weight;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (item[i].Ratio < item[j].Ratio){

                Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    double profits=0.0;
    int rem_capacity = capacity;
    for (int i=0;i<n;i++){

        if (item[i].weight <= rem_capacity){

            profits += item[i].profit;
            rem_capacity -= item[i].weight;

            cout << "Item taken ->" << i+1 << "Name: " << item[i].name << endl << "Weight: " << item[i].weight << "Profit: " << item[i].profit << "Ratio: " << item[i].Ratio;
        }

        else{

            profits += item[i].Ratio * rem_capacity;

            cout << "Fraction of item taken ->" << i+1 << "Name: " << item[i].name << endl;
            break;
        }
    }

    cout << "Total profit: " << profits << endl;
}
