#include "User.h"

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

std::string User::viewProfile() const {
    return "Username: " + username;
}

bool User::changePassword(const std::string& oldPwd, const std::string& newPwd) {
    if (password == oldPwd) {
        password = newPwd;
        return true;
    }
    return false;
}

User* User::deserialize(const std::string& data) {
    // Implement deserialization logic
    return nullptr;
}
