project(GAP)
set(PROJECT_DIR ".")
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(source_dir "${PROJECT_SOURCE_DIR}")

include_directories(include/)

add_executable(GAP src/main.cpp src/physics_math.cpp src/entity.cpp)

target_link_libraries(
            GAP
            PRIVATE
            raylib
)
