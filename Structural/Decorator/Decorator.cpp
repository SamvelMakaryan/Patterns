#include <string>

class Component {
public:
    virtual ~Component() = default;
public:
    virtual std::string someOperation() const = 0;
};

class concreteComponent : public Component {
public:
    std::string someOperation() const override {
        return "concreteComponent";
    }
};

class Decorator : public Component {
public:
    Decorator(Component* component) : component(component) {}
public:
    std::string someOperation() const override {
        return "Decorator + " + component->someOperation();
    }
protected:
    Component* component;
};

class concreteDecorator1 : public Decorator {
public:
    concreteDecorator1(Component* component) : Decorator(component) {}
public:
    std::string someOperation() const override {
        return "concreteDecorator1 + " + Decorator::component->someOperation();
    }
};

class concreteDecorator2 : public Decorator {
public:
    concreteDecorator2(Component* component) : Decorator(component) {}
public:
    std::string someOperation() const override{
        return "concreteDecorator2 + " + Decorator::component->someOperation();
    }
};


