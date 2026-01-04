#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Task {
    int id;
    string name;
    int priority;
    int executionTime;
    int arrivalOrder;
};


struct CompareTask {
    bool operator()(const Task& a, const Task& b) {
        if (a.priority == b.priority)
            return a.arrivalOrder > b.arrivalOrder; 
        return a.priority < b.priority; 
    }
};

class TaskScheduler {
private:
    priority_queue<Task, vector<Task>, CompareTask> pq;
    int order = 0;

public:
    void addTask() {
        Task t;
        t.arrivalOrder = order++;

        cout << "Enter Task ID: ";
        cin >> t.id;
        cout << "Enter Task Name: ";
        cin >> t.name;
        cout << "Enter Priority (higher = more important): ";
        cin >> t.priority;
        cout << "Enter Execution Time (ms): ";
        cin >> t.executionTime;

        pq.push(t);
        cout << "✅ Task added successfully!\n";
    }

    void executeTask() {
        if (pq.empty()) {
            cout << "⚠️ No tasks to execute.\n";
            return;
        }

        Task t = pq.top();
        pq.pop();

        cout << "\n🔹 Executing Task 🔹\n";
        cout << "ID: " << t.id << endl;
        cout << "Name: " << t.name << endl;
        cout << "Priority: " << t.priority << endl;
        cout << "Execution Time: " << t.executionTime << " ms\n";
    }

    void displayTasks() {
        if (pq.empty()) {
            cout << "⚠️ No tasks scheduled.\n";
            return;
        }

        priority_queue<Task, vector<Task>, CompareTask> temp = pq;
        cout << "\n📋 Scheduled Tasks:\n";
        while (!temp.empty()) {
            Task t = temp.top();
            temp.pop();
            cout << "ID: " << t.id
                 << " | Name: " << t.name
                 << " | Priority: " << t.priority
                 << " | Time: " << t.executionTime << " ms\n";
        }
    }
};

int main() {
    TaskScheduler scheduler;
    bool running = true;
    int choice;

    while (running) {
        cout << "\n--- Priority Task Scheduler ---\n";
        cout << "1. Add Task\n";
        cout << "2. Execute Task\n";
        cout << "3. View All Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "❌ Invalid input! Enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                scheduler.addTask();
                break;
            case 2:
                scheduler.executeTask();
                break;
            case 3:
                scheduler.displayTasks();
                break;
            case 4:
                cout << "👋 Exiting Task Scheduler.\n";
                running = false;
                break;
            default:
                cout << "❌ Invalid choice. Try again.\n";
        }
    }

    return 0;
}
