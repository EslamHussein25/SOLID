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


int main()
{
    //select  the protocol to inject in your high level class 
SPI<double> spi;
//using high level class with low level task class injection using constructor  injection 
GPS<double> gps1(&spi) ;

//send location without any care about how to send 
gps1.Send_Location(31.2562 , 30.2506);

    return  0;
}

