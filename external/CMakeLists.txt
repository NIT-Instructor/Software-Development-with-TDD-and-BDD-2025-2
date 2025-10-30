set(TARGETLIB "ExternalCLib")

set(LIB_SOURCE_FILES 
    external_c_lib.c
    )

add_library(${TARGETLIB} STATIC ${LIB_SOURCE_FILES})

target_include_directories(${TARGETLIB} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
