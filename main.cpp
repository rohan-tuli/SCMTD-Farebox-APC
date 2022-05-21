#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("all.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("gfi.csv", testMap);

}