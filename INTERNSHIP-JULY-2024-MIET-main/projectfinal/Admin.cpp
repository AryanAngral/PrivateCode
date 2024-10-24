#include "Admin.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password) {}

void Admin::createUser(std::vector<User*>& usersList, const std::string& username, const std::string& password) const {
    usersList.push_back(new User(username, password));  // Need specific User type
}

void Admin::deleteUser(std::vector<User*>& usersList, const std::string& username) const {
    auto it = std::remove_if(usersList.begin(), usersList.end(),
        [&username](User* user) { return user->viewProfile() == "Username: " + username; });
    if (it != usersList.end()) {
        delete *it;
        usersList.erase(it);
    }
}

void Admin::viewAllUsers(const std::vector<User*>& usersList) const {
    for (const auto& user : usersList) {
        std::cout << user->viewProfile() << std::endl;
    }
}

void Admin::addFoodService(const std::string& name, double price) const {
    // Implementation to add food service
}

void Admin::viewAllTrains(const std::map<std::string, Train>& trains) const {
    for (const auto& pair : trains) {
        std::cout << pair.second.details() << std::endl;
    }
}

void Admin::viewAllTickets(const std::vector<Ticket>& tickets) const {
    for (const auto& ticket : tickets) {
        std::cout << ticket.details() << std::endl;
    }
}

void Admin::viewAllFoodServices(const std::vector<FoodService>& foodServices) const {
    for (const auto& foodService : foodServices) {
        std::cout << foodService.details() << std::endl;
    }
}

void Admin::viewSystemLogs() const {
    std::ifstream logFile("system.log");
    std::string line;
    while (std::getline(logFile, line)) {
        std::cout << line << std::endl;
    }
}

std::string Admin::serialize() const {
    return "Admin|" + username + "|" + password + "\n";
}

Admin* Admin::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string type, user, pass;
    std::getline(iss, type, '|');
    std::getline(iss, user, '|');
    std::getline(iss, pass);
    return new Admin(user, pass);
}
