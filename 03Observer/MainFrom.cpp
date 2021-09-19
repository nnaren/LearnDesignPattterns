
#include <string>
#include <iostream>
#include "FileSpliter.hpp"
class Form{};

class TextBox{};
class ProgressBar{
private:
    int value_;
public:
    void setValue(int value);
};
class MainForm : public Form,  public IProgress  // 具体观察者1
{
private:
    TextBox* txtFileNumber;
    ProgressBar* progressBar;   
    
public:
    MainForm(/* args */);
    ~MainForm();
    void Button1Click(){
        std::string filePath = "textFilePath->getText()";
        int number = 0; //atoi(txtFileNumber->getText().c_str())
        FileSplitter splitter(filePath, number, this);
        splitter.split();
    }

    virtual void DoProgress(float value){
        progressBar->setValue(value);
    }
};

class ConsoleNotifier : public IProgress  // 具体观察者2
{
private:
    /* data */
public:
    ConsoleNotifier(/* args */);
    ~ConsoleNotifier();
    virtual void DoProgress(float value){
        std::cout<<".";
    }
};

