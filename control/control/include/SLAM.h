#ifndef SLAM_H
#define SLAM_H

#include <opencv2/core/core.hpp>
#include <memory>
class Config;

class SLAM
{

    public:
        /** Default constructor */
        SLAM();
        //初始化SLAM系统
        virtual bool Init() = 0；

        // 主函数
         void Run() = 0;
        // Proccess the given stereo frame. Images must be synchronized and rectified.
        // Input images: RGB (CV_8UC3) or grayscale (CV_8U). RGB is converted to grayscale.
        // Returns the camera pose (empty if tracking fails).
        virtual cv::Mat TrackStereo(const cv::Mat &imLeft, const cv::Mat &imRight, const double &timestamp) = 0;

        // Process the given rgbd frame. Depthmap must be registered to the RGB frame.
        // Input image: RGB (CV_8UC3) or grayscale (CV_8U). RGB is converted to grayscale.
        // Input depthmap: Float (CV_32F).
        // Returns the camera pose (empty if tracking fails).
        virtual cv::Mat TrackRGBD(const cv::Mat &im, const cv::Mat &depthmap, const double &timestamp) = 0;

        // Proccess the given monocular frame
        // Input images: RGB (CV_8UC3) or grayscale (CV_8U). RGB is converted to grayscale.
        // Returns the camera pose (empty if tracking fails).
        virtual cv::Mat TrackMonocular(const cv::Mat &im, const double &timestamp) = 0;


        // Reset the system (clear map)
        virtual void Reset() = 0;

        // All threads will be requested to finish.
        // It waits until all threads have finished.
        // This function must be called before saving the trajectory.
        virtual void Shutdown() = 0;
        /** Default destructor */
        virtual ~SLAM();

    protected:

    private:
};

#endif // SLAM_H
