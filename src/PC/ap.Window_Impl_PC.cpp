#include "ap.Window_Impl_PC.h"

namespace ap
{
	void Window_Impl_PC::Terminate()
	{
		if (window != nullptr)
		{
			glfwDestroyWindow(window);
			window = nullptr;
			glfwTerminate();
		}
	}

	Window_Impl_PC::Window_Impl_PC()
	{

	}
	
	Window_Impl_PC::~Window_Impl_PC()
	{
		Terminate();
	}

	ErrorCode Window_Impl_PC::Initialize(const WindowInitializationParameter& parameter)
	{
		if (!glfwInit())
		{
			return ErrorCode::FailedInitializeWindowSystem;
		}

		window = glfwCreateWindow(parameter.WindowWidth, parameter.WindowHeight, "", nullptr, nullptr);
		if (window == nullptr)
		{
			glfwTerminate();
			return ErrorCode::FailedCreateWindow;
		}

		return ErrorCode::OK;
	}

	bool Window_Impl_PC::DoEvent()
	{
		if (window = nullptr) return false;

		if (glfwWindowShouldClose(window))
		{
			Terminate();
			return false;
		}

		glfwPollEvents();
		return true;
	}
}