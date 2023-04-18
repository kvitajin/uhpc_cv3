#include "app.h"

inline std::string getEnvVar(const std::string &param, const std::string defaultValue)
{
	int i = 100;
	char *var = std::getenv(param.c_str());
	if (var != NULL)
	{
        std::stringstream ss(var);
		return ss.str();
	}
	else
	{
		return defaultValue;
	}
}


int main()
{
	const timespec time = now();
	const std::string FILE = "/tmp/.timer-" + getEnvVar("HOSTNAME", "login") + getEnvVar("LOGNAME", "") + ".time";
	
	#if defined START
		std::ofstream ss(FILE);
		ss << time << std::endl;
		ss.close();
	#elif defined STOP
		std::ifstream ss(FILE);
		std::string startTime;
		ss >> startTime;
		ss.close();
		std::remove(FILE.c_str());
		
		if (const auto duration = timespec2double(time - string2time(startTime)); duration > 0.5)
			std::cout << duration << std::endl;
		else
			std::cerr << "Very short run - " << duration << std::endl;
	#endif
	
	return 0;
}
