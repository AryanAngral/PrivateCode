#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
private:
    std::string id;
    std::string name;
    std::string departure;
    std::string arrival;

public:
    Train(const std::string& id, const std::string& name, const std::string& departure, const std::string& arrival);

    std::string getId() const;
    std::string details() const;

    std::string serialize() const;
    static Train deserialize(const std::string& data);
};

#endif // TRAIN_H
