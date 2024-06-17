#include <iostream>

//interface class 
//templated class for interfcing between high level class and low level class 
template<typename T>
class IMessage
{

    private:

    public:
        virtual void SendMessage(std::string msg ,T data) = 0;

};

/******************low level classes ***********************/
//concret class for UART : low level protocol to implemnt some low level functions : send messages 
template<typename T>
class UART : public IMessage<T>
{
    private :

    public:
        void SendMessage(std::string msg , T data) override
        {
            std::cout<<"Message sent by: UART\n"<<msg<<data<<"\n";
        }
};

//concret class for SPI : low level protocol to implemnt some low level functions : send messages 
template<typename T>
class SPI : public IMessage<T>
{
    private :

    public:
        void SendMessage(std::string msg , T data) override
        {
            std::cout<<"Message sent by: SPI\n"<<msg<<data<<"\n";
        }
};

//and we can add any other protocol here without any problems in high level classes 


//high level depend on interface class for perform low tasks with abstraction methods 
//here the injection using constructor injection method 
template<typename T>
class GPS
{
    private:
    IMessage<T> * _msg ;
    //example for bad design 
    UART<T> uart ;

    public:
    GPS(IMessage<T> * msg)
    {
        _msg = msg ;
    }

    void Send_Location(T Lat , T Lon)
    {
        _msg->SendMessage("Lat location: " , Lat);
        _msg->SendMessage("Lon location: " , Lon);
    }

/*exmaple for bad design */
    void Send_Location_with_bad_Design(T Lat , T Lon)
    {
        uart.SendMessage("Lat location: " , Lat);
        uart.SendMessage("Lon location: " , Lon);
    }
    

};


template<typename T>
class RF
{
private:
IMessage<T> * _method;
public:

void Send_Data(IMessage<T> * method , std::string msg , T Distance)
{
    method->SendMessage(msg , Distance);
}


};



template<typename T>
class Wifi
{
public :
IMessage<T> * method ;

void Send_Data(std::string msg , T Data)
{
    method->SendMessage(msg , Data);
}

};



int main()
{
    //select  the protocol to inject in your high level class 
SPI<double> spi;
SPI<int> spi_int;
UART<std::string> uart_int;
//using high level class with low level task class injection using constructor  injection 
GPS<double> gps1(&spi) ;

//send location without any care about how to send 
gps1.Send_Location(31.2562 , 30.2506);

std::cout<<"\n";
std::cout<<"\n";
std::cout<<"\n";

//send location using bad design 
gps1.Send_Location_with_bad_Design(31.2562 , 30.2506);


std::cout<<"\n";
std::cout<<"\n";
std::cout<<"\n";

//another example for injection method 
//using method injection 
RF<int> rf ;
rf.Send_Data(&spi_int , "Distance: " , 130);

std::cout<<"\n";
std::cout<<"\n";
std::cout<<"\n";


//another example for injection method 
//using properties injection 
Wifi<std::string> wifi;
//here must be select the method before send the message to avoid run time error else if we make default method in our code 
wifi.method = &uart_int;
wifi.Send_Data("Sensor Data:" , "H: 30 , T: 35 , NPK:{20,30,50}");


std::cout<<"\n";

    return  0;
}

