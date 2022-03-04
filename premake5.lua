-- Global Project Related Directories.
__PRJ_DIR   = "projects/"
__OBJ_DIR   = "obj/"
__BUILD_DIR = "builds/"

-- Global Depedencies.
__GLFW_DIR  = "external/glfw/"
__GLM_DIR   = "external/glm/"



workspace "Amen"
    configurations {"Debug", "MidRelease", "Release"}
    platforms "x64"
    startproject "Sandbox"

    
    -- ==============================|Project: GLFW|============================== --
    externalproject "GLFW"
        location(__GLFW_DIR.."build/")
        kind "StaticLib"
        language "C++"
    -- ==============================|Project: GLFW|============================== --




    -- ==============================|Project: GLAD|============================== --
    project_glad = "GLAD"
    project(project_glad)
        kind "StaticLib"
        language "C++"
        location(__PRJ_DIR.."%{prj.name}/")
        targetdir(__BUILD_DIR.."%{cfg.shortname}/")
        objdir(__OBJ_DIR.."%{prj.name}_%{cfg.shortname}/")

        files {
            __PRJ_DIR.."%{prj.name}/src/**.cpp",
            __PRJ_DIR.."%{prj.name}/src/**.h"
        }

        includedirs {
            __PRJ_DIR.."%{prj.name}/src/include/",
        }

        filter {}
        filter "system:Linux"
            buildoptions {"-fPIC"}
    -- ==============================|Project: GLAD|============================== --



    -- ===========================|Project: STB_Image|============================ --
    project_stbimage = "STB_Image"
    project(project_stbimage)
        kind "StaticLib"
        language "C++"
        location(__PRJ_DIR.."%{prj.name}/")
        targetdir(__BUILD_DIR.."%{cfg.shortname}/")
        objdir(__OBJ_DIR.."%{prj.name}_%{cfg.shortname}/")

        files {
            __PRJ_DIR.."%{prj.name}/src/**.cpp",
            __PRJ_DIR.."%{prj.name}/src/**.h"
        }

        includedirs {
            __PRJ_DIR.."%{prj.name}/src/",
        }

        filter {}
        filter "system:Linux"
            buildoptions {"-fPIC"}
    -- ===========================|Project: STB_Image|============================ --



    -- ==============================|Project: Amen|============================== --
    project_amen = "Amen"
    project(project_amen)
        kind "SharedLib"
        language "C++"
        location(__PRJ_DIR.."%{prj.name}/")
        targetdir(__BUILD_DIR.."%{cfg.shortname}/")
        objdir(__OBJ_DIR.."%{prj.name}_%{cfg.shortname}/")
        pchheader "pch.h"
        pchsource(__PRJ_DIR.."%{prj.name}/src/pch.cpp")

        files {
            __PRJ_DIR.."%{prj.name}/src/**.cpp",
            __PRJ_DIR.."%{prj.name}/src/**.hpp",
            __PRJ_DIR.."%{prj.name}/src/**.h"
        }

        includedirs {
            __PRJ_DIR.."%{prj.name}/src/",
            __PRJ_DIR..project_glad.."/src/include/",
            __PRJ_DIR..project_stbimage.."/src/",
            __GLFW_DIR.."include/",
            __GLM_DIR
        }

        links {
            project_glad,
            project_stbimage
        }

        filter {}
        filter "configurations:Debug"
            defines "AMEN_DEBUG"

        filter {}
        filter "configurations:MidRelease"
            defines "AMEN_MIDRELEASE"

        filter {}
        filter "configurations:Release"
            defines "AMEN_RELEASE"
        
        ----------------------------------Linux----------------------------------
        filter {}
        filter "system:Linux"
            defines {"AMEN_LINUX"}
            libdirs {
                __GLFW_DIR.."build/src/"
            }
            links "glfw3:static"
        ----------------------------------Linux----------------------------------


        ---------------------------------Windows---------------------------------
        filter {}
        filter "system:Windows"
            defines {"AMEN_WINDOWS", "AMEN_BUILD"}
            links {"glfw3", "opengl32"}

            filter "configurations:Debug"
                libdirs {
                    __GLFW_DIR.."build/src/Debug/"
                }

            filter "configurations:MidRelease"
                libdirs {
                    __GLFW_DIR.."build/src/Release/"
                }

            filter "configurations:Release"
                libdirs {
                    __GLFW_DIR.."build/src/Release/"
                }
        ---------------------------------Windows---------------------------------

    -- ==============================|Project: Amen|============================== --



    -- ============================|Project: Sandbox|============================= --
    project "Sandbox"
        kind "ConsoleApp"
        language "C++"
        location(__PRJ_DIR.."%{prj.name}/")
        targetdir(__BUILD_DIR.."%{cfg.shortname}/")
        objdir(__OBJ_DIR.."%{prj.name}_%{cfg.shortname}/")

        files {
            __PRJ_DIR.."%{prj.name}/src/**.cpp",
            __PRJ_DIR.."%{prj.name}/src/**.hpp",
            __PRJ_DIR.."%{prj.name}/src/**.h"
        }

        includedirs {
            __PRJ_DIR.."%{prj.name}/src/",
            __PRJ_DIR..project_amen.."/src/",
        }

        links {
            project_amen
        }

        filter {}
        filter "configurations:Debug"
            defines "AMEN_DEBUG"

        filter {}
        filter "configurations:MidRelease"
            defines "AMEN_MIDRELEASE"

        filter {}
        filter "configurations:Release"
            defines "AMEN_RELEASE"

        ----------------------------------Linux----------------------------------
        filter {}
        filter "system:Linux"
            defines {"AMEN_LINUX"}
        ----------------------------------Linux----------------------------------

        ---------------------------------Windows---------------------------------
        filter {}
        filter "system:Windows"
            defines {"AMEN_WINDOWS"}
        ---------------------------------Windows---------------------------------

    -- ============================|Project: Sandbox|============================= --