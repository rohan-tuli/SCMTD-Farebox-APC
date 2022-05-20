#include "avl.h"

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
		if (currentReadChar == ',') {
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
			}
		}
	}

	this->arrivalTime = removeSyncromaticsGarbageFromTime(rawArrivalTime);
	this->departureTime = removeSyncromaticsGarbageFromTime(rawDepartureTime);
	this->arrivalTimeInt = convertTimeStringToInt(this->arrivalTime);
	this->departureTimeInt = convertTimeStringToInt(this->departureTime);
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
	for (int i = 11; i < 18; i++) {
		output.push_back(fixme.at(i));
	}
	return output;
}

int StopTime::convertTimeStringToInt(std::string convertMe) {
	int output = 0;
	output = (convertMe[7]-48) + (convertMe[6]-48)*10 + (convertMe[4]-48)*60 + (convertMe[3]-48)*600 + (convertMe[1]-48)*3600 + (convertMe[0]-48)*36000;
	return output;
}