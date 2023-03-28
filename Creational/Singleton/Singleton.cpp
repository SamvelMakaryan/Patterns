class Singleton {
public:
    ~Singleton() {
        ob = nullptr;
    }
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&) = delete;
public:
    static Singleton* constructor() {
        if (ob == nullptr) {
            ob = new Singleton;
        }
        return ob;
    }
private:
    Singleton() = default;
private:
    static inline Singleton* ob = nullptr;
};
