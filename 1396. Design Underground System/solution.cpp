#include <unordered_map>
#include <string>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> passengers;
    unordered_map<string, unordered_map<string, pair<double, double>>> averageTime;
    
    UndergroundSystem() {
        unordered_map<int, pair<string, int>> *passengers = new unordered_map<int, pair<string, int>>;
        unordered_map<string, unordered_map<string, pair<double, double>>> *averageTime = new unordered_map<string, unordered_map<string, pair<double, double>>>;
    }
    
    void checkIn(int id, string stationName, int t) {
        passengers[id].first = stationName;
        passengers[id].second = t;
        averageTime[stationName];
    }
    
    void checkOut(int id, string stationName, int t) {
        for (auto& i: averageTime){
            
            if (i.first == passengers[id].first) {

                if (i.second.find(stationName) == i.second.end()){
                    
                    auto tmp = make_pair(t - passengers[id].second, 1);
                    
                    i.second.insert(make_pair(stationName, tmp));

                } else {
                    ++i.second[stationName].second;
                    i.second[stationName].first = (i.second[stationName].first*(i.second[stationName].second - 1) + t - passengers[id].second) / i.second[stationName].second;
                };

            }
        
        }
        
        
        passengers.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        for (auto& i: averageTime){
            if (i.first == startStation){

                if (i.second.find(endStation) != i.second.end()){
                    return i.second[endStation].first;
                }
                
            }
        }
        return 0;
    }
    
    ~UndergroundSystem(){
        passengers.clear();
        averageTime.clear();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */