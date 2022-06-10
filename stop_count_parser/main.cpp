#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

#define NUM_DAYS 7

#define STOP_ID 0
#define TRIP_ID 1
#define BOARDINGS 2

int main() {

	std::cout << "test\n";

	//vector of stop_ids for each route
	std::vector<std::string> stopIDs;

	stopIDs.push_back("1247");
	stopIDs.push_back("1246");
	stopIDs.push_back("1244");
	stopIDs.push_back("1242");
	stopIDs.push_back("1238");
	stopIDs.push_back("1561");
	stopIDs.push_back("2124");
	stopIDs.push_back("1558");
	stopIDs.push_back("1556");
	stopIDs.push_back("1554");
	stopIDs.push_back("1552");
	stopIDs.push_back("1550");
	stopIDs.push_back("1548");
	stopIDs.push_back("2128");
	stopIDs.push_back("1543");
	stopIDs.push_back("1474");
	stopIDs.push_back("2294");
	stopIDs.push_back("1466");
	stopIDs.push_back("1465");
	stopIDs.push_back("1471");
	stopIDs.push_back("1460");
	stopIDs.push_back("1458");
	stopIDs.push_back("2125");
	stopIDs.push_back("1534");
	stopIDs.push_back("1532");
	stopIDs.push_back("1530");
	stopIDs.push_back("1527");
	stopIDs.push_back("1492");
	stopIDs.push_back("1648");
	stopIDs.push_back("1650");
	stopIDs.push_back("2286");
	stopIDs.push_back("2624");
	stopIDs.push_back("1653");
	stopIDs.push_back("2632");
	stopIDs.push_back("1749");
	stopIDs.push_back("1735");
	stopIDs.push_back("1738");
	stopIDs.push_back("2372");
	stopIDs.push_back("1744");
	stopIDs.push_back("1745");
	stopIDs.push_back("1571");
	stopIDs.push_back("1667");
	stopIDs.push_back("1665");
	stopIDs.push_back("1894");
	stopIDs.push_back("1457");
	stopIDs.push_back("2364");
	stopIDs.push_back("2700");
	

	//vector of trip_ids
	std::vector<std::string> tripIDs;

	tripIDs.push_back("350502");
	tripIDs.push_back("350403");
	tripIDs.push_back("350902");
	tripIDs.push_back("350603");
	tripIDs.push_back("350704");
	tripIDs.push_back("350208");
	tripIDs.push_back("350407");
	tripIDs.push_back("350906");
	tripIDs.push_back("350607");
	tripIDs.push_back("350708");
	tripIDs.push_back("350212");
	tripIDs.push_back("350411");
	tripIDs.push_back("350910");
	tripIDs.push_back("350611");
	tripIDs.push_back("350712");
	tripIDs.push_back("350714");


	//for each trip_id

	//create the first line for the output file
	std::ofstream outputFile;
	outputFile.open("stop_count_totals.csv");
	outputFile << "tripID,"; //tripID column
	//stopID columns
	for (int m = 0; m < stopIDs.size(); m++) {
		outputFile << stopIDs.at(m) << ",";
	}
	outputFile << std::endl;


	for (int i = 0; i < tripIDs.size(); i++) {
		std::cout << tripIDs.at(i) << std::endl;
		//output the tripID to the file
		outputFile << tripIDs.at(i) << ",";

		//create an unordered map of stop_id and count, with a default value of 0
		std::unordered_map<std::string, int> stopCountMap;
		for (int a = 0; a < stopIDs.size(); a++) {
			stopCountMap.insert(std::pair<std::string, int>(stopIDs.at(a), 0));
		}

		//read through the file and for each stop_id, get the count for that stop_id
		std::ifstream inputFile;
		std::string lineFromFile;
		inputFile.open("count.csv");
		if (inputFile.is_open()) {
			//throw away the first line
			getline(inputFile, lineFromFile);

			//go through the rest of the lines in the file
			while(getline(inputFile, lineFromFile)) {
				std::string stopID;
				std::string tripID;
				std::string boardings;

				char currentReadChar;
				int commaCount = 0;
				for (int j = 0; commaCount <= BOARDINGS; j++) {
					currentReadChar = lineFromFile.at(j);
					if (currentReadChar == ',') {
						commaCount++;
					} else if (currentReadChar != ' ') {
						if (commaCount == STOP_ID) {
							stopID.push_back(currentReadChar);
						} else if (commaCount == TRIP_ID) {
							tripID.push_back(currentReadChar);
						} else if (commaCount == BOARDINGS) {
							boardings.push_back(currentReadChar);
						}
					}
				}

				//only process if it's for the correct trip_id
				if (tripID.compare(tripIDs.at(i)) == 0) {
					//add the boading value to the counter for the current stop in the unordered map
					std::unordered_map<std::string, int>::iterator myIterator;
					myIterator = stopCountMap.find(stopID);
					myIterator->second += stoi(boardings);

				}

			}

			inputFile.close();
		}

		//output the contents of the map to the file in order
		for (int k = 0; k < stopIDs.size(); k++) {
			std::unordered_map<std::string, int>::iterator myIterator2;
				myIterator2 = stopCountMap.find(stopIDs.at(k));
				outputFile << myIterator2->second << ",";
				std::cout << stopIDs.at(k) << ":" << myIterator2->second << std::endl;
		}

		outputFile << std::endl; //end the line of the CSV once the values for every stop have been written
	}

	outputFile.close();

}