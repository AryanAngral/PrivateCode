#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password);
    virtual ~User() {}

    std::string viewProfile() const;
    bool changePassword(const std::string& oldPwd, const std::string& newPwd);

    virtual void bookTicket(const std::string& trainId, const std::string& seat, const std::string& date) = 0;
    virtual void cancelTicket(int ticketId) = 0;
    virtual void viewTickets() const = 0;
    virtual void orderFood(int ticketId, const std::string& food) = 0;

    virtual std::string serialize() const = 0;
    static User* deserialize(const std::string& data);
};

#endif // USER_H
