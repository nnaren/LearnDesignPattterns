// 访问者模式
#include<iostream>
class Visitor
{
private:
    /* data */
public:
    
    virtual void visitElementA(ElementA& element) = 0;
    virtual void visitElementB(ElementB& element) = 0;
    Visitor(/* args */) {}

    virtual ~Visitor() {}
};

class Element
{
private:
    /* data */
public:
    virtual void accept(Visitor& visitor) = 0;
    
    virtual ~Element() {}
};

class ElementA : public Element
{
private:
    /* data */
public:
    virtual void accept(Visitor& visitor) override {
        visitor.visitElementA(*this);
    }
   
};

class ElementB : public Element
{
private:
    /* data */
public:
    virtual void accept(Visitor& visitor) override {
        visitor.visitElementB(*this);
    }
   
};

// =============================== 之上的内容不改变

class Visitor1 : public Visitor
{
private:
    /* data */
public:
    void visitElementA(ElementA& element) override {
        std::cout << "Visitor1 is processing ElementA" << std::endl;
    }
    void visitElementB(ElementB& element) override {
        std::cout << "Visitor1 is processing ElementB" << std::endl;
    }
};

class Visitor2 : public Visitor
{
private:
    /* data */
public:
    void visitElementA(ElementA& element) override {
        std::cout << "Visitor2 is processing ElementA" << std::endl;
    }
    void visitElementB(ElementB& element) override {
        std::cout << "Visitor2 is processing ElementB" << std::endl;
    }
};

int main()
{
    Visitor2 visitor;
    ElementB element;
    element.accept(visitor);   // double dispatch 二次辨析，两次派遣

    ElementA element;
    element.accept(visitor);
}