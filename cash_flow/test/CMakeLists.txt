project("${PROJECT_NAME}_test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  cash_flow.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  fin-calendar_cash-flow
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
