#include <iostream>

/*
the main idea of this code is: 
if any employee work less than 60 hour  will accountable as worker and we don't care about his real postion 

the same thing with any employee work over 60 hour will get tam leader salary 

and any one work over 100 hour will accountable as manager 
*/


// class to inhert for every empolyee from it to implment salary calculation method but with difference body 
class Worker
{

public:

    virtual int Cal_Salary(int Hours)  // also we may make this method abstract method to make this class abstract and use it
    {
        std::cout<<"\nWorker Category\n";
        return Hours * 60;
    }


};

class Team_Leader_category : public Worker
{

public:

int Cal_Salary(int Hours) 
{
    std::cout<<"\nLeader Category\n";
    return Hours * 100 ;
}

};

class Manager_category : public Worker
{

public:

int Cal_Salary(int Hours) override
{
    std::cout<<"\nManager Category\n";
    return Hours * 120 ;
}

};





int main()
{
    Worker * ptr_worker ;
    Worker  worker ;
    Team_Leader_category leader ;
    Manager_category manager ;
    int Hours ;
    std::cout<<"Please Enter the Hours: ";
    std::cin>>Hours ; 
    std::cout<<"\nWait... \n";
    bool falg = true ;

    if( Hours <= 40)//this employee will be held accountable as worker category 
    {
         ptr_worker = &worker;
    }
    else if (Hours > 40 && Hours <= 60)//this employee will be held accountable as team leader  category 
    {
            std::cout<<"\n2\n";
        ptr_worker = &leader;
    }
    else if (Hours > 60 && Hours <= 80)//this employee will be held accountable as manager category 
    {
        ptr_worker = &manager;
    }
    else 
    {
        std::cout<<"Error";
        falg = false ;
    }

    if(falg)
    {
        std::cout<<"Your Salary is: " << ptr_worker->Cal_Salary(Hours) << "  \n  \n \n Thank you \n";
    }

    
    return 0;
}
