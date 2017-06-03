# Compilação

gcc sdl.cpp -lSDL2 -std=c++11 

Devido ao seguinte erro 
~~~~  
anny@Anny-pc:~/reativos/tarefas/sdl$ gcc sdl.cpp -lSDL2
sdl.cpp:6:17: warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
  bool canMove = true;
                 ^
sdl.cpp: In function ‘int main(int, char**)’:
sdl.cpp:75:40: error: in C++98 ‘r1’ must be initialized by constructor, not by ‘{...}’
  SDL_Rect_Q r1 = { 10, 10, 50, 0.5, 100};
                                        ^
sdl.cpp:76:48: error: in C++98 ‘r2’ must be initialized by constructor, not by ‘{...}’
     SDL_Rect_Q r2 = { 200 , 200, 100, -0.5, 100};
~~~~  

