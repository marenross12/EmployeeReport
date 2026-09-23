#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //ifstream
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
struct Employee {
    std::string e_name;
    int e_empNum;
    double e_rate;
    double e_hours;
    double e_grossPay;
};
void parseString(std::string &line, std::string &field);
std::vector<Employee> readCSVFile(const std::string &filename);
void printTable(std::vector<Employee> &employees);
void randomOrder(std::vector<Employee> &employees);
int main() {
    std::vector<Employee> info = readCSVFile("../EmployeeData.csv");
    printTable(info);
    std::cout << "\n" <<std::endl;
    randomOrder(info);
    printTable(info);
    std::cout << "\n" <<std::endl;

    std::sort(info.begin(), info.end(), [](const Employee& a, const Employee& b){return a.e_grossPay > b.e_grossPay;});
    printTable(info);
    /*int loc;
    std::string name;
    std::string empNum;
    std::string rate;
    std::string hours;
    double grossPay;*/




    /*std::string line;
    std::getline(csvFile, line); //read header ignore
    std::cout << "--------------------------------------------------\n";
    while (std::getline(csvFile, line)) { //process csv file
        parseString(line,  name);
        parseString(line,  empNum);
        parseString(line,  rate);
        parseString(line,  hours);
        grossPay = stod(rate) * stod(hours);
        std::cout<< std::setw(15) << std::left<< name;
        std::cout<< std::setw(10) << std::right<< empNum;
        std::cout<< std::setw(10) <<std::right<<std::fixed<<std::setprecision(2)<<stod(rate);
        std::cout<< std::setw(10) <<std::right<<std::fixed<<std::setprecision(2)<<stod(hours);
        std::cout << std::setw(12) << std::right<<grossPay << std::endl;
    }
    csvFile.close(); //close file*/

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

std::vector<Employee> readCSVFile(const std::string &filename) {
    std::vector<Employee> employees;
    std::ifstream csvFile;
    csvFile.open(filename);
    if (!csvFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return employees;
    }
    std::string line;
    std::getline(csvFile, line); //read header ignore

    while (std::getline(csvFile, line)) {
        std::string name, empNum, rate, hours;
        parseString(line,  name);
        parseString(line,  empNum);

        parseString(line,  rate);

        parseString(line,  hours);
        Employee temp;
        temp.e_name = name;
        temp.e_empNum = std::stoi(empNum);
        temp.e_rate = std::stod(rate);
        temp.e_hours = std::stod(hours);
        temp.e_grossPay = temp.e_rate*temp.e_hours;
        employees.push_back(temp);
    }
    csvFile.close();
    return employees;
}
void printTable(std::vector<Employee> &employees) {
    std::cout << std::left << std::setw(13) << "NAME"
              << std::right << std::setw(13) << "EMPNUM"
              <<std::right << std::setw(15) << "HOURLY RATE"
              << std::right << std::setw(15)<< "HOURS WORKED"
              << std::right << std::setw(15)<< "GROSS PAY" << std::endl;
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << std::fixed<< std::setprecision(2);
    for (const Employee& temp : employees) {
        std::cout << std::left << std::setw(15) << temp.e_name
        << std::right << std::setw(10) << temp.e_empNum
        << std::right << std::setw(10) << "$" << temp.e_rate
        << std::right << std::setw(15)<< temp.e_hours
        << std::right << std::setw(8)<< "$" << temp.e_grossPay <<  std::endl;

    }


}
void randomOrder(std::vector<Employee> &employees) {
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator(seed);
    std::shuffle(employees.begin(), employees.end(), generator);
}