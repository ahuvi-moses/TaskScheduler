#pragma once
#include <string>
#include <iostream>
using namespace std;
class Task
{
	string title;
	int priority;
	bool completed;
	int maxExecutions;
	int executionsCount;
public:
	Task(string title="", int priority=0, int maxExecutions=1);
	string getTitle() const;
	int getPriority() const;
	int getMaxExecutions() const;
	int getExecutionsCount() const;
	void incrementExecutionsCount();
	bool isCompleted() const;
	void setTitle(string newTitle);
	void setCompleted(bool state);
	void setPriority(int newPriority);
	void markAsCompleted();
	void printTaskDetails();

};

