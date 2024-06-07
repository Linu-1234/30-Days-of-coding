Task
Given a base-10 integer,n, convert it to binary (base-2). Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation. When working with different bases, it is common to show the base as a subscript.
Example-
n=125
The binary representation of 125(10) is 1111101(2). In base 10, there are 5 and 1 consecutive ones in two groups. Print the maximum,5 .  

Input Format-
A single integer, n.  

Output Format-
Print a single base-10 integer that denotes the maximum number of consecutive 1's in the binary representation of n.

Sample Input 1-
5
Sample Output 1-
1
Sample Input 2-
13
Sample Output 2-
2


Solution-
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
string trim(const string &);

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(trim(n_temp));
    string binary = bitset<32>(n).to_string();

    // Remove leading zeros
    binary = binary.substr(binary.find('1'));

    int max_consecutive_ones = 0;
    int current_count = 0;

    for (char c : binary) {
        if (c == '1') {
            current_count++;
            if (current_count > max_consecutive_ones) {
                max_consecutive_ones = current_count;
            }
        } else {
            current_count = 0;
        }
    }

    cout << max_consecutive_ones << endl;
    return 0;
}

string ltrim(const string &str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    return (start == string::npos) ? "" : str.substr(start);
}

string rtrim(const string &str) {
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}

  

