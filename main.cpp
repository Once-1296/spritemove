#include"sprite.h"
using namespace std;
int main()
{
	sprite sp;
	while (sp.running())
	{
		sp.update();
		sp.render();
	}
	return 0;
}