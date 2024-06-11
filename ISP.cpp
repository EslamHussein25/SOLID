#include <iostream>



class Client_Data
{
  private:
    int  ID ;
    std::string FName ;
    std::string LName ;
    std::string Account ;
  public:
    Client_Data(int id , std::string fname , std::string lname , std::string account) : FName(fname) , LName(lname) , ID(id) , Account(account)
    {

    }

    int Get_ID()
    {
        return ID ;
    }

    std::string GetName()
    {
        return FName + LName ;
    }

    std::string GetAccount()
    {
        return Account ;
    }

};








//this class inhert from all ohter classes to implemnt the case if we need all the payment method to handle all cases 
//so here we doesn't add any methods else we need to apply common method in this case 





class IOrder_Cash
{
    public:
    virtual bool Pay_Cash_Order_handle(int order_price , Client_Data client) = 0 ;
};

class Order_Cash : IOrder_Cash
{
        public:
    bool Pay_Cash_Order_handle(int order_price , Client_Data client) override
    {
        // check data base for client 
        // make processes on db for orders 
        // make processes on db for client 
        // confirming order 
        return true ;
    }
};





class IOrder_Visa
{
    public:
    virtual bool Pay_Visa_Order_handle(int order_price , Client_Data client) = 0;
};

class Order_Visa : IOrder_Visa
{
    public:
   bool Pay_Visa_Order_handle(int order_price , Client_Data client)override
    {
        // check data base for client 
        // make processes on db for orders 
        // make processes on db for client 
        // check client Visa for payment allowness 
        // confirming order 
        // withdraw from Visa 
                return true ;

    }
};




class IOrder_Online_Payment
{
    public:
    virtual bool Pay_Online_Order_handle(int order_price , Client_Data client) = 0;
};

class Order_Online_Payment : IOrder_Online_Payment
{
    public:
    bool Pay_Online_Order_handle(int order_price , Client_Data client) override
    {
        // check data base for client 
        // make processes on db for orders 
        // make processes on db for client 
        // check client account for payment allowness 
        // confirming order 
        // withdraw from account 
                return true ;

    }

};




class Order : public Order_Cash , public Order_Visa , public Order_Online_Payment
{

//you can concatenate all processes in the system in one class and add new feature if needed in this case
public:
    void Print_Invoic(Client_Data cd)  
    {
        std::cout<<"Client ID: "<<cd.Get_ID() << " / Client Name" << cd.GetName()<<"\n";
    }
};


int main()
{

Client_Data client1(1 , "Eslam" , "Hussein" , "eslamhussein@gmail.com");

Order_Cash order_Cash;
bool Check = order_Cash.Pay_Cash_Order_handle(500 , client1);

Order_Online_Payment order_online ;
order_online.Pay_Online_Order_handle(2000 , client1);
Order order ;
order.Pay_Cash_Order_handle(20000 , client1);
order.Print_Invoic(client1);

if(Check)
{
    std::cout<<"Payment Done\n";
}
else 
{
    std::cout<<"Payment Fail\n";
}
    return 0;
}





/*

    bool Pay_Cash_Order_handle(int order_price , Client_Data client) 
    {
        // check data base for client 
        // make processes on db for orders 
        // make processes on db for client 
        // confirming order 
        return true ;
    }

    bool Pay_Visa_Order_handle(int order_price , Client_Data client)
    {
        // check data base for client 
        // make processes on db for orders 
        // make processes on db for client 
        // check client Visa for payment allowness 
        // confirming order 
        // withdraw from Visa 
                return true ;

    }

    bool Pay_Online_Order_handle(int order_price , Client_Data client) 
    {
        // check data base for client 
        // make processes on db for orders 
        // make processes on db for client 
        // check client account for payment allowness 
        // confirming order 
        // withdraw from account 
                return true ;

    }
*/