#pragma once

#include "Madgine_Tools/toolscollector.h"

#include "Modules/uniquecomponent/uniquecomponent.h"

#include "Madgine_Tools/toolbase.h"

namespace Engine {
namespace Tools {

    struct SentryTool : Tool<SentryTool> {

        SentryTool(ImRoot &root);

        std::string_view key() const override;

        void renderMenu() override;

        Dialog<std::string> feedbackDialog();

    };

}
}