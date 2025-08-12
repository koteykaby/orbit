workspace "orbit"
    location "build/%{_ACTION}_%{os.target()}"  
    configurations { 
        "Debug", 
        "Release" 
    }        
    architecture "x86"  
    cppdialect "C++20"                           
    characterset "ASCII"                        
    startproject "ubiorbitapi_r2_loader"        
 
    targetdir "bin/%{cfg.buildcfg}_%{cfg.architecture}"
    objdir "obj/%{cfg.buildcfg}_%{cfg.architecture}"

    filter "configurations:Debug"  
        defines { 
            "DEBUG" 
        }  
        symbols "On"                           
        optimize "Debug"  

    filter "configurations:Release"  
        defines { 
            "NDEBUG" 
        }  
        optimize "Speed"                      

group "main"  
    project "ubiorbitapi_r2_loader"
        kind "SharedLib" -- dll
        language "C++"
        files { 
            "commons/*.hpp",
            "commons/*.cpp",
            "ubiorbitapi_r2_loader/**.hpp", 
            "ubiorbitapi_r2_loader/**.cpp", 
            "ubiorbitapi_r2_loader/**.h" 
        }  
        includedirs { "commons" } 
        defines { 
            "UBIORBITAPI_R2_LOADER_EXPORT"
        }
