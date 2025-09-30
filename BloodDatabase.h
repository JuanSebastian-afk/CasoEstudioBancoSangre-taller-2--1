#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class BloodDatabase {
private:
    const std::string fileName = "data.txt";
    std::vector<Donor> donors;

    static void displayProvinces();
    static void displayBloodType();
public:
    static void clearConsole();
    static void waitForKeyPress();
    static int getValidatedInput(const std::string& prompt);

    void getDonorDetails();
    void writeDataToFile();
    void searchAndDisplay() const;
    void deleteDonor(const std::string& donorName);
    std::vector<Donor> getDonors();
};

#endif // BLOODDATABASE_H
