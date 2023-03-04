class ProductA {
public:
    virtual ~ProductA() = default;
    virtual void something() = 0;
};

class ProductB {
public:
    virtual ~ProductB() = default;
    virtual void something() = 0;
};

class concreteProductA1 : public ProductA {
public:
    void something() override {

    }
};

class concreteProductA2 : public ProductA {
public:
    void something() override {

    }
};

class concreteProductB1 : public ProductB {
public:
    void something() override {

    }
};

class concreteProductB2 : public ProductB {
public:
    void something() override {

    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual ProductA* createProductA() const = 0;
    virtual ProductB* createProductB() const = 0;
};

class FactoryA : public AbstractFactory {
public:
    ProductA* createProductA() const override {
        return new concreteProductA1;
    }
    ProductB* createProductB() const override {
        return new concreteProductB1;
    }
};

class FactoryB : public AbstractFactory {
public:
    ProductA* createProductA() const override {
        return new concreteProductA2;
    }
    ProductB* createProductB() const override {
        return new concreteProductB2;
    }
};
