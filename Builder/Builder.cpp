class Product {
public:
    void setPartA(bool part) {
        partA = part;
    }
    void setPartB(bool part) {
        partB = part;
    }
    void setPartC(bool part) {
        partC = part;
    }
private:
    bool partA = false;
    bool partB = false;
    bool partC = false;
};

class Builder {
public:
    virtual ~Builder() = default;
public: 
    virtual Builder* partA() = 0;
    virtual Builder* partB() = 0;
    virtual Builder* partC() = 0;
    virtual Product* getProduct() = 0;
};

class concreteBuilder1 : public Builder {
public:
    concreteBuilder1() {
        product = new Product;
    }
    ~concreteBuilder1() {
        delete product;
    }
public:
    concreteBuilder1* partA() override {
        product->setPartA(true);
        return this;
    }
    concreteBuilder1* partB() override {
        product->setPartB(true);
        return this;
    }
    concreteBuilder1* partC() override {
        product->setPartC(true);
        return this;
    }
    Product* getProduct() override {
     Product* tmp = product;
     product = new Product;
     return tmp;
    }
private:
    Product* product;
};

class Director {
public:
    void setBuilder(Builder* builder) {
        this->builder = builder; 
    }
    Builder* produceTypeA() {
        return builder->partA()->partB();
    }
    Builder* produceTypeB() {
        return builder->partC();
    }
private:
    Builder* builder;
};
