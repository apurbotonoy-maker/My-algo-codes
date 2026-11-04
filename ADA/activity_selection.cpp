#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct Activity{

       char n[10];
       int st,ft;
};

int main(){

    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity activity [n];
    for (int i=0;i<n;i++){

        cout << "Enter the name of activity " << i+1 << " : ";
        cin >> activity[i].n;
        cout << "Enter the start time of activity " << i+1 << " : ";
        cin >> activity[i].st;
        cout << "Enter the finish time of activity " << i+1 << " : ";
        cin >> activity[i].ft;
    }

    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (activity[i].ft > activity[j].ft){

                Activity temp = activity[i];
                activity[i] = activity[j];
                activity[j] = temp;
            }
        }
    }

            vector <string> sa;
            sa.push_back(activity[0].n);
            int let = activity[0].ft;
            int count = 1;

            for (int i=1;i<n;i++){
                if (activity[i].st >= let){
                    sa.push_back(activity[i].n);
                    let = activity[i].ft;
                    count ++;
                }
            }


            cout << "Total number of selected activities are: " << count << endl;
            cout << "Selected activities are: " << endl;
            for (int i=0;i<sa.size();i++)

                cout << sa[i] << endl;



}
