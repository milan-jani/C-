#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Connection structure for linked list
struct Connection {
    int routerID; // ID of the connected router
    Connection* next; // Pointer to the next connection
};

// Router structure
struct Router {
    int routerID; // ID of the router
    Connection* connections; // Pointer to the linked list of connections
};

// Class to manage the network routing system
class NetworkRoutingSystem {
private:
    static const int MAX_ROUTERS = 100; // Maximum number of routers
    Router routers[MAX_ROUTERS]; // Array to store routers
    int routerCount; // Current number of routers

public:
    NetworkRoutingSystem() : routerCount(0) {}

    // Function to add a new router
    void addRouter(int id) {
        if (routerCount < MAX_ROUTERS) {
            routers[routerCount].routerID = id;
            routers[routerCount].connections = nullptr; // Initialize connections list
            routerCount++;
            cout << "Router " << id << " added successfully!" << endl;
        } else {
            cout << "Router limit reached!" << endl;
        }
    }

    // Function to remove a router
    void removeRouter(int id) {
        for (int i = 0; i < routerCount; i++) {
            if (routers[i].routerID == id) {
                // Remove all connections to this router from other routers
                for (int j = 0; j < routerCount; j++) {
                    if (j != i) {
                        removeConnection(routers[j].routerID, id);
                    }
                }

                // Clear the connections list
                Connection* current = routers[i].connections;
                while (current != nullptr) {
                    Connection* temp = current;
                    current = current->next;
                    delete temp; // Free memory
                }

                // Shift routers in the array
                for (int j = i; j < routerCount - 1; j++) {
                    routers[j] = routers[j + 1];
                }
                routerCount--;
                cout << "Router " << id << " removed successfully!" << endl;
                return;
            }
        }
        cout << "Router with ID " << id << " not found." << endl;
    }

    // Function to add a connection between two routers
    void addConnection(int routerID1, int routerID2) {
        for (int i = 0; i < routerCount; i++) {
            if (routers[i].routerID == routerID1) {
                // Check if the connection already exists
                if (isConnected(routerID1, routerID2)) {
                    cout << "Connection already exists!" << endl;
                    return;
                }

                // Create a new connection node
                Connection* newConnection = new Connection{routerID2, nullptr};

                // Add the new connection to the linked list
                newConnection->next = routers[i].connections;
                routers[i].connections = newConnection;

                cout << "Connection added between Router " << routerID1 << " and Router " << routerID2 << "!" << endl;
                return;
            }
        }
        cout << "Router with ID " << routerID1 << " not found." << endl;
    }

    // Function to remove a connection between two routers
    void removeConnection(int routerID1, int routerID2) {
        for (int i = 0; i < routerCount; i++) {
            if (routers[i].routerID == routerID1) {
                Connection* current = routers[i].connections;
                Connection* prev = nullptr;

                // Search for the connection to remove
                while (current != nullptr && current->routerID != routerID2) {
                    prev = current;
                    current = current->next;
                }

                // If connection was not found
                if (current == nullptr) {
                    cout << "Connection between Router " << routerID1 << " and Router " << routerID2 << " not found." << endl;
                    return;
                }

                // Unlink the connection from the linked list
                if (prev == nullptr) {
                    // Removing the first connection
                    routers[i].connections = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current; // Free memory
                cout << "Connection removed between Router " << routerID1 << " and Router " << routerID2 << "!" << endl;
                return;
            }
        }
        cout << "Router with ID " << routerID1 << " not found." << endl;
    }

    // Function to check if two routers are connected
    bool isConnected(int routerID1, int routerID2) {
        for (int i = 0; i < routerCount; i++) {
            if (routers[i].routerID == routerID1) {
                Connection* temp = routers[i].connections;
                while (temp != nullptr) {
                    if (temp->routerID == routerID2) {
                        return true; // Connection found
                    }
                    temp = temp->next;
                }
                return false; // Connection not found
            }
        }
        cout << "Router with ID " << routerID1 << " not found." << endl;
        return false; // Router not found
    }

    // Function to find a path between two routers using DFS
    bool findPath(int startID, int endID) {
        vector<bool> visited(MAX_ROUTERS, false);
        return dfs(startID, endID, visited);
    }

private:
    // Helper function for DFS
    bool dfs(int currentID, int endID, vector<bool>& visited) {
        if (currentID == endID) return true; // Path found
        visited[currentID] = true;

        for (int i = 0; i < routerCount; i++) {
            if (routers[i].routerID == currentID) {
                Connection* temp = routers[i].connections;
                while (temp != nullptr) {
                    if (!visited[temp->routerID] && dfs(temp->routerID, endID, visited)) {
                        return true; // Path found in recursion
                    }
                    temp = temp->next;
                }
            }
        }
        return false; // No path found
    }
};

int main() {
    NetworkRoutingSystem nrs;
    int choice, routerID1, routerID2;

    do {
        cout << "\nNetwork Routing System Menu:" << endl;
        cout << "1. Add Router" << endl;
        cout << "2. Remove Router" << endl;
        cout << "3. Add Connection" << endl;
        cout << "4. Remove Connection" << endl;
        cout << "5. Check Connection" << endl;
        cout << "6. Find Path" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Router ID: ";
                cin >> routerID1;
                nrs.addRouter(routerID1);
                break;
            case 2:
                cout << "Enter Router ID to remove: ";
                cin >> routerID1;
                nrs.removeRouter(routerID1);
                break;
            case 3:
                cout << "Enter Router ID 1: ";
                cin >> routerID1;
                cout << "Enter Router ID 2: ";
                cin >> routerID2;
                nrs.addConnection(routerID1, routerID2);
                break;
            case 4:
                cout << "Enter Router ID 1: ";
                cin >> routerID1;
                cout << "Enter Router ID 2: ";
                cin >> routerID2;
                nrs.removeConnection(routerID1, routerID2);
                break;
            case 5:
                cout << "Enter Router ID 1: ";
                cin >> routerID1;
                cout << "Enter Router ID 2: ";
                cin >> routerID2;
                if (nrs.isConnected(routerID1, routerID2)) {
                    cout << "Router " << routerID1 << " is connected to Router " << routerID2 << "." << endl;
                } else {
                    cout << "Router " << routerID1 << " is not connected to Router " << routerID2 << "." << endl;
                }
                break;
            case 6:
                cout << "Enter Start Router ID: ";
                cin >> routerID1;
                cout << "Enter End Router ID: ";
                cin >> routerID2;
 if (nrs.findPath(routerID1, routerID2)) {
                    cout << "Path exists between Router " << routerID1 << " and Router " << routerID2 << "." << endl;
                } else {
                    cout << "No path exists between Router " << routerID1 << " and Router " << routerID2 << "." << endl;
                }
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}