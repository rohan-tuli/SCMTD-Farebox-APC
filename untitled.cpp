	std::unordered_map<std::string, BusHistory*> april3map = getAVL("april3.csv");
	//test loading file
	EventHistory* april3 = new EventHistory("stops.csv");
	//test->printStops();
	april3->readFromGFI("april3_gfi.csv", april3map);
	march3->generateBoardingsPerStopCSV("april3");
	
	april3->generateStopUsageTable("april3", stops, route);