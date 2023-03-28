#include <iostream>

class AbstractClass {
public:
    virtual ~AbstractClass() = default;
public:
    void templateMethod() {
        operation1();
        operation2();
        hook1();
        hook2();
        requiredOperation1();
        requiredOperation2();
    }
protected:
    void operation1 () const {
        std::cout << "operation1";
    }
    void operation2 () const {
        std::cout << "operation2";
    }
    virtual void hook1() const {}
    virtual void hook2() const {}
    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;
};

class concretClass1 : public AbstractClass {
protected:
    void requiredOperation1() const override {
        std::cout << "concrete class1 operation1";
    }
    void requiredOperation2() const override {
        std::cout << "concrete class1 operation2";
    }
    void hook1() const override {
        std::cout << "concrete class1 hook1";
    }
};

class concretClass2 : public AbstractClass {
protected:
    void requiredOperation1() const override {
        std::cout << "concrete class2 operation1";
    }
    void requiredOperation2() const override {
        std::cout << "concrete class2 operation2";
    }
    void hook2() const override {
        std::cout << "concrete class2 hook2";
    }
};
