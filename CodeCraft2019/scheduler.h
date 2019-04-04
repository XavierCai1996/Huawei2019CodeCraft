#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "sim-scenario.h"
#include "simulator.h"
#include "map-array.h"
#include "memory-pool.h"
#include "timer.h"
#include "load-state.h"

class Scheduler
{
protected:
    Scheduler();

public:
    virtual ~Scheduler();

    void Initialize(SimScenario& scenario);
    void Update(int& time, SimScenario& scenario); //before simulator update
    void HandleGetoutGarage(const int& time, SimScenario& scenario, SimCar* car);
    void HandleBecomeFirstPriority(const int& time, SimScenario& scenario, SimCar* car);
    void HandleResult(int& time, SimScenario& scenario, Simulator::UpdateResult& result); //after simulator update

protected:
    virtual void DoInitialize(SimScenario& scenario);
    virtual void DoUpdate(int& time, SimScenario& scenario);
    virtual void DoHandleGetoutGarage(const int& time, SimScenario& scenario, SimCar* car);
    virtual void DoHandleBecomeFirstPriority(const int& time, SimScenario& scenario, SimCar* car);
    virtual void DoHandleResult(int& time, SimScenario& scenario, Simulator::UpdateResult& result);

    MemoryPool m_memoryPool;

private:
    /* for statistic */
    LoadState m_loadState;

};//class Scheduler

#endif