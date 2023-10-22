#include <Arduino.h>
#include <BombaDagua.h>
#include <UpdateDisplay.h>
#include <DataCache.h>
#include <MultiTasking.h>

BombaDagua bomba;
UpdateDisplay display;
DataCache data;

void thread1(){
    data.run();
}

void thread2(){
    display.run(data);
}

void thread3(){
    bomba.run();
}

void setup() {
    superTask.setTimer(thread1, 500, 0);
    superTask.setTimer(thread2, 5000, 0);
    superTask.setTimer(thread3, 10000, 0);
    superTask.startTasks();

}

void loop(){
        
}
