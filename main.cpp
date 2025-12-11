#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    map<string, int> airport_traffic;
    fstream flight_data;
    // Milestone 1
    flight_data.open("210-final-1-FA25.txt");
    if (!flight_data.good()){
        cout << "Unable to open file" << endl;
    }
    else{
    string airport;
        while(!flight_data.eof()){
            flight_data >> airport;
            bool counter_up = false;
            if (!airport_traffic.empty()){
                for (auto &pair : airport_traffic){
                    if (pair.first == airport){
                        pair.second++;
                        //int* num_flights = &pair.second;
                        //*num_flights++;
                        counter_up = true;
                    }
                }
                if (!counter_up){
                    airport_traffic.insert(make_pair(airport, 1));
                }
            }
            else{
                airport_traffic.insert(make_pair(airport, 1));
            }
        }
    }

    int busiest_count = 0;
    vector<string> busiest_airports;
    // Milestone 1
    for (auto &pair : airport_traffic){
        cout << pair.first << " " << pair.second << endl;
        if (pair.second > busiest_count){
            busiest_count = pair.second;
        }
    }
    for (auto &pair : airport_traffic){
        // add all airports with busiest count to vector
    }
    return 0;
}