#include<string>
#include<list>
#include<iostream>

class Component{

    public:
    virtual void process() = 0;
    virtual ~Component(){}
};

// 树节点
class Composite : public Component
{
private:
    std::string name;
    std::list<Component*> elements;
public:
    Composite(const std::string& s) :name(s) {}

    void add(Component* element) {
        elements.push_back(element);
    }
    void remove(Component* element) {
        elements.remove(element);
    }
    ~Composite(){}

    void process() {
        // process current node
        std::cout << name << " Composite: process current node" << std::endl;
        // process leaf nodes
        for(auto &e: elements)
            e->process();
    }
};

// 叶子节点
class Leaf : public Component{
    std::string name;
public:
    Leaf(std::string s) : name(s) {}
    void process(){
        std::cout << name << " Leaf: process current node" << std::endl;
    }
};

void Invoke(Component & c) {
    //...
    c.process();
    //...
}

int main()
{
    Composite root("root");
    Composite treeNode1("treeNode1");
    Composite treeNode2("treeNode2");
    Composite treeNode3("treeNode3");
    Composite treeNode4("treeNode4");
    Leaf leaf1("leaf1");
    Leaf leaf2("leaf2");


    root.add(&treeNode1);
    treeNode1.add(&treeNode2);
    treeNode2.add(&leaf1);
    
    
    root.add(&treeNode3);
    treeNode3.add(&treeNode4);
    treeNode4.add(&leaf2);

    Invoke(root);

    return 0;
}

