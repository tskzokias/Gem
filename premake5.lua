 workspace "Gem"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist" -- distribution
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (.sln directory)
IncludeDir = {}
Include = {}
Include["GLFW"] = "Gem/vendor/GLFW/include"
Include["Glad"] = "Gem/vendor/Glad/include"

include "Gem/Vendor/GLFW"
include "Gem/Vendor/Glad"
	
project "Gem"
	location "Gem"
	kind "SharedLib" -- same as saying it's a dynamic library
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "gepch.h"
	pchsource "Gem/src/gepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		"%{prj.name}/src;",
		"%{prj.name}/vendor/spdlog/include;",
		"%{prj.name}/vendor/GLFW/include;",
		"%{prj.name}/vendor/Glad/include;",
		"%{prj.name}/vendor/Glad/src;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}
	
	links 
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}
	
	filter "system:windows" -- filters specially for windows
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GE_PLATFORM_WINDOWS", 
			"GE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
			-- "_WINDLL" commented out by TheCherno
		}
		
		postbuildcommands -- for copying Gem.dll to Sandbox
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "GE_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "GE_DIST"
		buildoptions "/MD"
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
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		"Gem/vendor/spdlog/include",
		"Gem/src"
	}
	
	links
	{
		"Gem"
	}
	
	filter "system:windows" -- filters specially for windows
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GE_PLATFORM_WINDOWS", 
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "GE_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "GE_DIST"
		buildoptions "/MD"
		optimize "On"