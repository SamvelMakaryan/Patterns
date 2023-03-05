class Implementation {
public:
    virtual ~Implementation() = default;
public:
    virtual void operation() = 0;
};

class Implementation1 : public Implementation {
public:
    void operation() override {

    }
};

class Implementation2 : public Implementation {
public:
    void operation() override {

    }
};

class Abstraction {
public:
    Abstraction(Implementation* imp) : imp(imp) {}
    virtual ~Abstraction() = default;
public:
    virtual void someOperation() = 0;
protected:
    Implementation* imp;
};

class OtherAbstraction1 : public Abstraction {
public:
    void someOperation() override {
        imp->operation();
    }
};

class OtherAbstraction2 : public Abstraction {
public:
    void someOperation() override {
        imp->operation();
    }
    void otherOperation() {

    }
};
