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

stopIDs.push_back("2702");
stopIDs.push_back("2667");
stopIDs.push_back("1713");
stopIDs.push_back("1892");
stopIDs.push_back("1664");
stopIDs.push_back("1666");
stopIDs.push_back("1570");
stopIDs.push_back("2519");
stopIDs.push_back("1743");
stopIDs.push_back("1741");
stopIDs.push_back("2633");
stopIDs.push_back("1740");
stopIDs.push_back("1739");
stopIDs.push_back("1734");
stopIDs.push_back("1748");
stopIDs.push_back("1733");
stopIDs.push_back("1731");
stopIDs.push_back("1652");
stopIDs.push_back("2624");
stopIDs.push_back("2371");
stopIDs.push_back("1651");
stopIDs.push_back("1649");
stopIDs.push_back("1647");
stopIDs.push_back("2559");
stopIDs.push_back("1529");
stopIDs.push_back("1531");
stopIDs.push_back("1533");
stopIDs.push_back("1535");
stopIDs.push_back("1459");
stopIDs.push_back("1461");
stopIDs.push_back("1472");
stopIDs.push_back("1463");
stopIDs.push_back("2127");
stopIDs.push_back("1467");
stopIDs.push_back("1468");
stopIDs.push_back("1470");
stopIDs.push_back("1462");
stopIDs.push_back("2288");
stopIDs.push_back("1544");
stopIDs.push_back("1547");
stopIDs.push_back("1549");
stopIDs.push_back("1553");
stopIDs.push_back("1555");
stopIDs.push_back("1557");
stopIDs.push_back("1559");
stopIDs.push_back("1560");
stopIDs.push_back("2515");
stopIDs.push_back("1564");
stopIDs.push_back("1565");
stopIDs.push_back("2440");
stopIDs.push_back("1678");
stopIDs.push_back("1567");
stopIDs.push_back("2354");
stopIDs.push_back("2505");
stopIDs.push_back("2600");
stopIDs.push_back("2514");
stopIDs.push_back("1236");
stopIDs.push_back("1237");
stopIDs.push_back("1239");
stopIDs.push_back("1240");
stopIDs.push_back("1241");
stopIDs.push_back("1243");
stopIDs.push_back("2445");
stopIDs.push_back("0918");
	

	//vector of trip_ids
	std::vector<std::string> tripIDs;

	tripIDs.push_back("350713");
	tripIDs.push_back("350217");

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