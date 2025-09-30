#include "Reports.h"
#include <iostream>
using namespace std;

Reports::Reports() { auxDonor.empty(); }

void Reports::loadDataBase(const std::vector<Donor>& auxdonor) {
    this->auxDonor = auxdonor;
}

int Reports::donorTotal() const { return auxDonor.size(); }

int Reports::donorTotal(const int& district, const int& age, const int& bloodType) const {
    int total = 0;
    for (const auto& d : auxDonor) {
        if (d.getDistrict() == district && d.getAge() == age && d.getBloodType() == bloodType)
            total++;
    }
    return total;
}

int Reports::donorTotal(const int& district, const int& bloodType) const {
    int total = 0;
    for (const auto& d : auxDonor) {
        if (d.getDistrict() == district && d.getBloodType() == bloodType)
            total++;
    }
    return total;
}

double Reports::donorMeanAge(const int& district) const {
    int total = 0, ages = 0;
    for (const auto& d : auxDonor) {
        if (d.getDistrict() == district) {
            ages += d.getAge();
            total++;
        }
    }
    return (total > 0) ? (double)ages / total : 0;
}

int Reports::donorAdult(const int& district, const int& bloodType) const {
    int total = 0;
    for (const auto& d : auxDonor) {
        if (d.getDistrict() == district && d.getAge() >= 18 && d.getBloodType() == bloodType)
            total++;
    }
    return total;
}

int Reports::bloodDonorUnits(const std::string& donorName) const {
    for (const auto& d : auxDonor) {
        if (d.getId() == donorId) {
            std::cout << "Donante: " << d.getName() << "\n";
            std::cout << "Unidades donadas: " << d.getUnits() << "\n";
            std::cout << "Fecha última donación: " << d.getDate() << "\n";
            return d.getUnits();
        }
    }
    std::cout << "❌ Donante no encontrado.\n";
    return 0;
}

void Reports::yearAndReport() const {
    std::cout << "📊 Reporte de donantes por Departamento y Tipo de Sangre:\n\n";
    for (int dep = 1; dep <= 10; dep++) {
        std::cout << "Departamento " << dep << ":\n";
        for (int bt = 1; bt <= 8; bt++) {
            int count = 0;
            for (const auto& d : auxDonor) {
                if (d.getDistrict() == dep && d.getBloodType() == bt) {
                    count++;
                }
            }
            if (count > 0) {
                std::cout << "   Tipo de sangre " << bt << ": " << count << " donantes\n";
            }
        }
        std::cout << std::endl;
    }
}
