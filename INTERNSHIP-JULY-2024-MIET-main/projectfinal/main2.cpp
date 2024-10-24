#include <cstdlib>  // for system()
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <unordered_map>

using namespace std;

class Train {
public:
    string train_id;
    string name;
    int capacity;
    string origin;
    string destination;

    Train() : train_id(""), name(""), capacity(0), origin(""), destination("") {}

    Train(string id, string n, int cap, string ori, string dest)
        : train_id(id), name(n), capacity(cap), origin(ori), destination(dest) {}

    string details() const {
        return "Train ID: " + train_id + ", Name: " + name + ", Capacity: " + to_string(capacity) +
               ", Origin: " + origin + ", Destination: " + destination;
    }
};

class Ticket {
public:
    static int ticket_counter;
    int ticket_id;
    string username;
    Train train;
    string seat_number;
    string date;

    Ticket(string user, Train t, string seat, string d)
        : username(user), train(t), seat_number(seat), date(d) {
        ticket_id = ++ticket_counter;
    }

    string details() const {
        return "Ticket ID: " + to_string(ticket_id) + ", User: " + username + ", Train: " + train.name +
               ", Seat: " + seat_number + ", Date: " + date;
    }
};

int Ticket::ticket_counter = 0;

class User {
protected:
    string username;
    string password;
    string role;
    vector<Ticket> tickets;

public:
    User(string uname, string pwd) : username(uname), password(pwd), role("user") {}
    virtual ~User() {}

    virtual bool login(string uname, string pwd) const {
        return (username == uname && password == pwd);
    }

    virtual string viewProfile() const {
        return "Username: " + username + ", Role: " + role;
    }

    bool changePassword(string oldPwd, string newPwd) {
        if (password == oldPwd) {
            password = newPwd;
            return true;
        }
        return false;
    }

    void bookTicket(const Train& train, const string& seat, const string& date) {
        Ticket ticket(username, train, seat, date);
        tickets.push_back(ticket);
        cout << "Ticket booked successfully: " << ticket.details() << endl;
    }

    void cancelTicket(int ticket_id) {
        auto it = tickets.begin();
        for (; it != tickets.end(); ++it) {
            if (it->ticket_id == ticket_id) {
                tickets.erase(it);
                cout << "Ticket cancelled successfully." << endl;
                return;
            }
        }
        throw runtime_error("Ticket ID not found.");
    }

    void viewTickets() const {
        for (const auto& ticket : tickets) {
            cout << ticket.details() << endl;
        }
    }

    string checkSeatNumber(int ticket_id) const {
        for (const auto& ticket : tickets) {
            if (ticket.ticket_id == ticket_id) {
                return ticket.seat_number;
            }
        }
        throw runtime_error("Ticket ID not found.");
    }

    string checkTrainNumber(int ticket_id) const {
        for (const auto& ticket : tickets) {
            if (ticket.ticket_id == ticket_id) {
                return ticket.train.train_id;
            }
        }
        throw runtime_error("Ticket ID not found.");
    }

    void orderFood(int ticket_id, const string& food) {
        for (const auto& ticket : tickets) {
            if (ticket.ticket_id == ticket_id) {
                cout << "Food order placed for " << food << " on ticket ID " << ticket_id << endl;
                return;
            }
        }
        throw runtime_error("Ticket ID not found.");
    }

    void viewTrainDetails(int ticket_id) const {
        for (const auto& ticket : tickets) {
            if (ticket.ticket_id == ticket_id) {
                cout << ticket.train.details() << endl;
                return;
            }
        }
        throw runtime_error("Ticket ID not found.");
    }
};

class Admin : public User {
public:
    Admin(string uname, string pwd) : User(uname, pwd) {
        role = "admin";
    }

    void createUser(vector<User*>& usersList, const string& newUsername, const string& newPassword) {
        for (const auto& user : usersList) {
            if (user->login(newUsername, "")) {
                throw runtime_error("Username already exists.");
            }
        }
        usersList.push_back(new User(newUsername, newPassword));
    }

    void deleteUser(vector<User*>& usersList, const string& username) {
        auto it = usersList.begin();
        for (; it != usersList.end(); ++it) {
            if ((*it)->login(username, "")) {
                delete *it;
                usersList.erase(it);
                return;
            }
        }
        throw runtime_error("Username not found.");
    }

    void viewAllUsers(const vector<User*>& usersList) const {
        for (const auto& user : usersList) {
            cout << user->viewProfile() << endl;
        }
    }

    void manageTrains(unordered_map<string, Train>& trains, const Train& train, bool add) {
        if (add) {
            if (trains.find(train.train_id) == trains.end()) {
                trains[train.train_id] = train;
                cout << "Train added successfully." << endl;
            } else {
                throw runtime_error("Train ID already exists.");
            }
        } else {
            if (trains.erase(train.train_id)) {
                cout << "Train removed successfully." << endl;
            } else {
                throw runtime_error("Train ID not found.");
            }
        }
    }

    void viewAllTrains(const unordered_map<string, Train>& trains) const {
        for (const auto& entry : trains) {
            cout << entry.second.details() << endl;
        }
    }

    void addFoodService(int ticket_id, const string& food) {
        cout << "Food service added to ticket ID " << ticket_id << " for " << food << endl;
    }

    void viewSystemLogs() const {
        cout << "Viewing system logs..." << endl;
    }

    void generateReports() const {
        cout << "Generating reports..." << endl;
    }
};

class RailwayManagementSystem {
private:
    vector<User*> usersList;
    unordered_map<string, Train> trains;

    void createAdmin() {
        usersList.push_back(new Admin("aryan", "1234"));
    }

    void log(const string& message) const {
        ofstream logFile("system.log", ios::app);
        logFile << message << endl;
    }

    void clearScreen() const {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

public:
    RailwayManagementSystem() {
        createAdmin();
    }

    ~RailwayManagementSystem() {
        for (auto user : usersList) {
            delete user;
        }
    }

    void mainMenu() {
        while (true) {
            clearScreen();
            cout << "Main Menu:\n1. Create User\n2. Login (User)\n3. Login (Admin)\n4. Exit\nEnter choice: ";
            int choice;
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        createUser();
                        break;
                    case 2:
                        userLogin();
                        break;
                    case 3:
                        adminLogin();
                        break;
                    case 4:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                log("Error: " + string(e.what()));
            }
        }
    }

    void createUser() {
        clearScreen();
        string username, password;
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> password;

        for (const auto& user : usersList) {
            if (user->login(username, "")) {
                throw runtime_error("Username already exists.");
            }
        }

        usersList.push_back(new User(username, password));
        cout << "User created successfully." << endl;
        log("User created: " + username);
        pressEnterToContinue();
    }

    void userLogin() {
        clearScreen();
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (auto user : usersList) {
            if (user->login(username, password)) {
                cout << "Login successful!" << endl;
                log("User logged in: " + username);
                userMenu(user);
                return;
            }
        }
        throw runtime_error("Invalid username or password.");
    }

        
void userMenu(User* user) {
    while (true) {
        clearScreen();
        cout << "User Menu:\n1. View Profile\n2. Change Password\n3. Book Ticket\n4. Cancel Ticket\n5. View Tickets\n6. Check Seat Number\n7. Check Train Number\n8. Order Food\n9. View Train Details\n10. Logout\nEnter choice: ";
        int choice;
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << user->viewProfile() << endl;
                    break;
                case 2:
                    {
                        string oldPwd, newPwd;
                        cout << "Enter old password: ";
                        cin >> oldPwd;
                        cout << "Enter new password: ";
                        cin >> newPwd;
                        if (user->changePassword(oldPwd, newPwd)) {
                            cout << "Password changed successfully." << endl;
                        } else {
                            cout << "Old password is incorrect." << endl;
                        }
                    }
                    break;
                case 3:
                    {
                        // Show available trains
                        clearScreen();
                        cout << "Available Trains:\n";
                        if (trains.empty()) {
                            cout << "No trains available." << endl;
                        } else {
                            for (const auto& pair : trains) {
                                cout << pair.second.details() << endl;
                            }
                        }

                        string train_id, seat, date;
                        cout << "Enter train ID to book: ";
                        cin >> train_id;
                        cout << "Enter seat number: ";
                        cin >> seat;
                        cout << "Enter date: ";
                        cin >> date;

                        if (trains.find(train_id) != trains.end()) {
                            user->bookTicket(trains[train_id], seat, date);
                        } else {
                            cout << "Train ID not found." << endl;
                        }
                    }
                    break;
                case 4:
                    {
                        int ticket_id;
                        cout << "Enter ticket ID: ";
                        cin >> ticket_id;
                        try {
                            user->cancelTicket(ticket_id);
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                    }
                    break;
                case 5:
                    user->viewTickets();
                    break;
                case 6:
                    {
                        int ticket_id;
                        cout << "Enter ticket ID: ";
                        cin >> ticket_id;
                        try {
                            cout << "Seat Number: " << user->checkSeatNumber(ticket_id) << endl;
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                    }
                    break;
                case 7:
                    {
                        int ticket_id;
                        cout << "Enter ticket ID: ";
                        cin >> ticket_id;
                        try {
                            cout << "Train Number: " << user->checkTrainNumber(ticket_id) << endl;
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                    }
                    break;
                case 8:
                    {
                        int ticket_id;
                        string food;
                        cout << "Enter ticket ID: ";
                        cin >> ticket_id;
                        cout << "Enter food item: ";
                        cin.ignore(); // To ignore any remaining newline characters
                        getline(cin, food);
                        try {
                            user->orderFood(ticket_id, food);
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                    }
                    break;
                case 9:
                    {
                        int ticket_id;
                        cout << "Enter ticket ID: ";
                        cin >> ticket_id;
                        try {
                            user->viewTrainDetails(ticket_id);
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                    }
                    break;
                case 10:
                    return; // Return to the previous menu
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            log("Error: " + string(e.what()));
        }
        pressEnterToContinue();
    }
}

    void adminLogin() {
        clearScreen();
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (auto user : usersList) {
            if (user->login(username, password) && user->viewProfile().find("admin") != string::npos) {
                cout << "Login successful!" << endl;
                log("Admin logged in: " + username);
                adminMenu(static_cast<Admin*>(user));
                return;
            }
        }
        throw runtime_error("Invalid username or password.");
    }

    void adminMenu(Admin* admin) {
        while (true) {
            clearScreen();
            cout << "Admin Menu:\n1. Create User\n2. Delete User\n3. View All Users\n4. Manage Trains\n5. View All Trains\n6. Add Food Service\n7. View System Logs\n8. Generate Reports\n9. Logout\nEnter choice: ";
            int choice;
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        {
                            string username, password;
                            cout << "Enter new username: ";
                            cin >> username;
                            cout << "Enter new password: ";
                            cin >> password;
                            admin->createUser(usersList, username, password);
                        }
                        break;
                    case 2:
                        {
                            string username;
                            cout << "Enter username to delete: ";
                            cin >> username;
                            admin->deleteUser(usersList, username);
                        }
                        break;
                    case 3:
                        admin->viewAllUsers(usersList);
                        break;
                    case 4:
                        {
                            string id, name, origin, destination;
                            int capacity;
                            cout << "Enter train ID: ";
                            cin >> id;
                            cout << "Enter train name: ";
                            cin.ignore(); // To ignore any remaining newline characters
                            getline(cin, name);
                            cout << "Enter train capacity: ";
                            cin >> capacity;
                            cout << "Enter origin: ";
                            cin.ignore(); // To ignore any remaining newline characters
                            getline(cin, origin);
                            cout << "Enter destination: ";
                            getline(cin, destination);
                            Train train(id, name, capacity, origin, destination);
                            admin->manageTrains(trains, train, true);
                        }
                        break;
                    case 5:
                        admin->viewAllTrains(trains);
                        break;
                    case 6:
                        {
                            int ticket_id;
                            string food;
                            cout << "Enter ticket ID: ";
                            cin >> ticket_id;
                            cout << "Enter food item: ";
                            cin.ignore(); // To ignore any remaining newline characters
                            getline(cin, food);
                            admin->addFoodService(ticket_id, food);
                        }
                        break;
                    case 7:
                        admin->viewSystemLogs();
                        break;
                    case 8:
                        admin->generateReports();
                        break;
                    case 9:
                        return; // Return to the previous menu
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                log("Error: " + string(e.what()));
            }
            pressEnterToContinue();
        }
    }

    void pressEnterToContinue() const {
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
};

int main() {
    RailwayManagementSystem rms;
    rms.mainMenu();
    return 0;
}
