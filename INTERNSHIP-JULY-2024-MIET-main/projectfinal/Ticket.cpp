#include "Ticket.h"
#include <sstream>

Ticket::Ticket(int id, const std::string& trainId, const std::string& seat, const std::string& date, const std::string& username)
    : id(id), trainId(trainId), seat(seat), date(date), username(username) {}

int Ticket::getId() const {
    return id;
}

std::string Ticket::details() const {
    return "Ticket ID: " + std::to_string(id) + ", Train ID: " + trainId + ", Seat: " + seat + ", Date: " + date + ", Username: " + username;
}

std::string Ticket::serialize() const {
    return std::to_string(id) + "|" + trainId + "|" + seat + "|" + date + "|" + username + "\n";
}

Ticket Ticket::deserialize(const std::string& data) {
    std::istringstream iss(data);
    int id;
    std::string trainId, seat, date, username;
    char delimiter;
    iss >> id >> delimiter;
    std::getline(iss, trainId, '|');
    std::getline(iss, seat, '|');
    std::getline(iss, date, '|');
    std::getline(iss, username);
    return Ticket(id, trainId, seat, date, username);
}
