#include <iostream>

class concreteComponent1;
class concreteComponent2;

class Visitor {
public:
    virtual ~Visitor() = default;
public:
    virtual void concreteOperation1(concreteComponent1*) const = 0;
    virtual void concreteOperation2(concreteComponent2*) const = 0;
};

class Component {
public:
    virtual ~Component() = default;
public:
    virtual void accept(Visitor*) = 0;
};

class concreteComponent1 : public Component {
public:
    void accept(Visitor* visitor) override {
        visitor->concreteOperation1(this);
    }
    void otherOperation() {
        std::cout << "Other operation 1";
    }
};

class concreteComponent2 : public Component {
public:
    void accept(Visitor* visitor) override {
        visitor->concreteOperation2(this);
    }
    void otherOperation() {
        std::cout << "Other operation 2";
    }
};

class concreteVisitor1 : public Visitor {
public:
    void concreteOperation1(concreteComponent1* component) const  override {
        std::cout << "Concrete operation 1 of Component 1 ";
        component->otherOperation();
    }
    void concreteOperation2(concreteComponent2* component) const  override {
        std::cout << "Concrete operation 1 of Component 2 ";
        component->otherOperation();
    }
};

class concreteVisitor2 : public Visitor {
public:
    void concreteOperation1(concreteComponent1* component) const override {
        std::cout << "Concrete operation 2 of Component 1";
        component->otherOperation();
    }
    void concreteOperation2(concreteComponent2* component) const override {
        std::cout << "Concrete operation 2 of Component 2";
        component->otherOperation();
    }
};
