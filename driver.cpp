#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <ctime>
#include "Duel.h"
using namespace std;

int main()
{
	srand(time(0));
	string types[] = {"dagger" , "sword" , "hammer"};
	string elements[] = {"water" , "wind" , "earth" , "fire" , "nature" , "arcane" , "electricity" , "light" , "plague" , "shadow" , "ice"};	//arreglos con elementos y tipos de armas disponibles
		
	Weapon you;		//se crea el arma del usuario
	string youType;
	string youElement;
	int elementalStones = 3;	//se crean los "rerolls" disponibles
	string yesno;
	string option;
	string *yesnoPtr = &yesno;	//se crean punteros a las variables yesno y option
	string *optionPtr = &option;
	
	
	cout<<"Welcome to your trial. You will be tested on your elemental knowledge with 10 battles."<<endl;	//introduccion
	cout<<"\nDo you wish to know the rules?"<<endl;
	
	while(true)
	{
		cin>>*yesnoPtr;
		if(*yesnoPtr != "yes" && *yesnoPtr != "no")
			{
				cout<<"Just answer yes or no..."<<endl;	//solo se aceptan respuestas yes o no
			}
		else
		break;
	}
	if(*yesnoPtr == "yes")	//se imprimen las reglas
	{
		cout<<"\n\nYou are allowed to pick a weapon among three: a dagger, a sword, or a hammer."<<endl;
		cout<<"A dagger is swift enough to counter a bulky hammer, while a sword reaches longer than the dagger. However, a hammer can easily destroy a sword. Keep this in mind."<<endl;
		cout<<"\nThereafter, you may infuse your weapon with one of eleven elements:"<<endl;
		cout<<"\nwater\twind\tearth\t\tfire\nnature\tarcane\telectricity\tlight\nplague\tshadow\tice"<<endl;
		cout<<"\nAn elemental power overrides the type of weapon it is in during battle. But if your weapon's and enemy weapon's elemental infusions dont interact, your types of weapon determine the outcome of the battle."<<endl;
		cout<<"Some elemental interactions may be trivial, but some are up to you to discover."<<endl;
		cout<<"\nWhenever you win a fight, you can proceed to the next one. If you lose, you die. However, if there is a tie, you may try the battle again."<<endl;
		cout<<"Before every battle, you may infuse your current weapon with your previous adversary's element, or switch your current weapon with it."<<endl;
		cout<<"Then, you may consume an Elemental Stone to reinfuse your current weapon with a random element. You start with only 3 Elemental stones."<<endl;
		cout<<"\n\nNow"<<endl;
		
	}
	
	
	
	cout<<"Choose your weapon type: dagger, sword, hammer."<<endl;
	cin>>youType;															//se ingresa el tipo y luego el elemento del arma
	you.setType(youType);
	cout<<"Choose an elemental infusion for your weapon."<<endl;
	cin>>youElement;
	you.setElement(youElement);
	
	cout<<"\nYour starting weapon has the following traits:"<<endl<<you<<endl;
	
	int randType = rand() % 3;
	int randElement = rand() % 11;
	
	
	Weapon enemy(types[randType] , elements[randElement]);
	Weapon prevEnemy	;
	
	for(int i = 0 ; i < 10 ; i++)		//se inician los 10 duelos
	{
		randType = rand() % 3;
		randElement = rand() % 11;
		Weapon enemy(types[randType] , elements[randElement]);		//el arma del enemigo siempre se genera al azar
		
		cout<<"\nThe ";
		switch(i)
		{
			case 0: cout<<"First";
			break;
			case 1: cout<<"Second";
			break;
			case 2: cout<<"Third";
			break;
			case 3: cout<<"Fourth";
			break;
			case 4: cout<<"Fifth";
			break;
			case 5: cout<<"Sixth";
			break;
			case 6: cout<<"Seventh";
			break;
			case 7: cout<<"Eighth";
			break;
			case 8: cout<<"Ninth";
			break;
			case 9: cout<<"Tenth and FINAL";
			break;
		}
		cout<<" enemy holds a weapon with the following traits:"<<endl<<enemy<<endl;
			
		if(i > 0)
		{
			cout<<"You can infuse your weapon with your previous adversary's weapon element, or switch your weapon with it."<<endl;
			cout<<"Will you infuse, switch, or do nothing?"<<endl;		//se da la opcion de infusionar el arma actual, intercambiar, o hacer nada con el arma del adversario anterior 
			cin>>*optionPtr;
			if(*optionPtr == "infuse")
			{
				you+prevEnemy;
				cout<<"\nYour weapon traits now are:"<<endl<<you<<endl;
			}
			if(*optionPtr == "switch")
			{
				you=prevEnemy;
				cout<<"\nYour weapon traits now are:"<<endl<<you<<endl;
			}
		}
		
		if(elementalStones > 0)
		{
			cout<<"Do you wish to reroll your element? (cost: 1 elemental stone):"<<endl;		//si hay Elemental Stones, se puede cambiar la infusion del arma actual con otra al azar
			{	while(true)
				{
					cin>>*yesnoPtr;
					if(*yesnoPtr != "yes" && *yesnoPtr != "no")
					{
						cout<<"Just answer yes or no..."<<endl;
					}
					else
					break;
				}
			}
		}
		else
		cout<<"\nNo elemental stones left."<<endl;
		
		if(*yesnoPtr == "yes")
		{
			elementalStones -= 1;
			int randElement = rand() % 11;
			you.setElement(elements[randElement]);
			cout<<"\nYour weapon traits now are:"<<endl<<you<<endl;
		}
		
				
		cout<<"\nDUEL BEGINS..."<<endl;
		cout<<you.fight(enemy)<<endl;
		if(you.fight(enemy) == "Defeat")
		{
			cout<<"Way to go, loser...";				//En caso de derrota, el programa termina
			exit(0);
		}
		if(you.fight(enemy) == "Tie")
		{
			cout<<"You may try again..."<<endl;			//En caso de victoria se pasa a la siguiente ronda
			i -= 1;
		}
		if(you.fight(enemy) == "Victory" && i == 9)
		{
			cout<<"\n\n\nV  I  C  T  O  R  Y"<<endl;
			cout<<"\nNow go do something productive.";	//En caso de victoria en la ronda final, el programa termina
			exit(0);
		}
			prevEnemy = enemy;	//se asigna el arma del enemigo de esta ronda como el arma del enemigo de la ronda anterior

	}


	
	
	

	
	
	
}
