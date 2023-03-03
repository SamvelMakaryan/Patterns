class Product {
public:
    virtual ~Product() = default;
    virtual void someOperation() = 0;
};

class concreteProduct1 : public Product {
public:
    void someOperation() override {

    }
};

class concreteProduct2 : public Product {
public:
    void someOperation() override {

    }
};

class Creator {
public:
    virtual ~Creator() = default;
    virtual Creator* FactoryMethod() const = 0;
};

class Product1Creator : public Creator {
public:
    Creator* FactoryMethod() const override {
        return new Product1Creator;
    }
};

class Product2Creator : public Creator {
public:
    Creator* FactoryMethod() const override {
        return new Product2Creator;
    }
};
