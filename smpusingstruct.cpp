#include <iostream>
#include <string>

using namespace std;

// Follower structure for linked list
struct Follower {
    int followerID; // ID of the follower
    Follower* next; // Pointer to the next follower
};

// User structure
struct User {
    int userID; // ID of the user
    Follower* followers; // Pointer to the linked list of followers
};

// Class to manage the social media platform
class SocialMediaPlatform {
private:
    static const int MAX_USERS = 100; // Maximum number of users
    User users[MAX_USERS]; // Array to store users
    int userCount; // Current number of users

public:
    SocialMediaPlatform() : userCount(0) {}

    // Function to add a new user
    void addUser (int id) {
        if (userCount < MAX_USERS) {
            users[userCount].userID = id;
            users[userCount].followers = nullptr; // Initialize followers list
            userCount++;
            cout << "User  added successfully!" << endl;
        } else {
            cout << "User  limit reached!" << endl;
        }
    }

    // Function to add a follower
    void addFollower(int userID, int followerID) {
        if(userID!=followerID){
          for (int i = 0; i < userCount; i++) {
            if (users[i].userID == userID) {
                // Check if the follower already exists
                Follower* temp = users[i].followers;
                while (temp != nullptr) {
                    if (temp->followerID == followerID) {
                        cout << "Follower already exists!" << endl;
                        return;
                    }
                    temp = temp->next;
                }

                // Create a new follower node
                Follower* newFollower = new Follower{followerID, nullptr};

                // Add the new follower to the linked list
                newFollower->next = users[i].followers;
                users[i].followers = newFollower;
                cout << "Follower added successfully!" << endl;
                return;
            }
            cout << "User  with ID " << userID << " not found." << endl;
        }
        }
        else{
            cout<<"User cannot follow themselves!"<<endl;
        }
        
        
    }

    // Function to remove a follower
    void removeFollower(int userID, int followerID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i].userID == userID) {
                Follower* current = users[i].followers;
                Follower* prev = nullptr;

                // Search for the follower to remove
                while (current != nullptr && current->followerID != followerID) {
                    prev = current;
                    current = current->next;
                }

                // If follower was not found
                if (current == nullptr) {
                    cout << "Follower with ID " << followerID << " not found." << endl;
                    return;
                }

                // Unlink the follower from the linked list
                if (prev == nullptr) {
                    // Removing the first follower
                    users[i].followers = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current; // Free memory
                cout << "Follower removed successfully!" << endl;
                return;
            }
        }
        cout << "User  with ID " << userID << " not found." << endl;
    }

    // Function to check if a user follows another user
    bool isFollowing(int userID, int followerID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i].userID == userID) {
                Follower* temp = users[i].followers;
                while (temp != nullptr) {
                    if (temp->followerID == followerID) {
                        return true; // Follower found
                    }
                    temp = temp->next;
                }
                return false; // Follower not found
            }
        }
        cout << "User  with ID " << userID << " not found." << endl;
        return false; // User not found
    }
};

int main() {
    SocialMediaPlatform smp;
    int choice, userID, followerID;

    do {
        cout << "\nSocial Media Platform Menu:" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Add Follower" << endl;
        cout << "3. Remove Follower" << endl;
        cout << "4. Check if User Follows Another User" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter User ID: ";
                cin >> userID;
                smp.addUser (userID);
                break;
            case 2:
                cout << "Enter User ID to add follower: ";
                cin >> userID;
                cout << "Enter Follower ID: ";
                cin >> followerID;
                smp.addFollower(userID, followerID);
                break;
            case 3:
                cout << "Enter User ID to remove follower: ";
                cin >> userID;
                cout << "Enter Follower ID: ";
                cin >> followerID;
                smp.removeFollower(userID, followerID);
                break;
            case 4:
                cout << "Enter User ID to check: ";
                cin >> userID;
                cout << "Enter Follower ID: ";
                cin >> followerID;
                if (smp.isFollowing(userID, followerID)) {
                    cout << "User  " << followerID << " is following User " << userID << "." << endl;
                } else {
                    cout << "User  " << followerID << " is not following User " << userID << "." << endl;
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}