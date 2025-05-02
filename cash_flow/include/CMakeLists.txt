project("cash-flow")

add_library(${PROJECT_NAME} INTERFACE
  cash_flow.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

export(TARGETS cash-flow NAMESPACE CashFlow:: FILE CashFlowConfig.cmake)
