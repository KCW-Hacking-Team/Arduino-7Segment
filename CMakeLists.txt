cmake_minimum_required(VERSION 3.27)

set(This Arduino-7Segment)

project(${This} CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(Headers
  BasicSegment.h
  SingleDigitSevenSegment.h
  TwoDigitSevenSegment.h
)
set(Sources
  BasicSegment.cpp
  SingleDigitSevenSegment.cpp
  TwoDigitSevenSegment.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)