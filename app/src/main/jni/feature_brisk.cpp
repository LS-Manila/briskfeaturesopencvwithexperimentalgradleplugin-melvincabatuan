#include <jni.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_brisk_MainActivity_findBRISKFeatures(JNIEnv *env, jobject instance,
                                                               jlong mGray, jlong mRgba) {

    cv::Mat& mGr  = *(cv::Mat*)mGray;
    cv::Mat& mRgb = *(cv::Mat*)mRgba;

    std::vector<cv::KeyPoint> v;

    cv::Ptr<cv::Feature2D> detector = cv::BRISK::create();

    detector->detect(mGr, v);

    for( unsigned int i = 0; i < v.size(); i++ )
    {
        const cv::KeyPoint& kp = v[i];
        cv::circle(mRgb, cv::Point(kp.pt.x, kp.pt.y), 10, cv::Scalar(0,255,0,255));
    }

}

#ifdef __cplusplus
}
#endif