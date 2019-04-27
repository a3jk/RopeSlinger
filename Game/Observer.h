#pragma once
#include <functional>

template <typename T>
class Observer
{
public:
	Observer();
	~Observer();
	std::function<void()> function;
private:
};

template<typename T>
Observer<T>::Observer()
{
}

template<typename T>
Observer<T>::~Observer()
{
}
