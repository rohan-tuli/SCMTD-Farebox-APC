#include "avl.h"


//read from the stop time export CSV and return a vector of bus history classes (one entry for each bus)
std::unordered_map<std::string, BusHistory*> getAVL(std::string filePath) {
	//create an unordered map
	std::unordered_map<std::string, BusHistory*> myMap;

	//go through the file and input all the lines
	std::ifstream avlFile;
	std::string lineFromFile;
	avlFile.open(filePath);
	if (avlFile.is_open()) {
		//throw away the first line
		getline(avlFile, lineFromFile);
		//go throught the rest of the lines
		while(getline(avlFile, lineFromFile)) {
			//create new stop time node
			StopTime* myStopTime = new StopTime(lineFromFile);
			//check if there isn't already an entry in the map for this fleet id
			if (myMap.count(myStopTime->getFleetID()) == 0) {
				//create a new one and put it in the map
				BusHistory* myNewBusHistory = new BusHistory(myStopTime->getFleetID());
				myMap.insert(std::pair<std::string, BusHistory*>(myStopTime->getFleetID(), myNewBusHistory));
			} else {
				//add the stop time node to an existing one
				std::unordered_map<std::string, BusHistory*>::iterator myIterator;
				myIterator = myMap.find(myStopTime->getFleetID());
				myIterator->second->insertStopTime(myStopTime);
			}

		}
	}

	return myMap;
}


//bus history class ///////////
//constructor
BusHistory::BusHistory(std::string fleetID) {
	this->fleetID = fleetID;
}

//add a stop time to the vector (at the end, assuming Syncromatics is behaving and stop times are in order for each bus)
void BusHistory::insertStopTime(StopTime* insertMe) {
	this->stopTimesVector.push_back(insertMe);

}

//stop time class /////////////////////////
//constructor
StopTime::StopTime(std::string lineFromStopTimeExport) {
	//extract the relevant information from the line (using the indices defined in avl.h)
	std::string rawArrivalTime;
	std::string rawDepartureTime;
	char currentReadChar;
	int commaCount = 0;
	for (int i = 0; commaCount <= DEPART + 1; i++) {
		currentReadChar = lineFromStopTimeExport.at(i);
		if (currentReadChar == ',' && lineFromStopTimeExport.at(i + 1) != ' ') {
			commaCount++;
		} else {
			if (commaCount == PATTERN_NAME) {
				this->routePatternName.push_back(currentReadChar);
			} else if (commaCount == STOP_NAME) {
				this->stopName.push_back(currentReadChar);
			} else if (commaCount == STOP_NUMBER) {
				this->stopID.push_back(currentReadChar);
			} else if (commaCount == TRIP_NAME) {
				this->tripID.push_back(currentReadChar);
			} else if (commaCount == ARRIVE) {
				rawArrivalTime.push_back(currentReadChar);
			} else if (commaCount == DEPART) {
				rawDepartureTime.push_back(currentReadChar);
			} else if (commaCount == VEHICLE_NAME) {
				this->fleetID.push_back(currentReadChar);
			}
		}
	}

	this->arrivalTime = removeSyncromaticsGarbageFromTime(rawArrivalTime);
	this->departureTime = removeSyncromaticsGarbageFromTime(rawDepartureTime);
	this->arrivalTimeInt = convertTimeStringToInt(this->arrivalTime);
	this->departureTimeInt = convertTimeStringToInt(this->departureTime);

		std::cout << fleetID << std::endl;
		std::cout << routePatternName << std::endl;
		std::cout << stopName << std::endl;
		std::cout << stopID << std::endl;
		std::cout << arrivalTime << std::endl;
		std::cout << departureTime << std::endl << std::endl;

}

std::string StopTime::getFleetID() {
	return this->fleetID;
}

int StopTime::getArrivalTimeInt() {
	return this->arrivalTimeInt;
}
int StopTime::getDepartureimeInt() {
	return this->departureTimeInt;
}

//remove syncromatics garbage from time
std::string StopTime::removeSyncromaticsGarbageFromTime(std::string fixme) {
	std::string output;
	if (fixme.size() >= 18) {
		for (int i = 11; i <= 18; i++) {
			output.push_back(fixme.at(i));
		}
	} else {
		output = "00:00:00";
	}

	return output;
}

int StopTime::convertTimeStringToInt(std::string convertMe) {
	int output = 0;
	output = (convertMe[7]-48) + (convertMe[6]-48)*10 + (convertMe[4]-48)*60 + (convertMe[3]-48)*600 + (convertMe[1]-48)*3600 + (convertMe[0]-48)*36000;
	return output;
}