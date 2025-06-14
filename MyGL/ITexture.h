#pragma once

namespace MyGL {
    class ITexture {
    public:
        enum InputFormat {
            RGBA8,
            RGB8
        };
        enum FilterType {
            Linear
        };
        enum Format {
            RGBA_DXT5,
            RGBA16
        };
    };
}