set_project("goastspace")
set_version("0.0.1")

set_languages("cxx20")

add_requires("libsdl3", "libsdl3_image", "libsdl3_ttf", "libsdl3_mixer","glm 1.0.3")
target("core")
    set_kind("static")
    add_files("core/*.cpp")
    add_includedirs("core",{public = true})
    add_packages("libsdl3", "libsdl3_image", "libsdl3_ttf", "libsdl3_mixer","glm",{public=true})

target("goastspace")
    set_kind("binary")
    add_files("src/*.cpp") 
    add_includedirs("src")
    add_deps("core")

    