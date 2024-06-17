Task-
Given an array,a , of size n distinct elements, sort the array in ascending order using the Bubble Sort algorithm above. Once sorted, print the following 3 lines:
Array is sorted in numSwaps swaps.
where numSwaps is the number of swaps that took place.
First Element: firstElement
where firstElement is the first element in the sorted array.
Last Element: lastElement
where LastElement is the last element in the sorted array.
Hint: To complete this challenge, you will need to add a variable that keeps a running tally of all swaps that occur during execution.

Example-
a=[4,3,2,1]
original a: 4 3 1 2
round 1  a: 3 1 2 4 swaps this round: 3
round 2  a: 1 2 3 4 swaps this round: 2
round 3  a: 1 2 3 4 swaps this round: 0
In the first round, the 4 is swapped at each of the 3 comparisons, ending in the last position. In the second round, the 3 is swapped at 2 of the 3 comparisons. Finally, in the third round, no swaps are made so the iterations stop. The output is the following:

Array is sorted in 5 swaps.
First Element: 1
Last Element: 4
  
Input Format-
The first line contains an integer,n , the number of elements in array a.
The second line contains n space-separated integers that describe a[0],a[1],....a[n-1].


Output Format-
Print the following three lines of output:
Array is sorted in numSwaps swaps.
where  is the number of swaps that took place.
First Element: firstElement
where  is the first element in the sorted array.
Last Element: lastElement
where  is the last element in the sorted array.
  
Sample Input 0-
3
1 2 3
  
Sample Output 0-
Array is sorted in 0 swaps.
First Element: 1
Last Element: 3

Sample Input 1-
3
3 2 1
  
Sample Output 1-
Array is sorted in 3 swaps.
First Element: 1
Last Element: 3


Solution-
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    // Write your code here
    int numSwaps=0;
    for(int i=0;i<=n;i++){
        bool swapped=false;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j + 1]);
                numSwaps++;
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    cout<<"Array is sorted in "<<numSwaps<<" swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
   cout <<"Last Element: " << a[n - 1] << endl; 

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
