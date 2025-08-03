#include "../sentrytoolslib.h"

#include "sentrytool.h"

#include "Modules/uniquecomponent/uniquecomponentcollector.h"

#include "Meta/keyvalue/metatable_impl.h"
#include "Meta/serialize/serializetable_impl.h"

#include "imgui/imgui.h"

#include "Madgine_Tools/renderer/imroot.h"

#include "Madgine/sentry.h"

UNIQUECOMPONENT(Engine::Tools::SentryTool)

METATABLE_BEGIN_BASE(Engine::Tools::SentryTool, Engine::Tools::ToolBase)
METATABLE_END(Engine::Tools::SentryTool)

SERIALIZETABLE_INHERIT_BEGIN(Engine::Tools::SentryTool, Engine::Tools::ToolBase)
SERIALIZETABLE_END(Engine::Tools::SentryTool)

namespace Engine {
namespace Tools {

    SentryTool::SentryTool(ImRoot &root)
        : Tool<SentryTool>(root)
    {
    }

    std::string_view SentryTool::key() const
    {
        return "SentryTool";
    }

    void SentryTool::renderMenu()
    {
        if (ImGui::MenuItem("Feedback")) {
            mRoot.dialogs().show(feedbackDialog(), [](const std::string &feedback) {
                Sentry::getSingleton().sendMessage(feedback);
            });
        }
    }

    Dialog<std::string> SentryTool::feedbackDialog()
    {
        DialogSettings &settings = co_await get_dialog_settings;

        settings.acceptText = "Send";
        settings.declineText = "Cancel";

        char buffer[2048] { 0 };
        do {
            ImGui::InputTextMultiline("Feedback", buffer, 2048);
        } while (co_yield settings);

        co_return buffer;
    }

}
}
