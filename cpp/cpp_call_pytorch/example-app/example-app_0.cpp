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
   }
   catch (const c10::Error & e) {
     std::cerr << "error loading the model\n";
     return -1;
   }
   std::cout << "ok\n";
 }

// #include <torch/torch.h>
// #include <iostream>

// int main() {
//  torch::Tensor tensor = torch::rand({2, 3});
//  std::cout << tensor << std::endl;
// }

// 构建与编译命令
// mkdir build
// cd buld
// cmake -DCMAKE_PREFIX_PATH=/Users/puyuan/code/libtorch ..
// cmake --build . --config Release