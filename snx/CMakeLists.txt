


set(
    src_time
    time/snx-time.cpp
)


set(
    src_mobility
    #mobility/node-mobility.cpp
    mobility/mobility-propagator.cpp
    mobility/earth-reference.cpp
    mobility/mob-propagator.cpp
    mobility/mob-parameters.cpp
    mobility/keplerian-propagator.cpp
)


set(
    inc_global
    ${CMAKE_CURRENT_SOURCE_DIR}
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(libsnx
    ${src_time}
    ${src_mobility}
)


target_link_libraries(libsnx
    mlx_analytics
)

target_include_directories(libsnx PRIVATE
    ${MLX_ANALYTICS_HDRS}
)

set(snx_includes ${inc_global} CACHE INTERNAL "${snx_includes}")

