#include<bits/stdc++.h>
using namespace std;
// This program is used to demonstrate that "how we can convert primitive data type to user defind type"
class Distance {
    private:
        int feet,inches;

    public:
        // First Method to convert primitive type to user defined type
        // Using Constructor conversion 
        /**
         * The Distance constructor converts inches to feet and inches.
         * 
         * @param inches The parameter "inches" is an integer representing the length in inches.
         */
        Distance(int inches) {
            cout << "Using Constructor Conversion Method" << endl;
            this->inches = inches%12;
            this->feet = inches/12;
        }

        // 2nd method using operator overloading
        // By overloading = operator
        /**
         * The function overloads the assignment operator to convert inches to feet and inches.
         * 
         * @param inches The parameter "inches" is an integer value representing the length in inches.
         */
        void operator=(int inches) {
            cout << "Using operator overloading" << endl;
            this->inches = inches%12;
            this->feet = inches/12;
        } 
        void show() {
            cout << feet << "\"" << inches << "'" << endl;
        }
};
int main()
{
    int inches = 74;
    // Using first method
    Distance d1(inches);
    d1.show();

    // Using 2nd method
    inches = 80;
    // destination : distance , source : int
    d1 = inches;
    d1.show();
    return 0;
}