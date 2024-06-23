Task-
Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:
1.If the book is returned on or before the expected return date, no fine will be charged (i.e.:fine=0) .
2.If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, fine=15 Hackos x (the number of days late).
3.If the book is returned after the expected return month but still within the same calendar year as the expected return date, the fine=500 Hackos x (the number of months late).
4.If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10000 Hackos.
  
Example-
d1,m1,y1=12312014 returned date
d2,m2,y2=112015 due date
The book is returned on time, so no fine is applied.

d1,m1,y1==112015  returned date
d2,m2,y2=12312014due date
The book is returned in the following year, so the fine is a fixed 10000.

Input Format-
The first line contains 3 space-separated integers denoting the respective date, month,year and  on which the book was actually returned.
The second line contains 3 space-separated integers denoting the respective date,month ,year and  on which the book was expected to be returned (due date).

Output Format-
Print a single integer denoting the library fine for the book received as input.

Sample Input-
STDIN       Function
-----       --------
9 6 2015    day = 9, month = 6, year = 2015 (date returned)
6 6 2015    day = 6, month = 6, year = 2015 (date due)
  
Sample Output-
45


Solution-
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // Variables to hold the actual and expected return dates
    int d1, m1, y1; // actual return date
    int d2, m2, y2; // expected return date
    
    // Read the actual return date
    cin >> d1 >> m1 >> y1;
    
    // Read the expected return date
    cin >> d2 >> m2 >> y2;
    
    // Calculate the fine
    int fine = 0;
    
    // Compare the dates and calculate the fine based on the rules
    if (y1 < y2) {
        fine = 0;
    } else if (y1 == y2) {
        if (m1 < m2) {
            fine = 0;
        } else if (m1 == m2) {
            if (d1 <= d2) {
                fine = 0;
            } else {
                fine = 15 * (d1 - d2);
            }
        } else {
            fine = 500 * (m1 - m2);
        }
    } else {
        fine = 10000;
    }
    
    // Output the fine
    cout << fine << endl;
    
    return 0;
}
  
  
