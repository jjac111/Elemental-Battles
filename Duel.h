#include <string>
#include <iostream>


class Weapon
{
	friend std::ostream &operator<<(std::ostream& , Weapon&);	//prototipo del operador <<
	public:
		Weapon(std::string tipo , std::string elemento);		//prototipo del constructor con argumentos
		Weapon();												//prototipo del constructor por default
		Weapon operator+(Weapon&);								//prototipo del operador + entre dos objetos Weapon
		Weapon operator=(Weapon&);								//prototipo del operador = entre dos objetos Weapon
		std::string getType();									//prototipo de funciones get y set para cada dato miembro
		std::string getElement();
		void setType(std::string);
		void setElement(std::string);
		std::string fight(Weapon& enemy);						//prototipo de la funcion que determina el ganador en un duelo

	private:
		std::string type;										//tipo de arma
		std::string element;									//elemento infusionado en el arma
};
