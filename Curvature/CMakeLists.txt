cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)

if (NOT ParaView_BINARY_DIR)
  find_package(ParaView REQUIRED)
  include(${PARAVIEW_USE_FILE})
endif()

include(ParaViewPlugins)

set(BLA_VENDOR Intel10_64lp)
find_package(LAPACK)

# create a paraview plugin containing server manager xml and the server
# manager classes to build
# this plugin can be loaded on the server side

ADD_PARAVIEW_PLUGIN(myCurvatureFilter "1.0"
  SERVER_MANAGER_XML vtkCurvatures1.xml
  SERVER_MANAGER_SOURCES vtkCurvatures1.cxx)

  TARGET_LINK_LIBRARIES(myCurvatureFilter
    ${CURV_LIBRARY}
    /usr/lib/liblapack.so
    /usr/lib/libblas.so
  )
