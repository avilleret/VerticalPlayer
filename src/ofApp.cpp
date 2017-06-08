#include "ofApp.h"

#define MASTER_CLOCK_SYNC_PORT 12366 ///> The port that will be used from GStreamer for master-slave clock synchronization.
#define MASTER_OSC_RCV_PORT 12777 ///> The port that the master listens for incoming osc messages from the clients.
#define SLAVE_OSC_SND_PORT MASTER_OSC_RCV_PORT ///> The osc send port of the slave should be the same as the receive port of the master.
#define SLAVE_OSC_RCV_PORT 12789 ///> You can choose any valid port for the slave to receive. Be carefull to choose a different one if you have multiple clients running on the same machine.

void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    player.push_back(new ofxGstVideoSyncPlayer);
    player.push_back(new ofxGstVideoSyncPlayer);
    player.push_back(new ofxGstVideoSyncPlayer);

    for (int i=0; i<player.size();i++){
        if (i==0){
            player[i]->initAsMaster("127.0.0.1", MASTER_CLOCK_SYNC_PORT, MASTER_OSC_RCV_PORT);
        } else {
            player[i]->initAsSlave("127.0.0.1", MASTER_CLOCK_SYNC_PORT, SLAVE_OSC_RCV_PORT+i, SLAVE_OSC_SND_PORT);
        }

        std::stringstream ss;
        ss << "testMH2_" << i + 1 << ".mov";
        player[i]->load(ss.str().c_str());
        player[i]->loop(true);
        player[i]->play();
    }
}

void ofApp::update()
{
    for (auto p : player){
      p->update();
    }
}

void ofApp::draw()
{

    unsigned int n = player.size();
    for (int i=0; i<n;i++){
        int width = ofGetWidth()/n;
        int offset = i*width;
        player[i]->draw(ofPoint(offset, 0), width, ofGetHeight());
    }
}

void ofApp::exit()
{
}
