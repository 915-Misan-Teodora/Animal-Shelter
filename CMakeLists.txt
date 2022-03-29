cmake_minimum_required(VERSION 3.17)
project(a89_915_Misan_Teodora)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(Domain)
include_directories(exceptions)
include_directories(Repository)
include_directories(Service)
include_directories(validation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

add_executable(a89_915_Misan_Teodora
        Domain/Pets.cpp
        Domain/Pets.h
        exceptions/exceptions.h
        Repository/CSVRepo.cpp
        Repository/CSVRepo.h
        Repository/File.cpp
        Repository/File.h
        Repository/HTMLRepo.cpp
        Repository/HTMLRepo.h
        Repository/Repo.cpp
        Repository/Repo.h
        Repository/RepoAdoption.cpp
        Repository/RepoAdoption.h
        Service/service.cpp
        Service/service.h
        validation/validator.cpp
        validation/validator.h
        main.cpp gui.cpp gui.h guiUser.cpp guiUser.h GUIMain.cpp GUIMain.h DogsWidget.cpp DogsWidget.h dogswidget.cpp dogswidget.h dogswidget.ui)


target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
