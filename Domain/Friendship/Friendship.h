//
// Created by Leti on 28.04.2022.
//

#ifndef SOCIALNETWORK_FRIENDSHIP_H
#define SOCIALNETWORK_FRIENDSHIP_H


#include <ostream>

class Friendship {
private:
    std::string email1;
    std::string email2;
public:
    Friendship(const std::string& email1, const std::string& email2);
    Friendship();
    ~Friendship();
    std::string getEmail1() const;
    std::string getEmail2() const;
    void setEmail1(const std::string& e1);
    void setEmail2(const std::string& e2);
    Friendship(const Friendship &f);
    Friendship &operator=(const Friendship &f);
    bool operator==(const Friendship &f) const;
    friend std::ostream& operator<<(std::ostream& os, const Friendship& f);
    Friendship(std::string args, char sep);
    void loadFromString(const std::string& args, char sep);
    std::string toStringDelimiter(char sep) const;
};


#endif //SOCIALNETWORK_FRIENDSHIP_H
