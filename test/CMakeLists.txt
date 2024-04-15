cmake_minimum_required(VERSION 3.14)

set(This SegmentTest)

project(${This} CXX)

# List of test source files
set(TestSources
    TestBasicSegment.cpp
    TestSingleDigitSevenSegment.cpp
    TestTwoDigitSevenSegment.cpp
)

# Create a test executable for each source file
foreach(TestSource ${TestSources})
    get_filename_component(TestName ${TestSource} NAME_WE) # Get the name of the test from the file name
    add_executable(${TestName} ${TestSource}) # Create an executable for the test
    target_link_libraries(${TestName} PUBLIC
        gtest_main
        Arduino-7Segment
    )
    add_test(
        NAME ${TestName}
        COMMAND ${TestName}
    )
endforeach()