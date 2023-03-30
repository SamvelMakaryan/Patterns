#include <iostream>
#include <string>
#include <vector>

class Memento {
public:
    virtual ~Memento() = default;
public:
    virtual std::string getState() const = 0; 
    virtual std::string getName() const = 0; 
};

class concreteMemento : public Memento {
public:
    concreteMemento(std::string state, std::string name) : state(state), name(name) {} 
public:
    std::string getState() const {
        return state;
    }
    std::string getName() const {
        return name;
    }
private:
    std::string state;
    std::string name;
};

class Creator {
public:
    Creator(std::string state, std::string name) : state(state), name(name) {}
public: 
    void changeState() {
        
    }
    Memento* save() {
        return new concreteMemento(this->state, this->name);
    }
    void Restore(Memento* memento) {
        this->state = memento->getState();
        this->name = memento->getName();
    }
private:
    std::string state;    
    std::string name;    
};

class Caretaker {
public:
    Caretaker(Creator* creator) : creator(creator) {}
    ~Caretaker() {
        for (auto& i : mementos) {
            delete i;
        }
    } 
public:
    void backup() {
        mementos.push_back(creator->save());
    }
    void undo() {
        if (!mementos.size()) {
            return;
        }
        Memento* memento = mementos.back();
        mementos.pop_back();
        if (!memento) {
            undo();
        }
        creator->Restore(memento);
    }
private:
    std::vector<Memento*> mementos;
    Creator* creator;
};
