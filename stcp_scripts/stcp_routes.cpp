#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream lines;
    ofstream answer;
    string str;
    
    lines.open(argv[1], fstream::in);

    while (getline(lines, str))
    {
        try
        {
            curlpp::Cleanup myCleanup;
            curlpp::Easy request;
            stringstream url;
            
            url << "https://www.stcp.pt/pt/itinerarium/callservice.php?action=linestops&lcode=" << str << "&ldir=" << argv[2];
            // cout << url.str() << endl;

            str = "stcp_lines_info/" + str + '_' + argv[2] + ".json";
            answer.open(str, fstream::out);
            // cout << str << endl << endl;

            request.setOpt(new curlpp::options::Url(url.str()));
            request.setOpt(new curlpp::options::UserAgent("PostmanRuntime/7.13.0"));

            list<string> header;
            header.push_back("Accept: */*");
            header.push_back("Cache-Control: no-cache");
            header.push_back("Postman-Token: 6fcb0713-5865-4b61-9422-5c9e3242d254,c1a82f0a-3942-4134-81b0-ed39d72eedcf");
            header.push_back("cookie: PHPSESSID=2dhnkd2v5g768gsmm7cdboo5h2");
            header.push_back("accept-encoding: gzip, deflate");
            header.push_back("referer: https://www.stcp.pt/itinerarium/callservice.php?action=linestops&lcode=200&ldir=0");
            header.push_back("Connection: keep-alive");
            header.push_back("cache-control: no-cache");

            request.setOpt(new curlpp::options::HttpHeader(header));

            answer << request;
            answer.close();
        }
        catch (curlpp::LogicError &e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (curlpp::RuntimeError &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    lines.close();

    return 0;
}