// basics/max5.hpp
#include <string>

template <typename T>
inline T const& max (T const& a, T const& b)
{
	return a < b ? b : a;
}

template <typename T>
inline T max2 (T a, T b)
{
	return a < b ? b : a;
}