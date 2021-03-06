
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void DisplayImage(char* filename)
{
	Mat image;
    image = imread(filename, CV_LOAD_IMAGE_COLOR);	// Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return;
    }

    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);											 // Wait for a keystroke in the window
}

void Swap_RB()
{
	Mat image = imread("..//..//Images//Lighthouse.jpg");
	
	if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return;
    }

	int nl = image.rows;
	int nc = image.cols;

	for(int j=0;j<nl;j++)
		for(int i=0;i<nc;i++)
		{
			uchar tmp = 0;
			tmp = image.at<Vec3b>(j,i)[0];
			image.at<Vec3b>(j,i)[0] = image.at<Vec3b>(j,i)[2];
			image.at<Vec3b>(j,i)[2] = tmp;
		}

	namedWindow("WinTitle");
	imshow("WinTitle", image);
	waitKey(0);
}

void RGB2HSV()
{
	Mat image = imread("..//..//Images//Lighthouse.jpg");
	
	if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return;
    }

	Mat hsv;
	cvtColor(image, hsv, CV_BGR2HSV);

	int nl = image.rows;
	int nc = image.cols;

	for(int j=0;j<nl;j++)
		for(int i=0;i<nc;i++)
		{
			hsv.at<Vec3b>(j,i)[1] = 0;
		}

	cvtColor(hsv, image, CV_HSV2BGR);

	namedWindow("WinTitle");
	imshow("WinTitle", image);
	waitKey(0);
}

void RGB2YUV()
{
	Mat image = imread("..//..//Images//Lighthouse.jpg");
	
	if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return;
    }

	Mat gray;
	Mat dst;

	cvtColor(image, gray, CV_BGR2YUV);

	int nl = image.rows;
	int nc = image.cols;

	
	for(int j=0;j<nl;j++)
		for(int i=0;i<nc;i++)
		{
			gray.at<Vec3b>(j,i)[1] = 128;
			gray.at<Vec3b>(j,i)[2] = 128;
		}

	cvtColor(gray, dst, CV_YUV2BGR);

	namedWindow("WinTitle");
	imshow("WinTitle", dst);
	waitKey(0);
}

Mat src1, src2, dst;
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

/**
 * @function on_trackbar
 * @brief Callback for trackbar
 */
static void on_trackbar( int, void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;

   beta = ( 1.0 - alpha );

   addWeighted( src1, alpha, src2, beta, 0.0, dst);

   imshow( "Linear Blend", dst );
}

void HighGUI()
{
   /// Read image ( same size, same type )
   src1 = imread("..//..//Images//Lighthouse.jpg");
   src2 = imread("..//..//Images//Desert.jpg");

   if( !src1.data ) { printf("Error loading src1 \n"); return; }
   if( !src2.data ) { printf("Error loading src2 \n"); return; }

   /// Initialize values
   alpha_slider = 0;

   /// Create Windows
   namedWindow("Linear Blend", 1);

   /// Create Trackbars
   char TrackbarName[50];
   sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
   createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

   /// Show some stuff
   on_trackbar( alpha_slider, 0 );

   /// Wait until user press some key
   waitKey(0);
}

int main( int argc, char** argv )
{
	//displayImage("..//..//Images//Desert.jpg");
	//Swap_RB();
	HighGUI();

	return 0;
}
