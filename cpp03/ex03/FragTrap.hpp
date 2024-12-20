#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap(  );
		FragTrap( const FragTrap &other );
		FragTrap &operator=( const FragTrap &other );
		~FragTrap(  );
		FragTrap( const std::string name );
		void highFivesGuys( void );
};
