#include "avl.h"

//bus history class ///////////
//constructor
BusHistory::BusHistory(std::string fleetID) {
	this.fleetID = fleetID;
}

//add a stop time to the vector (at the end, assuming Syncromatics is behaving and stop times are in order for each bus)
void BusHistory::insertStopTime(StopTime* insertMe) {
	this.stopTImesVector.push_back(insertMe);

}

//stop time class /////////////////////////
//constructor
StopTime::StopTime(std::string arrivalTime, std::string departureTime, std::string departureTime, std::string stopID, std::string routePatternName) {
	this.arrivalTime = removeSyncromaticsGarbageFromTime(arrivalTime);
	this.departureTime = removeSyncromaticsGarbageFromTime(departureTime);
	this.arrivalTimeInt = convertTimeStringToInt(this.arrivalTime);
	this.departureTimeInt = convertTimeStringToInt(this.departureTime);
	this.stopID = stopID;
	this.routePatternName = routePatternName;
}


std::string StopTime::getArrivalTimeInt() {
	return this.arrivalTimeInt;
}
std::string StopTime::getDepartureimeInt() {
	return this.departureTimeInt;
}

//remove syncromatics garbage from time
std::string StopTime::removeSyncromaticsGarbageFromTime(std::string fixme) {
	std::string output;
	for (int i = 11; i < 18; i++) {
		output.append(fixme.at(i));
	}
	return output;
}

int StopTime::convertTimeStringToInt(std::string convertMe) {
	int output = 0;
	output = (convertMe[7]-48) + (convertMe[6]-48)*10 + (convertMe[4]-48)*60 + (convertMe[3]-48)*600 + (convertMe[1]-48)*3600 + (convertMe[0]-48)*36000;
	return output;
}