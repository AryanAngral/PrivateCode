#include "Report.h"
#include <fstream>

void Report::generateUserReport(const std::vector<User*>& users) {
    std::ofstream reportFile("user_report.txt");
    reportFile << "User Report\n";
    for (const auto& user : users) {
        reportFile << user->viewProfile() << std::endl;
    }
}

void Report::generateTrainReport(const std::map<std::string, Train>& trains) {
    std::ofstream reportFile("train_report.txt");
    reportFile << "Train Report\n";
    for (const auto& pair : trains) {
        reportFile << pair.second.details() << std::endl;
    }
}

void Report::generateTicketReport(const std::vector<Ticket>& tickets) {
    std::ofstream reportFile("ticket_report.txt");
    reportFile << "Ticket Report\n";
    for (const auto& ticket : tickets) {
        reportFile << ticket.details() << std::endl;
    }
}
