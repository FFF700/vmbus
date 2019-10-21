# cmake_minimum_required(VERSION <specify CMake version here>)
project(vmbus C)

set(CMAKE_C_STANDARD 99)

add_executable(vmbus main.c HLUart.c HLUart.h HLDevice.c HLDevice.h HLSerial.c HLSerial.h typedef.h HLBus.c HLBus.h HLQueue.c HLQueue.h)