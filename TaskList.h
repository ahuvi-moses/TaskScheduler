#pragma once
#include "Task.h"
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class TaskList
{
	queue<Task> highPriorityTasks;
	queue<Task> mediumPriorityTasks;
	queue<Task> lowPriorityTasks;
	int timeQuantum;
public:
	TaskList(int quantum);
	void addTask(const Task& task);
	bool isEmpty() const;
	int getTimeQuantum() const;
	Task getNextTask();
	//void deleteTask(const string& title);
	//Task& getTaskByTitle(const string& title);
	//vector<Task> getAllTasks() const;
};

