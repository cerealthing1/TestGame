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
    cppdialect "C++17"
    

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
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