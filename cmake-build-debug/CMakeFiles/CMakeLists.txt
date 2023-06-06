find_package(FreeGLUT REQUIRED)
include_directories(${FREEGLUT_INCLUDE_DIRS})

add_executable(main main.c)
target_link_libraries(main PRIVATE ${FREEGLUT_LIBRARIES})
find_package(FreeGLUT CONFIG REQUIRED)
target_link_libraries(main PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)