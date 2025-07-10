project("${PROJECT_NAME}_test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  no_adjustment.cpp
  following.cpp
  preceding.cpp
  modified_following.cpp
  modified_preceding.cpp
  business_day_convention.cpp
  setup.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  fin-calendar_business-day-convention
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
