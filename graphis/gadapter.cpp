#include "gadapter.h"

#include <MyGL/IScene.h>
#include <MyGL/IData.h>
#include <MyGL/IShaderLoader.h>
#include <MyGL/IShaderEnvironment.h>
#include <MyGL/ShaderEnvironment.h>
#include "settingswidget.h"

MyGL::IShader *Adapter::bloom = 0;

Adapter::Adapter(MyGL::IScene *s) : MyGL::gadapter(s) {
    bloom = 0;
}

MyGL::IShader *Adapter::getLincShader() const {
    if (bloom)
        return bloom;

    if (isBloom())
        scene()->shaderLoader()->enviroment()->push("BLOOM", "");

    if (SettingsWidget::settings.fog)
        scene()->shaderLoader()->enviroment()->push("FOG", "");

    MyGL::IShader *s =
            scene()->dataControl()->addShader("MyGL::LincShader",
                                              "./shaders/postEfects/linc.vert",
                                              "./shaders/postEfects/linc.frag");

    if (isBloom())
        scene()->shaderLoader()->enviroment()->pop("BLOOM");

    if (SettingsWidget::settings.fog)
        scene()->shaderLoader()->enviroment()->pop("FOG");

    bloom = s;
    return s;
}

bool Adapter::isBloom() const {
    return SettingsWidget::settings.bloom;
}

bool Adapter::isShadowMapping() const {
    return SettingsWidget::settings.shadows;
}
