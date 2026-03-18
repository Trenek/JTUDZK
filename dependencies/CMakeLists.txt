add_subdirectory(CAPD)
add_subdirectory(raylib)

set(INCLUDE_DIRECTORIES
    "${CMAKE_CURRENT_SOURCE_DIR}/draw"
)

set(LINK_LIBRARIES
    capd
    raylib
)

set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} PARENT_SCOPE)
set(LINK_LIBRARIES ${LINK_LIBRARIES} PARENT_SCOPE)
