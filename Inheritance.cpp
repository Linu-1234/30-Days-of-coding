Task-
You are given two classes, Person and Student, where Person is the base class and Student is the derived class. Completed code for Person and a declaration for Student are provided for you in the editor. Observe that Student inherits all the properties of Person.
Complete the Student class by writing the following:
A Student class constructor, which has 4 parameters:
1.A string,firstname .
2.A string, lastname.
3.An integer,idnumber .
4.An integer array (or vector) of test scores, scores.
A char calculate() method that calculates a Student object's average and returns the grade character representative of their calculated average:

            Grading
  Letter              Average(a)
    O                 90<=a<=100
    E                 80<=a<=90
    A                 70<=a<=80
    P                 55<=a<=70
    D                 40<=a<=55
    T                   a<40

Input Format-
The locked stub code in the editor reads the input and calls the Student class constructor with the necessary arguments. It also calls the calculate method which takes no arguments.
The first line contains ,firstname ,lastname and id number, separated by a space. The second line contains the number of test scores. The third line of space-separated integers describes scores.

Output Format-
Output is handled by the locked stub code. Your output will be correct if your Student class constructor and calculate() method are properly implemented.

Sample Input-
Heraldo Memelli 8135627
2
100 80

Sample Output-
Name: Memelli, Heraldo
ID: 8135627
Grade: O  

  
Solution-
#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int id, vector<int> scores)
        : Person(firstName, lastName, id), testScores(scores) {}

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate() {
           int sum = 0;
            for (int score : testScores) {
                sum += score;
            }
            int average = sum / testScores.size();

            if (average >= 90)
                return 'O'; // Outstanding
            else if (average >= 80)
                return 'E'; // Exceeds Expectations
            else if (average >= 70)
                return 'A'; // Acceptable
            else if (average >= 55)
                return 'P'; // Poor
            else if (average >= 40)
                return 'D'; // Dreadful
            else
                return 'T'; // Troll
        }
};


int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}  
