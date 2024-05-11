// Inputs singleton

#ifndef INPUT_SINGLETON_HH
#define INPUT_SINGLETON_HH

class InputSingleton {
public:
  static InputSingleton* GetInstance();
  void Update();

  bool w_down;
  bool a_down;
  bool s_down;
  bool d_down;
  bool quit;
private:
  InputSingleton();

  static InputSingleton* instance;


};

#endif
