Task-
A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself. Given a number, n, determine and print whether it is Prime or Not prime.
Note: If possible, try to come up with a O(root(n)) primality algorithm, or see what sort of optimizations you come up with for an O(n) algorithm. Be sure to check out the Editorial after submitting your code.

Input Format-
The first line contains an integer,T , the number of test cases.
Each of the T subsequent lines contains an integer, n, to be tested for primality.

Output Format-
For each test case, print whether n is Prime or Not prime on a new line.

Sample Input-
3
12
5
7
  
Sample Output-
Not prime
Prime
Prime


Solution-
  #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string is_prime(int n) {
    if (n <= 1) {
        return "Not prime";
    }
    if (n <= 3) {
        return "Prime";
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return "Not prime";
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return "Not prime";
        }
    }
    return "Prime";
}

int main() {
    int t;
    cin >> t;
    vector<int> numbers(t);
    
    for (int i = 0; i < t; ++i) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < t; ++i) {
        cout << is_prime(numbers[i]) << endl;
    }
    
    return 0;
}
