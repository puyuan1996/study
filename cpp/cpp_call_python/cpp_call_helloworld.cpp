// cpp_call_helloworld.cpp
#include <Python.h>
int main(int argc, char *argv[]) {
  Py_Initialize();
  PyRun_SimpleString("print('hello world')\n");
  Py_Finalize();
  return 0;
}