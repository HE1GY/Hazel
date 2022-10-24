project "Glad"
	kind "StaticLib"
	language "C"
	

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/krrplatform.h",
		"src/glad.c"
	}


	includedirs
	{
		"include"
	}
	

	filter "system:windows"
		systemversion "latest"
		staticruntime "ON"

	filter {"system:windows","configurations:Release"}
		buildoptions "/MT"
