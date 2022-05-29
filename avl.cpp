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

int convertTimeStringToInt(std::string convertMe) {
	int output = 0;
	output = (convertMe[7]-48) + (convertMe[6]-48)*10 + (convertMe[4]-48)*60 + (convertMe[3]-48)*600 + (convertMe[1]-48)*3600 + (convertMe[0]-48)*36000;
	return output;
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

StopTime* BusHistory::findStopTimeObj(int eventTime) {
	//std::cout << "looking for stop time " << eventTime << std::endl;

	//first pass - iterate through the vector, and if the time int is between the arrival and departure times of a stop, return the obj for that stop time
	for (int i = 0; i < this->stopTimesVector.size(); i++) {
		if (this->stopTimesVector.at(i)->getArrivalTimeInt() <= eventTime && this->stopTimesVector.at(i)->getDepartureimeInt() >= eventTime) {
			//std::cout << "Found first pass match\n";
			return this->stopTimesVector.at(i);

		}
	}

	//if nothing has been found yet (the function hasn't returned), do a second pass (looking between nodes this time)
	for (int i = 0; i < this->stopTimesVector.size() - 1; i++) {
		//if it's between the current and next nodes
		if (eventTime > this->stopTimesVector.at(i)->getDepartureimeInt() && eventTime < this->stopTimesVector.at(i + 1)->getArrivalTimeInt()) {
			//find which node it's closer to
			int distanceToPrevious = eventTime - this->stopTimesVector.at(i)->getDepartureimeInt();
			int distanceToNext = this->stopTimesVector.at(i + 1)->getArrivalTimeInt() - eventTime;
			//if it's closer to the previous node (inclusive), return that one
			if (distanceToPrevious <= distanceToNext) {
				//std::cout << "Found second pass match (previous)\n";
				return this->stopTimesVector.at(i);
			} else { //if it's close to the next node, return that one
				//std::cout << "Found second pass match (next)\n";
				return this->stopTimesVector.at(i + 1);
			}
		}
	}

	//if still nothing has been found (the function still hasn't returned), create a dummy StopTime obj and return that
	//TODO
	//std::cout << "Creating empty...\n";
	StopTime* empty = new StopTime("0,0,0,Operator,0,0,0,0,0,0,0,0,0,0,0,0,0000,0,00/00/0000 00:00:00 -00:00,0,00/00/0000 00:00:00 -00:00,00/00/0000 00:00:00 -00:00,0,00/00/0000 00:00:00 -00:00,0,0,0,0,0");
	//std::cout << "Returnign empty node\n";
	return empty;
}

void BusHistory::printFleetID() {
	std::cout << this->fleetID << std::endl;
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
/*
		std::cout << fleetID << std::endl;
		std::cout << routePatternName << std::endl;
		std::cout << stopName << std::endl;
		std::cout << stopID << std::endl;
		std::cout << arrivalTime << std::endl;
		std::cout << departureTime << std::endl << std::endl; */

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

std::string StopTime::getDepartureTime() {
	return this->departureTime;
}

std::string StopTime::getStopID() {
	return this->stopID;
}

std::string StopTime::getRoutePatternName() {
	return this->routePatternName;
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


// stop log class /////////////////////////////
StopLog::StopLog(std::string stopID, std::string name, std::string lat, std::string lon) {
	this->stopID = stopID;
	this->name = name;
	this->lat = lat;
	this->lon = lon;
}

void StopLog::addStopEvent(StopTime* addMe) {
	stopEvents.push_back(addMe);
}


std::string StopLog::getStopID() {
	return this->stopID;
}
std::string StopLog::getLat() {
	return this->lat;
}
std::string StopLog::getLon() {
	return this->lon;
}

std::string StopLog::getName() {
	return this->name;
}

int StopLog::getSize() {
	return this->stopEvents.size();
}

std::vector<StopTime*> StopLog::getStopEvents() {
	return this->stopEvents;
}

// event history class /////////////////////////////
//constructor (create a stop log obj for every stop (read from GTFS), add to vector)
EventHistory::EventHistory(std::string GTFSfilePath) {
	
	//go through the file and input all the lines
	std::ifstream gtfsFile;
	std::string lineFromFile;
	gtfsFile.open(GTFSfilePath);
	if (gtfsFile.is_open()) {
		//throw away the first line
		getline(gtfsFile, lineFromFile);
		//go throught the rest of the lines
		while(getline(gtfsFile, lineFromFile)) {
			char currentReadChar;
			int commaCount = 0;

			//placeholder strings to put the extracted data
			std::string stopID;
			std::string lat;
			std::string lon;
			std::string name;

			for (int i = 0; commaCount <= GTFS_STOP_LON + 1; i++) {
				currentReadChar = lineFromFile.at(i);
				if (currentReadChar == ',' && lineFromFile.at(i + 1) != ' ') {
					commaCount++;
				} else {
					if (commaCount == GTFS_STOP_CODE) {
						stopID.push_back(currentReadChar);
					} else if (commaCount == GTFS_STOP_LAT) {
						lat.push_back(currentReadChar);
					} else if (commaCount == GTFS_STOP_LON) {
						lon.push_back(currentReadChar);
					} else if (commaCount == GTFS_STOP_NAME) {
						name.push_back(currentReadChar);
					}
				}
			}

			//create a new stopLog obj, using the extracted stopID, lat, and lon
			StopLog* myNewStopLog = new StopLog(stopID, name, lat, lon);

			//add the stop log to the stop vector
			this->stops.push_back(myNewStopLog);

		}
	} 
}

std::string EventHistory::removeGFIgarbageFromTime(std::string fixMe) {
	std::string output;

	//iterate through the input stirng until there's a space, then append the rest of the input string to the output
	char currentReadChar;
	bool foundSpace = false;
	for (int i = 0; i < fixMe.size(); i++) {
		currentReadChar = fixMe.at(i);
		if (foundSpace == true) {
			output.push_back(currentReadChar);
		}

		if (currentReadChar == ' ') {
			foundSpace = true;
		}
	}

	return output;

}

void EventHistory::readFromGFI(std::string FBfilePath, std::unordered_map<std::string, BusHistory*> busHistoryMap) {
	//go through the file and input all the lines
	std::ifstream fareboxFile;
	std::string lineFromFile;
	fareboxFile.open(FBfilePath);
	if (fareboxFile.is_open()) {
		//throw away the first 5 lines
		getline(fareboxFile, lineFromFile);
		getline(fareboxFile, lineFromFile);
		getline(fareboxFile, lineFromFile);
		getline(fareboxFile, lineFromFile);
		getline(fareboxFile, lineFromFile);

		//go throught the rest of the lines
		while(getline(fareboxFile, lineFromFile)) {

			char currentReadChar;
			int commaCount = 0;

			//placeholder strings to put the extracted data
			std::string fleetID;
			std::string rawTime;

			for (int i = 0; commaCount <= GFI_FLEET_ID + 1; i++) {
				currentReadChar = lineFromFile.at(i);
				if (currentReadChar == ',' && lineFromFile.at(i + 1) != ' ') {
					commaCount++;
				} else {
					if (commaCount == GFI_DATE_TIME) {
						rawTime.push_back(currentReadChar);
					} else if (commaCount == GFI_FLEET_ID) {
						fleetID.push_back(currentReadChar);
					}
				}
			}

			//if the fleet sid is only 3 chars long, prepend a 0 to it
			if (fleetID.size() == 3) {
				fleetID.insert(0, "0");
			}

			//convert the raw time to actual time the actual time to a time int
			std::string actualTime = removeGFIgarbageFromTime(rawTime);
			int timeInt = convertTimeStringToInt(actualTime);

			//std::cout << actualTime << ", " << fleetID << std::endl;
			//std::cout << timeInt << std::endl;

			//if the fleet id actually exists
			if (busHistoryMap.count(fleetID) > 0) {
				//look up the fleet ID in the bus history map, and then use the timeInt to find the closest StopTime obj
				std::unordered_map<std::string, BusHistory*>::iterator myIterator;

				myIterator = busHistoryMap.find(fleetID);

				StopTime* foundStopTime = myIterator->second->findStopTimeObj(timeInt);

				//get the stop ID for the found stop node
				std::string stopID = foundStopTime->getStopID();
				
				//go through the vector of stops and add this to the correct stopLog based on the stopID
				for (int i = 0; i < this->stops.size(); i++) {
					if (stopID.compare(this->stops.at(i)->getStopID()) == 0) {
						this->stops.at(i)->addStopEvent(foundStopTime);
					}
				}
			} else { //print an error
				std::cout << "Error: Fleet ID " << fleetID << " exists in GFI but not in Syncromatics\n";

			}
			
		}
	}

}

void EventHistory::printStops() {
	for (int i = 0; i < this->stops.size(); i++) {
		//std::cout << stops.at(i)->getStopID() << ", " << stops.at(i)->getName() << std::endl;
	}
}

void EventHistory::generateBoardingsPerStopCSV() {
	std::ofstream outputFile;
	outputFile.open("boardings_per_stop.csv");
	//output column headers to file
	outputFile << "lat, lon, stop_id, stop_name, usage\n";
	for (int i = 0; i < this->stops.size(); i++) {
		outputFile << this->stops.at(i)->getLat() << "," << 
					  this->stops.at(i)->getLon() << "," <<
					  this->stops.at(i)->getStopID() << "," <<
					  this->stops.at(i)->getName() << "," <<
					  this->stops.at(i)->getSize() << std::endl;
	}
	outputFile.close();

}

//output distribution of events for a specific stop
void EventHistory::generateEventDistribution(std::string stopID) {
	std::ofstream outputFile;
	std::string fileName = stopID;
	fileName.append("_distribution.csv");

	//look up the stop time in GTFS and choose the closest one

	outputFile.open(fileName);
	//lookup the correct StopLog
	for (int i = 0; i < this->stops.size(); i++) {
		if (stopID.compare(this->stops.at(i)->getStopID()) == 0) { //if it's the correct stop ID
			//get the correct vector
			std::vector<StopTime*> stopEventVector = this->stops.at(i)->getStopEvents();



			//go through each stop event and write the frequency of departure times (by route) to the file
			for (int j = 0; j < this->stops.at(i)->getSize(); j++) {
				outputFile << stopEventVector.at(j)->getRoutePatternName() << ",";
				outputFile << stopEventVector.at(j)->getDepartureTime() << std::endl;
			} 

		}
	}

	outputFile.close();

	//output column headers to file
	//outputFile << "time period, count\n";
	//time period X minutes long - increses by X minuteseach iteration
	//this x * 60 seconds to iterate every time

	//get the lower bound from the  time of the first event

	//get the upper bound form the time of the last event 

}