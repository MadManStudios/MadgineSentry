#pragma once

#include "Madgine/sentrylib.h"
#include "Madgine_Tools/toolslib.h"

#if defined(SentryTools_EXPORTS)
#    define MADGINE_SENTRY_TOOLS_EXPORT DLL_EXPORT
#else
#    define MADGINE_SENTRY_TOOLS_EXPORT DLL_IMPORT
#endif

#include "sentrytoolsforward.h"