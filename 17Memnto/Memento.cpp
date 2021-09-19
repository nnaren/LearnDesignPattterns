#include<string>

class Memento
{
private:
    std::string state;
public:
    Memento(const std::string &s) :state(s) {}
    std::string getState() const {return state;}
    void setState(const std::string & s) { state = s; }
    ~Memento() {}
};

class Originator
{
private:
    std::string state;
public:
    Originator() {}
    Memento createMomento() {
        Memento m(state);
        return m;
    }
    void setMomento(const Memento & m)
    {
        state = m.getState();  // 编码，序列化
    }
    ~Originator() {}
};

int main()
{
    Originator originator;

    // 捕获对象状态，存储到备忘录
    Memento mem = originator.createMomento();
    // ... 改变originator 状态

    // 从备忘录中恢复
    originator.setMomento(mem);
}