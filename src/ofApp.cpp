#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bSendSerialMessage = false;
    serial.enumerateDevices(); //print a list of all serial devices
    serial.setup(0,9600); //the first serial device (which is hopefully the arduino
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(bSendSerialMessage){
        
        //send a handshake message to the arduino telling it we want some data
        serial.writeByte('x');
        
        //make somewhere to store incoming data
        unsigned char bytesReturned[NUM_BYTES];
        memset(bytesReturned, 0, NUM_BYTES);
        
        //keep reading bytes until there is nothing left
        while (serial.readBytes(bytesReturned, NUM_BYTES) > 0) {
            //
        }
        
        //reset bSendSerialMessage to false
        bSendSerialMessage = false;
        
        
        distance = bytesReturned[0];
        distance <<= 8;
        distance += bytesReturned[1];
        
        
        other = bytesReturned[3];
        other <<= 8;
        other += bytesReturned[4];
        
        
        ofLog(OF_LOG_NOTICE, ofToString(distance) + " " + ofToString(bytesReturned[2]) + " " + ofToString(other));
    }
    
    
    
    countCycles++;
    if(countCycles == 5){
        bSendSerialMessage = true;
        countCycles = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   ofDrawBitmapString(ofToString(ofToString(distance) + " ~ " + ofToString(other)), 20, 40);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
