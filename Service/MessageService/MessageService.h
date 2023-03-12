//
// Created by Leti on 17.05.2022.
//

#ifndef SOCIALNETWORK_MESSAGESERVICE_H
#define SOCIALNETWORK_MESSAGESERVICE_H

#include "../../Domain/User/User.h"
#include "../../Domain/Message/Message.h"
#include "../../Domain/MessageValidator/MessageValidator.h"
#include "../../Repository/RepositoryFileCSV.h"

class MessageService {
private:
    RepositoryFileCSV<Message> repo;
    MessageValidator ms;
public:
    explicit MessageService(const RepositoryFileCSV<Message> &repo1, const MessageValidator& ms1);

    void addMessage(const Message &r);

    List<Message> getAll();

    void deleteMessage(const Message &r);

    void updateMessage(const Message& m);

    int getSize();

    Message getMessage(const Message& mes);

};


#endif //SOCIALNETWORK_MESSAGESERVICE_H
