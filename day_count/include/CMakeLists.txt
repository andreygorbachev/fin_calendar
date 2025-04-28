project("day-count")

add_library(${PROJECT_NAME} INTERFACE
  1_1.h
  actual_actual.h
  actual_actual_ICMA.h
  actual_365_fixed.h
  actual_360.h
  30_360.h
  30_E_360.h
  30_E_360_ISDA.h
  actual_365_L.h
  calculation_252.h
  RBA_bond_basis
  day_count.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

export(TARGETS day-count NAMESPACE DayCount:: FILE DayCountConfig.cmake)
