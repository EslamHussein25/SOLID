#include <iostream>
#include <string>
#include <vector>

class user_get_data
{

public:
int id ;
std::string name ;
user_get_data(int  _id , std::string _name ): id(_id) , name(_name)
{}

std::string user_name()
{
    return name ;
}

int user_id()
{
    return id ;
}

};


class User_Payment

{



public:
enum methods {manual , Visa_Debit , visa_credit , VCash , Fawary , ECash} ;
std::vector<std::string> allmethods = {"manual" , "Visa_Debit" , "visa_credit" , "VCash" , "Fawary" , "ECash"} ;

User_Payment(user_get_data _u): u(_u) 
{
   // u.id = _u.id ; // if you need some parameter you can use thsi method 
}

void Select_method(methods m)
{
    user_method = allmethods[m];
}

void make_payment()
{
    std::cout<<"this user data for payment operation: \n"<< "user id: " <<u.id<<"\n name: "<<u.name <<"\nmethod: "<<user_method <<"\n the op done";
}


private:

std::string user_method;
user_get_data u;

};


int main()
{
    user_get_data u1(1 , "Eslam");
    User_Payment p(u1);
    p.Select_method(User_Payment::Fawary);
    p.make_payment();
    return 0;
}

