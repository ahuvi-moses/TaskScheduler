#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Task.h"

using namespace std;

//void FileManager::saveTasksToFile(const string& filename, const vector<Task>& tasks) {
//    ofstream file(filename);
//    if (file.is_open()) {
//        for (const Task& task : tasks) {
//            file << task.getTitle() << ";" << ";" << task.isCompleted() << "\n";
//        }
//        file.close();
//        std::cout << "Tasks saved to " << filename << std::endl;
//    }
//    else {
//        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
//    }
//}

//vector<Task> FileManager::loadTasksFromFile(const string& filename) {
//    vector<Task> tasks;
//    ifstream file(filename);
//    if (file.is_open()) {
//        string line;
//        while (getline(file, line)) {
//            istringstream iss(line);
//            string title, priority, completedStr;
//            if (getline(iss, title, ';') &&
//                getline(iss, priority, ';') &&
//                getline(iss, completedStr)) {
//                bool completed = (completedStr == "true");
//                tasks.emplace_back(title, priority);
//            }
//        }
//        file.close();
//        cout << "Tasks loaded from " << filename << endl;
//    }
//    else {
//        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
//    }
//    return tasks;
//}
void FileManager::writeToLog(const string& filename, const string& logMessage) {
    ofstream logFile(filename, ios_base::app);
    if (logFile.is_open()) {
        logFile << logMessage << endl;
        logFile.close();
    }
    else {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
    }
}