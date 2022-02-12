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

IncludeDir["glm"] = "TestGame/vendor/glm"

IncludeDir["stb"] = "TestGame/vendor/stb"


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
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
        "%{prj.name}/vendor/stb/stb_image.hpp",
        "%{prj.name}/vendor/stb/stb_image.cpp"

        
    }

    includedirs
	{
        "%{prj.name}/src/OpenGL",
        "%{prj.name}/src/OpenGL/BufferUtils",
        "%{prj.name}/src/OpenGL/Utils",
        "%{prj.name}/src/GameObjects",
        
		"%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb}"
	}

    links
	{
		"GLFW",
        "Glad",
		"opengl32.lib"
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