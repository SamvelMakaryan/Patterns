#include <iostream>

class Command {
public:
    virtual ~Command() = default;
public:
    virtual void execute() = 0;
};

class Reciever {
public:
    void operation1() {
        std::cout << "Opertaion 1 ";
    }
    void operation2() {
        std::cout << "Opertaion 2 ";
    }
};

class concreteCommand1 : public Command {
public:
    concreteCommand1(Reciever* reciever) : reciever(reciever) {}
public:
    void execute() override {
        std::cout << "Concrete command 1";
        reciever->operation1();
    }
private:
    Reciever* reciever;
};


class concreteCommand2 : public Command {
public:
    concreteCommand2(Reciever* reciever) : reciever(reciever) {}
public:
    void execute() override {
        std::cout << "Concrete command 2 ";
        reciever->operation1();
        reciever->operation2();
    }
private:
    Reciever* reciever;
};

class Invoker {
public:
    Invoker(Command* command1, Command* commmand2) : command1(command1), command2(command2) {}
    Invoker() : command1(nullptr), command2(nullptr) {}
public:
    void setCommand1(Command* command) {
        command1 = command;
    }
    void setCommand2(Command* command) {
        command2 = command;
    }
    void someOperation(){
        if (command1) {
            command1->execute();
        }
        else {
            std::cout << "set command1 ";
        }
        if (command2) {
            command2->execute();
        }
        else {
            std::cout << "set command2 ";
        }
    }        
private:
    Command* command1;
    Command* command2;
};
