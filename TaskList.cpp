#include "TaskList.h"
#include <string>
#include <vector>
using namespace std;

TaskList::TaskList(int quantum) : timeQuantum(quantum) {}

void TaskList::addTask(const Task& task) {
	switch (task.getPriority()) {
	case(1):
		highPriorityTasks.push(task);
		break;
	case(2):
		mediumPriorityTasks.push(task);
		break;
	case(3):
		lowPriorityTasks.push(task);
		break;
	default:
		throw invalid_argument("Please insert a valid priority, one of the options: 1,2 or 3");
	}
}

bool TaskList::isEmpty() const {
	if (highPriorityTasks.empty() && mediumPriorityTasks.empty() && lowPriorityTasks.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int TaskList::getTimeQuantum() const { return timeQuantum; }

Task TaskList::getNextTask() {
	if (!highPriorityTasks.empty()) {
		Task task = highPriorityTasks.front();
		highPriorityTasks.pop();
		return task;
	}
	if (!mediumPriorityTasks.empty()) {
		Task task = mediumPriorityTasks.front();
		mediumPriorityTasks.pop();
		return task;
	}
	if (!lowPriorityTasks.empty()) {
		Task task = lowPriorityTasks.front();
		lowPriorityTasks.pop();
		return task;
	}
	return Task();
}
//void TaskList::deleteTask(const string& title) {
//	if (tasks.find(title) != tasks.end()) {
//		tasks.erase(title);
//		cout << "Task " << title << " removed" << endl;
//	}
//	else {
//		throw runtime_error("Error: Task with title '" + title + "' not found :(");
//	}
//}
//Task& TaskList::getTaskByTitle(const string& title) {
//
//	if (tasks.find(title) != tasks.end()) {
//		return tasks.find(title)->second;
//	}
//	else {
//		throw runtime_error("Error: Task with title '" + title + " 'does not exist :(");
//	}
//}

//vector<Task> TaskList::getAllTasks() const {
//	vector<Task> allTasks;
//	for (const auto& pair : tasks) {
//		allTasks.push_back(pair.second);
//	}
//	return allTasks;
//}
