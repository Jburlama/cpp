#include "../includes/whatever.hpp"

class Awesome
{
	public:
		Awesome(void) : _n(0) {}
		Awesome( int n ) : _n( n ) {}
		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	std::cout << "Test 1\n";
	std::cout << "-----------------------------------------\n";
	{
		int a = 42;
		int b = 69;
	
		swap(a, b);
	
		std::cout << "a: " << a << "\n";
		std::cout << "b: " << b << "\n";
	
		std::cout << "min: " << min(a,b) << "\n";
		std::cout << "max: " << max(a,b) << "\n";
	}
	std::cout << "\n";
	std::cout << "Test 2\n";
	std::cout << "-----------------------------------------\n";
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;


		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "\n";
	std::cout << "Test 3\n";
	std::cout << "-----------------------------------------\n";
	{
		Awesome a(2), b(4);
		swap(a, b);
		std::cout << "a:" << a << " " << "b:" << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
}
