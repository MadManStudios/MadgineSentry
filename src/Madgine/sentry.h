#pragma once

#include "Madgine/root/rootcomponentbase.h"
#include "Madgine/root/rootcomponentcollector.h"

namespace Engine {

    struct MADGINE_SENTRY_EXPORT Sentry : Core::RootComponent<Sentry> {

        Sentry(Core::Root &root);
        ~Sentry();

        virtual std::string_view key() const override;

        void sendMessage(std::string_view message);
        
    private:
    };

}