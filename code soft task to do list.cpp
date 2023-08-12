#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    cout << "			*******************************************************" << endl;
    cout << "			*       					      *" << endl;
    cout << "			*             Welcome to To-Do List Manager           *" << endl;
     cout << "			*       					      *" << endl;
    cout << "			*******************************************************" << endl<<endl;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "			*******************************************************" << endl;
               cout << "			*       					      *" << endl;
                cout << "			*  Thank you for using the To-Do List Manager!       *" << endl;
                 cout << "			*       					      *" << endl;
                cout << "			*******************************************************" << endl<<endl;
                break;
            default:
                cout << "			Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
	 // Display menu options
    cout << "			*******************************************************" << endl;
    cout << "			*       					      *" << endl;
    cout << "			*                     Menu:                           *" << endl;
    cout << "			*   1. Add Task                                       *" << endl;
    cout << "			*   2. View Tasks                                     *" << endl;
    cout << "			*   3. Mark Task as Completed                         *" << endl;
    cout << "			*   4. Remove Task                                    *" << endl;
    cout << "			*   5. Exit                                           *" << endl;
     cout << "			*       					      *" << endl;
    cout << "			*******************************************************" << endl<<endl;
    cout << "			Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "			Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "			*******************************************************" << endl;
     cout << "			*       					      *" << endl;
    cout << "			*            Task added successfully!                 *" << endl;
     cout << "			*       					      *" << endl;
    cout << "			*******************************************************" << endl<<endl;
}

void viewTasks(const vector<Task>& tasks) {
	// Display the to-do list
    cout << "			*******************************************************" << endl;
     cout << endl;
    cout << "			                    To-Do List:                        " << endl;
    cout <<  endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << "			   " << (i + 1) << "  . ";
        if (tasks[i].completed)
            cout << " [ X ] ";
        else
            cout << " [  ] ";
        cout << tasks[i].description;
        cout << string(50 - tasks[i].description.length(), ' ') << " " << endl;
    }
     cout << endl;
    cout << "			*******************************************************" << endl<<endl;
}

void markCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    int index;
    cout << "			Enter the number of the task to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
          // Task marked as completed confirmation
        cout << "			*******************************************************" << endl;
         cout << "			*       					      *" << endl;
        cout << "			*        Task marked as completed!                  *" << endl;
         cout << "			*       					      *" << endl;
        cout << "			*******************************************************" << endl<<endl;
    } else {
        cout << "			Invalid task number. Please try again." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    int index;
    cout << "			Enter the number of the task to remove: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
         // Task removed confirmation
        cout << "			*******************************************************" << endl;
         cout << "			*       					      *" << endl;
        cout << "			*         Task removed successfully!                  *" << endl;
         cout << "			*       					      *" << endl;
        cout << "			*******************************************************" << endl<<endl;
    } else {
        cout << "			Invalid task number. Please try again." << endl;
    }
}
//Created  by Maryam Siddiqui
//For Internship Task To-do manager
//For @softcode      
