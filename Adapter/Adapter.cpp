#include <string>
#include <algorithm>

class ProductA {
public:
    ProductA() = default;
    ProductA(const std::string& s) {
        reverseString = s;
    }
    virtual ~ProductA() = default;
public:
    virtual std::string getReverseString() const {
        return reverseString;
    } 
private:
    std::string reverseString;
};

class ProductB {
public:
    ProductB() = default;
    ProductB(const std::string& s) {
        string = s;
    }
    virtual ~ProductB() = default;
public:
    virtual std::string getString() const {
        return string;
    }
private:
    std::string string;
};

class A_to_B_Adapter : public ProductA, public ProductB {
public:
    A_to_B_Adapter(const std::string& s) : ProductA(s) {}
public:
    std::string getString() const override {
        std::string tmp = getReverseString();
        std::reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};
