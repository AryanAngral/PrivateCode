#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <sstream>

using namespace std;

// Abstract base class for User
class User {
protected:
    string username;
    string password;

public:
    User(const string& username, const string& password)
        : username(username), password(password) {}

    virtual ~User() {}

    string viewProfile() const {
        return "Username: " + username;
    }

    bool changePassword(const string& oldPwd, const string& newPwd) {
        if (password == oldPwd) {
            password = newPwd;
            return true;
        }
        return false;
    }

    virtual void bookTicket(const string& trainId, const string& seat, const string& date) = 0;
    virtual void cancelTicket(int ticketId) = 0;
    virtual void viewTickets() const = 0;
    virtual void orderFood(int ticketId, const string& food) = 0;

    virtual string serialize() const = 0;
    static User* deserialize(const string& data);
};

// Admin class inheriting from User
class Admin : public User {
public:
    Admin(const string& username, const string& password)
        : User(username, password) {}

    void createUser(vector<User*>& usersList, const string& username, const string& password) const {
        usersList.push_back(new User(username, password));
    }

    void deleteUser(vector<User*>& usersList, const string& username) const {
        auto it = remove_if(usersList.begin(), usersList.end(),
            [&username](User* user) { return user->viewProfile() == "Username: " + username; });
        if (it != usersList.end()) {
            delete *it;
            usersList.erase(it);
        }
    }

    void viewAllUsers(const vector<User*>& usersList) const {
        for (const auto& user : usersList) {
            cout << user->viewProfile() << endl;
        }
    }

    void addFoodService(const string& name, double price) const {
        // Implementation to add food service
    }

    void viewAllTrains(const map<string, Train>& trains) const {
        for (const auto& pair : trains) {
            cout << pair.second.details() << endl;
        }
    }

    void viewAllTickets(const vector<Ticket>& tickets) const {
        for (const auto& ticket : tickets) {
            cout << ticket.details() << endl;
        }
    }

    void viewAllFoodServices(const vector<FoodService>& foodServices) const {
        for (const auto& foodService : foodServices) {
            cout << foodService.details() << endl;
        }
    }

    void viewSystemLogs() const {
        ifstream logFile("system.log");
        string line;
        while (getline(logFile, line)) {
            cout << line << endl;
        }
    }

    string serialize() const override {
        return "Admin|" + username + "|" + password + "\n";
    }

    static Admin* deserialize(const string& data) {
        istringstream iss(data);
        string type, user, pass;
        getline(iss, type, '|');
        getline(iss, user, '|');
        getline(iss, pass);
        return new Admin(user, pass);
    }
};

// Train class
class Train {
private:
    string id;
    string name;
    string departure;
    string arrival;

public:
    Train(const string& id, const string& name, const string& departure, const string& arrival)
        : id(id), name(name), departure(departure), arrival(arrival) {}

    string getId() const {
        return id;
    }

    string details() const {
        return "Train ID: " + id + ", Name: " + name + ", Departure: " + departure + ", Arrival: " + arrival;
    }

    string serialize() const {
        return id + "|" + name + "|" + departure + "|" + arrival + "\n";
    }

    static Train deserialize(const string& data) {
        istringstream iss(data);
        string id, name, departure, arrival;
        getline(iss, id, '|');
        getline(iss, name, '|');
        getline(iss, departure, '|');
        getline(iss, arrival);
        return Train(id, name, departure, arrival);
    }
};

// Ticket class
class Ticket {
private:
    int id;
    string trainId;
    string seat;
    string date;
    string username;

public:
    Ticket(int id, const string& trainId, const string& seat, const string& date, const string& username)
        : id(id), trainId(trainId), seat(seat), date(date), username(username) {}

    int getId() const {
        return id;
    }

    string details() const {
        return "Ticket ID: " + to_string(id) + ", Train ID: " + trainId + ", Seat: " + seat + ", Date: " + date + ", Username: " + username;
    }

    string serialize() const {
        return to_string(id) + "|" + trainId + "|" + seat + "|" + date + "|" + username + "\n";
    }

    static Ticket deserialize(const string& data) {
        istringstream iss(data);
        int id;
        string trainId, seat, date, username;
        char delimiter;
        iss >> id >> delimiter;
        getline(iss, trainId, '|');
        getline(iss, seat, '|');
        getline(iss, date, '|');
        getline(iss, username);
        return Ticket(id, trainId, seat, date, username);
    }
};

// FoodService class
class FoodService {
private:
    string name;
    double price;

public:
    FoodService(const string& name, double price) : name(name), price(price) {}

    string details() const {
        return "Food Name: " + name + ", Price: " + to_string(price);
    }

    string serialize() const {
        return name + "|" + to_string(price) + "\n";
    }

    static FoodService deserialize(const string& data) {
        istringstream iss(data);
        string name;
        double price;
        getline(iss, name, '|');
        iss >> price;
        return FoodService(name, price);
    }
};

// Report class for generating reports
class Report {
public:
    static void generateUserReport(const vector<User*>& users) {
        ofstream reportFile("user_report.txt");
        reportFile << "User Report\n";
        for (const auto& user : users) {
            reportFile << user->viewProfile() << endl;
        }
    }

    static void generateTrainReport(const map<string, Train>& trains) {
        ofstream reportFile("train_report.txt");
        reportFile << "Train Report\n";
        for (const auto& pair : trains) {
            reportFile << pair.second.details() << endl;
        }
    }

    static void generateTicketReport(const vector<Ticket>& tickets) {
        ofstream reportFile("ticket_report.txt");
        reportFile << "Ticket Report\n";
        for (const auto& ticket : tickets) {
            reportFile << ticket.details() << endl;
        }
    }
};

// SystemLog class for logging system activities
class SystemLog {
public:
    static void log(const string& message) {
        ofstream logFile("system.log", ios_base::app);
        time_t now = time(0);
        tm* localtm = localtime(&now);
        logFile << asctime(localtm) << ": " << message << endl;
    }
};

// Main class for Railway Management System
class RailwayManagementSystem {
private:
    map<string, Train> trains;
    vector<User*> usersList;
    vector<Ticket> tickets;
    vector<FoodService> foodServices;

    void clearScreen() const {
        system("cls"); // For Windows, use "clear" for Unix-based systems
    }

    void pressEnterToContinue() const {
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void loadTrains() {
        ifstream file("trains.txt");
        string line;
        while (getline(file, line)) {
            Train train = Train::deserialize(line);
            trains[train.getId()] = train;
        }
    }

    void saveTrains() const {
        ofstream file("trains.txt");
        for (const auto& pair : trains) {
            file << pair.second.serialize();
        }
    }

    void loadUsers() {
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            User* user = User::deserialize(line);
            if (dynamic_cast<Admin*>(user)) {
                usersList.push_back(dynamic_cast<Admin*>(user));
            } else {
                usersList.push_back(user);
            }
        }
    }

    void saveUsers() const {
        ofstream file("users.txt");
        for (const auto& user : usersList) {
            file << user->serialize();
        }
    }

    void loadTickets() {
        ifstream file("tickets.txt");
        string line;
        while (getline(file, line)) {
            tickets.push_back(Ticket::deserialize(line));
        }
    }

    void saveTickets() const {
        ofstream file("tickets.txt");
        for (const auto& ticket : tickets) {
            file << ticket.serialize();
        }
    }

    void loadFoodServices() {
        ifstream file("food_services.txt");
        string line;
        while (getline(file, line)) {
            foodServices.push_back(FoodService::deserialize(line));
        }
    }

    void saveFoodServices() const {
        ofstream file("food_services.txt");
        for (const auto& foodService : foodServices) {
            file << foodService.serialize();
        }
    }

public:
    RailwayManagementSystem() {
        loadTrains();
        loadUsers();
        loadTickets();
        loadFoodServices();
        // Initialize default admin
        if (usersList.empty()) {
            usersList.push_back(new Admin("aryan", "1234"));
        }
    }

    ~RailwayManagementSystem() {
        saveTrains();
        saveUsers();
        saveTickets();
        saveFoodServices();
        for (auto user : usersList) {
            delete user;
        }
    }

    void mainMenu() {
        while (true) {
            clearScreen();
            cout << "==============================\n";
            cout << "     Railway Management System\n";
            cout << "==============================\n";
            cout << "1. User Login\n";
            cout << "2. Admin Login\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        userLogin();
                        break;
                    case 2:
                        adminLogin();
                        break;
                    case 3:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                SystemLog::log("Error: " + string(e.what()));
            }
        }
    }

    void userLogin() {
        clearScreen();
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (auto user : usersList) {
            if (user->viewProfile() == "Username: " + username && user->changePassword(password, password)) {
                cout << "User login successful!" << endl;
                userMenu(user);
                return;
            }
        }
        throw runtime_error("Invalid username or password.");
    }

    void userMenu(User* user) {
        while (true) {
            clearScreen();
            cout << "==============================\n";
            cout << "        User Menu             \n";
            cout << "==============================\n";
            cout << "1. Book Ticket\n";
            cout << "2. Cancel Ticket\n";
            cout << "3. View Tickets\n";
            cout << "4. Order Food\n";
            cout << "5. Logout\n";
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        bookTicket(user);
                        break;
                    case 2:
                        cancelTicket(user);
                        break;
                    case 3:
                        user->viewTickets();
                        pressEnterToContinue();
                        break;
                    case 4:
                        orderFood(user);
                        break;
                    case 5:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                SystemLog::log("Error: " + string(e.what()));
            }
        }
    }

    void adminLogin() {
        clearScreen();
        string username, password;
        cout << "Enter admin username: ";
        cin >> username;
        cout << "Enter admin password: ";
        cin >> password;

        for (auto user : usersList) {
            if (auto admin = dynamic_cast<Admin*>(user)) {
                if (admin->viewProfile() == username && admin->changePassword(password, password)) {
                    cout << "Admin login successful!" << endl;
                    SystemLog::log("Admin logged in: " + username);
                    adminMenu(admin);
                    return;
                }
            }
        }
        throw runtime_error("Invalid admin username or password.");
    }

    void adminMenu(Admin* admin) {
        while (true) {
            clearScreen();
            cout << "==============================\n";
            cout << "        Admin Menu            \n";
            cout << "==============================\n";
            cout << "1. Create User\n";
            cout << "2. Delete User\n";
            cout << "3. View All Users\n";
            cout << "4. Add Food Service\n";
            cout << "5. Generate Reports\n";
            cout << "6. View System Logs\n";
            cout << "7. View All Trains\n";
            cout << "8. View All Tickets\n";
            cout << "9. View All Food Services\n";
            cout << "10. Logout\n";
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        createUser(admin);
                        break;
                    case 2:
                        deleteUser(admin);
                        break;
                    case 3:
                        admin->viewAllUsers(usersList);
                        pressEnterToContinue();
                        break;
                    case 4:
                        addFoodService(admin);
                        break;
                    case 5:
                        generateReports(admin);
                        break;
                    case 6:
                        admin->viewSystemLogs();
                        pressEnterToContinue();
                        break;
                    case 7:
                        admin->viewAllTrains(trains);
                        pressEnterToContinue();
                        break;
                    case 8:
                        admin->viewAllTickets(tickets);
                        pressEnterToContinue();
                        break;
                    case 9:
                        admin->viewAllFoodServices(foodServices);
                        pressEnterToContinue();
                        break;
                    case 10:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                SystemLog::log("Error: " + string(e.what()));
            }
        }
    }

    void createUser(Admin* admin) {
        clearScreen();
        string username, password;
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> password;

        admin->createUser(usersList, username, password);
        cout << "User created successfully." << endl;
        SystemLog::log("User created by admin: " + admin->viewProfile());
        pressEnterToContinue();
    }

    void deleteUser(Admin* admin) {
        clearScreen();
        string username;
        cout << "Enter username to delete: ";
        cin >> username;

        admin->deleteUser(usersList, username);
        cout << "User deleted successfully." << endl;
        SystemLog::log("User deleted by admin: " + admin->viewProfile());
        pressEnterToContinue();
    }

    void addFoodService(Admin* admin) {
        clearScreen();
        string name;
        double price;
        cout << "Enter food name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter price: ";
        cin >> price;

        admin->addFoodService(name, price);
        foodServices.push_back(FoodService(name, price));
        cout << "Food service added successfully." << endl;
        SystemLog::log("Food service added by admin: " + admin->viewProfile());
        pressEnterToContinue();
    }

    void generateReports(Admin* admin) {
        clearScreen();
        Report::generateUserReport(usersList);
        Report::generateTrainReport(trains);
        Report::generateTicketReport(tickets);
        cout << "Reports generated successfully." << endl;
        SystemLog::log("Reports generated by admin: " + admin->viewProfile());
        pressEnterToContinue();
    }

    void bookTicket(User* user) {
        // Implementation for booking ticket
    }

    void cancelTicket(User* user) {
        // Implementation for canceling ticket
    }

    void orderFood(User* user) {
        // Implementation for ordering food
    }
};

int main() {
    try {
        RailwayManagementSystem system;
        system.mainMenu();
    } catch (const exception& e) {
        cerr << "Critical Error: " << e.what() << endl;
        SystemLog::log("Critical Error: " + string(e.what()));
        return 1;
    }
    return 0;
}
