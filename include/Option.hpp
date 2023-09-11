#ifndef OPTION_HPP
#define OPTION_HPP

class BaseOption {
	public: 
		virtual void print() = 0;
}

template <typename T> class Option : BaseOption {
public:
    Option(const char** name, T& value) : name(name), data(value) {}
	void print() override;
private:
    const char** name;
    T value;
    int (*validate)(int next_) = nullptr;
    int (*convert)() = nullptr;
};

#endif
