#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include <jsoncpp/json/json.h>

using namespace std;

void reverse_path(char *path, ofstream &output)
{
    ifstream input;
    Json::Value value1;
    Json::Reader reader1;
    string str(path);
    size_t pos = str.find('_');
    stringstream line;
    line << "stcp_lines_info/" << str.substr(0, pos) << '_' << (str[pos + 1] ? 0 : 1) << ".json";

    input.open(line.str());
    reader1.parse(input, value1);

    Json::Value &records = value1["records"];

    for (int i = records.size() - 1; i > 0; i--)
    {
        line.str("");
        line << '(' << records[i]["code"].asString() << ", " << records[i - 1]["code"].asString() << ')';

        output << '(' << records[i]["code"].asString() << ", " << records[i + 1]["code"].asString() << ')' << endl;
    }

    input.close();
}

int main()
{
    DIR *dir;
    struct dirent *ent;
    ifstream file;
    ofstream output;
    Json::Value value;
    Json::Reader reader;

    output.open("stcp_edge_codes.txt", fstream::trunc);
    dir = opendir("stcp_lines_info");

    while ((ent = readdir(dir)) != NULL)
    {
        stringstream stream;
        stream << "stcp_lines_info/" << ent->d_name;

        file.open(stream.str());

        reader.parse(file, value);

        Json::Value &records = value["records"];

        if (records.size() == 0)
            reverse_path(ent->d_name, output);
        else
        {
            for (int i = 0; i < records.size() - 1; i++)
            {
                stream.str("");
                stream << '(' << records[i]["code"].asString() << ", " << records[i + 1]["code"].asString() << ')';

                if (stream.str() == "(, )")
                    continue;
                output << '(' << records[i]["code"].asString() << ", " << records[i + 1]["code"].asString() << ')' << endl;
            }
        }

        file.close();
    }
    output.close();

    return 0;
}