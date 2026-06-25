CMAKE_MINIMUM_REQUIRED(VERSION 4.3)

include(RezBuild)
find_package( Houdini REQUIRED )

set( library_name libmultishot )
option(SYMLINK "Enable symlink" ON)

add_library( ${library_name} SHARED
    src/expr.C
)
target_link_libraries( ${library_name} Houdini )
houdini_configure_target(${library_name} INSTDIR ${PROJECT_BINARY_DIR}/dso)
install(DIRECTORY ${PROJECT_BINARY_DIR}/dso DESTINATION ${CMAKE_INSTALL_PREFIX})

if(SYMLINK AND ${REZ_BUILD_TYPE} STREQUAL local)
    foreach(d python otls)
        set(src ${CMAKE_CURRENT_SOURCE_DIR}/${d})
        set(dst ${CMAKE_INSTALL_PREFIX}/${d})
        install(CODE "message(STATUS \"Symlinking: ${src} -> ${dst}\")")
        install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${src} ${dst})")
    endforeach(d python otls)
else()
    install(DIRECTORY python DESTINATION ${CMAKE_INSTALL_PREFIX})
    install(DIRECTORY otls DESTINATION ${CMAKE_INSTALL_PREFIX}
        PATTERN "backup" EXCLUDE)
endif()

