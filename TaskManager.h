#pragma once
#include <iostream>
#include <string>
#include "TaskList.h" 
#include "FileManager.h"

using namespace std;

class TaskManager {

    TaskList taskList;

public:

    TaskManager(int quantum);

    void addTask(const std::string& title, int priority, int maxExecutions);

    void markTaskAsCompleted(const std::string& title);

    void runScheduler();

    void executeTask(Task& task, int executionTime);

private:
    void loadTasksFromFile();

    void saveTasksToFile() const;
};


