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

	stopIDs.push_back("2592");
	stopIDs.push_back("2582");
	stopIDs.push_back("2583");
	stopIDs.push_back("2584");
	stopIDs.push_back("1220");
	stopIDs.push_back("2291");
	stopIDs.push_back("1223");
	stopIDs.push_back("1226");
	stopIDs.push_back("1227");
	stopIDs.push_back("1228");
	stopIDs.push_back("1230");
	stopIDs.push_back("1232");
	stopIDs.push_back("2376");
	stopIDs.push_back("1231");
	stopIDs.push_back("2056");
	stopIDs.push_back("1225");
	stopIDs.push_back("1224");
	stopIDs.push_back("1222");
	stopIDs.push_back("1219");
	stopIDs.push_back("2585");
	stopIDs.push_back("2586");
	stopIDs.push_back("2587");
	stopIDs.push_back("2593");


	//vector of trip_ids
	std::vector<std::string> tripIDs;

	tripIDs.push_back("193101");
	tripIDs.push_back("193102");
	tripIDs.push_back("193103");
	tripIDs.push_back("183201");
	tripIDs.push_back("193105");
	tripIDs.push_back("193106");
	tripIDs.push_back("193107");
	tripIDs.push_back("193108");
	tripIDs.push_back("193109");
	tripIDs.push_back("193110");
	tripIDs.push_back("193111");
	tripIDs.push_back("193112");
	tripIDs.push_back("103110");
	tripIDs.push_back("183308");
	tripIDs.push_back("183309");


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