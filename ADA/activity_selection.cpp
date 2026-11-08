#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Activity
{

    string n;// name of activity, used string cause name of activity can be in words
    int st, ft;// start time and finish time of activity
};
// using custom sort function to sort the activities according to finish time
bool customSort(Activity a1, Activity a2)
{
    return a1.ft < a2.ft;
}
int main()
{

    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

   vector<Activity> v(n);// using vector insted of array cause variable size of array is not allowed in c++
    for (int i = 0; i < n; i++)
    {

        cout << "Enter the name of activity " << i + 1 << " : ";
        cin >> v[i].n;// taking name of activity as input
        cout << "Enter the start time of activity " << i + 1 << " : ";
        cin >> v[i].st;// taking start time of activity as input
        cout << "Enter the finish time of activity " << i + 1 << " : ";
        cin >> v[i].ft;// taking finish time of activity as input
    }

    sort(v.begin(), v.end(), customSort);// sorting the activities according to finish time using custom sort function, removing the need of creating a new array to store the sorted activities

    vector<string> sa;// vector to store the selected activities
    sa.push_back(v[0].n);//pushback function is used to add the first activity to the selected activities vector
    int let = v[0].ft;// let is the finish time of the last selected activity, initialized to the finish time of the first activity
    int count = 1;// count is the number of selected activities, initialized to 1 as the first activity is already selected

    for (int i = 1; i < n; i++)// starting from 1 as the first activity is already selected
    {
        if (v[i].st >= let)
        {
            sa.push_back(v[i].n);
            let = v[i].ft;
            count++;
        }
    }

    cout << "Total number of selected activities are: " << count << endl;
    cout << "Selected activities are: " << endl;
    for (int i = 0; i < sa.size(); i++)// printing the selected activities

        cout << sa[i] << endl;
}
