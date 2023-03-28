#include <string>

class Subsystem1 {
public:
    std::string operation1() const {
        return "Sub1::operation_1 ";
    }
    std::string operation2() const {
        return "Sub1::operation_2 ";
    }
};

class Subsystem2 {
public:
    std::string operation1() const {
        return "Sub2::operation_1 ";
    }
    std::string operation2() const {
        return "Sub2::operation_2 ";
    }
};

class Facade {
public:
    Facade(Subsystem1* sub1, Subsystem2* sub2) : sub1(sub1), sub2(sub2) {}
public:
    std::string someOpreations() {
        std::string result;
        result += sub1->operation1();
        result += sub1->operation2();
        result += sub2->operation1();
        result += sub2->operation2();
        return result;
    }
protected:
    Subsystem1* sub1;
    Subsystem2* sub2;
};

