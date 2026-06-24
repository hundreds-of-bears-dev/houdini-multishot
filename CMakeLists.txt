CMAKE_MINIMUM_REQUIRED(VERSION 4.3)

include(RezBuild)

find_package( Houdini REQUIRED )

set( library_name libmultishot )

add_library( ${library_name} SHARED
    src/expr.C
)

target_link_libraries( ${library_name} Houdini )
houdini_configure_target(${library_name} INSTDIR ${PROJECT_BINARY_DIR}/dso)
install(DIRECTORY python DESTINATION ${CMAKE_INSTALL_PREFIX})
install(DIRECTORY ${PROJECT_BINARY_DIR}/dso DESTINATION ${CMAKE_INSTALL_PREFIX})
install(DIRECTORY otls DESTINATION ${CMAKE_INSTALL_PREFIX})

