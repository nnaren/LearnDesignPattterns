
#include"Splitter.hpp"
#include"SplitterFactory.hpp"
 int main(int argc, char const *argv[])
{

}
class Form{};

class TextBox{};

class MainForm : public Form
{
    TextBox* txtFileNumber;
    SplitterFactory* factory;
public:
    MainForm(SplitterFactory* factory)
    {
        this->factory = factory;
    }
    void Button1Click(){
    // ISplitter* splitter =  new BinarySplitter(filePath, number);  //具体
    // SplitterFactory* factory;
    ISplitter* splitter =  
        factory->CreateSplitter();   // 多态new
    splitter->split();

    }
}