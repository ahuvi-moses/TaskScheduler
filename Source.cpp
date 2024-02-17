#include "TaskManager.h" 

int main() {
    TaskManager taskManager(1);

    taskManager.addTask("task1", 1,5);
    taskManager.addTask("task2", 2,3);
    taskManager.addTask("task3", 3,8);
    taskManager.addTask("task4", 2, 20);
    taskManager.addTask("task5", 1, 2);
    taskManager.addTask("task6", 3, 1);
    taskManager.addTask("task7", 3, 6);
    taskManager.addTask("task8", 2, 4);
    taskManager.addTask("task9", 1, 10);
    taskManager.addTask("task10", 1, 7);


    taskManager.runScheduler();

    return 0;
}
