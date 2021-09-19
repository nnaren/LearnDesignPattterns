
// 目标接口（新接口）
class ITarget
{
private:
    /* data */
public:
    virtual void process() = 0;
};

// 遗留接口（老接口）
class IAdaptee
{
private:
    /* data */
public:
    virtual void foo(int data) = 0;
    virtual int bar()= 0;

};
// 遗留类型
class OldClass: public IAdaptee {
    // ....
    void foo(int data) {}
    int bar() {}
};

class Adapter :public ITarget
{
private:
    IAdaptee* pAdaptee_;
public:
    Adapter(IAdaptee* pAdaptee) {
        pAdaptee_ = pAdaptee;
    }
    virtual void process() {
        int  data = pAdaptee_->bar();
        pAdaptee_->foo(data);
    }
};

int main() {
    IAdaptee* pAdaptee = new OldClass();
    ITarget* pTarget = new Adapter(pAdaptee);
    pTarget->process();
}