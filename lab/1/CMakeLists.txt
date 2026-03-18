add_executable(ex1
    "${CMAKE_CURRENT_SOURCE_DIR}/ex1.cpp"
)
target_link_libraries(ex1 ${LINK_LIBRARIES})
target_include_directories(ex1 PUBLIC ${INCLUDE_DIRECTORIES})

add_executable(ex2
    "${CMAKE_CURRENT_SOURCE_DIR}/ex2.cpp"
)
target_link_libraries(ex2 ${LINK_LIBRARIES})
target_include_directories(ex2 PUBLIC ${INCLUDE_DIRECTORIES})

add_executable(ex3
    "${CMAKE_CURRENT_SOURCE_DIR}/ex3.cpp"
)
target_link_libraries(ex3 ${LINK_LIBRARIES})
target_include_directories(ex3 PUBLIC ${INCLUDE_DIRECTORIES})

add_executable(ex4
    "${CMAKE_CURRENT_SOURCE_DIR}/ex4.cpp"
)
target_link_libraries(ex4 ${LINK_LIBRARIES})
target_include_directories(ex4 PUBLIC ${INCLUDE_DIRECTORIES})

add_executable(ex5
    "${CMAKE_CURRENT_SOURCE_DIR}/ex5.cpp"
)
target_link_libraries(ex5 ${LINK_LIBRARIES})
target_include_directories(ex5 PUBLIC ${INCLUDE_DIRECTORIES})
