# Session Management System

## Description
This is a collaborative session management prototype built using C++17. It simulates real-time session handling for music scoring applications, including features like participant management, chat functionality, and persistent storage.

## Features
### 1. Session Management
- Create collaborative sessions with unique links (e.g., `127.0.0.1:<port>`).
- Join or leave sessions dynamically.
- List all active sessions with participant counts.

### 2. Chat System
- Send messages within a session, with timestamps for each message.
- View chat history for each session.

### 3. Persistent Storage
- Save all sessions (participants and chat history) to a file for future use.
- Load saved sessions from a file.

---

## How to Build and Run

### Build Instructions
1. Clone this repository:
    ```
    git clone https://github.com/Astitva-Gupta/session-management-system.git
    cd session-management-system
    ```
2. Build using CMake and Ninja:
    ```
    mkdir build && cd build
    cmake .. -G "Ninja"
    ninja
    ./session-management
    ```

### Run Instructions
After building, run the executable:
``` 
./session-management 
```
---

## Example outputs

### **Session Management**
#### Creating a Session:
Astitva Gupta@DESKTOP-SRMAJFV MINGW64 /c/my-mini-projects/session-management/build (master)  
Welcome to Session Management System!  
Enter your username: Astitva Gupta  

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 1  
Enter session name: SAT Gsoc Meeting  
Session created: SAT Gsoc Meeting at 127.0.0.1:76530  
Astitva Gupta joined session at 127.0.0.1:76530  


#### Joining Participants:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 2  
Enter session link: 127.0.0.1:76530  
Warning: Astitva Gupta is already in the session!  


#### Leaving Participants:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 3  
Astitva Gupta left session at 127.0.0.1:76530  


#### Rejoining Participants:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 2  
Enter session link: 127.0.0.1:76530  
Astitva Gupta joined session at 127.0.0.1:76530  

---
### **Chat System**
#### Sending Messages:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 4  
Enter your message: Hi SAT mentors  
Message sent by Astitva Gupta in session at 127.0.0.1:76530  


#### Viewing Chat History:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 5  
Session State: 'SAT Gsoc Meeting' (Created: 2025-03-31 14:39:04)  
Participants:  
  - Astitva Gupta  
Chat History:  
  [14:39:04] Astitva Gupta has joined the session.  
  [14:39:43] Astitva Gupta has left the session.  
  [14:40:03] Astitva Gupta has joined the session.  
  [14:40:16] Astitva Gupta: Hi SAT mentors  


#### Listing All Sessions:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 6
Active Sessions:  
- 'SAT Gsoc Meeting' at 127.0.0.1:76530 (1 participants)  

---

### **Persistent Storage**
#### Saving Sessions to File:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 7  
Enter filename to save: ExampleOutput1  
Sessions saved to file: ExampleOutput1  


#### Loading Sessions from File:

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 8  
Enter filename to load: ExampleOutput1  
Sessions loaded from file: ExampleOutput1  

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 5  
Session State: 'SAT Gsoc Meeting' (Created: 2025-03-31 14:39:04)  
Participants:  
  - Astitva Gupta  
Chat History:  
  [14:39:04] Astitva Gupta has joined the session.  
  [14:39:43] Astitva Gupta has left the session.  
  [14:40:03] Astitva Gupta has joined the session.  
  [14:40:16] Astitva Gupta: Hi SAT mentors  

===== Session Management System =====
1. Create a new session
2. Join a session
3. Leave a session
4. Send a chat message
5. View session details
6. List all sessions
7. Save sessions to file
8. Load sessions from file
0. Exit  
Choice: 0  
Thank you for using Session Management System!  
