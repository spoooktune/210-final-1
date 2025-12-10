#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main(){
    map<string, int> airport_traffic;
    fstream flight_data;
    flight_data.open("210-final-1-FA25.txt");
    if (!flight_data.good()){
        cout << "Unable to open file" << endl;
    }
    else{
    while(!flight_data.eof())
        string airport;
        flight_data >> airport;
        if (airport_traffic.empty()){
            // add new airport
        }
    }
    return 0;
}