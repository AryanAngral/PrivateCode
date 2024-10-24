#include "FoodService.h"
#include <sstream>

FoodService::FoodService(const std::string& name, double price) : name(name), price(price) {}

std::string FoodService::details() const {
    return "Food Name: " + name + ", Price: " + std::to_string(price);
}

std::string FoodService::serialize() const {
    return name + "|" + std::to_string(price) + "\n";
}

FoodService FoodService::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string name;
    double price;
    std::getline(iss, name, '|');
    iss >> price;
    return FoodService(name, price);
}
