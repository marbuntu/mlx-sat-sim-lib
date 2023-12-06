cmake_minimum_required(VERSION 3.17.0)

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES 75)
endif()

project(mlx-sat-sim VERSION 0.1.2 LANGUAGES C CXX CUDA)

find_package(CUDAToolkit REQUIRED)

include(CTest)
enable_testing()

set(accel_input 
    accel/mlx-cuda.cpp
    accel/mob.cpp
)

subdirs(libs/mlx-analytics)
subdirs(snx)


add_executable(test_erk 
    src/test-erk.cpp
)

target_include_directories(test_erk PRIVATE
    ${MLX_ANALYTICS_HDRS}
    ${snx_includes}
)


target_link_libraries(test_erk
    mlx_analytics
    libsnx
#    CUDA::cudart
#    CUDA::cuda_driver
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)