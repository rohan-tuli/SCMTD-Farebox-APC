#include "avl.h"

int main() {

	//define route
	std::set<std::string> stops;
	std::string route= "72-00-4-Wats Hospital/Pinto Lake";

stops.insert("2902");
stops.insert("1059");
stops.insert("1060");
stops.insert("1061");
stops.insert("1062");
stops.insert("1070");
stops.insert("2725");
stops.insert("1127");
stops.insert("1052");
stops.insert("2233");
stops.insert("1053");
stops.insert("1054");
stops.insert("2234");
stops.insert("2554");
stops.insert("1069");
stops.insert("1193");
stops.insert("1191");
stops.insert("2235");
stops.insert("2573");
stops.insert("1040");
stops.insert("1149");
stops.insert("1147");
stops.insert("1145");
stops.insert("2477");
stops.insert("1989");
stops.insert("2567");
stops.insert("2466");
stops.insert("2465");
stops.insert("2467");
stops.insert("2641");
stops.insert("2469");
stops.insert("2191");

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

	std::unordered_map<std::string, BusHistory*> march28map = getAVL("march28.csv");
	//test loading file
	EventHistory* march28 = new EventHistory("stops.csv");
	//test->printStops();
	march28->readFromGFI("march28_gfi.csv", march28map);
	
	march28->generateStopUsageTable("march28", stops, route);

	std::unordered_map<std::string, BusHistory*> march29map = getAVL("march29.csv");
	//test loading file
	EventHistory* march29 = new EventHistory("stops.csv");
	//test->printStops();
	march29->readFromGFI("march29_gfi.csv", march29map);
	
	march29->generateStopUsageTable("march29", stops, route);

	std::unordered_map<std::string, BusHistory*> march30map = getAVL("march30.csv");
	//test loading file
	EventHistory* march30 = new EventHistory("stops.csv");
	//test->printStops();
	march30->readFromGFI("march30_gfi.csv", march30map);
	
	march30->generateStopUsageTable("march30", stops, route);

	std::unordered_map<std::string, BusHistory*> march31map = getAVL("march31.csv");
	//test loading file
	EventHistory* march31 = new EventHistory("stops.csv");
	//test->printStops();
	march31->readFromGFI("march31_gfi.csv", march31map);
	
	march31->generateStopUsageTable("march31", stops, route);

	std::unordered_map<std::string, BusHistory*> april1map = getAVL("april1.csv");
	//test loading file
	EventHistory* april1 = new EventHistory("stops.csv");
	//test->printStops();
	april1->readFromGFI("april1_gfi.csv", april1map);
	
	april1->generateStopUsageTable("april1", stops, route);

	std::unordered_map<std::string, BusHistory*> april4map = getAVL("april4.csv");
	//test loading file
	EventHistory* april4 = new EventHistory("stops.csv");
	//test->printStops();
	april4->readFromGFI("april4_gfi.csv", april4map);
	
	april4->generateStopUsageTable("april4", stops, route);

	std::unordered_map<std::string, BusHistory*> april5map = getAVL("april5.csv");
	//test loading file
	EventHistory* april5 = new EventHistory("stops.csv");
	//test->printStops();
	april5->readFromGFI("april5_gfi.csv", april5map);
	
	april5->generateStopUsageTable("april5", stops, route);

	std::unordered_map<std::string, BusHistory*> april6map = getAVL("april6.csv");
	//test loading file
	EventHistory* april6 = new EventHistory("stops.csv");
	//test->printStops();
	april6->readFromGFI("april6_gfi.csv", april6map);
	
	april6->generateStopUsageTable("april6", stops, route);

	std::unordered_map<std::string, BusHistory*> april7map = getAVL("april7.csv");
	//test loading file
	EventHistory* april7 = new EventHistory("stops.csv");
	//test->printStops();
	april7->readFromGFI("april7_gfi.csv", april7map);
	
	april7->generateStopUsageTable("april7", stops, route);

	std::unordered_map<std::string, BusHistory*> april8map = getAVL("april8.csv");
	//test loading file
	EventHistory* april8 = new EventHistory("stops.csv");
	//test->printStops();
	april8->readFromGFI("april8_gfi.csv", april8map);
	
	april8->generateStopUsageTable("april8", stops, route);

	std::unordered_map<std::string, BusHistory*> april11map = getAVL("april11.csv");
	//test loading file
	EventHistory* april11 = new EventHistory("stops.csv");
	//test->printStops();
	april11->readFromGFI("april11_gfi.csv", april11map);
	
	april11->generateStopUsageTable("april11", stops, route);

	std::unordered_map<std::string, BusHistory*> april12map = getAVL("april12.csv");
	//test loading file
	EventHistory* april12 = new EventHistory("stops.csv");
	//test->printStops();
	april12->readFromGFI("april12_gfi.csv", april12map);
	
	april12->generateStopUsageTable("april12", stops, route);

	std::unordered_map<std::string, BusHistory*> april13map = getAVL("april13.csv");
	//test loading file
	EventHistory* april13 = new EventHistory("stops.csv");
	//test->printStops();
	april13->readFromGFI("april13_gfi.csv", april13map);
	
	april13->generateStopUsageTable("april13", stops, route);

	std::unordered_map<std::string, BusHistory*> april14map = getAVL("april14.csv");
	//test loading file
	EventHistory* april14 = new EventHistory("stops.csv");
	//test->printStops();
	april14->readFromGFI("april14_gfi.csv", april14map);
	
	april14->generateStopUsageTable("april14", stops, route);

	std::unordered_map<std::string, BusHistory*> april15map = getAVL("april15.csv");
	//test loading file
	EventHistory* april15 = new EventHistory("stops.csv");
	//test->printStops();
	april15->readFromGFI("april15_gfi.csv", april15map);
	
	april15->generateStopUsageTable("april15", stops, route);

		std::unordered_map<std::string, BusHistory*> april18map = getAVL("april18.csv");
	//test loading file
	EventHistory* april18 = new EventHistory("stops.csv");
	//test->printStops();
	april18->readFromGFI("april18_gfi.csv", april18map);
	
	april18->generateStopUsageTable("april18", stops, route);

		std::unordered_map<std::string, BusHistory*> april19map = getAVL("april19.csv");
	//test loading file
	EventHistory* april19 = new EventHistory("stops.csv");
	//test->printStops();
	april19->readFromGFI("april19_gfi.csv", april19map);
	
	april19->generateStopUsageTable("april19", stops, route);

		std::unordered_map<std::string, BusHistory*> april20map = getAVL("april20.csv");
	//test loading file
	EventHistory* april20 = new EventHistory("stops.csv");
	//test->printStops();
	april20->readFromGFI("april20_gfi.csv", april20map);
	
	april20->generateStopUsageTable("april20", stops, route);

		std::unordered_map<std::string, BusHistory*> april21map = getAVL("april21.csv");
	//test loading file
	EventHistory* april21 = new EventHistory("stops.csv");
	//test->printStops();
	april21->readFromGFI("april21_gfi.csv", april21map);
	
	april21->generateStopUsageTable("april21", stops, route);



}