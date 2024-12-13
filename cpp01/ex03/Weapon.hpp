#pragma once
#include <string>
#include <iostream>

class Weapon {
	public:
		Weapon( std::string type );
		Weapon();
		const std::string &getType( void ) const;
		void	setType( std::string type );
	private:
		std::string _type;
};
