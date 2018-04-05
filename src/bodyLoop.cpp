#include <vector> 
#include "include/structs.h"
#include "include/faceLoop.h"
#include <algorithm>
#include "include/bodyLoop.h"

bool bodyLoop::addLoop(faceLoop loop){
	if(!(std::find(bodyloop.begin(), bodyloop.end(), loop) != bodyloop.end())) {
		bodyloop.push_back(loop) ;
		return true ; 
	}
	else return false ; 
}

void bodyLoop::removeLoop(faceLoop loop){
	if (std::find(bodyloop.begin(),bodyloop.end(),loop)!=bodyloop.end()) {
		bodyloop.erase(remove(bodyloop.begin(),bodyloop.end(),loop),bodyloop.end());
	}
}

bool bodyLoop::containsLoop(faceLoop loop){
	return (std::find(bodyloop.begin(), bodyloop.end(), loop) != bodyloop.end()) ; 
}

bool bodyLoop::legal(){
	return false ; 
} 
