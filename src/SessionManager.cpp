#include "SessionManager.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>

SessionManager::SessionManager() {}

std::string SessionManager::createSession(const std::string& sessionName) {
    // Generate a random link (e.g., "127.0.0.1:12345")
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10000, 99999);
    std::string link = "127.0.0.1:" + std::to_string(dist(gen));

    // Create session with current timestamp
    sessions[link] = {sessionName, {}, {}, std::time(nullptr)};
    std::cout << "Session created: " << sessionName << " at " << link << std::endl;
    return link;
}

bool SessionManager::joinSession(const std::string& link, const std::string& userName) {
    if (sessions.find(link) == sessions.end()) {
        std::cout << "Error: Session not found at " << link << std::endl;
        return false;
    }
    
    // Check if user is already in session
    auto& participants = sessions[link].participants;
    if (std::find(participants.begin(), participants.end(), userName) != participants.end()) {
        std::cout << "Warning: " << userName << " is already in the session!" << std::endl;
        return false;
    }
    
    // Add user to session
    participants.push_back(userName);
    
    // Add join notification to chat
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss << "[" << std::put_time(std::localtime(&now), "%H:%M:%S") << "] "
       << userName << " has joined the session.";
    sessions[link].chatHistory.push_back(ss.str());
    
    std::cout << userName << " joined session at " << link << std::endl;
    return true;
}

bool SessionManager::leaveSession(const std::string& link, const std::string& userName) {
    if (sessions.find(link) == sessions.end()) {
        std::cout << "Error: Session not found at " << link << std::endl;
        return false;
    }
    
    auto& participants = sessions[link].participants;
    auto it = std::find(participants.begin(), participants.end(), userName);
    
    if (it == participants.end()) {
        std::cout << "Warning: " << userName << " is not in the session!" << std::endl;
        return false;
    }
    
    // Remove user
    participants.erase(it);
    
    // Add leave notification
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss << "[" << std::put_time(std::localtime(&now), "%H:%M:%S") << "] "
       << userName << " has left the session.";
    sessions[link].chatHistory.push_back(ss.str());
    
    std::cout << userName << " left session at " << link << std::endl;
    return true;
}

void SessionManager::saveSessionState(const std::string& link) {
    if (sessions.find(link) == sessions.end()) {
        std::cout << "Error: Session not found at " << link << std::endl;
        return;
    }
    
    const auto& session = sessions[link];
    
    // Format creation time
    std::time_t creationTime = session.creationTime;
    std::stringstream timeSs;
    timeSs << std::put_time(std::localtime(&creationTime), "%Y-%m-%d %H:%M:%S");
    
    std::cout << "Session State: '" << session.name << "' (Created: " << timeSs.str() << ")" << std::endl;
    std::cout << "Participants:" << std::endl;
    
    if (session.participants.empty()) {
        std::cout << "  No participants" << std::endl;
    } else {
        for (const auto& participant : session.participants) {
            std::cout << "  - " << participant << std::endl;
        }
    }
    
    std::cout << "Chat History:" << std::endl;
    if (session.chatHistory.empty()) {
        std::cout << "  No messages" << std::endl;
    } else {
        for (const auto& message : session.chatHistory) {
            std::cout << "  " << message << std::endl;
        }
    }
}

void SessionManager::listAllSessions() const {
    if (sessions.empty()) {
        std::cout << "No active sessions." << std::endl;
        return;
    }
    
    std::cout << "Active Sessions:" << std::endl;
    for (const auto& [link, session] : sessions) {
        std::cout << "- '" << session.name << "' at " << link << " ("
                  << session.participants.size() << " participants)" << std::endl;
    }
}

bool SessionManager::sendChatMessage(const std::string& link, const std::string& userName, const std::string& message) {
    if (sessions.find(link) == sessions.end()) {
        std::cout << "Error: Session not found at " << link << std::endl;
        return false;
    }
    
    auto& participants = sessions[link].participants;
    if (std::find(participants.begin(), participants.end(), userName) == participants.end()) {
        std::cout << "Error: " << userName << " is not in the session!" << std::endl;
        return false;
    }
    
    // Add message to chat
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss << "[" << std::put_time(std::localtime(&now), "%H:%M:%S") << "] "
       << userName << ": " << message;
    sessions[link].chatHistory.push_back(ss.str());
    
    std::cout << "Message sent by " << userName << " in session at " << link << std::endl;
    return true;
}

std::vector<std::string> SessionManager::getChatHistory(const std::string& link) const {
    if (sessions.find(link) != sessions.end()) {
        return sessions.at(link).chatHistory;
    }
    return {};
}

bool SessionManager::saveSessionsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing: " << filename << std::endl;
        return false;
    }
    
    file << sessions.size() << std::endl;
    
    for (const auto& [link, session] : sessions) {
        file << link << std::endl;
        file << session.name << std::endl;
        file << session.creationTime << std::endl;
        
        file << session.participants.size() << std::endl;
        for (const auto& participant : session.participants) {
            file << participant << std::endl;
        }
        
        file << session.chatHistory.size() << std::endl;
        for (const auto& message : session.chatHistory) {
            file << message << std::endl;
        }
    }
    
    file.close();
    std::cout << "Sessions saved to file: " << filename << std::endl;
    return true;
}

bool SessionManager::loadSessionsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for reading: " << filename << std::endl;
        return false;
    }
    
    sessions.clear();
    
    size_t numSessions;
    file >> numSessions;
    file.ignore(); // Consume newline
    
    for (size_t i = 0; i < numSessions; ++i) {
        std::string link;
        std::getline(file, link);
        
        Session session;
        std::getline(file, session.name);
        
        file >> session.creationTime;
        file.ignore();
        
        size_t numParticipants;
        file >> numParticipants;
        file.ignore();
        
        for (size_t j = 0; j < numParticipants; ++j) {
            std::string participant;
            std::getline(file, participant);
            session.participants.push_back(participant);
        }
        
        size_t numMessages;
        file >> numMessages;
        file.ignore();
        
        for (size_t j = 0; j < numMessages; ++j) {
            std::string message;
            std::getline(file, message);
            session.chatHistory.push_back(message);
        }
        
        sessions[link] = session;
    }
    
    file.close();
    std::cout << "Sessions loaded from file: " << filename << std::endl;
    return true;
}
