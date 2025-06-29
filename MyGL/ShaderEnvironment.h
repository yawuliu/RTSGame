#pragma once

#include <string>
#include <vector>
#include <map>
#include "IShaderEnvironment.h"

namespace MyGL {
    class ShaderEnvironment : public IShaderEnvironment {
    public:
        class pimpl {
        public:
            class def {
            public:
                def(const pimpl::def &a2);

                def() = default;

                virtual ~def() = default;

            public:
                std::string str;
                int count;
            };

        public:
            pimpl() = default;

            virtual ~pimpl() = default;

            ShaderEnvironment::pimpl *operator=(const pimpl &a2);

        protected:
            std::string src;
            std::map<std::string, ShaderEnvironment::pimpl::def> map;
        };

    public:
        ShaderEnvironment(const ShaderEnvironment &other);

        ShaderEnvironment();

        virtual ~ShaderEnvironment() override;

        virtual const std::string &getPrecompileSource() override;

        virtual IShaderEnvironment *operator<<(const std::string &def) override;

        virtual ShaderEnvironment *operator=(const ShaderEnvironment &other) override;

        IShaderEnvironment *operator>>(const std::string &def);

        virtual IShaderEnvironment *pop(const std::string &name) override;

        virtual IShaderEnvironment *push(const std::string &name, const std::string &def) override;

    protected:
        bool needToUpdate;
        //        00000009     // padding byte
        //        0000000A     // padding byte
        //        0000000B     // padding byte
        //        0000000C     // padding byte
        //        0000000D     // padding byte
        //        0000000E     // padding byte
        //        0000000F     // padding byte
        ShaderEnvironment::pimpl *data;
    };
}

