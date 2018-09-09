#include <cstdio>
#include <exception>

struct NotImplementedError: public std::exception
{
};

int main(int argc, char const *argv[])
{
	throw NotImplementedError();
	return 0;
}