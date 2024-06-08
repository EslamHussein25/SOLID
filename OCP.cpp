#include <iostream>


//i will never edit or change this class later 
// but  i can to extend new classes this classes can be inhert from this class and apply the functionality of this method according to the class requeird 
class IEmployee 
{

// we can add here some properties if you want 

// here the most important methods that will be implmented in our concret class 

public:

double Cal_Salary(int Hours);

};

class Manager : public IEmployee
{
    public :
    double Cal_Salary(int Hours)
    {
        return Hours * 120 ;
    }
};

class Worker : public IEmployee
{
    public :
    double Cal_Salary(int Hours)
    {
        return Hours * 60 ;
    }
};


int main()
{

Manager m ;
std::cout<<"manager  salary is : "<<m.Cal_Salary(60)<<"\n";

Worker w ;
std::cout<<"worker  salary is : "<< w.Cal_Salary(50)<<"\n";
    return 0 ;
}
