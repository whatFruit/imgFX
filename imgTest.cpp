#include "ppmEncoder.hh"
#include<cmath>

void drawWave_1(ppmEncoder& imgEncoder,int frames = 1,int offsetSize = 20){
	//create blank buffer
	imgBuffer testBuffer = imgEncoder.blankBuffer();
	double aInc = 0.01;
	double wFreq = 0.01;
	double iStepAdj = 0.1;
	double jStepAdj = 0.1;
	int iOffset = 2650;
	int jOffset = 1420;

	std::string baseFileName = imgEncoder.getFileName();

	//create many frames
	for(int offset = 0; offset < frames; offset++){
		imgEncoder.setFileName(baseFileName + std::to_string(offset));
		for(int i=0; i < imgEncoder.getHeight(); i++){
			for (int j = 0; j < imgEncoder.getWidth(); j++)
			{
				double iStep = iStepAdj*(i+iOffset);
				double jStep = jStepAdj*(j+jOffset);
				//[i^(i+c)*sin(j*w)+o]%m
				testBuffer[i][j].r= static_cast<int>(std::round(std::abs((std::pow(iStep,iStep*aInc)*std::sin(jStep*wFreq) + offset*offsetSize))))%(imgEncoder.getMaxVal()+1);
				testBuffer[i][j].g= 125;
				testBuffer[i][j].b= 125;
			}
		}
		imgEncoder.writePPM(testBuffer);
	}
}

int main(int argc, char ** argv){
	//format: 'imgTest.exe <outfile name> [<width> <height>] <# frames> <max value>'
	int width = 300;
	int height = 200;
	int maxValue = 255;
	std::string fileName = "test";

	//for drawWave1()
	int frames = 1;
	int offsetSize = 20;
	//user input paramaters
	if(argc > 1){
		fileName = std::string(argv[1]);
	}
	if(argc > 3){
		width = std::atoi(argv[2]);
		height = std::atoi(argv[3]);
	}
	if(argc > 4){
		frames = std::atoi(argv[4]);
	}
	if(argc > 5){
		maxValue = std::atoi(argv[5]);
	}

	ppmEncoder imgEncoder(width,height,fileName);
	drawWave_1(imgEncoder,frames,offsetSize);
}