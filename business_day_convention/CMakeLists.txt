project("${PROJECT_NAME}_business-day-convention" LANGUAGES NONE)

add_subdirectory(include)

if(${FIN-CALENDAR_BUILD_TESTS_AND_EXAMPLES})

	add_subdirectory(test)

endif()
