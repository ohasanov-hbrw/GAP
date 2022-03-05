project(GAP)
set(PROJECT_DIR ".")
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(source_dir "${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE source_files "${source_dir}/*.cpp")
include_directories(include/)

add_executable(GAP ${source_files})

target_link_libraries(
            GAP
            PRIVATE
            raylib
)
