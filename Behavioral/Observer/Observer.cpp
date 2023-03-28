#include <string>
#include <list>

class IObserver {
public:
    virtual ~IObserver() = default;
public:
    virtual void update() = 0;
};

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void sub(IObserver*) = 0;
    virtual void remove(IObserver*) = 0;
    virtual void notify() = 0;
};

class ConcreteSubject : public ISubject {
public: 
    ConcreteSubject(const std::string& message) : message(message) {}
public:
    void createMessage(const std::string& message) {
        this->message = message;
    }
    void sub(IObserver* observer) override {
        observers.push_back(observer);
    }
    void remove(IObserver* observer) override {
        observers.remove(observer);
    }
    void notify() override {
        for (auto& i : observers) {
            i->update();
        }
    }
private:
    std::list<IObserver*> observers;
    std::string message;
};

class Observer : public IObserver {
public:
    Observer(ConcreteSubject& subject, const std::string& message) : subject(subject), message(message) {}
public:
    void update() override {
        subject.createMessage(message);
        subject.notify();
    }
    void removeThis() {
        subject.remove(this);
    }
private:
    ConcreteSubject& subject;
    std::string message;
};
