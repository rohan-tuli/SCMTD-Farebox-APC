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

stopIDs.push_back("2901");
stopIDs.push_back("1177");
stopIDs.push_back("1179");
stopIDs.push_back("2192");
stopIDs.push_back("2734");
stopIDs.push_back("1141");
stopIDs.push_back("1143");
stopIDs.push_back("2738");
stopIDs.push_back("2480");
stopIDs.push_back("2209");
stopIDs.push_back("2481");
stopIDs.push_back("1182");
stopIDs.push_back("1183");
stopIDs.push_back("1185");
stopIDs.push_back("2714");
stopIDs.push_back("2491");
stopIDs.push_back("1095");
stopIDs.push_back("1084");
stopIDs.push_back("1086");
stopIDs.push_back("1006");
stopIDs.push_back("2433");
stopIDs.push_back("2436");
stopIDs.push_back("1015");
stopIDs.push_back("2195");
stopIDs.push_back("1020");
stopIDs.push_back("2196");
stopIDs.push_back("2197");
stopIDs.push_back("1026");
stopIDs.push_back("2198");
stopIDs.push_back("2265");
stopIDs.push_back("2576");
stopIDs.push_back("2226");
stopIDs.push_back("1113");
stopIDs.push_back("1110");
stopIDs.push_back("2227");
stopIDs.push_back("2453");
stopIDs.push_back("1105");
stopIDs.push_back("2228");
stopIDs.push_back("1101");
stopIDs.push_back("2434");
stopIDs.push_back("2407");
stopIDs.push_back("2655");
stopIDs.push_back("2224");
stopIDs.push_back("2413");
stopIDs.push_back("2724");
stopIDs.push_back("2414");
stopIDs.push_back("2381");
stopIDs.push_back("2470");
stopIDs.push_back("1092");
stopIDs.push_back("1144");
stopIDs.push_back("1142");
stopIDs.push_back("1139");
stopIDs.push_back("1137");
stopIDs.push_back("2204");
stopIDs.push_back("2205");
	

	//vector of trip_ids
	std::vector<std::string> tripIDs;

tripIDs.push_back("750103");
tripIDs.push_back("750104");
tripIDs.push_back("750303");
tripIDs.push_back("750204");
tripIDs.push_back("750107");
tripIDs.push_back("750306");
tripIDs.push_back("750207");
tripIDs.push_back("750110");
tripIDs.push_back("750309");
tripIDs.push_back("750310");
tripIDs.push_back("790113");
tripIDs.push_back("790114");


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