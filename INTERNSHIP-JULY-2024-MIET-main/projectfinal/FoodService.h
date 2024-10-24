#ifndef FOODSERVICE_H
#define FOODSERVICE_H

#include <string>

class FoodService {
private:
    std::string name;
    double price;

public:
    FoodService(const std::string& name, double price);

    std::string details() const;

    std::string serialize() const;
    static FoodService deserialize(const std::string& data);
};

#endif // FOODSERVICE_H
