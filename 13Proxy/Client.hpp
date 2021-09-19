class ISubject
{
private:
    /* data */
public:
    ISubject(/* args */) {}
    virtual ~ISubject() {}
    virtual void process() = 0;
};

class RealSubject: public ISubject {
    public:
    virtual void process() {

    }
};

class ClientApp
{
private:
    ISubject* subject;
public:
    ClientApp() {
        subject = new RealSubject();  // 很多时候拿不到对象，网络传输的
    }
    void DoTask() {
        subject->process();
    }
};