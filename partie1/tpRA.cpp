#include <aruco.h>
#include <cvdrawingutils.h>
#include <fstream>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <sstream>
#include <string>
#include <stdexcept>

#define ESC_KEY 27
#if  CV_MAJOR_VERSION >= 4
#define CV_CAP_PROP_FRAME_COUNT cv::CAP_PROP_FRAME_COUNT
#define CV_CAP_PROP_POS_FRAMES cv::CAP_PROP_POS_FRAMES
#endif
using namespace std;
using namespace cv;
using namespace aruco;


/*
VideoCapture TheVideoCapturer;
vector<Marker> TheMarkers;
Mat TheInputImage, TheInputImageGrey, TheInputImageCopy;
CameraParameters TheCameraParameters;
string dictionaryString;
int iDetectMode = 0, iMinMarkerSize = 0, iCorrectionRate = 0, iShowAllCandidates = 0, iEnclosed = 0, iThreshold, iCornerMode, iDictionaryIndex, iTrack = 0;

int waitTime = 0;
bool showMennu = false, bPrintHelp = false, isVideo = false;
*/

char key;

int main(int argc, char** argv) {
	string imName = "ArUcO-Marker-Pic1.jpg";
	if (argc >= 2) {
		imName = argv[1];
	}

	// Reading the image (and forcing it to grayscale)
	Mat myImage = imread(imName);

	// creation d’un detecteur de marqueurs
	MarkerDetector myDetector;

	// liste de marqueurs : sera remplie par ArUco
	// myDetector.setDictionary("ARUCO_MIP_36h12");
	while (key != ESC_KEY) {
		// detect markers and for each one, draw infoand its  boundaries in the image
		for (auto m : myDetector.detect(myImage)) {
			std::cout << m << std::endl;
			m.draw(myImage);
			imshow("detect markers", myImage);
		}
		key = waitKey(1000);
	}
	return 0;
}