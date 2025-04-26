project(frequency-test)

add_executable(${PROJECT_NAME}
  frequency.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  frequency
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
