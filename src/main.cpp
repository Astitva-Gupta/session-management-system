#include "SessionManager.hpp"
#include <iostream>
#include <string>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "\n===== Session Management System =====\n";
    std::cout << "1. Create a new session\n";
    std::cout << "2. Join a session\n";
    std::cout << "3. Leave a session\n";
    std::cout << "4. Send a chat message\n";
    std::cout << "5. View session details\n";
    std::cout << "6. List all sessions\n";
    std::cout << "7. Save sessions to file\n";
    std::cout << "8. Load sessions from file\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    SessionManager manager;
    std::string currentLink;
    std::string currentUser;
    
    bool isRunning = true;
    int choice;
    
    std::cout << "Welcome to Session Management System!\n";
    std::cout << "Enter your username: ";
    std::getline(std::cin, currentUser);
    
    while (isRunning) {
        displayMenu();
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();
        
        switch (choice) {
            case 0: // Exit
                isRunning = false;
                break;
                
            case 1: { // Create session
                std::string sessionName;
                std::cout << "Enter session name: ";
                std::getline(std::cin, sessionName);
                
                currentLink = manager.createSession(sessionName);
                manager.joinSession(currentLink, currentUser);
                break;
            }
                
            case 2: { // Join session
                std::string link;
                std::cout << "Enter session link: ";
                std::getline(std::cin, link);
                
                if (manager.joinSession(link, currentUser)) {
                    currentLink = link;
                }
                break;
            }
                
            case 3: { // Leave session
                if (currentLink.empty()) {
                    std::cout << "You are not in any session.\n";
                } else {
                    if (manager.leaveSession(currentLink, currentUser)) {
                        currentLink = "";
                    }
                }
                break;
            }
                
            case 4: { // Send chat message
                if (currentLink.empty()) {
                    std::cout << "You are not in any session.\n";
                } else {
                    std::string message;
                    std::cout << "Enter your message: ";
                    std::getline(std::cin, message);
                    
                    manager.sendChatMessage(currentLink, currentUser, message);
                }
                break;
            }
                
            case 5: { // View session details
                std::string link;
                if (currentLink.empty()) {
                    std::cout << "Enter session link: ";
                    std::getline(std::cin, link);
                } else {
                    link = currentLink;
                }
                
                manager.saveSessionState(link);
                break;
            }
                
            case 6: // List all sessions
                manager.listAllSessions();
                break;
                
            case 7: { // Save sessions to file
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::getline(std::cin, filename);
                
                manager.saveSessionsToFile(filename);
                break;
            }
                
            case 8: { // Load sessions from file
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::getline(std::cin, filename);
                
                manager.loadSessionsFromFile(filename);
                break;
            }
                
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
    std::cout << "Thank you for using Session Management System!\n";
    return 0;
}
