#include "Task.h"
#include <iostream>
#include <string>
using namespace std;

Task::Task(string title, int priority, int maxExecutions) : title(title), priority(priority),maxExecutions(maxExecutions),executionsCount(0), completed(false) {}
string Task::getTitle() const { return title; }
int Task::getPriority() const { return priority; }
int Task::getMaxExecutions() const { return maxExecutions; }
int Task::getExecutionsCount() const { return executionsCount; }
bool Task::isCompleted() const { return completed; }
void Task::setTitle(string newTitle) { title = newTitle; }
void Task::setCompleted(bool state) { completed = state; }
void Task::setPriority(int newPriority) { priority = priority; }
void Task::markAsCompleted() { completed = true; }
void Task::incrementExecutionsCount() { executionsCount++; }
void Task::printTaskDetails() {
	cout << "Task title: " << title << endl;
	cout << "Priority " << priority << endl;
	cout << "The task " << (completed ? "completed" : "was not completed") << endl;
}

