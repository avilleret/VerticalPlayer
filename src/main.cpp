#include "ofApp.h"

int main()
{
  ofGLFWWindowSettings settings;
  settings.width=1920;
  settings.height=1200;
  settings.decorated=false;
  //settings.windowMode = OF_GAME_MODE;
  settings.windowMode = OF_FULLSCREEN;
#if defined(ONE)
  settings.setPosition(ofPoint(1920,0));
#else
#if defined (TWO)
  settings.setPosition(ofPoint(3840,0));
#else
  settings.setPosition(ofPoint(0,0));
#endif
#endif

  auto window = ofCreateWindow(settings);
  auto app = make_shared<ofApp>();
  ofRunApp(window, app);

  return ofRunMainLoop();
}
