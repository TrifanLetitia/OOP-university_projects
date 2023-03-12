//
// Created by Leti on 17.05.2022.
//

#include "MessageService.h"
#include "../../Domain/Message/Message.h"
#include "../../Domain/MessageValidator/MessageValidator.h"

MessageService::MessageService(const RepositoryFileCSV<Message> &repo1, const MessageValidator& ms1)
        : repo(repo1), ms(ms1) {
}

void MessageService::addMessage(const Message &r) {
    int i = 0;
    int id = r.getId();
    while(i < repo.getSize()){
        if(repo.getAll()[i].getId() == id){
            id = rand() % 100;
        }
        i++;
    }
    for(int j = 0; j < repo.getSize(); j++){
        if(repo.getAll()[j].getId() == id){throw invalid_argument("There is already another message with this id!");}
    }
    Message m(id, r.getMessage(), r.getEmail1(), r.getEmail2());
    ms.ValidateMessage(m);
    repo.add(m);
}

List<Message> MessageService::getAll() {
    return repo.getAll();
}

void MessageService::deleteMessage(const Message &r) {
    repo.deleteEl(r);
}

void MessageService::updateMessage(const Message& m) {
    ms.ValidateMessage(m);
    int nr = 0;
    for(int i = 0; i < repo.getSize(); i++){
        if(repo.getAll()[i].getId() == m.getId())
        {
            repo.updateEl(i, m);
            nr++;
        }
    }
    if(nr == 0){throw invalid_argument("searched elem was not found!");}
}

int MessageService::getSize() {
    return repo.getSize();
}

Message MessageService::getMessage(const Message &mes) {
    for (int i = 0; i < repo.getSize(); i++) {
        if (repo.getAll()[i] == mes) {
            return mes;
        }
    }
    return {};
}
