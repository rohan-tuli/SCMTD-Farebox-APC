#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april24.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april24_gfi.csv", testMap);
	//test->generateBoardingsPerStopCSV();
	//test->generateEventDistribution("1517");

	std::set<std::string> routeVariantStops;
	//18 variant stops
	/*
	std::string routeVariantName = "18-00-1-UCSC via Mission";
	routeVariantStops.insert("2731");
	routeVariantStops.insert("1630");
	routeVariantStops.insert("1624");
	routeVariantStops.insert("1620");
	routeVariantStops.insert("2342");
	routeVariantStops.insert("2344");
	routeVariantStops.insert("1907");
	routeVariantStops.insert("2393");
	routeVariantStops.insert("1909");
	routeVariantStops.insert("1910");
	routeVariantStops.insert("2659");
	routeVariantStops.insert("2660");
	routeVariantStops.insert("2661");
	routeVariantStops.insert("2662");
	routeVariantStops.insert("2663");
	routeVariantStops.insert("2619");
	routeVariantStops.insert("1619");
	routeVariantStops.insert("1623");
	routeVariantStops.insert("1625");
	routeVariantStops.insert("1629");
	routeVariantStops.insert("1590");
	*/

	/*
	std::string routeVariantName = "10-00-11-UCSC via High";
	routeVariantStops.insert("2303");
	routeVariantStops.insert("2304");
	routeVariantStops.insert("2302");
	routeVariantStops.insert("2085");
	routeVariantStops.insert("1517");
	routeVariantStops.insert("1516");
	routeVariantStops.insert("1515");
	routeVariantStops.insert("1513");
	routeVariantStops.insert("2090");
	routeVariantStops.insert("2497");
	routeVariantStops.insert("2091");
	routeVariantStops.insert("1512");
	routeVariantStops.insert("2086");
	routeVariantStops.insert("2394");
	routeVariantStops.insert("2656");
	routeVariantStops.insert("1638");
	routeVariantStops.insert("2627");
	routeVariantStops.insert("2364");
	*/

	std::string routeVariantName = "19-00-13-UCSC via Lower Bay";
	routeVariantStops.insert("2592");
	routeVariantStops.insert("2582");
	routeVariantStops.insert("2583");
	routeVariantStops.insert("2584");
	routeVariantStops.insert("1220");
	routeVariantStops.insert("2291");
	routeVariantStops.insert("1223");
	routeVariantStops.insert("1226");
	routeVariantStops.insert("1227");
	routeVariantStops.insert("1228");
	routeVariantStops.insert("1230");
	routeVariantStops.insert("1232");
	routeVariantStops.insert("2376");
	routeVariantStops.insert("1231");
	routeVariantStops.insert("2056");
	routeVariantStops.insert("1225");
	routeVariantStops.insert("1224");
	routeVariantStops.insert("1222");
	routeVariantStops.insert("1219");
	routeVariantStops.insert("2585");
	routeVariantStops.insert("2586");
	routeVariantStops.insert("2587");
	routeVariantStops.insert("2593");

	/*
	std::string routeVariantName = "20-07-26-UCSC via Westside CSC IB";
	routeVariantStops.insert("2592");
	routeVariantStops.insert("2582");
	routeVariantStops.insert("2583");
	routeVariantStops.insert("2694");
	routeVariantStops.insert("2723");
	routeVariantStops.insert("1356");
	routeVariantStops.insert("1353");
	routeVariantStops.insert("2420");
	routeVariantStops.insert("2330");
	routeVariantStops.insert("2718");
	routeVariantStops.insert("1350");
	routeVariantStops.insert("2749");
	routeVariantStops.insert("2744");
	routeVariantStops.insert("2750");
	routeVariantStops.insert("1349");
	routeVariantStops.insert("2715");
	routeVariantStops.insert("2717");
	routeVariantStops.insert("2740");
	routeVariantStops.insert("1351");
	routeVariantStops.insert("1408");
	routeVariantStops.insert("1352");
	routeVariantStops.insert("2061");
	routeVariantStops.insert("1355");
	routeVariantStops.insert("2696");
	routeVariantStops.insert("2695");
	routeVariantStops.insert("2587");
	routeVariantStops.insert("2593");
	*/

	test->generateStopUsageTable(routeVariantStops, routeVariantName);

}