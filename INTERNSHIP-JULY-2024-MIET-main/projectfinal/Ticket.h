#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    int id;
    std::string trainId;
    std::string seat;
    std::string date;
    std::string username;

public:
    Ticket(int id, const std::string& trainId, const std::string& seat, const std::string& date, const std::string& username);

    int getId() const;
    std::string details() const;

    std::string serialize() const;
    static Ticket deserialize(const std::string& data);
};

#endif // TICKET_H
