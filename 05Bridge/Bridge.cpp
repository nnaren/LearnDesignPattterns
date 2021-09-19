
#include<string>

class Image
{
private:
    /* data */
public:
    Image(/* args */) {}
    ~Image() {}
};

class Messager
{
protected:
    MessageImp* messagerImp_;    // new 
public:
    virtual void Login(std::string username, std::string password) = 0;
    virtual void SendMessage(std::string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Messager() {}
};

class MessageImp
{
private:
    /* data */
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0; 
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    virtual ~MessageImp() {}

};

class PCMessagerImp : public MessageImp
{
private:
    /* data */
public:
    virtual void PlaySound() {}
    virtual void DrawShape() {}
    virtual void WriteText() {}
    virtual void Connect() {}
};

class MobileMessagerImp : public MessageImp
{
private:
    /* data */
public:
    virtual void PlaySound() {}
    virtual void DrawShape() {}
    virtual void WriteText() {}
    virtual void Connect() {}
};

class MessagerLite : public Messager
{

public:
    MessagerLite(/* args */) {}
    ~MessagerLite() {}
    virtual void Login(std::string username, std::string password) {
        messagerImp_->Connect();
        //...
    }
    virtual void SendMessage(std::string message) {
        messagerImp_->WriteText();
        //...
    }
    virtual void SendPicture(Image image) {
        messagerImp_->DrawShape();
    }
};

class MessagerPerfect : public Messager
{
private:
    MessageImp* messagerImp_;    // new 
public:
    MessagerPerfect(/* args */) {}
    ~MessagerPerfect() {}
    virtual void Login(std::string username, std::string password) {
        messagerImp_->PlaySound();
        messagerImp_->Connect();
        //...
    }
    virtual void SendMessage(std::string message) {
        messagerImp_->PlaySound();
        messagerImp_->WriteText();
        //...
    }
    virtual void SendPicture(Image image) {
        messagerImp_->PlaySound();
        messagerImp_->DrawShape();
    }
};

void Process() {
    
}