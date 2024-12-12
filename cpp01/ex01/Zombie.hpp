#include <iostream>
#include <string>

class Zombie {
	public:
		void	announce( void );
		void	set_name( std::string name );
		~Zombie( void );
	private:
		std::string _name;
};

Zombie *zombieHorde( int N, std::string name );
