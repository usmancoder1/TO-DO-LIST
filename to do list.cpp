#include <iostream>
using namespace std;
struct Task {
    int id;
    string title;
    Task* next;
};

class ToDoList {
private:
    Task* start;

public:
    ToDoList() {
        start = NULL;
    }

  
    void insertTask() {
        Task* temp = new Task;
        cout << "Enter Task ID: ";
        cin >> temp->id;
        cin.ignore();
        cout << "Enter Task Title: ";
        getline(cin, temp->title);

        temp->next = NULL;

        if (start == NULL) {
            start = temp;
        } else {
            Task* cur = start;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
        }
        cout << "Task inserted successfully.\n";
    }

    
    void displayTasks() {
        if (start == NULL) {
            cout << "No tasks available.\n";
            return;
        }

        Task* cur = start;
        cout << "\n--- To Do List ---\n";
        while (cur != NULL) {
            cout << "ID: " << cur->id << " | Task: " << cur->title << endl;
            cur = cur->next;
        }
    }

    
    void updateTask() {
        if (start == NULL) {
            cout << "List is empty.\n";
            return;
        }

        int id;
        cout << "Enter Task ID to update: ";
        cin >> id;
        cin.ignore();

        Task* cur = start;
        while (cur != NULL) {
            if (cur->id == id) {
                cout << "Enter new Task Title: ";
                getline(cin, cur->title);
                cout << "Task updated successfully.\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Task not found.\n";
    }

    
    void deleteTask() {
        if (start == NULL) {
            cout << "List is empty.\n";
            return;
        }

        int id;
        cout << "Enter Task ID to delete: ";
        cin >> id;

        Task* cur = start;
        Task* prev = NULL;

        if (cur->id == id) {
            start = cur->next;
            delete cur;
            cout << "Task deleted successfully.\n";
            return;
        }

        while (cur != NULL && cur->id != id) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == NULL) {
            cout << "Task not found.\n";
        } else {
            prev->next = cur->next;
            delete cur;
            cout << "Task deleted successfully.\n";
        }
    }
};

int main() {
    ToDoList todo;
    int choice;

    do {
        cout << "\n1. Insert Task";
        cout << "\n2. Display Tasks";
        cout << "\n3. Update Task";
        cout << "\n4. Delete Task";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                todo.insertTask();
                break;
            case 2:
                todo.displayTasks();
                break;
            case 3:
                todo.updateTask();
                break;
            case 4:
                todo.deleteTask();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}


