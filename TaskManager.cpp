#include "TaskManager.h"
#include <iostream>
#include <string>
#include "TaskList.h" 
#include "FileManager.h"
#include <chrono>
#include <thread>

using namespace std;

TaskManager::TaskManager(int quantum):taskList(quantum){}
string logFileName = "Task_log";

void TaskManager::addTask(const string& title, int priority, int maxExecutions) {
    Task* newTask=new Task(title, priority,maxExecutions);
    taskList.addTask(*newTask);
    FileManager::writeToLog(logFileName, "Task " + (*newTask).getTitle() + " added");
}

void TaskManager::runScheduler() {
    string logFileName = "Task_log";
    while (!taskList.isEmpty()) {
        Task task = taskList.getNextTask();
        executeTask(task, taskList.getTimeQuantum());
        if (task.getExecutionsCount() >= task.getMaxExecutions()) {
            task.markAsCompleted();
        }
        if (!task.isCompleted()) {
            taskList.addTask(task);
            FileManager::writeToLog(logFileName, "Task "+task.getTitle()+" returned to the queue");
        }
        else if (task.isCompleted()) {
            FileManager::writeToLog(logFileName, "Task " + task.getTitle() + " completed");
        }
    }

}

void TaskManager::executeTask(Task& task, int executionTime) {
    auto startTime = chrono::steady_clock::now();

    while (true) {
        string logMassage = "Executing task: " + task.getTitle();
        cout << logMassage << endl;
        FileManager::writeToLog(logFileName, logMassage);
        task.incrementExecutionsCount();
        auto currentTime = chrono::steady_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - startTime).count();
        if (elapsedTime >= executionTime) {
            break;
        }

        this_thread::sleep_for(chrono::milliseconds(10));
    }
}
//void TaskManager::markTaskAsCompleted(const std::string& title) {
//    Task& task = taskList.getTaskByTitle(title);
//    if (task.getTitle()!="") {
//        task.markAsCompleted();
//        saveTasksToFile();
//    }
//    else {
//        std::cerr << "Error: Task not found" << std::endl;
//    }
//}
//void TaskManager::loadTasksFromFile() {
//    vector<Task> tasks = FileManager::loadTasksFromFile("tasks.txt");
//    for (const Task& task : tasks) {
//        taskList.addTask(task);
//    }
//}
//void TaskManager::saveTasksToFile() const {
//    FileManager::saveTasksToFile("tasks.txt", taskList.getAllTasks());
//}

