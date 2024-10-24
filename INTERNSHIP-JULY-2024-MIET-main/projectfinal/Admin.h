#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Train.h"
#include "Ticket.h"
#include "FoodService.h"
#include <map>

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);

    void createUser(std::vector<User*>& usersList, const std::string& username, const std::string& password) const;
    void deleteUser(std::vector<User*>& usersList, const std::string& username) const;
    void viewAllUsers(const std::vector<User*>& usersList) const;

    void addFoodService(const std::string& name, double price) const;
    void viewAllTrains(const std::map<std::string, Train>& trains) const;
    void viewAllTickets(const std::vector<Ticket>& tickets) const;
    void viewAllFoodServices(const std::vector<FoodService>& foodServices) const;
    void viewSystemLogs() const;

    std::string serialize() const override;
    static Admin* deserialize(const std::string& data);
};

#endif // ADMIN_H
