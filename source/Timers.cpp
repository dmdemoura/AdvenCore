#include "Timers.hpp"
#include "HwUtils.hpp"

using namespace AdvenCore;

volatile Timers::TimerRegisters* Timers::timerRegisters = (volatile Timers::TimerRegisters*) 0x04000100;

void Timers::Enable(int timerID, bool enable)
{
    HwUtils::SetBit(timerRegisters[timerID].Control, enable, TimerControlOffsets::Enable, TimerControlMasks::Enable);
}
void Timers::EnableCascading(int timerID, bool enable)
{
    HwUtils::SetBit(timerRegisters[timerID].Control, enable, TimerControlOffsets::Cascade, TimerControlMasks::Cascade);
}
void Timers::EnableInterruptOnOverflow(int timerID, bool enable)
{
    HwUtils::SetBit(timerRegisters[timerID].Control, enable, TimerControlOffsets::InterruptOnOverflow, TimerControlMasks::InterruptOnOveflow);
}
void Timers::SetFrequency(int timerID, Frequency frequency)
{
    HwUtils::SetBit(timerRegisters[timerID].Control, frequency, TimerControlOffsets::Frequency, TimerControlMasks::Frequency);
}
void Timers::SetInitialValue(int timerID, int cycles)
{
    timerRegisters[timerID].Data = cycles;
}
int Timers::GetCurrentValue(int timerID)
{
    return timerRegisters[timerID].Data;
}