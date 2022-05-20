#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

//column number of entries from the syncromatics stop time export (starting with 0)
#define VEHICLE_NAME 1
#define PATTERN_NAME 8
#define STOP_NAME 10
#define STOP_NUMBER 11
#define TRIP_NAME 14
#define ARRIVE 18
#define DEPART 21


class StopTime {
public:
	//constructor
	StopTime(std::string lineFromStopTimeExport);

	int getArrivalTimeInt();
	int getDepartureimeInt();
	std::string getFleetID();
private:
	//values
	std::string arrivalTime;
	std::string departureTime;
	int arrivalTimeInt;
	int departureTimeInt;
	std::string stopID;
	std::string stopName;
	std::string routePatternName;
	std::string tripID;
	std::string fleetID;

	//functions
	//remove syncromatics garbage from time
	std::string removeSyncromaticsGarbageFromTime(std::string fixme);
	//convert time string to int
	int convertTimeStringToInt(std::string convertMe);

};



class BusHistory {
public:
	//constructor
	BusHistory(std::string fleetID);
	//add a stop time to the vector (in order)
	void insertStopTime(StopTime* insertMe);
private:
	//fleet ID
	std::string fleetID;
	//stp times vector
	std::vector<StopTime*> stopTimesVector;
};


//read from the stop time export CSV and return a map of bus history classes (one entry for each bus)
//key: fleet id
//value: history for the fleet id
std::unordered_map<std::string, BusHistory*> getAVL(std::string filePath);