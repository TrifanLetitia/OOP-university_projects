//
// Created by Leti on 07.05.2022.
//

#ifndef SOCIALNETWORK_UI_H
#define SOCIALNETWORK_UI_H

#include "../Service/UserService/UserService.h"
#include "../Service/MessageService/MessageService.h"
#include "../Service/FriendshipService/FriendshipService.h"
#include "../Service/EventService/EventService.h"
#include "../Service/NetworkService/NetworkService.h"

class UI {
private:
    NetworkService network;
    MessageService messages;
    EventService events;
public:
    void userMenu(const string& email, const string& password);
    void adminMenu();
    void PrintMenu();
    void RunMenu();
    void addUser();
    void showUsers();
    void showMessages();
    void deleteUser();
    void updateUser();
    void deleteMessage();
    void updateMessage();
    void getUser();
    void sendMessage();
    void addFriendship();
    void deleteFriendship();
    void showFriendships();
    void addEvent();
    void deleteEvent();
    void showEvents();
    void createAccount();
    ~UI();
    UI(NetworkService& network, MessageService& messages, EventService& events);
};


#endif //SOCIALNETWORK_UI_H
