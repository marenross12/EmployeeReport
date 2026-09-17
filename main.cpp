#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //ifstream

void parseString(std::string &line, std::string &field);
int main() {
    std::ifstream csvFile; //instantiated ifstream object
    csvFile.open("../EmployeeData.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }
    std::string line = "Bugs Bunny,65732,21.45,36.8";

    int loc;
    std::string name;
    std::string empNum;
    std::string rate;
    std::string hours;
    double grossPay;
   /* loc = line.find(',');
    name = line.substr(0,loc);
    line = line.substr(loc+1,line.length());

    loc = line.find(',');
    empNum = line.substr(0,loc);
    line = line.substr(loc+1,line.length());

    loc = line.find(',');
    rate = line.substr(0,loc);
    line = line.substr(loc+1,line.length());

    loc = line.find(',');
    hours = line.substr(0,loc);
    line = line.substr(loc+1,line.length());*/

     parseString(line,  name);
     parseString(line,  empNum);
     parseString(line,  rate);
     parseString(line,  hours);

    grossPay = stod(rate) * stod(hours);
    std::cout<< std::setw(15) << std::left<< name;
    std::cout<< std::setw(15) << empNum;
    std::cout<< std::setw(15) <<rate;
    std::cout<< std::setw(15) <<hours;
    std::cout << std::setw(15) << grossPay;
    std::cout<< std::endl;
    return 0;
}

void parseString(std::string &line, std::string &field){
    int loc;
    loc = line.find(',');
    field = line.substr(0,loc);
    line = line.substr(loc+1,line.length());
}
