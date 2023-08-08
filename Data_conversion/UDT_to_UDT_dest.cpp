#include<iostream>
#define INCH 12
using namespace std;
// if the coversion function is defined in the source class then we need overload cast operator 
// if the coversion function is defined in the destination class then we use single parameter constructor 

// In the below progrm :   
//  We define "Conversion function in destination class"
//  using single parameter constructor
class Feet // Source class 
{ 
    int fe;
    public:
        Feet(int fe){
            this->fe = fe;
        }
        void show(){
            cout << "Feet = " << fe << endl;
        }
        int ret_feet(){
            return fe;
        }
};
class Inch    // destination class
{
    int inches;
        public:
        Inch() : inches(0) {}
        // Single Parameter constructor 
        Inch(Feet f1) {
            // f1.ret_feet() ==> as fe is private in Feet class 
            inches = f1.ret_feet() * INCH;
        }
        void show(){
            cout << "Inches = " << inches;
        }
};

int main()
{
    Feet f1(3);
    f1.show();
    Inch i1;
    i1 = f1;
    i1.show();
    return 0;
}