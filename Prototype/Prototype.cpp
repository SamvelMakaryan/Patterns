#include <unordered_map>
#include <string>

class Prototype {
public:
    virtual ~Prototype() = default;
    virtual void someOperation() = 0;
    virtual Prototype* clone() const = 0;
};

class concretePrototype1 : public Prototype {
public:
    void someOperation() override {

    }
    Prototype* clone() const override {
        return new concretePrototype1(*this);
    }
};

class concretePrototype2 : public Prototype {
public:
    void someOperation() override {

    }
    Prototype* clone() const override {
        return new concretePrototype2(*this);
    }
};

class PrototypeFactory {
public:
    PrototypeFactory() {
        prototypes["p1"] = new concretePrototype1;
        prototypes["p2"] = new concretePrototype2;
    }
    ~PrototypeFactory() {
        delete prototypes["p1"];
        delete prototypes["p2"];
    }
public:
    Prototype* createPrototype(const std::string& key) {
        return prototypes[key]->clone();
    }
private:
    std::unordered_map<std::string, Prototype*> prototypes;
};
