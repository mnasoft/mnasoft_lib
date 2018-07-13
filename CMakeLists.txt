cmake_minimum_required(VERSION 2.8.12)

project(mnas)

message ("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")

set(INSTALL_PREFIX_FOR_WINDOWS "${CMAKE_SOURCE_DIR}/../usr")
set(INSTALL_PREFIX_FOR_LINUX   "/home/namatv/usr")
set(MSYSTEM "$ENV{MSYSTEM}")
set(INSTALL_PREFIX_FOR_MSYS "D:/PRG/msys32/usr/local")

if ($ENV{MSYSTEM} MATCHES "MINGW32")
  set(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX_FOR_MSYS})
  message ("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
  message ("CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  set(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX_FOR_WINDOWS})
  message ("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
  message ("CMAKE_INSTALL_PREFIX =  ${CMAKE_INSTALL_PREFIX}")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX_FOR_LINUX})
  message ("${BoldRed}CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}${ColourReset}")
  message ("${BoldGreen}CMAKE_INSTALL_PREFIX =  ${CMAKE_INSTALL_PREFIX}${ColourReset}")
endif ($ENV{MSYSTEM} MATCHES "MINGW32")

add_definitions(-DMNAS_LIBRARY)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core)

#if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
#endif()

include_directories(src
                    src/ns_MNAS_CodePage
                    src/ns_MNAS_Error
				 src/ns_MNAS_Gases
				 src/ns_MNAS_HalfDiv
				 src/ns_MNAS_Matrix
				 src/ns_MNAS_MendeleevTbl
				 src/ns_MNAS_ValDimension)

set(ns_MNAS_HalfDiv_SRCS         src/ns_MNAS_HalfDiv/method_half_div.cpp)

set(ns_MNAS_ValDimension_SRCS    src/ns_MNAS_ValDimension/eqation_analizer.cpp
                                 src/ns_MNAS_ValDimension/eqation_el.cpp
			         src/ns_MNAS_ValDimension/nm_value.cpp)

set(ns_MNAS_Matrix_SRCS          src/ns_MNAS_Matrix/fdigbase.cpp src/ns_MNAS_Matrix/fvector.cpp
                                 src/ns_MNAS_Matrix/fpolynom.cpp src/ns_MNAS_Matrix/table.cpp
			         src/ns_MNAS_Matrix/fmatrix.cpp)

set(ns_MNAS_Error_SRCS           src/ns_MNAS_Error/ferror.cpp)

set(ns_MNAS_MendeleevTbl_SRCS    src/ns_MNAS_MendeleevTbl/elem.cpp
                                 src/ns_MNAS_MendeleevTbl/Mnd_elem.cpp)

set(ns_MNAS_CodePage_SRCS        src/ns_MNAS_CodePage/FCodeTable.cpp)

set(ns_MNAS_Gases_SRCS
                                 src/ns_MNAS_Gases/co.cpp
                                 src/ns_MNAS_Gases/no2.cpp
                                 src/ns_MNAS_Gases/c6h6.cpp
                                 src/ns_MNAS_Gases/c2h4.cpp
                                 src/ns_MNAS_Gases/ch4.cpp
                                 src/ns_MNAS_Gases/teplojomkost.cpp
                                 src/ns_MNAS_Gases/h2.cpp
                                 src/ns_MNAS_Gases/c2h5oh.cpp
                                 src/ns_MNAS_Gases/n2_atm.cpp
                                 src/ns_MNAS_Gases/c3h6.cpp
                                 src/ns_MNAS_Gases/h2s.cpp
                                 src/ns_MNAS_Gases/c2h2.cpp
                                 src/ns_MNAS_Gases/c3h8.cpp
                                 src/ns_MNAS_Gases/co2.cpp
                                 src/ns_MNAS_Gases/no.cpp
                                 src/ns_MNAS_Gases/so2.cpp
                                 src/ns_MNAS_Gases/c4h6_1-3.cpp
                                 src/ns_MNAS_Gases/c2h6.cpp
                                 src/ns_MNAS_Gases/oh.cpp
                                 src/ns_MNAS_Gases/n2.cpp
                                 src/ns_MNAS_Gases/air.cpp
                                 src/ns_MNAS_Gases/h2o.cpp
				 src/ns_MNAS_Gases/o2.cpp)

set(ns_MNAS_lib_SRCS
                                 ${ns_MNAS_HalfDiv_SRCS}
				 ${ns_MNAS_ValDimension_SRCS}
				 ${ns_MNAS_Matrix_SRCS}
				 ${ns_MNAS_Gases_SRCS}
				 ${ns_MNAS_MendeleevTbl_SRCS}
				 ${ns_MNAS_Error_SRCS}
				 ${ns_MNAS_CodePage_SRCS})

set(ns_MNAS__HEADERS             src/mnasoft_lib_global.h)

set(ns_MNAS_CodePage_HEADERS     src/ns_MNAS_CodePage/FCodeTable.h)

set(ns_MNAS_Error_HEADERS        src/ns_MNAS_Error/fmerror.h)

set(ns_MNAS_ValDimension_HEADERS src/ns_MNAS_ValDimension/eqation_analizer.h
                                 src/ns_MNAS_ValDimension/eqation_el.h
                                 src/ns_MNAS_ValDimension/nm_value.h)
				 
set(ns_MNAS_Gases_HEADERS
                                 src/ns_MNAS_Gases/co.h
                                 src/ns_MNAS_Gases/c6h6.h
                                 src/ns_MNAS_Gases/ch4.h
                                 src/ns_MNAS_Gases/c3h8.h
                                 src/ns_MNAS_Gases/so2.h
                                 src/ns_MNAS_Gases/teplojomkost.h
                                 src/ns_MNAS_Gases/c3h6.h
                                 src/ns_MNAS_Gases/gases.h
                                 src/ns_MNAS_Gases/co2.h
                                 src/ns_MNAS_Gases/c2h6.h
                                 src/ns_MNAS_Gases/no2.h
                                 src/ns_MNAS_Gases/c2h2.h
                                 src/ns_MNAS_Gases/c2h5oh.h
                                 src/ns_MNAS_Gases/n2.h
                                 src/ns_MNAS_Gases/c4h6_1-3.h
                                 src/ns_MNAS_Gases/h2o.h
                                 src/ns_MNAS_Gases/h2s.h
                                 src/ns_MNAS_Gases/o2.h
                                 src/ns_MNAS_Gases/no.h
                                 src/ns_MNAS_Gases/c2h4.h
                                 src/ns_MNAS_Gases/n2_atm.h
                                 src/ns_MNAS_Gases/h2.h
                                 src/ns_MNAS_Gases/air.h
                                 src/ns_MNAS_Gases/oh.h)
                                 set(ns_MNAS_HalfDiv_HEADERS
                                 src/ns_MNAS_HalfDiv/method_half_div.h)
                                 set(ns_MNAS_Matrix_HEADERS
                                 src/ns_MNAS_Matrix/table.h
                                 src/ns_MNAS_Matrix/fvector.h
                                 src/ns_MNAS_Matrix/fdigbase.h
                                 src/ns_MNAS_Matrix/fpolynom.h
                                 src/ns_MNAS_Matrix/fmatrix.h)
				 
set(ns_MNAS_MendeleevTbl_HEADERS src/ns_MNAS_MendeleevTbl/Mnd_elem.h
                                 src/ns_MNAS_MendeleevTbl/elem.h)

add_library (${CMAKE_PROJECT_NAME} SHARED ${ns_MNAS_lib_SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core)

install(
  TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION static/lib)

install (FILES ${ns_MNAS__HEADERS}             DESTINATION include/${CMAKE_PROJECT_NAME})
install (FILES ${ns_MNAS_CodePage_HEADERS}     DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_CodePage)
install (FILES ${ns_MNAS_Error_HEADERS}        DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_Error)
install (FILES ${ns_MNAS_ValDimension_HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_ValDimension)
install (FILES ${ns_MNAS_Gases_HEADERS}        DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_Gases)
install (FILES ${ns_MNAS_HalfDiv_HEADERS}      DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_HalfDiv)
install (FILES ${ns_MNAS_Matrix_HEADERS}       DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_Matrix)
install (FILES ${ns_MNAS_MendeleevTbl_HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME}/ns_MNAS_MendeleevTbl)

install (FILES ${ns_MNAS_HalfDiv_SRCS}         DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_HalfDiv)
install (FILES ${ns_MNAS_ValDimension_SRCS}    DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_ValDimension)
install (FILES ${ns_MNAS_Matrix_SRCS}          DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_Matrix)
install (FILES ${ns_MNAS_Gases_SRCS}           DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_Gases)				 
install (FILES ${ns_MNAS_Mende_SRCS}           DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_Mende)
install (FILES ${ns_MNAS_Error_SRCS}           DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_Eror)
install (FILES ${ns_MNAS_CodeP_SRCS}           DESTINATION src/${CMAKE_PROJECT_NAME}/ns_MNAS_CodeP)

