project(day-count-test)

add_executable(${PROJECT_NAME}
  1_1.cpp
  actual_actual.cpp
  actual_actual_ICMA.cpp
  actual_365_fixed.cpp
  actual_360.cpp
  actual_365_L.cpp
  calculation_252.cpp
  day_count.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  day-count
  calendar
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
