#include "avl.h"

int main() {
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april15.csv");

	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april15_gfi.csv", testMap);
	test->generateBoardingsPerStopCSV();
	//test->generateEventDistribution("2302");


	std::set<std::string> route35CCIBStops;
	std::string route35CCIB= "35-09-86-CClub via Glen Arbor IB SV Drive";

	route35CCIBStops.insert("1247");
	route35CCIBStops.insert("1246");
	route35CCIBStops.insert("1244");
	route35CCIBStops.insert("1242");
	route35CCIBStops.insert("1238");
	route35CCIBStops.insert("1561");
	route35CCIBStops.insert("2124");
	route35CCIBStops.insert("1558");
	route35CCIBStops.insert("1556");
	route35CCIBStops.insert("1554");
	route35CCIBStops.insert("1552");
	route35CCIBStops.insert("1550");
	route35CCIBStops.insert("1548");
	route35CCIBStops.insert("2128");
	route35CCIBStops.insert("1543");
	route35CCIBStops.insert("1474");
	route35CCIBStops.insert("2294");
	route35CCIBStops.insert("1466");
	route35CCIBStops.insert("1465");
	route35CCIBStops.insert("1471");
	route35CCIBStops.insert("1460");
	route35CCIBStops.insert("1458");
	route35CCIBStops.insert("2125");
	route35CCIBStops.insert("1534");
	route35CCIBStops.insert("1532");
	route35CCIBStops.insert("1530");
	route35CCIBStops.insert("1527");
	route35CCIBStops.insert("1492");
	route35CCIBStops.insert("1648");
	route35CCIBStops.insert("1650");
	route35CCIBStops.insert("2286");
	route35CCIBStops.insert("2624");
	route35CCIBStops.insert("1653");
	route35CCIBStops.insert("2632");
	route35CCIBStops.insert("1749");
	route35CCIBStops.insert("1735");
	route35CCIBStops.insert("1738");
	route35CCIBStops.insert("2372");
	route35CCIBStops.insert("1744");
	route35CCIBStops.insert("1745");
	route35CCIBStops.insert("1571");
	route35CCIBStops.insert("1667");
	route35CCIBStops.insert("1665");
	route35CCIBStops.insert("1894");
	route35CCIBStops.insert("1457");
	route35CCIBStops.insert("2364");
	route35CCIBStops.insert("2700");

	test->generateStopUsageTable(route35CCIBStops, route35CCIB);
	
	//define variants
	std::set<std::string> route18Stops;
	std::string route18= "18-00-1-UCSC via Mission";

	route18Stops.insert("2701");
	route18Stops.insert("1591");
	route18Stops.insert("2731");
	route18Stops.insert("1630");
	route18Stops.insert("1624");
	route18Stops.insert("1620");
	route18Stops.insert("2342");
	route18Stops.insert("2344");
	route18Stops.insert("1907");
	route18Stops.insert("2393");
	route18Stops.insert("1909");
	route18Stops.insert("1910");
	route18Stops.insert("1510");

	route18Stops.insert("2739");
	route18Stops.insert("2659");
	route18Stops.insert("2660");
	route18Stops.insert("2661");
	route18Stops.insert("2662");
	route18Stops.insert("2663");
	route18Stops.insert("2619");
	route18Stops.insert("1619");
	route18Stops.insert("1623");
	route18Stops.insert("1625");
	route18Stops.insert("1629");
	route18Stops.insert("1590");
	route18Stops.insert("2572");
	route18Stops.insert("2700");

	test->generateStopUsageTable(route18Stops, route18);

	std::set<std::string> route22Stops;
	std::string route22= "22-00-8-UCSC Coastal Science Campus";

	route22Stops.insert("2744");
	route22Stops.insert("2750");
	route22Stops.insert("1349");
	route22Stops.insert("2740");
	route22Stops.insert("1351");
	route22Stops.insert("1408");
	route22Stops.insert("1352");
	route22Stops.insert("2569");
	route22Stops.insert("2570");
	route22Stops.insert("1623");
	route22Stops.insert("1226");
	route22Stops.insert("1227");
	route22Stops.insert("1228");
	route22Stops.insert("1230");
	route22Stops.insert("1232");
	route22Stops.insert("2739");
	route22Stops.insert("1510");
	route22Stops.insert("2376");
	route22Stops.insert("1231");
	route22Stops.insert("1630");
	route22Stops.insert("1624");
	route22Stops.insert("2747");
	route22Stops.insert("2420");
	route22Stops.insert("2330");
	route22Stops.insert("1350");
	route22Stops.insert("2749");

	test->generateStopUsageTable(route22Stops, route22);

	std::set<std::string> route20Stops;
	std::string route20= "20-00-23-UCSC via Westside";

	route20Stops.insert("2701");
	route20Stops.insert("2697");
	route20Stops.insert("2592");
	route20Stops.insert("2582");
	route20Stops.insert("2583");
	route20Stops.insert("2694");
	route20Stops.insert("2723");
	route20Stops.insert("1356");
	route20Stops.insert("1353");
	route20Stops.insert("2420");
	route20Stops.insert("2330");
	route20Stops.insert("2718");
	route20Stops.insert("2716");
	route20Stops.insert("2344");
	route20Stops.insert("1907");
	route20Stops.insert("2393");
	route20Stops.insert("1909");
	route20Stops.insert("1910");
	route20Stops.insert("1510");
	route20Stops.insert("2739");
	route20Stops.insert("2659");
	route20Stops.insert("2660");
	route20Stops.insert("2661");
	route20Stops.insert("2662");
	route20Stops.insert("2663");
	route20Stops.insert("2715");
	route20Stops.insert("2717");
	route20Stops.insert("2740");
	route20Stops.insert("1351");
	route20Stops.insert("1408");
	route20Stops.insert("1352");
	route20Stops.insert("2061");
	route20Stops.insert("1355");
	route20Stops.insert("2696");
	route20Stops.insert("2695");
	route20Stops.insert("2587");
	route20Stops.insert("2593");

	test->generateStopUsageTable(route20Stops, route20);

	std::set<std::string> route20CSCIBStops;
	std::string route20CSCIB= "20-07-26-UCSC via Westside CSC IB";

	route20CSCIBStops.insert("2701");
	route20CSCIBStops.insert("2697");
	route20CSCIBStops.insert("2592");
	route20CSCIBStops.insert("2582");
	route20CSCIBStops.insert("2583");
	route20CSCIBStops.insert("2694");
	route20CSCIBStops.insert("2723");
	route20CSCIBStops.insert("1356");
	route20CSCIBStops.insert("1353");
	route20CSCIBStops.insert("2420");
	route20CSCIBStops.insert("2330");
	route20CSCIBStops.insert("2718");
	route20CSCIBStops.insert("2716");
	route20CSCIBStops.insert("2344");
	route20CSCIBStops.insert("1907");
	route20CSCIBStops.insert("2393");
	route20CSCIBStops.insert("1909");
	route20CSCIBStops.insert("1910");
	route20CSCIBStops.insert("1510");
	route20CSCIBStops.insert("2739");
	route20CSCIBStops.insert("2659");
	route20CSCIBStops.insert("2660");
	route20CSCIBStops.insert("2661");
	route20CSCIBStops.insert("2662");
	route20CSCIBStops.insert("2663");
	route20CSCIBStops.insert("2715");
	route20CSCIBStops.insert("2717");
	route20CSCIBStops.insert("1350");
	route20CSCIBStops.insert("2749");
	route20CSCIBStops.insert("2744");
	route20CSCIBStops.insert("2750");
	route20CSCIBStops.insert("2740");
	route20CSCIBStops.insert("1351");
	route20CSCIBStops.insert("1408");
	route20CSCIBStops.insert("1352");
	route20CSCIBStops.insert("2061");
	route20CSCIBStops.insert("1355");
	route20CSCIBStops.insert("2696");
	route20CSCIBStops.insert("2695");
	route20CSCIBStops.insert("2587");
	route20CSCIBStops.insert("2593");


	test->generateStopUsageTable(route20CSCIBStops, route20CSCIB);

	std::set<std::string> route20CSCOBStops;
	std::string route20CSCOB= "20-06-25-UCSC via Westside CSC OB";

	route20CSCOBStops.insert("2701");
	route20CSCOBStops.insert("2697");
	route20CSCOBStops.insert("2592");
	route20CSCOBStops.insert("2582");
	route20CSCOBStops.insert("2583");
	route20CSCOBStops.insert("2694");
	route20CSCOBStops.insert("2723");
	route20CSCOBStops.insert("1356");
	route20CSCOBStops.insert("1353");
	route20CSCOBStops.insert("2420");
	route20CSCOBStops.insert("2330");
	route20CSCOBStops.insert("2718");
	route20CSCOBStops.insert("2716");
	route20CSCOBStops.insert("2344");
	route20CSCOBStops.insert("1907");
	route20CSCOBStops.insert("2393");
	route20CSCOBStops.insert("1909");
	route20CSCOBStops.insert("1910");
	route20CSCOBStops.insert("1510");
	route20CSCOBStops.insert("2739");
	route20CSCOBStops.insert("2659");
	route20CSCOBStops.insert("2660");
	route20CSCOBStops.insert("2661");
	route20CSCOBStops.insert("2662");
	route20CSCOBStops.insert("2663");
	route20CSCOBStops.insert("2715");
	route20CSCOBStops.insert("2717");
	route20CSCOBStops.insert("1350");
	route20CSCOBStops.insert("2749");
	route20CSCOBStops.insert("2744");
	route20CSCOBStops.insert("2750");
	route20CSCOBStops.insert("2740");
	route20CSCOBStops.insert("1351");
	route20CSCOBStops.insert("1408");
	route20CSCOBStops.insert("1352");
	route20CSCOBStops.insert("2061");
	route20CSCOBStops.insert("1355");
	route20CSCOBStops.insert("2696");
	route20CSCOBStops.insert("2695");
	route20CSCOBStops.insert("2587");
	route20CSCOBStops.insert("2593");

	test->generateStopUsageTable(route20CSCOBStops, route20CSCOB);


	std::set<std::string> route10Stops;
	std::string route10= "10-00-11-UCSC via High";

	route10Stops.insert("2701");
	route10Stops.insert("2303");
	route10Stops.insert("2304");
	route10Stops.insert("2302");
	route10Stops.insert("2085");
	route10Stops.insert("1517");
	route10Stops.insert("1516");
	route10Stops.insert("1515");
	route10Stops.insert("1513");
	route10Stops.insert("2090");
	route10Stops.insert("2739");
	route10Stops.insert("1510");
	route10Stops.insert("2497");
	route10Stops.insert("2091");
	route10Stops.insert("1512");
	route10Stops.insert("2086");
	route10Stops.insert("2394");
	route10Stops.insert("2656");
	route10Stops.insert("1638");
	route10Stops.insert("2627");
	route10Stops.insert("2364");

	test->generateStopUsageTable(route10Stops, route10);


}