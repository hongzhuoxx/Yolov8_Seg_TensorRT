// Yolov8_Seg_TensorRT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include "model_onnx2trt.h"
#include <windows.h>
#include "trt_infer.h"
#include <string>
#include <stdexcept>

/// <summary>
/// 入口函数
/// </summary>
/// <returns></returns>
int main()
{
	//===========================================================================================================================
	//========== 测试数据


	std::string str_onnxPath = "D:/ZxCodes/C++/ZxOnnx_GPU_ALL/ZxOnnx/models/michelin.onnx";
	std::string str_enginePath = "D:/ZxCodes/C++/ZxOnnx_GPU_ALL/ZxOnnx/models/michelin.engine";
	std::string str_testImg = "D:/ZxCodes/C++/ZxOnnx_GPU_ALL/ZxOnnx/images/m1.bmp";

	char* c_onnxPath = new char[str_onnxPath.length() + 1];
	::strcpy_s(c_onnxPath, str_onnxPath.length() + 1, str_onnxPath.c_str());

	char* c_enginePath = new char[str_enginePath.length() + 1];
	::strcpy_s(c_enginePath, str_enginePath.length() + 1, str_enginePath.c_str());

	char* c_testImg = new char[str_testImg.length() + 1];
	::strcpy_s(c_testImg, str_testImg.length() + 1, str_testImg.c_str());

	//===========================================================================================================================


	if (false)
	{
		std::cout << "开始模型转换/n";

		// 模型转换
		main_o2t(c_onnxPath, c_enginePath);

		std::cout << "模型转换结束!/n";
	}

	if (true)
	{
		std::cout << "开始实例分割!/n";

		// 实例分割

		seg_trt_go(c_enginePath, c_testImg);

		std::cout << "实力分割结束!/n";
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单9

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


