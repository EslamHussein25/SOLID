#include <iostream>


template<typename T>
class IMessage
{

    private:

    public:
        virtual void SendMessage(std::string msg ,T data) = 0;

};


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

