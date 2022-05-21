#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

//time period to export stop distribution in (minutes);
#define STOP_DISTRIBUTION_TIME_PERIOD 15

//column number of entries from the syncromatics stop time export (starting with 0)
#define VEHICLE_NAME 1
#define PATTERN_NAME 8
#define STOP_NAME 10
#define STOP_NUMBER 11
#define TRIP_NAME 14
#define ARRIVE 18
#define DEPART 21

//column number of entries from GTFS feed
#define GTFS_STOP_CODE 1
#define GTFS_STOP_NAME 2
#define GTFS_STOP_LAT 4
#define GTFS_STOP_LON 5

//column number of entires from GFI farebox export
#define GFI_DATE_TIME 3
#define GFI_FLEET_ID 4


//convert time string to int
int convertTimeStringToInt(std::string convertMe);

class StopTime {
public:
	//constructor
	StopTime(std::string lineFromStopTimeExport);

	int getArrivalTimeInt();
	int getDepartureimeInt();
	std::string getFleetID();

	std::string getDepartureTime();
	std::string getStopID();
	std::string getRoutePatternName();
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

};



class BusHistory {
public:
	//constructor
	BusHistory(std::string fleetID);
	//add a stop time to the vector (in order)
	void insertStopTime(StopTime* insertMe);
	//return closest stop time obj, given a time int
	StopTime* findStopTimeObj(int eventTime);
	//print fleet id
	void printFleetID();
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


//stop obj where data is stored
class StopLog {
public:
	//constructor
	StopLog(std::string stopID, std::string name, std::string lat, std::string lon);

	std::string getStopID();
	std::string getLat();
	std::string getLon();
	std::string getName();
	int getSize();

	std::vector<StopTime*> getStopEvents();

	void addStopEvent(StopTime* addMe);
private:
	std::string stopID;
	std::string lat;
	std::string lon;
	std::string name;
	std::vector<StopTime*> stopEvents;
};

class EventHistory {
public:
	//constructor (create a stop log obj for every stop (read from GTFS), add to vector)
	EventHistory(std::string GTFSfilePath);
	/* given the unordred map of AVL history and the unordered map of bus stop logs, go through the GFI export
	and find the closest BusHistory.StopTime for that line item, then put it in the correct stop log
	*/
	void readFromGFI(std::string FBfilePath, std::unordered_map<std::string, BusHistory*> busHistoryMap);

	//print stops
	void printStops();

	//output total usage per stop CSV
	void generateBoardingsPerStopCSV();

	//output distribution of events for a specific stop
	void generateEventDistribution(std::string stopID);
private:
	std::string removeGFIgarbageFromTime(std::string fixMe);
	std::vector<StopLog*> stops;
};

