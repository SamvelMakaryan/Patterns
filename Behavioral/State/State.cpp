#include <iostream>
#include <string>

class Context;

class State {
public:
    State(Context* context) : context(context) {}
    virtual ~State() = default;
public:
    virtual void handle1() = 0;
    virtual void handle2() = 0;
protected:
    Context* context;
};

class Context {
public:
    Context(State* state) : state(state) {}
public:
    void request1() {
        state->handle1();
    }
    void request2() {
        state->handle2();
    }
private:
    State* state;
};

class ConcreteState1 : public State {
public:
    ConcreteState1(Context* context) : State(context) {}
public:
    void handle1() override {
        std::cout << "Changing state";
    }
    void handle2() override {
        std::cout << "Changing state";
    }
};

class ConcreteState2 : public State {
public:
    ConcreteState2(Context* context) : State(context) {}
public:
    void handle1() override {
    
    }
    void handle2() override {
        std::cout << "Changing state";
    }
};
