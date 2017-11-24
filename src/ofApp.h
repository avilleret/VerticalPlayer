#pragma once

#include "ofMain.h"
#include "ofxGstVideoSyncPlayer.h"

class ofApp : public ofBaseApp
{
  public:
    void setup  ();
    void update ();
    void draw   ();
    void exit   ();

    ofxGstVideoSyncPlayer player;
};
