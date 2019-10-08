#include "mainwindow.h"
#include "math.h"
#include "ui_mainwindow.h"
#include <QtGui>

/***********************************************************************
  This is the only file you need to change for your assignment. The
  other files control the UI (in case you want to make changes.)
************************************************************************/

/***********************************************************************
  The first eight functions provide example code to help get you started
************************************************************************/


// Convert an image to grayscale
void MainWindow::BlackWhiteImage(QImage *image)
{
    for(int r=0;r<image->height();r++)
        for(int c=0;c<image->width();c++)
        {
            QRgb pixel = image->pixel(c, r);
            double red = (double) qRed(pixel);
            double green = (double) qGreen(pixel);
            double blue = (double) qBlue(pixel);

            // Compute intensity from colors - these are common weights
            double intensity = 0.3*red + 0.6*green + 0.1*blue;

            image->setPixel(c, r, qRgb( (int) intensity, (int) intensity, (int) intensity));
        }
}

// Add random noise to the image
void MainWindow::AddNoise(QImage *image, double mag, bool colorNoise)
{
    int noiseMag = mag*2;

    for(int r=0;r<image->height();r++)
        for(int c=0;c<image->width();c++)
        {
            QRgb pixel = image->pixel(c, r);
            int red = qRed(pixel), green = qGreen(pixel), blue = qBlue(pixel);

            // If colorNoise, add color independently to each channel
            if(colorNoise)
            {
                red += rand()%noiseMag - noiseMag/2;
                green += rand()%noiseMag - noiseMag/2;
                blue += rand()%noiseMag - noiseMag/2;
            }
            // otherwise add the same amount of noise to each channel
            else
            {
                int noise = rand()%noiseMag - noiseMag/2;
                red += noise; green += noise; blue += noise;
            }
            image->setPixel(c, r, qRgb(max(0, min(255, red)), max(0, min(255, green)), max(0, min(255, blue))));
        }
}

// Downsample the image by 1/2
void MainWindow::HalfImage(QImage &image)
{
    int w = image.width();
    int h = image.height();
    QImage buffer = image.copy();

    // Reduce the image size.
    image = QImage(w/2, h/2, QImage::Format_RGB32);

    // Copy every other pixel
    for(int r=0;r<h/2;r++)
        for(int c=0;c<w/2;c++)
             image.setPixel(c, r, buffer.pixel(c*2, r*2));
}

// Round float values to the nearest integer values and make sure the value lies in the range [0,255]
QRgb restrictColor(double red, double green, double blue)
{
    int r = (int)(floor(red+0.5));
    int g = (int)(floor(green+0.5));
    int b = (int)(floor(blue+0.5));

    return qRgb(max(0, min(255, r)), max(0, min(255, g)), max(0, min(255, b)));
}

// Normalize the values of the kernel to sum-to-one
void NormalizeKernel(double *kernel, int kernelWidth, int kernelHeight)
{
    double denom = 0.000001; int i;
    for(i=0; i<kernelWidth*kernelHeight; i++)
        denom += kernel[i];
    for(i=0; i<kernelWidth*kernelHeight; i++)
        kernel[i] /= denom;
}

// Here is an example of blurring an image using a mean or box filter with the specified radius.
// This could be implemented using separable filters to make it much more efficient, but it's not done here.
// Note: This function is written using QImage form of the input image. But all other functions later use the double form
void MainWindow::MeanBlurImage(QImage *image, int radius)
{
    if(radius == 0)
        return;
    int size = 2*radius + 1; // This is the size of the kernel

    // Note: You can access the width and height using 'imageWidth' and 'imageHeight' respectively in the functions you write
    int w = image->width();
    int h = image->height();

    // Create a buffer image so we're not reading and writing to the same image during filtering.
    // This creates an image of size (w + 2*radius, h + 2*radius) with black borders (zero-padding)
    QImage buffer = image->copy(-radius, -radius, w + 2*radius, h + 2*radius);

    // Compute the kernel to convolve with the image
    double *kernel = new double [size*size];

    for(int i=0;i<size*size;i++)
        kernel[i] = 1.0;

    // Make sure kernel sums to 1
    NormalizeKernel(kernel, size, size);

    // For each pixel in the image...
    for(int r=0;r<h;r++)
    {
        for(int c=0;c<w;c++)
        {
            double rgb[3];
            rgb[0] = rgb[1] = rgb[2] = 0.0;

            // Convolve the kernel at each pixel
            for(int rd=-radius;rd<=radius;rd++)
                for(int cd=-radius;cd<=radius;cd++)
                {
                     // Get the pixel value
                     //For the functions you write, check the ConvertQImage2Double function to see how to get the pixel value
                     QRgb pixel = buffer.pixel(c + cd + radius, r + rd + radius);

                     // Get the value of the kernel
                     double weight = kernel[(rd + radius)*size + cd + radius];

                     rgb[0] += weight*(double) qRed(pixel);
                     rgb[1] += weight*(double) qGreen(pixel);
                     rgb[2] += weight*(double) qBlue(pixel);
                }
            // Store the pixel in the image to be returned
            // You need to store the RGB values in the double form of the image
            image->setPixel(c, r, restrictColor(rgb[0],rgb[1],rgb[2]));
        }
    }
    // Clean up (use this carefully)
    delete[] kernel;
}

// Convert QImage to a matrix of size (imageWidth*imageHeight)*3 having double values
void MainWindow::ConvertQImage2Double(QImage image)
{
    // Global variables to access image width and height
    imageWidth = image.width();
    imageHeight = image.height();

    // Initialize the global matrix holding the image
    // This is how you will be creating a copy of the original image inside a function
    // Note: 'Image' is of type 'double**' and is declared in the header file (hence global variable)
    // So, when you create a copy (say buffer), write "double** buffer = new double ....."
    Image = new double* [imageWidth*imageHeight];
    for (int i = 0; i < imageWidth*imageHeight; i++)
            Image[i] = new double[3];

    // For each pixel
    for (int r = 0; r < imageHeight; r++)
        for (int c = 0; c < imageWidth; c++)
        {
            // Get a pixel from the QImage form of the image
            QRgb pixel = image.pixel(c,r);

            // Assign the red, green and blue channel values to the 0, 1 and 2 channels of the double form of the image respectively
            Image[r*imageWidth+c][0] = (double) qRed(pixel);
            Image[r*imageWidth+c][1] = (double) qGreen(pixel);
            Image[r*imageWidth+c][2] = (double) qBlue(pixel);
        }
}

// Convert the matrix form of the image back to QImage for display
void MainWindow::ConvertDouble2QImage(QImage *image)
{
    for (int r = 0; r < imageHeight; r++)
        for (int c = 0; c < imageWidth; c++)
            image->setPixel(c, r, restrictColor(Image[r*imageWidth+c][0], Image[r*imageWidth+c][1], Image[r*imageWidth+c][2]));
}


/**************************************************
 TIME TO WRITE CODE
**************************************************/

/**************************************************
 TASK 1 (Oct. 1 - Oct. 6)
**************************************************/

// Convolve the image with the kernel
void MainWindow::Convolution(double** image, double *kernel, int kernelWidth, int kernelHeight, bool add)
/*
 * image: input image in matrix form of size (imageWidth*imageHeight)*3 having double values
 * kernel: 1-D array of kernel values
 * kernelWidth: width of the kernel
 * kernelHeight: height of the kernel
 * add: a boolean variable (taking values true or false)
*/
{
    // Add your code here

    // pseudo code from TA
    // need buffer image for output, can't keep convolving the same thing
    // create identical buffer

     double** buffer = new double* [imageWidth * imageHeight];
     for(int r = 0; r < imageWidth; ++r) {
        for(int c = 0; c < imageHeight; ++c) {
          buffer[c * imageHeight + r] = new double[3];
          buffer[c * imageHeight + r][0] = image[c * imageHeight + r][0];
          buffer[c * imageHeight + r][1] = image[c * imageHeight + r][1];
          buffer[c * imageHeight + r][2] = image[c * imageHeight + r][2];

          image[c * imageHeight + r][0] = add ? 128.0 : 0.0;
          image[c * imageHeight + r][1] = add ? 128.0 : 0.0;
          image[c * imageHeight + r][2] = add ? 128.0 : 0.0;
        }
      }
    //
    // now implement convolution
    //
    //

    // clean up
    // for(i = 0; i < imageWidth; ++i) {
    //    for(i = 0; i < imageHeight; ++j) {
    //      delete [] buffer[j * imageHeight + i];
    //    }
    //  delete [] buffer;
}

/**************************************************
 TASK 2 (Oct. 1 - Oct. 6)
**************************************************/

// Apply the 2-D Gaussian kernel on an image to blur it
void MainWindow::GaussianBlurImage(double** image, double sigma)
/*
 * image: input image in matrix form of size (imageWidth*imageHeight)*3 having double values
 * sigma: standard deviation for the Gaussian kernel
*/
{
    // Add your code here
}

/**************************************************
 TASK 3 (Oct. 6 - Oct. 13)
**************************************************/

/********** TASK 3 (a) **********/

// Compute the First derivative of an image along the horizontal direction and then apply Gaussian blur.
void MainWindow::FirstDerivImage_x(double** image, double sigma)
/*
 * image: input image in matrix form of size (imageWidth*imageHeight)*3 having double values
 * sigma: standard deviation for the Gaussian kernel
*/
{
    // Add your code here
}

/********** TASK 3 (b) **********/

// Compute the First derivative of an image along the vertical direction and then apply Gaussian blur.
void MainWindow::FirstDerivImage_y(double** image, double sigma)
/*
 * image: input image in matrix form of size (imageWidth*imageHeight)*3 having double values
 * sigma: standard deviation for the Gaussian kernel
*/
{
    // Add your code here
}


/**************************************************
 TASK 4 (Oct. 6 - Oct. 13)
**************************************************/

// Display the magnitude and orientation of the edges in an image using the Sobel operator in both X and Y directions
void MainWindow::SobelImage(double** image)
/*
 * image: input image in matrix form of size (imageWidth*imageHeight)*3 having double values
 * NOTE: image is grayscale here, i.e., all 3 channels have the same value which is the grayscale value
*/
{
    // Add your code here

    // Use the following 3 lines of code to set the image pixel values after computing magnitude and orientation
    // Here 'mag' is the magnitude and 'orien' is the orientation angle in radians to be computed using atan2 function
    // (sin(orien) + 1)/2 converts the sine value to the range [0,1]. Similarly for cosine.

    // image[r*imageWidth+c][0] = mag*4.0*((sin(orien) + 1.0)/2.0);
    // image[r*imageWidth+c][1] = mag*4.0*((cos(orien) + 1.0)/2.0);
    // image[r*imageWidth+c][2] = mag*4.0 - image[r*imageWidth+c][0] - image[r*imageWidth+c][1];
}
