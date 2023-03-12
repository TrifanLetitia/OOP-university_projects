//
// Created by Leti on 07.05.2022.
//

#include <iomanip>
#include <limits>
#include "UI.h"

Observer observer;

UI::~UI() = default;

UI::UI(NetworkService &network, MessageService &messages, EventService &events)
        : network(network), messages(messages), events(events) {
}

void UI::addUser() {
    try {
        string name;
        cout << "Gine name: ";
        std::getline(cin >> ws, name);
        cout << "Give age: ";
        int age;
        cin >> age;
        cout << "Give email: ";
        string email;
        std::getline(cin >> ws, email);
        cout << "Enter password: ";
        string password;
        std::getline(cin >> ws, password);
        User u(name, age, email, password);
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == email) {
                throw invalid_argument("There is already a user with this id!Try something else!");
            }
        }
        network.addUserService(u);
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::showUsers() {
    /*
    for (int i = 0; i < users.getSize(); i++) {
        cout << users.getAll()[i] << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
     */
    cout
            << left
            << setw(17)
            << "Name"
            << left
            << setw(16)
            << "Age"
            << left
            << setw(14)
            << "Email"
            << left
            << setw(14)
            << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < network.getUsers().getSize(); i++) {
        cout
                << left
                << setw(17)
                << network.getUsers().getAll()[i].getName()
                << left
                << setw(12)
                << network.getUsers().getAll()[i].getAge()
                << left
                << setw(13)
                << network.getUsers().getAll()[i].getEmail()
                << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}

void UI::deleteUser() {
    string email;
    cout << "Give email: ";
    std::getline(cin >> ws, email);
    User u = network.getUsers().getUser(email);
    for (int i = 0; i < network.getUsers().getSize(); i++) {
        if (network.getFriendships().inFriendship(network.getUsers().getAll()[i], u)) {
            Friendship f(network.getUsers().getAll()[i].getEmail(), u.getEmail());
            network.deleteFriendshipService(f);
        }
    }
    List<Message> mes;
    for (int i = 0; i < messages.getSize(); i++) {
        if (messages.getAll()[i].getEmail1() == email or
            messages.getAll()[i].getEmail2() == email) {
            mes.add(messages.getAll()[i]);
        }
    }
    for(int i = 0; i < mes.Size(); i++){
        messages.deleteMessage(mes[i]);
    }
    network.deleteUserService(u);
}

void UI::getUser() {
    string name;
    cout << "Give name: ";
    std::getline(cin >> ws, name);
    for (int i = 0; i < network.getUsers().getSize(); i++) {
        if (network.getUsers().getAll()[i].getName() == name) {
            cout << network.getUsers().getAll()[i];
        }
    }
}

void UI::addFriendship() {
    try {
        string name1;
        cout << "Give email of the first user: ";
        std::getline(cin >> ws, name1);
        string name2;
        cout << "Give email of the second user: ";
        std::getline(cin >> ws, name2);
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        User u1;
        User u2;
        int n = 0;
        int n1 = 0;
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == name1) {
                u1 = network.getUsers().getAll()[i];
                n++;
            }
        }
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == name2) {
                u2 = network.getUsers().getAll()[i];
                n1++;
            }
        }
        if (network.getFriendships().inFriendship(u1, u2)) {
            throw invalid_argument("You are already friends.");
        }
        if (n == 0 or n1 == 0) { throw invalid_argument("No user with this email found!"); }
        Friendship f(u1.getEmail(), u2.getEmail());
        network.addFriendshipService(f);
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::PrintMenu() {
    std::cout << "\n";
    std::cout << "Choose an option: " << std::endl;
    std::cout << "(1): Log in." << std::endl;
    std::cout << "(2): Create an account." << std::endl;
    std::cout << "(3): Admin menu." << std::endl;
    std::cout << "(4): Exit." << std::endl;
}

void UI::RunMenu() {
    int opt;
    do {
        PrintMenu();
        try {
            std::cin >> opt;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw invalid_argument("INVALID INPUT!");
            }
        }
        catch (invalid_argument &ex) {
            std::cout << "An exception occurred." << "->";
            std::cout << ex.what();
            continue;
        }
        switch (opt) {
            case 1: {
                try {
                    string email;
                    string password;
                    cout << "Enter your email: ";
                    std::getline(cin >> ws, email);
                    cout << "Enter your password: ";
                    std::getline(cin >> ws, password);
                    if (!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw invalid_argument("INVALID INPUT!");
                    }
                    userMenu(email, password);
                }
                catch (invalid_argument &ex) {
                    std::cout << "An exception occurred." << "->";
                    std::cout << ex.what();
                    continue;
                }
                break;
            }
            case 2: {
                createAccount();
                break;
            }
            case 3: {
                adminMenu();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                std::cout << "ERROR!You have selected an invalid choice." << std::endl;
                break;
            }
        }
    } while (opt != 4);
}

void UI::sendMessage() {
    try {
        string message;
        string email1;
        string email2;
        cout << "Enter message: ";
        std::getline(cin >> ws, message);
        cout << "Send message from: ";
        std::getline(cin >> ws, email1);
        cout << "To: ";
        std::getline(cin >> ws, email2);
        int id1 = rand() % 100;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        Message m(id1, message, email1, email2);
        int nr = 0;
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == email1 or
                network.getUsers().getAll()[i].getEmail() == email2) {
                nr++;
            }
        }
        if (nr == 0) { throw invalid_argument("Invalid email!Try again!"); }
        messages.addMessage(m);
        cout << "Message: " << m;
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::showMessages() {
    cout << "ALL MESSAGE: " << endl;
    for (int i = 0; i < messages.getSize(); i++) {
        cout << messages.getAll()[i] << endl;
    }
}

void UI::userMenu(const string &email, const string &password) {
    try {
        int nr = 0;
        User u;
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == email and
                network.getUsers().getAll()[i].getPassword() == password) {
                nr++;
                u = network.getUsers().getAll()[i];
            }
        }
        if (nr == 0) { throw invalid_argument("There is no account!Please create an account!"); }
        else {
            int opt;
            do {
                char heart = 3;
                cout << endl << "-------------" << heart << " " << u.getName() << " Profile " << heart
                     << "--------------" << endl;;
                cout << "Choose an option from below" << endl;
                cout << "1. Add a friend" << endl
                     << "2. Send a message" << endl
                     << "3. Show your friends" << endl
                     << "4. Print your private messages" << endl
                     << "5. Delete messages with a friend." << endl
                     << "6. Create an event" << endl
                     << "7. Delete one of your events" << endl
                     << "8. Change Password" << endl
                     << "9. Change your Name " << endl
                     << "10. Delete a Friend" << endl
                     << "11. Deactivate Profile " << endl
                     << "12. Logout" << endl;
                cout << "Choose option: ";
                std::cin >> opt;
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw invalid_argument("INVALID INPUT!");
                }
                switch (opt) {
                    case 1: {
                        try {
                            string fname;
                            cout << "Search friend by name: ";
                            int nr2 = 0;
                            std::getline(cin >> ws, fname);
                            cout << "Which friend would you like to add?" << endl;
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (network.getUsers().getAll()[i].getName() == fname) {
                                    cout << network.getUsers().getAll()[i] << endl;
                                    nr2++;
                                }
                            }
                            if (nr2 == 0) {
                                cout << ("No user was found in the database!");
                                break;
                            }
                            string email1;
                            cout << "Add your friend email: ";
                            std::getline(cin >> ws, email1);
                            int nr1 = 0;
                            if (network.getFriendships().inFriendship(u, network.getUsers().getUser(email1))) {
                                cout << "You are already friends!";
                                break;
                            }//throw invalid_argument("You are already friends!"); continue;}
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (fname == network.getUsers().getAll()[i].getName() &&
                                    email1 == network.getUsers().getAll()[i].getEmail()) {
                                    Friendship f(u.getEmail(), network.getUsers().getAll()[i].getEmail());
                                    network.addFriendshipService(f);
                                    nr1++;
                                }
                            }
                            if (nr1 == 0) {
                                cout << ("Wrong email!Try again!");
                                break;
                            }
                            cout << "Adding your friend... Come back later to connect with him!";
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 2: {
                        try {
                            cout << "Which friend would you like to send a message?Enter email: " << endl;
                            string email2;
                            std::getline(cin >> ws, email2);
                            string message;
                            int nr3 = 0;
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (email2 == network.getUsers().getAll()[i].getEmail()) {
                                    nr3++;
                                }
                            }
                            if (nr3 == 0) {
                                cout << "Invalid email!Try again!";
                                break;
                            }
                            cout << "What message would you like to send : " << endl;
                            std::getline(cin >> ws, message);
                            int id2 = rand() % 100;
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            Message m(id2, message, u.getEmail(), email2);
                            messages.addMessage(m);
                            cout << "Message sent! :)";
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 3: {
                        cout << "Your friends: " << endl;
                        for (int i = 0; i < network.getUsers().getSize(); i++) {
                            if (network.getFriendships().inFriendship(u, network.getUsers().getAll()[i])) {
                                cout << network.getUsers().getAll()[i] << endl;
                            }
                        }
                        break;
                    }
                    case 4: {
                        cout << "Your messages: " << endl;
                        for (int i = 0; i < messages.getSize(); i++) {
                            if (messages.getAll()[i].getEmail1() == email or
                                messages.getAll()[i].getEmail2() == email) {
                                cout << messages.getAll()[i] << endl;
                            }
                        }
                        break;
                    }
                    case 5: {
                        try {
                            cout << "Enter the name of the user with whom you want to delete conversations: ";
                            string nm;
                            std::getline(cin >> ws, nm);
                            int nt7 = 0;
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (network.getUsers().getAll()[i].getName() == nm) {
                                    cout << network.getUsers().getAll()[i] << endl;
                                    nt7++;
                                }
                            }
                            if (nt7 == 0) { throw invalid_argument("No user with this name!"); }
                            cout << "Enter email of the user you want to delete conversations: ";
                            string em1;
                            std::getline(cin >> ws, em1);
                            int nr8 = 0;
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (network.getUsers().getAll()[i].getEmail() == em1) {
                                    nr8++;
                                }
                            }
                            if (nr8 == 0) { throw invalid_argument("No user with this email!"); }
                            int nr9 = 0;
                            List<Message> msg;
                            for (int i = 0; i < messages.getSize(); i++) {
                                if (messages.getAll()[i].getEmail1() == u.getEmail() and
                                    messages.getAll()[i].getEmail2() == em1) {
                                    msg.add(messages.getAll()[i]);
                                    nr9++;
                                }
                                if (messages.getAll()[i].getEmail2() == u.getEmail() and
                                    messages.getAll()[i].getEmail1() == em1) {
                                    msg.add(messages.getAll()[i]);
                                    nr9++;
                                }
                            }
                            if (nr9 == 0) { throw invalid_argument("No messages with this user!"); }
                            for(int i =0; i < msg.Size(); i++){
                                messages.deleteMessage(msg[i]);
                            }
                            cout << "Messages deleted...";
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 6: {
                        try {
                            cout << "Give a name for your event: ";
                            string nevent;
                            std::getline(cin >> ws, nevent);
                            cout << "Give details about your event: ";
                            string devent;
                            std::getline(cin >> ws, devent);
                            int idevent = rand() % 100;
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            List<string> l;
                            l.add(u.getEmail());
                            Event e(idevent, u, nevent, devent, l);
                            events.addEvent(e);
                            cout << "Event created!";
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 7: {
                        try {
                            int nr1 = 0;
                            for (int i = 0; i < events.getSize(); i++) {
                                if (events.getAll()[i].getCreator() == u) {
                                    nr1++;
                                    cout << events.getAll()[i] << endl;
                                }
                            }
                            if (nr1 == 0) { throw invalid_argument("You don't created an event yet!"); }
                            cout << "Which event do you want to delete?Enter id: ";
                            int id2;
                            cin >> id2;
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            int nr2 = 0;
                            for (int i = 0; i < events.getSize(); i++) {
                                if (events.getAll()[i].getId() == id2) {
                                    nr2++;
                                    events.deleteEvent(events.getAll()[i]);
                                }
                            }
                            if (nr2 == 0) { throw invalid_argument("No event with this id!"); }
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 8: {
                        try {
                            string ps;
                            cout << "Enter new password: ";
                            std::getline(cin >> ws, ps);
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            User u1(u.getName(), u.getAge(), u.getEmail(), ps);
                            network.getUsers().updateUser(u1);
                            cout << "Password updated successfully! :)";
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 9: {
                        try {
                            string newname;
                            cout << "Enter your new name: ";
                            std::getline(cin >> ws, newname);
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            User u1(newname, u.getAge(), u.getEmail(), u.getPassword());
                            network.getUsers().updateUser(u1);
                            cout << "Name changed!";
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 10: {
                        try {
                            string nf;
                            cout << "Enter name of friend: ";
                            std::getline(cin >> ws, nf);
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            int nr2 = 0;
                            cout << "Which friend would you like to delete?" << endl;
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (network.getUsers().getAll()[i].getName() == nf) {
                                    if (network.getFriendships().inFriendship(u, network.getUsers().getAll()[i]))
                                        cout << network.getUsers().getAll()[i] << endl;
                                    nr2++;
                                }
                            }
                            if (nr2 == 0) {
                                throw invalid_argument("You don't have a friend with this email!");
                                continue;
                            }
                            string em;
                            cout << "Enter email: ";
                            std::getline(cin >> ws, em);
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                            int nr6 = 0;
                            for (int i = 0; i < network.getUsers().getSize(); i++) {
                                if (network.getUsers().getAll()[i].getEmail() == em) {
                                    if (network.getFriendships().inFriendship(u, network.getUsers().getAll()[i])) {
                                        Friendship f(u.getEmail(), em);
                                        network.deleteFriendshipService(f);
                                        nr6++;
                                        // network.getFriendships().deleteFriend(f1);
                                    }
                                }
                            }
                            if (nr6 == 0) {
                                throw invalid_argument("Wrong email!Try again!");
                            }
                            cout << "Friend deleted! He will miss you! :(";
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 11: {
                        try {
                            string op;
                            cout << "Are you sure you want to deactivate your account?(Yes/No):";
                            std::getline(cin >> ws, op);
                            if (op != "Yes" and op != "No") {
                                throw invalid_argument("Choose Yes or No!");
                            }
                            if (op == "Yes") {
                                List<Message> mes;
                                for (int i = 0; i < messages.getSize(); i++) {
                                    if (messages.getAll()[i].getEmail1() == email or
                                        messages.getAll()[i].getEmail2() == email) {
                                        mes.add(messages.getAll()[i]);
                                    }
                                }
                                for(int i = 0; i < mes.Size(); i++){
                                    messages.deleteMessage(mes[i]);
                                }
                                for (int i = 0; i < network.getFriendships().getSize(); i++) {
                                    if (network.getFriendships().getAll()[i].getEmail1() == u.getEmail() or
                                        network.getFriendships().getAll()[i].getEmail2() == u.getEmail()) {
                                        // Friendship f(u.getEmail(), network.getUsers().getAll()[i].getEmail());
                                        // Friendship f1(network.getUsers().getAll()[i].getEmail(), u.getEmail());
                                        network.deleteFriendshipService(network.getFriendships().getAll()[i]);
                                        // network.getFriendships().deleteFriend(f1);
                                    }
                                }
                                for(int i = 0; i < events.getSize(); i++){
                                    if(events.getAll()[i].getCreator() == u){
                                        events.deleteEvent(events.getAll()[i]);
                                    }
                                    for(int j = 0; j < events.getAll()[i].getParticipants().Size(); j++){
                                        if(events.getAll()[i].getParticipants()[j] == u.getEmail()){
                                            events.getAll()[i].getParticipants().remove(j);
                                        }
                                    }
                                }
                                network.deleteUserService(u);
                                RunMenu();
                            } else if (op == "No") {
                                char heart = 3;
                                cout << "Thank you for staying here on SDToySocialNetwork! " << heart;
                            }
                            if (!std::cin) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw invalid_argument("INVALID INPUT!");
                            }
                        }
                        catch (invalid_argument &ex) {
                            std::cout << "An exception occurred." << "->";
                            std::cout << ex.what();
                            continue;
                        }
                        break;
                    }
                    case 12: {
                        cout << "Bye, bye! Have a nice day!";
                        break;
                    }
                }
            } while (opt != 12);
        }
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::createAccount() {
    try {
        string nume;
        int age;
        string email;
        string password;
        cout << "What is your name?";
        std::getline(cin >> ws, nume);
        cout << "How old are you?";
        cin >> age;
        cout << "Enter an email: ";
        std::getline(cin >> ws, email);
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == email) {
                throw invalid_argument("This email is being used by another user!Try something else!");
                continue;
            }
        }
        cout << "Enter a password: ";
        std::getline(cin >> ws, password);
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        User u(nume, age, email, password);
        network.getUsers().addUser(u);
        cout << "Account successfully created! Enjoy SDToySocialNetwork!";
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::adminMenu() {
    int opt;
    do {
        cout << "Choose an option from below" << endl;
        cout << "1. Add a user" << endl
             << "2. Delete a user" << endl
             << "3. Update a user" << endl
             << "4. Show all users" << endl
             << "5. Send a message." << endl
             << "6. Delete a message" << endl
             << "7. Update a message" << endl
             << "8. Show all messages" << endl
             << "9. Add a friendship" << endl
             << "10. Delete a friendship" << endl
             << "11. Show all friendships" << endl
             << "12. Add an event" << endl
             << "13. Delete an event" << endl
             << "14. Show all events" << endl
             << "15. Main menu." << endl;
        cout << "Choose option: ";
        try {
            std::cin >> opt;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw invalid_argument("INVALID INPUT!");
            }
        }
        catch (invalid_argument &ex) {
            std::cout << "An exception occurred." << "->";
            std::cout << ex.what();
            continue;
        }
        switch (opt) {
            case 1: {
                try {
                    addUser();
                }
                catch (invalid_argument &ex) {
                    std::cout << "An exception occurred." << "->";
                    std::cout << ex.what();
                    continue;
                }
                break;
            }
            case 2: {
                deleteUser();
                break;
            }
            case 3: {
                updateUser();
                break;
            }
            case 4: {
                showUsers();
                break;
            }
            case 5: {
                sendMessage();
                break;
            }
            case 6: {
                deleteMessage();
                break;
            }
            case 7: {
                updateMessage();
                break;
            }
            case 8: {
                showMessages();
                break;
            }
            case 9: {
                addFriendship();
                break;
            }
            case 10: {
                deleteFriendship();
                break;
            }
            case 11: {
                showFriendships();
                break;
            }
            case 12: {
                addEvent();
                break;
            }
            case 13: {
                deleteEvent();
                break;
            }
            case 14: {
                showEvents();
                break;
            }
            case 15: {
                break;
            }
            default: {
                std::cout << "ERROR!You have selected an invalid choice." << std::endl;
                break;
            }
        }
    } while (opt != 15);
}

void UI::updateUser() {
    try {
        cout << "What user do you want to update?Enter email: ";
        string email;
        int nr = 0;
        User u;
        std::getline(cin >> ws, email);
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == email) {
                nr++;
                u = network.getUsers().getAll()[i];
            }
        }
        if (nr == 0) { throw invalid_argument("No user with this id"); }
        cout << "What do you want to update?Enter name/age/password:";
        string op;
        std::getline(cin >> ws, op);
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        if (op == "name") {
            cout << "Enter new name: ";
            string newname;
            std::getline(cin >> ws, newname);
            User u1(newname, u.getAge(), u.getEmail(), u.getPassword());
            network.updateUserService(u1);
        }
        if (op == "age") {
            cout << "Enter new age: ";
            int age;
            cin >> age;
            User u1(u.getName(), age, u.getEmail(), u.getPassword());
            network.updateUserService(u1);
        }
        if (op == "password") {
            cout << "Enter a new password: ";
            string password;
            std::getline(cin >> ws, password);
            User u1(u.getName(), u.getAge(), u.getEmail(), password);
            network.updateUserService(u1);
        }
        if (op != "name" and op != "age" and op != "password") {
            throw invalid_argument("You can only change the name, age or passord of the user!");
        }
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::deleteMessage() {
    try {
        cout << "Give id of the message you want to delete: ";
        int id;
        cin >> id;
        int nr = 0;
        for (int i = 0; i < messages.getSize(); i++) {
            if (messages.getAll()[i].getId() == id) {
                nr++;
                messages.deleteMessage(messages.getAll()[i]);
            }
        }
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        if (nr == 0) { throw invalid_argument("No message with given id!"); }
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::updateMessage() {
    try {
        cout << "Give id of the message you want to update: ";
        int id;
        cin >> id;
        int nr = 0;
        Message m;
        for (int i = 0; i < messages.getSize(); i++) {
            if (messages.getAll()[i].getId() == id) {
                nr++;
                m = messages.getAll()[i];
            }
        }
        if (nr == 0) { throw invalid_argument("No message with given id!"); };
        cout << "Enter new message: ";
        string mes;
        std::getline(cin >> ws, mes);
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        Message m1(m.getId(), mes, m.getEmail1(), m.getEmail2());
        messages.updateMessage(m1);
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::deleteFriendship() {
    try {
        cout << "Enter the emails of the users whose friendship you want to delete: " << endl;
        cout << "Email 1: ";
        string e1;
        std::getline(cin >> ws, e1);
        cout << "Email 2: ";
        string e2;
        std::getline(cin >> ws, e2);
        for (int i = 0; i < network.getFriendships().getSize(); i++) {
            if (network.getFriendships().inFriendship(network.getUsers().getUser(e1), network.getUsers().getUser(e2))) {
                Friendship f(e1, e2);
                network.deleteFriendshipService(f);
            }
        }
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::showFriendships() {
    for (int i = 0; i < network.getFriendships().getSize(); i++) {
        cout << network.getFriendships().getAll()[i] << endl;
    }
}

void UI::addEvent() {
    try {
        cout << "Give a name for your event: ";
        string nevent;
        std::getline(cin >> ws, nevent);
        cout << "Give details about your event: ";
        string devent;
        std::getline(cin >> ws, devent);
        int idevent = rand() % 100;
        List<string> l;
        cout << "Give email of the creator of event: ";
        string em;
        int v = 0;
        std::getline(cin >> ws, em);
        User u;
        for (int i = 0; i < network.getUsers().getSize(); i++) {
            if (network.getUsers().getAll()[i].getEmail() == em) {
                u = network.getUsers().getAll()[i];
                v++;
            }
        }
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        if (v == 0) { throw invalid_argument("No user with this email found!"); }
        l.add(em);
        Event e(idevent, u, nevent, devent, l);
        events.addEvent(e);
        cout << "Event created!";
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::deleteEvent() {
    try {
        cout << "Enter id of event: ";
        int id;
        cin >> id;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("INVALID INPUT!");
        }
        int nr = 0;
        for (int i = 0; i < events.getSize(); i++) {
            if (events.getAll()[i].getId() == id) {
                nr++;
                events.deleteEvent(events.getAll()[i]);
            }
        }
        if (nr == 0) { throw invalid_argument("No event with this id found!"); }
    }
    catch (invalid_argument &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.what();
    }
}

void UI::showEvents() {
    for (int i = 0; i < events.getSize(); i++) {
        cout << events.getAll()[i] << endl;
        cout << "Participants: " << endl;
        for (int j = 0; j < events.getAll()[i].getParticipants().Size(); j++) {
            cout << events.getAll()[i].getParticipants()[j] << endl;
        }
        cout << "-----------------------------------------------------" << endl;
    }
}


