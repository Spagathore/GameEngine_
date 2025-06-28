workspace "GameEngine_"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder { soltuion directories }

IncludeDir = {}
IncludeDir["GLFW"] = "GameEngine_/vendor/GLFW/include"
IncludeDir["Glad"] = "GameEngine_/vendor/Glad/include"
IncludeDir["ImGui"] = "GameEngine_/vendor/imgui"

include "GameEngine_/vendor/GLFW"
include "GameEngine_/vendor/Glad"
include "GameEngine_/vendor/imgui"

project "GameEngine_"
	location "GameEngine_"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ge_pch.h"
	pchsource "GameEngine_/src/ge_pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"Glad",
		"GLFW",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"GE_PLATFORM_WINDOWS",
			"GE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		buildoptions { "/utf-8" }

		links
		{
			"opengl32.lib"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter "system:macosx"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"GE_PLATFORM_MACOS",
			"GE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		buildoptions { "-fvisibility=hidden" }
		pchheader ""
		pchsource ""

		links
		{
			"OpenGL.framework",
			"Cocoa.framework",
			"IOKit.framework",
			"CoreFoundation.framework",
			"CoreGraphics.framework",
			"CoreVideo.framework"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter { "system:windows", "configurations:Debug" }
		defines "GE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter { "system:windows", "configurations:Release" }
		defines "GE_RELEASE"
		optimize "On"
		buildoptions "/MD"

	filter { "system:windows", "configurations:Dist" }
		defines "GE_DIST"
		optimize "On"
		buildoptions "/MD"

	filter { "system:macosx", "configurations:Debug" }
		defines "GE_DEBUG"
		symbols "On"

	filter { "system:macosx", "configurations:Release" }
		defines "GE_RELEASE"
		optimize "On"

	filter { "system:macosx", "configurations:Dist" }
		defines "GE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GameEngine_/src"
	}

	externalincludedirs
	{
		"GameEngine_/vendor/spdlog/include"
	}

	links
	{
		"GameEngine_"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"GE_PLATFORM_WINDOWS"
		}

		buildoptions { "/utf-8" }

	filter "system:macosx"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"GE_PLATFORM_MACOS"
		}

	filter { "system:windows", "configurations:Debug" }
		defines "GE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter { "system:windows", "configurations:Release" }
		defines "GE_RELEASE"
		optimize "On"
		buildoptions "/MD"

	filter { "system:windows", "configurations:Dist" }
		defines "GE_DIST"
		optimize "On"
		buildoptions "/MD"

	filter { "system:macosx", "configurations:Debug" }
		defines "GE_DEBUG"
		symbols "On"

	filter { "system:macosx", "configurations:Release" }
		defines "GE_RELEASE"
		optimize "On"

	filter { "system:macosx", "configurations:Dist" }
		defines "GE_DIST"
		optimize "On"