#include <iostream>
#include <string>
#include "Duel.h"
using namespace std;

Weapon::Weapon(string tipo , string elemento)	//implementacion del constructor con argumentos
:type(tipo) , element(elemento)
{
	
}

Weapon::Weapon()								//implementacion del constructor por default
:type("") , element("")
{
	
}

string Weapon::getType()						//implementacion de funciones get y set de cada dato miembro
{
	return type;
}

string Weapon::getElement()
{
	return element;
}

void Weapon::setType(string tipo)
{
	if(tipo == "dagger" || tipo == "sword" || tipo == "hammer")	
	type = tipo;
	
	else
	{
		cout << "No such weapon available. You are now barehanded." << endl;	//en caso de recibir un tipo de arma no valido, se asigna niguna
		type = "barehanded";
	}
}

void Weapon::setElement(string elemento)
{
	if(elemento == "water" || elemento == "wind" || elemento == "earth" || elemento == "fire" || elemento == "nature" || elemento == "arcane" || elemento == "electricity" || elemento == "light" || elemento == "plague" || elemento == "shadow" || elemento == "ice")
	element = elemento;
	
	else
	{
	cout << "No such element available. Your weapon is now uninfused." << endl;	//en caso de recibir un tipo de elemento no valido, se asigna niguno
	element = "uninfused";
	}
}

Weapon Weapon::operator+(Weapon& defeatedWeapon)		//implementacion del operador +, que significa infusion
{
	element = defeatedWeapon.element;
	
	return *this;
}

Weapon Weapon::operator=(Weapon& defeatedWeapon)		//implementacion del operador =, que significa intercambio
{
	element = defeatedWeapon.element;
	type = defeatedWeapon.type;
	
	return *this;
}

string Weapon::fight(Weapon& enemy)						//implementacion de la funcion fight, que determina las interacciones de elemenos y armas y devuelve Victory, Defeat, o Tie
{
	if(element == "water" && enemy.element == "wind" || element == "wind" && enemy.element == "earth" || element == "earth" && enemy.element == "fire" || element == "fire" && enemy.element == "nature" || element == "nature" && enemy.element == "arcane" || element == "arcane" && enemy.element == "electricity" || element == "electricity" && enemy.element == "light" || element == "light" && enemy.element == "plague" || element == "plague" && enemy.element == "shadow" || element == "shadow" && enemy.element == "ice" || element == "ice" && enemy.element == "water" || element == "water" && enemy.element == "earth" || element == "water" && enemy.element == "fire" || element == "wind" && enemy.element == "arcane" || element == "wind" && enemy.element == "lightning" || element == "earth" && enemy.element == "arcane" || element == "earth" && enemy.element == "electricity" || element == "fire" && enemy.element == "ice" || element == "fire" && enemy.element == "plague" || element == "nature" && enemy.element == "earth" || element == "nature" && enemy.element == "light" || element == "arcane" && enemy.element == "light" || element == "arcane" && enemy.element == "shadow" || element == "electricity" && enemy.element == "ice" || element == "electricity" && enemy.element == "water" || element == "light" && enemy.element == "shadow" || element == "light" && enemy.element == "wind" || element == "plague" && enemy.element == "nature" || element == "plague" && enemy.element == "water" || element == "shadow" && enemy.element == "fire" || element == "shadow" && enemy.element == "wind" || element == "ice" && enemy.element == "plague" || element == "ice" && enemy.element == "nature")
	return "Victory";
	
	else
	{
		if(enemy.element == "water" && element == "wind" || enemy.element == "wind" && element == "earth" || enemy.element == "earth" && element == "fire" || enemy.element == "fire" && element == "nature" || enemy.element == "nature" && element == "arcane" || enemy.element == "arcane" && element == "electricity" || enemy.element == "electricity" && element == "light" || enemy.element == "light" && element == "plague" || enemy.element == "plague" && element == "shadow" || enemy.element == "shadow" && element == "ice" || enemy.element == "ice" && element == "water" || enemy.element == "water" && element == "earth" || enemy.element == "water" && element == "fire" || enemy.element == "wind" && element == "arcane" || enemy.element == "wind" && element == "lightning" || enemy.element == "earth" && element == "arcane" || enemy.element == "earth" && element == "electricity" || enemy.element == "fire" && element == "ice" || enemy.element == "fire" && element == "plague" || enemy.element == "nature" && element == "earth" || enemy.element == "nature" && element == "light" || enemy.element == "arcane" && element == "light" || enemy.element == "arcane" && element == "shadow" || enemy.element == "electricity" && element == "ice" || enemy.element == "electricity" && element == "water" || enemy.element == "light" && element == "shadow" || enemy.element == "light" && element == "wind" || enemy.element == "plague" && element == "nature" || enemy.element == "plague" && element == "water" || enemy.element == "shadow" && element == "fire" || enemy.element == "shadow" && element == "wind" || enemy.element == "ice" && element == "plague" || enemy.element == "ice" && element == "nature")
		return "Defeat";
	
		else
		{
			if(type == "dagger" && enemy.type == "hammer" || type == "sword" && enemy.type == "dagger" || type == "hammer" && enemy.type == "sword")
			return "Victory";
		
			else
			{
				if(enemy.type == "dagger" && type == "hammer" || enemy.type == "sword" && type == "dagger" || enemy.type == "hammer" && type == "sword" || enemy.type == type && element == "uninfused" || type == "barehanded")
				return "Defeat";
			
				else
				{
					return "Tie";
				}
			}
		}
	}
	
	
	
}

ostream& operator<<(ostream &out , Weapon &arma)		//implementacion del operador <<
{
	out << "Weapon type: " << arma.getType() << endl;
	out << "Elemental infusion: " << arma.getElement() << endl;
   
   	return out;
}



