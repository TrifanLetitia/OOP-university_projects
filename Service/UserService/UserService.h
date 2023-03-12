//
// Created by Leti on 16.05.2022.
//

#ifndef SOCIALNETWORK_USERSERVICE_H
#define SOCIALNETWORK_USERSERVICE_H


#include "../../Repository/RepositoryFileCSV.h"
#include "../../Domain/User/User.h"
#include "../../Domain/UserValidator/UserValidator.h"

class UserService {
private:
    RepositoryFileCSV<User> repo;
    UserValidator UV;
public:
    UserService();
    UserService(const RepositoryFileCSV<User>& repo1, UserValidator& UV);
    void addUser(const User& u);
    void updateUser(const User &u);
    List<User> getAll();
    int getSize();
    void deleteUser(const User& u);
    User getUser(const string& email);
};


#endif //v_USERSERVICE_H
