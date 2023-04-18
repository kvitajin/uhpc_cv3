#include <fstream>
#include <iomanip>

//#include <time.h>
#include <type_traits>
#include <math.h>

template<typename T>
constexpr T pi = T(3.14159265358979323846);

timespec now();
double timespec2double (timespec time);
timespec string2time(const std::string &data);

inline timespec operator-(const timespec &a, const timespec &b)
{
	timespec diff;
	diff.tv_sec = a.tv_sec - b.tv_sec;
	diff.tv_nsec = a.tv_nsec - b.tv_nsec;
	if (diff.tv_nsec < 0)
	{
		diff.tv_nsec += 1e9;
		diff.tv_sec--;
	}
	return diff;
}

inline bool operator==(const timespec &a, const timespec &b)
{
	timespec diff;
	diff.tv_sec = a.tv_sec - b.tv_sec;
	diff.tv_nsec = a.tv_nsec - b.tv_nsec;
	if (diff.tv_nsec == 0 && diff.tv_sec == 0)
		return true;
	else
		return false;
}


inline std::ostream& operator<<(std::ostream& os, const timespec &time)
{
	os << time.tv_sec << "." << std::setfill('0') << std::setw(9) << time.tv_nsec;
	return os;
}



