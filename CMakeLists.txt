cmake_minimum_required(VERSION 3.15)

project("fin-calendar" VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

include(FetchContent)

set(CALENDAR_BUILD_TESTS_AND_EXAMPLES Off)

FetchContent_Declare(
  calendar
  GIT_REPOSITORY https://github.com/andreygorbachev/calendar.git
  GIT_TAG        main
)

FetchContent_MakeAvailable(calendar)

option(FIN-CALENDAR_BUILD_TESTS_AND_EXAMPLES "Build all of fin-calendar's own tests and examples." On)

if(${FIN-CALENDAR_BUILD_TESTS_AND_EXAMPLES})

  set(BUILD_GMOCK Off)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
  )

  FetchContent_MakeAvailable(googletest)

  enable_testing()

endif()

add_subdirectory(business_day_convention)
add_subdirectory(frequency)
add_subdirectory(quasi_coupon_dates)
add_subdirectory(day_count)
add_subdirectory(cash_flow)

#set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
#export(PACKAGE FinCalendar)
