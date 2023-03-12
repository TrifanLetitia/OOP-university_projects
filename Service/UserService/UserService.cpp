//
// Created by Leti on 16.05.2022.
//

#include "UserService.h"
void UserService::addUser(const User& u) {
    for(int i = 0; i < repo.getSize(); i++){
        if(repo.getAll()[i].getEmail() == u.getEmail()){throw invalid_argument("Another user uses this email address!");}
    }
    UV.ValidateUser(u);
    repo.add(u);
}

List<User> UserService::getAll() {
    return repo.getAll();
}

void UserService::deleteUser(const User& u) {
    repo.deleteEl(u);
}

int UserService::getSize() {
    return repo.getSize();
}

UserService::UserService(const RepositoryFileCSV<User>& repo1, UserValidator& UV) : repo(repo1), UV(UV) {
}

User UserService::getUser(const string& email) {
    for(int i = 0; i < repo.getSize(); i++){
        if(repo.getAll()[i].getEmail() == email){
            return repo.getElement(repo.getAll()[i]);
        }
    }
}

void UserService::updateUser(const User &u) {
    UV.ValidateUser(u);
    for(int i = 0; i < repo.getSize(); i++){
        if(repo.getAll()[i].getEmail() == u.getEmail())
        {
            repo.updateEl(i, u);
        }
    }
}

UserService::UserService() = default;

