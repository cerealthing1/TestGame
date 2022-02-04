workspace "TestGame"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "TestGame/vendor/GLFW/include"
include "TestGame/vendor/GLFW"

IncludeDir["Glad"] = "TestGame/vendor/Glad/include"
include "TestGame/vendor/Glad"

project "TestGame"
    location "TestGame"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines{
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
	{
		"GLFW",
        "Glad",
		"opengl32.lib"
	}

    filter "system:windows"
        systemversion "latest"
        defines
        {
            "GLFW_INCLUDE_NONE"
        }

    filter {"system:windows", "configurations:Debug"}
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines "ISDEBUG"
        symbols "On"

    filter {"system:windows", "configurations:Release"}
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"
    defines "ISRELEASE"
    optimize "On"