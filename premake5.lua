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
	
project "Gem"
	location "Gem"
	kind "SharedLib" -- same as saying it's a dynamic library
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
		"%{prj.name}/src;",
		"%{prj.name}/vendor/spdlog/include;"
	}
	
	filter "system:windows" -- filters specially for windows
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GE_PLATFORM_WINDOWS", 
			"GE_BUILD_DLL",
			-- "_WINDLL" commented out by TheCherno
		}
		
		postbuildcommands -- for copying Gem.dll to Sandbox
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
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
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		"Gem/vendor/spdlog/include;",
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
		symbols "On"
	
	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "GE_DIST"
		optimize "On"