#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april3.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april3_gfi.csv", testMap);
	//test->generateBoardingsPerStopCSV();
	//test->generateEventDistribution("1517");

	std::set<std::string> routeVariantStops;
	//18 variant stops

	
	std::string routeVariantName = "69W-00-5-Capitola Rd/Wats OB";

	routeVariantStops.insert("2704");
	routeVariantStops.insert("2666");
	routeVariantStops.insert("1781");	
	routeVariantStops.insert("1783");
	routeVariantStops.insert("2668");
	routeVariantStops.insert("1791");
	routeVariantStops.insert("1793");
	routeVariantStops.insert("2186");
	routeVariantStops.insert("1795");
	routeVariantStops.insert("1797");
	routeVariantStops.insert("1800");
	routeVariantStops.insert("1289");
	routeVariantStops.insert("1290");
	routeVariantStops.insert("2642");
	routeVariantStops.insert("1293");
	routeVariantStops.insert("1297");
	routeVariantStops.insert("1299");
	routeVariantStops.insert("1301");
	routeVariantStops.insert("1302");
	routeVariantStops.insert("2802");
	routeVariantStops.insert("2148");
	routeVariantStops.insert("2149");
	routeVariantStops.insert("1818");
	routeVariantStops.insert("1820");
	routeVariantStops.insert("1823");
	routeVariantStops.insert("1824");
	routeVariantStops.insert("1825");
	routeVariantStops.insert("1830");
	routeVariantStops.insert("1832");
	routeVariantStops.insert("1835");
	routeVariantStops.insert("1836");
	routeVariantStops.insert("2722");
	routeVariantStops.insert("1840");
	routeVariantStops.insert("1848");
	routeVariantStops.insert("1144");
	routeVariantStops.insert("1142");
	routeVariantStops.insert("1139");
	routeVariantStops.insert("2204");
	

	/*
	std::string routeVariantName = "18-00-1-UCSC via Mission";
	routeVariantStops.insert("1591");
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
	routeVariantStops.insert("2572");
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

	/*
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
	*/

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