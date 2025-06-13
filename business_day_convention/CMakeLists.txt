project("${PROJECT_NAME}_business-day-convention" LANGUAGES NONE)

add_subdirectory(include)

if(NOT FIN_CALENDAR_MINIMAL)

	add_subdirectory(test)

endif()
