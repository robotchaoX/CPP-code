# 设置最低版本的cmake要求
cmake_minimum_required(VERSION 2.8)
# 设置项目信息
project(harvest)

# 指定使用的编译器
#set(CMAKE_C_COMPILER "/usr/bin/gcc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")

# 设置编译选项
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
# 添加编译参数
#add_definitions( “-Wall -ansi –pedantic –g”)
# 添加c++ 11标准支持
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 ")

# 设置编译模式,debug会输出调试信息,Debug版会使用参数-g；Release版使用-O3 –DNDEBUG
set(CMAKE_BUILD_TYPE "Debug")
#set( CMAKE_BUILD_TYPE "Release" )

# 添加头文件路径
include_directories(./include ./src ./thirdparty ./thirdparty/percipio)

# 添加源文件路径 -> 变量DIR_SRCS
# 查找当前目录中的所有源文件，并将结果列表存放在变量DIR_SRCS中
aux_source_directory(./src DIR_SRCS)
# 可以添加多个源文件目录
aux_source_directory(./ DIR_SRCS_)
aux_source_directory(./thirdparty/percipio DIR_SRCS_Third)

# 添加CMakeList子目录,# 告诉cmake去子目录寻找新的CMakeList.txt子文件 # 子目录 CMakeLists.txt 将从父目录 CMakeLists.txt 继承设置
#add_subdirectory()


# ========================================
# === Qt
# ========================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)
#set(CMAKE_PREFIX_PATH "/usr/bin/cmake")
#set(CMAKE_PREFIX_PATH "/home/doudouban/Qt5.12.0/5.12.0/gcc_64/lib/cmake")
#set(CMAKE_PREFIX_PATH "/home/elsa/Qt/Qt5.12.0/5.12.0/gcc_64/lib/cmake")

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
#find_package(Qt5 COMPONENTS Core Gui Qml Quick REQUIRED)

set(UI_FILES)
set(RC_FILES)
set(QRC_FILES)
set(QT_LIB Qt5::Widgets)


# ========================================
# === OpenCV
# ========================================
find_package(OpenCV REQUIRED)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV library not found")
else()
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()


# 设置环境变量
set(Camera_LIB tycam)
set(Thread_LIB pthread)
#set(INCLUDE_PATH ./include)

# 指定可执行文件输出目录
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # 可执行软件的目录
#SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # 存放动态库的文件夹位置
#SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # 存放静态库的文件夹位置
# 指定库文件输出目录
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)  # 默认存放库文件的位置

# 定义变量Target_Name
set(Target_Name ${PROJECT_NAME})

# 主函数生成可执行文件
#add_executable(box_runtime_vertion ${DIR_SRCS} ${RC_FILES} ${UI_FILES} ${QRC_FILES})
add_executable(${Target_Name} ${DIR_SRCS} ${DIR_SRCS_} ${DIR_SRCS_Third} ${RC_FILES} ${UI_FILES} ${QRC_FILES})

# 增加库的搜索路径,动态链接库或静态链接库的搜索路径,this command is rarely necessary
#link_directories(./lib)
# All targets link with the same set of libs ??
#link_libraries(lib1 lib2 ...)
# 生成一个自己的库，可以是动态(SHARED)或者静态库(STATIC)
#add_library(helloLIB SHARED hello.cpp)  # #将hello.cxx编译成静态库如libHelloLIB.so

# 指定生成对象时依赖的库,设置链接库,为target添加需要链接的共享库
target_link_libraries(${Target_Name} ${Camera_LIB} ${OpenCV_LIBS} ${QT_LIB} ${Thread_LIB})
#target_link_libraries(box_runtime_vertion ${Camera_LIB} ${OpenCV_LIBS} ${QT_LIB} ${Thread_LIB})
# lots of properties... OUTPUT_NAME, VERSION, ....
#set_target_properties(ss7gw PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

# 安装目录
# 设置默认安装的路径
set(CMAKE_INSTALL_PREFIX /root/harvest)
# TARGETS安装目录,DESTINATION为相对于CMAKE_INSTALL_PREFIX的值的相对路径
INSTALL(TARGETS ${Target_Name}
        RUNTIME DESTINATION bin  # 可执行二进制
        LIBRARY DESTINATION lib  # 动态库
        ARCHIVE DESTINATION libstatic # 静态库
        )
#INSTALL(TARGETS ${Target_Name} DESTINATION bin)
# FILES将给定的文件复制到指定目录
INSTALL(FILES Rt.txt height.txt parameter.json param.txt high.txt DESTINATION ./)
# DIRECTORY复制文件夹
install(DIRECTORY "${PROJECT_SOURCE_DIR}/bin" DESTINATION ./
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ)
install(DIRECTORY "${PROJECT_SOURCE_DIR}/image" DESTINATION ./)
#install(DIRECTORY "${PROJECT_SOURCE_DIR}/image" DESTINATION
#FILES_MATCHING PATTERN "*.gif"  # 文件过滤
#               PATTERN "CVS" EXCLUDE ) # 排除路径

#INSTALL(FILES image/* DESTINATION image)
# PROGRAMS安装外部或者已编译好的库或者可执行文件,shell脚本
#install(PROGRAMS src/lib/boost/libboost_system.so DESTINATION lib)
# 安装时执行CODE代码
install(CODE "MESSAGE(\"Install done .\")")
# 生成并安装一个包含将安装过程的安装树导入到另一个工程中的CMake文件
#install(EXPORT myproj NAMESPACE mp_ DESTINATION lib/myproj)

#打印信息
MESSAGE(STATUS "Project Name : ${PROJECT_NAME}")
MESSAGE(STATUS "Project Dirrectory : ${PROJECT_SOURCE_DIR}")
MESSAGE(STATUS "Default Install Dirrectory : ${CMAKE_INSTALL_PREFIX}")
