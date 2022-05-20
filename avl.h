#include <string>
#include <vector>
#include <iostream>
#include <fstream>


//read from the stop time export CSV and return an unordered map of bus history classes
//std::unordered_map<std::string, BusHistory*> getAVL(std::string filePath);

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

class StopTime() {
public:
	//constructor
	StopTime(std::string arrivalTime, std::string departureTime, std::string departureTime, std::string stopID, std::string routePatternName);

	std::string getArrivalTimeInt();
	std::string getDepartureimeInt();
private:
	//values
	std::string arrivalTime;
	std::string departureTime;
	int arrivalTimeInt;
	int departureTimeInt;
	std::string stopID;
	std::string routePatternName;

	//functions
	//remove syncromatics garbage from time
	std::string removeSyncromaticsGarbageFromTime(std::string fixme);
	//convert time string to int
	int convertTimeStringToInt(std::string convertMe);

};