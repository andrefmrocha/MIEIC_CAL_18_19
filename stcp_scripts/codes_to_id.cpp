#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <iterator>

#define STOP_ID    "stcp_routes_Porto.txt"
#define STOP_CODES "stcp_edge_codes.txt"
#define BUS_EDGES  "stcp_edge_ids_1.txt"

using namespace std;

int main(void) {

    ifstream infile(STOP_ID);

    map<string, int> stops;

    string line;
    getline(infile, line);

    string delimiter = ", ";
    while (getline(infile, line)) {
        line = line.substr(1, line.length() - 2);

        size_t pos = line.find(delimiter);
        int vertexID = stoi(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        string stopCode = line.substr(1, pos - 2);

        cout << stopCode << ", " << vertexID << endl;
        stops[stopCode] = vertexID;
    }

    infile.close();

    infile.open(STOP_CODES);
    ofstream outfile(BUS_EDGES, fstream::trunc);

    set<string> edges;

    while (getline(infile, line)) {
        line = line.substr(1, line.length() - 2);

        size_t pos = line.find(delimiter);
        string srcStop = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        string destStop = line;

        if (stops[srcStop] == stops[destStop] || stops[srcStop] == 0 || stops[destStop] == 0)
            continue;

        string output = "(" + to_string(stops[srcStop]) + ", " + to_string(stops[destStop]) + ")";
        edges.insert(output);
    }

    for (set<string>::iterator it = edges.begin(); it != edges.end(); it++) {
        outfile << *it << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}