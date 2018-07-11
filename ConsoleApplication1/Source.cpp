#include <time.h>
#include <cstdlib>
#include "Swiat.h"
int main()
{
	srand(time(0));
	Swiat swiat(20, 20);
	swiat.menuStart();
	
	return 0;
}