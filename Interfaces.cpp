Task-
The AdvancedArithmetic interface and the method declaration for the abstract divisorSum(n) method are provided for you in the editor below.
Complete the implementation of Calculator class, which implements the AdvancedArithmetic interface. The implementation for the divisorSum(n) method must return the sum of all divisors of n.

Example-
n=25
The divisors of 25 are 1,5,25. Their sum is 31.
The divisors of 20 are `1,2,4,5,10,20 and their sum is 41.

Input Format-
A single line with an integer,n .

Output Format-
You are not responsible for printing anything to stdout. The locked template code in the editor below will call your code and print the necessary output.

Sample Input-
6

Sample Output-
I implemented: AdvancedArithmetic
12


Solution-
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};
class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                sum += i;
            }
        }
        return sum;
    }
};

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}
