#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

void get_flights_range(map<string, int> flights, int min, int max){
    // put func code here
}

int main(){
    srand(time(0));
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

    // Milestone 2
    int busiest_count = 0; 
    vector<pair<string, int>> airport_list; 
    // Milestone 1
    for (auto &pair : airport_traffic){
        cout << pair.first << " " << pair.second << endl;
        if (pair.second > busiest_count){
            busiest_count = pair.second; // Milestone 2
        }
    }
    cout << endl;

    // Milestone 2
    for (auto &pair : airport_traffic){
        if (pair.second == busiest_count){
            airport_list.push_back(pair);
        }
    }
    cout << "Busiest airport(s) with count " << busiest_count << ": " << endl;
    for (pair p : airport_list){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    for (int i = 0; i < 3; i++){
        airport_list.clear();
        int r_min = (rand() % (busiest_count-3)) + 1;
        int r_max = r_min + 5;
        for (auto &pair : airport_traffic){
            if (pair.second >= r_min && pair.second <= r_max){
                airport_list.push_back(pair);
            }
        }
        cout << "Airports with traffic in range [" << r_min << ", " << r_max << "]: " << endl;
        for (pair p : airport_list){
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
    }
    return 0;
}