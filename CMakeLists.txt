CMAKE_MINIMUM_REQUIRED(VERSION 4.3)

include(RezBuild)

find_package( Houdini REQUIRED )

set( library_name foo )

add_library( ${library_name} SHARED
    src/functions.C
)

target_link_libraries( ${library_name} Houdini )
houdini_configure_target( ${library_name} )
