#include <iostream>
#include "logging.h"
#include "NvOnnxParser.h"
#include "NvInfer.h"
#include <fstream>
#include "model_onnx2trt.h" 

using namespace nvinfer1;
using namespace nvonnxparser;

static Logger gLogger;
int main_o2t(char* onnxPath, char* enginePath) {
	
	// 1 onnx½âÎöÆ÷
	IBuilder* builder = createInferBuilder(gLogger);
	const auto explicitBatch = 1U << static_cast<uint32_t>(NetworkDefinitionCreationFlag::kEXPLICIT_BATCH);
	INetworkDefinition* network = builder->createNetworkV2(explicitBatch);

	nvonnxparser::IParser* parser = nvonnxparser::createParser(*network, gLogger);

	const char* onnx_filename = onnxPath;
	parser->parseFromFile(onnx_filename, static_cast<int>(Logger::Severity::kWARNING));
	for (int i = 0; i < parser->getNbErrors(); ++i)
	{
		std::cout << parser->getError(i)->desc() << std::endl;
	}
	std::cout << "successfully load the onnx model" << std::endl;

	// 2build the engine
	unsigned int maxBatchSize = 1;
	builder->setMaxBatchSize(maxBatchSize);
	IBuilderConfig* config = builder->createBuilderConfig();
	config->setMaxWorkspaceSize(1 << 20);
	//config->setMaxWorkspaceSize(128 * (1 << 20));  // 16MB
	config->setFlag(BuilderFlag::kFP16);
	ICudaEngine* engine = builder->buildEngineWithConfig(*network, *config);

	// 3serialize Model
	IHostMemory* gieModelStream = engine->serialize();
	std::ofstream p(enginePath, std::ios::binary);
	if (!p)
	{
		std::cerr << "could not open plan output file" << std::endl;
		return -1;
	}
	p.write(reinterpret_cast<const char*>(gieModelStream->data()), gieModelStream->size());
	gieModelStream->destroy();


	std::cout << "successfully generate the trt engine model" << std::endl;
	return 0;
}