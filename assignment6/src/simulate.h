/*
 * simulate.h
 *
 *  Created on: Dec 31, 2019
 *      Author: tylerrodgers
 */

#ifndef SIMULATE_H_
#define SIMULATE_H_

class TimerType
{
public:
    TimerType();                        // Class constructor
    // Sets count to zero.
    void SetTimer(int value);
    // Sets count to value.
    void Increment();
    // Increments count.
    void Decrement();
    // Decrements count.
    int TimeIs() const;
    // Returns count.
private:
    int count;
};

class JobType
{
public:
    JobType();                          // Class constructor
    int WaitTimeIs() const;
    // Returns the value of waitTime.
    void IncTimer();
    // Increments a jobs timer.
private:
    TimerType waitTime;
};

enum StatusType {BUSY, FREE};
class ServerType
{
public:
    ServerType();                       // Class constructor
    // Initializes status to FREE.
    bool IsFree() const;
    // Returns true if status is FREE; false otherwise.
    void SetBusy();
    // Sets status to BUSY.
    void SetFree();
    // Sets status to FREE.
    void SetTimeRemaining(int time);
    // Sets timeRemaining to time.
    void DecTimer();
    // Decrements a servers timer.
private:
    StatusType status;
    TimerType timeRemaining;
};



#endif /* SIMULATE_H_ */
