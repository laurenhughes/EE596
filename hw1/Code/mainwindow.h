#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

template <class T> const T& max ( const T& a, const T& b ) {
  return (b<a)?a:b;     // or: return comp(b,a)?a:b; for the comp version
}

template <class T> const T& min ( const T& a, const T& b ) {
  return (b>a)?a:b;     // or: return comp(b,a)?a:b; for the comp version
}

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage inImage;
    QImage outImage;
    QImage displayImage;
    double** Image;
    int imageWidth;
    int imageHeight;
    double xScroll;
    double yScroll;
    bool zoomChanged;

    void DrawDisplayImage();
    void BlackWhiteImage(QImage *image);
    void AddNoise(QImage *image, double mag, bool colorNoise);
    void MeanBlurImage(QImage *image, int radius);
    void HalfImage(QImage &image);

    void Convolution(double** image, double *kernel, int kernelWidth, int kernelHeight, bool add);
    void GaussianBlurImage(double** image, double sigma);
    void FirstDerivImage_x(double** image, double sigma);
    void FirstDerivImage_y(double** image, double sigma);
    void SobelImage(double** image);


private slots:
    void OpenImage();
    void SaveImage();
    void SaveDisplayImage();
    void ResetImage();
    void ToggleImage();
    void AddNoise();
    void BlackWhiteImage();
    void MeanBlurImage();
    void GaussianBlurImage();
    void FirstDerivImage_x();
    void FirstDerivImage_y();
    void SobelImage();
    void HalfImage();
    void Brightness(int val);
    void Zoom(int val);
    void Scroll(int val);
    void ConvertQImage2Double(QImage image);
    void ConvertDouble2QImage(QImage *image);
};

#endif // MAINWINDOW_H
