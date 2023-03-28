#include <string>

class SharedResurse {
public:
    SharedResurse(int field1, const std::string& field2) : field1(field1), field2(field2) {}
public:
    std::string someOperation() const {
        return "some info";
    }
private:
    int field1;
    std::string field2;
};

class UniqueResurse {
public:
    UniqueResurse(double field1, const std::string& field2) : field1(field1), field2(field2) {}
public:
    std::string someOperation() const {
        return "other info";
    }
private:
    double field1;
    std::string field2;
};

class Flyweight {
public:
    Flyweight(SharedResurse* resurse) : shared(resurse) {}  
public:
    std::string someOperation(const UniqueResurse& unique) const {
        return shared->someOperation() + " + " + unique.someOperation();
    }
private:
    SharedResurse* shared;
};
