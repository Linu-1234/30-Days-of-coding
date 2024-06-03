Task-
Given a string, S, of length N that is indexed from 0 to N-1, print its even-indexed and odd-indexed characters as 2 space-separated strings on a single line (see the Sample below for more detail).
Note:  is considered to be an even index.

Example-
S=adbecf
Print abc def  

Input Format-
The first line contains an integer,T  (the number of test cases).
Each line i of the T subsequent lines contain a string,S.

Output Format-
For each String Sj (where 0<=J<=T-1), print 's even-indexed characters, followed by a space, followed by  Sj's odd-indexed characters. 

Sample Input-
2
Hacker
Rank

Sample Output-
Hce akr
Rn ak  

Solution-
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int t;
    cin >> t; // number of test cases
    cin.ignore(); // ignore the newline character after reading integer

    while (t--) {
        string s;
        getline(cin, s); // read the string
        
        string evenChars = "", oddChars = "";

        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                evenChars += s[i];
            } else {
                oddChars += s[i];
            }
        }

        cout << evenChars << " " << oddChars << endl;
    }
  
    return 0;
}
  
  
