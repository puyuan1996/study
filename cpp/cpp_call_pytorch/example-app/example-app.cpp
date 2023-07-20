// 实例2: https://zhuanlan.zhihu.com/p/447973380
// 执行目标文件 ./example-app /mnt/nfs/puyuan/study/cpp/cpp_call_pytorch/traced_resnet_model.pt

#include <torch/script.h> // One-stop header.
#include <iostream>
#include <memory>
int main(int argc, const char* argv[]) {
  if (argc != 2) {
    std::cerr << "usage: example-app <path-to-exported-script-module>\n";
    return -1;
  }
  torch::jit::script::Module module;
  try {
    // Deserialize the ScriptModule from a file using torch::jit::load().
    module = torch::jit::load(argv[1]);

    // 如果要使用CUDA，用.to()把模型和数据放到device上，比如，model.to(at::kCUDA)
    // Create a vector of inputs.
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(torch::ones({1, 3, 224, 224}));

    // Execute the model and turn its output into a tensor.
    at::Tensor output = module.forward(inputs).toTensor();

    std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';
    // std::cout << output << '\n';

  }
  catch (const c10::Error& e) {
    std::cerr << "error loading the model\n";
    return -1;
  }
  std::cout << "ok\n";
}

// 构建与编译命令
// mkdir build
// cd buld
// cmake -DCMAKE_PREFIX_PATH=/Users/puyuan/code/libtorch ..
// cmake --build . --config Release