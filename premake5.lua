workspace "TestGame"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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

    filter {"system:windows", "configurations:Debug"}
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"
        defines "ISDEBUG"
        symbols "On"

    filter {"system:windows", "configurations:Debug"}
    cppdialect "Default"
    staticruntime "On"
    systemversion "latest"
    defines "ISRELEASE"
    optimize "On"