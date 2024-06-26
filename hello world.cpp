Task-
To complete this challenge, you must save a line of input from stdin to a variable, print Hello, World. on a single line, and finally print the value of your variable on a second line.  
 
Input Format-
A single line of text denoting  (the variable whose contents must be printed).

Output Format-
Print Hello, World. on the first line, and the contents of  on the second line.

Sample Input-
Welcome to 30 Days of Code!
  
Sample Output-
Hello, World. 
Welcome to 30 Days of Code!


Solution:-
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    // Declare a variable named 'input_string' to hold our input.
    string input_string; 
    
    // Read a full line of input from stdin (cin) and save it to our variable, input_string.
    getline(cin, input_string); 
    
    // Print a string literal saying "Hello, World." to stdout using cout.
    cout << "Hello, World." << endl;

    // TODO: Write a line of code here that prints the contents of input_string to stdout.
    cout<<input_string<<endl;

    return 0;
}
  
  
