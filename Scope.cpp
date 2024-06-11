The absolute difference between two integers, a and b , is written as |a-b| . The maximum absolute difference between two integers in a set of positive integers, ,elements is the largest absolute difference between any two integers in _elements .
The Difference class is started for you in the editor. It has a private integer array (elements) for storing N non-negative integers, and a public integer (maximun difference) for storing the maximum absolute difference.

Task-
Complete the Difference class by writing the following:
A class constructor that takes an array of integers as a parameter and saves it to the _elements instance variable.
A computeDifference method that finds the maximum absolute difference between any 2 numbers in _elements  and stores it in the maximumdifference instance variable.

Input Format-
You are not responsible for reading any input from stdin. The locked Solution class in the editor reads in 2 lines of input. The first line contains N, the size of the elements array. The second line has N space-separated integers that describe the _elements array.

Output Format-
You are not responsible for printing any output; the Solution class will print the value of the maximumdifference instance variable.

Sample Input-
STDIN   Function
-----   --------
3       __elements[] size N = 3
1 2 5   __elements = [1, 2, 5]
  
Sample Output-
4

  
Solution-  
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

	// Add your code here
     Difference(vector<int> e) {
        elements = e;
     }
        
        
    void computeDifference() {
        // Find the maximum and minimum values in the elements vector
        int maxElement = *max_element(elements.begin(), elements.end());
        int minElement = *min_element(elements.begin(), elements.end());
        
        // Calculate the maximum absolute difference
        maximumDifference = abs(maxElement - minElement);
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}  
