#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april16.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april16_gfi.csv", testMap);
	//test->generateBoardingsPerStopCSV();
	test->generateEventDistribution("2695");

}