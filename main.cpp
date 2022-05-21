#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april3.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april3_gfi.csv", testMap);
	test->generateBoardingsPerStopCSV();
	//test->generateEventDistribution("1620");

}