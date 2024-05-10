// Inputs singleton

#ifndef INPUT_SINGLETON_HH
#define INPUT_SINGLETON_HH

class InputSingleton {
public:
  static InputSingleton* GetInstance();
  void Update();

  bool w_down = false;
  bool a_down = false;
  bool s_down = false;
  bool d_down = false;
  bool quit = false;
private:
  InputSingleton() {};

  static InputSingleton* instance;

  
};

#endif