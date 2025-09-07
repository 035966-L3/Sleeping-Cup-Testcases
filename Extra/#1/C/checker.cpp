#include "testlib.h"
using namespace std;
int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);
	string pans = ouf.readString();
	string jans = ans.readString();
	if (pans == jans) quitp(1.0, "The answer is correct.");
	if (pans == "RrikcHfqcuUcp") quitp(0.2, "The answer is wrong: found = RrikcHfqcuUcp nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn \n\n\n\n\n\n\n\n\n\n\n\n\nexpected = gnihsiW siht noititepmoc a htooms nur.");
	quitp(0, "The answer is wrong.");
	return 0;
}
