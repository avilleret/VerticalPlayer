#include "ofApp.h"

#define MASTER_CLOCK_SYNC_PORT 12366 ///> The port that will be used from GStreamer for master-slave clock synchronization.
#define MASTER_OSC_RCV_PORT 12777 ///> The port that the master listens for incoming osc messages from the clients.
#define SLAVE_OSC_SND_PORT MASTER_OSC_RCV_PORT ///> The osc send port of the slave should be the same as the receive port of the master.
#define SLAVE_OSC_RCV_PORT 12789 ///> You can choose any valid port for the slave to receive. Be carefull to choose a different one if you have multiple clients running on the same machine.

void ofApp::setup()
{
    ofHideCursor();
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetBackgroundColor(ofColor::black);

#if defined(MASTER)
            player.initAsMaster("127.0.0.1", MASTER_CLOCK_SYNC_PORT, MASTER_OSC_RCV_PORT);
            player.load("testMH2_1.mov");
#endif

#if defined(ONE)
            player.initAsSlave("127.0.0.1", MASTER_CLOCK_SYNC_PORT, SLAVE_OSC_RCV_PORT+1, SLAVE_OSC_SND_PORT);
            player.load("testMH2_2.mov");
#endif

#if defined(TWO)
            player.initAsSlave("127.0.0.1", MASTER_CLOCK_SYNC_PORT, SLAVE_OSC_RCV_PORT+2, SLAVE_OSC_SND_PORT);
            player.load("testMH2_3.mov");
#endif

        player.loop(true);
        player.play();
}

void ofApp::update()
{
      player.update();
}

void ofApp::draw()
{
    player.draw(ofPoint(0, 0), 1920, 1080);
}

void ofApp::exit()
{
}
