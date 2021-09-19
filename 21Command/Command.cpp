
#include<vector>
#include<iostream>

class Command 
{
public:
    virtual void execute() = 0;
};


class ConcreteCommand1 : public Command
{
private:
    std::string arg;
public:
    ConcreteCommand1(const std::string & a) : arg(a) {}
    void execute() override
    {
        std::cout << "#1 process ... " << arg << std::endl;

    }
};

class ConcreteCommand2 : public Command
{
private:
    std::string arg;
public:
    ConcreteCommand2(const std::string & a) : arg(a) {}
    void execute() override
    {
        std::cout << "#2 process ... " << arg << std::endl;
    }
};

class MacroCommand : public Command
{
private:
    std::vector<Command*> commands;
public:
    void addCommand(Command *c) { commands.push_back(c); }
    void execute()  override {
        for (auto &c : commands)
        {
            c->execute();
        }
    }
};
int main()
{
    ConcreteCommand1 command1("Arg ###");
    ConcreteCommand2 command2("Arg $$$");

    MacroCommand macro;
    macro.addCommand(&command1);
    macro.addCommand(&command2);
    macro.execute();
}