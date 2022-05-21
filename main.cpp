#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("march29.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("march29_gfi.csv", testMap);
	test->generateBoardingsPerStopCSV();
	test->generateEventDistribution("1907");

}