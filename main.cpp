#include <iostream>
#include "Domain/User/User.h"
#include "Domain/Message/Message.h"
#include "Tests/DomainTests/MessageTests/MessageTests.h"
#include "Repository/RepositoryFileCSV.h"
#include "UI/UI.h"
#include "Tests/RepositoryTests/RepoTestsUser/RepoTestsUser.h"
#include "Service/MessageService/MessageService.h"
#include "Domain/MessageValidator/MessageValidator.h"
#include "Tests/DomainTests/UserTests/UserTests.h"
#include "Repository/RepositoryFileEventCSV.h"
#include "Tests/DomainTests/FriendshipTests/FriendshipTests.h"
#include "Tests/DomainTests/EventTests/EventTests.h"
#include "Tests/RepositoryTests/RepoTestsMessage/RepoTestsMessage.h"
#include "Tests/RepositoryTests/RepoTestsFriendship/RepoTestsFriendship.h"
#include "Tests/ServiceTests/UserServiceTests/UserServiceTests.h"
#include "Tests/ServiceTests/MessageServiceTests/MessageServiceTests.h"
#include "Tests/ServiceTests/FriendshipServiceTests/FriendshipServiceTests.h"
#include "Tests/BinarySearchTreeTest/BSTTest.h"
#include "BinaryTree/ABC.h"

void runAllTests();

int main() {
    runAllTests();
    RepositoryFileCSV<Message> messages(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\Messages.csv)");
    RepositoryFileCSV<User> users(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\Users.csv)");
    UserValidator UR;
    UserService serviceU(users, UR);
    MessageValidator ms(serviceU);
    RepositoryFileCSV<Friendship> friends(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\Friends.csv)");
    FriendshipValidator FV(serviceU);
    FriendshipService serviceF(friends);
    MessageService serviceM(messages, ms);
    RepositoryFileEventCSV events(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\Events.csv)");
    EventValidator EV;
    EventService serviceE(events, EV);
    Network *network;
    network  =  new Network(serviceU, serviceF);
    NetworkService networkService(network);
    UI ui(networkService,  serviceM, serviceE);
    cout << endl;
    cout << ("-----------------WELCOME TO SDToySocialNetwork!----------------") << endl;
    ui.RunMenu();
}

void runAllTests() {
    testBST();
    testEvent();
    testFriendship();
    UserTests();
    testMessage();
    runAllRepoUserTests();
    runAllRepoMessageTests();
    runAllFriendshipRepoTests();
    runAllUserServiceTests();
    runAllMessageServiceTests();
    runAllFriendshipServiceTests();
}
