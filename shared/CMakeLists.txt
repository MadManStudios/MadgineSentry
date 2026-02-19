
if (NOT EMSCRIPTEN)

	set(CRASHPAD_ENABLE_INSTALL_DEV OFF CACHE BOOL "Enable crashpad development installation" FORCE)
	set(SENTRY_BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" FORCE)
	add_subdirectory(sentry-0.11.2 EXCLUDE_FROM_ALL)

endif()