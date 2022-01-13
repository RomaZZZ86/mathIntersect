
#include <fstream>
#include <iostream>
#include"classes/include/Units.h"

#define WINDOWWIDTH 600
#define WINDOWHEIGHT 600

#define LIMITUNIT 100
#define SECTOR 50
#define DISTANCE 52

int main()
{
	
	RenderWindow window(VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Units intersects");
	smArray<Unit> uintArray;
	setlocale(LC_ALL, "rus");
	std::ofstream fout("information.txt", std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) // если файл небыл открыт
	{
		std::cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		return 1; // выполнить выход из программы
	}
	
	std::string text = format("Sector at %d degrees, distance %d units", SECTOR, DISTANCE);
	std::cout << text << "\n";
	std::cout  << "\n";

	fout << text << "\n" << std::endl;
	fout <<  "\n" << std::endl;

	for (int i = 0; i < LIMITUNIT; i++) {
		int x = random(-300, 300);
		int y = random(-300, 300);

		int dirx = random(100, -100);
		int diry = random(-100, 100);
		
		uintArray.add(new Unit(axisVector(WINDOWWIDTH, WINDOWHEIGHT), axisVector(x, y), axisVector(dirx, diry), SECTOR, DISTANCE));
		std::string str = format("Unit %d,Position(%d, %d), direction(%d, %d) ", i, (int)x, (int)y, (int)dirx, (int)diry);
		std::cout << str << "\n";
		fout << str << "\n" << std::endl;
		//Юнит1, позиция(1, 1), направление(0, 1)
		
	}
	std::cout <<  "\n";
	fout <<  "\n" << std::endl;
	std::cout << "unitsresult:" << "\n";
	fout << "unitsresult:" << "\n" << std::endl;

	bool stateF = 1;


	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close(); 
		}
		
		window.clear(Color(0, 0, 0, 200));

		
		
		for (int i = 0; i < LIMITUNIT; i++) {
			
				for (int n = 0; n < LIMITUNIT; n++) {
					if (n != i) {
						bool g = uintArray[i]->patrol_of_area(window, uintArray[n]->getposition());
						if (g) {

							std::string str = format("Unit%d: sees %d", i, n);
							std::cout << str << "\n";
							if(stateF)fout << str << "\n" << std::endl;
						}
						
					}
				}
				uintArray[i]->update(window);

				
			
			
		}

		window.display();
		stateF = 0;
		fout.close();
	}

	return 0;
}





