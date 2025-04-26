project("day-count")

add_library(${PROJECT_NAME} INTERFACE
  actual_360.h
  actual_365_fixed.h
  day_count.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

export(TARGETS day-count NAMESPACE DayCount:: FILE DayCountConfig.cmake)
