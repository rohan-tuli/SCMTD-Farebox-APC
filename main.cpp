#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april16.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april16_gfi.csv", testMap);
	//test->generateBoardingsPerStopCSV();
	test->generateEventDistribution("2695");

	std::set<std::string> routeVariantStops;
	routeVariantStops.insert("1624");
	routeVariantStops.insert("1620");
	routeVariantStops.insert("2342");
	// = {"1624", "1620", "2342"};
	std::string routeVariantName = "18-00-1-UCSC via Mission";

	test->generateStopUsageTable(routeVariantStops, routeVariantName);

}