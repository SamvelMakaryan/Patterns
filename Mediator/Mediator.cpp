#include <string>

class AbstractComponent;
class Mediator {
public:
    ~Mediator() = default;
public:
    virtual void someOperation(AbstractComponent*, std::string) const  =  0;
};

class AbstractComponent {
public:
    AbstractComponent(Mediator* mediator) : mediator(mediator) {}
protected:
    Mediator* mediator;
};

class ConcreteComponent1 : AbstractComponent {
public:
    void operation1() {
        mediator->someOperation(this, "1");
    }
    void operation2() {
        mediator->someOperation(this, "2");
    }
};

class ConcreteComponent2 : AbstractComponent {
public:
    void operation3() {
        mediator->someOperation(this, "3");
    }
    void operation4() {
        mediator->someOperation(this, "4");
    }
};

class ConcreteMediator : Mediator {
public:
    ConcreteMediator(ConcreteComponent1* component1, ConcreteComponent2* component2) : component1(component1), component2(component2) {}
public:
    void someOperation(AbstractComponent* component, std::string operation) const override {
        if (operation == "A") {
            component1->operation1();
            component2->operation3();
        }
        else if (operation == "C") {
            component1->operation2();
            component2->operation4();
            component1->operation1();
        }
        else if (operation == "D") {
            component2->operation3();
        }
    }
private:
    ConcreteComponent1* component1;
    ConcreteComponent2* component2;
};