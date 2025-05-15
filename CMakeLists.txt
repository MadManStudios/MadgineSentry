

add_subdirectory(shared)

PROJECT(Sentry)


set(sources)
FolderSources(sources "" src)
	FolderSources(sources src Madgine sentry.cpp sentry.h sentryforward.h sentrylib.h)
	
add_plugin(Sentry Madgine Misc ${sources} PRECOMPILED_HEADER src/Madgine/sentrylib.h)

target_link_plugins(Sentry Root)

if (NOT EMSCRIPTEN)
	target_link_libraries(Sentry PRIVATE sentry::sentry)
else()
	target_link_libraries(Sentry INTERFACE "--pre-js ${CMAKE_CURRENT_SOURCE_DIR}/js/header.js")
endif()

set(sources)
FolderSources(sources "" tools)
	FolderSources(sources tools Madgine_Tools sentrytoolsforward.h sentrytoolslib.h)
		FolderSources(sources Madgine_Tools sentry sentrytool.cpp sentrytool.h)

add_tools(Sentry ${sources} PRECOMPILED_HEADER tools/Madgine_Tools/sentrytoolslib.h SOURCE_ROOT tools)