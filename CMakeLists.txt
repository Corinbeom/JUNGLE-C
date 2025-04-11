cmake_minimum_required(VERSION 3.22)
project(jungle_c C)

set(CMAKE_C_STANDARD 11)

# 소스 파일들 자동 탐색
file(GLOB COMMON_SOURCES "Week05/common/*.c")
file(GLOB SAMPLE_USER_SOURCES "Week05/sample_user/*.c")

# 헤더 포함 경로 설정 (필요시)
include_directories(Week05/common Week05/sample_user)

# 실행 파일 생성
add_executable(jungle_c
        ${COMMON_SOURCES}
        ${SAMPLE_USER_SOURCES}
)
