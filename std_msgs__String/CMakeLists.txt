cmake_minimum_required(VERSION 2.8.12)

#if(NOT CMAKE_VERSION VERSION_LESS 3.0)
#    cmake_policy(SET CMP0048 NEW)
#endif()

project(std_msgs__String_opensplice)

# Find OpenSplice
if(NOT OpenSplice_FOUND)
    find_package(OpenSplice REQUIRED)
endif()

# Include OpenSplice directories
include_directories($ENV{OSPL_HOME}/include)
include_directories($ENV{OSPL_HOME}/include/sys)
include_directories($ENV{OSPL_HOME}/include/dcps/C++/SACPP)
include_directories($ENV{OSPL_HOME})
include_directories($ENV{OSPL_HOME}/examples/include)
include_directories($ENV{OSPL_HOME}/examples)
include_directories(standalone)

link_directories(standalone)
link_directories($ENV{OSPL_HOME}/lib)

# Set C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR
        CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    check_cxx_compiler_flag(-std=c++11 SUPPORTS_CXX11)
    if(SUPPORTS_CXX11)
        add_compile_options(-std=c++11)
    else()
        message(FATAL_ERROR "Compiler doesn't support C++11")
    endif()
endif()

message(STATUS "Configuring std_msgs__String_opensplice ...")

# OpenSplice types source files
set(STD_MSGS_STRING_TYPES_SRC
    standalone/StdMsgsStringSplDcps.cpp
    standalone/StdMsgsString.cpp
    standalone/StdMsgsStringDcps.cpp
    standalone/StdMsgsStringDcps_impl.cpp
    )

# OpenSplice subscriber source files
set(STD_MSGS_STRING_SUB_SRC
    src/CheckStatus.cpp
    src/DDSEntityManager.cpp
    src/StdMsgsStringSubscriber.cpp
    )

# OpenSplice publisher source files
set(STD_MSGS_STRING_PUB_SRC
    src/CheckStatus.cpp
    src/DDSEntityManager.cpp
    src/StdMsgsStringPublisher.cpp
    )

# OpenSplice subscriber executable
add_executable(std_msgs__String_opensplice_sub
    ${STD_MSGS_STRING_TYPES_SRC}
    ${STD_MSGS_STRING_SUB_SRC}
    )
target_link_libraries(std_msgs__String_opensplice_sub
#    OpenSplice
    dcpssacpp
    ddskernel
    sacpp_std_msgs__String_types
    )

# OpenSplice publisher executable
add_executable(std_msgs__String_opensplice_pub
    ${STD_MSGS_STRING_TYPES_SRC}
    ${STD_MSGS_STRING_PUB_SRC}
    )
target_link_libraries(std_msgs__String_opensplice_pub
#    OpenSplice
    dcpssacpp
    ddskernel
    sacpp_std_msgs__String_types
    )

