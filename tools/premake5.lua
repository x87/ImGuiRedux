
----------------------------
-- Premake Project Generator
----------------------------

workspace "ImGuiRedux"
    configurations { "Debug", "Release" }
    platforms "Win32"
    language "C++"
    cppdialect "C++20"
    characterset "MBCS"
    staticruntime "On"
    location "../build"
    targetdir "../build/bin"
    kind "SharedLib"
    targetextension ".cleo"

    files { 
        "../include/**", 
        "../src/**" 
    }
    
    includedirs {
        "../include/**"
    }

    libdirs {
        "../lib/",
    }

project "ImGuiRedux"
    architecture "x86"

    links { 
        "d3d9",
        "d3d11",
        "cleo_redux",
        "libMinHook-x86"
    }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"

project "ImGuiRedux64"
    architecture "x64"
    
    links { 
        "d3d9",
        "d3d11",
        "cleo_redux64",
        "libMinHook-x64"
    }

    filter "configurations:Debug"
        symbols "On"
        
    filter "configurations:Release"
        optimize "On"
        