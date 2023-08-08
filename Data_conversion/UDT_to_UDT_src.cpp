#include<iostream>
#define INCH 12
using namespace std;
// if the coversion function is defined in the source class then we need overload cast operator 
// if the coversion function is defined in the destination class then we use single parameter constructor 

// In the below progrm :   
// We define "Conversion function in source class
// By overloading the cast operator 
class Inch // Destination class
{
    int inches;
    public:
        Inch() : inches(0) {}
        Inch(int inches){
            this->inches = inches;
        }
        void show(){
            cout << "Inches = " << inches << endl;
        }
};
class Feet // Source class 
{ 
    int feet;
    public:
        Feet(int f){
            this->feet = f;
        }
        /**
         * The above function converts a length in feet to inches.
         * 
         * @return The code is returning an instance of the `Inch` class.
         */
        operator Inch(){
            int in = feet * INCH;
            // Inch(in) calling single parameter constructor of Inch class(destination class)
            return Inch(in);
        }
        void show(){
            cout << "Feet = " << feet << endl;
        }
};
int main()
{
    Feet f1(3);
    f1.show();
    Inch i1;
    // Destination : inch , Source : feet 
    i1 = f1;
    i1.show();
    return 0;
}