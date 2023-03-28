#include <iostream>

class Strategy {
public:
   virtual ~Strategy() = default;
   virtual void doSomething() const = 0;
};

class concreteStrategy1 : public Strategy {
public:
    void doSomething() const {
        std::cout << "Strategy1";
    }
};

class concreteStrategy2 : public Strategy {
public:
    void doSomething() const {
        std::cout << "Strategy2";
    }
};

class Context {
public:
    Context(Strategy* strategy = nullptr) : strategy(strategy) {}
public:
    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }
    void someOperation() const {
        if (strategy) {
            strategy->doSomething();
        }
        else {
            std::cout << "No strategy";
        }
    } 
private:
    Strategy* strategy;
};
