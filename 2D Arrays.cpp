Context-
Given a 6x6 2D Array,A:
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
We define an hourglass in A to be a subset of values with indices falling in this pattern in A's graphical representation:
a b c
  d
e f g
There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' values.

Task-
Calculate the hourglass sum for every hourglass in A, then print the maximum hourglass sum.

Example-
In the array shown above, the maximum hourglass sum is 7 for the hourglass in the top left corner.

Input Format-

There are 6 lines of input, where each line contains 6 space-separated integers that describe the 2D Array A.  

Output Format-
Print the maximum hourglass sum in A.

Sample Input-
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
  
Sample Output-
19

Solution-
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int main()
{

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }
    int max_sum = INT_MIN;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int top = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            int middle = arr[i+1][j+1];
            int bottom = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            int hourglass_sum = top + middle + bottom;
            if (hourglass_sum > max_sum) {
                max_sum = hourglass_sum;
            }
        }
    }

    cout << max_sum << endl;


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
  
