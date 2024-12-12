#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }

    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    ToDoList todo;
    int choice;
    std::string task;

    do {
        std::cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character after choice input

        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::getline(std::cin, task);
                todo.addTask(task);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                int taskNumber;
                std::cout << "Enter task number to delete: ";
                std::cin >> taskNumber;
                todo.deleteTask(taskNumber);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
