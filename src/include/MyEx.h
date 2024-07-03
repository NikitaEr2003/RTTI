#ifndef MYEX_H
#define MYEX_H
#include <stdexcept>
class MyEx : public std::domain_error
{

private:

	const char* message;

public:

    explicit MyEx( const char* msg);

	const char* what() const noexcept override;

};
#endif