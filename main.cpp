#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //ifstream
#include <vector>
#include <algorithm>
void parseString(std::string &line, std::string &field);
/*struct Employee {
    string name;
    int empNum;
    int rate;
    int hours;
};*/
int main() {
    std::ifstream csvFile; //instantiated ifstream object
    //std::vector<Employee> info;
    int loc;
    std::string name;
    std::string empNum;
    std::string rate;
    std::string hours;
    double grossPay;

    csvFile.open("../EmployeeData.csv"); //connecting ifstream obj to file
    if (!csvFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }
//create vector and push back employee info into vector
    std::string line;
    std::getline(csvFile, line); //read header ignore
    std::cout << "--------------------------------------------------\n";
    while (std::getline(csvFile, line)) { //process csv file
        parseString(line,  name);
        parseString(line,  empNum);
        parseString(line,  rate);
        parseString(line,  hours);
        grossPay = stod(rate) * stod(hours);
        std::cout<< std::setw(15) << std::left<< name;
        std::cout<< std::setw(15) << empNum;
        std::cout<< std::setw(15) <<rate;
        std::cout<< std::setw(15) <<hours;
        std::cout << std::setw(15) << grossPay << std::endl;
    }
    csvFile.close(); //close file

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


    return 0;
}

void parseString(std::string &line, std::string &field){
    int loc;
    loc = line.find(',');
    field = line.substr(0,loc);
    line = line.substr(loc+1,line.length());

}
