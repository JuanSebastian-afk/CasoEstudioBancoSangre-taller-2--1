#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
private:
    int donorId, district, bloodType, age;
    std::string name, address;
    long long number;   // teléfono validado (10 dígitos)
    int units;          // unidades de sangre donadas
    std::string date;   // fecha de última donación

    static std::string trim(const std::string& str);

public:
    Donor() = default;

    // Getters
    int getDonorId() const;
    std::string getName() const;
    int getAge() const;
    std::string getAddress() const;
    int getDistrict() const;
    int getBloodType() const;
    long long getNumber() const;
    int getUnits() const;
    std::string getDate() const;

    // Setters
    void setDonorId(int id);
    void setName(const std::string& n);
    void setAge(int a);
    void setAddress(const std::string& addr);
    void setDistrict(int d);
    void setBloodType(int bt);
    void setNumber(long long num);
    void setUnits(int u);
    void setDate(const std::string& d);

    // Métodos
    void donorDetails() const;
    static Donor parseLine(const std::string& line);
};

#endif // DONOR_H
