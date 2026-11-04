#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//FUNCTION TO FIND AND PRINT LCS

    void lcs (string s1, string s2){

         int length1 = s1.length();
         int length2 = s2.length();

//CREATE A 2D DP TABLE USING VECTOR

    vector<vector<int> >LCS(length1 + 1, vector<int>(length2 + 1, 0));

//FILL THE DP TABLE

    for(int i=1; i<=length1; i++){

        for(int j=1; j<=length2; j++){

            if(s1[i-1] == s2[j-1])
                LCS [i][j] = 1 + LCS[i-1][j-1];

            else if(s1[i-1] != s2[j-1] && LCS [i-1][j] == LCS[i][j-1])
                LCS[i][j] = LCS[i-1][j];

            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
}

//PRINTING DP TABLE

    cout << "\nDP Table:\n\n";

    for(int i = 0; i <= length1; i++){

        for(int j = 0; j <= length2; j++){

            cout << LCS[i][j] << " ";
        }

            cout << endl;
    }

//FINDING LCS STRING

    string result = "";

           int i = length1;
           int j = length2;

           while (i>0 && j>0){

               if(s1[i-1] == s2[j-1]){

                  result = s1[i-1] + result;
                  i--;
                  j--;
               }

               else if(LCS[i-1][j] > LCS[i][j-1]){

                  i--;
               }

               else{

                  j--;
               }
           }

//DISPLAY RESULT

     cout << "\nLength of LCS: " << LCS[length1][length2];
     cout << "\nLCS string: " << result << endl;

}

int main(){

    string s1, s2;

    cout << "Enter string 1: ";
    cin >> s1;

    cout << "Enter string 2: ";
    cin >> s2;

    lcs (s1,s2);
}
