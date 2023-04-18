
#include <iostream>
#include <ctime>


int main()
{
	const size_t n = 2048;

	double a [n*n];
	double b [n*n];
	double c [n*n];
	
	//init a and b
	std::srand(std::time(nullptr));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			a[i*n+j] = 1.0 / (std::rand() % 1000);
			a[i*n+j] = 1 + 1.0 / (std::rand() % 1000);
		}
	}

	//multiply
#if defined V1
	std::cout << "VERSION 1\n";
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			c[i+n*j] = .0;
			for(int k = 0; k < n; k++) {
				c[i+n*j] += a[i+n*k] * b[k+n*j];
			}
		}
	}
#elif defined V2
	std::cout << "VERSION 2\n";
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			c[i*n+j] = .0;
			for(int k = 0; k < n; k++) {
				c[i*n+j] += a[i*n+k] * b[k*n+j];
			}
		}
	}
#else
	std::cout << "NO multiplication done\n";
#endif

	return 0;
}
