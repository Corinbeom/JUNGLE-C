cmake_minimum_required(VERSION 3.22)
project(jungle_c C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SRC_FILES
        "Week05/common/*.c"
        "Week05/sample_user/*.c"
        "Week06/common/*.c"
        "Week06/sample_user/*.c"
        "Week07/common/*.c"
        "Week07/sample_user/*.c"
        "Week08/common/*.c"
        "Week08/sample_user/*.c"
)

# 헤더 경로 추가
include_directories(
        Week05/common
        Week05/sample_user
        Week06/common
        Week06/sample_user
        Week07/common
        Week07/sample_user
        Week08/common
        Week08/sample_user
)


add_executable(jungle_c ${SRC_FILES}
        Week05/common/Linked_List/LLprac1.c)
