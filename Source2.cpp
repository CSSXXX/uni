#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>


int main()
{
	long int n{}; // l. odd w firmie

	//long int m{}; // zrobiona suma podwyzek 2 wydzialów
	long int lprac{}; // l. pracowników w danym oddziale
	std::vector<long int> lplac1; // dynamicznie alokowana tablica p³ac ka¿dego pracownika
	std::vector<long int> lplac2;
	long int kwota{0}; // kwota do której bêd¹ dodawane podwyzki

	// P£ACA NIE MOZE BYC ROWNA 0

	
	std::cin >> n;

	// pierwszy oddzial
	std::cin >> lprac; 
	lplac1.resize(lprac);
	for (int i = 0; i < lprac; i++)
		std::cin >> lplac1[i];
	//


	for (int i = 1; i < n; i++)
	{
		
		// zapisujesz liczbe plac dla tablicy nr2 lprac razy
		std::cin >> lprac;
		lplac2.resize(lprac);
		for (int i = 0; i < lprac; i++)
		std::cin >> lplac2[i];
		//


		//znajdujesz najwieksza place w tablicy nr1
		long int max1{};
		max1 = lplac1[0];
		for (int i = 1; i < lplac1.size(); i++)
			max1 = std::max(max1, lplac1[i]);
		//

		//znajdujesz najwieksza place w tablicy nr2
		long int max2{};
		max2 = lplac2[0];
		for (int i = 1; i < lplac2.size(); i++)
			max2 = std::max(max2, lplac2[i]);
		//


		//sprawdzasz 3 warunki porownujace place
		if (max1 > max2)
		{
			long int difference = max1 - max2;
			long int i{ 0 };
			long int tempLplac1Size = lplac1.size();
			lplac1.resize(lplac1.size() + lplac2.size());
			for (; i < lplac2.size(); i++)
			{
				lplac2[i] += difference;
				lplac1[tempLplac1Size + i] = lplac2[i];
			}

			kwota += i * difference;


		}

		if (max1 == max2)
		{
			long int tempLplac1Size = lplac1.size();
			lplac1.resize(lplac1.size() + lplac2.size());
			for (long int i = 0; i < lplac2.size(); i++)
			{
				lplac1[tempLplac1Size + i] = lplac2[i];
			}
			kwota += 0;

		}

		if (max1 < max2)
		{
			long int difference = max2 - max1;
			long int i{ 0 };
			long int tempLplac1Size = lplac1.size();
			lplac1.resize(lplac1.size() + lplac2.size());
			for (; i < tempLplac1Size; i++)
			{
				lplac1[i] += difference;
				//lplac1[tempLplac1Size + i] = lplac2[i];
			}
			for (int i = 0; i < lplac1.size() - tempLplac1Size; i++)
			lplac1[tempLplac1Size + i] = lplac2[i];

			kwota += i * difference;
		}

		//w warunkach przepisujesz place, dodajesz nowe place do tablicy nr 1 i zapisujesz gdzies dodana
		// ilosc podwyzki




	}


	std::cout << "kwota: " << kwota;

}