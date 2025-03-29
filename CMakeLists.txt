cmake_minimum_required( VERSION 3.30 )

set( VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "" )
set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )
# set( VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "" )
# set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )

set( CMAKE_CXX_STANDARD 17 )
set( CXX_STANDARD_REQUIRED ON )

project( UnPAZ 
    LANGUAGES CXX C
    VERSION 0.1.0
    DESCRIPTION "UnPAZ is a simple tool to extract PAZ files"
)

find_package( ZLIB REQUIRED )
# target_link_libraries( main PRIVATE ZLIB::ZLIB )

find_package( dxsdk-d3dx CONFIG REQUIRED )
# target_link_libraries( main PRIVATE Microsoft::D3DX9 Microsoft::D3DX10 Microsoft::D3DX11 )


add_executable( UnPAZ
    BDO.cpp BDO.h
    BDOFiles.cpp BDOFiles.h
    #BDOFiles-boost.h 
    #BDOFiles-exp.h
    IceKey.cpp IceKey.h
    UnPAZ.cpp UnPAZ.h
    Utility.cpp Utility.h
)

target_link_libraries( UnPAZ PRIVATE ZLIB::ZLIB )
