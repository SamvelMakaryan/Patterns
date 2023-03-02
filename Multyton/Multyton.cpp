class Multyton {
public:
    ~Multyton() {
        ob1 = nullptr;
        ob2 = nullptr;
        ob3 = nullptr;
    }
public:
    static Multyton* constructor() {
        if (currentCount == count) {
            currentCount = 0;
        }
        switch (currentCount % count) {
            case 0 :
                ++currentCount;
                if (ob1 == nullptr) {
                    ob1 = new Multyton;
                }
                return ob1;
            case 1 :
                ++currentCount;
                if (ob2 == nullptr) {
                    ob2 = new Multyton;
                }
                return ob2;
            case 2 :
                ++currentCount;
                if (ob3 == nullptr) {
                    ob3 = new Multyton;
                }
                return ob3;
            default:
                return nullptr;
        }
    }
private:
    Multyton() = default;
private:
    static inline Multyton* ob1 = nullptr;
    static inline Multyton* ob2 = nullptr;
    static inline Multyton* ob3 = nullptr;
    static inline int currentCount = 0;
    static const int count = 3;
};
