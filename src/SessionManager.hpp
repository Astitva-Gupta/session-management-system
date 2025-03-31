#ifndef SESSIONMANAGER_HPP
#define SESSIONMANAGER_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>

class SessionManager {
public:
    SessionManager();

    // Core session management
    std::string createSession(const std::string& sessionName);
    bool joinSession(const std::string& link, const std::string& userName);
    bool leaveSession(const std::string& link, const std::string& userName);
    void saveSessionState(const std::string& link);
    
    // Enhanced features
    void listAllSessions() const;
    bool sendChatMessage(const std::string& link, const std::string& userName, 
                         const std::string& message);
    std::vector<std::string> getChatHistory(const std::string& link) const;
    
    // Persistence
    bool saveSessionsToFile(const std::string& filename) const;
    bool loadSessionsFromFile(const std::string& filename);

private:
    struct Session {
        std::string name;
        std::vector<std::string> participants;
        std::vector<std::string> chatHistory;
        std::time_t creationTime;
    };

    std::unordered_map<std::string, Session> sessions;
};

#endif // SESSIONMANAGER_HPP
