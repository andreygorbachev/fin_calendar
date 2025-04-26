project("day-count")

add_library(${PROJECT_NAME} INTERFACE
  day_count.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

export(TARGETS day-count NAMESPACE DayCount:: FILE DayCountConfig.cmake)
