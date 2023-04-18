#include "timelibrary.h"

timespec now()
{
	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);	
	return time;
}

double timespec2double (timespec time)
{
	return time.tv_sec + time.tv_nsec/1e9;
}

timespec string2time(const std::string &data)
{
	timespec time;
	int sec, nsec;
	sscanf( data.c_str(), "%d.%d", &sec, &nsec );
	time.tv_sec = sec;
	time.tv_nsec = nsec;
	return time;
}

/*
timespec duration(const timespec &a, const timespec &b)
{
	auto sub = [](auto x, auto y) { return y - x; };
	
	return sub(a, b);
}
*/
/*
template <class T>
constexpr double duration(T a, T b)
{
	if constexpr (std::is_floating_point<T>)
		return b - a;
	else
		return timespec2double(b - a);

}
*/



//template compareTime <timespec>;
//template compareTime <timespec>;

/*
bool cmp (timespec a, timespec b)
{
	return compareTime<timespec>(a, b);
}
*/












