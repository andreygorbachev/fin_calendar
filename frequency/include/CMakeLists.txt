project("frequency")

add_library(${PROJECT_NAME} INTERFACE
  frequency.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

#export(TARGETS frequency NAMESPACE Frequency:: FILE FrequencyConfig.cmake)
