

class ISubject
{
private:
    /* data */
public:
    ISubject(/* args */) {}
    virtual ~ISubject() {}
    virtual void process() = 0;
};
// Proxy设计 :安全控制，分布式，性能提升
class SubjectProxy : public ISubject
{

public:
  
    // 安全控制，分布式，性能提升
    void process() {
        // 对RealSubject的一种间接访问
    }
};

class ClientApp
{
private:
    ISubject* subject;
public:
    ClientApp() {
        subject = new SubjectProxy();  // 通过某种工厂方法
    }
    void DoTask(){
        // ...
        subject->process();
        // ...
    }

    ~ClientApp() {}
};