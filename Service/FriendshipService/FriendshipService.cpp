//
// Created by Leti on 20.05.2022.
//

#include "FriendshipService.h"


void FriendshipService::addFriendship(const Friendship &r) {
    Friendship f1(r.getEmail2(), r.getEmail1());
    for(int i  = 0; i < repo.getSize(); i++){
        if(repo.getAll()[i] == r or repo.getAll()[i] == f1){
            throw invalid_argument("This friendship aldready exists!");
        }
    }
    repo.add(r);
    repo.add(f1);
}

int FriendshipService::getSize() {
    return repo.getSize();
}

bool FriendshipService::inFriendship(const User& u1, const User& u2) {
    Friendship f(u1.getEmail(), u2.getEmail());
    Friendship f1(u2.getEmail(), u1.getEmail());
    for(int i = 0; i < repo.getSize(); i++){
        if(f == repo.getAll()[i] or f1 == repo.getAll()[i]){
            return true;
        }
    }
    return false;
}

FriendshipService::FriendshipService(const RepositoryFileCSV<Friendship>& repo)
        : repo(repo){
}

List<Friendship> FriendshipService::getAll() {
    return repo.getAll();
}

void FriendshipService::deleteFriend(const Friendship &r) {
    Friendship f(r.getEmail2(), r.getEmail1());
    repo.deleteEl(r);
    repo.deleteEl(f);
}

FriendshipService::~FriendshipService() = default;
/*
FriendshipService::FriendshipService(FriendshipService &fs) {
    this->repo = fs.repo;
    this->FV = fs.FV;
}

*/