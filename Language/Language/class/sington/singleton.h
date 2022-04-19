#pragma once
template<typename T>
class singleton
{
public:
	static T& getInstance();
private:
	singleton();
	singleton(const T& rhs);
};

template<typename T>
inline T& singleton<T>::getInstance()
{
	static T instance;
	return instance;
}
