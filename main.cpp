#include "BloodDatabase.h"
#include "Donor.h"
#include "Reports.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int main() {
    std::string donorName;
    BloodDatabase database;
    Reports reporte;
    int d=3;
    int a=43;
    int b=3;
    int choice;

    while (true) {
        BloodDatabase::clearConsole();
        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Reportes\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            database.getDonorDetails();
            database.writeDataToFile();
            break;
        case 2:
            database.searchAndDisplay();
            break;
        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            std::getline(std::cin, donorName);
            database.deleteDonor(donorName);
            BloodDatabase::waitForKeyPress();
            break;
        case 4:
            reporte.loadDataBase(database.getDonors());
            std::cout << "Total registros: " << reporte.donorTotal() << endl;
            std::cout << "Ingrese nombre para ver unidades donadas: ";
            std::getline(std::cin, donorName);
            reporte.bloodDonorUnits(donorName);
            std::cout << "\nReporte por año/departamento:\n";
            reporte.yearAndReport();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Opción no válida.\n";
            BloodDatabase::waitForKeyPress();
            break;
        }
    }
}
