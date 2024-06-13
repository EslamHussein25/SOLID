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
};


int main()
{
SPI<double> spi;
GPS<double> gps1(&spi) ;

gps1.Send_Location(31.2562 , 30.2506);

    return  0;
}

