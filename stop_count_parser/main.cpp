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
	stopIDs.push_back("2704");
	stopIDs.push_back("2666");
	stopIDs.push_back("1781");	
	stopIDs.push_back("1783");
	stopIDs.push_back("2668");
	stopIDs.push_back("1791");
	stopIDs.push_back("1793");
	stopIDs.push_back("2186");
	stopIDs.push_back("1795");
	stopIDs.push_back("1797");
	stopIDs.push_back("1800");
	stopIDs.push_back("1289");
	stopIDs.push_back("1290");
	stopIDs.push_back("2642");
	stopIDs.push_back("1293");
	stopIDs.push_back("1297");
	stopIDs.push_back("1299");
	stopIDs.push_back("1301");
	stopIDs.push_back("1302");
	stopIDs.push_back("2802");
	stopIDs.push_back("2148");
	stopIDs.push_back("2149");
	stopIDs.push_back("1818");
	stopIDs.push_back("1820");
	stopIDs.push_back("1823");
	stopIDs.push_back("1824");
	stopIDs.push_back("1825");
	stopIDs.push_back("1830");
	stopIDs.push_back("1832");
	stopIDs.push_back("1835");
	stopIDs.push_back("1836");
	stopIDs.push_back("2722");
	stopIDs.push_back("1840");
	stopIDs.push_back("1848");
	stopIDs.push_back("1144");
	stopIDs.push_back("1142");
	stopIDs.push_back("1139");
	stopIDs.push_back("2204");


	//vector of trip_ids
	std::vector<std::string> tripIDs;

	tripIDs.push_back("693501");
	tripIDs.push_back("693202");
	tripIDs.push_back("693303");
	tripIDs.push_back("353701");
	tripIDs.push_back("693204");
	tripIDs.push_back("693305");
	tripIDs.push_back("353703");
	tripIDs.push_back("693206");
	tripIDs.push_back("693507");
	tripIDs.push_back("693108");
	tripIDs.push_back("693309");


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