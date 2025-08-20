#include "Utils.h"

#include <iostream>

namespace Utils
{
	void DecimalToHexadecimal(unsigned short const number, std::string& addTo)
	{
		for (int i = 0; i < 4; i++)
		{
			unsigned short tempNumber = number;
			tempNumber <<= 4 * i;
			tempNumber >>= 4 * 3;
			char charact = static_cast<char>(tempNumber);
			if (charact < 10) charact += '0';
			else charact += 'A' - 10;
			addTo += charact;
		}
	}
}
