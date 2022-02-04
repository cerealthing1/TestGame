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
IncludeDir["Glad"] = "TestGame/vendor/Glad/include"
include "TestGame/vendor/GLFW"
include "TestGame/vendor/Glad"

project "TestGame"
    location "TestGame"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.GLFW}",
         "%{IncludeDir.Glad}"
    }

    links
	{
		"GLFW",
        "GLAD",
		"opengl32.lib"
	}

    filter {"system:windows", "configurations:Debug"}
        cppdialect "Default"
        staticruntime "On"
        systemversion "latest"
        defines "ISDEBUG"
        symbols "On"

    filter {"system:windows", "configurations:Release"}
    cppdialect "Default"
    staticruntime "On"
    systemversion "latest"
    defines "ISRELEASE"
    optimize "On"