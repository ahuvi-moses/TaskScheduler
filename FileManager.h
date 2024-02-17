#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Task.h" 

using namespace std;
class FileManager {
public:
    //static void saveTasksToFile(const std::string& filename, const std::vector<Task>& tasks);
    //static std::vector<Task> loadTasksFromFile(const std::string& filename);
    static void writeToLog(const std::string& filename, const std::string& logMessage);

};


