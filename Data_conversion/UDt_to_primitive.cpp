#include<bits/stdc++.h>
using namespace std;
// This program is used to demonstrate that "how we can convert user defined type to primitive type"
class Distance {
    private:
        int feet,inches;

    public:
        Distance(int feet,int inches) {
            this->feet = feet;
            this->inches = inches;
        }    

        
        /**
         * The above function converts a measurement in feet and inches to inches.
         * 
         * @return the value of the variable "inch", which is the total number of inches calculated by
         * multiplying the value of "feet" by 12 and adding the value of "inches".
         */
        operator int() {
            double inch;
            inch = feet * 12 + inches;
            return inch;
        }
};
int main()
{
    Distance d1(6,4);
    /* `int inches = d1;` is using the conversion operator defined in the `Distance` class to convert
    the `d1` object of type `Distance` to an `int`. The conversion operator is invoked automatically
    when an object of the `Distance` class is assigned to a variable of type `int`. In this case,
    the `feet` and `inches` values of the `d1` object are converted to inches and assigned to the
    `inches` variable. */
    // destination : int, source : distance object
    int inches = d1;
    cout << inches << endl;
    return 0;
}