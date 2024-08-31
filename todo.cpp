#include<bits/stdc++.h>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;  // A vector to store the list of tasks

public:
    // Function to add a task to the list
    void addTask(const string& task) {
        tasks.push_back(task);  // Add the task to the end of the vector
        cout << "Task added: " << task << endl;
    }

    // Function to view all tasks in the list
    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;  // Display each task with its number
        }
    }

    // Function to delete a task from the list
    void deleteTask(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Task deleted: " << tasks[taskNumber - 1] << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);  // Remove the task at the given index
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after the choice input

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                getline(cin, task);  // Read the full task description including spaces
                toDoList.addTask(task);
                break;
            }
            case 2:
                toDoList.viewTasks();  // Display all tasks in the list
                break;
            case 3: {
                int taskNumber;
                cout << "Enter the task number to delete: ";
                cin >> taskNumber;  // Get the task number to delete
                toDoList.deleteTask(taskNumber);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);  // Repeat until the user chooses to exit

    return 0;
}
