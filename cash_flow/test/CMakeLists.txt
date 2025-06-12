project("cash-flow-test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  cash_flow.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  cash-flow
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
