class Subject {
public:
    virtual ~Subject() = default;
public:
    virtual void someOperation() const = 0; 
};

class RealSubject : public Subject {
public:
    void someOperation() const override {

    }
};

class Proxy : public Subject {
public:
    Proxy(RealSubject* real) : realSub(real) {}
public:
    void someOperation() const override {
        otherOperation();
        realSub->someOperation();

    }
    void otherOperation() const {

    }
private:
    RealSubject* realSub;
};
