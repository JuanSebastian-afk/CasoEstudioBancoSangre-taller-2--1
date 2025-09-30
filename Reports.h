#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class Reports {
private:
    std::vector<Donor> auxDonor;

public:
    Reports();
    void loadDataBase(const std::vector<Donor>& adonor);

    int donorTotal() const;
    int donorTotal(const int& district, const int& age, const int& bloodType) const;
    int donorTotal(const int& district, const int& bloodType) const;  
    double donorMeanAge(const int& district) const;
    int donorAdult(const int& district, const int& bloodType) const;

    // Nuevos métodos
    int bloodDonorUnits(const std::string& donorName) const;
    void yearAndReport() const;
};

#endif // REPORTS_H
