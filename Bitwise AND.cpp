Task-
Given set s={1,2,3......,N}. Find two integers, A and B (where A<B), from set  S such that the value of A&B is the maximum possible and also less than a given integer,K . In this case,&  represents the bitwise AND operator.

Function Description-
Complete the bitwiseAnd function in the editor below.
bitwiseAnd has the following paramter(s):
- int N: the maximum integer to consider
- int K: the limit of the result, inclusive

Returns
- int: the maximum value of A&B within the limit.

Input Format-
The first line contains an integer,T , the number of test cases.
Each of the T subsequent lines defines a test case as 2 space-separated integers, N  and K, respectively.

Sample Input-
STDIN   Function
-----   --------
3       T = 3
5 2     N = 5, K = 2
8 5     N = 8, K = 5
2 2     N = 8, K = 5
  
Sample Output-
1
4
0



Solution-
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bitwiseAnd' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER K
 */

int bitwiseAnd(int N, int K) {
    
    int max_val = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            int current = a & b;
            if (current < K && current > max_val) {
                max_val = current;
            }
        }
    }
    return max_val;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int count = stoi(first_multiple_input[0]);

        int lim = stoi(first_multiple_input[1]);

        int res = bitwiseAnd(count, lim);

        fout << res << "\n";
    }

    fout.close();

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
  
