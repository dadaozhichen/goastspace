add_rules("plugin.compile_commands.autoupdate")
set_project("goastspace")
set_version("0.0.1")

set_languages("cxx20")

add_requires("libsdl3", "libsdl3_image", "libsdl3_ttf", "libsdl3_mixer","glm 1.0.3")


target("goastspace")
    set_kind("binary")
    add_files("src/*.cpp") 
    add_includedirs("include")

    -- 链接上述声明的包
    add_packages("libsdl3", "libsdl3_image", "libsdl3_ttf", "libsdl3_mixer","glm")