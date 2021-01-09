workspace "wordcounter-cpp"
   configurations { "Debug", "Release" }

project "wordcounter"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"

   includedirs { "src ", "" , "scripts"}
   
   pchheader "pch.h"
   pchsource "src/pch.cpp"
   files { "**.hpp", "**.cpp", "**.h" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
