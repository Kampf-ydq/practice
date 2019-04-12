#include"stackOperate.h"
#include<string>

using namespace std;

int main()
{
	stackOperate stackObj;

	//×ªÎªºó×º
	stackObj.postfix();

	stackObj.calculate();

	return 0;
}