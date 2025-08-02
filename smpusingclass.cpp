#include <iostream>
#include <string>

using namespace std;

// Class to represent a follower
class Follower {
public:
    int followerID; // ID of the follower
    Follower* next; // Pointer to the next follower

    Follower(int id) : followerID(id), next(nullptr) {}
};

// Class to represent a user
class User {
public:
    int userID; // ID of the user
    Follower* followers; // Pointer to the linked list of followers

    User(int id) : userID(id), followers(nullptr) {}

    // Function to add a follower
    void addFollower(int followerID) {
        // Check if the follower already exists
        Follower* temp = followers;
        while (temp != nullptr) {
            if (temp->followerID == followerID) {
                cout << "Follower already exists!" << endl;
                return;
            }
            temp = temp->next;
        }

        // Create a new follower node
        Follower* newFollower = new Follower(followerID);
        newFollower->next = followers;
        followers = newFollower;
        cout << "Follower added successfully!" << endl;
    }

    // Function to remove a follower
    void removeFollower(int followerID) {
        Follower* current = followers;
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
            followers = current->next;
        } else {
            prev->next = current->next;
        }
        delete current; // Free memory
        cout << "Follower removed successfully!" << endl;
    }

    // Function to check if a user follows another user
    bool isFollowing(int followerID) {
        Follower* temp = followers;
        while (temp != nullptr) {
            if (temp->followerID == followerID) {
                return true; // Follower found
            }
            temp = temp->next;
        }
        return false; // Follower not found
    }
};

// Class to manage the social media platform
class SocialMediaPlatform {
private:
    static const int MAX_USERS = 100; // Maximum number of users
    User* users[MAX_USERS]; // Array to store users
    int userCount; // Current number of users

public:
    SocialMediaPlatform() : userCount(0) {}

    // Function to add a new user
    void addUser (int id) {
        if (userCount < MAX_USERS) {
            users[userCount] = new User(id);
            userCount++;
            cout << "User  " << id << " added successfully!" << endl;
        } else {
            cout << "User  limit reached!" << endl;
        }
    }

    // Function to remove a user
    void removeUser (int id) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->userID == id) {
                // Clear the followers list
                delete users[i];

                // Shift users in the array
                for (int j = i; j < userCount - 1; j++) {
                    users[j] = users[j + 1];
                }
                userCount--;
                cout << "User  " << id << " removed successfully!";
                 return;
            }
        }
        cout << "User  with ID " << id << " not found." << endl;
    }

    // Function to add a follower to a user
    void addFollower(int userID, int followerID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->userID == userID) {
                users[i]->addFollower(followerID);
                return;
            }
        }
        cout << "User  with ID " << userID << " not found." << endl;
    }

    // Function to remove a follower from a user
    void removeFollower(int userID, int followerID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->userID == userID) {
                users[i]->removeFollower(followerID);
                return;
            }
        }
        cout << "User  with ID " << userID << " not found." << endl;
    }

    // Function to check if a user follows another user
    void checkFollowing(int userID, int followerID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->userID == userID) {
                if (users[i]->isFollowing(followerID)) {
                    cout << "User  " << followerID << " is following User " << userID << "." << endl;
                } else {
                    cout << "User  " << followerID << " is not following User " << userID << "." << endl;
                }
                return;
            }
        }
        cout << "User  with ID " << userID << " not found." << endl;
    }
};

int main() {
    SocialMediaPlatform smp;
    int choice, userID, followerID;

    do {
        cout << "\nSocial Media Platform Menu:" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Remove User" << endl;
        cout << "3. Add Follower" << endl;
        cout << "4. Remove Follower" << endl;
        cout << "5. Check Following" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter User ID: ";
                cin >> userID;
                smp.addUser (userID);
                break;
            case 2:
                cout << "Enter User ID to remove: ";
                cin >> userID;
                smp.removeUser (userID);
                break;
            case 3:
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Follower ID: ";
                cin >> followerID;
                smp.addFollower(userID, followerID);
                break;
            case 4:
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Follower ID: ";
                cin >> followerID;
                smp.removeFollower(userID, followerID);
                break;
            case 5:
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Follower ID: ";
                cin >> followerID;
                smp.checkFollowing(userID, followerID);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}