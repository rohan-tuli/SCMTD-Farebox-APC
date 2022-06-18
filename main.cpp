#include "avl.h"

int main() {

	//define route
	std::set<std::string> stops;
	std::string route= "66-03-11-Live Oak via 17th/HarborHS IB";


stops.insert("2801");
stops.insert("2167");
stops.insert("2163");
stops.insert("2161");
stops.insert("2159");
stops.insert("1692");
stops.insert("1690");
stops.insert("1687");
stops.insert("2177");
stops.insert("1682");
stops.insert("2617");
stops.insert("2173");
stops.insert("2174");
stops.insert("2175");
stops.insert("2178");
stops.insert("1269");
stops.insert("1266");
stops.insert("2296");
stops.insert("1263");
stops.insert("1917");
stops.insert("1919");
stops.insert("2732");
stops.insert("2352");
stops.insert("1803");
stops.insert("1801");
stops.insert("1799");
stops.insert("1798");
stops.insert("1796");
stops.insert("1903");
stops.insert("1901");
stops.insert("1899");
stops.insert("1895");
stops.insert("1894");
stops.insert("1457");
stops.insert("2364");


	std::unordered_map<std::string, BusHistory*> april3map = getAVL("april3.csv");
	//test loading file
	EventHistory* april3 = new EventHistory("stops.csv");
	//test->printStops();
	april3->readFromGFI("april3_gfi.csv", april3map);
	march3->generateBoardingsPerStopCSV("april3");
	
	april3->generateStopUsageTable("april3", stops, route);

		std::unordered_map<std::string, BusHistory*> april4map = getAVL("april4.csv");
	//test loading file
	EventHistory* april4 = new EventHistory("stops.csv");
	//test->printStops();
	april4->readFromGFI("april4_gfi.csv", april4map);
	march3->generateBoardingsPerStopCSV("april4");
	
	april4->generateStopUsageTable("april4", stops, route);

		std::unordered_map<std::string, BusHistory*> april10map = getAVL("april10.csv");
	//test loading file
	EventHistory* april10 = new EventHistory("stops.csv");
	//test->printStops();
	april10->readFromGFI("april10_gfi.csv", april10map);
	march3->generateBoardingsPerStopCSV("april10");
	
	april10->generateStopUsageTable("april10", stops, route);

		std::unordered_map<std::string, BusHistory*> april11map = getAVL("april11.csv");
	//test loading file
	EventHistory* april11 = new EventHistory("stops.csv");
	//test->printStops();
	april11->readFromGFI("april11_gfi.csv", april11map);
	march3->generateBoardingsPerStopCSV("april11");
	
	april11->generateStopUsageTable("april11", stops, route);

		std::unordered_map<std::string, BusHistory*> april17map = getAVL("april17.csv");
	//test loading file
	EventHistory* april17 = new EventHistory("stops.csv");
	//test->printStops();
	april17->readFromGFI("april17_gfi.csv", april17map);
	march3->generateBoardingsPerStopCSV("april17");
	
	april17->generateStopUsageTable("april17", stops, route);

		std::unordered_map<std::string, BusHistory*> april18map = getAVL("april18.csv");
	//test loading file
	EventHistory* april18 = new EventHistory("stops.csv");
	//test->printStops();
	april18->readFromGFI("april18_gfi.csv", april18map);
	march3->generateBoardingsPerStopCSV("april18");
	
	april18->generateStopUsageTable("april18", stops, route);

	//get data

	/*
	std::unordered_map<std::string, BusHistory*> testMap = getAVL("april15.csv");
	//test loading file
	EventHistory* test = new EventHistory("stops.csv");
	//test->printStops();
	test->readFromGFI("april15_gfi.csv", testMap);
	test->generateBoardingsPerStopCSV();
	//test->generateEventDistribution("2302");

	test->generateStopUsageTable("april15", route35CCIBStops, route35CCIB);
	*/

	// std::unordered_map<std::string, BusHistory*> march28map = getAVL("march28.csv");
	// //test loading file
	// EventHistory* march28 = new EventHistory("stops.csv");
	
	// march28->readFromGFI("march28_gfi.csv", march28map);
	
	// march28->generateStopUsageTable("march28", stops, route);
	// march28->generateBoardingsPerStopCSV("march28");

	// std::unordered_map<std::string, BusHistory*> march29map = getAVL("march29.csv");
	// //test loading file
	// EventHistory* march29 = new EventHistory("stops.csv");
	// //test->printStops();
	// march29->readFromGFI("march29_gfi.csv", march29map);
	
	// march29->generateStopUsageTable("march29", stops, route);
	// march29->generateBoardingsPerStopCSV("march29");

	// std::unordered_map<std::string, BusHistory*> march30map = getAVL("march30.csv");
	// //test loading file
	// EventHistory* march30 = new EventHistory("stops.csv");
	// //test->printStops();
	// march30->readFromGFI("march30_gfi.csv", march30map);
	// march30->generateBoardingsPerStopCSV("march30");
	
	// march30->generateStopUsageTable("march30", stops, route);

	// std::unordered_map<std::string, BusHistory*> march31map = getAVL("march31.csv");
	// //test loading file
	// EventHistory* march31 = new EventHistory("stops.csv");
	// //test->printStops();
	// march31->readFromGFI("march31_gfi.csv", march31map);
	
	// march31->generateStopUsageTable("march31", stops, route);
	// march31->generateBoardingsPerStopCSV("march31");

	// std::unordered_map<std::string, BusHistory*> april1map = getAVL("april1.csv");
	// //test loading file
	// EventHistory* april1 = new EventHistory("stops.csv");
	// //test->printStops();
	// april1->readFromGFI("april1_gfi.csv", april1map);
	
	// april1->generateStopUsageTable("april1", stops, route);
	// april1->generateBoardingsPerStopCSV("april1");

	// std::unordered_map<std::string, BusHistory*> april4map = getAVL("april4.csv");
	// //test loading file
	// EventHistory* april4 = new EventHistory("stops.csv");
	// //test->printStops();
	// april4->readFromGFI("april4_gfi.csv", april4map);
	
	// april4->generateStopUsageTable("april4", stops, route);
	// april4->generateBoardingsPerStopCSV("april4");

	// std::unordered_map<std::string, BusHistory*> april5map = getAVL("april5.csv");
	// //test loading file
	// EventHistory* april5 = new EventHistory("stops.csv");
	// //test->printStops();
	// april5->readFromGFI("april5_gfi.csv", april5map);
	
	// april5->generateStopUsageTable("april5", stops, route);
	// april5->generateBoardingsPerStopCSV("april5");

	// std::unordered_map<std::string, BusHistory*> april6map = getAVL("april6.csv");
	// //test loading file
	// EventHistory* april6 = new EventHistory("stops.csv");
	// //test->printStops();
	// april6->readFromGFI("april6_gfi.csv", april6map);
	
	// april6->generateStopUsageTable("april6", stops, route);
	// april6->generateBoardingsPerStopCSV("april6");

	// std::unordered_map<std::string, BusHistory*> april7map = getAVL("april7.csv");
	// //test loading file
	// EventHistory* april7 = new EventHistory("stops.csv");
	// //test->printStops();
	// april7->readFromGFI("april7_gfi.csv", april7map);
	
	// april7->generateStopUsageTable("april7", stops, route);

	// std::unordered_map<std::string, BusHistory*> april8map = getAVL("april8.csv");
	// //test loading file
	// EventHistory* april8 = new EventHistory("stops.csv");
	// //test->printStops();
	// april8->readFromGFI("april8_gfi.csv", april8map);
	
	// april8->generateStopUsageTable("april8", stops, route);

	// std::unordered_map<std::string, BusHistory*> april11map = getAVL("april11.csv");
	// //test loading file
	// EventHistory* april11 = new EventHistory("stops.csv");
	// //test->printStops();
	// april11->readFromGFI("april11_gfi.csv", april11map);
	
	// april11->generateStopUsageTable("april11", stops, route);

	// std::unordered_map<std::string, BusHistory*> april12map = getAVL("april12.csv");
	// //test loading file
	// EventHistory* april12 = new EventHistory("stops.csv");
	// //test->printStops();
	// april12->readFromGFI("april12_gfi.csv", april12map);
	
	// april12->generateStopUsageTable("april12", stops, route);

	// std::unordered_map<std::string, BusHistory*> april13map = getAVL("april13.csv");
	// //test loading file
	// EventHistory* april13 = new EventHistory("stops.csv");
	// //test->printStops();
	// april13->readFromGFI("april13_gfi.csv", april13map);
	
	// april13->generateStopUsageTable("april13", stops, route);

	// std::unordered_map<std::string, BusHistory*> april14map = getAVL("april14.csv");
	// //test loading file
	// EventHistory* april14 = new EventHistory("stops.csv");
	// //test->printStops();
	// april14->readFromGFI("april14_gfi.csv", april14map);
	
	// april14->generateStopUsageTable("april14", stops, route);

	// std::unordered_map<std::string, BusHistory*> april15map = getAVL("april15.csv");
	// //test loading file
	// EventHistory* april15 = new EventHistory("stops.csv");
	// //test->printStops();
	// april15->readFromGFI("april15_gfi.csv", april15map);
	
	// april15->generateStopUsageTable("april15", stops, route);

	// 	std::unordered_map<std::string, BusHistory*> april18map = getAVL("april18.csv");
	// //test loading file
	// EventHistory* april18 = new EventHistory("stops.csv");
	// //test->printStops();
	// april18->readFromGFI("april18_gfi.csv", april18map);
	
	// april18->generateStopUsageTable("april18", stops, route);

	// 	std::unordered_map<std::string, BusHistory*> april19map = getAVL("april19.csv");
	// //test loading file
	// EventHistory* april19 = new EventHistory("stops.csv");
	// //test->printStops();
	// april19->readFromGFI("april19_gfi.csv", april19map);
	
	// april19->generateStopUsageTable("april19", stops, route);

	// 	std::unordered_map<std::string, BusHistory*> april20map = getAVL("april20.csv");
	// //test loading file
	// EventHistory* april20 = new EventHistory("stops.csv");
	// //test->printStops();
	// april20->readFromGFI("april20_gfi.csv", april20map);
	
	// april20->generateStopUsageTable("april20", stops, route);

	// 	std::unordered_map<std::string, BusHistory*> april21map = getAVL("april21.csv");
	// //test loading file
	// EventHistory* april21 = new EventHistory("stops.csv");
	// //test->printStops();
	// april21->readFromGFI("april21_gfi.csv", april21map);
	// april21->generateBoardingsPerStopCSV("april21");
	
	// april21->generateStopUsageTable("april21", stops, route);



}