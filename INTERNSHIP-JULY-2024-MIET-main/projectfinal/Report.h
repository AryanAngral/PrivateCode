#ifndef REPORT_H
#define REPORT_H

#include "User.h"
#include "Train.h"
#include "Ticket.h"
#include <vector>
#include <map>

class Report {
public:
    static void generateUserReport(const std::vector<User*>& users);
    static void generateTrainReport(const std::map<std::string, Train>& trains);
    static void generateTicketReport(const std::vector<Ticket>& tickets);
};

#endif // REPORT_H
