#include "delay.h"

// delay : Int -> Void
// sleeps current thread for a specified amount of milliseconds
void delay(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}