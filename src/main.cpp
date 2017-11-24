#include "ofApp.h"

int main()
{
  ofGLFWWindowSettings settings;
  settings.width=1920;
  settings.height=1200;
  settings.decorated=false;
  //settings.windowMode = OF_GAME_MODE;
  settings.windowMode = OF_FULLSCREEN;
  //settings.multiMonitorFullScreen = true;
#if defined(ONE)
  settings.setPosition(ofPoint(1920,0));
#endif
#if defined(TWO)
  settings.setPosition(ofPoint(3840,0));
#endif
#if defined(MASTER)
  settings.setPosition(ofPoint(0,0));
#endif

  auto window = ofCreateWindow(settings);
  auto app = make_shared<ofApp>();
  ofRunApp(window, app);

  return ofRunMainLoop();
}
