//
// Created by Leti on 20.05.2022.
//

#ifndef SOCIALNETWORK_REPOSITORYFILEEVENT_H
#define SOCIALNETWORK_REPOSITORYFILEEVENT_H


#include <string>
#include "../Domain/Event/Event.h"
#include "../BinaryTree/ABC.h"

using namespace std;


class RepositoryFileEvent {

protected:
    string fileName;
    ABC<Event> elements;
public:
    RepositoryFileEvent();
    explicit RepositoryFileEvent(const string &fileName);
    virtual void saveToFile() = 0;
    virtual void loadFromFile() = 0;
    ~RepositoryFileEvent();
    void addEvent(const Event &e);
    List<Event> getAll();
    void deleteEvent(const Event& e);
    int getSize();
    void addParticipant(Event& e, const User& u);
    void deleteParticipant(const Event& e, User u);
    void clearfile(const string &fileName);
    void updateEvent(const Event& e1, const Event& e);
    static List<Event> list;
};

#endif //SOCIALNETWORK_REPOSITORYFILEEVENT_H
