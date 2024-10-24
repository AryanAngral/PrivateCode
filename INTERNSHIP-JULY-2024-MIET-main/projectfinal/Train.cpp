#include "Train.h"
#include <sstream>

Train::Train(const std::string& id, const std::string& name, const std::string& departure, const std::string& arrival)
    : id(id), name(name), departure(departure), arrival(arrival) {}

std::string Train::getId() const {
    return id;
}

std::string Train::details() const {
    return "Train ID: " + id + ", Name: " + name + ", Departure: " + departure + ", Arrival: " + arrival;
}

std::string Train::serialize() const {
    return id + "|" + name + "|" + departure + "|" + arrival + "\n";
}

Train Train::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string id, name, departure, arrival;
    std::getline(iss, id, '|');
    std::getline(iss, name, '|');
    std::getline(iss, departure, '|');
    std::getline(iss, arrival);
    return Train(id, name, departure, arrival);
}
