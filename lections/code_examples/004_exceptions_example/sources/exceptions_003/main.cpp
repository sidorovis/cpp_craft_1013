#include <string>
#include <iostream>
#include <exception>

class my_exception : public std::exception
{
public:
	virtual const char * what() const
	{
		return "my_exception";
	}
	const std::string hello() const
	{
		return "hello exception!";
	}
};

int main()
{
	try
	{
		throw my_exception();
	}
	catch( const my_exception& e )
	{
		std::cout << e.hello() << std::endl;
	}
	catch( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
}

