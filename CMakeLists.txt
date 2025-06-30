# Generated from Game.pro.

cmake_minimum_required(VERSION 3.16)
project(Game LANGUAGES CXX)
if (MSVC)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/msvc2022_64/lib/cmake/")
else ()
    set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake/")
endif ()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif ()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

if (MSVC)
    add_compile_options("/Zc:__cplusplus")
endif ()

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS OpenGL REQUIRED)
find_package(Qt6 COMPONENTS OpenGLWidgets REQUIRED)
find_package(Qt6 COMPONENTS Xml REQUIRED)
find_package(Qt6 COMPONENTS Core5Compat REQUIRED)
find_package(Qt6 COMPONENTS Multimedia REQUIRED)
qt_standard_project_setup()
qt_add_executable(Game WIN32 MACOSX_BUNDLE
        clandobject.cpp clandobject.h
        dataCtrl/filestream.cpp dataCtrl/filestream.h
        dataCtrl/materials.cpp dataCtrl/materials.h
        dataCtrl/pixmaps.cpp dataCtrl/pixmaps.h
        dialogs/saveloaddialog.cpp dialogs/saveloaddialog.h dialogs/saveloaddialog.ui
        fun/bmpmap.cpp fun/bmpmap.h
        game/abstractbehavior.cpp game/abstractbehavior.h
        game/ai/bot.cpp game/ai/bot.h
        game/behaviorcollection.cpp game/behaviorcollection.h
        game/buildingbehavior.cpp game/buildingbehavior.h
        game/centralbuildingbehavior.cpp game/centralbuildingbehavior.h
        game/control/castlecontrol.cpp game/control/castlecontrol.h game/control/castlecontrol.ui
        game/control/icontroller.h
        game/control/incompletebuildingcontrol.cpp game/control/incompletebuildingcontrol.h game/control/incompletebuildingcontrol.ui
        game/control/unitctrl.cpp game/control/unitctrl.h game/control/unitctrl.ui
        game/control/workercontroller.cpp game/control/workercontroller.h game/control/workercontroller.ui
        game/falagownerbahavior.cpp game/falagownerbahavior.h
        game/game.cpp game/game.h
        game/incompletebuildingbehavior.cpp game/incompletebuildingbehavior.h
        game/map.cpp game/map.h
        game/movealgo.cpp game/movealgo.h
        game/objectcollection.cpp game/objectcollection.h
        game/playler.cpp game/playler.h
        game/resourcebehavior.cpp game/resourcebehavior.h
        game/selectrect.cpp game/selectrect.h
        game/ui/buybutton.cpp game/ui/buybutton.h
        game/unitbehavior.cpp game/unitbehavior.h
        game/utils/randomgen.cpp game/utils/randomgen.h
        game/utils/spatialindex.cpp game/utils/spatialindex.h
        game/utils/stableset.h
        game/utils/unitscounter.cpp game/utils/unitscounter.h
        game/warriorbehavior.cpp game/warriorbehavior.h
        game/workerbehavior.cpp game/workerbehavior.h
        globject.cpp globject.h
        glwidget.cpp glwidget.h
        graphis/abstractuserpass.cpp graphis/abstractuserpass.h
        graphis/gadapter.cpp graphis/gadapter.h
        graphis/bulletobject.cpp graphis/bulletobject.h
        graphis/deathanimation.cpp graphis/deathanimation.h
        graphis/gamescene.cpp graphis/gamescene.h
        graphis/gamescenegraph.cpp graphis/gamescenegraph.h
        graphis/graphicsobject.cpp graphis/graphicsobject.h
        graphis/landtechnicue.cpp graphis/landtechnicue.h
        graphis/renderalgo.cpp graphis/renderalgo.h
        graphis/rendermainpass.cpp graphis/rendermainpass.h
        graphis/view.cpp graphis/view.h
        graphis/virtualtexturingpass.cpp graphis/virtualtexturingpass.h
        hud/cyrcle.cpp hud/cyrcle.h
        hud/minimap.cpp hud/minimap.h hud/minimap.ui
        hud/screenhudrender.cpp hud/screenhudrender.h
        hud/showhint.cpp hud/showhint.h
        hud/unitavatar.cpp hud/unitavatar.h hud/unitavatar.ui
        log.cpp log.h
        main.cpp
        mainwindow.cpp mainwindow.h mainwindow.ui
        manwidget.cpp manwidget.h manwidget.ui
        qtshader.cpp qtshader.h
        runtime/atacktypes.cpp runtime/atacktypes.h
        runtime/cxmlbind.cpp runtime/cxmlbind.h
        runtime/gameclasses.cpp runtime/gameclasses.h
        runtime/gameobject.cpp runtime/gameobject.h
        runtime/gameobjectclass.cpp runtime/gameobjectclass.h
        runtime/hotkeys.cpp runtime/hotkeys.h
        runtime/soundgroup.cpp runtime/soundgroup.h
        runtime/texturefactory.cpp runtime/texturefactory.h
        settingswidget.cpp settingswidget.h settingswidget.ui
        sound/sound.cpp sound/sound.h
        style/cursors.cpp style/cursors.h
        style/norwegianwoodstyle.cpp style/norwegianwoodstyle.h
        widgets/gamewidget.cpp widgets/gamewidget.h widgets/gamewidget.ui
        widgets/mapfilewidget.cpp widgets/mapfilewidget.h
        widgets/playlersettings.cpp widgets/playlersettings.h widgets/playlersettings.ui
        widgets/showwidget.cpp widgets/showwidget.h
        widgets/startffawidget.cpp widgets/startffawidget.h widgets/startffawidget.ui
        widgets/unitbutton.cpp widgets/unitbutton.h
        widgets/unitsgroup.cpp widgets/unitsgroup.h widgets/unitsgroup.ui
        MyGL/AbstractPass.cpp
        MyGL/AbstractShader.cpp
        MyGL/Adapter.cpp
        MyGL/AddBlendPass.cpp
        MyGL/Camera.cpp
        MyGL/CGL.cpp
        MyGL/Color.cpp
        MyGL/ColorPass.cpp
        MyGL/DataLoader.cpp
        MyGL/DepthPass.cpp
        MyGL/Filter.cpp
        MyGL/ForwardRenderAlgo.cpp
        MyGL/UniformSampler.cpp
        MyGL/UniformMatrix4x4.cpp
        MyGL/Uniform1f.cpp
        MyGL/Uniform4f.cpp
        MyGL/TransparentPass.cpp
        MyGL/TextureRectangle.cpp
        MyGL/Light.cpp
        MyGL/MainPass.cpp
        MyGL/Model.cpp
        MyGL/Scene.cpp
        MyGL/SceneGraph.cpp
        MyGL/ShaderEnvironment.cpp
        MyGL/ShaderLoader.cpp
        MyGL/ShadowPass.cpp
        MyGL/SSAOpass.cpp
        MyGL/StdMaterial.cpp
        MyGL/StdTechnique.cpp
        MyGL/Texture2d.cpp
        MyGL/ObjectMatrix.cpp
        MyGL/ModelLoader.cpp
        MyGL/ISceneGraph.cpp
        MyGL/IOModel.cpp
        MyGL/GraphicsObject.cpp
        MyGL/FBO.cpp
        MyGL/DataStream.cpp
        MyGL/ErrorControl.cpp
        MyGL/privateGLSupportClass.cpp
        MyGL/Render.cpp
        MyGL/AbstractMaterial.cpp
        MyGL/LightsCollection.cpp
        MyGL/ModelInfo.cpp
        MyGL/RenderState.cpp
        MyGL/ObjectCollection.cpp
        MyGL/AbstractTechnique.cpp
        MyGL/BloomPass.cpp
        MyGL/SmallLightsPass.cpp
        MyGL/VolumetricLightScatteringPass.cpp
        MyGL/VBO.cpp
        MyGL/LincPass.cpp
        MyGL/TextureLoader.cpp
        MyGL/TextureLoader.h
)
target_include_directories(Game PRIVATE
        .
        MyGL_XmlData/include
)

target_link_libraries(Game PRIVATE
        Qt6::Core
        Qt6::Core5Compat
        Qt6::Gui
        Qt6::Multimedia
        Qt6::OpenGL
        Qt6::OpenGLWidgets
        Qt6::Widgets
        Qt6::Xml
)

if (WIN32)
    target_link_libraries(Game PRIVATE
            "OpenGL32"
            "glu32"
    )
endif ()

install(TARGETS Game
        RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
        BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
        LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

set_target_properties(Game
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin"
)

set_target_properties(Game PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)

qt_generate_deploy_app_script(
        TARGET Game
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})


# Retrieve the absolute path to qmake and then use that path to find
# the windeployqt executable
get_target_property(QMAKE_EXE Qt6::qmake IMPORTED_LOCATION)
get_filename_component(QT_BIN_DIR "${QMAKE_EXE}" DIRECTORY)


find_program(WINDEPLOYQT_ENV_SETUP qtenv2.bat HINTS "${QT_BIN_DIR}")
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_BIN_DIR}")

# Run windeployqt immediately after build
add_custom_command(TARGET Game
        POST_BUILD
        COMMAND "${WINDEPLOYQT_ENV_SETUP}" && "${WINDEPLOYQT_EXECUTABLE}" "$<TARGET_FILE:Game>"
)